#include<stdio.h>
#include<locale.h>
//Implemente um progrma para identificar se um número é primo.

int main()
{
	//O comando abaixo é para adicionar acentuação ao código.
	setlocale(LC_ALL, "Portuguese");
	
	int num, i, resultado = 0;

	printf("Digite um número: ");
	scanf("%d", &num);
	
	for (i = 2; i <= num / 2; i++){
		if (num % i == 0) {
			resultado++;
			break;
		}
	}
	if (resultado == 0)
		printf("O número %d é primo!\n", num);
	else 
		printf("O número %d não é primo!\n", num);
	
	return 0;
	
}