#include "Circuit.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

Circuit::Circuit() : length(0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (Car* car : cars) {
        delete car;
    }
    for (RaceResult* res : results) {
        delete res;
    }
}

void Circuit::SetLength(int l) {
    length = l;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    for (Car* car : cars) {
        if (!car->CanFinish(length, weather)) {
            RaceResult* result = new RaceResult();
            result->finished = false;
            result->distance = car->GetFuelCapacity();
            result->time = -1;
            result->car = car;
            results.push_back(result);
            continue;
        }
        double time = car->CalculateRaceTime(length, weather);
        RaceResult *result = new RaceResult();
        result->finished = true;
        result->distance = length;
        result->time = time;
        result->car = car;
        results.push_back(result);
    }
}

void Circuit::ShowFinalRanks() {
    // sorting xd
    for (int i = 0; i < results.size(); i++) {
        for (int k = i + 1; k < results.size(); k++) {
            if (results[i]->finished == results[k]->finished && results[k]->time < results[i]->time) {
                RaceResult* aux = results[i];
                results[i] = results[k];
                results[k] = aux;
            }
        }
    }

    // results
    for (int i = 0, place = 1; i < results.size(); i++, place++) {
        RaceResult *r = results[i];
        printf("Place %d: %s (%f)\n", place, r->car->GetCarType(), r->time);
    }
}

void Circuit::ShowWhoDidNotFinish() {
    for (RaceResult* res : results) {
        if (res->finished == false) {
            std::cout << "A car could not finish the race." << std::endl;
            return;
        }
    }
}