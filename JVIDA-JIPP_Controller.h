/*JVIDA-JIPP_Controller.h 
29/11/2023
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
int conta_vizinhos(int, int);

void carregaVivo(int, int);
void carregaVivoProx(int, int);
int VerifMorto(int, int);
void carregaMorto(int, int);
void carregaMortosViz();
void atualizaViz();
void iniciaListas();
void copiaVivo();
void gravaCelulas();
void carregaConfig();
void recuperaCelulas();
void limpaGer();
void deletaConfig();

