pint::pint() : value(0) { setValue(0); }

pint::pint(int val) : value(val) { setValue(val); }

int *pint::address() { return &value; }

[[nodiscard]] int pint::getValue() const { return value; }

void pint::setValue(int val) {
    value = val;
    usedValues.push_back(value);

    if (onChangedFunc != nullptr)
        onChangedFunc(val);
}

pint &pint::named(std::string str) {
    varName = std::move(str);
    return *this;
}

std::string pint::name() {
    return varName;
}

std::string *pint::nameAddress() {
    return &varName;
}

//pint &pint::traceBy(loopTracer *tracer) {
//    tracer->trace(this);
//    return *this;
//}

std::string pint::history(const std::string &conj = " -> ") {
    std::string text;
    for (int k = 0; k < this->historicalValuesCount(); ++k) {
        text += std::to_string((*this)[k]);

        if (k < this->historicalValuesCount() - 1)
            text += conj;
    }
    return text;
}

int &pint::operator[](int index) {
    if (index >= 0 && index < usedValues.size())
        return usedValues[index];
    else
        exit(-1);
}

int &pint::operator[](const pint &index) {
    if (index >= 0 && index.getValue() < usedValues.size())
        return usedValues[index.getValue()];
    else
        exit(-1);
}

int pint::historicalValuesCount() { return (int) usedValues.size(); }

pint &pint::operator++(int) {
    setValue(value + 1);
    return *this;
}

pint &pint::operator--(int) {
    setValue(value - 1);
    return *this;
}

int pint::operator+(int val) const { return value + val; }

int pint::operator-(int val) const { return value - val; }

int pint::operator*(int val) const { return value * val; }

int pint::operator/(int val) const { return value / val; }

int pint::operator%(int val) const { return value % val; }

int pint::operator&(int val) const { return value & val; }

int pint::operator|(int val) const { return value | val; }

int pint::operator^(int val) const { return value ^ val; }

int pint::operator<<(int val) const { return value << val; }

int pint::operator>>(int val) const { return value >> val; }

pint pint::operator+(pint &val) const { return {value + val.getValue()}; }

pint pint::operator-(pint &val) const { return {value - val.getValue()}; }

pint pint::operator*(pint &val) const { return {value * val.getValue()}; }

pint pint::operator/(pint &val) const { return {value / val.getValue()}; }

pint pint::operator%(pint &val) const { return {value % val.getValue()}; }

pint pint::operator&(pint &val) const { return {value & val.getValue()}; }

pint pint::operator|(pint &val) const { return {value | val.getValue()}; }

pint pint::operator^(pint &val) const { return {value ^ val.getValue()}; }

pint pint::operator<<(pint &val) const { return {value << val.getValue()}; }

pint pint::operator>>(pint &val) const { return {value >> val.getValue()}; }

bool pint::operator<(int val) const { return value < val; }

bool pint::operator>(int val) const { return value > val; }

bool pint::operator<=(int val) const { return value <= val; }

bool pint::operator>=(int val) const { return value >= val; }

bool pint::operator==(int val) const { return value == val; }

bool pint::operator!=(int val) const { return value != val; }

bool pint::operator<(pint &val) const { return value < val.getValue(); }

bool pint::operator>(pint &val) const { return value > val.getValue(); }

bool pint::operator<=(pint &val) const { return value <= val.getValue(); }

bool pint::operator>=(pint &val) const { return value >= val.getValue(); }

bool pint::operator==(pint &val) const { return value == val.getValue(); }

bool pint::operator!=(pint &val) const { return value != val.getValue(); }

pint &pint::operator=(int &val) {
    setValue(val);
    return *this;
}

pint &pint::operator=(const int &val) {
    setValue(val);
    return *this;
}

pint &pint::operator=(const pint &other) {
    if (this != &other)
        setValue(other.getValue());
    return *this;
}

pint::operator int() const { return getValue(); }

pint &pint::onChanged(std::function<void(int)> func) {
    onChangedFunc = std::move(func);
    return *this;
}

int operator+(int lhs, const pint &rhs) {
    return lhs + rhs.getValue();
}

int operator-(int lhs, const pint &rhs) {
    return lhs - rhs.getValue();
}

int operator*(int lhs, const pint &rhs) {
    return lhs * rhs.getValue();
}

int operator/(int lhs, const pint &rhs) {
    return lhs / rhs.getValue();
}

int operator%(int lhs, const pint &rhs) {
    return lhs % rhs.getValue();
}

int operator&(int lhs, const pint &rhs) {
    return lhs & rhs.getValue();
}

int operator|(int lhs, const pint &rhs) {
    return lhs | rhs.getValue();
}

int operator^(int lhs, const pint &rhs) {
    return lhs ^ rhs.getValue();
}

int operator<<(int lhs, const pint &rhs) {
    return lhs << rhs.getValue();
}

int operator>>(int lhs, const pint &rhs) {
    return lhs >> rhs.getValue();
}

pint operator+(const pint &lhs, const pint &rhs) {
    return {lhs + rhs.getValue()};
}

pint operator-(const pint &lhs, const pint &rhs) {
    return {lhs - rhs.getValue()};
}

pint operator*(const pint &lhs, const pint &rhs) {
    return {lhs * rhs.getValue()};
}

pint operator/(const pint &lhs, const pint &rhs) {
    return {lhs / rhs.getValue()};
}

pint operator%(const pint &lhs, const pint &rhs) {
    return {lhs % rhs.getValue()};
}

pint operator&(const pint &lhs, const pint &rhs) {
    return {lhs & rhs.getValue()};
}

pint operator|(const pint &lhs, const pint &rhs) {
    return {lhs | rhs.getValue()};
}

pint operator^(const pint &lhs, const pint &rhs) {
    return {lhs ^ rhs.getValue()};
}

pint operator<<(const pint &lhs, const pint &rhs) {
    return {lhs << rhs.getValue()};
}

pint operator>>(const pint &lhs, const pint &rhs) {
    return {lhs >> rhs.getValue()};
}


// Below are out of `pint` class


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
