#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<locale.h>

void conversao(){
	printf("Convers�o\n");
	esperar_comando();
	chamar_menu();
}

void sistema_linear(){
	
	printf("Sistema Linear\n");
	esperar_comando();
	chamar_menu();
	
}

void equacao_algebrica(){
	printf("Equa��o Algebrica\n");
	esperar_comando();
	chamar_menu();
}
void esperar_comando(){
	char entradaChr;
	printf("Digite qualquer letra para continuar:\n");
	scanf(" %c", &entradaChr);
}
void chamar_menu(){
	//Fun��o chama o menu da aplica��o, solicita a op��o desejada, ler a op��o escolhida pelo usu�rio e 
	//direciona para essa op��o atrav�s do switch case.
	char entradaChr;
	
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	printf("Menu Principal\n");
	printf("C - Convers�o\nS - Sistema Linear\nE - Equa��o Alg�brica\nF - Finalizar\n");
	scanf (" %c", &entradaChr);                                                               

	switch (entradaChr){
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
		default:
			printf("Alternativa inv�lida.");
			esperar_comando();
			chamar_menu();
	}
}
int main (){
	
	chamar_menu();
	
	return 0; 
}
