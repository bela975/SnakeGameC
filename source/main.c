/*Jogo da cobrinha em c
desenvolvido por: Isabela Spinelli, Maria Julia Pessoa e Maria Luisa Arruda
disciplina de programacao imperativa e funcional
*/



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include <termios.h>
#include <string.h>

 


#define LINHAS 20
#define COLS 20


typedef struct jogador{
    char nome[50];
    int pontos;
    struct jogador *next;
}jogador;


typedef struct Cobra {
    int cabeca;
    int rabo;
    int x;
    int y;
    int macaX, macaY;
    int indicador;
    int gameOver;
    int pontos;
    int dx, dy;
    int* corpoCobra;
    int tamanhoCobra;
   
} Cobra;

//criando uma variavel global do tipo cobra para que os dados de Cobra sejam
//acessados dentro de todas as funcoes
Cobra cobra;  
int pontos;


void addJogador(jogador **head, char *nome, int pontos){
    jogador* novoNo = (jogador*)malloc(sizeof(jogador));
    strcpy(novoNo ->nome, nome);
    novoNo ->pontos = pontos;
    if(*head == NULL){
      *head = novoNo;
      novoNo -> next=NULL;
     
    }else if((*head)->pontos < novoNo->pontos){
      novoNo->next = *head;
      *head = novoNo;
    }
    else{
      jogador *jogadorAtual = *head;
      while(jogadorAtual ->next ->pontos > jogadorAtual->pontos){
        jogadorAtual = jogadorAtual ->next;
      }
    novoNo ->next = jogadorAtual->next;
    jogadorAtual->next = novoNo;
    }
   
}
   
void mostrarHighscore(jogador *lista){
    printf("Highscores:\n");
    while (lista != NULL) {
        printf("%s: %d\n", lista->nome, lista->pontos);
        lista = lista->next;
    }
}



void printTitulo(int nextX, int nextY)
{
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(cobra.x, cobra.y);
    printf("           ");
    cobra.x = nextX;
    cobra.y = nextY;
    screenGotoxy(cobra.x, cobra.y);
    printf("O Papa maçã");
}

void macas(){

int gameOver = 0;
 
        if(gameOver == 0) {
            cobra.x = LINHAS/2;
            cobra.y = COLS/2;
           
  //criando uma nova maca de forma aleatoria dentro das linhas e colunas (20 ambas)
 if(cobra.macaX == 0) {

  cobra.macaX = rand() % 20;
 }
 
  if(cobra.macaX == 0) {
  cobra.macaY = rand() % 20;

           }
         }
       }

// Funcao para identificar se uma tecla foi pressionada e qal foi pressionada
void inputJogador(){
if (keyhit()) {
switch (readch()) {
case 'a':
cobra.indicador = 1;
break;
case 's':
cobra.indicador = 2;
break;
case 'd':
cobra.indicador = 3;
break;
case 'w':
cobra.indicador = 4;
break;

case 'x':
cobra.gameOver = 1;
break;
}
    }
}

//criando uma funcao que permite exibir as partes da cobra e as frutas

void itensJogo(){
int i, j;
screenGotoxy(1, 1);  
printf("\033[?25l"); //escondendo cursor quando o jogo estiver ativo para que ele n'ao atrapalhe a jogabilidade

//criando um array de alocacao dinamica de espacos de memoria e inserindo nele o x e y da posicao da cobra
cobra.corpoCobra = malloc(sizeof(int) * 2 * (LINHAS * COLS));
cobra.corpoCobra[0] = cobra.x;                                      
    cobra.corpoCobra[1] = cobra.y;  

if(i == cobra.macaX && j == cobra.macaY){
printf("🍎");
}else if (i == cobra.x && j == cobra.y) {
                    printf("O");
            } else {
                int corpo = 0;
                for (int k = 1; k < cobra.tamanhoCobra; k++) {
                    if (i == cobra.corpoCobra[2 * k] && j == cobra.corpoCobra[2 * k + 1]) {
                        printf("0");
                        corpo = 1;
                        break;
                     }
               }
            //onde a cobra nao tiver, printa espaco vazio
                 if (!corpo) {
                   printf(" ");
                 }
                  printf("\n");
            }

}      
       
       
       
       
void movimentoCobra()

{

     switch (cobra.indicador) {
case 1:
cobra.y--;
break;
case 2:
cobra.x++;
break;
case 3:
cobra.y++;
break;
case 4:
cobra.x--;
break;
default:
break;
}

// checando se o jogo acabou
if (cobra.x < 0 || cobra.x > COLS
|| cobra.y < 0 || cobra.y > LINHAS)
cobra.gameOver = 1;

//atualizando a pontuacao total
if (cobra.x == cobra.macaX && cobra.y == cobra.macaY) {
//aleatorizando novas macas
macax:
cobra.macaX = rand() % 20;
if (cobra.macaX == 0)
goto macax;

//criando uma fruta nova assim que a maca de cima estiver zerada(consumida)
macay:
cobra.macaY = rand() % 20;
if (cobra.macaY == 0)
goto macay;
//adicionando pontos correspondentes a maca que foi devorada
pontos += 10;
}


screenUpdate();
}

void printKey(int ch)
{
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(35, 22);
    printf("Key code :");

    screenGotoxy(34, 23);
    printf("            ");
   
    if (ch == 27) screenGotoxy(36, 23);
    else screenGotoxy(39, 23);

    printf("%d ", ch);
    while (keyhit())
    {
        printf("%d ", readch());
    }
}

 
int main()
{
jogador* head = NULL;
static int ch = 0;
int gameOver = 0;
int escolhaUsuario;
int var = 0;
char username[50];



screenInit(1);
        keyboardInit();
       
        addJogador(&head, "Rodrigu", 3);
addJogador(&head, "dri", 10);
addJogador(&head, "igu", 8);
addJogador(&head, "R", 45678);
       
       
        printTitulo(cobra.x, cobra.y);
        screenUpdate();

       
        while (gameOver == 0)
        {
        printf("\n\n\n aperte 1 para: NOVO JOGO\n");
printf("\n aperte 2 para: VER LISTA DE HIGHSCORE\n");
printf("\n aperte 3 para: VER CREDITOS\n");
printf("\n aperte 4 para: SAIR\n");
scanf("%d", &escolhaUsuario);

printf("\n\n\n insira seu username:\n");
        scanf("%s", username);
        pontos = 0;


        if(escolhaUsuario == 1){
       
        screenInit(1);
        keyboardInit();
        //setando o loop de execucao do jogo
        while((cobra.x > 0 || cobra.x < COLS || cobra.y > 0 || cobra.y < LINHAS)){
       
        //chamando funcoes
macas();
screenUpdate();
movimentoCobra();
itensJogo();

        }
        addJogador(&head,username,pontos);

}else if(escolhaUsuario == 2){
                 
mostrarHighscore(head);

                 }else if(escolhaUsuario == 3){
                 
                  char *var1 = "Papa-maca\n";
char *var2 = "Disciplina de programacao imperativa e funcional - CIÊNCIAS DA COMPUTAÇÃO\n";
char *var3 = "Desenvolvido por Isabela Spinelli, Maria Julia Pessoa e Maria Luisa Arruda\n";
                 
     
       //setando a cor da mensagem da var 1 e do fundo
printf("\n\n\n\n\n ");
screenSetColor(MAGENTA,BLACK);
printf("%s",var1);
printf("\n\n ");
printf(" %c\n\n ", 169);
printf("%s",var2);
printf("\n\n ");
printf(" %c\n\n ", 169);
printf("%s",var3);
printf("\n\n ");
printf(" %c\n\n ", 169);
readch();
screenClear();
        }else if(escolhaUsuario == 4){

  gameOver = 1;
  printf("jogo finalizado! aperte 0 para retornar ao menu principal");
        scanf("%d", &gameOver);
       
         
       }else{
           printf("O numero inserido n'ao corresponde a nenhum comando :(");
           escolhaUsuario = 4;
       }




if (var == 0) {
screenGotoxy(34, 19);
printf(" ");
screenGotoxy(34, 17);
printf(" ");
screenGotoxy(34, 21);
printf("%c", 175);
screenGotoxy(34, 15);
printf("%c", 175);
}

screenClear();

var += -1;

while(head != NULL){
jogador *temp = head;
head = head ->next;

free(temp);
}

       }
      keyboardDestroy();
         screenDestroy();
      return 0 ;
    }
