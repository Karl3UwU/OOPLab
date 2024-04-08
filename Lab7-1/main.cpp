#include <iostream>
#include "temperature_literals.h"

using namespace temperature;

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << " C" << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << " C" << std::endl;

    return 0;
}