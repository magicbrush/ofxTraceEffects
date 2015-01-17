#include "ofApp.h"
#include "ofxTraceEffects.h"
#include "ofxTraceRippleEffects.h"

//--------------------------------------------------------------
void ofApp::setup(){
	resizeFBO(ofGetWidth(),ofGetHeight());
	te = new ofxTraceRippleEffect;
}

//--------------------------------------------------------------
void ofApp::update(){
	te->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	F.begin();
	te->draw();
	F.end();
	F.draw(0,0,ofGetWidth(),ofGetHeight());
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

void ofApp::resizeFBO( int param1, int param2 )
{
	F.allocate(param1,param2,GL_RGBA16F);
	F.begin();
	ofClear(0,0,0,0);
	F.end();
}
