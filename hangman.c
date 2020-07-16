//Data structures course-based project (B.Tech 2nd-year)

/*
Probable input:  
      Guess a letter
Probable output:
      If your guess is correct-
     Hurray! You guessed it right. 
     Word
     Remaining chances.
     If your guess is wrong-
     Whoops! That letter isn’t there.
     Remaining chances.
     If your chances are completed:
     Sorry you have been hanged.
 */

//Code starts here!!!

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void showHangman(int);
int main(void)
{
    char hangmanWord[100], tempWord[100];
    char hangmanOutput[100];
    int wrongTry = 6 , matchFound = 0;
    int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;
    system("cls");
    printf("\n\n Enter any word in small case and hit >>ENTER<<\n\n");
    scanf("%s",hangmanWord);
    printf("\n\n Now give the COMPUTER to your friend and see if he/she can CRACK it!!!");
    printf("\n\n\tHIT >>ENTER<<\n");
    getchar();
    length = strlen(hangmanWord);
    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");
    printf("\n\n You will get 5 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");
    getchar();
        printf("\n\t||===== ");
	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
    printf("\n\n     The word has %d alphabets \n\n",length);
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }
    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);
    }
    while(wrongTry != 0)
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");
	    fflush(stdin);
	    scanf("%c",&alphabetFromUser);
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z')
    {

        printf("\n\n\t Wrong input TRY AGAIN ");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)
	    {
		    if(alphabetFromUser==hangmanWord[counter])
		     {
		       matchFound = 1;
                     }
            }
	   if(matchFound == 0)
	    {
     	      printf("\n\t :( You have %d tries left ",--wrongTry);
	          getchar();
              showHangman(wrongTry);
              getchar();
	    }
	   else
	   {

	            for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;
                 if(alphabetFromUser == hangmanWord[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser;
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' )


                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanOutput[i] = '_';
                      }
                }
                tempWord[position] = alphabetFromUser;
                tempWord[length] = '\0';
                winner = strcmp(tempWord,hangmanWord);

                if(winner == 0)
                {
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",hangmanWord);
                    getchar();
                    return 0;
                }
	       }
	    }
      }
     }
    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);
      }
    getchar();
    }
      if(wrongTry <= 0)
      {
          printf("\n\n\t The Word was %s ",hangmanWord);
          printf("\n\n\t The man is dead Better luck next!!!");
      }
getchar();
return 0;
}
void showHangman(int choice)
 {
     switch(choice)
     {

     case 0:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }
      return;
 }

//end of code!!
//written by Ullas Reddy Chennuri
