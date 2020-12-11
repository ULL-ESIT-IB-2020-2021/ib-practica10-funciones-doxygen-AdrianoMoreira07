#
# Universidad de La Laguna; Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática (1º)
# Asignatura: Informática Básica
# 
# @author Adriano dos Santos Moreira <alu0101436784@ull.edu.es> 
# @brief makefile para cripto
# 

CXX=g++
CXXFLAGS=-g -std=c++14 -Wall -I.
OBJ = cripto.o funciones_cripto.o

cripto: $(OBJ)
	$(CXX) -o $@ $^

.PHONY: clean

	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o
	rm cripto
