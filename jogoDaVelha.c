
/*
   UM SIMPLES JOGO DA VELHA DESENVOLVIDO EM C
   by Daniel Pereira Sanches

*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void limpar(char casas[9]){
   int i;
   for(i = 0; i < 9; i++){
      casas[i] = ' ';
   }
}

void tabuleiro(char casas[9]){
   system("cls");
   printf("\t %c | %c | %c \n",casas[0],casas[1],casas[2]);
   printf("\t --------- \n");
   printf("\t %c | %c | %c \n",casas[3],casas[4],casas[5]);
   printf("\t --------- \n");
   printf("\t %c | %c | %c \n",casas[6],casas[7],casas[8]);
}

void main() {
   char casas[9];
   char opcao = 's', vez;
   int countJogadas, jogada;
   while(opcao == 's' || opcao == 'S'){
      limpar(casas);
      countJogadas = 1;
      tabuleiro(casas);
      while(countJogadas <= 9){
         if(countJogadas %2 != 0){
            vez = 'X';
         } else {
            vez = 'O';
         }
         printf("Deseja jogar em qual casa? ");
         scanf("%d", &jogada);
         getchar();
         if(vez == 'X'){
            if(jogada < 1 || jogada > 9){
               printf("Jogada %d invalida. Voce so pode marcar de 1 a 9\n", jogada);
               getchar();
               jogada = 0;
            } else if(casas[jogada-1] == 'O' || casas[jogada-1] == 'X'){
               printf("Casa ocupada. Jogada invalida\n");
               getchar();
               jogada = 0;
            } else {
               casas[jogada-1] = 'X';
               countJogadas ++;
            }
         } else {
            if(jogada < 1 || jogada > 9){
               printf("Jogada %d invalida. Voce so pode marcar de 1 a 9\n", jogada);
               getchar();
               jogada = 0;
            } else if(casas[jogada-1] == 'X' || casas[jogada-1] == 'O'){
               printf("Casa ocupada. Jogada invalida\n");
               getchar();
               jogada = 0;
            }
            else {
               casas[jogada-1] = 'O';
               countJogadas ++;
            }
         }
         tabuleiro(casas);
      }

      printf("\nDeseja jogar novamente? S/N ");
      scanf("%s",&opcao);
      getchar(); // LIMPA O BUFFER DO TECLADO
   }
   system("pause");
}