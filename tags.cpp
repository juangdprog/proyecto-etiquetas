#include <cstdio>
#include <cstring>
#include <string>
using std::string;

int main() {
  int n;
  int caso = 1;
  while (scanf("%d", &n) == 1 && n != 0) {
    printf("Caso %d:\n", caso);
    int i = 0;
    while (i < n) {
      char orden[16];
      scanf("%15s", orden);
      if (strcmp(orden, "TOP") == 0) {
        int k;
        scanf("%d", &k);
        printf("TOP %d\n", k);
      } else {
        char pal[32];
        scanf("%31s", pal);
        string e = pal;
        printf("%s %s\n", orden, e.c_str());
      }
      i = i + 1;
    }
    caso = caso + 1;
  }
  return 0;
}
