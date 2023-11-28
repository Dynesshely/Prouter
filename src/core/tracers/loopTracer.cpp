#include "../pint.cpp"

class loopTracer {
private:
public:
  loopTracer trace(pint v) {
    v.onChanged([this](int val) {

    });
    return *this;
  }
};