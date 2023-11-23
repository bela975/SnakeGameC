/*
Jogo da cobrinha em c
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
    int LINHAS= 20, COLS= 20;
    int macaX, macaY;
    int indicador;
    int gameOver;
    int pontos;
} Cobra;



void macas(){

  gameOver = 0;
 
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
         return 0;
       }

void limiteTela(){
//limpando o terminal
system("cls");
for (i = 0; i < COLUNAS ; i++) {
for (j = 0; j < LINHAS ; j++) {
if (i == 0 || i == LINHAS - 1  || j == 0 || j == COLUNAS - 1) {
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
}
case 'x':
gameover = 1;
break;
}
}
}
       

void movimentoCobra()
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
}
