/**
 * Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática (1º)
 * Asignatura: Informática Básica
 * 
 * @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
 * @brief Funciones para cripto.cc
 * 
 * 
*/

#include <cstdlib>
#include <string>
#include <iostream>
#include "funciones_cripto.h"


void Inicio (int argc, char* argv[]) {

  if (argc != 6) {
    if (argc == 2) {
      std::string entrada = argv[1];
      if (entrada == "--help") {
        std::cout << "./cripto -- Cifrado de ficheros" << std::endl <<
"Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl <<

"fichero_entrada: Fichero a codificar" << std::endl <<
"fichero_salida:  Fichero codificado" << std::endl <<
"método:          Indica el método de encriptado" << std::endl <<
"                   1: Cifrado xor" << std::endl <<
"                   2: Cifrado de César" << std::endl <<
"password:        Palabra secreta en el caso de método 1, Valor de K en el método 2" << std::endl <<
"operación:       Operación a realizar en el fichero" << std::endl <<
"                   +: encriptar el fichero" << std::endl <<
"                   -: desencriptar el fichero" << std::endl;
      }
      exit(EXIT_SUCCESS);
    }
    std::cout << "./cripto -- Cifrado de ficheros" << std::endl <<
"Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl <<
"Pruebe ./cripto --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

