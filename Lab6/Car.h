#pragma once
#include "Weather.h"
#include "string"

class Car {
public:
    virtual ~Car() = default;
    virtual void SetFuelCapacity(int capacity) = 0;
    virtual void SetFuelConsumption(double consumption) = 0;
    virtual void SetAverageSpeed(Weather condition, double speed) = 0;

    virtual const char* GetCarType() const = 0;
    virtual int GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetAverageSpeed(Weather condition) const = 0;
    virtual double CalculateRaceTime(int circuitLength, Weather condition) const = 0;
    virtual double CalculateDistanceTraveled(int circuitLength, Weather condition) const = 0;
    virtual bool CanFinish(int circuitLength, Weather condition) const = 0;
};
