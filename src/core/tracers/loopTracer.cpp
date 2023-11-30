#include "../pint.cpp"
#include <string>
#include <vector>

struct loopRow {
  int loopId{};
  std::vector<pint> pints;
};

class loopTracer {
private:
  int colCount = 0;

  std::vector<pint *> targets;
  std::vector<loopRow *> rows;

  void updateValue(int colIndex, int val) {
    if (rows.back()->pints.size() < colCount)
      rows.back()->pints.emplace_back(val);
    else
      rows[rows.size() - 1]->pints[colIndex] = val;
  }

public:
  loopTracer() {
    rows.push_back(new loopRow());
    rows[0]->loopId = 0;
  }

  loopTracer trace(pint *v) {
    targets.push_back(v);
    auto currentCol = colCount++;
    updateValue(currentCol, v->getValue());
    v->onChanged([this, currentCol](int val) { updateValue(currentCol, val); });
    return *this;
  }

  loopTracer loop() {
    auto row = new loopRow();
    row->loopId = (int)rows.size();
    rows.push_back(row);
    return *this;
  }

  loopTracer end() {
    rows.pop_back();

    for (auto &target : targets)
      target->onChanged(nullptr);

    return *this;
  }

  std::string tableText() {
    std::string text;

    for (auto &row : rows) {
      text += std::to_string(row->loopId) + " | ";

      for (auto &pint : row->pints) {
        for (int k = 0; k < pint.historicalValuesCount(); ++k) {
          text += std::to_string(pint[k]);

          if (k < pint.historicalValuesCount() - 1)
            text += " -> ";
        }
        text += " | ";
      }

      text += "\n";
    }

    return text;
  }
};
