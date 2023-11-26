#include <iostream>

class pint {
private:
  int value;

public:
  pint(int val) : value(val) {}

  int getValue() const { return value; }

  void setValue(int val) { value = val; }

  pint &operator++(int) {
    value++;
    return *this;
  }

  pint &operator--(int) {
    value--;
    return *this;
  }

  pint operator+(int val) { return pint(value + val); }

  pint operator-(int val) { return pint(value - val); }

  pint operator*(int val) { return pint(value * val); }

  pint operator/(int val) { return pint(value / val); }

  pint operator%(int val) { return pint(value % val); }

  friend pint operator+(int lhs, const pint &rhs) {
    return pint(lhs + rhs.getValue());
  }

  friend pint operator-(int lhs, const pint &rhs) {
    return pint(lhs - rhs.getValue());
  }

  friend pint operator*(int lhs, const pint &rhs) {
    return pint(lhs * rhs.getValue());
  }

  friend pint operator/(int lhs, const pint &rhs) {
    return pint(lhs / rhs.getValue());
  }

  friend pint operator%(int lhs, const pint &rhs) {
    return pint(lhs % rhs.getValue());
  }

  pint operator+(pint &val) { return pint(value + val.getValue()); }

  pint operator-(pint &val) { return pint(value - val.getValue()); }

  pint operator*(pint &val) { return pint(value * val.getValue()); }

  pint operator/(pint &val) { return pint(value / val.getValue()); }

  pint operator%(pint &val) { return pint(value % val.getValue()); }

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
pint &operator++(pint &obj) {
  obj.setValue(obj.getValue() + 1);
  return obj;
}

pint &operator--(pint &obj) {
  obj.setValue(obj.getValue() - 1);
  return obj;
}
