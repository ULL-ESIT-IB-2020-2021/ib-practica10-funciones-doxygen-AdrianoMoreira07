/**
 * Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática (1º)
 * Asignatura: Informática Básica
 * 
 * @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
 * @brief Header para cripto.cc
 */

#include <string>

/**
 * Muestra mensajes en funcion de si el número de parámetros
 * es inapropiado (!= 6) ó si el usuario escribe '--help'
 *
 * @param argc Número de parámetros de entrada del programa
 * @param argv Parámetros de entrada del programa
 * @return void
 */
void Inicio (int argc, char* argv[]);

/**
 * Sale del programa si el nombre de los ficheros son inapropiados
 * o si los nombres coinciden
 * 
 * @param fichero_entrada Nombre del fichero de entrada
 * @param fichero_salida Nombre del fichero de salida
 * @return void
 */
void ComprobarRuta (const std::string& fichero_entrada,const std::string& fichero_salida);

/**
 * Comprueba si el fichero contiene * . " \ [ ] : ; | ,
 * 
 * @param nombre_fichero Nombre del fichero a analizar
 * @return 1 si hay caracteres prohibidos y 0 si no los hay
 */
bool TieneCaracteresProhibidos(const std::string& nombre_fichero);