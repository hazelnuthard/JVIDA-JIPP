/*JVIDA-JIPP_Controller.cpp 
25/10/2023
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
				apresenta_mundo(mundo, dime, celviz, ger);
				limpatela();
				break;
			case 2:
				insere_cel();
				break;
			case 3:
				simulacao();
				break;
			case 4:
				cel_vizinhas();
				break;
			case 5:
				limpa_mapa();
				break;
		}
	}
	while(resp != 6);
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
			apresenta_mundo(mundo, dime, celviz, ger);
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
				apresenta_mundo(mundo, dime, celviz, ger);
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
				apresenta_mundo(mundo, dime, celviz, ger);
				ex = exclui(l,c);
				
				if(ex == 'S')
				{
					mundo[l][c] = '.';
					atualizar_viz();
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
	
	titulo(5);
	apresenta_mundo(mundo, dime, celviz, ger);
	r = menu_limpa();
	
	if(r == 'S')
	{
		ger = 1;
		cria_mundo(dime);
		titulo(5);
		apresenta_mundo(mundo, dime, celviz, ger);
		apresenta_mensagem(" Mundo reiniciado com sucesso!\n");
		limpatela();
	}
}

void cel_vizinhas()
{
	char i = celviz;
	
	titulo(4);
	apresenta_mundo(mundo, dime, celviz, ger);
	celviz = menu_cel_viz(celviz);
	
	if(i != celviz)
	{
	titulo(4);
	apresenta_mundo(mundo, dime, celviz, ger);
	apresenta_mensagem(" Configuracao alterada com sucesso!\n");
	limpatela();
	}
}

void simulacao()
{
	int p, k, qtviz;
	
	titulo(3);
	ger = geracoes();
	k = 1;
	p = passo();
	
	while(k <= ger)
	{
		apresenta_mundo(mundo, dime, celviz, k);
		limpa_aux();
		for(int l = 0; l < dime; l++)
		{
			for(int c = 0; c < dime; c++)
			{	
				if(mundo[l][c] == '+')
				{
					qtviz = conta_vizinhos(l, c);
					
					if(qtviz == 3)
					{
						aux[l][c] = 'O';
					}
				}
				else if(mundo[l][c] == 'O')
				{
					qtviz = conta_vizinhos(l, c);
					
					if(qtviz < 2 || qtviz > 3)
					{
						aux[l][c] = '.';
					}
					else
					{
						aux[l][c] = 'O';
					}
				}
			}
		}
		for(int i = 0; i < dime; i++)
		{
			for(int j = 0; j < dime; j++)
			{
				mundo[i][j] = aux[i][j];
			}
		}
		atualizar_viz();
		controla_passo(p);
		k++;
	}
	apresenta_mensagem(" Fim da simulacao\n");
	limpatela();
}

void atualizar_viz()
{
	for(int i = 0 ; i < dime ; i++) 
	{
        for(int j = 0; j < dime; j++)
		{
        	if(mundo[i][j] != 'O')
        	{
        		if(mundo[i-1][j-1] == 'O')
        				mundo[i][j] = '+';
            	else if (mundo[i-1][j] == 'O')
            		mundo[i][j] = '+';
            	else if (mundo[i-1][j+1] == 'O')
            		mundo[i][j] = '+';
            	
            	else if (mundo[i][j-1] == 'O')
            		mundo[i][j] = '+';
            	else if (mundo[i][j+1] == 'O')
            		mundo[i][j] = '+';
            	
            	else if (mundo[i+1][j-1] == 'O')
            		mundo[i][j] = '+';
            	else if (mundo[i+1][j] == 'O')
            		mundo[i][j] = '+';
            	else if (mundo[i+1][j+1] == 'O')
            		mundo[i][j] = '+';
            		
            	else
            		mundo[i][j] = '.';
			}
    	}
	}
}

int conta_vizinhos(int l, int c)
{
	int il = -1, fl = 1, ic = -1, fc = 1, k;
	int qtviz = 0;

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
			if(mundo[l+il][c+k] == 'O')
			{
				qtviz++;
			}
		}
	}
	if(mundo[l][c] == 'O')
	{
		qtviz--;
	}
	return qtviz;
}

void limpa_aux()
{
	for(int i = 0; i < dime; i++)
	{
		for(int j = 0; j < dime; j++)
		{
			aux[i][j] = '.';
		}
	}
}
