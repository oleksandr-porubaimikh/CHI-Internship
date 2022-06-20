#ifndef LAB4_SALE
#define LAB4_SALE

#include <fstream>
#include <vector>

#include "TaxableProduct.h"

namespace sict {
  class Sale {
    std::vector<IProduct *> products;
  public:
    Sale(const char *filepath) {
      std::ifstream file(filepath);
      if (!file)
        throw std::runtime_error("Could not open the file");

      sict::TaxableProduct tmp(0, 0, nullptr);
      while (file.peek() != EOF) {
        products.push_back(tmp.readRecord(file));
      }
    }

    ~Sale() {
      for (auto &x : products) {
        delete x;
      }
    }

    void display(std::ostream &os) const {
      for (auto &x : products) {
        x->display(os);
        os << '\n';
      }
    }
  };
}

#endif // !LAB4_SALE
