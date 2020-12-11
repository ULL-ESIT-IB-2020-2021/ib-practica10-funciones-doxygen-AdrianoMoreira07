/**
 * Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática (1º)
 * Asignatura: Informática Básica
 * 
 * @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
 * @brief //DESC
 * 
 * 
 */

#include "funciones_cripto.h"
#include <string>
#include <fstream>


int main (int argc, char* argv[]) {

  Inicio(argc, argv);

  std::string ruta_fichero_entrada{argv[1]};
  std::string ruta_fichero_salida{argv[2]};
  ComprobarRuta(ruta_fichero_entrada, ruta_fichero_salida);
  std::string metodo_entrada{argv[3]};
  int metodo{std::stoi(metodo_entrada)};
  std::string password{argv[4]};
  std::string operacion{argv[5]};
  



  return 0;
}