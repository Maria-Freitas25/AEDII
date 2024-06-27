#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de dados para o grafo
typedef struct {
    int vertices;
    int arestas;
    int **matrizAdj;
} GRAFO;

// Função para criar um grafo
GRAFO* criaGrafo(int vertices) {
    GRAFO* grafo = (GRAFO*)malloc(sizeof(GRAFO));
    grafo->vertices = vertices;
    grafo->arestas = 0;
    
    // Alocando memória para a matriz de adjacência
    grafo->matrizAdj = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        grafo->matrizAdj[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            grafo->matrizAdj[i][j] = 0; // Inicializa a matriz com 0
        }
    }
    return grafo;
}

// Função para inserir uma aresta
void insereAresta(GRAFO* grafo, int origem, int destino, int peso) {
    if (origem < 0 || origem >= grafo->vertices || destino < 0 || destino >= grafo->vertices) {
        printf("Erro: vértice inválido.\n");
        return;
    }
    grafo->matrizAdj[origem][destino] = peso;
    grafo->arestas++;
}

// Função para exibir o grafo
void exibeGrafo(GRAFO* grafo) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < grafo->vertices; i++) {
        for (int j = 0; j < grafo->vertices; j++) {
            printf("%d ", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

// Função principal para testar o TAD
int main() {
    int vertices = 5;
    GRAFO* grafo = criaGrafo(vertices);
    
    insereAresta(grafo, 0, 1, 2);
    insereAresta(grafo, 0, 2, 4);
    insereAresta(grafo, 1, 2, 1);
    insereAresta(grafo, 1, 3, 7);
    insereAresta(grafo, 2, 4, 3);
    insereAresta(grafo, 3, 4, 1);
    
    exibeGrafo(grafo);
    
    // Liberando memória
    for (int i = 0; i < vertices; i++) {
        free(grafo->matrizAdj[i]);
    }
    free(grafo->matrizAdj);
    free(grafo);
    
    return 0;
}
