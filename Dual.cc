// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Diego Vegas Acosta
// Correo: alu0101651361@ull.edu.es
// Fecha: 01/10/2024
// Archivo Dual.cc archivo de definición de la clase Dual
// Referencias: 
// Enlaces de interés
// Historial de revisiones
// 01/10/2024 - Creación (primera versión) del código

// Dual();  // Constructor default
//   Dual(std::string, int);  // Constructor
//   std::string GetValor() const { return valor_; }
//   int GetLinea() const { return linea_; }
//   void SetValor(std::string);
//   void SetLinea(int);

#include "Dual.h"

Dual::Dual() {
  valor_ = "0";
  linea_ = 0;
}

Dual::Dual(std::string valor, int linea) {
  valor_ = valor;
  linea_ = linea;
}

void Dual::SetValor(std::string valor) {
  valor_ = valor;
}

void Dual::SetLinea(int linea) {
  linea_ = linea;
}