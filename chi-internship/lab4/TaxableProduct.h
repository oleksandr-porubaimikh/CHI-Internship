#ifndef LAB4_TAXABLE_PRODUCT
#define LAB4_TAXABLE_PRODUCT

#include <iomanip>
#include <cstring>

#include "IProduct.h"
#include "Product.h"

namespace sict {
  class TaxableProduct : public IProduct {
    size_t id;
    double _price;
    char tax[3];

  public:
    TaxableProduct(const size_t &id, const double &price, const char *tax)
      : id(id)
      , _price(price)
    { 
      if (tax)
        strcpy_s(this->tax, tax);
    }

    void display(std::ostream &os) const {
      os << std::setw(FW) << id << std::setw(FW) << _price << std::setw(FW) << tax;
    }

    double price() const {
      return _price;
    }

    IProduct *readRecord(std::ifstream &file) {
      size_t id;
      double price;

      file >> id >> price;
      char x = file.peek();
      if (file.peek() != '\n') {
        char tax[3];
        file >> tax;

        return new TaxableProduct(id, price, tax);
      }

      return new Prodcut(id, price);
    }
  };
}

#endif // !LAB4_TAXABLE_PRODUCT
