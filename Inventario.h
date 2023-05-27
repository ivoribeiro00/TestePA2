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
    std::string filename;
    // Funções auxiliares para leitura e escrita de objetos
    void read();
    void save();

public:
    Inventario(std::string filename);
    // Destrutor para liberar memória alocada para objetos
    ~Inventario();

    // Adicionar objeto ao inventário
    void adicionarObjeto(Objeto *objeto);

    // Remover objeto do inventário
    void removerObjeto(const std::string &nome);

    // Listar objetos ordenados por nome
    void listarObjetosPorNome();

    // Procurar objeto
    void procurarObjeto() const;

    // Apresentar Possivel Menu
    void apresentarMenu() const;

    // Adicionar Livro
    void adicionarLivro();

    // Adicionar Componente Eletronico
    void adicionarComponenteEletronico();

    // Remover Objeto (receber o nome)
    void auxRemoverObjeto();
};


#endif //TESTEPA2_INVENTARIO_H
