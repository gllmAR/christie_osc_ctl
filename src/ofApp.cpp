#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    //Your projectors IP, and if its not PJLINK try NEC
    

    
    //string baseIP = "10.33.2.142";
    
    projector1.setup(baseIP,Christie_MODE,"");
    
    ofSetFrameRate(30);
    ofSetBackgroundColor(50, 50, 50);
    
    gui.setup("christieOscCtl");
    gui.setName("christieOscCtl");
    gui.add(powerOn.setup("powerOn"));
    gui.add(powerOff.setup("powerOff"));
    
    powerOff.addListener(this, &ofApp::commandPowerOff);
    powerOn.addListener(this, &ofApp::commandPowerOn);
    
    if( XML.loadFile("ethernet.xml") ){
        cout<<"ethernet.xml loaded!"<<endl;
        baseIP = XML.getValue("CONFIG:IP", "10.0.0.1");
        cout<<"base ip config is : "<<baseIP<<endl;
    }else{
        cout<<"unable to load ethernet.xml check data/ folder"<<endl;
    }
    
     projector1.setup(baseIP,Christie_MODE,"");
    
    sync.setup((ofParameterGroup&)gui.getParameter(),10098,"localhost",10099);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    powerCompteur++;
    
    if (powerCompteur> 1000){
        cout<<"<--------POWER GET-----------> @ "<<ofGetTimestampString()<<endl;

        projector1.sendCommand("powerGet");
        powerCompteur = 0;
    }
    sync.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    ofDrawBitmapString(baseIP, 10, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'o')  projector1.sendCommand("powerOff");
    if(key == 'i')  projector1.sendCommand("powerOn");
    if(key == 'u')  projector1.sendCommand("powerGet");

}


//--------------------------------------------------------------


void ofApp::commandPowerOff(){
    cout<<"<--------POWER OFF-----------> @ "<<ofGetTimestampString()<<endl;
    projector1.sendCommand("powerOff");
}
//--------------------------------------------------------------
void ofApp::commandPowerOn(){
    cout<<"<--------POWER ON-----------> @ "<<ofGetTimestampString()<<endl;

    projector1.sendCommand("powerOn");
}
//--------------------------------------------------------------



//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------


