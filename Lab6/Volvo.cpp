#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 60;
    fuelConsumption = 9; // per 100km
    averageSpeedRain = 60;
    averageSpeedSunny = 100;
    averageSpeedSnow = 50;
}

void Volvo::SetFuelCapacity(int capacity) {
    fuelCapacity = capacity;
}

void Volvo::SetFuelConsumption(double consumption) {
    fuelConsumption = consumption;
}

void Volvo::SetAverageSpeed(Weather condition, double speed) {
    switch (condition) {
        case Weather::Rain: averageSpeedRain = speed; break;
        case Weather::Sunny: averageSpeedSunny = speed; break;
        case Weather::Snow: averageSpeedSnow = speed; break;
    }
}

const char* Volvo::GetCarType() const {
    return "Volvo";
}

int Volvo::GetFuelCapacity() const {
    return fuelCapacity;
}

double Volvo::GetFuelConsumption() const {
    return fuelConsumption;
}

double Volvo::GetAverageSpeed(Weather condition) const {
    switch (condition) {
        case Weather::Rain: return averageSpeedRain;
        case Weather::Sunny: return averageSpeedSunny;
        case Weather::Snow: return averageSpeedSnow;
    }
    return 0;
}

double Volvo::CalculateRaceTime(int circuitLength, Weather condition) const {
    double averageSpeed = GetAverageSpeed(condition);
    return averageSpeed > 0 ? circuitLength / averageSpeed : -1;
}

double Volvo::CalculateDistanceTraveled(int circuitLength, Weather condition) const {
    return fuelCapacity;
}

bool Volvo::CanFinish(int circuitLength, Weather condition) const {
    double fuelNeeded = (fuelConsumption / 100) * circuitLength;
    return fuelCapacity >= fuelNeeded;
}