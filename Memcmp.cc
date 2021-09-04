#include <gtest/gtest.h>

int Memcmp(const void* s1, const void* s2, size_t n) {
  unsigned char* s1_ptr = s1;
  unsigned char* s2_ptr = s2;

  while (n-- > 0) {
    if (*s1_ptr != *s2_ptr) break;
    s1_ptr++;
    s2_ptr++;
  }
  return *s1_ptr - *s2_ptr;
}

TEST(Memcmp, foo) {}
