#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeSpaces(char []);
int KnoledgeBase(char*[]);
int getInput(char[]);

int removeSpaces(char text[128])
{ 
	 char  blank[1000];
   int c = 0, d = 0;
 
   while (text[c] != '\0') {
      if (text[c] == ' ') {
		  text[c] = '_';
         int temp = c + 1;
         if (text[temp] != '\0') {
            while (text[temp] != ' ' && text[temp] != '\0') {
               if (text[temp] == ' ') {
				   text[temp] = '_';
                  c++;
               }  
               temp++;
            }
         }
      }
      blank[d] = text[c];
      c++;
      d++;
   }
 
   blank[d] = '\0';
	     const char command[] = "espeak ";		
		strcat(command,blank);
		system(command);
}
int getInput(char  input[128])
{
	char  array[128];
	FILE *fp=fopen("data.txt", "r+");
	if(!fp)
	{
		printf("ERROR: No Directory To Read Answers");
	}
	
	while(!feof(fp))
	{
		fgets(array,128,fp);
		if(strncmp(array,input,strlen(input))==0)
		{
			fgets(array,128,fp);
			printf("%s",array);
			removeSpaces(array);
			
		}
		
	}
	return 0;

}
int main()
{
	char input[128];
	printf("Hello, Welcome\n This is chatbot v1.0\n>>Hi\n");

	do{
		printf(">>");
		gets(input);
		getInput(input);
	}while(1);	
	return 0;
}
