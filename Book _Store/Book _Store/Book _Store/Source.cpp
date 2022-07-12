#include <iostream>
#include <string>				// standard libraries called and included.
#include <fstream>
#include <ctime>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;
string arr[100];
bool found = false;
void endinsert();
void delbook();
int totalpro;
int tavail;
float tamount;
void deleteNode(int position);
void menu();
int noofline = 0;
fstream itemRec;	// fstream filehandling used (input and output operations in default mode).

void insert(string array, int i);
void iteminsert(string id, string name, float unitprcie, int quantity, float tprice, string authtor);


struct node{
	string  lname, lauthor;
	int lid, lquantity;
	float lunit, ltotal;
	struct node *next;

}*start;


void FiletoLL(){
	struct  node* ptr, *newnode = NULL;


	int i = 0, totalline;
	itemRec.open("Inventory.txt", ios::in);
	string line;
	if (itemRec.is_open())
	{

		while (getline(itemRec, line))
		{
			i++;
			//	cout << line << endl;
			arr[i] = line.substr(line.find(":") + 1);

		}
		cout << "\nData fateched from file successfully\n";
	}
	else
	{
		cout << "Error encountered in opening file.\n\n";
	}

	totalline = i;
	//cout << totalline;
	/*for (int i = 0; i <=totalline+1; i++)
	{
	cout << arr[i];

	}*/
	totalpro = totalline / 6;

	cout << totalpro;


	itemRec.close();
	struct node *temp;
	temp = new node;
	start = NULL;

	for (int i = 1; i <= totalpro; i++)
	{
		if (i > 1){
			noofline = noofline + 6;
		}
		int id = std::stoi(arr[1 + noofline]);
		float unit = std::stof(arr[3 + noofline]);
		int quantity = std::stoi(arr[4 + noofline]);
		float total = std::stof(arr[5 + noofline]);
		if (start == NULL){
			temp->lid = id;
			temp->lname = arr[2 + noofline];
			temp->lunit = unit;
			temp->lquantity = quantity;
			temp->ltotal = total;
			temp->lauthor = arr[6 + noofline];
			temp->next = NULL;
			start = temp;


		}

		else
		{


			ptr = start;
			while (1){

				if (ptr->next != NULL){
					ptr = ptr->next;
				}

				else{
					break;
				}


			}
			newnode = new node();
			newnode->lid = id;
			newnode->lname = arr[2 + noofline];
			newnode->lunit = unit;
			newnode->lquantity = quantity;
			newnode->ltotal = total;
			newnode->lauthor = arr[6 + noofline];
			newnode->next = NULL;
			ptr->next = newnode;
		}


	}
	/*
	struct node *dis;
	dis = start;


	while (dis->next != NULL){

	cout << dis->lid << endl;
	cout << dis->lname << endl;
	cout << dis->lunit << endl;
	cout << dis->lquantity << endl;
	cout << dis->ltotal << endl;
	cout << dis->lauthor << endl;
	dis = dis->next;
	}
	cout << dis->lid << endl;
	cout << dis->lname << endl;
	cout << dis->lunit << endl;
	cout << dis->lquantity << endl;
	cout << dis->ltotal << endl;
	cout << dis->lauthor << endl;
	*/
}

void Bookinsert(int id, string name, float unitprice, int quantity, float tprice, string author){
	struct node* temp1 = NULL;
	temp1 = new node();
	totalpro++;
	if (start == NULL){
		temp1->lid = id;
		temp1->lname = name;
		temp1->lunit = unitprice;
		temp1->lquantity = quantity;
		temp1->ltotal = tprice;
		temp1->lauthor = author;
		temp1->next = NULL;
		start = temp1;
	}

	else
	{
		struct node *ptr, *newnode = NULL;

		ptr = start;
		while (1){
			if (ptr->next != NULL){
				ptr = ptr->next;

			}

			else{
				break;
			}

		}

		newnode = new node();
		newnode->lid = id;
		newnode->lname = name;
		newnode->lunit = unitprice;
		newnode->lquantity = quantity;
		newnode->ltotal = tprice;
		newnode->lauthor = author;
		newnode->next = NULL;
		ptr->next = newnode;

	}

}


void display(){
	struct node *dis;
	dis = start;
	tavail = 0;
	tamount = 0;

	if (totalpro <= 0){
		cout << "\n\nNo Book available\n\n";
	}
	else{
		for (int i = 1; i <= totalpro; i++)
		{
			cout << "Book ID: " << dis->lid << endl;
			cout << "Book Name: " << dis->lname << endl;
			cout << "Price of one Book: " << dis->lunit << endl;
			cout << "Book Available Quantity: " << dis->lquantity << endl;
			cout << "Total Price of Available Books: " << dis->ltotal << endl;
			cout << "Book Author: " << dis->lauthor << endl << endl;

			tavail += dis->lquantity;
			tamount += dis->ltotal;
			if (i < totalpro){
				dis = dis->next;
			}
		}
	}
	system("pause");
}


void LLtoFile()		// Function for "Adding an Item" declared, defined and built here.
{
	string fid, funit, fquantity, ftotal;
	bool check = false;
	remove("Inventory.txt");
	itemRec.open("Inventory.txt", ios::out | ios::app);

	if (itemRec.is_open())
	{
		string choice;

		struct node *dis;
		dis = start;


		for (int i = 1; i <= totalpro; i++)
		{
			dis->lid;
			dis->lname;
			dis->lunit;
			dis->lquantity;
			dis->ltotal;
			dis->lauthor;

			fid = to_string(dis->lid);
			funit = to_string(dis->lunit);
			fquantity = to_string(dis->lquantity);
			ftotal = to_string(dis->ltotal);
			string data = ("Item ID: " + fid) + "\n" + ("Item Name: " + dis->lname) + "\n" + ("Unit Price in PKR: " + funit) + "\n" + ("Quantity: " + fquantity) + "\n" + ("Net Amount in PKR: " + ftotal) + "\n" + ("Author: " + dis->lauthor);
			itemRec << data << endl;
			if (i < totalpro){
				dis = dis->next;
			}
		}

	}
	else
	{
		cout << "Error encountered in opening file.\n";
	}
	itemRec.close();
	cout << "Moving back to the menu.\n\n";

}



void Search(int searchid)
{
	struct node *dis;
	dis = start;
	bool found = false;

	while (dis->next != NULL){

		if (dis->lid == searchid){
			found = true;
			cout << "Book ID:" << dis->lid << endl;
			cout << "Book Name:" << dis->lname << endl;
			cout << "Book Unit Price: " << dis->lunit << endl;
			cout << "Book Quatity: " << dis->lquantity << endl;
			cout << "Total Price: " << dis->ltotal << endl;
			cout << "Book Author: " << dis->lauthor << endl;
			break;
		}
		dis = dis->next;
		found = false;
	}
	if (found == false){
		if (dis->lid == searchid){
			found = true;
			cout << "Book ID: " << dis->lid << endl;
			cout << "Book Name: " << dis->lname << endl;
			cout << "Book Unit Price: " << dis->lunit << endl;
			cout << "Book Quatity: " << dis->lquantity << endl;
			cout << "Total Price: " << dis->ltotal << endl;
			cout << "Book Author: " << dis->lauthor << endl;
		}

		else{
			found = false;
		}
	}
	if (found == false){
		cout << "\n============Book not Found===============\n";
		system("pause");
	}

	else{
		cout << "\n============Book Found Successfully===============\n";
		system("pause");
	}

}

void deleteNode(int searchid)
{
	struct node *dis;
	dis = start;
	
	int position = -1;

	while (dis->next != NULL){
		position++;
		if (dis->lid == searchid){
			totalpro--;
			found = true;
			cout << "Book ID: " << dis->lid << endl;
			cout << "Book Name: " << dis->lname << endl;
			cout << "Book Unit Price: " << dis->lunit << endl;
			cout << "Book Quatity: " << dis->lquantity << endl;
			cout << "Total Price: " << dis->ltotal << endl;
			cout << "Book Author: " << dis->lauthor << endl;
			break;
		}
		dis = dis->next;
		found = false;
	}
	if (found == false){
		if (dis->lid == searchid){
			totalpro--;
			position++;
			found = true;
			cout << "Book ID: " << dis->lid << endl;
			cout << "Book Name: " << dis->lname << endl;
			cout << "Book Unit Price: " << dis->lunit << endl;
			cout << "Book Quatity: " << dis->lquantity << endl;
			cout << "Total Price: " << dis->ltotal << endl;
			cout << "Book Author: " << dis->lauthor << endl;
		}

		else{
			found = false;
		}
	}
	if (found == false){
		cout << "\n============Book not Found===============\n";

	}

	else{

		cout << "\n============Book Found Successfully===============\n";
	}


	struct node*temp1 = start;
	if (found == true){

		if (temp1 == NULL)
			return;


		node* temp = temp1;


		if (position == 0)
		{


			start = temp->next;


			free(temp);
			return;
		}


		for (int i = 0; temp != NULL && i < position - 1; i++)
			temp = temp->next;


		if (temp == NULL || temp->next == NULL)
			return;


		node *next = temp->next->next;


		free(temp->next);


		temp->next = next;

	}


}
void menu()
{

	system("CLS");
	time_t now = time(0);

	// convert now to string form
	char* date_time = ctime(&now);

	cout << "\n\n\tThe current date and time is: " << date_time << endl;
	cout << "\t********\n";
	cout << "\n\t\t         Press '1' to Add a New Book         \n";
	cout << "\t\t         Press '2' to View Book collection        \n";
	cout << "\t\t         Press '3' to Delete an Book         \n";
	cout << "\t\t         Press '4' to Search an Book         \n";
	cout << "\t\t         Press '5' to Update an Book         \n";
	cout << "\t\t         Press '6' For Report             \n";
	cout << "\t\t         Press '0' to Exit the System        \n\n";
	cout << "\t     Dont Use Windows X button to close the program       \n\n";
}
void main()
{
	system("mode 650");
	system("color 79");
	string name, author;
	int id, quantity;
	float unitprice, tprice;
	int count = 0;
	bool close = false;
	int option;
	FiletoLL();
	do
	{
		float paid = 0, due = 0, purch_total = 0;

		menu();
		cout << "\t\tEnter Your Desired Option "; cin >> option;
		system("CLS");
		cout << endl;

		if (option == 1){
			int quan;
			cout << "\nHow many books you want to add:  ";
			cin >> quan;

			for (int i = 0; i < quan; i++)
			{
				cout << "\nEnter data for Book" << i + 1 << "\n";
				cout << "Enter Unique Book ID: "; cin >> id;
				cout << "Enter Name of Book: "; cin >> name;
				cout << "Enter Unit Price in PKR of Book: "; cin >> unitprice;
				cout << "Enter Quantity for Book: "; cin >> quantity;
				tprice = unitprice * quantity;
				cout << "Net Amount in PKR: " << tprice << endl;
				cout << "Auhor/Write name: "; cin >> author;
				Bookinsert(id, name, unitprice, quantity, tprice, author);
			}
			cout << "\nBook(s) Added Successfully\n\n";
			system("pause");
		}

		else if (option == 2){
			display();
		}
		else if (option == 3){
			int n;

			if (totalpro <= 0){
				cout << "\n\nNo Book available\n\n";
				system("pause");
			}
			else{
				cout << "\nEnter the id of book you want to delete\nEnter ID of product: ";
				cin >> n;
				deleteNode(n);

				if (found == true){
					cout << "\n===========Book Deleted Successfully===========\n\n";
					system("pause");
				}

				else{
					cout << "\n===========Book Not Deleted Successfully===========\n\n";
					system("pause");
				}
			}
		}
		else if (option == 4){
			int searchid;

			if (totalpro <= 0){
				cout << "\n\nNo Book available\n\n";
				system("pause");
			}
			else{
				cout << "\n================Searching===============\n";
				cout << "\nEnter the id of book you want to search\nEnter ID of product: ";
				cin >> searchid;
				Search(searchid);
			}
		}

		else if (option == 5){
			int n;
			if (totalpro <= 0){
				cout << "\n\nNo Book available\n\n";
				system("pause");
			}
			else{
				cout << "\nEnter the id of book you want to update\nEnter ID of product: ";
				cin >> n;
				deleteNode(n);
				cout << "\nEnter New updated info of Book\n";
				cout << "Enter Unique Book ID: "; cin >> id;
				cout << "Enter Name of Book: "; cin >> name;
				cout << "Enter Unit Price in PKR of Book: "; cin >> unitprice;
				cout << "Enter Quantity for Book: "; cin >> quantity;
				tprice = unitprice * quantity;
				cout << "Net Amount in PKR: " << tprice << endl;
				cout << "Auhor/Write name: "; cin >> author;
				Bookinsert(id, name, unitprice, quantity, tprice, author);
				if (found == true){
					cout << "\n===========Book Updated Successfully===========\n";
					system("pause");
				}

				else{
					cout << "\n==============Book Not Updated==============\n";
					system("pause");
				}
			}
		}

		else if (option == 6){
			display();
			cout << "\nTotal Available Book(s):   " << totalpro;
			cout << "\nTotal Quantity of Book(s): " << tavail;
			cout << "\nTotal Cost of All Available Book(s): " << tamount;
			cout << "\n\n";
			system("pause");
		}

	} while (!(option == 0));
	if (option == 0)
	{
		if (totalpro <= 0){
			cout << "\n\nNo Book available\n\n";
		}
		else{
			LLtoFile();
			itemRec.close();
			display();
			cout << "\nAbove Book(s) added in file Successfully\n";
		}
	}
	system("pause");
}