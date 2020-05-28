#include "ofApp.h"
//Question: What do you typically gitignore on an openframeworks project?
//Question: Where would be a good place to store global variables?
int windowWidth = 800;
int windowHeight = 800;
vector<int> randomStartArr;
vector<int> randomLengthArr;
vector<int> randomGapArr;
vector<int> randomGap;
vector<int> randomGapLength;
vector<int> randomSlopeArr;
vector<int> randomSlopeArr2;
vector<int> ramdomInterruptionStartArr;
vector<int> ramdomInterruptionHeightArr;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(windowWidth, windowHeight);
    ofSetBackgroundColor(238, 234, 233);
    for (int i = 0; i < 20; i++) {
//        QUESTION: what's the difference b/w ofRandom and ofNoise
        randomStartArr.push_back(ofRandom(-50, 50));
        randomLengthArr.push_back(ofRandom(-20, 20));
//        QUESTION: How to get random integer value instead of percentage?
        randomGapArr.push_back(ofRandom(1, 10));
        randomGap.push_back(ofRandom(2, 15));
        randomGapLength.push_back(ofRandom(10, 600));
    }
    
//    40 because there are more slanted lines so we need more variations
    for (int j=0; j < 40; j++) {
        randomSlopeArr.push_back(ofRandom(10, 40));
        randomSlopeArr2.push_back(ofRandom(20, 150));
        ramdomInterruptionStartArr.push_back(ofRandom(100, 700));
        ramdomInterruptionHeightArr.push_back(ofRandom(100, 600));
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw square of horizontal lines:
    // NOTE:
//    * her lines aren't uniform width
//    * starting & ending points vary but when start is to the left, so is the end -- makes a subtle wave effect
    
    // QUESTION: would it be possible to utilize ofDrawGrid to draw horizontal lines?
    ofSetColor(0); // set color of lines to black
    // QUESTION: Is there a way to dynamically get window WxH to dynamically set margin?
    int margin = 100;
    for (int i = 0; i < 20; i++) {
//      QUESTION: Is there a way to see the coordinate grid before drawing lines?
        int lineWidth = windowWidth - randomLengthArr[i]; // add slight variation to width
        int newYCoordinate = margin + (((windowHeight - (margin*2)) / 20) * i); // evenly distribute lines (vertically) within margin
        ofDrawLine(
                   margin + randomStartArr[i],
                   newYCoordinate,
                   lineWidth - (margin - randomStartArr[i]), // note: ofRandomWidth() animates random widths
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
