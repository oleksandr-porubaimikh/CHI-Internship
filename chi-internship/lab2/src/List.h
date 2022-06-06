#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <string>

template <typename T, size_t N>
class List {
  size_t list_size;
  T array[N];

public:
  List() 
    : list_size(0u)
  { }

  size_t size() const {
    return list_size;
  }

  const T &operator [](size_t index) {
    if (index < list_size) {
      return array[index];
    } else {
      throw std::out_of_range("index " + std::to_string(index) + " is out of range");
    }
  }

  void operator +=(const T &element) {
    if (list_size + 1 < N) {
      array[list_size++] = element;
    } else {
      throw std::length_error("the list has max length of " + std::to_string(N) + " elements");
    }
  }
};

#endif // !LIST_H
