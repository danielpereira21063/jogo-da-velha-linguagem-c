#include <stdio.h>
#include <stdlib.h>

void tabuleiro(char casas[9]){
   system("cls");
   printf("\t %c | %c | %c \n",casas[0],casas[1],casas[2]);
   printf("\t ---------- \n");
   printf("\t %c | %c | %c \n",casas[3],casas[4],casas[5]);
   printf("\t ---------- \n");
   printf("\t %c | %c | %c \n",casas[6],casas[7],casas[8]);
}

void main() {
   char casas[9] = {'1','2','3','4','5','6','7','8','9'};
   tabuleiro(casas);
   system("pause");
}