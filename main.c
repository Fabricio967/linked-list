#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct livro{

    int codigo;
    char titulo[30];
    char autor[20];
    float preco;
    struct livro *proximo;

}Livro;

typedef struct lista{

    Livro *primeiro;
    Livro *ultimo;
    int tamanho;

}Lista;

Lista *criar_lista(); //funcao que cria a lista
void inserir(Livro conteudo, Lista *nome); // funcao que insere um no na lista, no final
void exibir(Lista *nome); // funcao que exibe os elementos da lista
Livro cadastrar(); //funcao que preenche os campos do Nó Livro
void destruir(Lista *nome); //funcao que destroi a lista
void menu(void); //funcao complementar, apresenta o menu de opcoes do programa
void loading(void); //funcao para "carregar"
void pop(Lista *nome); //funcao que remove um item da lista
void InsereEmOrdemAlfabetica(Lista *list, Livro nome); //funcao
int isEmpty(Lista *nome); //funcao que verifica se a lista esta vazia

Lista *criar_lista(){

    Lista *p; //criando um ponteiro para Lista
    p = (Lista* ) malloc(sizeof(Lista));

    if(!p){
        printf("\nNao foi possivel criar a lista.");
        exit(1);
    }

    p->tamanho = 0;
    p->primeiro = NULL;
    p->ultimo = NULL;

    return p;
}

void inserir(Livro data, Lista *list){

    Livro *plivro = (Livro*) malloc(sizeof(Livro));

    if(!plivro){
        exit(1);
    }

    if(isEmpty(list)){

        *plivro = data;
        list->primeiro = plivro;
        list->ultimo = list->primeiro;
        list->tamanho++;

    }
    else{

        Livro *auxiliar = (Livro*) malloc(sizeof(Livro));
        auxiliar = list->primeiro;

        while(auxiliar->proximo){
            auxiliar = auxiliar->proximo;

        }

        *plivro = data;
        list->ultimo = plivro;
        auxiliar->proximo = plivro;
        list->tamanho++;

    }
}

void exibir(Lista *list){ //funcao que exibe o conteudo da lista

    Livro *auxiliar = (Livro*) malloc(sizeof(Livro));
    auxiliar = list->primeiro;
    int cont = 1;
    system("cls");

    if(auxiliar){
        while(auxiliar){
            //printf("-------------------------------------\n");
            printf("\nLivro %d:\n", cont);
            printf("\nCodigo do Livro: %d\n", auxiliar->codigo);
            printf("\nTitulo do Livro: %s", auxiliar->titulo);
            printf("\nAutor do Livro: %s", auxiliar->autor);
            printf("\nPreco do Livro: R$ %.2f", auxiliar->preco);
            printf("\n-------------------------------------");

            auxiliar = auxiliar->proximo;
            cont++;

        }
    }
    else{
        printf("\nLista Vazia.");
    }
}

Livro cadastrar(){ //função usada para fazer o cadastro dos livros

    setlocale(LC_ALL, "");
    Livro auxiliar;

    loading();
    Sleep(250);
    system("cls");

    printf("\n1. Qual o código do livro? \n");
    //setbuf(stdin, NULL);
    scanf("%d%*c", &auxiliar.codigo);

    /*
    printf("\n2. Qual o título do livro? \n");
    //setbuf(stdin, NULL);
    fgets(auxiliar.titulo, 30, stdin);

    printf("\n3. Quem é o autor do livro? \n");
    //setbuf(stdin, NULL);
    fgets(auxiliar.autor, 20, stdin);

    printf("\n4. Qual o preço do livro? \n");
    //setbuf(stdin, NULL);
    scanf("%f%*c", &auxiliar.preco); */

    auxiliar.proximo = NULL;

    printf("\nCadastro realizado com sucesso!\n");
    printf("-----------------------------------\n");
    loading();
    Sleep(1000);
    system("cls");

    return auxiliar;

}

void InsereEmOrdemAlfabetica(Lista *list, Livro conteudo){

    Livro *plivro = (Livro*) malloc(sizeof(Livro));

    if(!plivro){
        printf("\nErro: Memoria nao alocada.\n");
        exit(1);
    }

    if(list->primeiro == NULL){

        *plivro = conteudo;
        list->primeiro = plivro;
        list->ultimo = list->primeiro;
        list->tamanho++;

    }



}

void pop(Lista *list){

    if(list == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Livro *auxiliar = (Livro*) malloc(sizeof(Livro));
        auxiliar = list->primeiro->proximo;
        free(list->primeiro);
        list->primeiro = auxiliar;
        list->tamanho--;
    }
}

int isEmpty(Lista *list){

    if(!list->primeiro){
        printf("\nisEmpty Yes.\n");
        return 1;
    }
    else{
        printf("\nisEmpty No.\n");
        return 1;
    }

}

void destruir(Lista *list){

    free(list);

}

void menu(void){

    system("cls");
    printf("=====================================\n");
    printf("\t\tMENU\n");
    printf("=====================================\n");
    printf("\nPor favor, selecione uma opção válida.\n\n");
    printf("\n[1] Cadastrar um livro: \n[2] Listar todos os livros: \n[3] Remover um livro: \n[0] Sair do programa:\n\n");
    printf("-------------------------------------\n");

}

void loading(void){

    int i;
    for(i = 0; i < 3; i++){
        printf(".");
        Sleep(333);
    }
}

int main(){

    setlocale(LC_ALL, "");

    int opcao_menu;
    char criaLista;
    Lista *A = criar_lista();

    printf("=====================================\n");
    printf("\tCADASTRO DE LIVROS\n");
    printf("=====================================\n");

    printf("\nDeseja criar uma lista de livros? [s/n]\n");
    scanf("%c%*c", &criaLista);

    if(criaLista == 's' || criaLista == 'S'){

        loading();

        do{
            Sleep(750);
            menu();
            scanf("%d%*c", &opcao_menu);

            switch(opcao_menu){

                case 1: printf("\nOk, aguarde um instante"); //Opcao de cadastro
                isEmpty(A);
                inserir(cadastrar(), A);
                isEmpty(A);

                break;

                case 2: printf("\nListando");
                loading();
                exibir(A);
                printf("\nPressione enter para voltar ao menu anterior: ");
                getchar();

                break;

                case 3: printf("\nRemovendo.");
                pop(A);

                case 0: printf("\nSaindo.\n");
                loading();
                break;

                default: printf("\nOpcao Invalida.");
                break;

            }

        }while(opcao_menu != 0);

    }
    else if(criaLista == 'n' || criaLista == 'N'){
        printf("\nObrigado.\n");
    }
    else{
        printf("\nComando invalido.\n");
        exit(1);
    }

    destruir(A);

    return 0;
}
