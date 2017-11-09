#pragma once
#ifndef POSITIONCLASS_H
#define POSITIONCLASS_H
#include <math.h>

class PositionClass
{
	// down, up ~ y
	// turnLeft, turnRight ~ ry
	// lookup, lookdown ~ rx
	// speed= frameTime* gia toc( ect: 1.0f, 5.0f,...)
	float a_moveSpeedUp ; 
	float a_moveSpeedDown ;
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;

	float m_frameTime;

	float m_forwardSpeed, m_backwardSpeed;
	float m_upwardSpeed, m_downwardSpeed;
	float m_leftTurnSpeed, m_rightTurnSpeed;
	float m_lookUpSpeed, m_lookDownSpeed;
public:
	PositionClass();
	~PositionClass();
	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	void GetPosition(float&, float&, float&);
	void GetRotation(float&, float&, float&);
	
	void SetFrameTime(float time);
	
	void MoveForward(bool keydown);
	void MoveBackward(bool keydown);
	void MoveUpward(bool keydown);
	void MoveDownward(bool keydown);
	void TurnLeft(bool keydown);
	void TurnRight(bool keydown);
	void LookUpward(bool keydown);
	void LookDownward(bool keydown);
};

#endif // !POSITIONCLASS_H


