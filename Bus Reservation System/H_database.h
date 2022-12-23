#include<stdio.h>
#include<string.h>

void add_info(int a, int b)
{
    char arr[8][30] = {"Mirpur", "Uttara", "Banani", "Gulshan",
                       "Bashundhara", "Badda", "Mohammadpur", "Dhanmondi"};
    char str1[30], str2[30];

    FILE *fptr;

    fptr = fopen("history.txt", "a");

    if(fptr==NULL)
        printf("Error finding history file");

    strcpy(str1, arr[a-1]);
    strcpy(str2, arr[b-1]);
    fprintf(fptr, "%s to %s\n", str1, str2);
    fflush(stdin);

    fclose(fptr);
}

void readhis(void)
{
    FILE * fptr;
    char buffer[255];

    fptr = fopen("history.txt", "r");

    if(fptr==NULL)
        printf("Error opening history file");


    while((fgets(buffer, 255, fptr))!=NULL)
    {
        printf("%s\n", buffer);
    }

    fclose(fptr);
}
