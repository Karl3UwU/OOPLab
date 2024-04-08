#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 40;
    fuelConsumption = 77; // per 100km
    averageSpeedRain = 95;
    averageSpeedSunny = 125;
    averageSpeedSnow = 87;
}

void Seat::SetFuelCapacity(int capacity) {
    fuelCapacity = capacity;
}

void Seat::SetFuelConsumption(double consumption) {
    fuelConsumption = consumption;
}

void Seat::SetAverageSpeed(Weather condition, double speed) {
    switch (condition) {
        case Weather::Rain: averageSpeedRain = speed; break;
        case Weather::Sunny: averageSpeedSunny = speed; break;
        case Weather::Snow: averageSpeedSnow = speed; break;
    }
}

const char* Seat::GetCarType() const {
    return "Seat";
}

int Seat::GetFuelCapacity() const {
    return fuelCapacity;
}

double Seat::GetFuelConsumption() const {
    return fuelConsumption;
}

double Seat::GetAverageSpeed(Weather condition) const {
    switch (condition) {
        case Weather::Rain: return averageSpeedRain;
        case Weather::Sunny: return averageSpeedSunny;
        case Weather::Snow: return averageSpeedSnow;
    }
    return 0;
}

double Seat::CalculateRaceTime(int circuitLength, Weather condition) const {
    double averageSpeed = GetAverageSpeed(condition);
    return averageSpeed > 0 ? circuitLength / averageSpeed : 0;
}

double Seat::CalculateDistanceTraveled(int circuitLength, Weather condition) const {
    return fuelCapacity;
}

bool Seat::CanFinish(int circuitLength, Weather condition) const {
    double fuelNeeded = (fuelConsumption / 100) * circuitLength;
    return fuelCapacity >= fuelNeeded;
}