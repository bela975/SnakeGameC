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
#include "timer.c"
#include "screen.c"
#include "keyboard.c"

typedef struct cobra {
    int X[1000];
    int Y[1000];
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



void macas(){

int gameOver = 0;
 
       while(gameOver == 0) {
            x = LINHAS/2;
            y = COLS/2;
           
  //criando uma nova maca de forma aleatoria dentro das linhas e colunas (20 ambas)
 if(macaX == 0) {

  macaX = rand() % 20;
 }
 
  if(macaX == 0) {
  macaY = rand() % 20;

        }
    }
}

void limiteTela(){
int X[1000];
    int Y[1000];
    int cabeca;
    int rabo;
    int x;
    int y;
    int macaX, macaY;
    int indicador;
    int pontos;


int LINHAS=20, COLS= 20;
int i, j;

int gameOver = 0;


//limpando o terminal
system("cls");
for (i = 0; i < COLS ; i++) {
for (j = 0; j < LINHAS ; j++) {
if (i == 0 || i == LINHAS - 1  || j == 0 || j == COLS - 1) {
printf("H");
} else {
          if (i == x && j == y){
printf("?");
                   }
                   else if (i == macaX && j == macaY){
                        printf("*");
                   }
                   else{
                   printf(" ");
                   }
                }
                printf("\n");
              }
             }
printf("Pontuacao obtida:%d\n", pontos);
printf("\n");
printf("aperte X para terminar o jogo");
return 0;
}
 
        // Function to take the input
        void inputJogador(){
if (peekcharacter()) {
switch (readch()) {
case 'a':
indicador = 1;
break;
case 's':
indicador = 2;
break;
case 'd':
indicador = 3;
break;
case 'w':
indicador = 4;
break;

case 'x':
gameOver = 1;
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

int X[1000];
int Y[1000];
int cabeca;
int rabo;
int x;
int y;
int macaX, macaY;
int indicador;
int pontos;



{

switch (indicador) {
case 1:
y--;
break;
case 2:
x++;
break;
case 3:
y++;
break;
case 4:
x--;
break;
default:
break;
}

// checando se o jogo acabou
if (x < 0 || x > COLS
|| y < 0 || y > LINHA)
gameover = 1;

//atualizando a pontuacao total
if (x == macaX && y == macaY) {
//aleatorizando novas macas
macax:
macaX = rand() % 20;
if (macaX == 0)
goto macax;

//criando uma fruta nova assim que a maca de cima estiver zerada(consumida)
macay:
macaY = rand() % 20;
if (macaY == 0)
goto macay;
//adicionando pontos correspondentes a maca que foi devorada
pontos += 10;
}
}

 
int main()
{
    int X[1000];
    int Y[1000];
    int cabeca;
    int rabo;
    int x;
    int y;
    int macaX, macaY;
    int indicador;
    int pontos;


int LINHAS=20, COLS= 20;
int i, j;


int gameOver = 0;


int m, n;

// gerando as bordas
limiteTela();

// Until the game is over
while (gameover = 0) {

//chamando funcoes
draw();
input();
logic();
}
printf("jogo finalizado! deseja jogar novamente?");
printf("caso queira digite 1");
scanf("%d", &gameOver);
return 0;
}
