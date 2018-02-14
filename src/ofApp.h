#pragma once

#include "ofMain.h"
#include "ofxChristieControl.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxOscParameterSync.h"
#include "ofxXmlSettings.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxButton powerOn;
    ofxButton powerOff;
    
      ofxChristieControl projector1;
    ofxPanel gui;
    ofxOscParameterSync sync;
    ofxXmlSettings XML;
    string buf;
    
    string baseIP;
    
    bool powerState = 0;
    int powerCompteur = 1000;
    
    void commandPowerOff();
    void commandPowerOn();
};
