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

bool toggleHorMove=false;
bool toggleHorMove2=false;
bool toggleSlantMove=false;
bool toggleSlantMove2=false;
bool invertColor=false;
bool randomColor=false;
bool randomDensity=false;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(windowWidth, windowHeight);
    ofSetBackgroundColor(238, 234, 233);
    for (int i = 0; i < 20; i++) {
//        TODO: move random generator to resusable function
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
        ramdomInterruptionStartArr.push_back(ofRandom(90, 620));
        ramdomInterruptionHeightArr.push_back(ofRandom(100, 635));
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
    float time = ofGetElapsedTimef();
    
    if (randomDensity) {
        randomStartArr = {};
        randomLengthArr = {};
        randomGapArr = {};
        randomGap = {};
        randomGapLength = {};
        randomSlopeArr = {};
        randomSlopeArr2 = {};
        ramdomInterruptionStartArr = {};
        ramdomInterruptionHeightArr ={};
        
                for (int i = 0; i < 20; i++) {
            //        TODO: move random generator to resusable function
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
                    ramdomInterruptionStartArr.push_back(ofRandom(90, 620));
                    ramdomInterruptionHeightArr.push_back(ofRandom(100, 635));
                }
    }
    
    
    
    
    
    if (randomColor) {
            ofSetBackgroundColor(ofRandom(255),
                                 ofRandom(255),
                                 ofRandom(255));
    } else {
        invertColor ? ofSetBackgroundColor(0) : ofSetBackgroundColor(238, 234, 233);
    }
    // QUESTION: would it be possible to utilize ofDrawGrid to draw horizontal lines?
    invertColor ? ofSetColor(238, 234, 233) : ofSetColor(0x000000, 128); // set color of lines to slightly opaque black to emulate pen tracing over
    // QUESTION: Is there a way to dynamically get window WxH to dynamically set margin?
    int margin = 100;
    for (int i=0; i < 20; i++) {
//      QUESTION: Is there a way to see the coordinate grid before drawing lines?
        int lineWidth = (windowWidth - (randomDensity ? ofRandom(2, 100) : randomLengthArr[i])); // add slight variation to width
        int lineEnd = lineWidth - (margin - randomStartArr[i]); // make line ending point correlated to starting
        int newYCoordinate = margin + (((windowHeight - (margin*2)) / 20) * i); // evenly distribute lines (vertically) within margin
        for (int j=0; j < 6; j++) {
//            TODO: replace this by using noise to draw line to emulate shaky hand
            ofSetLineWidth(randomGap[j] * 0.2); // slightly vary line width to emulate hand writing

            // HORIZONTAL LINE GAPS (INTERRUPTIONS)
            // there are five gaps in vera's work so there's a 25% chance that a line will have a small gap
            if (randomGapArr[i] > 6.5) {

                // if this is our 1/5 line where we create gap, then draw two slightly separate lines
                int firstLineEnd = randomGapLength[i];
//                TODO: Break ofDrawLine into reusable function
//                TODO: Add more variable lengths, to multiply pen stroke effect
                ofDrawLine(
                           margin + randomStartArr[i] + j,
                           newYCoordinate,
                           toggleHorMove ? ofRandomWidth() : firstLineEnd - j, // note: ofRandomWidth() animates random widths
                           newYCoordinate); // y coordinate remains the same bc line is straight (ofRandomHeight is fun!)

                ofDrawLine(
                           firstLineEnd + (randomGap[i]), // variable gap length
                           newYCoordinate,
                           toggleHorMove ? ofRandomWidth() : lineEnd + (j *6), // note: ofRandomWidth() animates random widths
                           newYCoordinate); // y coordinate remains the same bc line is straight (ofRandomHeight is fun!)
            } else {
                ofDrawLine(
                          (margin + randomStartArr[i]),
                          newYCoordinate,
                          toggleHorMove2 ? ofRandomWidth() : lineEnd - (j * 6), // note: ofRandomWidth() animates random widths
                          newYCoordinate); // y coordinate remains the same bc line is straight (ofRandomHeight is fun!)
            }
        }
        
//        TODO: maybe try intercepting one or two slanted lines with the gap
//        TODO: get subtle slope when drawing lines
//        SLANTED line interruptions:
//        NOTE: all of her slopes are positive and over 90 degrees.
        invertColor ? ofSetColor(238, 234, 233) : ofSetColor(0); // set color of lines to slightly opaque black to emulate pen tracing over
        ofSetLineWidth(2); // slightly vary line width to emulate hand writing

        for (int k = 0; k < 40; k ++) {
            float centerX = toggleSlantMove ? ofRandom(90, 620) : ramdomInterruptionStartArr[k];
            float centerY = toggleSlantMove2 ? ofRandom(100, 635) : ramdomInterruptionHeightArr[k];
          
            float slopeX = randomSlopeArr2[k];
            float slopeY = randomSlopeArr[k] + k * 2;

//            RISE OVER RUN :)
            ofDrawLine(centerX + slopeX,
                       centerY - slopeY,
                       centerX,
                       centerY
                       );
        };
        
        
        
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'z') {
        toggleHorMove = !toggleHorMove;
    } else if (key == 'x') {
        toggleHorMove2 = !toggleHorMove2;
    } else if (key == 'c') {
        toggleSlantMove = !toggleSlantMove;
    } else if (key == 'v') {
        toggleSlantMove2 = !toggleSlantMove2;
    } else if (key == 'b') {
        invertColor = !invertColor;
    } else if (key == 'n') {
        randomColor = !randomColor;
    } else if (key == 'm') {
        randomDensity = !randomDensity;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

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
