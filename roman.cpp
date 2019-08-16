#include <stdio.h>
#include <string.h>

void roman(int k) {
  char buff[16], p = 0;
  unsigned long long int d = 0x4d44434c585649ULL;
  unsigned long long int n = 0x0227315091041fULL;
  for (int c = k % 10, o = 0; k != 0; k = k / 10, c = k % 10, o += 2) {
    while ((c = (n >> 5 * c) & 31) != 31) {
      buff[p++] = ((char*)(&d))[o + (c >> 3)];
      c = c & 7;
    }
  }
  buff[p] = 0;
  printf("%s\n", _strrev(buff));
}

int main() {
  for (int t = 1; t < 4000; t++) {
    roman(t);
  }
  return 0;
}
