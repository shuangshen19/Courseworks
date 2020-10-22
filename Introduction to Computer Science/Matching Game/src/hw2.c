#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	printf("Welcome to the Matching Game!\n");
    printf("Hope you have a great time playing!\n");
    printf("Following are the rules.\n");
    printf("Rule1:Please input coordinate to choose two cards\n");
    printf("      EX.coordinate(12,04),(13,01)expressed as 12,04,13,01\n");
    printf("      If the number of the chosen cards are equal -> get one point\n");
	printf("      If the number of the chosen cards aren't equal -> no point\n");
    printf("Rule2:Player can continue playing until he gets wrong.\n");
    printf("Rule3:If the cards are the same, they would be remove.\n");
    printf("      If they not the same, they would be covered");
    printf(" after showing the value\n");
    printf("Rule4:Input exit can end the game\n");
    printf("Now, let's get started!\n\n");

	// initialize
	static const char filename[] ="CardSet.txt";
    FILE *fp = fopen(filename, "r+");
    char *token, *token1, *token2, *token3, search[] = ",";
    char result[52][5];
	char chart[52][8] = {"(01,01)","(02,01)","(03,01)","(04,01)","(05,01)","(06,01)","(07,01)","(08,01)","(09,01)","(10,01)","(11,01)","(12,01)","(13,01)",
	                     "(01,02)","(02,02)","(03,02)","(04,02)","(05,02)","(06,02)","(07,02)","(08,02)","(09,02)","(10,02)","(11,02)","(12,02)","(13,02)",
						 "(01,03)","(02,03)","(03,03)","(04,03)","(05,03)","(06,03)","(07,03)","(08,03)","(09,03)","(10,03)","(11,03)","(12,03)","(13,03)",
						 "(01,04)","(02,04)","(03,04)","(04,04)","(05,04)","(06,04)","(07,04)","(08,04)","(09,04)","(10,04)","(11,04)","(12,04)","(13,04)"};
    int i = 0, j = 0, game = 0, win = 0, score[] = {0,0};
	
	// create a loop
	while(game == 0)
	{
	    // Open the CardSet file.
	    // Check whether the file exists or not.    
	    if(fp == NULL)
        {
            printf("Can not open the file.\n");
            exit(1);
        }
        else
        {
            // Read the file line by line
            char line[60];
            while(fgets(line, sizeof line, fp) != NULL)
            {
                // Split the line by comma and store into the result.
                // token: temporary variable for storing the split data
                // search: Store the word you want to split with		
                token = strtok(line, search);
                while(token != NULL && i < 52)
                {
                    strcpy(result[i], token);
                    result[i][4]='\0';
                    token = strtok(NULL, search);
                    i++;
                }
            }
        }
		// print the coordinate
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	    for(i = 0; i < 52; i++)
	    {
	        printf("%s ",chart[i]);
            if(i==12||i==25||i==38||i==51) printf("\n");		
	    }
	    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        int spot[4];
	    char card[20], place[4][3];
		// scan input
        printf("Please choose two cards: ");
        scanf("%s",card);
		printf("\n");
		if(strcmp(card,"exit") == 0) // exit function
	    {
	    	game = 1;
	    	break;
	    }
		else if(strlen(card)!=11) // default function
		{
			printf("Wrong input! Please try again!\n");
			continue;
		}
		else
		{
			token1 = NULL;
			token1 = strtok(card,search);
			j = 0;
    	    // Split the input by comma and store into place
    	    while(token1 != NULL && j < 4)
    	    {
    	        strcpy(place[j], token1);
     	        place[j][2]='\0';
    	        token1 = strtok(NULL,search);
    	        j++;
   	        } 
			// change char to int
			spot[0] = atoi(place[0]);
			spot[1] = atoi(place[1]);
			spot[2] = atoi(place[2]);
			spot[3] = atoi(place[3]);
			if(spot[0] > 13 || spot[1] > 4 || spot[2] > 13 || spot[3] > 4)
			{
				printf("Wrong coordinate input! Please try again!\n");
			    continue;
			}
		}
		// calculate the spot
		int a = (spot[1]-1)*13+spot[0], b = (spot[3]-1)*13+spot[2];
		char open[52][5];
		
		// judge the cards whether have been chosen or not
		if(strcmp(chart[a-1],"  NULL ") != 0 && strcmp(chart[b-1],"  NULL ") != 0)
	    {
		    int t = 0;
		    char result_c1[2][3],result_c2[2][3];
		    int result_int[52];
			// store the number of card a
		    if(strlen(result[a-1]) != 1)
		    {
			    strcpy(open[a-1],result[a-1]);
		    	token2 = NULL;
		    	token2 = strtok(result[a-1],"-");
		    	while(token2 != NULL && t < 2)
		    	{
			    	strcpy(result_c1[t], token2);
		    		result_c1[0][1]='\0';
		    		token2 = strtok(NULL,"-");
			    	t++;
			    }
			    result_int[a-1] = atoi(result_c1[1]);
		    }
		    // store the number of card b
		    if(strlen(result[b-1]) != 1)
		    {
		    	strcpy(open[b-1],result[b-1]);
			    t = 0;
			    token3 = NULL;
			    token3 = strtok(result[b-1],"-");
			    while(token3 != NULL && t < 2)
			    {
			    	strcpy(result_c2[t], token3);
			    	result_c2[0][1]='\0';
			    	token3 = strtok(NULL,"-");
			    	t++;
			    }
			    result_int[b-1] = atoi(result_c2[1]);
		    }
	
		    printf("The card you choose(%02d,%02d): %s\n",spot[0],spot[1],open[a-1]);
		    printf("The card you choose(%02d,%02d): %s\n",spot[2],spot[3],open[b-1]);
			// judge the cards are equal or aren't equal
	    	if(result_int[a-1] == result_int[b-1]) 
        	{	
	        	score[win]++;
				printf("\nCARDS MATCH!!\n");
				printf("Player1: %d\n",score[0]);
				printf("Player2: %d\n\n",score[1]);
				strcpy(chart[a-1],"  NULL ");
	        	strcpy(chart[b-1],"  NULL ");
	        }
			else 
	        {
				// not equal -> change player 
				printf("\nNO MATCH!\n");
				printf("Player1: %d\n",score[0]);
				printf("Player2: %d\n",score[1]);
	        	if(win == 0) 
		    	{
			    	win = 1;
			    	printf("It's turn to Player2.\n\n");
			    }
	    	    else 
			    {
			    	win = 0;
			    	printf("It's turn to Player1.\n\n");
			    }
	        }
	    }
	    else printf("The cards you choose was already chosen! Please try again!\n");
		// judge the cards have all been removed
		int k = 1;
		for(i = 0; i < 52; i++)
		{
			if(strcmp(chart[i],"  NULL ") == 0) 
			{
				k++;
				if(k==52) 
				{
					game = 1;
					break;
				}
				else game = 0;
			}
		}
	}
	// end
	printf("Player1 gets %d points\n",score[0]);
	printf("Player2 gets %d points\n",score[1]);
	if(score[0]-score[1] > 0) printf("The winner is Player1!\n");
	else if (score[0]-score[1] < 0) printf("The winner is Player2!\n");
	else printf("The game is no winner, it's a tie!\n");
	printf("Thank you for your playing!\n");
	return 0;
}
