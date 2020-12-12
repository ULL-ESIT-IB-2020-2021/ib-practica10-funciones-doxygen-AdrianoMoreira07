/**
 * Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática (1º)
 * Asignatura: Informática Básica
 * 
 * @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
 * @brief Encripta un fichero con el cifrado xor o el cifrado de César
 */

#include "funciones_cripto.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <bitset>


int main (int argc, char* argv[]) {

  Inicio(argc, argv);

  std::string ruta_fichero_entrada{argv[1]};
  std::string ruta_fichero_salida{argv[2]};
  ComprobarRuta(ruta_fichero_entrada, ruta_fichero_salida);
  std::ifstream fichero_entrada{ruta_fichero_entrada};
  std::ofstream fichero_salida{ruta_fichero_salida};
  if (!fichero_entrada || !fichero_salida) {
    std::cerr << "No se pudo abrir alguno de los ficheros o ambos" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string linea_entrada{"-1"};
  std::string linea_salida{"-2"};

  std::string metodo_entrada{argv[3]};
  int metodo{std::stoi(metodo_entrada)};

  std::string password{argv[4]};
  int clave_cesar{0};

  std::string operacion{argv[5]};
  
  switch (metodo) {
  case 1: // Cifrado xor
    while (fichero_entrada) {
      getline(fichero_entrada, linea_entrada);
      linea_salida = CifradoXor(linea_entrada, password);
      fichero_salida << linea_salida << '\n';
    }
    break;
  case 2: // Cifrado de César
    if (operacion == "+") {
      clave_cesar = std::stoi(password);
    } else if (operacion == "-") {
      clave_cesar = std::stoi(password) * -1;

    } else {
      std::cerr << "Solo se admiten las operaciones '+' y '-'" << std::endl;
      exit(EXIT_SUCCESS);
    }

    while (fichero_entrada) {
      getline(fichero_entrada, linea_entrada);
      linea_salida = CifradoCesar(linea_entrada, clave_cesar);
      fichero_salida << linea_salida << '\n';
    }
    break;
  default:
    std::cerr << "Solo se admiten los métodos 1 (xor) ó 2 (César)" << std::endl;
    break;
  }

  std::cout << argv[0] << ": Ejecución satisfactoria" << std::endl;

  return 0;
}