/*
  ==============================================================================

    VariableDelayLine.h
    Created: 10 Dec 2014 5:25:11pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#ifndef VARIABLEDELAYLINE_H_INCLUDED
#define VARIABLEDELAYLINE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class VariableDelayLine
{

private:
	float* vdl = 0;
	int delayRead = 0;
	int delayWrite = 0;
	int vdlLength = 0;
	float readFract = 0;
	int readInt = 0;
	float decay = 0;

public:
	VariableDelayLine(int Length){
		vdl = new float[Length];
		for (int i = Length; --i >= 0;)
			*(vdl + i) = 0;
		vdlLength = Length;
	}
	

	~VariableDelayLine(){
		delete[] vdl;
	}

	float* getBuffer(){
		return vdl;
	}

	void setDecay(float newDecay){ decay = newDecay; };


	float  readWrite(float value);
	float  getValueAtOffset(int offset);
	void   Set(float value);

};




#endif  // VARIABLEDELAYLINE_H_INCLUDED
