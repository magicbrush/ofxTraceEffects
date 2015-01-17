#include "ofxTraceRippleEffects.h"

ofxTraceRippleEffect::ofxTraceRippleEffect(void)
{

}

ofxTraceRippleEffect::~ofxTraceRippleEffect(void)
{

}

void ofxTraceRippleEffect::StartTrace( ofVec3f P )
{
	LastPos = P;
}

void ofxTraceRippleEffect::ContinueTrace( ofVec3f P )
{
	addRipple(P);
}

void ofxTraceRippleEffect::StopTrace( ofVec3f P )
{
	addRipple(P);
}

void ofxTraceRippleEffect::draw()
{
	deque<Ripple>::iterator itr;
	for(itr=ripples.begin();itr<ripples.end();itr++)
	{
		itr->draw();
	}

}

void ofxTraceRippleEffect::update()
{
	deque<Ripple>::iterator itr;
	for(itr=ripples.begin();itr<ripples.end();itr++)
	{
		itr->update();
	}

	if(ripples.size()>0)
	{
		if(ripples[0].getLife()<=0)
		{
			ripples.pop_front();
		}
	}
}

void ofxTraceRippleEffect::addRipple( ofVec3f &P )
{
	if(P.distance(LastPos)>=10.0f)
	{
		Ripple R(P);
		ripples.push_back(R);
	}
}

ofxTraceRippleEffect::Ripple::Ripple(ofVec3f pos,
									 float life /*=100.0f*/ ):
	Life(life),Pos(pos)
{
	
}

ofxTraceRippleEffect::Ripple::~Ripple()
{

}

void ofxTraceRippleEffect::Ripple::draw()
{
	ofPushStyle();
	ofFloatColor C(0.0f,0.0f,0.0f,ofClamp(Life/5.0f,0.0f,1.0f));
	ofSetColor(C);
	ofSetLineWidth(Life/2.0f);
	ofNoFill();
	ofCircle(Pos,Life*3.0f);
	ofPopStyle();
}

void ofxTraceRippleEffect::Ripple::update()
{
	Life -= ofGetLastFrameTime();
}

float ofxTraceRippleEffect::Ripple::getLife()
{
	return Life;
}
