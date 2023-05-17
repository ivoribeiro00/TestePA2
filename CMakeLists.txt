cmake_minimum_required(VERSION 3.25)
project(TestePA2)

set(CMAKE_CXX_STANDARD 23)

add_executable(TestePA2 main.cpp Inventario.cpp Inventario.h Objeto.cpp Objeto.h ComponenteEletronico.cpp ComponenteEletronico.h Livro.cpp Livro.h)
