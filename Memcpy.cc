#include <gtest/gtest.h>

void *Memcpy(void *dest, const void *src, size_t n) {
  const char *src_ptr = (char *)src;
  char *dest_ptr = (char *)dest;
  for (size_t i = 0; i < n; i++) {
    *dest_ptr++ = *src_ptr++;
  }
  return dest;
}

TEST(Memcpy, foo) {
  char a[256];
  Memcpy(a, "whats poppin?", 14);
  EXPECT_STREQ(a, "whats poppin?");
}
