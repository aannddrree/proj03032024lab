#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 100
#define MAX_AUTOR 50

// Definição da estrutura Livro
typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
} Livro;

// Função para adicionar um livro
void adicionarLivro(Livro *biblioteca, int *quantidade) {
    printf("Digite o título do livro: ");
    scanf(" %[^\n]s", biblioteca[*quantidade].titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]s", biblioteca[*quantidade].autor);
    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &biblioteca[*quantidade].ano);
    (*quantidade)++;
}

// Função para listar todos os livros
void listarLivros(Livro *biblioteca, int quantidade) {
    if (quantidade == 0) {
        printf("Biblioteca vazia.\n");
        return;
    }
    printf("Lista de Livros:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Título: %s\tAutor: %s\tAno: %d\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano);
    }
}

// Função para buscar um livro pelo título
void buscarLivroPorTitulo(Livro *biblioteca, int quantidade, char *tituloBusca) {
    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(biblioteca[i].titulo, tituloBusca) == 0) {
            printf("Livro encontrado:\n");
            printf("Título: %s\tAutor: %s\tAno: %d\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Livro não encontrado.\n");
    }
}

int main() {
    Livro biblioteca[100]; // Capacidade máxima da biblioteca
    int quantidade = 0;
    int opcao;
    char tituloBusca[MAX_TITULO];

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar novo livro\n");
        printf("2. Listar todos os livros\n");
        printf("3. Buscar livro pelo título\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(biblioteca, &quantidade);
                break;
            case 2:
                listarLivros(biblioteca, quantidade);
                break;
            case 3:
                printf("Digite o título do livro a buscar: ");
                scanf(" %[^\n]s", tituloBusca);
                buscarLivroPorTitulo(biblioteca, quantidade, tituloBusca);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}