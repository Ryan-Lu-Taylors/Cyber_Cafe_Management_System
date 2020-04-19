#include "pc_entry_module.h"

#include <iostream>

#include <fstream>

#include <string>

#include <cstdlib>

#include <iomanip>


using namespace std;



void goBack();



void goBack()
{
	cout << "\n" << "Type 'continue' to return... \t";
	string word;
	cin >> word;
	PcEntryModule goBack;
	goBack.pcEntryModule();
}



void PcEntryModule::pcEntryModule()
{
	
	cout << "Please select your action:" << "\n" << endl;
	cout << "view repository" << "\n\n" << "add machine" ;
	cout << "\n\n" << "Selection: ";
	
	string selection_1;
	
	getline(cin,selection_1);
	
	if (selection_1 == "view repository")
	{
		
		ViewRepository viewRep;
		viewRep.viewRepository();
	
	}
	
	else if (selection_1 == "add machine")
	{
		
		AddMachine addMach;
		addMach.addMachine();

	}
	
	{
		cout << "Invalid input. Please try again.";
		
		system("CLS");
		
		PcEntryModule::pcEntryModule();
	}
	
	
}













void AddMachine::addMachine()
{
	
	system("CLS");
	
	
	cout << "Adding Machine to database..." << endl;
	
	cout << "\n" << "Apple (MacOS) -->  1" << endl;
	cout << "\n" << "Windows	   -->  2" << endl;
	
	int selection_2;
	
	cout << "\n" << "Please select your operating system: " << endl;
	
	cin >> selection_2;
	
	switch(selection_2)
	{
		case 1:
			system("CLS");
			
			AddMachine apple;
			
			apple.apple();
						
			break;
			
		case 2:
			system("CLS");
			
			AddMachine windows;
			
			windows.windows();
				
			break;
			
		default:
			cout << "invalid selection. please try again...";
			
			cin.ignore();
			
			AddMachine::addMachine();
			
			break;

	}
	
}


void AddMachine::apple()
{
	cout << "You are adding a new apple desktop device..." << endl;
	
	char nothing;
	cin.ignore();
	
	ofstream newApple("appleDirectory.txt",ios::app);
	
	if (!newApple.is_open())
	{
		cout << "The file could not be opened.";
	}
	
	
	cout << "\n" << "Enter Device Name: ";
	string setDeviceName;
	getline(cin,setDeviceName);
	
	
	cout << "\n" << "Enter memory size: ";
	string setMemorySize;
	getline(cin,setMemorySize);
	
	
	cout << "\n" << "Enter disk size: ";
	string setDiskSize;
	getline(cin,setDiskSize);
	
	
	cout << "\n" << "Enter processor model: ";
	string setProcessorModel;
	getline(cin,setProcessorModel);
	
	cout << "\n" << "Enter graphics card: ";
	string setGraphicsCard;
	getline(cin,setGraphicsCard);
	
	
	
	newApple << setDeviceName << setw(10);
	newApple << setMemorySize << setw(10);
	newApple << setDiskSize << setw(10);
	newApple << setProcessorModel << setw(10);
	newApple << setGraphicsCard << setw(10);
	
	newApple << "\n";
	
	newApple.close();
	
	
	cout << "\n" << "New Apple device documented!" << endl;
	cout << "Press any key to return...";
	cin.ignore();
	
	system("CLS");
		
	PcEntryModule returnToModule;
	
	returnToModule.pcEntryModule();
	
}

void AddMachine::windows()
{
	cout << "You are adding a new Windows device..." << endl;
	
	char nothing;
	cin.ignore();
	
	ofstream newWindows("windowsDirectory.txt",ios::app);
	
	if (!newWindows.is_open())
	{
		cout << "The file could not be opened.";
	}
	
	
	cout << "\n" << "Enter Device Name: ";
	string setDeviceName;
	getline(cin,setDeviceName);
	
	
	cout << "\n" << "Enter memory size: ";
	string setMemorySize;
	getline(cin,setMemorySize);
	
	
	cout << "\n" << "Enter disk size: ";
	string setDiskSize;
	getline(cin,setDiskSize);
	
	
	cout << "\n" << "Enter processor model: ";
	string setProcessorModel;
	getline(cin,setProcessorModel);
	
	cout << "\n" << "Enter graphics card: ";
	string setGraphicsCard;
	getline(cin,setGraphicsCard);
	
	
	
	newWindows << setDeviceName << setw(10);
	newWindows << setMemorySize << setw(10);
	newWindows << setDiskSize << setw(10);
	newWindows << setProcessorModel << setw(10);
	newWindows << setGraphicsCard << setw(10);
	
	newWindows << "\n";
	
	newWindows.close();
	
	
	cout << "\n" << "New Windows device documented!" << endl;
	cout << "Press any key to return...";
	cin.ignore();
	
	system("CLS");
		
	PcEntryModule returnToModule;
	
	returnToModule.pcEntryModule();
}











void ViewRepository::viewRepository()
{
	system("CLS");
	
	
	cout << "Viewing machines in database..." << endl;
	
	cout << "\n" << "Apple (MacOS) -->  1" << endl;
	cout << "\n" << "Windows	   -->  2" << endl;
	
	int selection;
	
	cout << "\n" << "Please select your operating system to view: " << endl;
	
	cin >> selection;
	
	switch(selection)
	{
		case 1:
			system("CLS");
			
			ViewRepository viewApple;
			viewApple.viewAppleRepository();
			
			
			break;
			
		case 2:
			system("CLS");
			
			ViewRepository viewWindows;
			viewWindows.viewWindowsRepository();
			
			break;
			
		default:
			cout << "invalid selection. please try again...";
			
			cin.ignore();
			
			
			
			break;

	}
	
}


void ViewRepository::viewAppleRepository()
{
	cout << "You have entered Apple device repository." << "\n\n" << endl;
	
	ifstream viewAppleDevices("AppleDirectory.txt");
	
	if (!viewAppleDevices.is_open())
	{
		cout << "The file could not be opened!" << endl;
	}
	
	cout << "The following are the devices stored in repository yet." << endl;
	
	string currentRepository;
	
	getline(viewAppleDevices,currentRepository,'n');
	
	cout << "\n" << currentRepository;
	
	goBack();
}


void ViewRepository::viewWindowsRepository()
{
	cout << "You have entered Windows device repository." << "\n\n" << endl;
	
	ifstream viewWindowsDevices("WindowsDirectory.txt");
	
	if (!viewWindowsDevices.is_open())
	{
		cout << "The file could not be opened!" << endl;
	}
	
	cout << "The following are the devices stored in repository yet." << endl;
	
	string currentRepository;
	
	getline(viewWindowsDevices,currentRepository,'n');
	
	cout << "\n" << currentRepository;
	
	goBack();
}



























