#pragma once
#include "Car.h"

class BMW : public Car {
private:
    int fuelCapacity;
    double fuelConsumption;
    double averageSpeedRain;
    double averageSpeedSunny;
    double averageSpeedSnow;

public:
    BMW();
    void SetFuelCapacity(int capacity) override;
    void SetFuelConsumption(double consumption) override;
    void SetAverageSpeed(Weather condition, double speed) override;

    const char* GetCarType() const override;
    int GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather condition) const override;
    double CalculateRaceTime(int circuitLength, Weather condition) const override;
    double CalculateDistanceTraveled(int circuitLength, Weather condition) const override;
    bool CanFinish(int circuitLength, Weather condition) const override;
};