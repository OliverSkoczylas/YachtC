#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void seed(int argc, char ** argv){
    srand(time(NULL)); // Initialize random seed
    if (argc>1){
        int i;
        if (1 == sscanf(argv[1],"%d",&i)){
            srand(i);
        }
    }
}
void instructions(){
    printf("\n\n\n\n"
           "\t**********************************************************************\n"
           "\t*                         Welcome to YahtC                            *\n"
           "\t**********************************************************************\n"
           "\tYahtC is a dice game (very) loosely modeled on Yahtzee\n"
           "\tBUT YahtC is not Yahtzee.\n\n"
           "\tRules:\n"
           "\t5 dice are rolled\n"
           "\tThe user selects which dice to roll again.\n"
           "\tThe user may choose to roll none or all 5 or any combination.\n"
           "\tAnd then the user selects which dice to roll, yet again.\n"
           "\tAfter this second reroll the turn is scored.\n\n"
           "\tScoring is as follows:\n"
           "\t\t*\t50 points \t5 of a kind scores 50 points.\n"
           "\t\t*\t45 points \tNo pairs (all unique) scores 45 points.\n"
           "\t\t*\t40 points \t4 of a kind scores 40 points.\n"
           "\t\t*\t30 points \t3 of a kind scores 30 points.\n"
           "\t\t*\tTotal Dice\tOtherwise score the dice total.\n\n"
           "\tTo indicate nothing to reroll the user will input 0\n"
           "\tThis should end the players turn.\n"
           "\tOtherwise the user will indicate which dice to reroll by position\n"
           "\t135 would indicate to reroll the first, third and last die.\n"
           "\tThe numbers do not have to be given in order\n"
           "\tThe game ends after 7 turns.\n"
           "\t**********************************************************************\n\n\n");
           }
void scoreCalc(int list[], int size, int *score) {
   int count = 0;

   for (int i = 1; i < 1 + size; i++) {
      if (list[i] == list[1]) {
         count++;
      } if (list[i] == list[2]) {
         count++;
      } if (list[i] == list[3]) {
         count++;
      } if (list[i] == list[4]) {
         count++;
      } if (list[i] == list[5]) {
         count++;
      }
   }

   if (count == 25) {
      *score = 50;
   } else if (count == 5) {
      *score = 45;
   } else if (count == 17) {
      *score = 40;
   } else if (count >= 11 && count <= 13) {
      *score = 30;
   } else {
      *score = list[1] + list[2] + list[3] + list[4] + list[5];
   }

   printf("%d", *score);

}
void diceReroll(int list[], int size, int x) {

   int choice[size];
   int count = 0;

   if (x >= 10000) 
   {
      choice[count] = (x / 10000);
      count++;
   }

   if (x >= 1000) 
   {
      choice[count] = (x / 1000) % 10;
      count++;
   }

   if (x >= 100) 
   {
      choice[count] = (x / 100) % 10;
      count++;
   }

   if (x >= 10) 
   {
      choice[count] = (x / 10) % 10;
      count++;
   }

   if (x > 0) 
   {
      choice[count] = x % 10;
      count++;
   }

   for (int i = 0; i < count; i++) {

      if (choice[i] == 1) 
      {
         list[1] = (rand() % 6 + 1);
      }
      else if (choice[i] == 2) 
      {
         list[2] = (rand() % 6 + 1);
      }
      else if (choice[i] == 3) 
      {
         list[3] = (rand() % 6 + 1);
      }
      else if (choice[i] == 4) 
      {
         list[4] = (rand() % 6 + 1);
      }
      else if (choice[i] == 5) 
      {
         list[5] = (rand() % 6 + 1);
      }

   }


}
void diceRoll(int list[], int size) {

   printf("First Roll = ");

   for (int i = 0; i < size; i++) {
      list[1+ i] = (rand()%6+1);

      printf("%d", list[i + 1]);
   }

   printf("\n");
}





int main(int argc, char ** argv){
    seed(argc, argv);
    instructions();

    int size = 5, list[1 + size], x, score, totalRounds = 7, totalScore = 0, scoreList[7] = {};
    

    for (int i = 0; i < totalRounds; i++) {
        diceRoll(list, size);

        printf("Select Dice to Re-roll => ");
        scanf("%d", &x);

        if (x != 0) {
        diceReroll(list, size, x);

        printf("Second Roll = %d%d%d%d%d\n", list[1], list[2], list[3], list[4], list[5]);

        printf("Select Dice to Re-roll => ");
        scanf("%d", &x);

            if (x != 0) {

                diceReroll(list, size, x);

                printf("score for %d%d%d%d%d is ", list[1], list[2], list[3], list[4], list[5]);
                scoreCalc(list, size, &score);

            } else {

                printf("score for %d%d%d%d%d is ", list[1], list[2], list[3], list[4], list[5]);
                scoreCalc(list, size, &score);
            }
        } else {
            printf("score for %d%d%d%d%d is ", list[1], list[2], list[3], list[4], list[5]);
            scoreCalc(list, size, &score);
        }

        scoreList[i] = score;
        totalScore = totalScore + score;

        printf("\n");
        printf("\n");

    }

    printf("---------\n");
    printf("SCORESHEET\n");
    printf("----------\n");
    printf("Turn 1: %d\n", scoreList[0]);
    printf("Turn 2: %d\n", scoreList[1]);
    printf("Turn 3: %d\n", scoreList[2]);
    printf("Turn 4: %d\n", scoreList[3]);
    printf("Turn 5: %d\n", scoreList[4]);
    printf("Turn 6: %d\n", scoreList[5]);
    printf("Turn 7: %d\n", scoreList[6]);
    printf("==========\n");
    printf("Total: %d\n", totalScore);


    return 0;
}