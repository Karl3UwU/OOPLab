#include "BMW.h"

BMW::BMW() {
    fuelCapacity = 80;
    fuelConsumption = 13; // per 100km
    averageSpeedRain = 55;
    averageSpeedSunny = 105;
    averageSpeedSnow = 55;
}

void BMW::SetFuelCapacity(int capacity) {
    fuelCapacity = capacity;
}

void BMW::SetFuelConsumption(double consumption) {
    fuelConsumption = consumption;
}

void BMW::SetAverageSpeed(Weather condition, double speed) {
    switch (condition) {
        case Weather::Rain: averageSpeedRain = speed; break;
        case Weather::Sunny: averageSpeedSunny = speed; break;
        case Weather::Snow: averageSpeedSnow = speed; break;
    }
}

const char* BMW::GetCarType() const {
    return "BMW";
}

int BMW::GetFuelCapacity() const {
    return fuelCapacity;
}

double BMW::GetFuelConsumption() const {
    return fuelConsumption;
}

double BMW::GetAverageSpeed(Weather condition) const {
    switch (condition) {
        case Weather::Rain: return averageSpeedRain;
        case Weather::Sunny: return averageSpeedSunny;
        case Weather::Snow: return averageSpeedSnow;
    }
    return 0;
}

double BMW::CalculateRaceTime(int circuitLength, Weather condition) const {
    double averageSpeed = GetAverageSpeed(condition);
    return averageSpeed > 0 ? circuitLength / averageSpeed : 0;
}

double BMW::CalculateDistanceTraveled(int circuitLength, Weather condition) const {
    return fuelCapacity;
}

bool BMW::CanFinish(int circuitLength, Weather condition) const {
    double fuelNeeded = (fuelConsumption / 100) * circuitLength;
    return fuelCapacity >= fuelNeeded;
}