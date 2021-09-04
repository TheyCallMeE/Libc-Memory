#include <gtest/gtest.h>

void *Memset(void *s, int c, size_t n) {
  char *s_ptr = (char *)s;
  while (n-- > 0) {
    *s_ptr = c;
    s_ptr++;
  }
  return s;
}

TEST(Memset, foo) {
  char a[5];
  Memset(a, 'a', 5);
  EXPECT_STREQ(a, "aaaaa");
}
