#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <fstream>
using namespace std;
///Logic Functions

/// Update & Insert Function
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);

/// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

///Delete & Count Function
void deletefood(int serial);
int countitem();

///extra design Function

void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);

///START Structure Here

struct Node
{
	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;
};

///Global Type

typedef struct Node node;

node *head, *list;

int main()
{
	system("Food Menu System");
	system("mode con: cols=88 lines=30");

	loadingbar();
	cls();
	pwellcome();
	Sleep(300);
	cls();

	int c = 0;
	int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order = 0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(1, "Tapsilog", 50, 65);
	insertend(2, "Bacsilog", 50, 65);
	insertend(3, "Longsilog", 50, 50);
	insertend(4, "Hotsilog", 50, 45);
	insertend(5, "Bangsilog", 50, 65);
	insertend(6, "Chicksilog", 50, 60);

mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1);
	pre(4);
	fflush(stdin);
	scanf("%d", &main_menu_choice);

	if ((main_menu_choice >= 1 && main_menu_choice <= 3))
	{
		if (main_menu_choice == 1)
		{
		foodlist:

			cls();
			printf("=> 0. Main Menu ");
			foodlist();
		}

		else if (main_menu_choice == 2)
		{
		adminpanelchoice:




			//int admin_panel_choice;
			cls();
			middle1();
			pre(4);
			//printf("1. Main Menu\n\n\t");
			//Sleep(300);
			//printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");
			//fflush(stdin);
			//scanf("%d", &admin_panel_choice);
			
string pass ="";
   char ch;
   cout << "Enter your Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "password"){
      
				node *temp;

				temp = list;

			adminchoise:

				cls();
				br(3);
				pre(4);
				echo(">>>> Admin Section <<<<   \n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");
				Sleep(250);
				pre(4);
				printf(" 0. Main Menu \n\n");
				printf("\t\tEnter your desired choice [1-0]: ");
				Sleep(250);

				int adminchoise;

				fflush(stdin);
				scanf("%d", &adminchoise);

				if (adminchoise == 1)
				{
					cls();
					middle1();
					pre(4);
					printf("Todays Total Cash : %0.2f  \n", totalmoney);

					Sleep(2000);

					goto adminchoise;
				}

				else if (adminchoise == 0)
				{
					goto mainmenu;
				}

				else
				{
					br(2);
					pre(4);
					printf("Please Select From Food List :  ");
					Sleep(500);
					goto adminchoise;
				}
			}
		}

		else if (main_menu_choice == 3)
		{
			cls();
			middle1();
			pre(3);
			printf("Thank You For Buying at The Best Kainan! \n\n\n\n\n\n\n");
			Sleep(1000);

			exit(1);
		}
	}
	else
	{
		br(2);
		pre(4);
		printf("Please Enter Correct Choice");
		Sleep(300);
		goto mainmenu;
	}

	int get_food_choice;

	br(2);
	pre(3);
	fflush(stdin);
	printf("Place Your Order: ");
	scanf("%d", &get_food_choice);

	if (get_food_choice == 0)
	{
		goto mainmenu;
	}

	node *temp;

	temp = list;

	while (temp->data != get_food_choice)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			br(2);
			pre(3);
			echo("Invalid input! Please choose from the food list!");
			br(2);
			Sleep(1000);
			goto foodlist;
		}
	}
	if (get_food_choice == temp->data)
	{
	fcquantity:
		br(2);
		pre(3);
		printf("Enter Food Quantity: ");

		int fcquantity;

		fflush(stdin);
		scanf("%d", &fcquantity);
		cls();

		if (fcquantity == 0)
		{
			cls();
			middle1();
			pre(3);
			printf("Quantity Can not be Zero ");
			Sleep(2000);
			cls();
			goto foodlist;
		}
		else if (fcquantity > temp->quantity)
		{
			cls();
			middle1();
			pre(3);
			printf("Oppps!! sorry Food is Out of Stock ! ");
			Sleep(2000);

			goto foodlist;
		}

		middle1();
		pre(1);
		printf("Choice item %s's price is %0.2f \n\n", temp->foodname, temp->price * fcquantity);

		int senior;
		printf("\tAre you a senior citizen? Enter [1] if yes, Enter [2] if not: ");
		cin >> senior;

		ofstream outfile;
		outfile.open("Receipt.txt");
		outfile << "Thank You for Purchasing Food!" << endl;

		if (senior == 1)
		{
			printf("Choice item %s's discounted price is %0.2f \n\n", temp->foodname, temp->price * fcquantity * 0.8);
			cout << endl;
			totalmoney += temp->price * fcquantity;

		outfile << "Total Amount Due: " << totalmoney * 0.8 << endl;
		}
		else
		{
			totalmoney += temp->price * fcquantity;

		outfile << "Total Amount Due: " << totalmoney << endl;
		}

		br(2);
		pre(3);
		printf("1. Confirm to buy this \n\n");
		pre(3);
		printf("2. Food List \n\n");
		printf("\tEnter [1] to confirm and [2] to cancel the order and go back to the list: ");

	confirm:
		int confirm;

		fflush(stdin);
		scanf("%d", &confirm);

		if (confirm == 1)
		{
			br(2);
			pre(3);

			printf("Method Of payment is cash only");
			printf("\n\n\t enter [1] to continue: ");
		payment:
			int payment;

			fflush(stdin);
			scanf("%d", &payment);

			if (payment == 1)
			{
				order++;
				total_order[order] = get_food_choice;

				order_quantity[order] = fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice, uquantity);

				cls();
				middle1();
				pre(4);
				printf("===>THANK YOU<===");
				br(2);
				pre(4);
				printf("Food Ordered Successfully ...");
				br(2);
				pre(4);
				printf("1. Want Another? ");
				br(2);
				pre(4);
				printf("2. Main Menu \n");
				br(2);
				pre(4);
				printf("Select: ");
			psmenu:
				int ps_menu;

				fflush(stdin);
				scanf("%d", &ps_menu);

				if (ps_menu == 1)
				{
					goto foodlist;
				}
				else if (ps_menu == 2)
				{
					goto mainmenu;
				}
				else
				{
					br(2);
					pre(4);
					printf("Please Choice from list : ");
					goto psmenu;
				}
			}

			///Credit Card Option

			else
			{
				br(2);
				pre(4);
				printf("Enter Choice from List : ");

				goto payment;
			}

		} ///END Confirm Y/y

		else if (confirm == 2)
		{
			goto foodlist;
		}

		else
		{
			br(2);
			pre(4);
			printf("Enter Choice from List : ");

			goto confirm;

		} ///end confirm;

	} ///end get food choice if line

	else
	{
		br(2);
		pre(4);
		echo("Please Choose From List ");
		br(2);
		Sleep(300);

		goto foodlist;

	} ///end get food choice
}

void cls()
{
	system("cls");
}

void echo(char print[])
{
	printf("%s", print);
}

void br(int line)
{
	for (int i = 0; i < line; i++)
	{
		printf("\n");
	}
}

void pre(int tab)
{
	for (int i = 0; i < tab; i++)
	{
		printf("\t");
	}
}
void span(int space)
{
	for (int i = 0; i < space; i++)
	{
		printf(" ");
	}
}

void main_menu()
{
	cls();
	br(5);
	pre(3);
	echo(">> 1. Food Lists");
	Sleep(400);
	br(2);
	pre(3);
	echo(">> 2. Admin Section");
	Sleep(400);
	br(2);
	pre(3);
	echo(">> 3. Exit");
	Sleep(400);
	//   br(2); pre(3); echo("=> 4. Admin Panel");  Sleep(400);
	br(2);
}

void insertend(int data, char foodname[25], int quantity, float price)
{
	node *temp;

	temp = (node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp->quantity = quantity;

	strcpy(temp->foodname, foodname);

	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		list = head;
	}
	else
	{
		while (head->next != NULL)
		{
			head = head->next;
		}

		head->next = temp;
	}
}

void insertfirst(int data, char foodname[25], int quantity, float price)
{
	node *temp;

	temp = (node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	strcpy(temp->foodname, foodname);

	temp->quantity = quantity;

	temp->next = head;

	head = temp;

	list = head;
}

void insertmid(int pos, int data, char foodname[25], int quantity, float price)
{
	node *temp;

	temp = (node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp->quantity = quantity;

	strcpy(temp->foodname, foodname);

	while (head->next->data != pos)
	{
		head = head->next;
	}

	temp->next = head->next;
	head->next = temp;

	//    free(temp);
}

void updatefood(int udata, int uquantity)
{
	node *temp;
	temp = list;

	while (temp->data != udata)
	{
		temp = temp->next;
	}
	if (temp->data == udata)
	{
		temp->quantity = uquantity;
	}
}

void foodlist()
{
	ccolor(0);

	printf("\n\t\t");
	ccolor(240);
	printf("______________________________________________________ ");
	ccolor(26);
	printf("\n\t\t");
	ccolor(240);
	printf("|  Item No.  |   Food Name   |  Price  |   In Stock   |");
	ccolor(26);
	printf("\n\t\t");
	ccolor(240);
	printf("-------------------------------------------------------");
	ccolor(26);

	node *temp;

	temp = list;

	while (temp != NULL)
	{
		ccolor(26);

		printf("\n\t\t");
		ccolor(62);
		printf("|     %d      |    %s  |    %0.2f   |    %d    |", temp->data, temp->foodname, temp->price, temp->quantity);
		ccolor(26);
		printf("\n\t\t");
		ccolor(62);
		printf("-------------------------------------------------------");

		temp = temp->next;

		Sleep(100);
	}

	ccolor(26);

	//  free(temp);
}

void order_view(int order, int quantity, int or_no)
{
	ccolor(26);

	node *temp;

	temp = list;

	while (temp->data != order)
	{
		temp = temp->next;
	}
	if (temp->data == order)
	{
		ccolor(26);

		printf("\n\t\t");
		ccolor(62);
		printf("|     %d      |    %s  |     %d     |     %d     |", or_no, temp->foodname, quantity, temp->quantity);
		ccolor(26);
		printf("\n\t\t");
		ccolor(62);
		printf("-------------------------------------------------------");

		Sleep(100);
	}

	ccolor(26);
}

void ccolor(int clr)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

	//the above code displays colorful background. if you want colorful then you can remove the above comment but not the code, only comment//
}

///HEERE PRINTF STYLE FUNCTION

void pwellcome()
{
	ccolor(26);

	char welcome[50] = "Welcome";
	char welcome2[50] = " To";
	char welcome3[50] = " Kainan";
	char welcome4[50] = " Ni Mang Hulyo!";
	printf("\n\n\n\n\n\t\t\t");
	for (int wlc = 0; wlc < strlen(welcome); wlc++)
	{
		printf(" %c", welcome[wlc]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++)
	{
		printf(" %c", welcome2[wlc2]);
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++)
	{
		if (welcome3[wlc3] != 'D')
		{
			printf(" %c", welcome3[wlc3]);
		}
		else
		{
			printf(" %c", welcome3[wlc3]);
		}

		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for (int wlc3 = 0; wlc3 < strlen(welcome4); wlc3++)
	{
		if (welcome4[wlc3] != 'A' && welcome4[wlc3] != 'E')
		{
			printf(" %c", welcome4[wlc3]);
		}
		else
		{
			printf(" %c", welcome4[wlc3]);
		}
		Sleep(100);
	}
	ccolor(26);
}
void loadingbar(void)
{
	for (int i = 15; i <= 100; i += 5)
	{
		cls();

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t", i);

		printf("");

		for (int j = 0; j < i; j += 2)
		{
			ccolor(160 + j);
			printf(" ");
			ccolor(26);
		}
		Sleep(100);
		if (i == 90 || i == 50 || i == 96 || i == 83)
		{
			Sleep(100);
		}
	}
}

void middle1(void)
{
	printf("\n\n\n\n\n\n\n");
}

void middtab1(void)
{
	printf("\t\t\t\t\t");
}
