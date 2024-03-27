#pragma once

class Number {
private:
    char* value;
    int base;
    int GetDecimalValue();

public:
    Number(const char* value, int base);
    Number(Number& other);
    Number(const int x);
    ~Number();

    Number& operator=(Number& other);
    Number& operator=(Number&& other);

    char& operator[](int index);
    Number operator+(Number& other);
    Number operator-(Number& other);
    bool operator>(Number& other);
    bool operator<(Number& other);
    bool operator>=(Number& other);
    bool operator<=(Number& other);
    bool operator==(Number& other);

    Number operator--();

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};