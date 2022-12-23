#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct login{
  char fname[30];
  char lname[30];
  char username[30];
  char password[20];
};

void login (void);
void registration(void);

void Log_reg(void)
{
    int option;

    printf("Welcome to NSU Bus Service.\n");
    printf("Press '1' to register\nPress '2' to login\n\n");
    scanf("%d",&option);

    getchar();

    if(option == 1){
        system("CLS");
        registration();
    }
    else if(option == 2){
        system("CLS");
        login();
    }
}
void login (void){
  char username[30],password[20];
  FILE *log;

  log = fopen("login.txt","r");
  if(log == NULL){
    fputs("Error at opening File!",stderr);
     exit(1);
  }
  struct login l;

  printf("\nPlease Enter your login credentials below\n\n");
  printf("Username:");
  fgets(username, 30, stdin);
  printf("\nPassword:");
  printf("\n");
  fgets(password, 20, stdin);

  while(fread(&l,sizeof(l),1,log)){
    if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){
        printf("\nSuccessful Login\n");
    }
    else{
        printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
    }
  }
   fclose(log);
    system("CLS");
   return;
 }

   void registration(void){

      char firstname[15];
      FILE *log;

      log=fopen("login.txt","w");
      if(log == NULL){
        fputs("Error at opening File!",stderr);
         exit(1);
      }

      struct login l;
      printf("\nWelcome to NSU Bus Service. You need to enter some details for registration.\n\n");
      printf("\nEnter first name:\n");
      scanf("%s", l.fname);
      printf("\nEnter surname:\n");
      scanf("%s", l.lname);

      printf("Thank you.\nNow please choose a Username and password as credentials for system login.\nEnsure the username is no more than 30 characters log.\nensure yor password is least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");

      printf("\nEnter username:\n");
      scanf("%s", l.username);
      printf("\nEnter password:\n");
      scanf("%s", l.password);

      fwrite(&l,sizeof(l),1,log);
      fclose(log);

      printf("\nConfirming details...\n...\nWelcome,%s\n\n", firstname);
      printf("\nRegistration successful!\n");
      printf("Press any key to continue ...");
      getchar();
      system("CLS");
      login();
}
