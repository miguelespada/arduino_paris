#include "ArduinoWrapper.h"


ArduinoWrapper::ArduinoWrapper(){
    bArduinoConnected = false;
    arduino = new ofArduino;
    ofAddListener(ofEvents().update, this, &ArduinoWrapper::update);
}

ArduinoWrapper::~ArduinoWrapper(){
    if(bArduinoConnected){
        arduino->disconnect();
        delete arduino;
    }
}

string ArduinoWrapper::getPort(){
    ofSerial serial;
    vector <ofSerialDeviceInfo> deviceList =  serial.getDeviceList();
    for (int i=0; i<deviceList.size(); i++) {
        if(deviceList[i].getDeviceName().find("tty.usbmodem") != std::string::npos){
            return deviceList[i].getDeviceName();
        }
    }
    return "";
};

void ArduinoWrapper::connectArduino(string deviceName){
    bArduinoConnected = arduino->connect(deviceName, 57600);
    ofAddListener(arduino->EInitialized, this, &ArduinoWrapper::setupArduino);
}

//--------------------------------------------------------------
void ArduinoWrapper::setupArduino(const int & version) {
    ofRemoveListener(arduino->EInitialized, this, &ArduinoWrapper::setupArduino);
    arduino->sendAnalogPinReporting(0, ARD_ANALOG);
}

//--------------------------------------------------------------
void ArduinoWrapper::update(){
    if(bArduinoConnected) {
        if(v < 800 && arduino->getAnalog(0) > 1000){
            cout << "/key_down" << endl;
            osc.sendAction("/key_down");
            ofSleepMillis(500);
        }
        
        v = arduino->getAnalog(0);
        
        ofSendMessage("[Info] Arduino connected");
        ofSendMessage("[Info] Analog: " + ofToString(v));
    }
    else{
        ofSendMessage("[Info] Arduino NOT connected"); 
    }
    
    if(ofGetFrameNum() % 90 == 0){
        string deviceName = getPort();
        if(deviceName == "" && bArduinoConnected){
            arduino->disconnect();
            bArduinoConnected = false;
        }
        if(deviceName != "" && !bArduinoConnected){
            connectArduino(deviceName);
        }
    }
    
    arduino->update();
    


}


//--------------------------------------------------------------
void ArduinoWrapper::update(ofEventArgs &args){
    update();
}


