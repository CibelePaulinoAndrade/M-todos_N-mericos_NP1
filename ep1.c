#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
//1� Exerc�cio-programa de M�todos Num�ricos
//Prof. Glauber Cintra
//Equipe: Cibele Paulino, Narc�lio Lima, Gabriel, Raimundo.

//Come�a t�pico 1 - Convers�o
void conversao(){
	printf("Convers�o\n");
	esperar_comando();
	chamar_menu();
}
//Termina t�pico 1 - Convers�o

//Come�a t�pico 2 - Sistema Linear 
//FALTA COLOCAR O LANCE DAS LINHAS E COLUNAS (ATEN��O!!!!)
double gauss_seidel(int indice, int *multiplicadores, double *valores, int tamVal ){
	//Fun��o que recebe o indice (variav�l) a ser calculado(da), o endere�o de um vetor com os valores de vetor[i], o endere�o de um vetor 
	//com os valores atuais das variav�is e um inteiro com o n�mero de variav�is. Calcula o valor das variav�is utilizando o m�todo interativo 
	//para resolu��o de sistemas de equa��es lineares de Gauss-Seidel. Retorna o valor obtido.
	int i;
	double result;
	result = 0.0;
	for (i=0; i<tamVal; i++ ){
		if (indice != i){
			result = result - multiplicadores [i]*valores [i];
		}
	}
	result+=multiplicadores[i];
	result/=multiplicadores[indice];
	return result;
}

int controle_parada_sistema(int val, double *estAtual, double *estAnterior, int interacoes){
	//Fun��o que recebe um inteiro referente ao n�mero de variav�is do sistema, o endere�o de um vetor com os valores atuais das variav�is,
	//o endere�o de um vetor com os valores anteriores das variav�is e um inteiro com o n�mero de intera��es que j� foram executadas. Verifica se
	//a varia��o no valor das variav�is � menor que 10^(-8) ou se 1000 intera��es j� foram executas. Retorna 1 (um) caso as uma das condi��es 
	//anteriores seja satisfeita e, 0 (zero), caso contr�rio.
	int i;
	int controle = 0;
	for(i=0;i<val;i++){
			if((estAtual[i]-estAnterior[i])< 0.00000001){
				controle++;
			}
		}
		if(controle==val || interacoes == 1000 ){
			return 1;
		}
		else{
			return 0;
		}
}

void imprime_resultado_sistema(double *estAtual ,int interacoes, int val){
	//Fun��o que recebe o endere�o de um vetor com os valores atuais das variav�is, um inteiro com o n�mero de intera��es que foram 
	//executadas e um inteiro referente ao n�mero de variav�is do sistema. Imprime na tela os valores obtidos para cada variav�l e o
	//n�mero de intera��es realizadas.
	int i;
	system("cls");
	printf("Resultado:\n");
	for (i=0;i<val;i++){
		printf("X%d: %.4Le\n", i+1, estAtual[i]);
	}
	printf("\n%d iteracoes realizadas\n\n", interacoes);
}
void sistema_linear(){
	//Fun��o que l� um arquivo de texto contendo um sistema linear de n equa��es e n variav�is. Aloca os valores nas variav�is adequadas.
	//Chama a fun��o para calcular o valor das v�riav�is do sistema e a fun��o para imprimir os valores obtidos na tela.
	FILE *arq;
	char arquivo[20];
	int interacoes = 0;
	int aux;
	int val;
	int i;
	int j;
	
	printf("Digite o nome do arquivo desejado: \n");
	scanf("%s", &arquivo);
	arq = fopen(arquivo, "r");
	
	fscanf(arq, " %d", &val);
	int vetor [val][val+1];
	
	for ( i = 0; i<val; i++){
		for ( j = 0; j<val+1; j++){
			fscanf(arq, " %d", &aux);
			vetor[i][j] = aux;
		}
	}
	
	double estAtual[val];
	double estAnterior [val];
	
	for (i=0; i<val; i++){
		estAtual[i]=0.0;
		estAnterior[i]=0.0;
	}
	
	while(1){
		double resultado;
		interacoes++;
		for (i=0;i<val;i++){
			resultado = gauss_seidel(i, vetor[i], estAtual, val);
			estAnterior[i] = estAtual[i];
			estAtual[i]= resultado;
		}
		if ((controle_parada_sistema(val, estAtual, estAnterior, interacoes)) == 1){
			break;
		}
	}
	
	imprime_resultado_sistema(estAtual, interacoes, val);
	
	esperar_comando();
	chamar_menu();
	
}
//Termina t�pico 2 - Sistemas Lineares

//Come�a t�pico 3 - Equa��o alg�brica
void equacao_algebrica(){
	printf("Equa��o Algebrica\n");
	
	esperar_comando();
	chamar_menu();
}
//Termina t�pico 3 - Equa��o alg�brica

void esperar_comando(){
	char entradaChr;
	printf("Digite qualquer letra para voltar ao menu inicial:\n");
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
