//
// Created by Ivo Ribeiro on 16/05/2023.
//

#ifndef TESTEPA2_COMPONENTEELETRONICO_H
#define TESTEPA2_COMPONENTEELETRONICO_H

#include <iostream>
#include "Objeto.h"

// Classe derivada para componentes eletrônicos
class ComponenteEletronico : public Objeto {
    std::string localizacao;

public:
    ComponenteEletronico(const std::string &nome, const std::string &genero, const std::string &autor,
                         const std::string &localizacao)
            : Objeto(nome, genero, autor), localizacao(localizacao) {}

    // Getter
    std::string getLocalizacao() const;

    // Impressão de informações do componente eletrônico
    void imprimir() const override;
};

#endif //TESTEPA2_COMPONENTEELETRONICO_H
