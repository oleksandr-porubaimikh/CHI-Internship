#ifndef PAIR_H
#define PAIR_H

#include <map>

template <typename A, typename B>
class Pair {
  A first;
  B second;

public:
  Pair() 
    : first()
    , second()
  { }

  Pair(const A& first, const B& second)
    : first(first)
    , second(second)
  { }

  const A &getKey() const {
    return first;
  }

  const B &getValue() const {
    return second;
  }
};

#endif // !PAIR_H
