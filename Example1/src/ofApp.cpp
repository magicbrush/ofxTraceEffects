#include "ofApp.h"
#include "ofxTraceEffects.h"
#include "ofxTraceRippleEffects.h"

//--------------------------------------------------------------
void ofApp::setup(){
	te = new ofxTraceRippleEffect;
}

//--------------------------------------------------------------
void ofApp::update(){
	te->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	te->draw();
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
	te->ContinueTrace(ofVec3f(x,y,0));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	te->StartTrace(ofVec3f(x,y,0));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	te->StopTrace(ofVec3f(x,y,0));
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
