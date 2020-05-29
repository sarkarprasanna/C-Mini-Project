#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>

//structure for user data
struct user{
    char username[10];
    char password[10];
	char name[40];
    char address[40];
    char nationality[8];
    char car_taken[3];
}*pUser;

struct rate_us{
    char stars[5];
    char suggestions[40];
}*sUser;
void screenheader();
void intro();
void userlogin();
void welcome();
void car(char[]);
void function(char[],int);
void tutorials();
void rating();
void package();
void profile(char[]);
void portal(char[]);
void bike();
void return_car();

//function to print introductory message
void welcome()
{
   printf("\n                     ::::::::::::::::::::::::::::::::::::::::::::::");
   printf("\n                     ::          ________________________        ::");  
   printf("\n                     ::         /************************\\      ::");
   printf("\n                     ::        /**************************\\     ::");
   printf("\n                     ::  _____/****************************|***  ::");
   printf("\n                     :: |********|      WELCOME      |*****|***  ::");
   printf("\n                     :: |********|         TO        |*****|***  ::");
   printf("\n                     :: |********|    APNA    CAR    |*****|     ::");
   printf("\n                     :: \\********************************./     ::");
   printf("\n                     ::    ******                 ******         ::");
   printf("\n                     ::     ****                   ****          ::");
   printf("\n                     ::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n\n                           Press any key to continue\n");
   getch();
   system("cls");
   sleep(1);	//function which waits for n seconds
   printf("\nProgram is starting, please wait....\n");
   sleep(1);
   printf("\nLoading files...\n");
   sleep(1);
   system("cls");
}

//function for user login
void userlogin(void)
{

    FILE *fp;
    char uName[10], pwd[10];
    int i,a=0;
    char c,b;
	pUser=(struct user *)malloc(sizeof(struct user));
    
    printf("                                  WELCOME TO APNI CAR RENTAL SERVICE");
    printf("\n\n\n\n\n\t\t\t1.Login Through An Existing Account\n\t\t\t2. Create New account\n");
    printf("\n\n\t\t\tEnter your choice==> ");
    scanf("%d",&i);
    system("cls");
    switch(i){
        case 1:
        		printf("\n\n\t\t\tLOGIN TO APNI CAR\n\n");
             	if ((fp=fopen("user.txt", "r+")) == NULL) 
                {
                	if ((fp=fopen("user.txt", "w+")) == NULL) 
                	{
                    	printf ("Could not open file\n");
                    	exit (1);
                	}
            	}
            	printf("Username: ");
            	scanf("%9s",uName);
            	printf("Password: ");
            	scanf("%9s",pwd);
            	while (fread(pUser, sizeof(struct user), 1, fp) == 1) 
            	{
                  	if( strcmp ( pUser->username, uName) == 0 && strcmp ( pUser->password, pwd) == 0)
                   	{
                      	a=1;
                      	break;
                   	}
            	}
                if(a==1)
                {
                    printf ("Congratulations, you are succesfully logged in!!!!!\n");
                    printf("\nPress any key to continue...");
                    getch();
                    portal(uName);
                    exit(1);
                }
                else
                {
                    printf("Incorrect username or password \n\n");
                    printf("Do you want to try again(Y/N)\n\n");
                    b=getch();
                    if(b=='y'||b=='Y')
                    {
                        system("cls");
                        userlogin();
                    }
                    else
                    {
                        exit(1);
                    }
                }
                fclose(fp);
      	case 2:
            	
                	if ((fp=fopen("user.txt", "a+")) == NULL)
                	{
                        printf ("Could not open file\n");
                        exit ( 1);
                	}
                 	fflush(stdin);
                	printf("Choose A Username: ");
                	scanf("%[^\n]s",pUser->username);
                 	fflush(stdin);
                	printf("Choose A Password: ");
                	scanf("%[^\n]s",pUser->password);
                	fflush(stdin);
                	printf("Name: ");
                	scanf("%[^\n]s",pUser->name);
                	fflush(stdin);
                	printf("Address: ");
                	scanf("%[^\n]s",pUser->address);
                	fflush(stdin);
                 	printf("Nationality: ");
                	scanf("%[^\n]s",pUser->nationality);
                	fflush(stdin);
                	strcpy(pUser->car_taken,"no");
	                fwrite (pUser, sizeof(struct user), 1, fp);
                	printf("Account Created Successfully \n\n\n");
                	printf("\n\nPress any key...");
                	getch();
                	portal(pUser->username);
                  	break;     				          	
    	}
    	free ( pUser);//free allocated memory
    	fclose(fp);
}

//function for car booking
void car(char arr[])
{
    int i;
    system("cls");
	printf("                     Welcome for car booking \n\n                               Hope you will have a nice journey\n\n\n\n");
	char cars[9][20]={"Maruti Brezza","Hyundai Creta","Alto K10     ","Hyundai i20  ","Ford EcoSport","Volkswagon Polo","Tata Indigo  ","Mahindra Xuv500","Tata Hexa"},p;
	int price[9]={15,17,12,13,16,14,14,19,20};
	    printf("                        MODEL             RATE(per Km)  \n");
	    printf("\n                ======================================\n");
    for(i=0;i<9;i++)
    {
        printf("               %d.         %s         %d\n",i+1,cars[i],price[i]);
    }
    p=getch();
    FILE *fp;
    if ( ( fp=fopen("user.txt", "r+")) == NULL) 
    {
            printf ("Could not open file\n");
            exit (1);
    }
    while ( fread (pUser, sizeof(struct user), 1, fp) == 1) 
    {
        if( strcmp ( pUser->username, arr) ==0) 
        {
            {
                strcpy(pUser->car_taken,"yes");
                break;
            }
        }
    }
    fclose(fp);
    if(p>'9')
    { 
        printf("choose a valid option");
        car(arr);
    }
    function(cars[p-'1'],price[p-'1']);
}


void function(char arr[],int a)
{
		int b,k;
	char c;
   	system("cls");
    printf("You have selected %s as your car which has a price (per Km) of %d\n\n\n",arr,a);
    printf("\nEnter the number of days you will be using this for ::::   ");
    scanf("%d",&b);
    printf("1.   upto  120 kms\n");
    printf("2.   upto  360 kms\n");
    printf("3.   upto  600 kms\n");
    printf("4.   beyond  600 kms\n");
    printf("\nselect the range of kms you want included in your service : \nEnter your choice : ");
    scanf("%d",&k);
    static int total;
    int J;
    switch(k)
      {  
        case 1: total= b*a*1*120;
                printf("\n\n\n\n\nThe total cost is :::::  %d",b*a*1*120);
                break;
        
        case 2: total= b*a*0.8*360;
                printf("\n\n\n\n\nThe total cost is :::::  %d",b*a*0.8*360);
                break;
        
        case 3: total= b*a*0.67*600;
                printf("\n\n\n\n\nThe total cost is :::::  %d",b*a*0.67*600);
                break;
        
        case 4: printf("\n\n\n\n\nFor Journies more than 600kms ,contact us through our customer care number :1800 201 3636\nor mail us at: apni_car.custcare@gmail.com \n");
                printf("1. Exit Website\n2.   Start another booking!\n\n");
                scanf("%d",&J);
                switch(J){  
                          case 1: printf("\nHope you liked our services. Please Visit Us Again.  :) <3\n") ;
						          return ;
                                  break;
                                  
                	      case 2: printf("\n\n=============================================================================================================================\n\n");
						          return userlogin(); 
                	              break;
			             };
                
				break;

        default: printf("\n\n\nChoose appropiate options only. Try again :( ");
                 break; 
      }
    int T= total;

    printf("\n\n\n\n\nThe total cost is :::::  %d",1.2*total);
    printf("\n\n\nDo you want a driver(y/n).");
    c=getch();
    if(c=='y'||'Y')
    {
        printf("\n\n\n\nNow the revised cost is :::::%f",1.25*a*b);
        printf("\n\n\nYou have booked your car");
        printf("\n\n\n\nNow you can pay your bill by visiting this url 'www.apni car/bill payment'");
    }
    if(c=='n'||c=='N'){
        printf("You have booked your car");
        printf("Now you can pay your bill by visiting this url 'www.apni car/bill payment'");
        getch();
        exit(1);
    }
}

void return_car(){}

//function for user portal
void portal(char str[10])
{
    char p,b[3],m;
    int a=0;
    FILE *fp;
    if ((fp=fopen("user.txt", "r+")) == NULL)
	{
        printf ("Could not open file\n");
        exit (1);
    }
    while (fread(pUser, sizeof(struct user), 1, fp) == 1) 
	{
        if( strcmp ( pUser->username, str) ==0) 
		{
            strcpy(b,pUser->car_taken);
            a=1;
            break;
        }
    }                    
	fclose(fp);
    if(strcmp(b,"yes")==0)
    {
        printf("Sorry there are no options avilable for you as you have already booked a car which is yet to be returned");
        printf("Do you want to return it right now(y/n):");
        m=getch();
        if(m=='y')
        	return_car();
        else
        	exit(1);
    }

    else
    {
       system("cls");
       printf("                        Hello %s, Select one of the services:\n\n\n",str);
       printf("                        1. Car rent\n");
       printf("                        2. Bike rent\n");
       printf("                        3. Rating servies \n");
       printf("                        4. Long trips(special discounts avilable)\n");
       printf("                        5. My profile\n");
       printf("                        6. Exit\n\n\n\n");
       p=getchar();
       switch(p)
       {
       		case '1':   car(str);
       					break;
       		case '2':	bike();
       					break;
       		case '3':	rating();
       					break;
       		case '4':	package();
       					break;
       		case '5':	profile(str);
       					break;
       		case '6':	exit(1);
       					break;
       }
    }
}

void bike(){}

void rating()
{
	system("cls");
	char p;
	FILE *fp;
    if ( ( fp=fopen("rating.txt", "a+")) == NULL) 
	{
        printf ("Could not open file\n");
        exit (1);
    }
    sUser=(struct rate_us *)malloc(sizeof(struct rate_us));
	printf("Enter the stars you want to give ");
	scanf("%s",sUser->stars);
	printf("Would you like to suggest something(y/n)");
	scanf("%c",p);
	if(p=='y')
	scanf("%s",sUser->suggestions);
	else	
    exit(1);
}

void package(){}

void profile(char arr[])
{
	FILE *fp;
    if ( ( fp=fopen("user.txt", "r+")) == NULL)
	{
    	printf ("Could not open file\n");
        exit (1);
    }
    while ( fread (pUser, sizeof(struct user), 1, fp) == 1)
	{
        if( strcmp ( pUser->username, arr) ==0)
        {
    		system("cls");
    		printf("            Name:::%s\n\n\n",pUser->username);
            fflush(stdin);
            printf("            Password:::%s\n\n\n",pUser->password);
            fflush(stdin);
            printf("            Nationality: %s",pUser->nationality);
	        fflush(stdin);
            printf("            Address: %s",pUser->address);
            fflush(stdin);
            printf("            Car taken:::%s\n\n\n",pUser->car_taken);
            fflush(stdin);
            break;		  
        }
	}
    fclose(fp);

}

//driver function
int main()
{
  	welcome();
  	printf("Press any key to continue...");
  	getch();
  	system("cls");
  	userlogin();
}
