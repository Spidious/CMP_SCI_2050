#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses);
void printStr(char str[3]);
int isEquals(char *str1, char *str2);
//Heads or Tales:  ((rand()%2 == 1) ? 'H' : 'T');

int main(void)
{

    // Create player prediction arrays and create winner and num toss varaibles
    char p1[4] = {"HHT\0"};
    char p2[4] = {"THH\0"};
    int winner = 0;
    int numToss = 0;
    
    int p1win = 0;
    int p2win = 0;

    // call the function

    for(int i = 0; i < 1000000; i++)
    {
        coinTossGame(p1, p2, &winner, &numToss);

        if(winner == 1)
        {
            p1win += 1;
        }
        else if(winner == 2)
        {
            p2win += 1;
        }
    }
    printf("Player1: %d%%\nPlayer2: %d%%\n", (int)(((float)p1win/1000000)*100), (int)(((float)p2win/1000000)*100));

}

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses)
{
    int errval = 0;
    char tosses[4] = {'F', 'F', 'F', '\0'};
    for(*winner = 0; *winner == 0;)
    {
        char toss = ((rand()%2 == 1) ? 'C' : 'T');
        errval = (toss == 'T')||(toss == 'H') ? 0 : 1;
        *numTosses += 1;
        tosses[0] = tosses[1];
        tosses[1] = tosses[2];
        tosses[2] = toss;

        if(strcmp(tosses, player1)==0)
        {
            *winner = 1;
        }
        if(strcmp(tosses, player2)==0)
        {
            *winner = 2;
        }
    }
    return errval;
}

void printStr(char *str)
{
    for(int i = 0; i<3; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
}