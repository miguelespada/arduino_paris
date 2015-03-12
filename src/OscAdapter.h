//
//  OscAdapter.h
//  pull_arduino
//
//  Created by miguel on 30/10/14.
//
//

#ifndef __pull_arduino__OscAdapter__
#define __pull_arduino__OscAdapter__

#include <stdio.h>

#include "ofxOsc.h"

class OscAdapter{
    
    ofxOscSender sender;
public:
    OscAdapter();
    void init(){
        
    }
    string host = "localhost";
    int port = 8080;
    void sendAction(string msg);
};
#endif /* defined(__pull_arduino__OscAdapter__) */
