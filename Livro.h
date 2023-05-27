//
// Created by Ivo Ribeiro on 16/05/2023.
//

#ifndef TESTEPA2_LIVRO_H
#define TESTEPA2_LIVRO_H

#include <iostream>
#include "Objeto.h"

// Classe derivada para livros
class Livro : public Objeto {
    int ano;

public:
    Livro(const std::string& nome, const std::string& genero, const std::string& autor, const int& ano)
            : Objeto(nome, genero, autor), ano(ano) {}

    // Getter
    const int &getAno() const;

    // Impressão de informações do livro
    void imprimir() const override;
    void save(std::ostream &myfile) const override;




};

#endif //TESTEPA2_LIVRO_H
