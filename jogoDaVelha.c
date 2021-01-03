
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
   printf("\n");
   printf("\t %c | %c | %c \n",casas[0],casas[1],casas[2]);
   printf("\t --------- \n");
   printf("\t %c | %c | %c \n",casas[3],casas[4],casas[5]);
   printf("\t --------- \n");
   printf("\t %c | %c | %c \n",casas[6],casas[7],casas[8]);
   printf("\n");
}

void main(){
   char casas[9];
   char opcao = 's', vez, vencedor;
   int countJogadas, jogada;
   while(opcao == 's' || opcao == 'S'){
      countJogadas = 1;
      limpar(casas);
      tabuleiro(casas);
      while(countJogadas <= 9){
         if(countJogadas %2 != 0){
            vez = 'X';
         } else {
            vez = 'O';
         }
         printf("\nVEZ: %c\n", vez);
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
         if(casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X'){ // X LINHA 1
            vencedor = 'X';
            countJogadas = 10;
         } else if(casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){ // X LINHA 2
            vencedor = 'X';
            countJogadas = 10;
         } else if(casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X'){ // X LINHA 3
            vencedor = 'X';
            countJogadas = 10;
         } else if(casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X'){ // X COLUNA 1
            vencedor = 'X';
            countJogadas = 10;
         } else if(casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X'){ // X COLUNA 2
            vencedor = 'X';
            countJogadas = 10;
         } else if(casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X'){ // X COLUNA 3
            vencedor = 'X';
            countJogadas = 10;
         } else if(casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X'){  // X DIAGONAL 1
            vencedor = 'X';
            countJogadas = 10;           
         } else if(casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X'){ // X DIAGONAL 2
            vencedor = 'X';
            countJogadas = 10;
         }


         if(casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O'){ // O LINHA 1
            vencedor = 'O';
            countJogadas = 10;
         } else if(casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O'){ // O LINHA 2
            vencedor = 'O';
            countJogadas = 10;
         } else if(casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O'){ // O LINHA 3
            vencedor = 'O';
            countJogadas = 10;
         } else if(casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O'){ // O COLUNA 1
            vencedor = 'O';
            countJogadas = 10;
         } else if(casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O'){ // O COLUNA 2
            vencedor = 'O';
            countJogadas = 10;
         } else if(casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O'){ // O COLUNA 3
            vencedor = 'O';
            countJogadas = 10;
         } else if(casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O'){  // O DIAGONAL 1
            vencedor = 'O';
            countJogadas = 10;           
         } else if(casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O'){ // O DIAGONAL 2
            vencedor = 'O';
            countJogadas = 10;
         }
         tabuleiro(casas);
      }
      if(vencedor == 'X'){
         printf("\t--------------------\n\tJOGADOR X VENCEU\n\t--------------------");   
      } else if(vencedor == 'O') {
         printf("\t--------------------\n\tJOGADOR O VENCEU\n\t--------------------");
      } else {
         printf("\t--------------------\n\tNENHUM JOGADOR VENCEU\n\t--------------------");
      }

      printf("\nDeseja jogar novamente? S/N ");
      scanf("%s",&opcao);
      getchar(); // LIMPA O BUFFER DO TECLADO
   }
   system("pause");
}