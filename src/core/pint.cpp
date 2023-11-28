#include <cstddef>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

class pint {
private:
  int value;

  std::vector<int> usedValues;

  std::function<void(int)> onChangedFunc = NULL;

public:
  pint() : value(0) { usedValues.push_back(0); }

  pint(int val) : value(val) { usedValues.push_back(val); }

  int getValue() { return value; }

  int getValue() const { return value; }

  void setValue(int val) {
    value = val;
    usedValues.push_back(value);

    if (onChangedFunc != NULL)
      onChangedFunc(val);
  }

  int &operator[](int index) {
    if (index >= 0 && index < usedValues.size())
      return usedValues[index];
    else
      exit(-1);
  }

  int &operator[](pint index) {
    if (index >= 0 && index.getValue() < usedValues.size())
      return usedValues[index.getValue()];
    else
      exit(-1);
  }

  int historicalValuesCount() { return usedValues.size(); }

  pint &operator++(int) {
    setValue(value + 1);
    return *this;
  }

  pint &operator--(int) {
    setValue(value - 1);
    return *this;
  }

  int operator+(int val) { return value + val; }

  int operator-(int val) { return value - val; }

  int operator*(int val) { return value * val; }

  int operator/(int val) { return value / val; }

  int operator%(int val) { return value % val; }

  int operator&(int val) { return value & val; }

  int operator|(int val) { return value | val; }

  int operator^(int val) { return value ^ val; }

  int operator<<(int val) { return value << val; }

  int operator>>(int val) { return value >> val; }

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

  pint operator+(pint &val) { return pint(value + val.getValue()); }

  pint operator-(pint &val) { return pint(value - val.getValue()); }

  pint operator*(pint &val) { return pint(value * val.getValue()); }

  pint operator/(pint &val) { return pint(value / val.getValue()); }

  pint operator%(pint &val) { return pint(value % val.getValue()); }

  pint operator&(pint &val) { return pint(value & val.getValue()); }

  pint operator|(pint &val) { return pint(value | val.getValue()); }

  pint operator^(pint &val) { return pint(value ^ val.getValue()); }

  pint operator<<(pint &val) { return pint(value << val.getValue()); }

  pint operator>>(pint &val) { return pint(value >> val.getValue()); }

  friend pint operator+(pint lhs, const pint &rhs) {
    return pint(lhs + rhs.getValue());
  }

  friend pint operator-(pint lhs, const pint &rhs) {
    return pint(lhs - rhs.getValue());
  }

  friend pint operator*(pint lhs, const pint &rhs) {
    return pint(lhs * rhs.getValue());
  }

  friend pint operator/(pint lhs, const pint &rhs) {
    return pint(lhs / rhs.getValue());
  }

  friend pint operator%(pint lhs, const pint &rhs) {
    return pint(lhs % rhs.getValue());
  }

  friend pint operator&(pint lhs, const pint &rhs) {
    return pint(lhs & rhs.getValue());
  }

  friend pint operator|(pint lhs, const pint &rhs) {
    return pint(lhs | rhs.getValue());
  }

  friend pint operator^(pint lhs, const pint &rhs) {
    return pint(lhs ^ rhs.getValue());
  }

  friend pint operator<<(pint lhs, const pint &rhs) {
    return pint(lhs << rhs.getValue());
  }

  friend pint operator>>(pint lhs, const pint &rhs) {
    return pint(lhs >> rhs.getValue());
  }

  bool operator<(int val) { return value < val; }

  bool operator>(int val) { return value > val; }

  bool operator<=(int val) { return value <= val; }

  bool operator>=(int val) { return value >= val; }

  bool operator==(int val) { return value == val; }

  bool operator!=(int val) { return value != val; }

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

  bool operator<(pint &val) { return value < val.getValue(); }

  bool operator>(pint &val) { return value > val.getValue(); }

  bool operator<=(pint &val) { return value <= val.getValue(); }

  bool operator>=(pint &val) { return value >= val.getValue(); }

  bool operator==(pint &val) { return value == val.getValue(); }

  bool operator!=(pint &val) { return value != val.getValue(); }

  friend bool operator<(pint lhs, const pint &rhs) {
    return lhs.getValue() < rhs.getValue();
  }

  friend bool operator>(pint lhs, const pint &rhs) {
    return lhs.getValue() > rhs.getValue();
  }

  friend bool operator<=(pint lhs, const pint &rhs) {
    return lhs.getValue() <= rhs.getValue();
  }

  friend bool operator>=(pint lhs, const pint &rhs) {
    return lhs.getValue() >= rhs.getValue();
  }

  friend bool operator==(pint lhs, const pint &rhs) {
    return lhs.getValue() == rhs.getValue();
  }

  friend bool operator!=(pint lhs, const pint &rhs) {
    return lhs.getValue() != rhs.getValue();
  }

  pint &operator=(int &val) {
    value = val;
    return *this;
  }

  pint &operator=(const int &val) {
    value = val;
    return *this;
  }

  pint &operator=(pint &other) {
    if (this != &other) {
      value = other.value;
    }
    return *this;
  }

  pint &operator=(const pint &other) {
    if (this != &other) {
      value = other.value;
    }
    return *this;
  }

  operator int() const { return value; }

  pint onChanged(std::function<void(int)> func) {
    onChangedFunc = func;
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
