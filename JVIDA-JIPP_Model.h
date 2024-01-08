/*JVIDA-JIPP_Model.h  
29/11/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#define FALSE 0
#define TRUE 1
#define VIVO 'O'
#define MORTO '.'
#define VIZINHO '+'

int dime;	//dimensao a ser definida pelo operador
int ger = 1;
int cel_vivas;
char mundo[60][60];	//Matriz de caracteres com dimensionamento pelo tamanho máximo que cabe na tela
char celviz = 'N';
int totvivo, totmorto, totvivoprox;
int qtconf = 0;
int ultrecup = -1;


