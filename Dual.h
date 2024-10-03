// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Diego Vegas Acosta
// Correo: alu0101651361@ull.edu.es
// Fecha: 01/10/2024
// Archivo Dual.h archivo de definición de la clase Dual
// Referencias: 
// Enlaces de interés
// Historial de revisiones
// 01/10/2024 - Creación (primera versión) del código

#ifndef DUAL_H
#define DUAL_H

#include <string>

class Dual {
 public:
  Dual();  // Constructor default
  Dual(std::string, int);  // Constructor
  std::string GetValor() const { return valor_; }
  int GetLinea() const { return linea_; }
  void SetValor(std::string);
  void SetLinea(int);
 private:
  std::string valor_;
  int linea_;
};

#endif