//
// Created by Ivo Ribeiro on 16/05/2023.
//

#include "Livro.h"

// Getter
int Livro::getExemplares() const {
    return exemplares;
}

// Impressão de informações do livro
void Livro::imprimir() const {
        std::cout << "Livro: " << nome << ", Gênero: " << genero << ", Autor: " << autor << ", Exemplares: " << exemplares << std::endl;
}

void Livro::save(std::ostream &myfile) const {
    myfile << "livro:"<< std::endl << nome << std::endl << genero << std::endl << autor << std::endl << exemplares << std::endl;
}