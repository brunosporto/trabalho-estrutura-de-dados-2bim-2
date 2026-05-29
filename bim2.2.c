#include <stdio.h>
#include <stdlib.h>

typedef struct NoInt {
    int valor;
    struct NoInt *prox;
} NoInt;

NoInt* criarNoInt(int valor) {
    NoInt *novo = (NoInt*) malloc(sizeof(NoInt));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirFim(NoInt **head, int valor) {
    NoInt *novo = criarNoInt(valor);

    if (*head == NULL) {
        *head = novo;
        return;
    }

    NoInt *atual = *head;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
}

void inserirPosicao(NoInt **head, int valor, int posicao) {
    if (posicao < 0) {
        printf("Posicao invalida!\n");
        return;
    }

    NoInt *novo = criarNoInt(valor);

    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    NoInt *atual = *head;
    int i = 0;

    while (atual != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        printf("Posicao invalida!\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

int buscarValor(NoInt *head, int valor) {
    int posicao = 0;

    while (head != NULL) {
        if (head->valor == valor) {
            return posicao;
        }

        head = head->prox;
        posicao++;
    }

    return -1;
}

void inverterLista(NoInt **head) {
    NoInt *anterior = NULL;
    NoInt *atual = *head;
    NoInt *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

void dividirLista(NoInt *head, NoInt **lista1, NoInt **lista2) {
    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    NoInt *lento = head;
    NoInt *rapido = head;

    while (rapido->prox != NULL && rapido->prox->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;
    lento->prox = NULL;
}

void exibirLista(NoInt *head) {
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }

    printf("NULL\n");
}

void liberarLista(NoInt *head) {
    NoInt *temp;

    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

void copiarTexto(char *destino, char *origem) {
    int i = 0;

    while (origem[i] != '\0' && i < 99) {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

void adicionarMusica(No **head, char *nome) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    copiarTexto(novo->musica, nome);

    if (*head == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *head = novo;
        return;
    }

    No *ultimo = (*head)->ant;

    novo->prox = *head;
    novo->ant = ultimo;

    ultimo->prox = novo;
    (*head)->ant = novo;
}

void proximaMusica(No **atual) {
    if (*atual != NULL) {
        *atual = (*atual)->prox;
    }
}

void musicaAnterior(No **atual) {
    if (*atual != NULL) {
        *atual = (*atual)->ant;
    }
}

void exibirPlaylist(No *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    No *atual = head;

    do {
        printf("[%s] <-> ", atual->musica);
        atual = atual->prox;
    } while (atual != head);

    printf("(volta ao inicio)\n");
}

int totalMusicas(No *head) {
    if (head == NULL) {
        return 0;
    }

    int total = 0;
    No *atual = head;

    do {
        total++;
        atual = atual->prox;
    } while (atual != head);

    return total;
}

void tocarTodas(No *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    No *atual = head;

    do {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
    } while (atual != head);
}

void liberarPlaylist(No **head) {
    if (*head == NULL) {
        return;
    }

    No *atual = (*head)->prox;
    No *temp;

    while (atual != *head) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(*head);
    *head = NULL;
}

int main() {
    NoInt *lista = NULL;
    NoInt *lista1 = NULL;
    NoInt *lista2 = NULL;

    printf("=== Lista Encadeada Simples ===\n");

    inserirFim(&lista, 10);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);

    printf("Lista original:\n");
    exibirLista(lista);

    inserirPosicao(&lista, 99, 1);

    printf("Depois de inserir 99 na posicao 1:\n");
    exibirLista(lista);

    int pos = buscarValor(lista, 20);

    if (pos != -1) {
        printf("Valor 20 encontrado na posicao %d\n", pos);
    } else {
        printf("Valor nao encontrado!\n");
    }

    inverterLista(&lista);

    printf("Lista invertida:\n");
    exibirLista(lista);

    dividirLista(lista, &lista1, &lista2);

    printf("Lista 1:\n");
    exibirLista(lista1);

    printf("Lista 2:\n");
    exibirLista(lista2);

    liberarLista(lista1);
    liberarLista(lista2);

    printf("\n=== Playlist Circular Duplamente Encadeada ===\n");

    No *playlist = NULL;
    No *atual = NULL;

    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    atual = playlist;

    printf("Playlist:\n");
    exibirPlaylist(playlist);

    printf("Total de musicas: %d\n", totalMusicas(playlist));

    printf("\nNavegando para frente:\n");
    printf("Atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Atual: %s\n", atual->musica);

    printf("\nVoltando para musica anterior:\n");
    musicaAnterior(&atual);
    printf("Atual: %s\n", atual->musica);

    printf("\nTocando todas sem loop infinito:\n");
    tocarTodas(playlist);

    liberarPlaylist(&playlist);

    return 0;
}