#pragma once

class Student {
private:
	char name[48] = "";
	float math=0.f, english=0.f, history=0.f;
public:
	bool setName(char* s);
	char* getName();

	bool  setMathGrade(float x);
	float getMathGrade();

	bool  setEnglishGrade(float x);
	float getEnglishGrade();

	bool  setHistoryGrade(float x);
	float getHistoryGrade();

	float getAverage();
};