// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Diego Vegas Acosta
// Correo: alu0101651361@ull.edu.es
// Fecha: 01/10/2024
// Archivo Analyzer.cc archivo de definición de la clase Analyzer
// Referencias: 
// Enlaces de interés
// Historial de revisiones
// 01/10/2024 - Creación (primera versión) del código

#include <iostream>

#include "Analyzer.h"

Analyzer::Analyzer(bool main, std::vector<Dual> variables, std::vector<Dual> statements, std::vector<Dual> comentarios) {
  main_ = main;
  variables_ = variables;
  statements_ = statements;
  comentarios_ = comentarios;
}

std::ostream& operator<<(std::ostream& os, const Analyzer& analisis) {
  
  //// DESCRIPTION ////
  os << "DESCRIPTION:\n";
  int size_comments = analisis.GetComentarios().size();
  int final_descripcion;
  for(int i = 0; i < size_comments; i++) {
    os << analisis.GetComentarios()[i].GetValor() << std::endl;
    if (analisis.GetComentarios()[i].GetValor() == " */") {
      final_descripcion = i + 1;
      break;
    }
  }
  //// DESCRIPTION ////

  os << std::endl;

  //// VARIABLES (INT Y DOUBLE) ////
  os << "VARIABLES:\n";
  int tamaño_variables = analisis.GetVariable().size();
  for(int i = 0; i < tamaño_variables; i++) {
    os << "[Line " << analisis.GetVariable()[i].GetLinea() << "]";
    // os << analisis.GetVariable()[i].GetValor() << std::endl;
    bool acceder{false};
    bool es_int{true};
    int contador{0};
    std::vector<char> palabra;
    for(auto& word : analisis.GetVariable()[i].GetValor()) {
      if(contador == 0) {
        if(word == 'd') {
          es_int = false;
        }
      }
      if(es_int == true) {
        if(word == 't' || acceder) {
          acceder = true;
          palabra.push_back(word);
        }
      }
      if(es_int == false) {
        if(word == 'e' || acceder) {
          acceder = true;
          palabra.push_back(word);
        }
      }
    }
    if (es_int == true) {
      os << " INT: ";
      int size = (palabra.size() - 1);
      for(int i = 2; i < size; i++) {
        os << palabra[i];
      }
    }
    if (es_int == false) {
      os << " DOUBLE: ";
      int size = (palabra.size() - 1);
      for(int i = 2; i < size; i++) {
        os << palabra[i];
      }
    }
    os << std::endl;
    // [ Line 22] INT : factorial = 1
    // [ Line 32] INT : limit
  }
  //// VARIABLES (INT Y DOUBLE) ////

  os << std::endl;

  //// STATEMENTS (FOR Y WHILE) ////
  os << "STATEMENTS:\n";
  int tamaño_statements = analisis.GetStatements().size();
  for(int i = 0; i < tamaño_statements; i++) {
    os << "[Line " << analisis.GetStatements()[i].GetLinea() << "]";
    os << " LOOP: ";
    //os << analisis.GetStatements()[i].GetValor() << std::endl;
    bool es_for{false};
    bool acceso{true};
    for(auto& word : analisis.GetStatements()[i].GetValor()) {
      if(word == 'f' && acceso) {
        acceso = false;
        es_for = true;
      }
    }
    if(es_for == true) {
      os << "for\n";
    }
    if(es_for == false) {
      os << "while\n";
    }
  }
  //// STATEMENTS (FOR Y WHILE) ////

  os << std::endl;

  //// MAIN ////
  os << "MAIN:\n";
  if(analisis.GetMain() == true) {
    os << "TRUE\n";
  }
  else {
    os << "FALSE\n";
  }
  //// MAIN ////

  os << std::endl;

  //// COMMENTS ////
  os << "COMMENTS:\n";
  os << "[Line 1-" << final_descripcion << "]" << " DESCRIPTION\n";
  for(int i = final_descripcion; i < size_comments; i++) {
    std::vector<char> filtro_comentario;
    int inicio;
    os << "[Line " << analisis.GetComentarios()[i].GetLinea() << "] ";
    //os << analisis.GetComentarios()[i].GetValor() << std::endl;
    for(auto& word : analisis.GetComentarios()[i].GetValor()) {
      filtro_comentario.push_back(word);
    }
    int size_vector = filtro_comentario.size();
    for(int i = 0; i < size_vector; i++) {
      if((filtro_comentario[i] == '/') && (filtro_comentario[i + 1] == '/')) {
        inicio = i;
        break;
      }
    }
    for(int i = inicio; i < size_vector; i++) {
      os << filtro_comentario[i];
    }
    os << std::endl;
  }
    //// COMMENTS ////
  return os;
}
