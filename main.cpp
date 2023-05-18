#include "Inventario.h"
#include "Livro.h"
#include "ComponenteEletronico.h"

int main() {
    // Criar instância do inventário
    Inventario inventario;

    // Criar objetos e adicionar ao inventário
    Livro* livro1 = new Livro("Livro A", "Gênero A", "Autor A", 5);
    Livro* livro2 = new Livro("Livro B", "Gênero B", "Autor B", 3);
    ComponenteEletronico* componente1 = new ComponenteEletronico("Componente A", "Gênero C", "Autor C", "Localização A");
    Livro* livro3 = new Livro("Livro C", "Gênero A", "Autor A", 2);

    inventario.adicionarObjeto(livro1);
    inventario.adicionarObjeto(livro2);
    inventario.adicionarObjeto(componente1);
    inventario.adicionarObjeto(livro3);
    std::cout << std::endl;


    std::cout << "Tentar adicionar objeto repetido no inventário -> " << livro3->getNome() << std::endl;
    //todo tentar adicionarObjeto(pelo nome)
    //todo tentar
    //todo escrever para ficheiro a lista de objeto que já estão dentro do inventario
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


    return 0;
}
