#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ArduinoWrapper.h"
#include "Info.h"


class testApp : public ofSimpleApp{
    
public:
    
	void setup();
	void update();
	void draw();
    
	void keyPressed(int key);
	void keyReleased(int key);
    
    ArduinoWrapper	arduino;
    Info info;
};

