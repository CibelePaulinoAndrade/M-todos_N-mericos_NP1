#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<locale.h>

void conversao(){
	
}

void sistema_linear(){
	
}

void equacao_algebrica(){
	
}

void chamar_menu(){
	//Fun��o chama o meu da aplica��o, solicita a op��o desejada, ler a op��o escolhida pelo usu�rio e 
	//direciona para a op��o desejada atrav�s do switch case.
	char menu ;
	
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	printf("Menu Principal\n");
	printf("C - Convers�o\nS - Sistema Linear\nE - Equa��o Alg�brica\nF - Finalizar\n");
	scanf ("%2c", &menu);
	
	while(menu != 'C' && menu != 'S' && menu != 'E' && menu != 'F'){
		printf("Alternativa inv�lida, tente novamente:\n");
		scanf ("%2c", &menu);
	}
	switch (menu){
		case 'C':
			conversao();
			break;
		case 'S':
			sistema_linear();
			break;
		case 'E':
			equacao_algebrica();
			break;
		case 'F': 
			printf("At� logo\n");
			break;
	}
}
int main (){
	
	chamar_menu();
	
	return 0; 
}
