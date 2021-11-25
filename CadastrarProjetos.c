#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 200

struct projeto{
	int codigo, ano, status;
	char titulo[50], descricao[100], gerente[30], empresa[30], revisao[30], data[15];	
};

struct projeto proj[MAX];
int op, i=0, cont=0;
char escolha;

void mostrarMenu(){
	printf("\n******************************************************************");
	printf("\n********** MAPA - Algoritmos e Lógica de Programação II **********\n");
	printf("******************************************************************\n");
	printf("\n(1) Cadastrar um novo projeto.\n");
	printf("\n(2) Exibir todos os projetos cadastrados.\n");
	printf("\n(3) Exibir projetos com o Status: A fazer.\n");
	printf("\n(4) Exibir projetos com o Status: Fazendo.\n");
	printf("\n(5) Exibir projetos com o Status: Concluído.\n");
	printf("\n(6) Pesquisa por código.\n");
	printf("\n(7) Sair\n");
	printf("\n******************** Selecione uma opção *********************\n\n\n");	
}

void cadastraProjeto(){
	system("cls");
		printf("\n************************ CADASTRO DE PROJETOS ******************************\n");
		fflush(stdin);
		printf("\nGerente de projetos: ");
		scanf("%30[^\n]s", &proj[cont].gerente);
		fflush(stdin);
		printf("\nEmpresa: ");
		scanf("%30[^\n]s", &proj[cont].empresa);
		fflush(stdin);
		printf("\nRevisão: ");
		scanf("%30[^\n]s", &proj[cont].revisao);
		fflush(stdin);
		printf("\nPrazo de entrega do projeto (DD/MM/AAAA): ");
		scanf("%15[^\n]s", &proj[cont].data);
		fflush(stdin);
		printf("\nCrie um título para seu projeto: ");
		scanf("%50[^\n]s", &proj[cont].titulo);
		fflush(stdin);
		printf("\nFaça uma descrição para o seu projeto: ");
		scanf("%100[^\n]s", &proj[cont].descricao);
		fflush(stdin);
		printf("\nInforme o ano de criação do seu projeto: ");
		scanf("%d", &proj[cont].ano);
		fflush(stdin);
		
		printf("\n************************ Selecione o status do projeto ****************************\n");
		printf("\n(1) A fazer.\n(2) Fazendo.\n(3) Concluído.\n");
		scanf("%d", &proj[cont].status);
		while ((proj[cont].status < 1) || (proj[cont].status > 3)){
			printf("Status inválido!!!\n\nInforme um número válido:");
			scanf("%d", &proj[cont].status);
		}
				
		proj[cont].codigo = cont + 1; 
		cont = cont + 1;
		
		printf("\nProjeto com o código %d gerado com sucesso!\n", cont);
		sleep(2);
		system("cls");						
								
}

char* trocaStatus(int tipo){
	if(tipo == 1) { 
		return "A Fazer";
	}
	if(tipo == 2){
		return "Fazendo";
	}
	else{
		return "Concluido";
	}
}

void listaTodos(){
	system("cls");
	int in;
		printf("\n*********************** PROJETOS CADASTRADOS ************************\n\n");
		if (cont == 0){
		printf("\nNenhum projeto cadastrado.\n");
		sleep(2);
		system("cls");
	}
		for(in=0; in<cont; in++){
			printf("\n******************* Código do projeto: %d **************************\n\n", proj[in].codigo);
			printf("\nGerente de projetos: %s\n", proj[in].gerente);
			printf("\nEmpresa: %s\n", proj[in].empresa);
			printf("\nRevisão: %s\n", proj[in].revisao);
			printf("\nPrazo de entrega do projeto: %s\n", proj[in].data);
			printf("\nTítulo: %s\n", proj[in].titulo);
			printf("\nDescrição: %s\n", proj[in].descricao);
			printf("\nAno de criação: %d\n", proj[in].ano);
			printf("\nStatus: %s\n", trocaStatus(proj[in].status));
			printf("\n\n");
		}
}

void listaAfazer(){
	int in, contFazer = 0;
	system("cls");
	printf("***************************** STATUS: A FAZER *****************************\n");
	for(in=0; in<cont; in++) { 
		if(proj[in].status == 1 ) {
			printf("\n******************* Código do projeto: %d **************************\n\n", proj[in].codigo); 
			contFazer++;
			printf("\nGerente de projetos: %s\n", proj[in].gerente);
			printf("\nEmpresa: %s\n", proj[in].empresa);
			printf("\nRevisão: %s\n", proj[in].revisao);
			printf("\nPrazo de entrega do projeto: %s\n", proj[in].data);
			printf("\nTítulo: %s\n", proj[in].titulo);
			printf("\nDescrição: %s\n", proj[in].descricao);
			printf("\nAno de criação: %d\n", proj[in].ano);
			printf("\nStatus: %s\n", trocaStatus(proj[in].status));
			printf("\n\n");
		}
	}
	if (contFazer == 0){
		printf("Nenhum projeto cadastrado com o status - A fazer");
	}
}

void listaFazendo(){
	system("cls");
	printf("*************************** STATUS: FAZENDO ***************************\n");
	int in, contFazendo = 0;
	for(in=0; in<cont; in++) { 
		if(proj[in].status == 2 ) {
			printf("\n********************* Código do projeto: %d ****************************\n\n", proj[in].codigo); 
			contFazendo++;
			printf("\nGerente de projetos: %s\n", proj[in].gerente);
			printf("\nEmpresa: %s\n", proj[in].empresa);
			printf("\nRevisão: %s\n", proj[in].revisao);
			printf("\nPrazo de entrega do projeto: %s\n", proj[in].data);
			printf("\nTítulo: %s\n", proj[in].titulo);
			printf("\nDescrição: %s\n", proj[in].descricao);
			printf("\nAno de criação: %d\n", proj[in].ano);
			printf("\nStatus: %s\n", trocaStatus(proj[in].status));
			printf("\n\n");
		}
	}if (contFazendo == 0){
		printf("Nenhum projeto cadastrado com o status - Fazendo");
	}
}

void listaConcluido(){
	system("cls");
	printf("**************************** STATUS: CONCLUÍDO *****************************\n");
	int in, contConcluido = 0;
	for(in=0; in<cont; in++) { 
		if(proj[in].status == 3 ) {
			printf("\n********************* Código do projeto: %d ****************************\n\n", proj[in].codigo); 
			contConcluido++;
			printf("\nGerente de projetos: %s\n", proj[in].gerente);
			printf("\nEmpresa: %s\n", proj[in].empresa);
			printf("\nRevisão: %s\n", proj[in].revisao);
			printf("\nPrazo de entrega do projeto: %s\n", proj[in].data);
			printf("\nTítulo: %s\n", proj[in].titulo);
			printf("\nDescrição: %s\n", proj[in].descricao);
			printf("\nAno de criação: %d\n", proj[in].ano);
			printf("\nStatus: %s\n", trocaStatus(proj[in].status)); 
			printf("\n\n");	
		}
	}if (contConcluido == 0){
		printf("Nenhum projeto cadastrado com o status - Concluído");
	}
}

void listaCodigo(){
	system("cls");
	printf("******************************* Pesquisa por código ********************************\n\n");
	int in, cod, conti = 0;
	printf("Informe o código do projeto: ");
	fflush(stdin);
	scanf("%d", &cod);
	for(in=0; in<cont ; in++) { 
			if(proj[in].codigo == cod) {
				printf("\n******************** Código do projeto: %d ***************************\n\n", proj[in].codigo); 
				conti++;
				printf("\nGerente de projetos: %s\n", proj[in].gerente);
				printf("\nEmpresa: %s\n", proj[in].empresa);
				printf("\nRevisão: %s\n", proj[in].revisao);
				printf("\nPrazo de entrega do projeto: %s\n", proj[in].data);
				printf("\nTítulo: %s\n", proj[in].titulo);
				printf("\nDescrição: %s\n", proj[in].descricao);
				printf("\nAno de criação: %d\n", proj[in].ano);
				printf("\nStatus: %s\n", trocaStatus(proj[in].status)); 
				printf("\n\n");	
				
		}
	}if (conti == 0){
		printf("Não existe nenhum projeto cadastrado com esse código.\n\nPor favor, tente novamente ou cadastre um projeto.\n");	
	}
}

int main (){
	setlocale (LC_ALL, "Portuguese");
	int op;
	
	do{
		mostrarMenu();
		scanf("%d", &op);
			switch (op)
			{
			case 1:  
				cadastraProjeto();
				break;
			
			case 2:
				listaTodos();
				break;
			
			case 3:
				listaAfazer();
				break;
			
			case 4:
				listaFazendo();
				break;
				
			case 5:
				listaConcluido();
				break;
			
			case 6:
				listaCodigo();
				break;
						
			case 7:
				printf("Saindo do programa...");
				sleep(2);
				system ("cls");
			break;
			
			default:
				printf("Opção Inválida!!!\n\nPor favor, selecione uma opção válida...\n");
					sleep(2);
					system("cls");
				
			}
	
	}while (op !=7);
	
return(0);

}
