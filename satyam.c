#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct members
{
 int id;
 char name[30];
 int number;
}member;

void password();
void insert();
void deletefile();
void disp();
int avlId(int);
void mainmenu();

int main()
{
 password();
 return 0;
}

void password()
 {
    char str1[20];  
    char str2[20];   
    int pswd,value;
	
	  printf("\n \t\t*************************************************\n");
    printf("\n \t\t\t ADMIN LOGIN \n");
    printf("\n \t\t*************************************************\n");
    printf("\n \t\t\t USER NAME:-");
    gets(str1);
    printf("\n \t\t\t PASSWORD:-");
    gets(str2);
    value=strcmp(str1,str2);
    if(strcmp(str1,"satyam")==0)
    {
  	if(strcmp(str2,"1234")==0)
	  {
    printf("\n\n\n\t\tPassword matched!!");
    printf("\n\n\tPress any key to countinue.....");
    getch();
    mainmenu();
	  }
	  else
	  {
	  	printf("Wrong Password");	
                getch();  	
	  }
  }
  else
  {
  	printf("Wrong User Name");
        getch();
  }
}

void mainmenu()
{
system("cls");
int i;
printf(" \n\t\tMAIN MENU \n ");
printf("\n \t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
printf("\n<1> Add Members   ");
printf("\n<2> Delete Members Details");
printf("\n<3> View Member's list");
printf("\n<4> Developer Detail");
printf("\n<5> Close Application");
printf("\n \t\t*************************************************\n");
printf("\nEnter your choice:");

switch(getch())
{
case '1':
insert();
break;
case '2':
deletefile();
break;
case '3':
disp();
break;
case '4':
printf("\n \t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
 printf("This is a Gym Managment System Develop By SATYAM RATHORE from LNCT Bhopal");
 printf("\n\n\tPress any key to countinue.....");
 getch();
 mainmenu();
break;
case '5':
{
system("cls");
exit(0);
}
default:
{
printf("\n \aWrong Entry!!Please re-entered correct option");
printf("\n\n\tPress any key to countinue.....");
getch();
mainmenu();
}
}
}
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no   :");
 scanf("%d", &member.id);
 printf("Enter the Name      :");
 scanf("%s", &member.name);
 printf("Enter the number:");
 scanf("%d", &member.number);
 fwrite(&member, sizeof(member), 1, fp);
 fclose(fp);
printf("\n\n\tPress any key to countinue.....");
getch();
mainmenu();
}

void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRoll Number\tName\tNumber\n\n");
 while (fread(&member, sizeof(member), 1, fp1))
 printf("  %d\t\t%s\t%d\n", member.id, member.name, member.number);
 fclose(fp1);
 printf("\n\n\tPress any key to countinue.....");
 getch();
 mainmenu();
}

void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Roll no you want to delete :");
 scanf("%d", &r);
 if (avlId(r) == 0)
  printf("Roll no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&member, sizeof(member), 1, fpo))
  {
   s = member.id;
   if (s != r)
    fwrite(&member, sizeof(member), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&member, sizeof(member), 1, fpt))
  fwrite(&member, sizeof(member), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
  printf("\n\n\tPress any key to countinue.....");
  getch();
  mainmenu();
 }
}

int avlId(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&member, sizeof(member), 1, fp);

  if (rno == member.id)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}

