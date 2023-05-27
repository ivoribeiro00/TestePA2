//
// Created by Ivo Ribeiro on 16/05/2023.
//

#include "Inventario.h"
#include "Livro.h"
#include "ComponenteEletronico.h"

Inventario::Inventario(std::string filename) {
    this->filename = filename;
    this->read();
}

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
    save();
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
                save();
                return;
            }
        }
        std::cerr << "Objeto: " << nome << " não existe no inventário!! "  << std::endl;
    }
}

void Inventario::auxRemoverObjeto() {
    std::string nome;
    std::cout << "Digite o nome do objeto: " << std::endl;
    std::cin >> nome;
    removerObjeto(nome);
}


// Listar objetos ordenados por nome
void Inventario::listarObjetosPorNome() {
    std::vector<Objeto *> copiaObjetos(objetos.begin(), objetos.end());
    std::sort(copiaObjetos.begin(), copiaObjetos.end(), [](const Objeto *obj1, const Objeto *obj2) {
        return *obj1 < *obj2;
    });

    for (const Objeto *objeto: copiaObjetos) {
        objeto->imprimir();
    }
}

// Procurar objeto
void Inventario::procurarObjeto() const {
    //apenas procura se o inventário não estiver vazio
    if (objetos.empty()) {
        std::cerr << "Inventário vazio " << std::endl;
        return;
    }
    std::string nome;
    std::cout << "Digite o nome do objeto que procura: " << std::endl;
    std::cin >> nome;
    for (const Objeto *objeto: objetos) {
        if (objeto->getNome() == nome) {
            objeto->imprimir();
            return;
        }
    }
}

void Inventario::apresentarMenu() const {
    std::cout << "  Menu Inventário" << std::endl;
    std::cout << "1 - Adicionar Livro" << std::endl;
    std::cout << "2 - Adicionar Componente Eletronico" << std::endl;
    std::cout << "3 - Remover objeto" << std::endl;
    std::cout << "4 - Procurar objeto" << std::endl;
    std::cout << "5 - Listar objetos" << std::endl;
    std::cout << "6 - Sair" << std::endl;
    std::cout << "Escolha uma opção: " << std::endl;
}

void Inventario::adicionarLivro() {
    //tem que receber os dados do livro
    std::string nome;
    std::string genero;
    std::string autor;
    int ano;

    std::cout << "Digite o nome do livro: " << std::endl;
    std::cin >> nome;
    fflush(stdin);
    std::cout << "Digite o gênero do livro: " << std::endl;
    std::cin >> genero;
    fflush(stdin);
    std::cout << "Digite o autor do livro: " << std::endl;
    std::cin >> autor;
    fflush(stdin);
    std::cout << "Digite o ano do livro: " << std::endl;
    std::cin >> ano;
    fflush(stdin);
    Livro *livro = new Livro(nome, genero, autor, ano);
    adicionarObjeto(livro);
}

void Inventario::adicionarComponenteEletronico() {
    //tem que receber os dados do componente eletronico
    std::string nome;
    std::string genero;
    std::string dono;
    std::string localizacao;

    std::cout << "Digite o nome do componente eletronico: " << std::endl;
    std::cin >> nome;
    //limpar o cin
    fflush(stdin);
    std::cout << "Digite a marca do componente eletronico: " << std::endl;
    std::cin >> genero;
    fflush(stdin);
    std::cout << "Digite a descrição do componente eletronico: " << std::endl;
    std::cin >> dono;
    fflush(stdin);
    std::cout << "Digite a localização do componente eletronico: " << std::endl;
    std::cin >> localizacao;
    fflush(stdin);

    ComponenteEletronico *componente = new ComponenteEletronico(nome, genero, dono, localizacao);
    adicionarObjeto(componente);
}

void Inventario::read() {
    std::ifstream myfile(filename);

    if (myfile.is_open()) {
        std::string line;

        while (getline(myfile, line)) {
            std::cout << line << std::endl;
            if (line == "livro:") {
                // ler as specificações
                std::string nome;
                getline(myfile, nome);
                std::string genero;
                getline(myfile, genero);
                std::string autor;
                getline(myfile, autor);
                int ano;
                myfile >> ano;
                Livro *livro = new Livro(nome, genero, autor, ano);
                objetos.push_back(livro);
            }
            if (line == "componente:") {
                // ler as specificações
                std::string nome;
                getline(myfile, nome);
                std::string marca;
                getline(myfile, marca);
                std::string dono;
                getline(myfile, dono);
                std::string localizacao;
                getline(myfile, localizacao);

                ComponenteEletronico *componente = new ComponenteEletronico(nome, marca, dono, localizacao);
                objetos.push_back(componente);
            }
        }
        myfile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
    }
}

void Inventario::save() {
    std::ofstream myfile(filename);

    for (const Objeto *objeto: objetos) {
        objeto->save(myfile);
    }
    myfile.close();
}



