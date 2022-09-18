#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define N 5

void gerar_dados(int x[]);
void imp_dados(int x[]);
int somar_par(int x[]);
int somar_PR(int q, int x[]);
int Par(int num);

int main () {
  //Comando abaixo é para ter acentuação no código
  setlocale(LC_ALL,"");
  
  int soma_par;
  int vetor[N];
  gerar_dados(vetor);
  imp_dados(vetor);

  soma_par= somar_PR(N-1, vetor);
  printf("\nA soma dos pares é: %i\n",soma_par);
  return(0);
}

void imp_dados(int x[]){
	int i;
	for(i = 0; i < N; i++){
		printf("\nVetor[%i] = %i\n", i, x[i]);
	}
}

void gerar_dados(int x[]){
	int i, n;
  time_t t;
   
   n = 5;
   
   srand((unsigned) time(&t));
   for( i = 0; i < N; i++) {
      x[i]= (int)rand() % 10;
   }
}

int somar_par(int x[]){
	int i, soma = 0;
	for(i = 0; i < N; i++){
    if(x[i] % 2 == 0){
     		soma = soma + x[i]; 
    }
	}
	return soma;
}

int Par(int num){
  if(num % 2 == 0){
    return 1;
  }
  return 0;
}

int somar_PR(int q, int x[]){
  int r;
	if(q == 0){
		return Par(x[0])?x[0]:0;
	}
  r = Par(x[q])?x[q]:0;
	return r+somar_PR(q-1, x);
}
