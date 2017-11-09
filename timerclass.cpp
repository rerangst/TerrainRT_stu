///////////////////////////////////////////////////////////////////////////////
// Filename: timerclass.cpp
///////////////////////////////////////////////////////////////////////////////
#include "timerclass.h"


TimerClass::TimerClass()
{
}


TimerClass::TimerClass(const TimerClass& other)
{
}


TimerClass::~TimerClass()
{
}


bool TimerClass::Initialize()
{
	//INT64 frequency;


	// Get the cycles per second speed for this system.
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	if(m_frequency == 0)
	{
		return false;
	}
	
	// Find out how many times the frequency counter ticks every millisecond.
	m_ticksPerMs = (float)(m_frequency / 1000);

	// Get the initial start time.
	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

	return true;
}


void TimerClass::Frame()
{
	INT64 currentTime;
	float timeDifference;


	// Query the current time.
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	// Calculate the difference in time since the last time we queried for the current time.
	timeDifference = (float)(currentTime - m_startTime);

	// Calculate the frame time.
	m_frameTime = timeDifference / m_ticksPerMs;

	// Restart the timer.
	m_startTime = currentTime;

	return;
}


float TimerClass::GetTime()
{
	return m_frameTime;
}


//void TimerClass::StartTimer()
//{
//	QueryPerformanceCounter((LARGE_INTEGER*)&m_beginTime);
//	return;
//}
//
//
//void TimerClass::StopTimer()
//{
//	QueryPerformanceCounter((LARGE_INTEGER*)&m_endTime);
//	return;
//}
//
//
//int TimerClass::GetTiming()
//{
//	float elapsedTicks;
//	INT64 frequency;
//	float milliseconds;
//
//
//	// Get the elapsed ticks between the two times.
//	elapsedTicks = (float)(m_endTime - m_beginTime);
//
//	// Get the ticks per second speed of the timer.
//	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
//
//	// Calculate the elapsed time in milliseconds.
//	milliseconds = (elapsedTicks / (float)frequency) * 1000.0f;
//
//	return (int)milliseconds;
//}