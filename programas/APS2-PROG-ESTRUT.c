/* 
	APS 2 - PROGRAMAÇÃO ESTRUTURADA
	ALUNO: ARHTUR MATASSOLI DOS SANTOS NUNES
	MATRÍCULA: 2021200117
	TURMA: 931
	PROFESSOR: SÉRGIO ASSUNÇÃO MONTEIRO
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct usuario{
	
    int num;  
    char nome[50];
    char data[20];
    char cpf[20];
	char rg[20];  
    char telefone[20];
    char email[50]; 
    char endereco[30];
};

FILE *arquivo;

struct usuario C;

// Menu de opções
char menu(){
	
	setlocale ( LC_ALL, "Portuguese" );

    system("cls");
    printf("\n======================================\n");
    printf("=============== AGENDA ===============");
    printf("\n======================================\n");
    printf("\n\nEscolha uma das opções abaixo:\n");
    printf("\n");
    printf("[1] - Cadastrar contato.\n");
    printf("[2] - Procurar contato. \n");
    printf("[3] - Editar contato.\n");
    printf("[4] - Excluir contato.\n\n");
    printf("Digite a opção:");

    return (getche());
}

/*/ Pesquisa pelo telefone de inscrição
int BuscaTelefone(int n){
    fread(&C,sizeof(C),1,arquivo);

    while(!feof(arquivo)){      
        if(C.num == n){     
            fseek(arquivo,sizeof(C),SEEK_CUR);      
            return 1;       
        }       
    fread(&C,sizeof(C),1,arquivo);  
    }   
    return 0;
}
*/
// Cadastro de usuário
void cadastrarUsuario(){    
    int i;  
    arquivo = fopen("agenda.txt","a+b");

    if(arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!!!\n");
        return;
    }

    if(C.num != 1){ 
        printf("\n\nDigite o Nome: ");    
        fflush(stdin);  
        gets(C.nome); 
		printf("\nDigite a Data de nascimento: ");    
        fflush(stdin);  
        gets(C.data);
		printf("\nDigite o CPF: ");    
        fflush(stdin);  
        gets(C.cpf);
		printf("\nDigite o RG: ");    
        fflush(stdin);  
        gets(C.rg);  
        printf("\nDigite o Telefone: ");    
        fflush(stdin);  
        gets(C.telefone);
        printf("\nDigite o E-mail: ");  
        fflush(stdin);  
        gets(C.email);  
        printf("\nDigite o Endereço: ");    
        fflush(stdin);  
        gets(C.endereco); 
        fwrite(&C,sizeof(C),1,arquivo); 
        getchar();
    }

    else{
        printf("\nCÓDIGO DE INSCRIÇÃO JÀ CADASTRADO!!!.\n");   
    }
    fclose(arquivo);

}

// Buscar usuário pelo telefone
void buscarUsuario(){
	char telefone[20];
    arquivo = fopen("agenda.txt","rw");

    if(arquivo == NULL){
        printf("\nERRO AO ABRIR O ARQUIVO!!!\n");
    }

    printf("\n");
    printf("\nDigite o telefone da inscrição: ");
    scanf("%d",&telefone);
    
	if(C.telefone !=0){
		 printf("\n======================================\n");
        	printf("=============== AGENDA ===============");
        	printf("\n======================================\n");
	        printf("Nome: %s\n",C.nome);
	        printf("Data de nascimento: %s\n",C.data);
	        printf("CPF: %s\n",C.cpf);
	        printf("RG: %s\n",C.rg);
	        printf("Telefone: %s\n",C.telefone);
	        printf("E-mail: %s\n",C.email);
	        printf("Endereço: %s\n",C.endereco);
	        printf("\n======================================\n");

	        getchar();
	        getchar();
    	}
    else;
        printf("\nTELEFONE DE INCRIÇÃO INVÁLIDO!!!\n");
    	fclose(arquivo);
		}


// Edição de usuário
void editarUsuario()
{
    char telefone[20];
    arquivo = fopen("agenda.txt","rw");
    if(arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!!!\n");
    }
    printf("\n");
    printf("\nDigite o telefone da inscrição: ");
    scanf("%d",&telefone);

    //Busca Telefone

    if(telefone == NULL or 0)
        printf("\nTELEFONE INCORRETO!!!\n");
    else
        arquivo = fopen("agenda.txt","wb");

    if(arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!!!\n");
        return;
    }
	
    printf("\n\nDigite o telefone da inscrição: ");
    scanf("%d",&C.num);

        printf("\nDigite o Nome: ");
        fflush(stdin);
        gets(C.nome);
        printf("\nDigite a Data de nascimento: ");
        fflush(stdin);
        gets(C.data);
        printf("\nDigite o CPF: ");
        fflush(stdin);
        gets(C.cpf);
        printf("\nDigite o RG: ");
        fflush(stdin);
        gets(C.rg);
        printf("\nDigite o Telefone: ");
        fflush(stdin);
        gets(C.telefone);
        printf("\nDigite o E-mail: ");
        fflush(stdin);
        gets(C.email);
        printf("\nDigite o Endereço: ");
        fflush(stdin);
        gets(C.endereco);
        printf("\nALTERAÇÃO REALIZADA COM SUCESSO!!!");
        fwrite(&C,sizeof(C),1,arquivo);
        getchar();
    
}

// Apagar usuário
void apagarUsuario()
{
    FILE* arquivo = fopen("agenda.txt", "rw");
    FILE* novoArquivo = fopen("temp.txt", "w");
    char telefone[20];

    printf("\nDigite o telefone do usuário a ser excluido: ");
    scanf("%s", telefone);
    
	while(!feof(arquivo)){
        fread(&C, sizeof(C), 1, arquivo);
        if(strcmp(telefone, C.telefone)){
            fwrite(&C, sizeof(C), 1, novoArquivo);
        }
    }
    fclose(novoArquivo);
    fclose(arquivo);
    remove("agenda.txt");
    rename("temp.txt", "agenda.txt");
}

// Função principal
main(){
    char op;
    while(op!='6'){
        op = menu();
        switch(op){
            case '1':cadastrarUsuario();
            break;

            case '2':buscarUsuario();
            break;

            case '3':editarUsuario();
            break;

            case '4':apagarUsuario();
            break;
            
        }
        printf("\n");
        system("pause");
    }

}
