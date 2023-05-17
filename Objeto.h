//
// Created by Ivo Ribeiro on 16/05/2023.
//

#ifndef TESTEPA2_OBJETO_H
#define TESTEPA2_OBJETO_H

//
// Created by Ivo Ribeiro on 16/05/2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Classe base para objetos
class Objeto {

protected:
    std::string nome;
    std::string genero;
    std::string autor;

public:
    // Construtor
    Objeto(const std::string& nome, const std::string& genero, const std::string& autor);

    // Getters
    std::string getNome() const;
    std::string getGenero() const;
    std::string getAutor() const;

    // Sobrecarga do operador < para ordenação
    bool operator<(const Objeto& other) const;

    // Função virtual para impressão de informações do objeto
    virtual void imprimir() const = 0;
};







#endif //TESTEPA2_OBJETO_H
