#include <iostream>
#include "Student.h"
#include "StudentComp.h"

int main()
{
	char inteliName[] = "ElGay", dumbName[] = "Hughie";

	Student intelligent;
	intelligent.setName(inteliName);
	intelligent.setMathGrade(9);
	intelligent.setEnglishGrade(10);
	intelligent.setHistoryGrade(3);

	Student dumbass;
	dumbass.setName(dumbName);
	dumbass.setMathGrade(3);
	dumbass.setEnglishGrade(10);
	dumbass.setHistoryGrade(8);

	std::cout << compareName(intelligent, dumbass) << '\n';
	std::cout << compareMath(intelligent, dumbass) << '\n';
	std::cout << compareEnglish(intelligent, dumbass) << '\n';
	std::cout << compareHistory(intelligent, dumbass) << '\n';

	return 0;
}