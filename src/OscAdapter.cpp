//
//  OscAdapter.cpp
//  pull_arduino
//
//  Created by miguel on 30/10/14.
//
//

#include "OscAdapter.h"

OscAdapter::OscAdapter(){
    host = "localhost";
    port = 8080;
    sender.setup(host, port);
    cout << "Sending to "<< host << " " << port << endl;
}

void OscAdapter::sendAction(string msg){
    
    ofxOscMessage m;
    m.setAddress(msg);
    sender.sendMessage(m);
}
