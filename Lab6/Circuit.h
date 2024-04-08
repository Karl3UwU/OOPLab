#pragma once
#include "Car.h"
#include <vector>

struct RaceResult {
    bool finished;
    double time;
    double distance;
    Car* car;
};

class Circuit {
private:
    std::vector<Car*> cars;
    std::vector<RaceResult*> results;
    int length;
    Weather weather;

public:
    Circuit();
    ~Circuit();

    void SetLength(int l);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};