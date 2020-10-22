#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	static const char filename[] ="CardSet.txt";
	FILE *fp = fopen(filename, "r");
	char *token;
	char *search = ",";
	char result[52][5];
	int i=0;
	
	/*
		Open the CardSet file.
		Check whether the file exists or not.
	*/
	
	if(fp == NULL){
		printf("Can not open the file.\n");
		exit(1);
	}
	else{
		
		/*
			Read the file line by line
		*/
		
		char line[60];
		while( fgets(line, sizeof line, fp) != NULL){
			
			/*
				Split the line by comma and store into the result.
				token: temporary variable for storing the split data
				search: Store the word you want to split with
			*/
			
			token = strtok(line, search);
			while(token != NULL && i<52){
				strcpy(result[i], token);
				result[i][4]='\0';
				token = strtok(NULL, search);
				i++;
			}
		}
	}
	return 0;
}

