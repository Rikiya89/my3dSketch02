#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableDepthTest();

    for(int i = 0; i < NUM_SPHERES; i++){
        positions.push_back(ofVec3f(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),
                                    ofRandom(-ofGetHeight()/2, ofGetHeight()/2),
                                    ofRandom(-500, 500)));
        radii.push_back(ofRandom(10, 50));
        colors.push_back(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
        originalRadii.push_back(radii[i]);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // Change sphere radii with time for a pulsing effect
    float time = ofGetElapsedTimef();
    for(int i = 0; i < NUM_SPHERES; i++){
        radii[i] = originalRadii[i] + 10 * sin(0.5 * time + i); // Each sphere has a different phase
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    // Rotate on all three axes for more dynamic rotation
    ofRotateXDeg(ofGetFrameNum() * 0.3);
    ofRotateYDeg(ofGetFrameNum() * 0.5);
    ofRotateZDeg(ofGetFrameNum() * 0.2);
    
    for(int i = 0; i < NUM_SPHERES; i++){
        ofSetColor(colors[i].getLerped(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), 0.01)); // Slow color transition
        ofDrawSphere(positions[i], radii[i] * scale);
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
    scale = ofMap(y, 0, ofGetHeight(), 0.5, 2.0);
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
