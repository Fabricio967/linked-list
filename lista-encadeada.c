#include "lista-encadeada.h"

void menu(void){

    system("cls");
    printf("=====================================\n");
    printf("\t\tMENU\n");
    printf("=====================================\n");
    printf("\nPor favor, selecione uma opcao valida.\n\n");
    printf("\n[1] Cadastrar um livro    \n[2] Listar todos os livros");
    printf("\n[3] Remover um livro");
    printf("\n[4] Carregar Dados (Modo para preguicosos)");
    printf("\n[0] Sair do programa");
    printf("\n----------------------------------------------\n");
    printf("Sua opcao: ");

}

Lista *criar_lista(){

    Lista *lista = (Lista* ) malloc(sizeof(Lista));

    if(!lista){
        printf("\nNao foi possivel criar a lista.");
        exit(1);
    }

    lista->tamanho = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void adicionarElemento(Lista *lista, Livro livro){
    Livro *auxiliar = (Livro*) malloc(sizeof(Livro));

    *auxiliar = livro;

    if(estaVazia(lista)){
        auxiliar->proximo = NULL;
        lista->primeiro = auxiliar;
        lista->ultimo = auxiliar;
        lista->tamanho++;
    }
    else{
        auxiliar->proximo = NULL;
        lista->ultimo->proximo = auxiliar;
        lista->ultimo = auxiliar;
        lista->tamanho++;
    }
}

Livro cadastrarLivro(){

    Livro novoLivro;

    printf("\n1. Qual o codigo do livro? \n");
    scanf("%d%*c", &novoLivro.codigo);

    printf("\n2. Qual o titulo do livro? \n");
    fgets(novoLivro.titulo, 30, stdin);

    printf("\n3. Quem e o autor do livro? \n");
    fgets(novoLivro.autor, 20, stdin);

    printf("\n4. Qual o preco do livro? \n");
    scanf("%f%*c", &novoLivro.preco);

    novoLivro.proximo = NULL;

    printf("\nCadastro realizado com sucesso!\n");
    printf("-----------------------------------\n");

    return novoLivro;
}

void exibirLista(Lista *lista){

    Livro *auxiliar = (Livro*) malloc(sizeof(Livro));
    auxiliar = lista->primeiro;

    if(estaVazia(lista)){
        printf("\nExibir Lista: Lista vazia!\n");
    }
    else{
        while(auxiliar){
            printf("\nCodigo do Livro: %d\n", auxiliar->codigo);
            printf("\nTitulo do Livro: %s", auxiliar->titulo);
            printf("\nAutor do Livro: %s", auxiliar->autor);
            printf("\nPreco do Livro: R$ %.2f", auxiliar->preco);
            printf("\n-------------------------------------");
            auxiliar = auxiliar->proximo;
        }
    }
}

void removerNoInicio(Lista *lista){

    if(estaVazia(lista)){
        printf("lista vazia.\n");
    }
    else{
        Livro *auxiliar = (Livro*) malloc(sizeof(Livro));
        if(!auxiliar){
            printf("\nRemover no Inicio: Erro ao alocar auxiliar");
            exit(1);
        }
        auxiliar = lista->primeiro->proximo;

        free(lista->primeiro);
        lista->primeiro = auxiliar;
        lista->tamanho--;
    }
}

void removerNoFinal(Lista *lista){

    if(estaVazia(lista)){
        printf("lista vazia.\n");
    }
    else{
        Livro *auxAnterior = NULL, *auxiliar = (Livro*) malloc(sizeof(Livro));
        if(!auxiliar){
            printf("\nRemover no Final: Erro ao alocar auxiliar");
            exit(1);
        }

        auxiliar = lista->primeiro;
        
        while(auxiliar->proximo){
            auxAnterior = auxiliar;
            auxiliar = auxiliar->proximo;
        }
        free(auxiliar);
        auxAnterior->proximo = NULL;
        lista->tamanho--;
    }
}

void removerElemento(Lista *lista){

    int flag = 0;
    Livro *atual, *anterior = NULL;
    atual = (Livro*) malloc(sizeof(Livro));

    atual = lista->primeiro;

    if(!atual && !anterior){
        printf("\nRemover Elemento: Erro alocar memoria!");
        exit(1);
    }

    if(estaVazia(lista)){
        printf("\nRemover Elemento: Lista vazia!\n");
    }
    else{
        int codigo;
        printf("\nDigite o codigo do elemento a ser removido: ");
        scanf("%d", &codigo);

        while(atual != NULL && atual->codigo != codigo){
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual == lista->primeiro){
            removerNoInicio(lista);
            flag = 1;
        }
        else if(atual != NULL){
            anterior->proximo = atual->proximo;
            free(atual);
            flag = 1;
        }

        if(flag == 0){
            printf("\nRemover Elemento: Livro nao encontrado.");
        }
    }

}

int estaVazia(Lista *list){
    if(list->tamanho == 0)
        return 1;
    else
        return 0;
}

void carregarDados(Lista *listaDeLivros){

    FILE *arquivoDados;
    Livro livro;

    arquivoDados= fopen("livros.txt", "r");
    
    if(!arquivoDados){
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }

    while(feof(arquivoDados) == 0){
        fscanf(arquivoDados, "%d\n", &livro.codigo);

        fgets(livro.titulo, 30, arquivoDados);
        //puts(livro.titulo);

        fgets(livro.autor, 20, arquivoDados);
        //puts(livro.autor);

        fscanf(arquivoDados, "%f\n", &livro.preco);
        //printf("\n-------------------------\n");

        adicionarElemento(listaDeLivros, livro);
    }

    printf("\nDados carregados. Pressione qualquer tecla para continuar...");
    getchar();
    fclose(arquivoDados);   
}