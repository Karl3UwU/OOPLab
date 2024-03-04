#include "Student.h"
#include <cstring>

bool Student::setName(char* s) {
	strcpy_s(name, s);
	return true;
}
char* Student::getName() {
	return name;
}

bool Student::setMathGrade(float x) {
	if (x < 1 || x > 10) return false;
	math = x;
	return true;
}
float Student::getMathGrade() {
	return math;
}

bool Student::setEnglishGrade(float x) {
	if (x < 1 || x > 10) return false;
	english = x;
	return true;
}
float Student::getEnglishGrade() {
	return english;
}

bool Student::setHistoryGrade(float x) {
	if (x < 1 || x > 10) return false;
	history = x;
	return true;
}
float Student::getHistoryGrade() {
	return history;
}

float Student::getAverage() {
	return ((math + english + history) / 3.0f);
}