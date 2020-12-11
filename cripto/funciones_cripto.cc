/**
 * Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática (1º)
 * Asignatura: Informática Básica
 * 
 * @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
 * @brief Funciones para cripto.cc
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
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

void ComprobarRuta (const std::string& fichero_entrada,const std::string& fichero_salida) {
  if (fichero_entrada == fichero_salida) {
    std::cerr << "Los ficheros de entrada y salida no pueden tener el mismo nombre." << std::endl;
    exit(EXIT_SUCCESS);
  } else if (TieneCaracteresProhibidos(fichero_entrada) || TieneCaracteresProhibidos(fichero_salida)) {
    std::cerr << "Uno o dos ficheros tienen caracteres no permitidos" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

bool TieneCaracteresProhibidos(const std::string& nombre_fichero) {
  const std::vector<char> kCaracteresProhibidos{'*', '.', '"', '\\', '[', ']', ':', ';', '|', ','};
  for (auto i: kCaracteresProhibidos) {
    if (nombre_fichero.find(i) != std::string::npos) {
      return true;
    }
  }
  return false;
}