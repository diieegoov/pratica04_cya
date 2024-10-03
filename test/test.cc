#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(const int argc, char* argv[]) {
  std::string nombre = argv[1];
  std::fstream archivo(nombre);
  std::string linea_individual;
  std::vector<std::string> lineas;
  while(getline(archivo, linea_individual)) {
    lineas.push_back(linea_individual);
  }
  std::vector<std::string> comentarios;
  for(std::string& word : lineas) {
    if(word == "#include") {
      break;
    }
    else {
      comentarios.push_back(word);
    }
  }
  std::cout << comentarios[2] << std::endl;
  return 0;
}

//   // Expresión regular para detectar declaraciones de enteros
//     std::regex patron_int(R"(\bint\s+\w+\s*(=\s*\d+)?\s*;)");

//     // Leer el archivo línea por línea
//     while (std::getline(archivo, linea)) {
//         numero_linea++;  // Incrementar el número de línea

//         // Buscar si la línea coincide con la expresión regular
//         if (std::regex_search(linea, patron_int)) {
//             std::cout << "Declaración de entero encontrada en la línea " << numero_linea << ": " << linea << std::endl;
//         }
