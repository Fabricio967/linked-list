#include <stdio.h>
#include <stdlib.h>

typedef struct livro{
    int codigo;
    char titulo[30];
    char autor[20];
    float preco;
    struct livro *proximo;
} Livro;

typedef struct lista{
    int tamanho;
    Livro *primeiro;
    Livro *ultimo;
} Lista;

void menu(void);
Lista *criar_lista();
void adicionarElemento(Lista *lista, Livro livro);
Livro cadastrarLivro();
void exibirLista(Lista *lista);
void removerNoInicio(Lista *lista);
void removerNoFinal(Lista *lista);
void removerElemento(Lista *lista);
int estaVazia(Lista *list);
void carregarDados(Lista *listaDeLivros);