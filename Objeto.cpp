//
// Created by Ivo Ribeiro on 16/05/2023.
//

#include "Objeto.h"

// Construtor
Objeto::Objeto(const std::string &nome, const std::string &genero, const std::string &autor) {
    this->nome = nome;
    this->genero = genero;
    this->autor = autor;
}

// Getters
std::string Objeto::getNome() const {
    return nome;
}

std::string Objeto::getGenero() const {
    return genero;
}

std::string Objeto::getAutor() const {
    return autor;
}

// Sobrecarga do operador < para ordenação
bool Objeto::operator<(const Objeto &other) const {
    return nome < other.nome;
}
