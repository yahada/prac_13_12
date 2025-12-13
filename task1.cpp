#include <iostream>
#include <cstddef>

struct Stud {
  const char * fst;
  const char * snd;
  int year;
  int dep;
};

struct Subj {
  const char * name;
  size_t people, classes;
  const Stud * const * studs;
  const size_t * visited;
};

int main()
{

}