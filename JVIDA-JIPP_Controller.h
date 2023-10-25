/*JVIDA-JIPP_Controller.h 
25/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

void comecar();  //inicia o programa
void cria_mundo(int);  //preenche a matriz da dimensao desejada com '.'
void insere_cel();  //insere uma celula no mundo trocando '.' por 'O' ou exclui uma celula existente
void limpa_mapa();
void cel_vizinhas();
void simulacao();
void atualizar_viz();
void limpa_aux();
int conta_vizinhos(int, int);
