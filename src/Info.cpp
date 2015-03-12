//
//  Info.cpp
//  planta
//
//  Created by miguel on 20/02/15.
//
//

#include "Info.h"

Info::Info(){
    ofAddListener(ofEvents().keyPressed, this, &Info::keyPressed);
    ofRegisterGetMessages(this);
    info = "";
};

void Info::draw(){
    if(!bInfo) return;
    ofPushStyle();
    
    ofSetColor(255);
    ofLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
    ofLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
    ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), ofGetMouseX() + 5, ofGetMouseY() + 15);
    ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()), 5, 15);
    ofDrawBitmapString(info, 5, 30);
    info = "";
    ofPopStyle();
};

void Info::toggle(){
    bInfo = !bInfo;
};

void Info::keyPressed (ofKeyEventArgs& eventArgs){
    switch (eventArgs.key) {
        case 'i':
            toggle();
            break;
        default:
            break;
    }
}

void Info::gotMessage(ofMessage& msg){
    if(!bInfo) return;
    if(msg.message.substr(0, 6) == "[Info]"){
        info += msg.message.substr(7);
        info += "\n";
    }
}