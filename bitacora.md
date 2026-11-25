# Bitácora

## 2026-11-23
- Leí el enunciado del problema A y seguí el ejemplo a mano.
- Creé el repositorio con los casos de prueba del enunciado.
- Siguiente: leer los casos y las órdenes.

## 2026-11-24
- Lectura de casos: TOP lee un entero, PUBLICAR y BORRAR leen la etiqueta y la copian a string.
- Solución con map<string,int> para el conteo y map<int, set<string>> para los grupos por conteo.
- La salida coincide con sample.out.
- Casos propios: consulta antes de publicar y k mayor que las etiquetas (caso1),
  etiqueta que llega a cero y vuelve a aparecer (caso2), empates y un caso después de otro con muchas etiquetas (caso3).
