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

const Stud** copy(const Stud* const* src, const Stud** dest, size_t k) 
{
  for (size_t i = 0; i < k; ++i) {
      dest[i] = src[i];
  }
  return dest + k;
}
bool contains(const Stud * const* stud, const Stud* s, size_t k)
{
  bool res = false;
  for (size_t i = 0; i < k; ++i) {
    res = res || stud[i] == s;
  }
  return res;
}

const Stud ** stud_union(size_t& r, const Subj& s1, const Subj& s2)
{
  const Stud ** uni = new const Stud*[s1.people + s2.people];
  copy(s1.studs, uni, s1.people);
  size_t count = s1.people;

  for (size_t i = 0; i < s2.people; ++i) {
    if (!contains(uni, s2.studs[i], count)) {
      uni[count++] = s2.studs[i];
    }
  }
  try {
    const Stud** tmp = new const Stud*[count];
    copy(uni, tmp, count);
    delete [] uni;
    uni = tmp;
  } catch (...) {
    delete [] uni;
    throw;
  }
  r = count;
  return uni;
}

int main()
{

}