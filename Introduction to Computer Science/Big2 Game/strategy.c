#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int color(char *p)
{
	int j = 0;
	if(strcmp(p,"C") == 0) j = 1;
	else if(strcmp(p,"D") == 0) j = 2;
	else if(strcmp(p,"H") == 0) j = 3;
	else if(strcmp(p,"S") == 0) j = 4;
	
	return j;
}

int main(int argc, char *argv[])
{
    FILE *fp1 = fopen(argv[3], "r");
	char player[8], player1[8], current[5][5], type[2], must[5], must1[5], play[4][3];
	// 0: follow the former player, 1: whatever you want, 2: must contain
    char *token, *token1, *token2, c1[15], c2[65], card[13][5], card1[13][5], search[] = ",";
    int i = 0, player_nu = 0, w = 4, pl[4];
	// save the playe rnumber
	strcpy(player,argv[2]);

	for(i = 0; i < 5; i++) strcpy(current[i],"None"); // initialize
	// Open the file
	// Check whether the file exists or not    
	if(fp1 == NULL)
    {
        printf("Can not open the file.\n");
        exit(1);
    }
    else
    {
        fscanf(fp1, "%s%s", c1, c2); // read the file line by line
		strcpy(play[0], c2);
		fscanf(fp1, "%s%s", c1, c2);
		strcpy(play[1], c2);
		fscanf(fp1, "%s%s", c1, c2);
		strcpy(play[2], c2);
		fscanf(fp1, "%s%s", c1, c2);
		strcpy(play[3], c2);
		
		// my number 
		strcpy(player1,player);
		token = strtok(player1, "Player");
		player_nu = atoi(token);
		if(player_nu == 1) w = 0;
		else if(player_nu == 2) w = 1;
		else if(player_nu == 3) w = 2;
		else if(player_nu == 4) w = 3;
		for(i = 0; i < 4; i++) pl[i] = atoi(play[i]); // player has ? cards in hand

		fscanf(fp1, "%s%s", c1, c2); // hand card
		token = strtok(c2, search);  // spilt the string
		i = 0;
        while(token != NULL && i < pl[w])
        {
            strcpy(card[i], token);
			if(strlen(card[i]) == 4) card[i][4]='\0';
			else if(strlen(card[i]) == 3) card[i][3]='\0';
            token = strtok(NULL, search);
            i++;
        }
		for(i = 0; i < pl[w]; i++) strcpy(card1[i],card[i]);
		fscanf(fp1, "%s%s", c1, c2);
		strcpy(type, c2); // play type

		fscanf(fp1, "%s%s", c1, c2);
		strcpy(must, c2);
		strcpy(must1,must);
		fscanf(fp1, "%s%s", c1, c2); // current
		if(strcmp(c2,"None") != 0)
		{
			i = 0;
			token1 = strtok(c2, search); // spilt the string
			while(token1 != NULL && i < 5)
			{
				strcpy(current[i], token1);
				if(strlen(current[i]) == 4) current[i][4]='\0';
				else if(strlen(current[i]) == 3) current[i][3]='\0';
				token1 = strtok(NULL, search);
				i++;
			} 
		}
		fclose(fp1);
    }
	
	// open the file
	FILE *fp2 = fopen(argv[4], "a");	
	int ty, ca[13], mu = 0, cu[5] = {0,0,0,0,0}, co_ca[13], co_cu[5];
	
	for(i = 0; i < pl[w]; i++) // cards' color and number
	{
		token2 = strtok(card[i], "-");
		co_ca[i] = color(token2); 
		token2 = strtok(NULL, "-");
		ca[i] = atoi(token2);
		
	}
	for(i = 0; i < pl[w]; i++)
	{
		if(ca[i] == 2) ca[i] = 15; // set 2 and A in large number
		else if(ca[i] == 1) ca[i] = 14;
	}
	ty = atoi(type);
	
	if(strcmp(must,"None") != 0)
	{
		token2 = strtok(must, "-");
		token2 = strtok(NULL, "-");
		mu = atoi(token2); // mustcontain's number
		if(mu == 2) mu = 15;
		else if(mu == 1) mu = 14;
	}
	
	for(i = 0; i < 5; i++) // currents' number
	{
		if(strcmp(current[i],"None") != 0)
		{
			token2 = strtok(current[i], "-");
			co_cu[i] = color(token2);
			token2 = strtok(NULL, "-");
			cu[i] = atoi(token2);
		}
	}
	for(i = 0; i < 5; i++)
	{
		if(cu[i] == 2) cu[i] = 15; // set 2 and A in large number
		else if(cu[i] == 1) cu[i] = 14;
	}

	int j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, bool = 0, bool1 = 0;
	// bool: judge the card have been placed
	// bool1: check tne combination -> bool1 = 1(play 5), = 2(3 and 2) = 3(4 and 1), = 4(same color play 5)
	if(ty == 2) // assign
	{
		if(strcmp(must1,card1[0]) == 0) // judge your hand have mustcontain card or not
		{
			if(ca[0] == ca[1])
			{
				// play 4 and 1
				if(bool == 0 && ca[1] == ca[2] && ca[2] == ca[3])
				{
					fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[0], card1[1], card1[2], card1[3], card1[4]);
					bool = 1;
				}// play 3 and 2
				if(bool == 0 && ca[1] == ca[2])
				{
					for(i = 3; i < pl[w]-1; i++) 
					{
						if(bool == 0 && (ca[i] == ca[i+1]) && (ca[i] <= 13))
						{
							fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[0], card1[1], card1[2], card1[i], card1[i+1]);
							bool = 1;
							break;
						}
					}
				}
				if(bool == 0)
				{
					for(i = 2; i < pl[w]-2; i++) 
					{
						if(bool == 0 && (ca[i] == ca[i+1] && ca[i+1] == ca[i+2]) && (ca[i] <= 13))
						{
							fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[i], card1[i+1], card1[i+2], card1[0], card1[1]);
							bool = 1;
							break;
						}
					}
				}
			}				
			if(bool == 0) // play 5, first
			{
				for(i = 0; i < pl[w]; i++)
				{
					if(ca[0] == ca[i]-1) // second
					{
						for(j = i; j < pl[w]; j++)
						{
							if(ca[i] == ca[j]-1) // third
							{
								for(k = j; k < pl[w]; k++)
								{
									if(ca[j] == ca[k]-1) // forth
									{
										for(l = k; l < pl[w]; l++)
										{
											if(bool == 0 && ca[k] == ca[l]-1 && ca[l] != 15) // fifth
											{
												fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[0], card1[i], card1[j], card1[k], card1[l]);
												bool = 1;
												break;
											}
										}
										break;
									}
								}
								break;
							}
						}
						break;
					}
				}
			}
			if(bool == 0 && ca[0] == ca[1])
			{
				fprintf(fp2, "%s	place	%s,%s\n", player, card1[0], card1[1]); // play pair
				bool = 1;
			}
			if(bool == 0) 
			{
				fprintf(fp2, "%s	place	%s\n", player, card1[0]);
				bool = 1;
			}
		}
	}
	else if(ty == 1) // free
	{
		if(pl[w] >= 5)
		{
			printf("11\n");
			if(bool == 0)  // play 5
			{
				for(o = 0; o < pl[w]; o++) // first
				{
					printf("12\n");
					for(i = o; i < pl[w]; i++) // second
					{
						for(m = 0; m < pl[w]; m++)
						{
						printf("13,%d,%d\n",ca[o+m],ca[i]);
						if(ca[o+m] == ca[i]-1) 
						{
							printf("14,%d\n",ca[j]);
							for(j = i; j < pl[w]; j++) // third
							{
								if(ca[i] == ca[j]-1)
								{
									printf("15,%d\n",ca[k]);
									for(k = j; k < pl[w]; k++) // forth
									{
										if(ca[j] == ca[k]-1)
										{
											printf("16,%d\n",ca[l]);
											for(l = k; l < pl[w]; l++) // fifth
											{
												if(ca[k] == ca[l]-1 && ca[l] != 15)
												{
													printf("17,%d\n",ca[l]);
													if(co_ca[o+m] == co_ca[i] && co_ca[i] == co_ca[j] && co_ca[j] == co_ca[k] && co_ca[k] == co_ca[l])
													{
														if(bool == 0 && pl[w] <= 10)
														{
															fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+m], card1[i], card1[j], card1[k], card1[l]);
															bool = 1;
															break;
														}
														else break;
													}
													else if(bool == 0)
													{
														fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+m], card1[i], card1[j], card1[k], card1[l]);
														bool = 1;
														break;
													}
												}
											}
											break;
										}
									}
									break;
								}
							}
							break;
						}
						}
					}
					break;
				}
			}
			if(bool == 0 && pl[w] <= 8) // play 4 and 1
			{
				for(i = 0; i < pl[w]-3; i++)
				{
					if(bool == 0 && (pl[w] >= 5) && (ca[i] == ca[i+1]) && (ca[i+1] == ca[i+2]) && (ca[i+2] == ca[i+3]))
					{
						fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[i], card1[i+1], card1[i+2], card1[i+3], card1[0]);
						bool = 1;
						break;
					}
				}
			}
		}
		if(bool == 0 && pl[w] > 4) // play 3 and 2
		{
			printf("01\n");
			for(i = 0; i < pl[w]-2; i++) 
			{
				printf("02\n");
				printf("%d,%d,%d\n",ca[i],ca[i+1],ca[i+2]);
				if(ca[i] == ca[i+1] && ca[i+1] == ca[i+2] && ca[i] <= 14)
				{
					printf("03\n");
					for(j = 0; j < pl[w]-1; j++)
					{
						printf("04\n");
						if(bool == 0 && (ca[j] != ca[i]) && (ca[j] == ca[j+1]) && (ca[j] <= 13))
						{
							fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[i], card1[i+1], card1[i+2], card1[j], card1[j+1]);
							bool = 1;
							break;
						}
					}
					break;
				}
			}
		}
		if(bool == 0 && pl[w] > 1) // play pair
		{
			printf("05\n");
			for(i = 0; i < pl[w]-1; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(bool == 0 && ca[i] == ca[i+1] && ca[i] <= 13)
					{
						fprintf(fp2, "%s	place	%s,%s\n", player, card1[i], card1[i+1]);
						bool = 1;
						break;
					}
					if(bool == 0 && ca[i] == ca[i+1] && (pl[j] < 5 || pl[w] < 4) && j != w)
					{
						fprintf(fp2, "%s	place	%s,%s\n", player, card1[i], card1[i+1]);
						bool = 1;
						break;
					}
				}
			}
		}
		if(bool == 0) 
		{
			if(pl[w] < 3)
			{
				fprintf(fp2, "%s	place	%s\n", player, card1[pl[w]-1]);
				bool = 1;
			}
			else
			{
				fprintf(fp2, "%s	place	%s\n", player, card1[0]);
				bool = 1;
			}
		}
	}
	else // follow
	{
		if(pl[w] > 4 && strcmp(current[2],"None") == 0)
		{
			if(bool == 0) // play 4 and 1
			{
				for(i = 0; i < pl[w]-3; i++)
				{
					if((pl[w] >= 5) && (ca[i] == ca[i+1]) && (ca[i+1] == ca[i+2]) && (ca[i+2] == ca[i+3]))
					{
						for(j = 0; j < pl[w]; j++)
						{
							if(bool == 0 && ca[j] != ca[i])
							{
								fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[i], card1[i+1], card1[i+2], card1[i+3], card1[j]);
								bool = 1;
								break;
							}
						}
						break;
					}
				}
			}
			if(bool == 0)  // play 5
			{
				for(o = 0; o < pl[w]; o++) // first
				{
					for(i = o; i < pl[w]; i++) // second
					{
						for(m = 0; m < pl[w]; m++)
						{
						if(ca[o+m] == ca[i]-1)
						{
							for(j = i; j < pl[w]; j++) // third
							{
								if(ca[i] == ca[j]-1)
								{
									for(k = j; k < pl[w]; k++) // forth
									{
										if(ca[j] == ca[k]-1)
										{
											for(l = k; l < pl[w]; l++) // fifth
											{
												if(ca[k] == ca[l]-1 && ca[l] != 15)
												{
													if(bool == 0 && co_ca[o+m] == co_ca[i] && co_ca[i] == co_ca[j] && co_ca[j] == co_ca[k] && co_ca[k] == co_ca[l])
													{
														fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+m], card1[i], card1[j], card1[k], card1[l]);
														bool = 1;
														break;
													}
												}
											}
											break;
										}
									}
									break;
								}
							}
							break;
						}
						}
					}
					break;
				}
			}
		}
		if(bool == 0)
		{
		if((pl[w] > 4) && (strcmp(current[1],"None") != 0) && (strcmp(current[2],"None") != 0))
		{
			// play 4 and 1
			if((cu[0] == cu[1] && cu[1] == cu[2] && cu[2] == cu[3]) || (cu[0] == cu[1] && cu[1] == cu[2] && cu[2] == cu[4]) ||
			   (cu[0] == cu[1] && cu[1] == cu[3] && cu[3] == cu[4]) || (cu[0] == cu[2] && cu[2] == cu[3] && cu[3] == cu[4]))
			{
				bool1 = 3;
				for(o = 0; o < pl[w]-3; o++)
				{
					if(ca[o] > cu[0] && ca[o] == ca[o+1] && ca[o+1] == ca[o+2] && ca[o+2] == ca[o+3])
					{
						for(i = 0; i < pl[w]; i++)
						{
							if(bool == 0 && ca[i] != ca[o])
							{
								fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o], card1[o+1], card1[o+2], card1[o+3], card1[i]);
								bool = 1;
								break;
							}
						}
						break;
					}
				}
			}
			else if(cu[1] == cu[2] && cu[2] == cu[3] && cu[3] == cu[4])
			{
				bool1 = 3;
				for(o = 0; o < pl[w]-3; o++)
				{
					if(ca[o] > cu[1] && ca[o] == ca[o+1] && ca[o+1] == ca[o+2] && ca[o+2] == ca[o+3])
					{
						for(i = 0; i < pl[w]; i++)
						{
							if(bool == 0 && ca[i] != ca[o])
							{
								fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o], card1[o+1], card1[o+2], card1[o+3], card1[i]);
								bool = 1;
								break;
							}
						}
						break;
					}
				}
			}
			// play 3 and 2
			if(bool == 0 && bool1 == 0)
			{
				if((cu[0] == cu[1] && cu[1] == cu[2]) || (cu[0] == cu[1] && cu[1] == cu[3]) || (cu[0] == cu[1] && cu[1] == cu[4]) ||
  				   (cu[0] == cu[2] && cu[2] == cu[3]) || (cu[0] == cu[2] && cu[2] == cu[4]) || (cu[0] == cu[3] && cu[3] == cu[4]))
				{
					bool1 = 2;
					for(o = 0; o < pl[w]-2; o++)
					{
						if(ca[o] > cu[0] && ca[o] == ca[o+1] && ca[o+1] == ca[o+2])
						{
							
							for(m = 0; m < pl[w]-1; m++)
							{
								if(bool == 0 && ca[m] == ca[m+1] && ca[o] != ca[m] && ca[m] <= 13)
								{
									printf("51\n");
									fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o], card1[o+1], card1[o+2], card1[m], card1[m+1]);
									bool = 1;
									break;
								}
							}
							break;
						}
					}
				}
				else if((cu[1] == cu[2] && cu[2] == cu[3]) || (cu[1] == cu[2] && cu[2] == cu[4]) || (cu[1] == cu[3] && cu[3] == cu[4]))
				{
					bool1 = 2;
					for(o = 0; o < pl[w]-2; o++)
					{
						if(ca[o] > cu[1] && ca[o] == ca[o+1] && ca[o+1] == ca[o+2])
						{
							for(m = 0; m < pl[w]-1; m++)
							{
								if(bool == 0 && ca[o] != ca[m] && ca[m] == ca[m+1] && ca[m] <= 13)
								{
									printf("50\n");
									fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o], card1[o+1], card1[o+2], card1[m], card1[m+1]);
									bool = 1;
									break;
								}
							}
							break;
						}
					}
				}
				else if(cu[2] == cu[3] && cu[3] == cu[4])
				{
					bool1 = 2;
					for(o = 0; o < pl[w]-2; o++)
					{
						if(ca[o] > cu[2] && ca[o] == ca[o+1] && ca[o+1] == ca[o+2])
						{
							for(m = 0; m < pl[w]-1; m++)
							{
								if(bool == 0 && ca[m] == ca[m+1] && ca[o] != ca[m] && ca[m] <= 13)
								{
									printf("52\n");
									fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o], card1[o+1], card1[o+2], card1[m], card1[m+1]);
									bool = 1;
									break;
								}
							}
							break;
						}
					}
				}
			}
			if(bool == 0) // play 5
			{
				for(m = 0; m < 5; m++)
				{
					if(co_cu[0] == co_cu[1] && co_cu[1] == co_cu[2] && co_cu[2] == co_cu[3] && co_cu[3] == co_cu[4]) bool1 = 4;
					int check = 0;
					if(cu[m] > cu[0]) check++;
					if(cu[m] > cu[1]) check++;
					if(cu[m] > cu[2]) check++;
					if(cu[m] > cu[3]) check++;
					if(cu[m] > cu[4]) check++;
					
					if(check == 4 && bool1 == 0)
					{
						bool1 = 1;
						for(o = 0; o < pl[w]; o++)
						{
							for(i = o; i < pl[w]; i++)
							{
								for(n = 0; n < pl[w]; n++)
								{
									if(ca[o+n] == ca[i]-1) // second
									{
										for(j = i; j < pl[w]; j++)
										{
											if(ca[i] == ca[j]-1) // third
											{
												for(k = j; k < pl[w]; k++)
												{
													if(ca[j] == ca[k]-1) // forth
													{
														for(l = k; l < pl[w]; l++)
														{
															if(bool == 0 && ca[l] > cu[m] && ca[k] == ca[l]-1 && ca[l] != 15) // fifth
															{
																printf("53\n");
																fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+n], card1[i], card1[j], card1[k], card1[l]);
																bool = 1;
																break;
															}
															else if(bool == 0 && ca[l] == cu[m] && ca[k] == ca[l]-1 && ca[l] != 15)
															{
																if(co_ca[l] > co_cu[m])
																{
																	printf("54\n");
																	fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+n], card1[i], card1[j], card1[k], card1[l]);
																	bool = 1;
																	break;
																}
															}
														}
														break;
													}
												}
												break;
											}	
										}
										break;
									}
								}
							}
							break;	
						}
						break;
					}
					if(check == 4 && bool1 == 4) // same color play 5
					{
						for(o = 0; o < pl[w]; o++)
						{
							for(i = o; i < pl[w]; i++)
							{
								for(n = 0; n < pl[w]; n++)
								{
									if(ca[o+n] == ca[i]-1 && co_ca[o+n] == co_ca[i]) // second
									{
										for(j = i; j < pl[w]; j++)
										{
											if(ca[i] == ca[j]-1 && co_ca[i] == co_ca[j]) // third
											{
												for(k = j; k < pl[w]; k++)
												{
													if(ca[j] == ca[k]-1 && co_ca[j] == co_ca[k]) // forth
													{
														for(l = k; l < pl[w]; l++)
														{
															if(bool == 0 && ca[l] > cu[m] && ca[k] == ca[l]-1 && ca[l] != 15 && co_ca[k] == co_ca[l]) // fifth
															{
																printf("53\n");
																fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+n], card1[i], card1[j], card1[k], card1[l]);
																bool = 1;
																break;
															}
															else if(bool == 0 && ca[l] == cu[m] && ca[k] == ca[l]-1 && ca[l] != 15 && co_ca[k] == co_ca[l])
															{
																if(co_ca[l] > co_cu[m])
																{
																	printf("54\n");
																	fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+n], card1[i], card1[j], card1[k], card1[l]);
																	bool = 1;
																	break;
																}
															}
														}
														break;
													}
												}
												break;
											}	
										}
										break;
									}
								}
							}
							break;	
						}
						break;
					}
				}
			}
			if(bool == 0 && bool1 == 1) // play 3 and 2, current is play 5
			{
				for(o = 0; o < pl[w]-2; o++)
				{
					if(ca[o] == ca[o+1] && ca[o+1] == ca[o+2])
					{
						for(m = 0; m < pl[w]-1; m++)
						{
							if(bool == 0 && ca[m] == ca[m+1] && ca[o] != ca[m] && ca[m] <= 13)
							{
								printf("51\n");
								fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o], card1[o+1], card1[o+2], card1[m], card1[m+1]);
								bool = 1;
								break;
							}
						}
						break;
					}
				}
			}
			if(bool == 0 && bool1 <= 2) // play 4 and 1, current is play 5 or 3 and 2
			{
				for(i = 0; i < pl[w]-3; i++)
				{
					if((pl[w] >= 5) && (ca[i] == ca[i+1]) && (ca[i+1] == ca[i+2]) && (ca[i+2] == ca[i+3]))
					{
						for(j = 0; j < pl[w]; j++)
						{
							if(bool == 0 && ca[j] != ca[i])
							{
								fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[i], card1[i+1], card1[i+2], card1[i+3], card1[j]);
								bool = 1;
								break;
							}
						}
						break;
					}
				}
			}
			if(bool == 0 && bool1 <= 3) // same color play 5, current is play 5 or 3 and 2 or 4 and 1
			{
				for(o = 0; o < pl[w]; o++) // first
				{
					for(i = o; i < pl[w]; i++) // second
					{
						for(m = 0; m < pl[w]; m++)
						{
						if(ca[o+m] == ca[i]-1)
						{
							for(j = i; j < pl[w]; j++) // third
							{
								if(ca[i] == ca[j]-1)
								{
									for(k = j; k < pl[w]; k++) // forth
									{
										if(ca[j] == ca[k]-1)
										{
											for(l = k; l < pl[w]; l++) // fifth
											{
												if(ca[k] == ca[l]-1 && ca[l] != 15)
												{
													if(bool == 0 && co_ca[o+m] == co_ca[i] && co_ca[i] == co_ca[j] && co_ca[j] == co_ca[k] && co_ca[k] == co_ca[l])
													{
														fprintf(fp2, "%s	place	%s,%s,%s,%s,%s\n", player, card1[o+m], card1[i], card1[j], card1[k], card1[l]);
														bool = 1;
														break;
													}
												}
											}
											break;
										}
									}
									break;
								}
							}
							break;
						}
						}
					}
					break;
				}
			}
			if(bool == 0) 
			{
				printf("55\n");
				fprintf(fp2, "%s	pass\n", player);
				bool = 1;
			}
		}
		else if((pl[w] > 1) && (strcmp(current[1],"None") != 0) && (strcmp(current[2],"None") == 0)) // play pair
		{
			if(bool == 0 && cu[0] < ca[pl[w]-1]) // keep 3
			{
				for(i = 0; i < pl[w]; i++)
				{
					if((i < pl[w]-2 && ca[i] == ca[i+1] && ca[i+1] == ca[i+2]) ||
    				   (i > 1 && ca[i] == ca[i-1] && ca[i-1] == ca[i-2]) ||
					   (i > 0 && i < pl[w]-1 && ca[i-1] == ca[i] && ca[i] == ca[i+1])) continue;
					else if(cu[0] < ca[i])
					{
						if(bool == 0 && i < pl[w]-1 && ca[i] == ca[i+1])
						{
							fprintf(fp2, "%s	place	%s,%s\n", player, card1[i], card1[i+1]);
							bool = 1;
							break;
						}
						else continue;
					}
					else if(cu[0] == ca[i]) // same number
					{
						if((co_cu[0] < co_ca[i]) && (co_cu[1] < co_ca[i]))
						{
							if(bool == 0 && (i > 0) && (ca[i] == ca[i-1]))
							{
								fprintf(fp2, "%s	place	%s,%s\n", player, card1[i-1], card1[i]);
								bool = 1;
								break;
							}
							else if(bool == 0 && (i < (pl[w]-1)) && (ca[i] == ca[i+1]))
							{
								fprintf(fp2, "%s	place	%s,%s\n", player, card1[i], card1[i+1]);
								bool = 1;
								break;
							}
						}
						else continue;
					}
				}
			}
			if(cu[0] < ca[pl[w]-1]) // no 2, spilt
			{
				for(i = 0; i < pl[w]; i++)
				{
					if(cu[0] < ca[i])
					{
						if(bool == 0 && i < pl[w]-1 && ca[i] == ca[i+1])
						{
							fprintf(fp2, "%s	place	%s,%s\n", player, card1[i], card1[i+1]);
							bool = 1;
							break;
						}
						else continue;
					}
					else if(cu[0] == ca[i]) // same number
					{
						if((co_cu[0] < co_ca[i]) && (co_cu[1] < co_ca[i]))
						{
							if(bool == 0 && (i > 0) && (ca[i] == ca[i-1]))
							{
								fprintf(fp2, "%s	place	%s,%s\n", player, card1[i-1], card1[i]);
								bool = 1;
								break;
							}
							else if(bool == 0 && (i < (pl[w]-1)) && (ca[i] == ca[i+1]))
							{
								fprintf(fp2, "%s	place	%s,%s\n", player, card1[i], card1[i+1]);
								bool = 1;
								break;
							}
						}
						else continue;
					}
				}
			}
			if(bool == 0 && (cu[0] == ca[pl[w]-1]) && (ca[pl[w]-1] == ca[pl[w]-2]))
			{
				if((co_cu[0] < co_ca[pl[w]-1]) && (co_cu[1] < co_ca[pl[w]-1]))
				{
					if(ca[pl[w]-1] == ca[pl[w]-2]) 
					{
						fprintf(fp2, "%s	place	%s,%s\n", player, card1[pl[w]-2], card1[pl[w]-1]);
						bool = 1;
					}
				}
			}
			if(bool == 0)
			{
				fprintf(fp2, "%s	pass\n", player); // current > hand card -> pass
				bool = 1;
			}
		}
		else if((strcmp(current[0],"None") != 0) && (strcmp(current[1],"None") == 0) && (strcmp(current[2],"None") == 0)) // play single
		{
			if(ca[pl[w]-1] == 15 && cu[0] < ca[pl[w]-1])
			{
				for(j = 0; j < 4; j++)
				{
					if(bool == 0 && pl[j] < 5 && j != w)
					{
						fprintf(fp2, "%s	place	%s\n", player, card1[pl[w]-1]);
						bool = 1;
						break;
					}
				}
			}
			if(bool == 0 && cu[0] < ca[pl[w]-1]) // keep pair
			{
				for(i = 0; i < pl[w]; i++)
				{
					if((i < pl[w]-1 && ca[i] == ca[i+1]) || (i > 0 && ca[i] == ca[i-1])) continue;
					else if(bool == 0 && cu[0] < ca[i])
					{
						fprintf(fp2, "%s	place	%s\n", player, card1[i]);
						bool = 1;
						break;
					}
					else if(cu[0] == ca[i]) // same number
					{
						if(bool == 0 && co_cu[0] < co_ca[i])
						{
							fprintf(fp2, "%s	place	%s\n", player, card1[i]);
							bool = 1;
							break;
						}
						else continue;
					}
				}
			}
			if(bool == 0) // no single, spilt pair
			{
				if(cu[0] < ca[pl[w]-1])
				{
					for(i = 0; i < pl[w]; i++)
					{
						if(bool == 0 && cu[0] < ca[i])
						{	
							fprintf(fp2, "%s	place	%s\n", player, card1[i]);
							bool = 1;
							break;
						}
						else if(cu[0] == ca[i]) // same number
						{
							if(bool == 0 && co_cu[0] < co_ca[i])
							{
								fprintf(fp2, "%s	place	%s\n", player, card1[i]);
								bool = 1;
								break;
							}
							else continue;
						}
					}
				}
			}
			if(bool == 0 && cu[0] == ca[pl[w]-1])
			{
				if(co_cu[0] < co_ca[pl[w]-1]) 
				{
					fprintf(fp2, "%s	place	%s\n", player, card1[pl[w]-1]);
					bool = 1;
				}
				else 
				{
					fprintf(fp2, "%s	pass\n", player);
					bool = 1;
				}
			}
			if(bool == 0)
			{
				fprintf(fp2, "%s	pass\n", player); // current > hand card -> pass
				bool = 1;
			}
		}
		else fprintf(fp2, "%s	pass\n", player);
		}
	}
	fclose(fp2);
	return 0;
}
