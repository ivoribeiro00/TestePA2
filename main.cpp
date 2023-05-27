#include "Inventario.h"
#include "Livro.h"
#include "ComponenteEletronico.h"

int main() {
    // Criar instância do inventário
    Inventario inventario("../inventario.txt");

    int opcao = -1;

    //Mostrar menu
    inventario.apresentarMenu();
    std::cin >> opcao;
    std::cout << std::endl;

    // Executar opções do menu
    while (opcao != 6) {
        switch (opcao) {
            case 1:
                //Adicionar Livro
                inventario.adicionarLivro();
                break;
            case 2:
                //Adicionar Componente Eletronico
                inventario.adicionarComponenteEletronico();
                break;
            case 3:
                //Remover objeto
                inventario.auxRemoverObjeto();
                break;
            case 4:
                //Procurar objeto
                inventario.procurarObjeto();
                break;
            case 5:
                //Listar objetos
                inventario.listarObjetosPorNome();
                break;
            default:
                std::cerr << "Opção inválida!" << std::endl;
        }
        inventario.apresentarMenu();
        std::cin >> opcao;
        std::cout << std::endl;
    }

/*
    // Criar objetos e adicionar ao inventário
    Livro *livro1 = new Livro("Livro A", "Gênero A", "Autor A", 5);
    Livro *livro2 = new Livro("Livro B", "Gênero B", "Autor B", 3);
    ComponenteEletronico *componente1 = new ComponenteEletronico("Componente A", "Gênero C", "Autor C",
                                                                 "Localização A");
    Livro *livro3 = new Livro("Livro C", "Gênero A", "Autor A", 2);

    inventario.adicionarLivro();
    inventario.adicionarObjeto(livro1);
    inventario.adicionarObjeto(livro2);
    inventario.adicionarObjeto(componente1);
    inventario.adicionarObjeto(livro3);
    std::cout << std::endl;


    std::cout << "Tentar adicionar objeto repetido no inventário -> " << livro3->getNome() << std::endl;


    inventario.adicionarObjeto(livro3);
    std::cout << std::endl;

    // Imprimir objetos no inventário (ordenados por nome)
    inventario.listarObjetosPorNome();
    std::cout << std::endl;

    // Remover um objeto do inventário
    std::cout << "Removendo objeto do inventário -> " << livro3->getNome() << std::endl;
    inventario.removerObjeto("Livro C");
    std::cout << std::endl;


    // Imprimir objetos no inventário após a remoção
    inventario.listarObjetosPorNome();

*/
    return 0;
}
