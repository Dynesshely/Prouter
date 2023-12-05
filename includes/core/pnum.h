#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "./pint.h"

template<typename T>
class pnum {
private:
    T value;
    std::string varName;
    std::vector<T> usedValues;
    std::function<void(T)> onChangedFunc = nullptr;

public:
    pnum();

    pnum(T val);

    T *address();

    [[nodiscard]] T getValue() const;

    void setValue(T val);

    pnum &named(std::string str);

    std::string name();

    std::string *nameAddress();

    T &operator[](int index);

    T &operator[](const pint &index);

    T historicalValuesCount();

    pnum &operator++(int);

    pnum &operator--(int);

    T operator+(T val) const;

    T operator-(T val) const;

    T operator*(T val) const;

    T operator/(T val) const;

    friend T operator+(T lhs, const pnum &rhs);

    friend T operator-(T lhs, const pnum &rhs);

    friend T operator*(T lhs, const pnum &rhs);

    friend T operator/(T lhs, const pnum &rhs);

    pnum operator+(pnum &val) const;

    pnum operator-(pnum &val) const;

    pnum operator*(pnum &val) const;

    pnum operator/(pnum &val) const;

    friend pnum operator+(const pnum &lhs, const pnum &rhs);

    friend pnum operator-(const pnum &lhs, const pnum &rhs);

    friend pnum operator*(const pnum &lhs, const pnum &rhs);

    friend pnum operator/(const pnum &lhs, const pnum &rhs);

    bool operator<(T val) const;

    bool operator>(T val) const;

    bool operator<=(T val) const;

    bool operator>=(T val) const;

    bool operator==(T val) const;

    bool operator!=(T val) const;

    friend bool operator<(T lhs, const pnum &rhs);

    friend bool operator>(T lhs, const pnum &rhs);

    friend bool operator<=(T lhs, const pnum &rhs);

    friend bool operator>=(T lhs, const pnum &rhs);

    friend bool operator==(T lhs, const pnum &rhs);

    friend bool operator!=(T lhs, const pnum &rhs);

    bool operator<(pnum &val) const;

    bool operator>(pnum &val) const;

    bool operator<=(pnum &val) const;

    bool operator>=(pnum &val) const;

    bool operator==(pnum &val) const;

    bool operator!=(pnum &val) const;

    friend bool operator<(const pnum &lhs, const pnum &rhs);

    friend bool operator>(const pnum &lhs, const pnum &rhs);

    friend bool operator<=(const pnum &lhs, const pnum &rhs);

    friend bool operator>=(const pnum &lhs, const pnum &rhs);

    friend bool operator==(const pnum &lhs, const pnum &rhs);

    friend bool operator!=(const pnum &lhs, const pnum &rhs);

    pnum &operator=(T &val);

    pnum &operator=(const T &val);

    pnum &operator=(const pnum &other);

    operator T() const;

    pnum &onChanged(std::function<void(T)> func);
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const pnum<T> &obj);

template<typename T>
pnum<T> &operator+=(pnum<T> &obj, T val);

template<typename T>
pnum<T> &operator-=(pnum<T> &obj, T val);

template<typename T>
pnum<T> &operator*=(pnum<T> &obj, T val);

template<typename T>
pnum<T> &operator/=(pnum<T> &obj, T val);

template<typename T>
pnum<T> &operator+=(pnum<T> &obj, pnum<T> &val);

template<typename T>
pnum<T> &operator-=(pnum<T> &obj, pnum<T> &val);

template<typename T>
pnum<T> &operator*=(pnum<T> &obj, pnum<T> &val);

template<typename T>
pnum<T> &operator/=(pnum<T> &obj, pnum<T> &val);

template<typename T>
pnum<T> &operator++(pnum<T> &obj);

template<typename T>
pnum<T> &operator--(pnum<T> &obj);

#include "../../src/core/pnum.cpp"
