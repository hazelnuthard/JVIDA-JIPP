/*JVIDA-JIPP_View.cpp 
10/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_View.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int dimensao()
{
	do
	{
		int d;
		printf(" Digite o tamanho do mundo (minimo 10 e maximo 60): ");
		scanf("%d", &d);
		
		if(d < 10 || d > 60)
		{
			resp_invalida();
		}
		else
		{
			system("cls");
			return d;
		}
	}
	while(1);
}

int menu_geral()
{
	do
	{
		int op;
		
		printf("      Projeto JOGO DA VIDA      \n");
		printf(" ===============================\n");
		printf(" 1-Apresentar o Mundo\n");
		printf(" 2-Incluir/Excluir celulas vivas\n");
		printf(" 3-Sair\n");
		printf(" ===============================\n");
		printf(" Resp: ");
		scanf("%d", &op);
		
		if(op < 0 || op > 3)
		{
			resp_invalida();
		}
		else
		{
			system("cls");
			return op;
		}
	}
	while(1);
}

void apresenta_mundo(char m[60][60], int dim)
{
	system("cls");
	printf(" ================================");
	for(int k = 0; k < (dim-10); k++)
	{
		printf("===");
	}
	printf("\n");
	printf("   ");
	for(int a = 0; a < dim; a++)
	{
		printf("%3d", a);
	}
	printf("\n");
	for(int i = 0; i < dim; i++)
	{
		printf("%3d", i);
		for(int j = 0; j < dim; j++)
		{
			printf("%3c", m[i][j]);
		}
		printf("\n");
	}
	printf(" ================================");
	for(int k = 0; k < (dim-10); k++)
	{
		printf("===");
	}
	printf("\n\n");
}

void resp_invalida()
{
	system("cls");
	printf(" RESPOSTA INVALIDA\n");
	system("pause");
	system("cls");
}

int coord_x()
{ 
	do
	{
		int l;
	
		printf(" Digite a linha desejada: ");
		scanf("%d", &l);
		
		return l;
	}
	while(1);
}

int coord_y()
{
	do
	{
		int c;
	
		printf(" Digite a coluna desejada: ");
		scanf("%d", &c);
		
		return c;
	}
	while(1);
}

char exclui(int li, int col)
{
	char r;
	
	do
	{
		printf(" Ja ha uma celula na posicao (%d,%d)\n", li, col);
		printf(" Deseja exclui-la? (S/N) ");
		scanf(" %c", &r);
		r = toupper(r);
		
		return r;
	}
	while(1);
}

void limpatela()
{
	printf(" ");
	system("pause");
	system("cls");
}
