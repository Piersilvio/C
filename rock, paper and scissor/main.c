#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int ch = 0, j = 0;
	char *string[3] = { "rock", "paper", "scissor" };

	srand (time(NULL));

	setbuf(stdout,NULL);
	j = rand()%3;
	//printf("%s\n", string[j]);


    printf("Rock, paper and scissor! \n");
    printf(":::::::::::::::::::::::  \n");
    printf("rules! \n");
    printf("1 - rock vs paper -> paper win \n");
    printf("2 - rock vs scissor -> rock win \n");
    printf("3 - scissor vs paper -> scissor win \n");
    printf(":::::::::::::::::::::::: \n");
    printf("player (1 - rock)(2 - paper)(3 - scissor): ");
    scanf("%d", &ch);
    printf(":::::::::::::::::::::::: \n");

    if((ch == 3) && (strcmp(string[j], "rock") == 0)){

    	printf(":: CPU won! \n");

    }else if((ch == 1) && (strcmp(string[j], "paper") == 0)){

    	printf(":: CPU won! \n");

    }else if((ch == 2) && (strcmp(string[j], "scissor") == 0)){

    	printf(":: CPU won! \n");
    }else{

    	printf(":: YOU won! \n");
    }

    system("pause");
    return 0;
}
