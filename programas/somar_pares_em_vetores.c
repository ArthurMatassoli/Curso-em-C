/* 
Programação estruturada
Aluno: Arthur matassoli
Matrícula: 2021200117
Turma:931
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#define vet 10

void ent_dados(int x []);
int par(int num);
int somar_PR(int qtd, int x[]);
void maior_num(int x);

void ent_dados(int x[]){
	int i;
	
	for(i = 0; i < vet; i++){
		x[i] = rand() % 100;
		printf("%d ", x[i]);
	}
}
int par(int num){
	if(num % 2 == 0){
		return 1;
	}
	return 0;
}
int somar_PR(int qtd, int x[]){
	int r;
	
	if(qtd == 0){
		return par(x[0])?x[0]:0;
	}
	r = par(x[qtd])?x[qtd]:0;
	return r + somar_PR(qtd - 1, x);
}

int maior;

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int v1[vet],v2[vet],v3[vet],v4[vet],v5[vet];
	int soma_par;
	int par(int num);
	
	printf("-=-=-=Gerando números inteiros aleatórios!=-=-=- \n\n");
	ent_dados(v1);
	printf("\n\n");
	ent_dados(v2);
	printf("\n\n");
	ent_dados(v3);
	printf("\n\n");
	ent_dados(v4);
	printf("\n\n");
	ent_dados(v5);
	
	printf("\n\n-=-=-=Somando os números pares de cada vetor!=-=-=-\n\n");
	soma_par = somar_PR(vet-1, v1);
	printf("\nA soma dos pares é = %i\n",soma_par);
	maior_num(soma_par);
		
	soma_par = somar_PR(vet-1, v2);
	printf("\nA soma dos pares é = %i\n",soma_par);
	maior_num(soma_par);
		
	soma_par = somar_PR(vet-1, v3);
	printf("\nA soma dos pares é = %i\n",soma_par);
	maior_num(soma_par);
	
	soma_par = somar_PR(vet-1, v4);
	printf("\nA soma dos pares é = %i\n",soma_par);
	maior_num(soma_par);

	soma_par = somar_PR(vet-1, v5);
	printf("\nA soma dos pares é = %i\n",soma_par);
	maior_num(soma_par);
	
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	
	printf("\nO maior número é: %d\n", maior);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");									
}
void maior_num( int x){
int qtd;

	if(maior < x){
	maior = x;
	}
}
