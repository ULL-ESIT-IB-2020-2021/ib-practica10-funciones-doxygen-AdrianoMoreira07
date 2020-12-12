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
#include <fstream>
#include <bitset>
#include <bits/stdc++.h>
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
  }
}


std::string CifradoXor (const std::string& linea, const std::string pass) {
  int longitud_pass{(int)pass.length()};
  int longitud_linea{(int)linea.length()};
  int posicion_pass{0};

  char caracter_cifrado{'0'};
  std::string linea_final{""};
  std::vector< std::bitset<8> > password(longitud_pass);

  /// Convierte la password a binario
  for (int i{0}; i < longitud_pass; ++i) {
    password[i] = std::bitset<8>(pass[i]) ^ std::bitset<8>{10000000}; // 10000000 = 128 en binario
  }

  /// Cifra cada caracter y añade a la string final
  for (int i{0}; i < longitud_linea; ++i) {
    if (posicion_pass == longitud_pass) {
      posicion_pass = 0;
    }
    caracter_cifrado = char((std::bitset<8>(linea[i]) ^ password[posicion_pass]).to_ulong());
    linea_final += char(caracter_cifrado);

    ++posicion_pass;
  }
  return linea_final;
}

std::string CifradoCesar (const std::string& linea, const int& pass) {
  std::string linea_cifrada{""};
  for (int i: linea) {
    /// Modo cifrado (+) para letras
    if ((i >= 97 && i <= 122) && (i + pass > 122)) {      // Minúsculas
      linea_cifrada += char(i + pass - 26);
      continue;
    } else if ((i >= 65 && i <= 90) && (i + pass > 90)) { // Mayúsculas
      linea_cifrada += char(i + pass - 26);
      continue;
    }

    /// Modo descifrado (-) para letras
    if ((i >= 97 && i <= 122) && (i + pass < 97)) {       // Minúsculas
      linea_cifrada += char(i + pass + 26);
      continue;
    } else if ((i >= 65 && i <= 90) && (i + pass < 65)) { // Mayúsculas
      linea_cifrada += char(i + pass + 26);
      continue;
    }

    linea_cifrada += char(i + pass);
  }
  return linea_cifrada;
}