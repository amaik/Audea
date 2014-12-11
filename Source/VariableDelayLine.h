/*
  ==============================================================================

    VariableDelayLine.h
    Created: 10 Dec 2014 5:25:11pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#ifndef VARIABLEDELAYLINE_H_INCLUDED
#define VARIABLEDELAYLINE_H_INCLUDED

class VariableDelayLine
{

private:
	float* vdl;
	int delayRead;
	int delayWrite = 0;
	int vdlLength;
	float readFract;
	int readInt;
	float decay;

public:
	VariableDelayLine(){}
	VariableDelayLine(int Length){
		vdl = new float[Length];
		vdlLength = Length;
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
