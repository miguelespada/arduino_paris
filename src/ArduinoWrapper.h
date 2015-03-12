//
//  ArduinoWrapper.h
//  planta
//
//  Created by miguel on 21/02/15.
//
//

#ifndef __planta__ArduinoWrapper__
#define __planta__ArduinoWrapper__

#include "ofMain.h"
#include "ArduinoEvent.h"
#include "OscAdapter.h"

#define RECONNECT_RATE 90

class ArduinoWrapper
{
private:
    bool    bSetupArduino;
    bool    bArduinoConnected;
    
    string  getPort();
    void    connectArduino(string deviceName);
    void    configPins();
    void    updateArduino();
    
    void    setupArduino(const int & version);
    void    digitalPinChanged(const int & pinNum);
    void    analogPinChanged(const int & pinNum);
    void    update();
    int     v = 0;
    

    
public:
    ArduinoWrapper();
    ~ArduinoWrapper();
    void update(ofEventArgs &args);
    ofArduino	*arduino;
    OscAdapter osc;
};
#endif /* defined(__planta__ArduinoWrapper__) */
