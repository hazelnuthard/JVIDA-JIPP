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
	int d;
	
	printf(" Digite o tamanho do mundo (minimo 10 e maximo 60): ");
	scanf("%d", &d);
	return d;
}

int menu_geral()
{
	int op;
	
	do
	{
		system("cls");
		printf("      Projeto JOGO DA VIDA      \n");
		printf(" ==================================\n");
		printf(" 1-Apresentar o Mundo\n");
		printf(" 2-Incluir/Excluir celulas vivas\n");
		printf(" 3-Mostrar/Ocultar celulas vizinhas\n");
		printf(" 4-Limpar totalmente o mapa\n");
		printf(" 5-Sair\n");
		printf(" ==================================\n");
		printf(" Resp: ");
		scanf("%d", &op);
		
		if(op < 0 || op > 5)
		{
			printf(" Opcao invalida!\n");
			system("pause");
		}
		else
		{
			return op;
		}
	}
	while(1);
}

void apresenta_mundo(char m[60][60], int dim, char celv)
{	
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

int coord_x()
{ 
	int l;

	printf(" Digite a linha desejada (-1 para sair): ");
	scanf("%d", &l);
	
	return l;
}

int coord_y()
{
	int c;

	printf(" Digite a coluna desejada (-1 para sair): ");
	scanf("%d", &c);
	
	return c;
}

char exclui(int li, int col)
{
	char r;

	printf(" Ja ha uma celula na posicao (%d,%d)\n", li, col);
	printf(" Deseja exclui-la? (S/N) ");
	scanf(" %c", &r);
	r = toupper(r);
	
	if(r != 'S' && r != 'N')
	{
		printf(" Opcao invalida!\n");
		system("pause");
	}
	
	return r;
}

void limpatela()
{
	printf(" ");
	system("pause");
	system("cls");
}

void titulo(int op)
{
	system("cls");
	switch(op)
	{
		case 1:
			printf(" APRESENTACAO DO MUNDO\n");
			break;
		case 2:
			printf(" INCLUIR/EXCLUIR CELULAS\n");
			break;
		case 3:
			printf(" MOSTRAR/OCULTAR CELULAS\n");
			break;
		case 4:
			printf(" LIMPAR O MAPA\n");
			break;
	}
}

void apresenta_mensagem(char m[100])
{
	printf("%s\n", m);
}

char menu_limpa()
{
	char r;
	
	printf(" Deseja realmente limpar todas as celulas do mapa? (S/N) ");
	scanf(" %c", &r);
	r = toupper(r);
	return r;
}

char cel_viz(char cel)
{
	char r, c;
	
	c = cel;
	
	if(cel == 'N')
	{
		printf(" Deseja mostrar as celulas vizinhas mortas? (S/N) ");
		scanf(" %c", &r);
		r = toupper(r);
		
		if(r == 'S')
		{
			cel = 'S';
		}
	}
	else if(cel == 'S')
	{
		printf(" Deseja ocultar as celulas vizinhas mortas? (S/N) ");
		scanf(" %c", &r);
		r = toupper(r);
		
		if(r == 'S')
		{
			cel = 'N';
		}
	}
	return cel;
}
