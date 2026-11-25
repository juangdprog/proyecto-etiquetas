#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
using std::string;
using std::map;
using std::set;

// conteo: etiqueta -> conteo actual
// grupos: -conteo -> etiquetas con ese conteo, en orden alfabetico
// la clave es negativa para que begin() sea el conteo mas alto

void sacarDeGrupo(map<int, set<string> > &grupos, int c, const string &e) {
  grupos[-c].erase(e);
  if (grupos[-c].empty()) {
    grupos.erase(-c);
  }
}

void publicar(map<string, int> &conteo, map<int, set<string> > &grupos, const string &e) {
  int c = 0;
  if (conteo.count(e) == 1) {
    c = conteo[e];
    sacarDeGrupo(grupos, c, e);
  }
  conteo[e] = c + 1;
  grupos[-(c + 1)].insert(e);
}

void borrar(map<string, int> &conteo, map<int, set<string> > &grupos, const string &e) {
  int c = conteo[e];
  sacarDeGrupo(grupos, c, e);
  if (c == 1) {
    conteo.erase(e);
  } else {
    conteo[e] = c - 1;
    grupos[-(c - 1)].insert(e);
  }
}

void top(map<int, set<string> > &grupos, int k) {
  if (grupos.empty()) {
    printf("VACIO\n");
    return;
  }
  int impresas = 0;
  map<int, set<string> >::iterator g = grupos.begin();
  while (g != grupos.end() && impresas < k) {
    set<string>::iterator it = g->second.begin();
    while (it != g->second.end() && impresas < k) {
      if (impresas > 0) {
        printf(" ");
      }
      printf("%s", it->c_str());
      impresas = impresas + 1;
      ++it;
    }
    ++g;
  }
  printf("\n");
}

int main() {
  int n;
  int caso = 1;
  while (scanf("%d", &n) == 1 && n != 0) {
    map<string, int> conteo;
    map<int, set<string> > grupos;
    printf("Caso %d:\n", caso);
    int i = 0;
    while (i < n) {
      char orden[16];
      scanf("%15s", orden);
      if (strcmp(orden, "TOP") == 0) {
        int k;
        scanf("%d", &k);
        top(grupos, k);
      } else {
        char pal[32];
        scanf("%31s", pal);
        string e = pal;
        if (strcmp(orden, "PUBLICAR") == 0) {
          publicar(conteo, grupos, e);
        } else {
          borrar(conteo, grupos, e);
        }
      }
      i = i + 1;
    }
    caso = caso + 1;
  }
  return 0;
}
