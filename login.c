#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SiZE
#define MAX 30
int login(); 
int reg();
int getch();
struct login {
	char name[MAX];
	char level[MAX];
	char department[MAX];
	char regNo[MAX];
	char email[MAX];
};

char database[MAX];
int main()
{
	
system("clear");
login();

}

int login()
{
	char name[MAX];
	
	char department[MAX];
	char regNo[MAX];
	char email[MAX];
	struct login details;
	int reg1=0,i=0;
	FILE *file;
	file = fopen("database.csv","r");
	if(file==NULL)
	{
	   reg();
	  
	}
	system("clear");
	printf("\n\n\t************************************");

	printf("\n\t WELCOME TO THE LOGIN PAGE\n");
	printf("\n Enter your level:\n 100 for 100level\n 200 for 200level and so on\n");
	scanf("%s",database);
	printf("\n\t Enter your email:\t");
	scanf("%s",email);
	reg:
	printf("\n\t Enter your Reg Number:\t");
	scanf("%s",regNo);
	if(strlen(regNo)<10)
         { 
           printf("\n\t **Reg number too short\n\n\n");
           i=i+1;
            if(i==3)
           {goto not;}
           else 
           {goto reg;}
           
         }
          else
          {
		while(fscanf(file,"%[^\b]\n",details.regNo)==1)
	   	 {
	       
		if(strstr(details.regNo,regNo))
		   {
		   
		   	 printf("\n\t ***********************\n");
		   	printf("\n\t Login Successful\n");
		   	 printf("\n\t ***********************\n\n");
		   	getch();
		   	return 1;
			
		   } 
	       
		}
	}
		
	 if(strstr(details.regNo,regNo)==NULL)
		   {   not:
		   	printf("\n\n\t ***You are not registered***\n\n Press 1 to Register\n");
			scanf("%d",&reg1);
			//break;
		   } 
	    
	getch();
	  
	  fclose(file);
	if(reg1==1) 
	  reg();
}
int reg()
{
	int i;
	struct login details;
	
	system("clear");
	printf("\n\n\t************************************\n");

	printf("\n\t WELCOME TO THE REGISTRATION PAGE\n");
	FILE *file;
	file = fopen("database.csv","a");	
	 if ( file == NULL )

    {

        file=fopen("database.csv","w");
     }
        if(file==NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            getch();
            return 0;
            }
	printf("\n\t Enter your level:\n 100 for 100level\n 200 for 200level and so on\n");
	scanf("%s",details.level);
	printf("\n\t Enter your Reg Number:\t");
	scanf("%s",details.regNo);
	fprintf (file, "%s, ",details.regNo);
	printf("\n\t Enter your Name:\t");
	getch();
	scanf("%s",details.name);
	fprintf (file, "%s, ",details.name);
	printf("\n\t Enter your Department:\t");
	getch();
	scanf("%s",details.department);
	fprintf (file, "%s, ",details.department);
	printf("\n\t Enter your email:\t");
	scanf("%s",details.email);
	fprintf (file, "%s, ",details.email);
    fclose(file);
    printf("\n\t ***********************\n"); 
    printf("\n\t Registation Successful\n"); 
     printf("\n\t ***********************\n\n"); 
     int one; 
       printf("\n\t press 1 to go to login page\n\n"); 
       scanf("%d",&one);
       if(one==1)
       {
       	//login();  
       	 printf("\n\t Reload to login\n\n\n");
	   return 0;
       }
}

int getch()
{
	char buf[100];
	int bufp=0;
	return (bufp>0)?buf[--bufp]:getchar();
}
    
