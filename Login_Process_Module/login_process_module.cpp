#include "login_process_module.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

user* Login_Process_Module :: InitializeList(user *h)
{
	
	user* t, *ptr, temp;
	
	FILE *fp;
	
	int cc = 0, x;
	
	float ff;
	
	fp = fopen("users.txt","r");
	
	
	
	if (fp == NULL)
	{
		return NULL;
	} 
	
	
	if (fgetc(fp) == EOF)
	{
		return NULL;
	}
	
	
	rewind(fp);
	
	
	while(fscanf(fp,"%s %s %f %d",temp.username,temp.password,&temp.price,&temp.numtick)!=EOF)

    {

        ptr=(user*)malloc(sizeof(user));

        strcpy(ptr->username,temp.username);

        strcpy(ptr->password,temp.password);

        ptr->price=temp.price;

        ptr->numtick=temp.numtick;

        ptr->next=NULL;



        if(h==NULL)

            h=t=ptr;

        else

        {

            h->next=ptr;

            h=ptr;

        }
    
	}



    fclose(fp);

    return t;

}

void Login_Process_Module::writeToFile (user *h)
{
	
    FILE *fp;

    fp=fopen("users.txt","w");

    while(h!=NULL)

    {

        fprintf(fp,"%s %s %f %d\n",h->username,h->password,h->price,h->numtick);

        h=h->next;

    }

    fclose(fp);	
    
}


user* Login_Process_Module:: AddUser(user* h)

{

    user *t;

    t=h;

    user *nw;

    nw=(user*)malloc(sizeof(user));

    fflush(stdin);

    printf("Enter username or email\n");

    scanf("%s",nw->username);

    while(h!=NULL)

    {

        if(!strcmp(h->username,nw->username))

        {

            printf("That email already exists\n");

            return t;

        }

        h=h->next;

    }

    h=t;

    fflush(stdin);

    printf("Enter password\n");

    scanf(" %[^\n]s",&nw->password);

    nw->next=NULL;


    nw->price=0.0;

    nw->numtick=0;



    if(h==NULL)

    {

        h=t=nw;

    }

    else

    {

        while(h->next!=NULL)

        {

            h=h->next;

        }

        h->next=nw;

    }

    writeToFile(t);

    return t;

}



void Login_Process_Module::loginUser(user* h)

{

    char username[100];

    char password[100];

    fflush(stdin);

    printf("\n\n");

    printf("\t\tEnter Email/Username:\n\t\t");

    scanf("%s",username);

    fflush(stdin);

    printf("\n\t\tEnter Password:\n\t\t");

    scanf(" %[^\n]s",password);

    while(h!=NULL)

    {

        if((!strcmp(h->username,username)) && (!strcmp(h->password,password)))

        {

            currentstate=loggedin;

            strcpy(currentuser,username);

            

            printf("\n\t\tLogin successful!\n");

            system("PAUSE");

            return;

        }

        else if((!strcmp(h->username,username)) && (strcmp(h->password,password)))

        {

            printf("Password mismatch\n");

            return;

        }

        h=h->next;

    }

    printf("Sorry, no such user record was found\n");

}



void Login_Process_Module::changePassword(user* h)

{

    user *t=h;

    char passcurr[100];

    fflush(stdin);

    printf("Enter your current password to continue:\n");

    scanf(" %[^\n]s",passcurr);

    while(h!=NULL)

    {

        if(!strcmp(h->username,currentuser))

            break;

        h=h->next;

    }

    if(h==NULL)

        return;

    if(!strcmp(passcurr,h->password))

    {

        printf("Enter new password:\n");

        scanf(" %[^\n]s",h->password);

    }

    writeToFile(t);

}



void Login_Process_Module::logoutUser()

{

    if(currentstate==menu || strcmp(currentuser,"\0")==0)

    {

        printf("You must be logged in to logout\n");

        return;

    }

    strcpy(currentuser,"\0");

    currentstate=menu;

    printf("You have been successfully logged out\n");

}



void Login_Process_Module::exitProgram()

{

    printf("Exiting...\n\nBrought To You By code-projects.org\n\nPress \"Enter/Return\" to exit");

    char exitprog;

    fflush(stdin);

    scanf("%c",&exitprog);

}
 
 
 
 
 
 
 
 
 
 int main()
{
	
	Login_Process_Module a;
	
	    printf("==== || CYBER CAFE MANAGEMENT || ====\n");

    user* h=NULL;

    int ch1,ch2;

    h = a.InitializeList(h);

    while (1)

    {

        

        if(currentstate==menu)

        {

            

            printf("\n\t\tAdd User - 1\n\t\tLogin User - 2\n\t\tBExit - 3\n\n\t\tEnter:");

            scanf("%d",&ch1);

            switch(ch1)

            {

                case 1:

                    h=a.AddUser(h);

                    break;

                case 2:

                    a.loginUser(h);

                    break;

                case 3:

                    a.exitProgram();

                    exit(0);

                    break;

                default:

                    printf("Not a valid input at this stage\n");

            }

        }

        else if(currentstate==loggedin)

        {

        system("CLS");

        printf("\n\t\t=========================");

        printf("\n\t\t CYBER CAFE MANAGEMENT ");

        printf("\n\t\t=========================\n");

            printf("\n\t\tgame1 - 1\n\t\tgame2 - 2\n\t\tgame3 - 3\n\t\tChange Password - 4"

                   "\n\t\tLogout User - 5\n\t\tExit - 6\n");

            scanf("%d",&ch2);

            switch(ch2)

            {

                case 1:

                    system("PAUSE");

                    system("CLS");

                    break;

                case 2:

                    system("PAUSE");

                    system("CLS");

                    break;

                case 3:

                    system("PAUSE");

                    system("CLS");

                    break;

                    

                case 4:

                    a.changePassword(h);

                    system("PAUSE");

                    system("CLS");

                    break;

                case 5:

                    a.logoutUser();

                    system("PAUSE");

                    system("CLS");

                    break;



                case 6:

                    a.exitProgram();

                    exit(0);

                    break;

                default:

                    printf("Not a valid input at this stage\n");

            }

        }

    }

    return 0;

	
}

