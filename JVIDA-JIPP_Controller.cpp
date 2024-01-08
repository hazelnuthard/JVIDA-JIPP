/*JVIDA-JIPP_Controller.cpp 
29/11/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_View.cpp"
#include "JVIDA-JIPP_Controller.h"
#include "JVIDA-JIPP_Model.cpp"
#include <time.h>

void liberaLista(TipoCel* aux, int);
void mostraLista(TipoCel* aux);

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
			case 6:
				gravaCelulas();
				break;
			case 7:
				recuperaCelulas();
				break;
			case 8:
				limpaGer();
				break;
			case 9:
				regras();
				break;
		}
	}
	while(resp != 10);
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
	
	iniciaListas();
	
	for(int l = 0; l < dime; l++)
	{
		for(int c = 0; c < dime; c++)
		{	
			if(mundo[l][c] == 'O')
			{
				carregaVivo(l, c);
			}
		}
	}
	
	carregaMortosViz();
	while(k <= ger)
	{
		apresenta_mundo(mundo, dime, celviz, k);
		mostraLista(pvivo);
		mostraLista(pmorto);
		k++;
		
		if(k > ger)
		{
			ger = 1;
			break;
		}
		
		atualizaViz();
		liberaLista(pvivo, totvivo);
		liberaLista(pmorto, totmorto);
		totvivo = totmorto = 0;
		cria_mundo(dime);
		copiaVivo();
		carregaMortosViz();
		controla_passo(p);
	}
	apresenta_mensagem(" Fim da simulacao\n");
	limpatela();
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

void carregaVivo(int ii, int jj)
{
	TipoCel* aux = (TipoCel*) malloc(sizeof(TipoCel));
	
	if(aux == NULL)
	{
		apresenta_mensagem("Sem espaco na memoria para inclusao de celula viva\n");
		return;
	}
	aux->lin = ii;
	aux->col = jj;
	mundo[ii][jj] = VIVO;
	
	if(totvivo == 0)
	{
		pvivo = aux;
		pvivo->next = NULL;
	}
	else
	{
		aux->next = pvivo;
		pvivo = aux;
	}
	totvivo++;
}

void liberaLista(TipoCel* aux, int tot)
{
	if(aux == NULL || tot == 0)
	{
		return;
	}
	TipoCel* aux2;
	
	do
	{
		aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
	while(aux != NULL);
}

void iniciaListas()
{
	liberaLista(pvivo, totvivo);
	liberaLista(pmorto, totmorto);
	liberaLista(pvivoprox, totvivoprox);
	
	pvivo = pmorto = pvivoprox = NULL;
	totvivo = totmorto = totvivoprox = 	0;
}

void carregaVivoProx(int ii, int jj)
{
	TipoCel* aux = (TipoCel*) malloc(sizeof(TipoCel));
	
	if(aux == NULL)
	{
		apresenta_mensagem(" Sem espaco na memoria para inclusao de celula viva para a proxima geracao\n");
		return;
	}
	
	aux->lin = ii;
	aux->col = jj;
	
	if(totvivoprox == 0)
	{
		pvivoprox = aux;
		pvivoprox->next = NULL;
	}
	else
	{
		aux->next = pvivoprox;
		pvivoprox = aux;
	}
	totvivoprox++;
}

int VerifMorto(int ii, int jj)
{
	TipoCel* aux;
	aux = pmorto;
	
	if(totmorto == 0)
	{
		return FALSE;
	}
	
	do
	{
		if(aux->lin == ii && aux->col == jj)
		{
			return TRUE;
		}
		aux = aux->next;
	}
	while(aux != NULL);
	return FALSE;
}

void carregaMorto(int ii, int jj)
{
	if((ii < 0) || (jj < 0))
	{
		return;
	}
	if((ii >= dime) || (jj >= dime))
	{
		return;
	}
	if(mundo[ii][jj] == VIVO)
	{
		return;
	}
	
	if(VerifMorto(ii, jj) == TRUE)
	{
		return;
	}
	
	TipoCel* aux = (TipoCel*) malloc(sizeof(TipoCel));
	if(aux == NULL)
	{
		apresenta_mensagem("Sem espaco na memoria para inclusao de celula morta-vizinha\n");
		return;
	}
	aux->lin = ii;
	aux->col = jj;
	mundo[ii][jj] = VIZINHO;
	if(totmorto == 0)
	{
		pmorto = aux;
		pmorto->next = NULL;
	}
	else
	{
		aux->next = pmorto;
		pmorto = aux;
	}
	totmorto++;
}

void carregaMortosViz()
{
	int k, i, ii, jj;
	
	struct
	{
		int li, co;
	} a, b, c, d, e, f, g, h;
	
	totmorto = 0;
	
	TipoCel* aux;
	aux = pvivo;
	
	if(totvivo == 0)
	{
		return;
	}
	
	do
	{
		ii = aux->lin;
		jj = aux->col;
		
		a.li = ii-1; a.co = jj-1;
		b.li = ii-1; b.co = jj;
		c.li = ii-1; c.co = jj+1;
		d.li = ii;   d.co = jj-1;
		e.li = ii;   e.co = jj+1;
		f.li = ii+1; f.co = jj-1;
		g.li = ii+1; g.co = jj;
		h.li = ii+1; h.co = jj+1;
		
		carregaMorto(a.li, a.co);
		carregaMorto(b.li, b.co);
		carregaMorto(c.li, c.co);
		carregaMorto(d.li, d.co);
		carregaMorto(e.li, e.co);
		carregaMorto(f.li, f.co);
		carregaMorto(g.li, g.co);
		carregaMorto(h.li, h.co);
		
		if(aux->next == NULL)
		{
			break;
		}
		
		aux = aux->next;
	}
	while(TRUE);
}

void atualizaViz()
{
	int i, j, ii, jj, vii, vjj, ct;
	
	liberaLista(pvivoprox, totvivoprox);
	pvivoprox = NULL;
	
	if(pvivo == NULL)
	{
		return;
	}
	
	TipoCel *aux, *aux2;
	aux = pvivo;
	
	do
	{
		ct = 0;
		ii = aux->lin;
		jj = aux->col;
		aux2 = pvivo;
		do
		{
			vii = aux2->lin;
			vjj = aux2->col;
			
			if(vii != ii || vjj != jj)
			{
				if(abs(ii-vii) <= 1 && abs(jj-vjj) <= 1)
				{
					ct++;
				}
			}
			aux2 = aux2->next;
		}
		while(aux2 != NULL);
		
		if(ct == 2 || ct == 3)
		{
			carregaVivoProx(ii, jj);
		}
		aux = aux->next;
	}
	while(aux != NULL);
	
	if(pmorto == NULL)
	{
		return;
	}
	
	aux = pmorto;
	
	do
	{
		ct = 0;
		ii = aux->lin;
		jj = aux->col;
		aux2 = pvivo;
		
		do
		{
			vii = aux2->lin;
			vjj = aux2->col;
			
			if(abs(ii-vii) <= 1 && abs(jj-vjj) <= 1)
			{
				ct++;
			}
			
			aux2 = aux2->next;
		}
		while(aux2 != NULL);
		
		if(ct == 3)
		{
			carregaVivoProx(ii, jj);
		}
		aux = aux->next;
	}
	while(aux != NULL);
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

void copiaVivo()
{
	TipoCel *aux; //define um ponteiro auxiliar
	aux = pvivoprox; //inicializa esse ponteiro auxiliar
	if (totvivoprox > 0)
	{
		while(aux->next != NULL)
		{
			carregaVivo(aux->lin, aux->col);
			aux = aux->next; //caminha para o próximo ponteiro
		}
		carregaVivo(aux->lin, aux->col); //mostra a ultima celula
	}
}

void gravaCelulas()
{
	titulo(6);
	int k, i, ni;
	
	k = qtconf;
	
	iniciaListas();
	
	for(int l = 0; l < dime; l++)
	{
		for(int c = 0; c < dime; c++)
		{	
			if(mundo[l][c] == 'O')
			{
				carregaVivo(l, c);
			}
		}
	}
	
	carregaMortosViz();
	
	if(totvivo == 0)
	{
		apresenta_mensagem(" Nao ha celulas para serem gravadas\n");
		limpatela();
		return;
	}
	
	TipoCel* aux;
	aux = pvivo;
	ni = 0;
	
	do
	{
		Lvivo.L[ni].lin = aux->lin;
		Lvivo.L[ni].col = aux->col;
		ni++;
		aux = aux->next;
	}
	while(aux != NULL);
	
	Lvivo.cont = totvivo;
	LConfig[k].TL = Lvivo;
	
	FILE* fp;
	if((fp = fopen("CONFIG_INIC", "w")) == NULL)
	{
		apresenta_mensagem(" ERRO: O arquivo CONFIG_INIC nao pode ser aberto para gravacao");
		limpatela();
		return;
	}
	
	for(i = 0; i <= qtconf; i++)
	{
		if(fwrite(&LConfig[i], sizeof(TipoLista), 1, fp) != 1)
		{
			apresenta_mensagem(" Erro na gravacao do arquivo CONFIG_INIC");
			limpatela();
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	qtconf++;
	apresenta_mensagem(" Configuracao gravada com sucesso!");
	limpatela();
}

void carregaConfig()
{
	int k;
	FILE* fp;
	
	if((fp = fopen("CONFIG_INIC", "r")) != NULL)
	{
		qtconf = 0;
		k = 0;
		
		while(!feof(fp))
		{
			if(fread(&LConfig[k], sizeof(TipoLista), 1, fp) != 1)
			{
				fclose(fp);
				return;
			}
			qtconf++;
			k++;
		}
		fclose(fp);
	}
}

void recuperaCelulas()
{
	titulo(7);
	
	cria_mundo(dime);
	liberaLista(pvivo, totvivo);
	pvivo = NULL;
	totvivo = 0;
	carregaConfig();
	
	int i, j, k, ni;
	
	if (qtconf == 0)
	{
		apresenta_mensagem(" Nao existe configuracao a recuperar");
		limpatela();
		return;
	}
	
	k = ultrecup + 1;
	
	if (k >= qtconf)
	{
		k = 0;
	}
	Lvivo = LConfig[k].TL;
	ultrecup = k;
	
	for(ni = 0; ni < Lvivo.cont; ni++)
	{
		carregaVivo(Lvivo.L[ni].lin, Lvivo.L[ni].col);
	}
	
	carregaMortosViz();
	apresenta_mundo(mundo, dime, celviz, ger);
	apresenta_mensagem(" Geracao carregada com sucesso!");
	limpatela();
}

void limpaGer()
{
	titulo(8);
	
	char resp;
	
	if(qtconf > 0)
	{
		resp = menuGeracoes();
		
		if(resp != 'S')
		{
			return;
		}
	}
	qtconf = 0; //nenhuma configuracao gravada
	ultrecup = -1; //ultimo �ndice recuperado
	deletaConfig();
	apresenta_mensagem(" O deposito de geracoes iniciais esta vazio\n");
	limpatela();
}


void deletaConfig()
{	
	if(remove("CONFIG_INIC") != 0)
	{
		apresenta_mensagem(" ERRO: O arquivo CONFIG_INIC nao pode ser removido");
		limpatela();
		return;
	}
	qtconf = 0;
}

void mostraLista(TipoCel* p)
{
	TipoCel* aux;
	aux = p;
	
	if (totvivo > 0)
	{
		if(p == pvivo)
		{
			apresenta_mensagem(" Celulas Vivas: ");
		}
		else
		{
			apresenta_mensagem(" Mortos-Vizinhos");
		}
		while(aux->next != NULL)
		{
			printf("(%d,%d) ", aux->lin, aux->col);
			aux = aux->next; //caminha para o próximo ponteiro
		}
		printf("(%d,%d) ", aux->lin, aux->col); //mostra a ultima celula
	}
	printf("\n\n");
}
