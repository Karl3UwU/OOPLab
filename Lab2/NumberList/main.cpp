#include <iostream>
#include "NumberList.h"

int main() {
    NumberList test;
    test.Init();

    std::cout << "Adding numbers:\n";
    for (int i = 1; i <= 100; i++) {
        test.Add(i);
    }

    return 0;
}
