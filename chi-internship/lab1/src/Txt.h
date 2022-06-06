#ifndef L1_TXT_H
#define L1_TXT_H

#include <vector>
#include <string>

namespace l1 {
  class Txt {
    std::string *text;
    size_t text_size;

  public:
    Txt();
    Txt(const std::string &);
    Txt(const Txt &);
    Txt(Txt &&) noexcept;

    ~Txt();

    Txt &operator =(const Txt &);
    Txt &operator =(Txt &&) noexcept;

    size_t size() const;
  };
}

#endif // !L1_TXT_H
