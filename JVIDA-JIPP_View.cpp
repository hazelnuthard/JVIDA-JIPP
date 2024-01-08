/*JVIDA-JIPP_View.cpp 
29/11/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_View.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>

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
		printf(" 3-Iniciar o processo\n");
		printf(" 4-Mostrar/Ocultar celulas vizinhas\n");
		printf(" 5-Limpar totalmente o mapa\n");
		printf(" 6-Gravar uma geracao inicial\n");
		printf(" 7-Recuperar uma geracao cadastrada\n");
		printf(" 8-Excluir o deposito de geracoes iniciais\n");
		printf(" 9-Regras\n");
		printf(" 10-Sair\n");
		printf(" ==================================\n");
		printf(" Resp: ");
		scanf("%d", &op);
		
		if(op < 0 || op > 10)
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

void apresenta_mundo(char m[60][60], int dim, char celv, int g)
{	
	int vivas = 0;
	int mv = 0;
	
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
			if(m[i][j] == '+')
			{
				mv++;
				
				if(celv == 'N')
				{
					printf("%3c", '.');
				}
				else
				{
					printf("%3c", m[i][j]);
				}
			}
			else
			{
				printf("%3c", m[i][j]);
			}
			if(m[i][j] == 'O')
			{
				vivas++;
			}
		}
		printf("\n");
	}
	printf(" ================================");
	for(int k = 0; k < (dim-10); k++)
	{
		printf("===");
	}
	
	printf("\n GERACAO %d: %d Celulas vivas | Mortos-Vizinhos: %d\n\n", g, vivas, mv);
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
			printf(" SIMULACAO\n");
		case 4:
			printf(" MOSTRAR/OCULTAR CELULAS\n");
			break;
		case 5:
			printf(" LIMPAR O MAPA\n");
			break;
		case 6:
			printf(" GRAVACAO DA GERACAO\n");
			break;
		case 7:
			printf(" RECUPERACAO DE GERACAO INICIAL\n");
			break;
		case 8:
			printf(" LIMPAR GERACOES INICIAIS\n");
			break;	
		case 9:
			printf(" REGRAS DE FUNCIONAMENTO\n");
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

char menu_cel_viz(char cel)
{
	char r;

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

int geracoes()
{
	int g;
	
	printf(" Quantas geracoes voce deseja simular? ");
	scanf("%d", &g);
	return g;
}

int passo()
{
	int p;
	
	printf(" Digite a velocidade da simulacao em seg (0 para passo a passo) ");
	scanf("%d", &p);
	return p;
}

void controla_passo(int p)
{
	if(p == 0)
	{
		system("pause");
	}
	else
	{
		Sleep(p*1000);
	}
}

char menuGeracoes()
{
	char r;
	
	printf(" Deseja realmente excluir todas as geracoes iniciais cadastradas? (S/N) ");
	scanf(" %c", &r);
	r = toupper(r);
	return r;
}

void regras()
{
	titulo(9);
	printf("\n");
	printf("    Em 1970, o cientista John Conway inventou um jogo que simula o processo de\n");
    printf(" nascimento, sobrevivencia, e morte. O jogo da vida e um automato celular e foi criado de modo\n");
    printf(" a reproduzir, atraves de regras simples, as alteracoes e mudancas em grupos de seres vivos, tendo\n");
    printf(" aplicacoes em diversas areas da ciencia.\n");
    printf("    A ideia base e que um ser vivo necessita de outros seres vivos para sobreviver e procriar, mas\n");
    printf(" um excesso de densidade populacional provoca a morte do ser vivo devido a escassez de comida.\n");
    printf(" Os individuos vivem num mundo matricial e a geracao seguinte e gerada a partir da geracao\n");
    printf(" anterior de acordo com as seguintes regras:\n\n");
    printf(" - Reproducao: Um ser vivo nasce numa celula vazia se essa celula vazia tiver exatamente\n");
    printf(" 3 seres vivos vizinhos.\n\n");
    printf(" - Sobrevivencia: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.\n\n");
    printf(" - Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre porque fica sem\n");
    printf(" comida.\n\n");
    printf(" - Morte por solidao: Um ser vivo com 0 ou 1 vizinhos morre de solidao.\n\n");
	system("pause");
}
