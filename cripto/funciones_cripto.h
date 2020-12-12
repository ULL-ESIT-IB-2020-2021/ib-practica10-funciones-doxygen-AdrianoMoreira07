/**
 * Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática (1º)
 * Asignatura: Informática Básica
 * 
 * @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
 * @brief Header para cripto.cc
 */

#include <string>
#include <bitset>

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
 * Sale del programa si los nombres coinciden
 * 
 * @param fichero_entrada Nombre del fichero de entrada
 * @param fichero_salida Nombre del fichero de salida
 * @return void
 */
void ComprobarRuta (const std::string& fichero_entrada,const std::string& fichero_salida);

/**
 * Encripta una línea con el cifrado xor
 * 
 * @param linea La línea a encriptar
 * @param pass Contraseña con la que encriptar
 * @return La línea encriptada
 */
std::string CifradoXor (const std::string& linea, const std::string pass);

/**
 * Encripta una línea con el cifrado de César
 * 
 * @param linea La línea a encriptar
 * @param pass Número de posiciones a mover por cada caracter
 * @return La línea encriptada
 */
std::string CifradoCesar (const std::string& linea, const int& pass);