#include "Number.h"
#include <iostream>
#include <cstring>

Number::Number(const char* source, int setBase) {
    base = setBase;
    value = new char[strlen(source) + 1];
    strcpy(value, source);
}

Number::Number(Number& other) {
    base = other.base;
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

Number::Number(const int x) {
    base = 10;

    int len = 0;
    for (int k = x; k; len++, k /= 10);
    if (len == 0) len++;

    value = new char[len+1];
    for (int i = len, k = x; i >= 0; i--, k /= 10) {
        value[i] = k % 10;
    }
}

Number::~Number() {
    delete[] value;
}

Number& Number::operator=(Number& other) {
    if (this != &other) {
        delete[] value;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
        base = other.base;
    }
    return *this;
}

Number& Number::operator=(Number&& other) {
    if (this != &other) {
        delete[] value;
        value = other.value;
        other.value = nullptr;
        std::swap(base, other.base);
    }
    return *this;
}

char& Number::operator[](int index) {
    return value[index];
}

void Number::SwitchBase(int newBase) {
    int decimalValue = GetDecimalValue();

    base = newBase;

    int index = 0;
    char newValue[124];

    while (decimalValue > 0)
    {
        int remainder = decimalValue % newBase;

        if (remainder < 10)
            newValue[index] = remainder + '0';
        else
            newValue[index] = remainder - 10 + 'A';

        decimalValue /= newBase;
        index++;
    }

    newValue[index] = '\0';

    delete[] value;
    value = new char[index + 1];
    for (int i = 0; i < index; i++) {
        value[i] = newValue[index - 1 - i];
    }
    value[index] = '\0';
}

void Number::Print() {
    printf("%s\n", value);
}

int Number::GetDigitsCount() {
    return strlen(value);
}

int Number::GetBase() {
    return base;
}

int Number::GetDecimalValue() {
    int decimalValue = 0;
    int power = 0;

    // Traverse the number string in reverse order
    for (int i = strlen(value) - 1, d=1; i >= 0; i--, d*=10) {
        int digitValue = 0;
        if (value[i] >= '0' && value[i] <= '9') {
            digitValue += d*(value[i] - '0');
        }
        else if (value[i] >= 'A' && value[i] <= 'F') {
            digitValue += d*(value[i] - 'A' + 10);
        }
        else {
            // LMFAO
        }

        decimalValue += digitValue * pow(base, power);
        power++;
    }

    return decimalValue;
}

Number Number::operator+(Number& other) {
    int maxBase = std::max(base, other.base);
    Number result("0", maxBase);

    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    int sum = num1 + num2;

    // Converting sum to result base
    int index = 0;
    while (sum > 0)
    {
        result[index++] = sum % maxBase;
        sum /= maxBase;
    }

    return result;
}

Number Number::operator-(Number& other) {
    int maxBase = std::max(base, other.base);
    Number result("0", maxBase);

    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    int diff = std::abs(num1 - num2);

    // Converting diff to result base
    int index = 0;
    while (diff > 0)
    {
        result[index++] = diff % maxBase;
        diff /= maxBase;
    }

    return result;
}

Number Number::operator--() {

}

bool Number::operator>(Number& other) {
    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    return num1 > num2;
}

bool Number::operator<(Number& other) {
    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    return num1 < num2;
}

bool Number::operator>=(Number& other) {
    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    return num1 >= num2;
}

bool Number::operator<=(Number& other) {
    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    return num1 <= num2;
}

bool Number::operator==(Number& other) {
    int num1 = GetDecimalValue();
    int num2 = other.GetDecimalValue();
    return num1 == num2;
}