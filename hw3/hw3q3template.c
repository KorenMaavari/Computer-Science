#include <stdio.h>
#include <stdlib.h>

int main()
{
    int question;
    scanf("%d",&question);
    switch (question)
    {
    case 1 :
        printf("The answer to question 1 is ???\n");
        break;
    case 2 :
        printf("The answer to question 2 is ???\n");
        break;
    case 3 :
        printf("The answer to question 3 is ???\n");
        break;
    case 4 :
        printf("The answer to question 4 is ???\n");
        break;
    case 5 :
        printf("The answer to question 5 is ???\n");
        break;
    case 6 :
        printf("The answer to question 6 is ???\n");
        break;
    default :
        printf("Error!\n");
        break;
    }
    return 0;
}