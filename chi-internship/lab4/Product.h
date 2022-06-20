#ifndef LAB4_PRODUCT
#define LAB4_PRODUCT

#include <iomanip>
#include "IProduct.h"

namespace sict {
  class Prodcut : public IProduct {
    size_t id;
    double _price;

  public:
    Prodcut(const size_t &id, const double &price) 
      : id(id)
      , _price(price)
    { }

    double price() const {
      return _price;
    }

    void display(std::ostream &os) const {
      os << std::setw(FW) << id << std::setw(FW) << _price;
    }

    IProduct *readRecord(std::ifstream &file) {
      size_t id;
      double price;

      file >> id >> price;
      return new Prodcut(id, price);
    }
  };
}

#endif // !LAB4_PRODUCT
