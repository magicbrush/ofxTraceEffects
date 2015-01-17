#pragma once
#include "ofMain.h"

class ofxTraceEffects
{
public:
	ofxTraceEffects();
	virtual ~ofxTraceEffects();

	virtual void StartTrace(ofVec3f P)=0;
	virtual void ContinueTrace(ofVec3f P)=0;
	virtual void StopTrace(ofVec3f P)=0;

	virtual void draw()=0;
	virtual void update()=0;
};



