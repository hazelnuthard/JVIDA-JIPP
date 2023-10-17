/*JVIDA-JIPP_View.h 
10/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

int dimensao();  //recebe a dimensao do mundo digitada pelo usuario
int menu_geral();  //apresenta o menu de opcoes das acoes do jogo
int coord_x();  //recebe a linha de onde o usuario deseja inserir a celula
int coord_y();  //recebe a coluna de onde o usuario deseja inserir a celula
char exclui(int, int);  //confirma se o usuario deseja excluir a celula
char continuar_inserindo();
void apresenta_mundo(char, int);  //apresenta a matriz do mundo
void limpatela();  //organiza melhor o codigo removendo acoes anteriores da tela
void titulo(int);
void apresenta_mensagem(char);
char menu_limpa();
