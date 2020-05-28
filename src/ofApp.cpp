#include "ofApp.h"

//Question: Where would be a good place to store global variables?
int windowWidth = 800;
int windowHeight = 800;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(windowWidth, windowHeight);
    ofSetBackgroundColor(238, 234, 233);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw square of horizontal lines:
    // QUESTION: would it be possible to utilize ofDrawGrid to draw horizontal lines?
    ofSetColor(0); // set color of lines to black
    // QUESTION: Is there a way to dynamically get window WxH to dynamically set margin?
    int margin = 100;
    for (int i = 0; i < 20; i++) {
//      QUESTION: Is there a way to see the coordinate grid before drawing lines?
        int newYCoordinate = margin + (((windowHeight - (margin*2)) / 20) * i); // evenly distribute lines (vertically) within margin
        ofDrawLine(
                   margin,
                   newYCoordinate,
                   windowHeight - margin, // set uniform line length
                   newYCoordinate);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

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
