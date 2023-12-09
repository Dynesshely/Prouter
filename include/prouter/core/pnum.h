#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include <prouter/core/pint.h>

template<typename T>
class pnum {
private:
    T value;
    std::string varName;
    std::vector<T> usedValues;
    std::function<void(T)> onChangedFunc = nullptr;

public:
    pnum() : value(0) { setValue(0); }

    pnum(T val) : value(val) { setValue(val); }

    T *address() { return &value; }

    [[nodiscard]] T getValue() const { return value; }

    void setValue(T val) {
        value = val;
        usedValues.push_back(value);

        if (onChangedFunc != nullptr)
            onChangedFunc(val);
    }

    pnum &named(std::string str) {
        varName = std::move(str);
        return *this;
    }

    std::string name() {
        return varName;
    }

    std::string *nameAddress() {
        return &varName;
    }

    std::string history(const std::string &conj = " -> ") {
        std::string text;
        for (int k = 0; k < this->historicalValuesCount(); ++k) {
            text += std::to_string((*this)[k]);

            if (k < this->historicalValuesCount() - 1)
                text += conj;
        }
        return text;
    }

    T &operator[](int index) {
        if (index >= 0.0 && index < usedValues.size())
            return usedValues[index];
        else
            exit(-1);
    }

    T &operator[](const pint &index) {
        if (index >= 0 && index.getValue() < usedValues.size())
            return usedValues[index.getValue()];
        else
            exit(-1);
    }

    T historicalValuesCount() { return (T) usedValues.size(); }

    pnum &operator++(int) {
        setValue(value + 1);
        return *this;
    }

    pnum &operator--(int) {
        setValue(value - 1);
        return *this;
    }

    T operator+(T val) const { return value + val; }

    T operator-(T val) const { return value - val; }

    T operator*(T val) const { return value * val; }

    T operator/(T val) const { return value / val; }

    friend T operator+(T lhs, const pnum &rhs) {
        return lhs + rhs.getValue();
    }

    friend T operator-(T lhs, const pnum &rhs) {
        return lhs - rhs.getValue();
    }

    friend T operator*(T lhs, const pnum &rhs) {
        return lhs * rhs.getValue();
    }

    friend T operator/(T lhs, const pnum &rhs) {
        return lhs / rhs.getValue();
    }

    pnum operator+(pnum &val) const { return {value + val.getValue()}; }

    pnum operator-(pnum &val) const { return {value - val.getValue()}; }

    pnum operator*(pnum &val) const { return {value * val.getValue()}; }

    pnum operator/(pnum &val) const { return {value / val.getValue()}; }

    friend pnum operator+(const pnum &lhs, const pnum &rhs) {
        return {lhs + rhs.getValue()};
    }

    friend pnum operator-(const pnum &lhs, const pnum &rhs) {
        return {lhs - rhs.getValue()};
    }

    friend pnum operator*(const pnum &lhs, const pnum &rhs) {
        return {lhs * rhs.getValue()};
    }

    friend pnum operator/(const pnum &lhs, const pnum &rhs) {
        return {lhs / rhs.getValue()};
    }

    bool operator<(T val) const { return value < val; }

    bool operator>(T val) const { return value > val; }

    bool operator<=(T val) const { return value <= val; }

    bool operator>=(T val) const { return value >= val; }

    bool operator==(T val) const { return value == val; }

    bool operator!=(T val) const { return value != val; }

    friend bool operator<(T lhs, const pnum &rhs) {
        return lhs < rhs.getValue();
    }

    friend bool operator>(T lhs, const pnum &rhs) {
        return lhs > rhs.getValue();
    }

    friend bool operator<=(T lhs, const pnum &rhs) {
        return lhs <= rhs.getValue();
    }

    friend bool operator>=(T lhs, const pnum &rhs) {
        return lhs >= rhs.getValue();
    }

    friend bool operator==(T lhs, const pnum &rhs) {
        return lhs == rhs.getValue();
    }

    friend bool operator!=(T lhs, const pnum &rhs) {
        return lhs != rhs.getValue();
    }

    bool operator<(pnum &val) const { return value < val.getValue(); }

    bool operator>(pnum &val) const { return value > val.getValue(); }

    bool operator<=(pnum &val) const { return value <= val.getValue(); }

    bool operator>=(pnum &val) const { return value >= val.getValue(); }

    bool operator==(pnum &val) const { return value == val.getValue(); }

    bool operator!=(pnum &val) const { return value != val.getValue(); }

    friend bool operator<(const pnum &lhs, const pnum &rhs) {
        return lhs.getValue() < rhs.getValue();
    }

    friend bool operator>(const pnum &lhs, const pnum &rhs) {
        return lhs.getValue() > rhs.getValue();
    }

    friend bool operator<=(const pnum &lhs, const pnum &rhs) {
        return lhs.getValue() <= rhs.getValue();
    }

    friend bool operator>=(const pnum &lhs, const pnum &rhs) {
        return lhs.getValue() >= rhs.getValue();
    }

    friend bool operator==(const pnum &lhs, const pnum &rhs) {
        return lhs.getValue() == rhs.getValue();
    }

    friend bool operator!=(const pnum &lhs, const pnum &rhs) {
        return lhs.getValue() != rhs.getValue();
    }

    pnum &operator=(T &val) {
        setValue(val);
        return *this;
    }

    pnum &operator=(const T &val) {
        setValue(val);
        return *this;
    }

    pnum &operator=(const pnum &other) {
        if (this != &other)
            setValue(other.getValue());
        return *this;
    }

    operator T() const { return getValue(); }

    pnum &onChanged(std::function<void(T)> func) {
        onChangedFunc = std::move(func);
        return *this;
    }
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const pnum<T> &obj) {
    os << obj.getValue();
    return os;
}

template<typename T>
pnum<T> &operator+=(pnum<T> &obj, T val) {
    obj.setValue(obj.getValue() + val);
    return obj;
}

template<typename T>
pnum<T> &operator-=(pnum<T> &obj, T val) {
    obj.setValue(obj.getValue() - val);
    return obj;
}

template<typename T>
pnum<T> &operator*=(pnum<T> &obj, T val) {
    obj.setValue(obj.getValue() * val);
    return obj;
}

template<typename T>
pnum<T> &operator/=(pnum<T> &obj, T val) {
    obj.setValue(obj.getValue() / val);
    return obj;
}

template<typename T>
pnum<T> &operator+=(pnum<T> &obj, pnum<T> &val) {
    obj.setValue(obj.getValue() + val.getValue());
    return obj;
}

template<typename T>
pnum<T> &operator-=(pnum<T> &obj, pnum<T> &val) {
    obj.setValue(obj.getValue() - val.getValue());
    return obj;
}

template<typename T>
pnum<T> &operator*=(pnum<T> &obj, pnum<T> &val) {
    obj.setValue(obj.getValue() * val.getValue());
    return obj;
}

template<typename T>
pnum<T> &operator/=(pnum<T> &obj, pnum<T> &val) {
    obj.setValue(obj.getValue() / val.getValue());
    return obj;
}

template<typename T>
pnum<T> &operator++(pnum<T> &obj) {
    obj.setValue(obj.getValue() + 1);
    return obj;
}

template<typename T>
pnum<T> &operator--(pnum<T> &obj) {
    obj.setValue(obj.getValue() - 1);
    return obj;
}

#include "../../../src/core/pnum.cpp"
