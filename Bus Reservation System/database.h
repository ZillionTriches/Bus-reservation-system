#include<stdio.h>


void get_info(int b[])
{
    FILE *fptr;
    int i;


    fptr = fopen("data.txt", "r");

    if(fptr==NULL)
        printf("Error opening file");

    i=0;
    while(!feof(fptr))
    {
        fscanf(fptr, "%d", &b[i]);
        i++;
    }

    fclose(fptr);

}


int seatbook(int a)
{
    int i, seat_info[40];
    FILE *infile;

    infile = fopen("data.txt", "r");

    if(infile==NULL)
    {
        printf("Error opening file(1).");
    }

    i=0;
    while(!feof(infile))
    {
        fscanf(infile, "%d", &seat_info[i]);
        i++;
    }

    fclose(infile);

    if(seat_info[a-1] == 0)
    {
        seat_info[a-1] += 1;
    }
    else if(seat_info[a-1]==1)
        return 10;

    infile = fopen("data.txt", "w");

    if(infile==NULL)
        printf("File open unsuccessful(2)");

    for(i=0; i<40; i++)
    {
        fprintf(infile, "%d\n", seat_info[i]);
    }

    fclose(infile);

    return 0;
}

