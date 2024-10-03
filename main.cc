// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Diego Vegas Acosta
// Correo: alu0101651361@ull.edu.es
// Fecha: 01/10/2024
// Archivo main.cc: programa main del proyecto
// Referencias: 
// Enlaces de interés
// Historial de revisiones
// 01/10/2024 - Creación (primera versión) del código

#include <iostream>

#include "main.h"

int main(const int argc, char* argv[]) {
  if(!CheckCorrectParameters(argc, argv, 3)) {
    return 0;
  }
  std::string entrada = ObtenerPrograma(argv);
  bool funcion_main = DecidirMain(entrada);
  std::vector<Dual> variables = AlmacenarVariables(entrada);
  std::vector<Dual> statements = AlmacenarStatements(entrada);
  std::vector<Dual> comentarios = AlmacenarComentarios(entrada);
  Analyzer analisis{funcion_main, variables, statements, comentarios};
  std::string salida = ObtenerSalida(argv);
  Imprimir(analisis, salida, entrada);
  return 0;
}