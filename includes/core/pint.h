#ifndef PINT_H
#define PINT_H

#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <functional>

class loopTracer;

class pint {
private:
    int value;
    std::string varName;
    std::vector<int> usedValues;
    std::function<void(int)> onChangedFunc = nullptr;

public:
    pint();

    pint(int val);

    int *address();

    [[nodiscard]] int getValue() const;

    void setValue(int val);

    pint &named(std::string str);

    std::string name();

    std::string *nameAddress();

    pint &traceBy(class loopTracer *tracer);

    int &operator[](int index);

    int &operator[](const pint &index);

    int historicalValuesCount();

    pint &onChanged(std::function<void(int)> func);

    pint &operator++(int);

    pint &operator--(int);

    int operator+(int val) const;

    int operator-(int val) const;

    int operator*(int val) const;

    int operator/(int val) const;

    int operator%(int val) const;

    int operator&(int val) const;

    int operator|(int val) const;

    int operator^(int val) const;

    int operator<<(int val) const;

    int operator>>(int val) const;

    friend int operator+(int lhs, const pint &rhs);

    friend int operator-(int lhs, const pint &rhs);

    friend int operator*(int lhs, const pint &rhs);

    friend int operator/(int lhs, const pint &rhs);

    friend int operator%(int lhs, const pint &rhs);

    friend int operator&(int lhs, const pint &rhs);

    friend int operator|(int lhs, const pint &rhs);

    friend int operator^(int lhs, const pint &rhs);

    friend int operator<<(int lhs, const pint &rhs);

    friend int operator>>(int lhs, const pint &rhs);

    pint operator+(pint &val) const;

    pint operator-(pint &val) const;

    pint operator*(pint &val) const;

    pint operator/(pint &val) const;

    pint operator%(pint &val) const;

    pint operator&(pint &val) const;

    pint operator|(pint &val) const;

    pint operator^(pint &val) const;

    pint operator<<(pint &val) const;

    pint operator>>(pint &val) const;

    friend pint operator+(const pint &lhs, const pint &rhs);

    friend pint operator-(const pint &lhs, const pint &rhs);

    friend pint operator*(const pint &lhs, const pint &rhs);

    friend pint operator/(const pint &lhs, const pint &rhs);

    friend pint operator%(const pint &lhs, const pint &rhs);

    friend pint operator&(const pint &lhs, const pint &rhs);

    friend pint operator|(const pint &lhs, const pint &rhs);

    friend pint operator^(const pint &lhs, const pint &rhs);

    friend pint operator<<(const pint &lhs, const pint &rhs);

    friend pint operator>>(const pint &lhs, const pint &rhs);

    bool operator<(int val) const;

    bool operator>(int val) const;

    bool operator<=(int val) const;

    bool operator>=(int val) const;

    bool operator==(int val) const;

    bool operator!=(int val) const;

    friend bool operator<(int lhs, const pint &rhs);

    friend bool operator>(int lhs, const pint &rhs);

    friend bool operator<=(int lhs, const pint &rhs);

    friend bool operator>=(int lhs, const pint &rhs);

    friend bool operator==(int lhs, const pint &rhs);

    friend bool operator!=(int lhs, const pint &rhs);

    bool operator<(pint &val) const;

    bool operator>(pint &val) const;

    bool operator<=(pint &val) const;

    bool operator>=(pint &val) const;

    bool operator==(pint &val) const;

    bool operator!=(pint &val) const;

    friend bool operator<(const pint &lhs, const pint &rhs);

    friend bool operator>(const pint &lhs, const pint &rhs);

    friend bool operator<=(const pint &lhs, const pint &rhs);

    friend bool operator>=(const pint &lhs, const pint &rhs);

    friend bool operator==(const pint &lhs, const pint &rhs);

    friend bool operator!=(const pint &lhs, const pint &rhs);

    pint &operator=(int &val);

    pint &operator=(const int &val);

    pint &operator=(const pint &other);

    operator int() const;
};

std::ostream &operator<<(std::ostream &os, const pint &obj);

pint &operator+=(pint &obj, int val);

pint &operator-=(pint &obj, int val);

pint &operator*=(pint &obj, int val);

pint &operator/=(pint &obj, int val);

pint &operator%=(pint &obj, int val);

pint &operator&=(pint &obj, int val);

pint &operator|=(pint &obj, int val);

pint &operator^=(pint &obj, int val);

pint &operator<<=(pint &obj, int val);

pint &operator>>=(pint &obj, int val);

pint &operator+=(pint &obj, pint &val);

pint &operator-=(pint &obj, pint &val);

pint &operator*=(pint &obj, pint &val);

pint &operator/=(pint &obj, pint &val);

pint &operator%=(pint &obj, pint &val);

pint &operator&=(pint &obj, pint &val);

pint &operator|=(pint &obj, pint &val);

pint &operator^=(pint &obj, pint &val);

pint &operator++(pint &obj);

pint &operator--(pint &obj);

#endif // PINT_H

