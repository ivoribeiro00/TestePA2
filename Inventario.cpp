//
// Created by Ivo Ribeiro on 16/05/2023.
//

#include "Inventario.h"

// Destrutor para liberar memória alocada para objetos
Inventario::~Inventario() {
    {
        for (Objeto *objeto: objetos) {
           // delete objeto;
        }
    }
}

// Adicionar objeto ao inventário
void Inventario::adicionarObjeto(Objeto *objeto) {

    {
        //apenas adiciona se o objeto ainda não existir no inventário e se o inventário não estiver cheio = 5
        if (objetos.size() == 5) {
            std::cerr << "Inventário cheio " << std::endl;
            return;
        }
        for (const Objeto *obj: objetos) {
            if (obj->getNome() == objeto->getNome()) {
                //explicar o erro
                std::cerr << "Objeto já existe no inventário o objeto:  " << objeto->getNome() << std::endl;
                return;
            }
        }
        //imprimir cada objeto adicionado no inventário e o total de objetos
        std::cout << "Objeto adicionado ao inventário: " << objeto->getNome() << std::endl;
        std::cout << "Total de objetos no inventário: " << objetos.size() + 1 << std::endl;
        objetos.push_back(objeto);

    }
}

// Remover objeto do inventário
void Inventario::removerObjeto(const std::string &nome) {
    {
        //apenas remove se o objeto existir e se o inventário não estiver vazio e avisar se conseguiu remover ou não
        if (objetos.empty()) {
            std::cerr << "Inventário vazio " << std::endl;
            return;
        }
        for (auto it = objetos.begin(); it != objetos.end(); it++) {
            if ((*it)->getNome() == nome) {
                std::cout << "Objeto removido do inventário: " << nome << std::endl;
                objetos.erase(it);
                return;
            }
        }
        std::cerr << "Objeto não existe no inventário " << nome << std::endl;
    }
}

// Listar objetos ordenados por nome
void Inventario::listarObjetosPorNome() const {
    {
        std::vector<Objeto *> copiaObjetos(objetos.begin(), objetos.end());
        std::sort(copiaObjetos.begin(), copiaObjetos.end(), [](const Objeto *obj1, const Objeto *obj2) {
            return *obj1 < *obj2;
        });

        for (const Objeto *objeto: copiaObjetos) {
            objeto->imprimir();
        }
    }
}

// Procurar objeto
void Inventario::procurarObjeto() const {



}

