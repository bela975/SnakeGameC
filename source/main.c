#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include <termios.h>

#define LINHAS 20
#define COLS 20

typedef struct Cobra {
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
} Cobra;

//criando uma variavel global do tipo cobra para que os dados de Cobra sejam
//acessados dentro de todas as funcoes
Cobra cobra;  

void printHello(int nextX, int nextY)
{
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(cobra.x, cobra.y);
    printf("           ");
    cobra.x = nextX;
    cobra.y = nextY;
    screenGotoxy(cobra.x, cobra.y);
    printf("Hello World");
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

int limiteTela(){
    
    int gameOver = 0;
    int i, j;
    
    //limpando o terminal
    system("cls");
    for (i = 0; i < COLS ; i++) {
        for (j = 0; j < LINHAS ; j++) {
            if (i == 0 || i == LINHAS - 1  || j == 0 || j == COLS - 1) {
                printf("H");
            } else {
              if (i == cobra.x && j == cobra.y){
                printf("?");
                } else if (i == cobra.macaX && j == cobra.macaY){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
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
       

void movimentoCobra(){

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
    if (cobra.x < 0 || cobra.x > COLS || cobra.y < 0 || cobra.y > LINHAS)
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
            cobra.pontos += 10;
        }
    screenUpdate();
}

void printKey(int ch){
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(35, 22);
    printf("Key code :");

    screenGotoxy(34, 23);
    printf("            ");
   
    if (ch == 27) 
        screenGotoxy(36, 23);
    else 
        screenGotoxy(39, 23);

    printf("%d ", ch);
    while (keyhit()) {
        printf("%d ", readch());
    }
}

 
int main() {

    static int ch = 0;
    int gameOver = 0;
    
    screenInit(1);
            keyboardInit();
           
             printHello(cobra.x, cobra.y);
             screenUpdate();
    
           
            while (ch != 10){//enter 
            // Handle user input
                if (keyhit()){
                    ch = readch();
                    printKey(ch);
                    screenUpdate();
                }
    
    int m, n;
    
    // gerando as bordas
    limiteTela();
    
    // Until the game is over
    while (cobra.gameOver = 0) {
    
        //chamando funcoes
        macas();
        screenUpdate();
        limiteTela();
        movimentoCobra();
    }
        
    printf("jogo finalizado! deseja jogar novamente?");
    printf("caso queira digite 1");
    scanf("%d", &gameOver);
    
    
    keyboardDestroy();
    screenDestroy();
    
    return 0;
    }
}
