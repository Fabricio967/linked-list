#include "lista-encadeada.c"

int main(void){

    int opcao_menu, opcaoRemover;
    char criaLista;
    Lista *listaDeLivros = criar_lista();

    printf("=====================================\n");
    printf("\tCADASTRO DE LIVROS\n");
    printf("=====================================\n");

    printf("\nDeseja criar uma lista de livros? [s/n]\n");
    scanf("%c%*c", &criaLista);
    //getchar();

    if(criaLista == 's' || criaLista == 'S'){
        do{
            menu();
            scanf("%d%*c", &opcao_menu);
            //getchar();

            switch(opcao_menu){

                case 1: 
                    adicionarElemento(listaDeLivros, cadastrarLivro());
                break;

                case 2: 
                    printf("\nListando...\n");
                    exibirLista(listaDeLivros);
                    printf("\nPressione enter para voltar ao menu anterior: ");
                    getchar();
                break;

                case 3: 
                    printf("\nComo desejar remover?");
                    printf("\n[1] O primeiro elemento \n[2] O ultimo elemento");
                    printf("\n[3] Pelo codigo do livro");
                    printf("\nSua opcao: ");
                    scanf("%d", &opcaoRemover);
                    if(opcaoRemover == 1){
                        removerNoInicio(listaDeLivros);
                    }
                    else if(opcaoRemover == 2){
                        removerNoFinal(listaDeLivros);
                    }
                    else if(opcaoRemover == 3){
                        removerElemento(listaDeLivros);
                        getchar();
                    }
                    else{
                        printf("\nRemover Elementos: Opcao invalida!");
                    }
                    printf("\nPressione enter para voltar ao menu anterior: ");
                    getchar();
                    
                break;

                case 4:
                    carregarDados(listaDeLivros);
                break;
                
                case 0: 
                    printf("\nSaindo.\n");
                break;

                default:
                    printf("\nOpcao Invalida.");
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

    free(listaDeLivros);

    return 0;
}