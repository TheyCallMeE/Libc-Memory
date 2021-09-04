#include <gtest/gtest.h>

void *Memmove(void *dest, const void *src, size_t n) {
  unsigned char *s = (unsigned char *)src;
  unsigned char *d = (unsigned char *)dest;
  bool reversed = false;

  if (d > s && (s + n) < (d + n)) {
    s += n - 1;
    d += n - 1;
    reversed = true;
  }

  while (n-- > 0) {
    *d = *s;
    reversed ? d-- : d++;
    reversed ? s-- : s++;
  }

  return dest;
}

TEST(Memmove, foo) {
  char t[256] = "hello world";
  Memmove(t, t + 6, 5);
  EXPECT_STREQ(t, "world world");
  char a[256] = "hello world";
  Memmove(a + 6, a, 5);
  EXPECT_STREQ(a, "hello hello");
}
