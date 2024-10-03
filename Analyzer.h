// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Diego Vegas Acosta
// Correo: alu0101651361@ull.edu.es
// Fecha: 01/10/2024
// Archivo Analyzer.h archivo de declaración de la clase Analyzer
// Referencias: 
// Enlaces de interés
// Historial de revisiones
// 01/10/2024 - Creación (primera versión) del código

#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>

#include "Dual.h"

class Analyzer {
 public:
  Analyzer();  // Constructor por defecto
  Analyzer(bool, std::vector<Dual>, std::vector<Dual>, std::vector<Dual>);
  bool GetMain() const { return main_; }
  std::vector<Dual> GetVariable() const { return variables_; }
  std::vector<Dual> GetStatements() const { return statements_; }
  std::vector<Dual> GetComentarios() const { return comentarios_; }
  friend std::ostream& operator<<(std::ostream& in, const Analyzer& analisis);

 private:
  bool main_;
  std::vector<Dual> variables_;
  std::vector<Dual> statements_;
  std::vector<Dual> comentarios_;
};

#endif