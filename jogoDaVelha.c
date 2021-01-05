#include <stdio.h>
#include <stdlib.h>


void main() {
   char casas[9];
   limparTela();
   limparCasas(casas);
   definirJogador();
   limparTela();
   definirDificuldade();
   limparTela();
   desenharTabuleiro(casas);
   system("pause");
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
      printf("\n\t\t\tESCOLHA UMA OPCAO: ");
      scanf("%d", &jogador);
      if(jogador < 1 || jogador > 2) {
         system("cls");
         printf("\n\t\tOPCAO INVALIDA. TENTE NOVAMENTE\n\n");
      }
   }
}

int definirDificuldade() {
   int dificuldade = 0;
   while(dificuldade < 1 || dificuldade > 2) {
      printf("\n\t\t\tESCOLHA A DIFICULDADE: \n");
      printf("\n\t---------------------------------------\n");
      printf("\n\t\t\t1 - facil \n \t\t\t2 - medio \n");
      printf("\n\t---------------------------------------\n");
      printf("\n\t\t\tESCOLHA UMA OPCAO: ");
      scanf("%d", &dificuldade);
      if(dificuldade < 1 || dificuldade > 2) {
         limparTela();
         printf("\n\t\tOPCAO INVALIDA. TENTE NOVAMENTE\n\n");
      }
   }
}

int desenharTabuleiro(char casas[9]) {
   printf("\t %c | %c | %c \n",casas[0],casas[1],casas[2]);
   printf("\t ---------- \n");
   printf("\t %c | %c | %c \n",casas[3],casas[4],casas[5]);
   printf("\t ---------- \n");
   printf("\t %c | %c | %c \n",casas[6],casas[7],casas[8]);
}