#pragma once
#include "ofxTraceEffects.h"




class ofxTraceRippleEffect :
	public ofxTraceEffects
{
public:
	class Ripple
	{
	public:
		Ripple(
			ofVec3f pos=ofVec3f(0,0,0),
			float life =5.0f );
		~Ripple();

		void draw();
		void update();
		float getLife();

		float Life;
		ofVec3f Pos;
	};
public:
	ofxTraceRippleEffect(void);
	virtual ~ofxTraceRippleEffect(void);

	virtual void StartTrace( ofVec3f P );

	virtual void ContinueTrace( ofVec3f P );

	void addRipple( ofVec3f &P );

	virtual void StopTrace( ofVec3f P );

	virtual void draw();

	virtual void update();

private:
	deque<Ripple> ripples;
	ofVec3f LastPos;


};

