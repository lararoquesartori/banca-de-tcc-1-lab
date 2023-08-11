#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcoes_aluno.h"
#include "funcoes_professor.h"
#include "funcoes_banca.h"
/*
    EQUIPE:
    Lara Roque
    Leon Araujo
    Marcus Luan
    Milena Gomes "de software"
    Fernanda Amorim
*/

void ler_arquivo(){
    ler_arquivo_aluno();
    ler_arquivo_professor();
    ler_arquivo_banca();
}

void salvar(){
    salvar_aluno();
    salvar_banca();
    salvar_professor();
}



void menu(){
int num = 0;
int opcao = 0;




while(1){
    printf("\n\n\n");
    
    printf("\nEXIBIR:\n1-aluno\t2-professor\t3-banca\n");

    printf("\nADICIONAR:\n4-aluno\t5-professor\t6-banca\n");

    printf("\nATUALIZAR:\n7-aluno\t8-professor\t9-banca\n");

    printf("\nEXCLUIR:\n10-aluno\t11-professor\t12-banca\n");

    printf("Para salvar na memoria digite 13, Para carregar o arquivo salvo 14\n");

    printf("Para fechar o programa digite 15\n");
    
    scanf("%d", &opcao);
    
    if(opcao > 15 || opcao < 1){
        printf("%s\n","Opção invalida, por favor reinicie o programa" );

        break;
    }

    switch(opcao){
        case 1:
            printf("%d", tamanho_aluno);
            exibir_todos_os_alunos();
            break;
        case 2:
            exibir_todos_os_professores();
            break;
        case 3:
            exibir_todas_as_banca();
            break;
        case 4:
            printf("digite o numero de alunos a adicionar\n");
            scanf("%d", &num);
            for (int i = 0; i < num; ++i){
                scan_aluno();
                //printf("%d", tamanho_aluno);
            }
            
            break;
        case 5:
            printf("digite o numero de profesores a adicionar\n");
            scanf("%d", &num);
            for (int i = 0; i < num; ++i){
                scan_professor();
            }
            
            break;
        case 6:
            printf("digite o numero de bancas a adicionar\n");
            scanf("%d", &num);
            for (int i = 0; i < num; ++i){
                scan_banca();
            }
            break;
        case 7:
            atualizar_aluno();
            break;
        case 8:
            atualizar_banca();
            break;
        case 9:
            atualizar_professor();
            break;
        case 10:
            printf("digite a matricula do aluno a se excluir\n");
            scanf("%d", &num);
            apagar_aluno(num);
            break;
        case 11:
            printf("digite o siape do professor a se excluir\n");
            scanf("%d", &num);
            apagar_professor(num);
            break;
        case 12:
            printf("digite o id da banca a se excluir\n");
            scanf("%d", &num);

            apagar_banca(num);
            break;
        case 13:
            printf("\n Arquivos salvos com sucesso!!!!\n");
            salvar();
            break;
        case 14:
            printf("\n Sua base de dados foi carregada com sucesso!!!!, se ela existir.\n");
            ler_arquivo();
            break;
        case 15:
            return;
        }
  
}
}
int main(){
    menu();
  return 0;
}