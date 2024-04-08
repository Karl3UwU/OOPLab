#pragma once

namespace temperature {

    float kelvinToCelsius(float kelvin) {
        return kelvin - 273.15f;
    }

    float fahrenheitToCelsius(float fahrenheit) {
        return (fahrenheit - 32.0f) * 5.0f / 9.0f;
    }

    float operator"" _Kelvin(unsigned long long kelvin) {
        return kelvinToCelsius(kelvin);
    }

    float operator"" _Fahrenheit(unsigned long long fahrenheit) {
        return fahrenheitToCelsius(fahrenheit);
    }

}