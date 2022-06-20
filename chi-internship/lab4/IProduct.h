#ifndef LAB4_IPRODUCT
#define LAB4_IPRODUCT

#include <ostream>
#include <fstream>

extern int FW;

namespace sict {
  struct IProduct {
    virtual double price() const = 0;
    virtual void display(std::ostream &os) const = 0;
    virtual IProduct *readRecord(std::ifstream &file) = 0;

    friend std::ostream &operator <<(std::ostream &os, const IProduct &p) {
      p.display(os);

      return os;
    }
  };
}

#endif // !LAB4_IPRODUCT
