#include "StudentComp.h"
#include <cstring>

int compareName(Student &a, Student &b) {
	int cmp = strcmp(a.getName(), b.getName());
	if (cmp == 0) return 0;
	else if (cmp < 0) return 1;
	else return -1;
}

int compareMath(Student &a, Student &b) {
	float cmp = a.getMathGrade() - b.getMathGrade();
	if (cmp == 0) return 0;
	else if (cmp > 0) return 1;
	else return -1;
}

int compareEnglish(Student &a, Student &b) {
	float cmp = a.getEnglishGrade() - b.getEnglishGrade();
	if (cmp == 0) return 0;
	else if (cmp > 0) return 1;
	else return -1;
}

int compareHistory(Student &a, Student &b) {
	float cmp = a.getHistoryGrade() - b.getHistoryGrade();
	if (cmp == 0) return 0;
	else if (cmp > 0) return 1;
	else return -1;
}

int compareAverage(Student &a, Student &b) {
	float cmp = a.getAverage() - b.getAverage();
	if (cmp == 0) return 0;
	else if (cmp > 0) return 1;
	else return -1;
}