//
// Created by Ivo Ribeiro on 16/05/2023.
//

#ifndef TESTEPA2_INVENTARIO_H
#define TESTEPA2_INVENTARIO_H

#include <vector>
#include "Objeto.h"

// Classe para o inventário
class Inventario {
private:
    std::vector<Objeto *> objetos;

public:

    // Destrutor para liberar memória alocada para objetos
    ~Inventario();

    // Adicionar objeto ao inventário
    void adicionarObjeto(Objeto *objeto);

    // Remover objeto do inventário
    void removerObjeto(const std::string &nome);

    // Listar objetos ordenados por nome
    void listarObjetosPorNome() const;
};


#endif //TESTEPA2_INVENTARIO_H
