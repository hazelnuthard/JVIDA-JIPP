/*JVIDA-JIPP_Model.cpp 
29/11/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_Model.h"

typedef struct cel
{
	int lin, col;
	struct cel* next;
} TipoCel;

TipoCel *pvivo, *pmorto, *pvivoprox;

typedef struct c
{
	int lin, col;
} Cel;

typedef struct list
{
	int cont;
	Cel L[400];
} TipoLista;

TipoLista Lvivo;

struct arquivo
{
	TipoLista TL;
} LConfig[50];

