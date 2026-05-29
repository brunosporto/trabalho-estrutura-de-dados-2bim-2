# trabalho-estrutura-de-dados-2bim-2

Parte 1
Função
void inserirPosicao(NoInt **head, int valor, int posicao)
Objetivo

Inserir um novo elemento em qualquer posição da lista:

Lista vazia
Início
Meio
Final
Exemplo

Antes:

10 -> 20 -> 30 -> NULL

Inserindo 99 na posição 1:

10 -> 99 -> 20 -> 30 -> NULL
Como funciona

Primeiro verifica se a posição é válida:

if (posicao < 0)

Se a posição for 0:

novo->prox = *head;
*head = novo;

O novo nó vira o primeiro da lista.

Para outras posições, percorre a lista até encontrar o nó anterior:

while (atual != NULL && i < posicao - 1)

Depois faz as ligações:

novo->prox = atual->prox;
atual->prox = novo;
Resumo
Cria um novo nó.
Encontra a posição desejada.
Ajusta os ponteiros.
Não cria nova lista.
Parte 2
Função
int buscarValor(NoInt *head, int valor)
Objetivo

Procurar um valor dentro da lista.

Exemplo

Lista:

10 -> 20 -> 30 -> NULL

Buscar:

20

Retorno:

1
Como funciona

Percorre toda a lista:

while (head != NULL)

Compara:

if (head->valor == valor)

Se encontrar:

return posicao;

Se chegar ao final:

return -1;
Resumo
Percorre nó por nó.
Retorna a posição do valor.
Retorna -1 se não existir.
Parte 3
Função
void inverterLista(NoInt **head)
Objetivo

Inverter a ordem dos elementos.

Exemplo

Antes:

10 -> 20 -> 30 -> NULL

Depois:

30 -> 20 -> 10 -> NULL
Como funciona

Utiliza três ponteiros:

anterior
atual
proximo

Inicialmente:

anterior = NULL
atual = primeiro nó

A cada repetição:

Guarda o próximo:

proximo = atual->prox;

Inverte o ponteiro:

atual->prox = anterior;

Avança:

anterior = atual;
atual = proximo;

No final:

*head = anterior;
Resumo
Não usa vetor.
Não cria nova lista.
Apenas muda os ponteiros de direção.
Parte 4
Função
void dividirLista(NoInt *head,
                  NoInt **lista1,
                  NoInt **lista2)
Objetivo

Dividir a lista em duas listas menores.

Exemplo

Antes:

10 -> 20 -> 30 -> 40 -> 50 -> NULL

Depois:

Lista1:
10 -> 20 -> 30 -> NULL

Lista2:
40 -> 50 -> NULL
Como funciona

Usa dois ponteiros:

lento
rapido

O lento anda:

1 nó por vez

O rápido anda:

2 nós por vez

Enquanto:

rapido->prox != NULL

Quando o rápido chega ao fim:

lento

está no meio da lista.

Então:

*lista2 = lento->prox;
lento->prox = NULL;

Corta a lista em duas partes.

Resumo
Não conta elementos.
Usa técnica rápido/lento.
Se for ímpar, a primeira lista fica com um elemento a mais.

Parte 5
Estrutura
typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;
Objetivo

Criar uma playlist onde seja possível:

Avançar músicas.
Voltar músicas.
Repetir infinitamente.
Contar músicas.
5.1 Adicionar Música
Função
void adicionarMusica(No **head, char *nome)
Exemplo

Após adicionar:

Rock
Jazz
Pop

A estrutura fica:

Rock <-> Jazz <-> Pop
 ^                |
 |________________|
Como funciona

O novo nó é inserido no final.

O último aponta para o primeiro:

ultimo->prox = novo;

O primeiro aponta para o último:

head->ant = novo;

Mantendo a circularidade.

5.2 Próxima Música
Função
void proximaMusica(No **atual)

Avança:

*atual = (*atual)->prox;

Exemplo:

Rock → Jazz → Pop → Rock
5.3 Música Anterior
Função
void musicaAnterior(No **atual)

Volta:

*atual = (*atual)->ant;

Exemplo:

Rock ← Jazz ← Pop
5.4 Exibir Playlist
Função
void exibirPlaylist(No *head)

Percorre usando:

do {
    ...
} while(atual != head);

Assim para quando retorna ao início.

5.5 Total de Músicas
Função
int totalMusicas(No *head)

Conta quantos nós existem.

Exemplo:

Rock
Jazz
Pop

Retorna:

3
5.6 Controle para evitar loop infinito

Como a playlist é circular:

Rock -> Jazz -> Pop -> Rock -> Jazz...

Ela nunca termina naturalmente.

Por isso usamos:

while(atual != head)

ou

do {
   ...
} while(atual != head);

Quando o ponteiro volta ao início, sabemos que todas as músicas já foram percorridas uma vez.
