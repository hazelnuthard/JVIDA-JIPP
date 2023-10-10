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
	dime = dimensao();
	cria_mundo(dime);
	
	int resp;
	
	do
	{	
		resp = menu_geral();
		
		switch(resp)
		{
			case 1:
				apresenta_mundo(mundo, dime);
				limpatela();
				break;
			case 2:
				insere_cel();
				limpatela();
				break;
		}
	}
	while(resp != 3);
}

void cria_mundo(int dim)
{	
	for(int i = 0; i < dime; i++)
	{
		for(int j = 0; j < dime; j++)
		{
			mundo[i][j] = '.';	//definicao de quarto vazio
		}
	}
}

void insere_cel()
{	
	int l, c;
	char resp;
	
	do
	{
		apresenta_mundo(mundo, dime);
		l = coord_x();
		
		if(l < 0 || l >= dime)
		{
			resp_invalida();
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
			resp_invalida();
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
			apresenta_mundo(mundo, dime);
			resp = exclui(l,c);
			
			if(resp == 'S')
			{
				mundo[l][c] = '.';
				break;
			}
			else if(resp == 'N')
			{
				break;
			}
			else
			{
				resp_invalida();
			}
		}
		while(1);
	}
	else
	{
		mundo[l][c] = 'O';
	}
	apresenta_mundo(mundo, dime);
}
