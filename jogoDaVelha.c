
/*
   Jogo da velha desenvolvido em C
   by DANIEL PEREIRA SANCHES

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void main() {
   char casas[9];
   limparTela();
   limparCasas(casas);
   jogo(casas);
   pausar();
}

int limparTela() {
   system("cls");
}

int limparCasas(char casas[9]){
   int i;
   for(i=0; i < 9; i++) {
      casas[i] = ' ';
   }
}

int definirJogador() {
   int jogador = 0;
   while(jogador < 1 || jogador > 2) {
      printf("\n\t\t\tJOGAR COM: \n");
      printf("\n\t---------------------------------------\n");
      printf("\n\t\t\t1 - amigo \n \t\t\t2 - computador \n");
      printf("\n\t---------------------------------------\n");
      printf("\n\t\tESCOLHA UMA OPCAO: ");
      scanf("%d", &jogador);
      if(jogador < 1 || jogador > 2) {
         limparTela();
         printf("\n\t\tOPCAO INVALIDA. TENTE NOVAMENTE\n\n");
      }
   }
   limparTela();
   return jogador;
}

int definirDificuldade() {
   int dificuldade = 0;
   while(dificuldade < 1 || dificuldade > 2) {
      printf("\n\t\t  ESCOLHA A DIFICULDADE: \n");
      printf("\n\t---------------------------------------\n");
      printf("\n\t\t\t1 - facil \n \t\t\t2 - medio \n");
      printf("\n\t---------------------------------------\n");
      printf("\n\t\tESCOLHA UMA OPCAO: ");
      scanf("%d", &dificuldade);
      if(dificuldade < 1 || dificuldade > 2) {
         limparTela();
         printf("\n\t\tOPCAO INVALIDA. TENTE NOVAMENTE\n\n");
      }
   }
   limparTela();
   return dificuldade;
}

int desenharTabuleiro(char casas[9]) {
   limparTela();
   printf("\n\n");
   printf("\t %c | %c | %c \n",casas[0],casas[1],casas[2]);
   printf("\t ---------- \n");
   printf("\t %c | %c | %c \n",casas[3],casas[4],casas[5]);
   printf("\t ---------- \n");
   printf("\t %c | %c | %c \n",casas[6],casas[7],casas[8]);
}

int jogo(char casas[9]) {
   int countJogadas = 1, jogada;
   char vez;
   switch(definirJogador()) { // CHAMA A FUNCAO PARA DEFINIR O JOGADOR
      case 1: // JOGAR COM UM AMIGO
         while(countJogadas <= 9) {
            if(countJogadas % 2 == 0) {
               vez = 'O';
            } else {
               vez = 'X';
            }
            desenharTabuleiro(casas);
            printf("\n DESEJA JOGAR EM QUAL CASA? ");
            scanf("%d",&jogada);
            switch(vez) {
               case 'X':
                  if(casas[jogada-1] != ' ') {
                     printf("\nCASA OCUPADA. JOGADA INVALIDA\n");
                     pausar();
                  } else if(jogada < 1 || jogada > 9) {
                     printf("\nJOGADA %d INVALIDA. VOCE SO PODE MARCAR DE 1 A 9\n");
                     pausar();
                  } else {
                     casas[jogada-1] = 'X';
                     countJogadas++;
                  }
               break;

               case 'O':
                  if(casas[jogada-1] != ' ') {
                     printf("\nCASA OCUPADA. JOGADA INVALIDA\n");
                     pausar();
                  } else if(jogada < 1 || jogada > 9) {
                     printf("\nJOGADA %d INVALIDA. VOCE SO PODE MARCAR DE 1 A 9\n");
                     pausar();
                  } else {
                     casas[jogada-1] = 'O';
                     countJogadas++;
                  }
               break;
            }
         }
      break;


      case 2: // JOGAR COM O COMPUTADOR
         printf("\nESOCLHEU CPU\n");
         switch(definirDificuldade()) {
            case 1:  // DIFICULDADE FACIL
               printf("\nESCOLHEU FACIL\n");
            break;


            case 2:  // DIFICULDADE MEDIA
            
            break;
         }
      break;
   }
   desenharTabuleiro(casas);
}

int pausar() {
   system("pause");
}