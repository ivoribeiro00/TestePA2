//
// Created by Ivo Ribeiro on 16/05/2023.
//

#include "ComponenteEletronico.h"

// Getter
std::string ComponenteEletronico::getLocalizacao() const {
    return localizacao;
}

// Impressão de informações do componente eletrônico
void ComponenteEletronico::imprimir() const {
    {
        std::cout << "Componente Eletrônico: " << nome << ", Gênero: " << genero << ", Autor: " << autor
                  << ", Localização: " << localizacao << std::endl;
    }
}
