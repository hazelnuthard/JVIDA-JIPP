/*JVIDA-JIPP_Controller.cpp 
10/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_View.cpp"
#include "JVIDA-JIPP_Controller.h"
#include "JVIDA-JIPP_Model.cpp"
#include <time.h>

void comecar()
{	
	do
	{
		dime = dimensao();
		
		if(dime < 10 || dime > 60)
		{
			apresenta_mensagem(" Tamanho invalido!\n");
			limpatela();
		}
		else
		{
			break;
		}
	}
	while(1);
	
	cria_mundo(dime);
	
	int resp;
	
	do
	{	
		resp = menu_geral();
		
		switch(resp)
		{
			case 1:
				titulo(1);
				apresenta_mundo(mundo, dime);
				limpatela();
				break;
			case 2:
				insere_cel();
				break;
			case 3:
				limpa_mapa();
				break;
		}
	}
	while(resp != 4);
}

void cria_mundo(int dim)
{	
	for(int i = 0; i < dime; i++)
	{
		for(int j = 0; j < dime; j++)
		{
			mundo[i][j] = '.';
		}
	}
}

void insere_cel()
{	
	int l, c;
	char ex, resp;
	do
	{
		do
		{
			titulo(2);
			apresenta_mundo(mundo, dime);
			l = coord_x();
			
			if(l == 60)
			{
				menu_geral();
			}
			else if(l < 0 || l >= dime)
			{
				apresenta_mensagem(" Linha invalida!\n");
				limpatela();
			}
			else
			{
				break;
			}
		}
		while(1);
		
		do
		{
			c = coord_y();
			
			if(c < 0 || c >= dime)
			{
				apresenta_mensagem(" Coluna invalida!\n");
				limpatela();
				titulo(2);
				apresenta_mundo(mundo, dime);
			}
			else
			{
				break;
			}
		}
		while(1);
		
		if(mundo[l][c] == 'O')
		{
			do
			{
				titulo(2);
				apresenta_mundo(mundo, dime);
				ex = exclui(l,c);
				
				if(ex == 'S')
				{
					mundo[l][c] = '.';
					break;
				}
				else if(ex == 'N')
				{
					break;
				}
			}
			while(1);
		}
		else
		{
			mundo[l][c] = 'O';
			
		}
		
		do
		{
			titulo(2);
			apresenta_mundo(mundo, dime);
			resp = continuar_inserindo();
		}
		while(resp != 'S' && resp != 'N');
	}
	while(resp == 'S');
}

void limpa_mapa()
{
	char r;
	
	titulo(3);
	apresenta_mundo(mundo, dime);
	r = menu_limpa();
	
	if(r == 'S')
	{
		cria_mundo(dime);
		titulo(3);
		apresenta_mundo(mundo, dime);
		apresenta_mensagem(" Mundo reiniciado com sucesso!\n");
		limpatela();
	}
}
