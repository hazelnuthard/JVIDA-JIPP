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
				apresenta_mundo(mundo, dime, celviz);
				limpatela();
				break;
			case 2:
				insere_cel();
				break;
			case 3:
				cel_vizinhas();
				break;
			case 4:
				limpa_mapa();
				break;
		}
	}
	while(resp != 5);
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
	char ex;
	
	do
	{
		do
		{
			titulo(2);
			apresenta_mundo(mundo, dime, celviz);
			l = coord_x();
			
			if(l < -1 || l >= dime)
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
		
		if(l == -1)
		{
			break;
		}
		
		do
		{
			c = coord_y();
			
			if(c < -1 || c >= dime)
			{
				apresenta_mensagem(" Coluna invalida!\n");
				limpatela();
				titulo(2);
				apresenta_mundo(mundo, dime, celviz);
			}
			else
			{
				break;
			}
		}
		while(1);
		
		if(c == -1)
		{
			break;
		}
		
		if(mundo[l][c] == 'O')
		{
			do
			{
				titulo(2);
				apresenta_mundo(mundo, dime, celviz);
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
			
			int il = -1, fl = 1, ic = -1, fc = 1, k;
			
			if(l == 0)
			{
				il = 0;
			}
			else if(l == dime-1)
			{
				fl = 0;
			}
			
			if(c == 0)
			{
				ic = 0;
			}
			else if(c == dime-1)
			{
				fc = 0;
			}

			for(il; il <= fl; il++)
			{
				for(k = ic; k <= fc; k++)
				{
					if(mundo[l+il][c+k] == '.')
					{
						mundo[l+il][c+k] = '+';
					}
				}
			}
		}
	}
	while(1);
}

void limpa_mapa()
{
	char r;
	
	titulo(3);
	apresenta_mundo(mundo, dime, celviz);
	r = menu_limpa();
	
	if(r == 'S')
	{
		cria_mundo(dime);
		titulo(3);
		apresenta_mundo(mundo, dime, celviz);
		apresenta_mensagem(" Mundo reiniciado com sucesso!\n");
		limpatela();
	}
}

void cel_vizinhas()
{
	char i = celviz;
	
	titulo(3);
	apresenta_mundo(mundo, dime, celviz);
	celviz = menu_cel_viz(celviz);
	
	if(i != celviz)
	{
	titulo(3);
	apresenta_mundo(mundo, dime, celviz);
	apresenta_mensagem(" Configuracao alterada com sucesso!\n");
	limpatela();
	}
}
