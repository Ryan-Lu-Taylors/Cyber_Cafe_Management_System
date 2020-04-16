#ifndef LOGIN_PROCESS_MODULE_H
#define LOGIN_PROCESS_MODULE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

enum state {menu,loggedin};

enum state currentstate = menu;

typedef struct user
{
	
	char username[100];
	
	char password[100];
	
	struct user *next;
	
	float price;
	
	int numtick;
	
} user;


char currentuser[100];


class Login_Process_Module
{
	
	public:
		
		user* InitializeList(user*);
		
		user* AddUser(user*);
		
		void loginUser(user*);
		
		void changePassword(user*);
		
		void logoutUser();
		
		void displayAll(user*);
		
		void writeToFile(user*);
		
		void exitProgram();
	
};




#endif
