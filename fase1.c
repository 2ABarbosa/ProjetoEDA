#include <stdio.h>
#include <stdlib.h>
#include "antenas.h"

Antena* criarAntena(char frequencia, int x, int y) {
    Antena* nova = (Antena*)malloc(sizeof(Antena));
    nova->frequencia = frequencia;
    nova->x = x;
    nova->y = y;
    nova->prox = NULL;
    return nova;
}

void inserirAntena(Antena **lista, char frequencia, int x, int y) {
    Antena *nova = criarAntena(frequencia, x, y);
    nova->prox = *lista;
    *lista = nova;
    printf("Antena inserida com sucesso!\n");
}

void removerAntena(Antena **lista, int x, int y) {
    Antena *atual = *lista, *anterior = NULL;
    while (atual != NULL && (atual->x != x || atual->y != y)) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Antena nao encontrada!\n");
        return;
    }
    if (anterior == NULL) *lista = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
    printf("Antena removida com sucesso!\n");
}

void imprimirAntenas(Antena *lista) {
    if (lista == NULL) {
        printf("Nenhuma antena cadastrada.\n");
        return;
    }
    printf("Lista de Antenas:\n");
    while (lista != NULL) {
        printf("Frequencia: %c, Posicao: (%d, %d)\n", lista->frequencia, lista->x, lista->y);
        lista = lista->prox;
    }
}

void exibirMapa(Antena *lista) {
    char mapa[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            mapa[i][j] = '.';
        }
    }
    Antena *atual = lista;
    while (atual != NULL) {
        if (atual->x >= 0 && atual->x < MAP_SIZE && atual->y >= 0 && atual->y < MAP_SIZE) {
            mapa[atual->y][atual->x] = atual->frequencia;
        }
        atual = atual->prox;
    }
    printf("\nMapa de Antenas:\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}

void detectarInterferencia(Antena *lista) {
    Antena *a1, *a2;
    int interferencia = 0;
    printf("\nAntenas com interferencia (Efeito Nefasto):\n");
    for (a1 = lista; a1 != NULL; a1 = a1->prox) {
        for (a2 = a1->prox; a2 != NULL; a2 = a2->prox) {
            if (a1->frequencia == a2->frequencia) {
                int distancia = abs(a1->x - a2->x) + abs(a1->y - a2->y);
                if (distancia <= 2) {
                    printf("Antenas em (%d, %d) e (%d, %d) com frequencia '%c' estão em interferencia!\n", 
                           a1->x, a1->y, a2->x, a2->y, a1->frequencia);
                    interferencia = 1;
                }
            }
        }
    }
    if (!interferencia) {
        printf("Nenhuma interferencia detectada.\n");
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1 - Inserir Antena\n");
    printf("2 - Remover Antena\n");
    printf("3 - Listar Antenas\n");
    printf("4 - Exibir Mapa\n");
    printf("5 - Detectar Interferencias\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Antena *lista = NULL;
    int opcao, x, y;
    char freq;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite a frequencia (A-Z): ");
                scanf(" %c", &freq);
                printf("Digite as coordenadas (x y): ");
                scanf("%d %d", &x, &y);
                inserirAntena(&lista, freq, x, y);
                break;
            case 2:
                printf("Digite as coordenadas da antena a remover (x y): ");
                scanf("%d %d", &x, &y);
                removerAntena(&lista, x, y);
                break;
            case 3:
                imprimirAntenas(lista);
                break;
            case 4:
                exibirMapa(lista);
                break;
            case 5:
                detectarInterferencia(lista);
                break;
            case 0:
                printf("A sair...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}
