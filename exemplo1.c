#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

// Definição da estrutura Aluno
typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

// Função para calcular a média da turma
float calcularMedia(Aluno *alunos, int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].nota;
    }
    return soma / quantidade;
}

// Função para encontrar o aluno com a maior nota
Aluno * encontrarMelhorAluno(Aluno *alunos, int quantidade) {
    Aluno *melhorAluno = &alunos[0];
    for (int i = 1; i < quantidade; i++) {
        if (alunos[i].nota > melhorAluno->nota) {
            melhorAluno = &alunos[i];
        }
    }
    return melhorAluno;
}

// Função para exibir todos os alunos
void exibirAlunos(Aluno *alunos, int quantidade) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s\tIdade: %d\tNota: %.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].nota);
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int quantidade;
    
    // Solicitar a quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidade);
    
    // Preencher informações dos alunos
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%s", alunos[i].nome);
        printf("Digite a idade do aluno %d: ", i+1);
        scanf("%d", &alunos[i].idade);
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].nota);
    }
    
    // Calcular e exibir a média da turma
    float media = calcularMedia(alunos, quantidade);
    printf("Média da turma: %.2f\n", media);
    
    // Encontrar e exibir o aluno com a maior nota
    Aluno *melhorAluno = encontrarMelhorAluno(alunos, quantidade);
    printf("Melhor aluno: %s\tNota: %.2f\n", melhorAluno->nome, melhorAluno->nota);
    
    // Exibir todos os alunos
    exibirAlunos(alunos, quantidade);
    
    return 0;
}