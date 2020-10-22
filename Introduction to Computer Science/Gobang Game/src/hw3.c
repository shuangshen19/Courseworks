#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check(char in[])
{
	int ex;
	ex = strlen(in);
	return (ex == 5 || ex == 6 || ex == 7) ? 0:1;
}

int checkGetLine(char ch[15][15])  // check if the chesses are about to get a line
{
	int i = 0, j = 0, k = 0;
	int b = 0, w = 0;
	// if b = 1, the black chess is getting a line
	// if w = 1, the white chess is getting a line
    for(i = 0; i < 15; i++)
	{
        for(j = 0; j < 15; j++)
		{
			// get row
            if((j < 12 && ch[i][j] == ch[i][j+1] && ch[i][j+1] == ch[i][j+2] && ch[i][j+2] == ch[i][j+3]) || 
			   (j < 11 && ch[i][j] == ch[i][j+1] && ch[i][j+1] == ch[i][j+3] && ch[i][j+3] == ch[i][j+4]) ||
			   (j < 11 && ch[i][j] == ch[i][j+2] && ch[i][j+2] == ch[i][j+3] && ch[i][j+3] == ch[i][j+4]) ||
			   (j < 11 && ch[i][j] == ch[i][j+1] && ch[i][j+1] == ch[i][j+2] && ch[i][j+2] == ch[i][j+4]))
			{
				if((j > 0 && ch[i][j-1] == '.') || (j < 11 && ch[i][j+4] == '.') || (j < 13 && ch[i][j+2] == '.') ||
				   (j < 14 && ch[i][j+1] == '.') || (j < 12 && ch[i][j+3] == '.'))
				{
                    if(ch[i][j] == 'B') b = 1;
                    else if(ch[i][j] == 'W') w = 1;
                }
            }
			// get straight
            else if((i < 12 && ch[i][j] == ch[i+1][j] && ch[i+1][j] == ch[i+2][j] && ch[i+2][j] == ch[i+3][j]) || 
					(i < 11	&& ch[i][j] == ch[i+1][j] && ch[i+1][j] == ch[i+3][j] && ch[i+3][j] == ch[i+4][j]) ||
					(i < 11 && ch[i][j] == ch[i+2][j] && ch[i+2][j] == ch[i+3][j] && ch[i+3][j] == ch[i+4][j]) ||
					(i < 11 && ch[i][j] == ch[i+1][j] && ch[i+1][j] == ch[i+2][j] && ch[i+2][j] == ch[i+4][j]))
			{
                if((i > 0 && ch[i-1][j] == '.') || (i < 11 && ch[i+4][j] == '.') || (i < 13 && ch[i+2][j] == '.') ||
				   (i < 14 && ch[i+1][j] == '.') || (i < 12 && ch[i+3][j] == '.'))
				{
                    if(ch[i][j] == 'B') b = 1;
                    else if(ch[i][j] == 'W') w = 1;
                }
            }
			// left slope
            else if((i < 12 && j < 12 && ch[i][j] == ch[i+1][j+1] && ch[i+1][j+1] == ch[i+2][j+2] && ch[i+2][j+2] == ch[i+3][j+3]) || 
					(i < 11 && j < 11 && ch[i][j] == ch[i+2][j+2] && ch[i+2][j+2] == ch[i+3][j+3] && ch[i+3][j+3] == ch[i+4][j+4]) ||
					(i < 11 && j < 11 && ch[i][j] == ch[i+1][j+1] && ch[i+1][j+1] == ch[i+3][j+3] && ch[i+3][j+3] == ch[i+4][j+4]) ||
					(i < 11 && j < 11 && ch[i][j] == ch[i+1][j+1] && ch[i+1][j+1] == ch[i+2][j+2] && ch[i+2][j+2] == ch[i+4][j+4]))
			{
                if((i > 0 && j > 0 && ch[i-1][j-1] == '.') || (i < 11 && j < 11 && ch[i+4][j+4] == '.') ||
   				   (i < 14 && j < 14 && ch[i+1][j+1] == '.') || (i < 13 && j < 13 && ch[i+2][j+2] == '.') || (i < 12 && j < 12 && ch[i+3][j+3] == '.'))
				{
                    if(ch[i][j] == 'B') b = 1;
                    else if(ch[i][j] == 'W') w = 1;
                }
            }
			// right slope
            else if((i < 12 && j > 2 && ch[i][j] == ch[i+1][j-1] && ch[i+1][j-1] == ch[i+2][j-2] && ch[i+2][j-2] == ch[i+3][j-3]) || 
					(i < 11 && j > 3 && ch[i][j] == ch[i+2][j-2] && ch[i+2][j-2] == ch[i+3][j-3] && ch[i+3][j-3] == ch[i+4][j-4]) ||
					(i < 11 && j > 3 && ch[i][j] == ch[i+1][j-1] && ch[i+1][j-1] == ch[i+3][j-3] && ch[i+3][j-3] == ch[i+4][j-4]) ||
					(i < 11 && j > 3 && ch[i][j] == ch[i+1][j-1] && ch[i+1][j-1] == ch[i+2][j-2] && ch[i+2][j-2] == ch[i+4][j-4]))
			{
                if((i > 0 && j < 14 && ch[i-1][j+1] == '.') || (i < 11 && j > 3 && ch[i+4][j-4] == '.') ||
				   (i < 14 && j > 0 && ch[i+1][j-1] == '.') || (i < 13 && j > 1 && ch[i+2][j-2] == '.') || (i < 12 && j > 2 && ch[i+3][j-3] == '.'))
				{
                    if(ch[i][j] == 'B') b = 1;
                    else if(ch[i][j] == 'W') w = 1;
                }
            }
        }
	}
	
	if (b == 1 && w == 1) k = 3;
	else if(b == 1) k = 1;
	else if(w == 1) k = 2;
	
	return k;
}

int checkLine(char ch[15][15])     // check if the chesses get a line
{
	int i = 0, j = 0, win = 2;
	// if win = 0, black chess win; if win = 1, white chess win
	for(i = 0; i < 15; i++)
	{
        for(j = 0; j < 15; j++)
		{
			// judge the line is all chess
			if(ch[i][j] != '.')
			{
				// get row
				if(j < 11 && ch[i][j] == ch[i][j+1] && ch[i][j+1] == ch[i][j+2] && ch[i][j+2] == ch[i][j+3] && ch[i][j+3] == ch[i][j+4])
				{
                    if(ch[i][j] == 'B') win = 0;
                    else if(ch[i][j] == 'W') win = 1;
				}
				// get straight
				else if(i < 11 && ch[i][j] == ch[i+1][j] && ch[i+1][j] == ch[i+2][j] && ch[i+2][j] == ch[i+3][j] && ch[i+3][j] == ch[i+4][j])
				{
                    if(ch[i][j] == 'B') win = 0;
                    else if(ch[i][j] == 'W') win = 1;
                }
				// left slope
				else if(i < 11 && j < 11 && ch[i][j] == ch[i+1][j+1] && ch[i+1][j+1] == ch[i+2][j+2] && ch[i+2][j+2] == ch[i+3][j+3] && ch[i+3][j+3] == ch[i+4][j+4])
				{
                    if(ch[i][j] == 'B') win = 0;
                    else if(ch[i][j] == 'W') win = 1;
                }    
				// right slope
				else if(i < 11 && j > 3 && ch[i][j] == ch[i+1][j-1] && ch[i+1][j-1] == ch[i+2][j-2] && ch[i+2][j-2] == ch[i+3][j-3] && ch[i+3][j-3] == ch[i+4][j-4])
				{ 
                    if(ch[i][j] == 'B') win = 0;
                    else if(ch[i][j] == 'W') win = 1;
                }
            }
        }
	}
	
    return win;
}

int main(int argc, char *argv[])
{
	// welcome and rules
	printf("Welcome to the Gobang Game!\n");
    printf("Hope you have a great time playing!\n");
    printf("Following are the rules.\n");
    printf("Rule1:Please input coordinate to choose the place you want\n");
    printf("      EX.coordinate[3,4]is the place of row 3 and column 4\n");
    printf("Rule2:If player gets 5 chess in a line, the player wins\n");
    printf("Rule3:If no one gets 5 chess in a line, the game is a tie\n");
    printf("Rule4:The black chess is the first in the initial game\n");
    printf("Rule5:The black chess and the white chess are turn by turn\n");
    printf("Rule6:The chess board has 15 rows and 15 columns\n");
    printf("Now, let's get started!\n\n");

	// initialize
	char chart[15][15], *p, input[8];
	char *token, *token1, *token2;
    int i = 0, j = 0, game = 0, turn = 0;
	// turn = 0 is black chess, turn = 1 is white chess
	// game = 0 is playing
    for(p = &chart[0][0]; p < &chart[15][15]; p++) *p = '.';

	// open a not end game
	if(argc > 1)
	{
		FILE *fp;
        fp = fopen(argv[1],"r");   // read
        char line[30];
        int b = 0, w = 0;
		i =0;
		// judge '.', 'B', 'W' position
        while(fgets(line, sizeof line, fp) != NULL && i < 29)  
		{
            for(j = 0; j < 29; j+=2)
			{
                if(line[j] == 'B')
				{
                    b++;
                    chart[i/2][j/2] = 'B';
                }
                else if(line[j] == 'W')
				{
                    w++;
                    chart[i/2][j/2] = 'W';
                }
            }
            i++;
		}
		
		// judge the next player
		if(b == w) turn = 0;
        else if(b > w) turn = 1;
        else  
		{
			// not a regular game -> can't play
            printf("Wrong chessformat of the game.\n");
            exit(0);
        }
	}
	
	while(game == 0)                // create a while loop to run
	{
		for(i = 0; i < 15; i++)		// print chessboard
		{
			for(j = 0; j < 15; j++) printf("%c ", chart[i][j]);
			printf("%d\n",i+1);
		}
		printf("\n");
		if(turn == 0) printf("Turn to black chess.\n");
		else if(turn == 1) printf("Turn to white chess.\n");
		
		int getLine = checkGetLine(chart);
		// if value = 0, both are about to get line; value = 1, black chess is about to get line; value = 2, white chess  is about to get line
		int line = checkLine(chart);
		// if value = 0, black chess win; value = 1, white chess win
		if(line == 2)
		{
			if(getLine == 3) printf("Both are about to get line.\n");
			else if(getLine == 1) printf("Black chess is about to get line.\n");
			else if(getLine == 2) printf("White chess is about to get line.\n");
		}
		else if(line == 0 || line == 1)
		{
			if(line == 0)
			{
				printf("Black chess WIN.\n");
				game = 1;
				break;
			}
			else if(line == 1)
			{
				printf("White chess WIN.\n");
				game = 1;
				break;
			}	
		}
		else
		{
			// judge the chess board is full or not
			for(p = &chart[0][0]; p < &chart[15][15]; p++)
			{
				if(*p != '.')
				{
					if(p == &chart[14][14])
					{
						printf("Game Over. No Winner. It's a tie.\n");
						game = 1;
						break;
					}
				}
				else break;
			}
		}
		
		// the black chess is first	
		printf("Please input a coordinate (ex. [5-9]): ");
		scanf("%s",input);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		char place[2][3];
		int spot[2];
			
		if(check(input) == 0 && input[0] == '[' && (input[2] == '-' || input[3] == '-') && (input[4] == ']' || input[5] == ']' || input[6] == ']'))
		{	
			// Split the input and store into place
			token = strtok(input,"[");
			token = strtok(token,"]");
            token1 = strtok(token,"-");
			strcpy(place[0],token1);
			token2 = strtok(NULL,"-");
			strcpy(place[1],token2);
					
			// change char to int
			spot[1] = atoi(place[0]);
			spot[0] = atoi(place[1]);
			if(spot[0] > 15 || spot[1] > 15)
			{
				printf("Wrong coordinate input! Please try again!\n");
			    continue;
			}
				
			// put the chess into chessboard
			if(chart[spot[0]-1][spot[1]-1] == '.')
			{
				if(turn == 0) chart[spot[0]-1][spot[1]-1] = 'B';
				else if(turn == 1) chart[spot[0]-1][spot[1]-1] = 'W';
			}
			else
			{
				printf("The place has a chess, please choose another place.\n");
				continue;
			}
	
			// turn to next player
			turn = (turn+1)%2;
		}
		else
		{
			if(strcmp(input,"exit") == 0)    // exit function
			{
				printf("Exit Game.\n");
				game = 1;
				break;
			}
			else if(strcmp(input,"save") == 0)  // save function
			{
				FILE *fpw;
				fpw = fopen("SaveGame.txt","w");
				for(i = 0; i < 15; i++)		// save chessboard
				{
					for(j = 0; j < 15; j++) 
					{
						fprintf(fpw, "%c", chart[i][j]);
						if(j < 14) fprintf(fpw, " ");
					}
					if(i < 14) fprintf(fpw, "\n");
				}
				fclose(fpw);
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("Save completely.\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				continue;
			}
			else
			{
				printf("Wrong input! Please try again!\n");
				continue;
			}
		}			
	}
	// end
	printf("Thank you for your playing!! Hope you have a wonderfal day.\n");
	return 0;
}
