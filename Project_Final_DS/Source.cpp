#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
using namespace std;

int main()
{
	ifstream Account("Info.txt");
	string username;
	string password;
	getline(Account, username);
	getline(Account, password);
	cout << "Enter Username: ";
	string username_entered;
	getline(cin, username_entered);
	cout << "Enter Password: ";
	string password_entered;
	getline(cin, password_entered);
	if ((username_entered.compare(username) == 0) && (password_entered.compare(password) == 0))
	{
		bool loop = true;
		LinkedList List;
		while (loop)
		{
			cout << "1.Add New Line" << endl;
			cout << "2.Insert New Line" << endl;
			cout << "3.Get Line Text" << endl;
			cout << "4.Delete Line" << endl;
			cout << "5.Update Line" << endl;
			cout << "6.Find All" << endl;
			cout << "7.Find And Replace All" << endl;
			cout << "8.Show" << endl;
			cout << "9.Change Account Details" << endl;
			int operation;
			cout << "Enter number of operation you want : " << endl;
			cin >> operation;
			switch (operation)
			{
			case 1:
			{
				string str;
				cout << "Enter String you want to add" << endl;
				cin.ignore();
				getline(cin, str);
				List.append(str);
				break;
			}
			case 2:
			{
				string str;
				int pos;
				cout << "Enter String you want to add" << endl;
				cin.ignore();
				getline(cin, str);
				cout << "Enter position of string" << endl;
				cin >> pos;
				List.InsertAt(str, pos);
				break;
			}
			case 3:
			{
				int pos;
				cout << "Enter position of string you want" << endl;
				cin >> pos;
				List.GetString(pos);
				break;
			}
			case 4:
			{
				int pos;
				cout << "Enter position of string you want to delete" << endl;
				cin >> pos;
				List.deleteat(pos);
				break;
			}
			case 5:
			{
				string str;
				int pos;
				cout << "Enter position of string you want to edit" << endl;
				cin >> pos;
				cout << "Enter new String" << endl;
				cin.ignore();
				getline(cin, str);
				List.UpdateLine(str, pos);
				break;
			}
			case 6:
			{
				string str;
				cout << "Enter string you want to find" << endl;
				cin.ignore();
				getline(cin, str);
				List.Find(str);
				break;
			}
			case 7:
			{
				string old_str;
				string new_str;
				cout << "Enter old string you want to replace" << endl;
				cin.ignore();
				getline(cin, old_str);
				cout << "Enter new string" << endl;
				getline(cin, new_str);
				List.FindAndReplace(old_str, new_str);
				break;
			}
			case 8:
			{
				List.Display();
				break;
			}
			case 9: {
				system("CLS");
				cout << "1.Account Username" << endl;
				cout << "2.Account Password" << endl;
				cout << "3.Account Username And Password" << endl;
				int account_operation;
				cout << "Enter number of operation you want : " << endl;
				cin >> account_operation;
				cin.ignore();
				switch (account_operation)
				{
				case 1: {
					cout << "Enter New Username :" << endl;
					getline(cin, username);
					ofstream Account("Info.txt");
					Account << username << endl;
					Account << password << endl;
					break;
				}
				case 2: {
					cout << "Enter New Password :" << endl;
					getline(cin, password);
					ofstream Account("Info.txt");
					Account << username << endl;
					Account << password << endl;
					break;
				}
				case 3: {
					cout << "Enter New Username :" << endl;
					getline(cin, username);
					cout << "Enter New Password :" << endl;
					getline(cin, password);
					ofstream Account("Info.txt");
					Account << username << endl;
					Account << password << endl;
					break;
				}
				default: {
					cout << "Invalid Operation:\n";
					break;
				}
				}
				break;
			}
			default:
				break;
			}
			cout << "Do you want to do another operation ? Enter (Y/N)" << endl;
			char Another_Operation = 'N';
			cin >> Another_Operation;
			if (Another_Operation == 'Y' || Another_Operation == 'y')
			{
				loop = true;
				system("CLS");
			}
			else {
				loop = false;
				break;
			}
		}
		//List.save(list<string>List); 
		system("pause");
		return 0;
	}
	else
	{
		cout << "Username Or Password Incorrect." << endl;
		system("pause");
		return 0;
	}
}