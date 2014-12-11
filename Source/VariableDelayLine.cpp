/*
  ==============================================================================

    VariableDelayLine.cpp
    Created: 10 Dec 2014 5:25:11pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "VariableDelayLine.h"



float VariableDelayLine::getValueAtOffset(int offset)
{
	int ValuePosition = delayWrite - offset;
	if (ValuePosition < 0)
		ValuePosition += vdlLength -1;
	return vdl[ValuePosition];
}

void VariableDelayLine::Set(float value)
{
	readInt = (int)value;
	readFract = value - readInt;
}

float VariableDelayLine::readWrite(float invalue)
{
	int readPosition = delayWrite - readInt;
	if (readPosition < 0)
		readPosition += vdlLength-1;
	if (readInt == 0){
		vdl[delayWrite] = invalue;
		if (++delayWrite >= vdlLength)
			delayWrite = 0;
	}
	float out = vdl[readPosition];
	if (--readPosition < 0)
		readPosition += vdlLength-1;
	out += (vdl[readPosition] - out) * readFract;
	if (readInt > 0){
		vdl[delayWrite] = invalue;
		if (++delayWrite >= vdlLength)
			delayWrite = 0;
	}
	return out * decay;
}