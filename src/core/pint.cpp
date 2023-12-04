#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

#pragma once

class pint {
private:
    int value;

    std::string varName;

    std::vector<int> usedValues;

    std::function<void(int)> onChangedFunc = nullptr;

public:
    pint() : value(0) { setValue(0); }

    pint(int val) : value(val) { setValue(val); }

    int *address() { return &value; }

    [[nodiscard]] int getValue() const { return value; }

    void setValue(int val) {
        value = val;
        usedValues.push_back(value);

        if (onChangedFunc != nullptr)
            onChangedFunc(val);
    }

    pint &named(std::string str) {
        varName = std::move(str);
        return *this;
    }

    std::string name() {
        return varName;
    }

    std::string *nameAddress() {
        return &varName;
    }

    int &operator[](int index) {
        if (index >= 0 && index < usedValues.size())
            return usedValues[index];
        else
            exit(-1);
    }

    int &operator[](const pint &index) {
        if (index >= 0 && index.getValue() < usedValues.size())
            return usedValues[index.getValue()];
        else
            exit(-1);
    }

    int historicalValuesCount() { return (int) usedValues.size(); }

    pint &operator++(int) {
        setValue(value + 1);
        return *this;
    }

    pint &operator--(int) {
        setValue(value - 1);
        return *this;
    }

    int operator+(int val) const { return value + val; }

    int operator-(int val) const { return value - val; }

    int operator*(int val) const { return value * val; }

    int operator/(int val) const { return value / val; }

    int operator%(int val) const { return value % val; }

    int operator&(int val) const { return value & val; }

    int operator|(int val) const { return value | val; }

    int operator^(int val) const { return value ^ val; }

    int operator<<(int val) const { return value << val; }

    int operator>>(int val) const { return value >> val; }

    friend int operator+(int lhs, const pint &rhs) {
        return lhs + rhs.getValue();
    }

    friend int operator-(int lhs, const pint &rhs) {
        return lhs - rhs.getValue();
    }

    friend int operator*(int lhs, const pint &rhs) {
        return lhs * rhs.getValue();
    }

    friend int operator/(int lhs, const pint &rhs) {
        return lhs / rhs.getValue();
    }

    friend int operator%(int lhs, const pint &rhs) {
        return lhs % rhs.getValue();
    }

    friend int operator&(int lhs, const pint &rhs) {
        return lhs & rhs.getValue();
    }

    friend int operator|(int lhs, const pint &rhs) {
        return lhs | rhs.getValue();
    }

    friend int operator^(int lhs, const pint &rhs) {
        return lhs ^ rhs.getValue();
    }

    friend int operator<<(int lhs, const pint &rhs) {
        return lhs << rhs.getValue();
    }

    friend int operator>>(int lhs, const pint &rhs) {
        return lhs >> rhs.getValue();
    }

    pint operator+(pint &val) const { return {value + val.getValue()}; }

    pint operator-(pint &val) const { return {value - val.getValue()}; }

    pint operator*(pint &val) const { return {value * val.getValue()}; }

    pint operator/(pint &val) const { return {value / val.getValue()}; }

    pint operator%(pint &val) const { return {value % val.getValue()}; }

    pint operator&(pint &val) const { return {value & val.getValue()}; }

    pint operator|(pint &val) const { return {value | val.getValue()}; }

    pint operator^(pint &val) const { return {value ^ val.getValue()}; }

    pint operator<<(pint &val) const { return {value << val.getValue()}; }

    pint operator>>(pint &val) const { return {value >> val.getValue()}; }

    friend pint operator+(const pint &lhs, const pint &rhs) {
        return {lhs + rhs.getValue()};
    }

    friend pint operator-(const pint &lhs, const pint &rhs) {
        return {lhs - rhs.getValue()};
    }

    friend pint operator*(const pint &lhs, const pint &rhs) {
        return {lhs * rhs.getValue()};
    }

    friend pint operator/(const pint &lhs, const pint &rhs) {
        return {lhs / rhs.getValue()};
    }

    friend pint operator%(const pint &lhs, const pint &rhs) {
        return {lhs % rhs.getValue()};
    }

    friend pint operator&(const pint &lhs, const pint &rhs) {
        return {lhs & rhs.getValue()};
    }

    friend pint operator|(const pint &lhs, const pint &rhs) {
        return {lhs | rhs.getValue()};
    }

    friend pint operator^(const pint &lhs, const pint &rhs) {
        return {lhs ^ rhs.getValue()};
    }

    friend pint operator<<(const pint &lhs, const pint &rhs) {
        return {lhs << rhs.getValue()};
    }

    friend pint operator>>(const pint &lhs, const pint &rhs) {
        return {lhs >> rhs.getValue()};
    }

    bool operator<(int val) const { return value < val; }

    bool operator>(int val) const { return value > val; }

    bool operator<=(int val) const { return value <= val; }

    bool operator>=(int val) const { return value >= val; }

    bool operator==(int val) const { return value == val; }

    bool operator!=(int val) const { return value != val; }

    friend bool operator<(int lhs, const pint &rhs) {
        return lhs < rhs.getValue();
    }

    friend bool operator>(int lhs, const pint &rhs) {
        return lhs > rhs.getValue();
    }

    friend bool operator<=(int lhs, const pint &rhs) {
        return lhs <= rhs.getValue();
    }

    friend bool operator>=(int lhs, const pint &rhs) {
        return lhs >= rhs.getValue();
    }

    friend bool operator==(int lhs, const pint &rhs) {
        return lhs == rhs.getValue();
    }

    friend bool operator!=(int lhs, const pint &rhs) {
        return lhs != rhs.getValue();
    }

    bool operator<(pint &val) const { return value < val.getValue(); }

    bool operator>(pint &val) const { return value > val.getValue(); }

    bool operator<=(pint &val) const { return value <= val.getValue(); }

    bool operator>=(pint &val) const { return value >= val.getValue(); }

    bool operator==(pint &val) const { return value == val.getValue(); }

    bool operator!=(pint &val) const { return value != val.getValue(); }

    friend bool operator<(const pint &lhs, const pint &rhs) {
        return lhs.getValue() < rhs.getValue();
    }

    friend bool operator>(const pint &lhs, const pint &rhs) {
        return lhs.getValue() > rhs.getValue();
    }

    friend bool operator<=(const pint &lhs, const pint &rhs) {
        return lhs.getValue() <= rhs.getValue();
    }

    friend bool operator>=(const pint &lhs, const pint &rhs) {
        return lhs.getValue() >= rhs.getValue();
    }

    friend bool operator==(const pint &lhs, const pint &rhs) {
        return lhs.getValue() == rhs.getValue();
    }

    friend bool operator!=(const pint &lhs, const pint &rhs) {
        return lhs.getValue() != rhs.getValue();
    }

    pint &operator=(int &val) {
        setValue(val);
        return *this;
    }

    pint &operator=(const int &val) {
        setValue(val);
        return *this;
    }

    pint &operator=(const pint &other) {
        if (this != &other)
            setValue(other.getValue());
        return *this;
    }

    operator int() const { return getValue(); }

    pint &onChanged(std::function<void(int)> func) {
        onChangedFunc = std::move(func);
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const pint &obj) {
    os << obj.getValue();
    return os;
}

pint &operator+=(pint &obj, int val) {
    obj.setValue(obj.getValue() + val);
    return obj;
}

pint &operator-=(pint &obj, int val) {
    obj.setValue(obj.getValue() - val);
    return obj;
}

pint &operator*=(pint &obj, int val) {
    obj.setValue(obj.getValue() * val);
    return obj;
}

pint &operator/=(pint &obj, int val) {
    obj.setValue(obj.getValue() / val);
    return obj;
}

pint &operator%=(pint &obj, int val) {
    obj.setValue(obj.getValue() % val);
    return obj;
}

pint &operator&=(pint &obj, int val) {
    obj.setValue(obj.getValue() & val);
    return obj;
}

pint &operator|=(pint &obj, int val) {
    obj.setValue(obj.getValue() | val);
    return obj;
}

pint &operator^=(pint &obj, int val) {
    obj.setValue(obj.getValue() ^ val);
    return obj;
}

pint &operator<<=(pint &obj, int val) {
    obj.setValue(obj.getValue() << val);
    return obj;
}

pint &operator>>=(pint &obj, int val) {
    obj.setValue(obj.getValue() >> val);
    return obj;
}

pint &operator+=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() + val.getValue());
    return obj;
}

pint &operator-=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() - val.getValue());
    return obj;
}

pint &operator*=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() * val.getValue());
    return obj;
}

pint &operator/=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() / val.getValue());
    return obj;
}

pint &operator%=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() % val.getValue());
    return obj;
}

pint &operator&=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() & val.getValue());
    return obj;
}

pint &operator|=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() | val.getValue());
    return obj;
}

pint &operator^=(pint &obj, pint &val) {
    obj.setValue(obj.getValue() ^ val.getValue());
    return obj;
}

pint &operator++(pint &obj) {
    obj.setValue(obj.getValue() + 1);
    return obj;
}

pint &operator--(pint &obj) {
    obj.setValue(obj.getValue() - 1);
    return obj;
}
