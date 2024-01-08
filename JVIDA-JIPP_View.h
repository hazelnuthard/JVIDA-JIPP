/*JVIDA-JIPP_View.h 
29/11/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

int dimensao();  //recebe a dimensao do mundo digitada pelo usuario
int menu_geral();  //apresenta o menu de opcoes das acoes do jogo
int coord_x();  //recebe a linha de onde o usuario deseja inserir a celula
int coord_y();  //recebe a coluna de onde o usuario deseja inserir a celula
int geracoes();
int passo();
char exclui(int, int);  //confirma se o usuario deseja excluir a celula
char menu_limpa();
char menu_cel_viz(char cel);
char muenuGeracoes();
void apresenta_mundo(char, int, char);  //apresenta a matriz do mundo
void limpatela();  //organiza melhor o codigo removendo acoes anteriores da tela
void titulo(int);
void apresenta_mensagem(char);
void controla_passo(int);
