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

 


#define LINHAS 20
#define COLS 20

typedef struct highscore{
char *nomeJogador;
float pontos;
} Highscore;

typedef struct Jogador{
char *nomeJogador;
float pontos;
} Jogador;

typedef struct Cobra {
    int X;
    int Y;
    int cabeca;
    int rabo;
    int x;
    int y;
    int macaX, macaY;
    int indicador;
    int gameOver;
    int pontos;
    Highscore highscore;
} Cobra;

//criando uma variavel global do tipo cobra para que os dados de Cobra sejam
//acessados dentro de todas as funcoes
Cobra cobra;  

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

int mensagemInferior(){

int gameOver = 0;
int i, j;

//limpando o terminal
system("cls");


printf("Pontuacao obtida:%d\n", cobra.pontos);
printf("\n");
printf("aperte X para terminar o jogo");
return 0;
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
cobra.highscore.pontos += 10;
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

static int ch = 0;
int gameOver = 0;
int escolhaUsuario;
int var = 0;


screenInit(1);
        keyboardInit();
       
        printTitulo(cobra.x, cobra.y);
        screenUpdate();

       
        while (gameOver == 0)
        {
        printf("\n\n\n aperte 1 para: NOVO JOGO\n");
printf("\n aperte 2 para: VER LISTA DE HIGHSCORE\n");
printf("\n aperte 3 para: VER CREDITOS\n");
printf("\n aperte 4 para: SAIR\n");
scanf("%d", &escolhaUsuario);

        if(escolhaUsuario == 1){
        screenInit(1);
        keyboardInit();
        //setando o loop de execucao do jogo
        while((cobra.x > 0 || cobra.x < COLS || cobra.y > 0 || cobra.y < LINHAS)){
       
        //chamando funcoes
macas();
screenUpdate();
movimentoCobra();
        }
}else if(escolhaUsuario == 2){
                 //exibirhighscore
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


       }
      keyboardDestroy();
         screenDestroy();
     
      }
     
   




/*
switch (var) {
case 1:

screenGotoxy(23, 15);

printf("Digite seu nome: ");

scanf("%s", cobra.highscore.nomeJogador);

screenGotoxy(1, 1);

screenSetColor(MAGENTA, BLACK);

printf("Nome: %s SCORE: %lf pontos",cobra.highscore.nomeJogador, cobra.highscore.pontos);
break;

case 2:
screenClear();
screenGotoxy(16, 2);
screenSetColor(MAGENTA, BLACK);
printf(" ");
screenGotoxy(16, 3);
printf(" ");
screenSetColor(MAGENTA, BLACK);
printf(" ");
screenGotoxy(16, 4);
printf(" ");
screenSetColor(MAGENTA, BLACK);
printf(" HIGH SCORE ");
screenSetColor(MAGENTA, BLACK);
printf(" ");
screenGotoxy(16, 5);
printf(" ");
screenSetColor(MAGENTA, BLACK);
printf(" ");
screenSetColor(MAGENTA, BLACK);
printf(" ");
screenGotoxy(16, 6);
printf(" ");
screenSetColor(MAGENTA, BLACK);
printf("\n ");
printf("\n\n NOME: %s Pontos: %.2f", cobra.highscore.nomeJogador, cobra.highscore.pontos);
readch();
break;

case 3:
printf("\n\n\n\n\n\n\n ");
printf("%s",cred1);
printf("\n\n ");
printf("\n\n\n\n\n\n\n ");
printf("%s", cred2);
printf("\n\n ");
printf("\n\n\n\n\n\n\n ");
readch();
break;

case 4:
exit(0);
break;
}
*/  