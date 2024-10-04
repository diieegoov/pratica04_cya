// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Diego Vegas Acosta
// Correo: alu0101651361@ull.edu.es
// Fecha: 01/10/2024
// Archivo main.h: programa de definicion del main del proyecto
// Referencias: 
// Enlaces de interés
// Historial de revisiones
// 01/10/2024 - Creación (primera versión) del código

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

#include "Analyzer.h"
#include "Dual.cc"
#include "Dual.h"

/// @brief Comprueba que los argumentos sean los adecuados
/// @param argc número de argumentos
/// @param argv argumentos
/// @param kCorrectNumber número correcto de argumentos, en este caso es 2
/// @return true si es correcto
bool CheckCorrectParameters(const int argc, char* argv[], int kCorrectNumber) {
  if(argc != kCorrectNumber) {
    std::fstream archivo("help.txt");
    std::string word;
    while(getline(archivo, word)) {
      std::cout << word << std::endl;
    }
    return false;
  }
  return true;    
}

/// @brief Obtiene el programa de linea de comandos
/// @param argv el programa que se quiera obtener
/// @return el programa para anamlizar
std::string ObtenerPrograma(char* argv[]) {
  std::string nombre = argv[1];
  return nombre;
}

/// @brief Obtiene la salida de linea de comandos
/// @param argv el archivo que se quiera escribir
/// @return el archivo para modificar
std::string ObtenerSalida(char* argv[]) {
  std::string nombre = argv[2];
  return nombre;
}

/// @brief Almacena el contenido y las lineas en la que aparecen variables
/// @param archivo es el programa a analizar
/// @return vector de dual de variables
std::vector<Dual> AlmacenarVariables(std::string archivo) {
  std::fstream programa(archivo);
  // Expresión regular para detectar declaraciones de int
  std::regex patron_int_double(R"(\b(int|double)\s+\w+\s*(=\s*(\d+|.+)(\.\d+)?)?\s*;$)");
  // std::regex patron_double(R"(\bdouble\s+\w+\s*(=\s*\d+(,\d+)?)?\s*;)");
  int numero_linea{0};
  std::string linea;
  std::vector<Dual> variables;
  while (getline(programa, linea)) {
    numero_linea++;
    if (std::regex_search(linea, patron_int_double)) {
      Dual val;
      val.SetLinea(numero_linea);
      val.SetValor(linea);
      variables.push_back(val);
    }
  }
  return variables;
}

/// @brief Almacena el contenido y las lineas en la que aparecen variables
/// @param archivo es el programa a analizar
/// @return vector de dual de statements
std::vector<Dual> AlmacenarStatements(std::string archivo) {
  std::fstream programa(archivo);
  // Expresión regular para detectar declaraciones de int
  std::regex patron_statements(R"(\b(for|while)\b)");
  // \s+\(\s*\w+\s*\)\s*\{\s
  // std::regex patron_double(R"(\bdouble\s+\w+\s*(=\s*\d+(,\d+)?)?\s*;)");
  int numero_linea{0};
  std::string linea;
  std::vector<Dual> statements;
  while (getline(programa, linea)) {
    numero_linea++;
    if (std::regex_search(linea, patron_statements)) {
      Dual val;
      val.SetLinea(numero_linea);
      val.SetValor(linea);
      statements.push_back(val);
    }
  }
  return statements;
}

/// @brief Estudia si hay main o no en el programa
/// @param programa_entrada es el programa a analizar
/// @return true si hay main
bool DecidirMain(std::string programa_entrada) {
  std::fstream programa(programa_entrada);
  std::regex patron_main(R"(int\s+main\((.*\[?\]?)\)\s*\{)");
  std::string linea;
  bool hay_main{false};
  while(getline(programa, linea)) {
    if(std::regex_search(linea, patron_main)) {
      hay_main = true;
    }
  }
  return hay_main;
}

/// @brief Almacena el contenido y las lineas en la que aparecen comentarios
/// @param programa_entrada es el programa a analizar
/// @return vector de dual de comentarios
std::vector<Dual> AlmacenarComentarios(std::string programa_entrada) {
  std::fstream programa(programa_entrada);
  // Expresión regular para detectar declaraciones de int
  std::regex patron_comments(R"((\/\*+)|(\s\*(\s|\n))|(\*\/)|(\/\/))");
  int numero_linea{0};
  std::string linea;
  std::vector<Dual> comments;
  while (getline(programa, linea)) {
    numero_linea++;
    if(std::regex_search(linea, patron_comments)) {
      Dual val;
      val.SetLinea(numero_linea);
      val.SetValor(linea);
      comments.push_back(val);
    }
    if(linea == " *") {
      Dual val;
      val.SetLinea(numero_linea);
      val.SetValor(linea);
      comments.push_back(val);
    }
  }
  return comments;
}

/// @brief Imprime con la sobrecarga de salida 
/// @param analisis objeto analisis
/// @param programa_salida string con el nombre del programa de salida
void Imprimir(Analyzer analisis, std::string programa_salida, std::string programa_entrada) {
  std::ofstream salida(programa_salida);
  salida << "PROGRAM: " << programa_entrada << std::endl;
  salida << analisis;
}

#endif