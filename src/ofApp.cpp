#include "ofApp.h"

//Question: Where would be a good place to store global variables?
int windowWidth = 800;
int windowHeight = 800;
vector<int> randomStartArr;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(windowWidth, windowHeight);
    ofSetBackgroundColor(238, 234, 233);
    for (int i = 0; i < 20; i++) {
//        QUESTION: what's the difference b/w ofRandom and ofNoise
        randomStartArr.push_back(ofRandom(-50, 50));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw square of horizontal lines:
    // NOTE:
//    * her lines aren't uniform length
//    * starting & ending points vary but when start is to the left, so is the end -- makes a subtle wave effect
    // QUESTION: would it be possible to utilize ofDrawGrid to draw horizontal lines?
    ofSetColor(0); // set color of lines to black
    // QUESTION: Is there a way to dynamically get window WxH to dynamically set margin?
    int margin = 100;
    for (int i = 0; i < 20; i++) {
//      QUESTION: Is there a way to see the coordinate grid before drawing lines?
        int newYCoordinate = margin + (((windowHeight - (margin*2)) / 20) * i); // evenly distribute lines (vertically) within margin
        ofDrawLine(
                   margin + randomStartArr[i],
                   newYCoordinate,
                   windowWidth - (margin - randomStartArr[i]), // note: ofRandomWidth() animates random widths
                   newYCoordinate); // y coordinate remains the same bc line is straight (ofRandomHeight is fun!)
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
