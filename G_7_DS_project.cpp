/*
  The password(bahirdar)

*/


/*
               ........Thank You For Using This  System........
           Group member’s name                                            Id
          1.Tadele Workie Mihretu                                   BDU1308433
		  2. Simachew Gedefaw Chekol                                BDU1308736
		  3. Kidanemariam mazengiaw                                BDU1307035
          4.Ermias Sintayehu Deresse                                BDU1307028
          5.brham Dessalegn Workie                                  BDU1307050
          6.Meron Gebresilassie Bahru                               BDU1311637
          7.Nuhamin Zelalem Getachew                                BDU1313860
          8.Samrawit Fikremariam                                    BDU1308042

               !    Departement of Software Engineering
               !----------------------------------------------!

*/


#include <iomanip>//for size 
#include<iostream>//for importing cin and cout key and others 
#include<conio.h>//for exit and getch
#include<time.h>//for 
#include<windows.h>//for color
#include<stdlib.h>//we used this header file for clear screen
using namespace std;
struct node {
	string first_name, middle_name,last_name;
	char Address[30];
	int Acc_no;
	float deposit;
	node *next;
	string gender;
	string Acc_type;
};
struct node *start=NULL;
void  Create_new_account();
void  Delete_account();
void search_by_account();
void  Withdraw();
void  Deposit();
void  Display();
void  Money_Transferring();
void  menu();
void  Add_at_the_end();
void delete_by_searching();
void  Modify_Account();
int dataTypeChecker(int n);
double dataTypeChecker(double  n);
int sender_Checker();
int receiver_Checker();
double amount;
int b;
int choice;
int account;
int main()

{

	char pass [8];
	
	  while(true)
	{
	  system("color 0C");
	  cout<<"  \n\t\t\t\t\t\t\t***************************************";
	  cout<<"  \n\t\t\t\t\t\t\t***************************************";
	  cout<<"\n\t\t\t\t\t\t\t-                                      -";
	  cout<<"\n\t\t\t\t\t\t\t-                  C                -";
	  cout<<"\n\t\t\t\t\t\t\t-         L                O           -";
	  cout<<"\n\t\t\t\t\t\t\t-      E                       M       -";
	  cout<<"\n\t\t\t\t\t\t\t-   W  TO BAHIR DAR UNIVERSITY   E     -";
	  cout<<"\n\t\t\t\t\t\t\t-   B                              S   -";
	  cout<<"\n\t\t\t\t\t\t\t-     I                          U     -";
	  cout<<"\n\t\t\t\t\t\t\t-        T                    p        -";
	  cout<<"\n\t\t\t\t\t\t\t-             C     A     M            -";
	  cout<<"\n\t\t\t\t\t\t\t-                                      -";
	  cout<<"\n\t\t\t\t\t\t\t***************************************";
	  cout<<"\n\t\t\t\t\t\t\t***************************************\n";
	  cout<<"\n\n";
	  	cout<<"\tEnter the appropriate password to login :";
	  	  int i=0;
	 	while(i<8){
	 		pass[i]=getch();
	 		cout<<"*";
	 		i++;
	 	}
	   if(pass[0]=='b'&&pass[1]=='a'&&pass[2]=='h'&&pass[3]=='i'&&pass[4]=='r'&&pass[5]=='d'&&pass[6]=='a'&&pass[7]=='r')
	 	break;
	    }
	

	char ta;
	system("Color 0A");

	cout<<endl<<"\t\t\t\t|****************************************************************|"<<endl;
	cout<<endl<<"\t\t\t\t|WELLCOME TO BANK CUSTOMER INFORMATION HANDLING  MANAGMENT SYSTEM|"<<endl;
	cout<<endl<<"\t\t\t\t|****************************************************************|"<<endl;


	do {
		cout<<"\t\t\t\t\t::Main Menu::\n\n";
		menu();
		cout<<"\n \tSelect your option  \n";
		cin>>choice;
		while (dataTypeChecker(choice) != 0 || choice < 1 || choice > 10) {
			cout << "Invalid choice, Choose what you want to do : ";
			cin >> choice;
		}
		{

		}
		switch(choice) {
			case 1 :
				Add_at_the_end();
				break;
			case 2 :
				delete_by_searching();
				break;
			case 3:
				search_by_account();
				break;
			case 4 :
				Deposit();
				break;
			case 5 :
				Withdraw();

				break;
			case 6 :
				Money_Transferring();
				break;
			case 7:
				Modify_Account();
				break;
			case 8 :
				Display();
				break;
			case 9 :
				menu();
				break;
			case 10 :
				if(choice==9) {
					exit(9);
				}
				break;

		}
		cout<<"Do you want to continue? ENTER (Y/N) to continue, ENTER any key to exit\n";
		cin>>ta;
	} while(ta=='Y'||ta=='y');

	cout<<"Thank you!\n";

	return 0;
};

void menu() {

	cout<<"\t\t\t\t\t  1.  Create new Account\n";
	cout<<"\t\t\t\t\t  2.  Delete(Close ) Account\n";
	cout<<"\t\t\t\t\t  3.  search Account\n";
	cout<<"\t\t\t\t\t  4.  Deposit\n";
	cout<<"\t\t\t\t\t  5.  withdraw\n";
	cout<<"\t\t\t\t\t  6.  Transferring money\n";
	cout<<"\t\t\t\t\t  7.  Modify An account\n";
	cout<<"\t\t\t\t\t  8.  All Account records\n";
	cout<<"\t\t\t\t\t  9.  go to Menu\n";
	cout<<"\t\t\t\t\t  10. Exit";

}

void  Add_at_the_end() {
	system("cls");
	node *temp1=start,*temp=new node;
	cout<<"Enter your information\n";
	cout<<"\tEnter your fist name:";
	cin>>temp->first_name;
	cout<<"\n\tEnter your middle name:";
	cin>>temp->middle_name;
	cout<<"\n\tEnter your last name:";
	cin>>temp->last_name;
	cout<<"\n\tEnter Gender :";
	cout<<"\n\tEnter F for female, M for male :";
again:
	cin >>temp->gender;
	if(temp->gender != "F" && temp->gender != "M")  {
		cout<<" You entered wrong letter, please enter again: ";
		goto again;
	}
	temp->Acc_no=(100 + (rand()%101));
	cout<<"\n\tEnter your Address ";
	cin>>temp->Address;
	cout<<"\n\tEnter Account Type (S/C):";
	cout<<"\n\tEnter capital  S for Saving, C current :";
	
type:
	cin>>temp->Acc_type;
	if(temp->Acc_type != "S" && temp->Acc_type != "C")  {
		cout<<" You entered wrong letter, please enter again: ";
		goto type;
	}
	cout<<"\n\tEnter your  intial deposit amount:";
	while(!(cin >> temp->deposit) || temp->deposit <50) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout<<" Wrong deposit amount, please enter again: ";
	}
	temp->next=NULL;
	if(start==NULL)
		start=temp;
	else {

		while(temp1->next!=NULL) {
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	cout<<"\n\nCongratulation Account is created";
	cout<<"\nFirst Name    :"<<temp->first_name;
	cout<<"\nMiddle Name   :"<<temp->middle_name;
	cout<<"\nLast Name     :"<<temp->last_name;
	cout<<"\nGender        :"<<temp->gender;
	cout<<"\nYour Address  :"<<temp->Address;
	cout<<"\nAccount number:"<<temp->Acc_no;
	cout<<"\nAccount type  :"<<temp->Acc_type;
	cout<<"\nBalance       :"<<temp->deposit<<"\n";

}


void delete_by_searching() {
	node *temp=start;
	node  *temp1;
	system("cls");
	cout<<"Enter the account you want to close \n";
c:
	cin>>account;
	while (dataTypeChecker(account) != 0 || account < 0 ) {
		cout << "\nWrong Account number, please enter the correct account number :\n ";
		cin >> account;
	}
	if(start==NULL) {
		cout<<"There is no recorede list :\n";
	} else {

		while(temp->Acc_no!=account) {

			temp1=temp;
			temp=temp->next;
		}
		if(temp==NULL) {
			cout<<"\nThe is no such account in this system :\n";
		} else {

			temp1->next=temp->next;
			delete temp;
			cout<<"\nAccount successfully deleted :\n";
		}

	}
}

void Display()

{

	system("cls");
	int i=1;
	node *temp=start;
	cout<<"\n\n";
	cout<<"\t\t==========================================+\n";
	cout<<"\t\t| All information  recorded       |\n";
	cout<<"\t\t==========================================+\n\n";
	if(temp==NULL)
		cout<<"\tThere is no list \n";
	else {
		cout<<"=============================================================================================================================================================================#\n";
		cout<<"Fist Name"<<setw(21)<<"Middle Name"<<setw(21)<<"last Name"<<setw(21)<<"Gender"<<setw(21)<<"Address"<<setw(21)<<"Account_number"<<setw(21)<<"Acount_type"<<setw(21)<<"balance"<<"\n";
		cout<<"==============================================================================================================================================================================#\n";

		while(temp!=NULL) {
			cout<<temp->first_name<<setw(21)<<temp->middle_name<<setw(21)<<temp->last_name<<setw(21)<<temp->gender<<setw(21)<<temp->Address<<setw(21)<<temp->Acc_no<<setw(21)<<temp->Acc_type<<setw(21)<<temp->deposit<<endl<<endl;
			temp=temp->next;
			i++;
		}
	}

}
void  Deposit() {

	system("cls");
	int count=0;
	node *temp=start;
	cout<<"\n\n\n\t\tThank you for selecting us  to get service from our system  :\n";
	cout<<"\n\tEnter your Account number :";
Depo:
	cin>>account;
	while (dataTypeChecker(account) != 0 || account < 0 ) {
		cout << "\nInvalid input, please enter the valid account number : ";
		cin >> account;
	}

	while(temp!=NULL) {
		if(temp->Acc_no==account) {
			count++;
			break;
		}

		temp=temp->next;
	}

	if(count==1) {

		cout<<"Enter the amount of money you want to deposit min (25) :";
		cin>>amount;
		while (dataTypeChecker(amount) != 0 || amount < 25 ) {
			cout << "\nMin deposit is 25: ";
			cin>>amount;
		}
		temp->deposit=temp->deposit+amount;
		cout<<"\n\n You successfully deposit your money and your current status :";
		cout<<"\nFirst Name    :"<<temp->first_name;
		cout<<"\nMiddle Name   :"<<temp->middle_name;
		cout<<"\nLast Name     :"<<temp->last_name;
		cout<<"\nGender        :"<<temp->gender;
		cout<<"\nYour Address  :"<<temp->Address;
		cout<<"\nAccount number:"<<temp->Acc_no;
		cout<<"\nAccount type  :"<<temp->Acc_type;
		cout<<"\nBalance       :"<<temp->deposit<<"\n";
	} else {

		cout<<"Your  entered account number is not present on our system , plelase  enter the correct one: \n";
		temp=start;
		goto Depo;


	}
}

void Withdraw() {
	system("cls");
	int count=0;
	node *temp=start;
	cout<<"\n\n\t\tThank you for selecting us  to get service from our system  :\n";
	cout<<"\nEnter your account number: ";
z :
	cin>>account;
	while (dataTypeChecker(account) != 0 || account < 0 ) {
		cout << "Invalid input, please enter the valid account number : ";
		cin >> account;
	}


	while(temp!=NULL) {
		if(temp->Acc_no==account) {
			count++;

			break;
		}

		temp =temp->next;
	}
	if(count==1) {
		cout<<"Enter the amout of money you want to withdraw:";
		cin>>amount;
		while (dataTypeChecker(amount) != 0 || amount < 25 ) {
			cout << "\nMin Withdraw is 25: ";
			cin >> amount;
		}
		temp->deposit=temp->deposit-amount;
		cout<<"\nYou successfully withdraw your money";


		cout<<"\nFirst Name    :"<<temp->first_name;
		cout<<"\nMiddle Name   :"<<temp->middle_name;
		cout<<"\nLast Name     :"<<temp->last_name;
		cout<<"\nGender        :"<<temp->gender;
		cout<<"\nYour Address  :"<<temp->Address;
		cout<<"\nAccount number:"<<temp->Acc_no;
		cout<<"\nAccount type  :"<<temp->Acc_type;
		cout<<"\nBalance       :"<<temp->deposit<<"\n";


	} else {

		cout<<"\nYour entered  account number is not present on our system, please enter a gain";
		temp=start;
		goto z;


	}
}
void  Money_Transferring() {
	node *temp;
	temp=start;
	node *temp1=start;
	int sender=sender_Checker( );
	int receiver= receiver_Checker();

	if(sender!=0&&receiver!=0) {
		while(temp!=NULL) {
			if(temp->Acc_no==sender) {
				temp->deposit =temp->deposit-amount;
				cout<<"\nYou successfully transfer the money :\n\n";
				cout<<"\nFirst Name    :"<<temp->first_name;
				cout<<"\nMiddle Name   :"<<temp->middle_name;
				cout<<"\nLast Name     :"<<temp->last_name;
				cout<<"\nGender        :"<<temp->gender;
				cout<<"\nYour Address  :"<<temp->Address;
				cout<<"\nAccount number:"<<temp->Acc_no;
				cout<<"\nAccount type  :"<<temp->Acc_type;
				cout<<"\nBalance       :"<<temp->deposit<<"\n";
				break;
			}
			temp=temp->next;

		}
		while(temp1!=NULL) {
			if(temp1->Acc_no==receiver)
				temp1->deposit=temp1->deposit+amount;
			temp1=temp1->next;
		}
	} 
	else if(sender==0 && receiver!=0) {
		cout<<"\nThe sender account is not in our system \n:";
	    } 
	else if(sender!=0 && receiver==0) {

		cout<<"\nThe receiver account is not present in our system :\n";
         	} 
	else
	   {
		
		cout<<"\nThe sender and the reciver account are  not present in our system :\n ";
	  }  


}

void search_by_account() {

	node *temp;
	temp=start;
	int count=0;
	system("cls");
	cout<<"\Enter the account number you want to search:";
search :
	cin>>account;
	while (dataTypeChecker(account) != 0 || account < 0 ) {
		cout << "\nWrong Account number, please enter the correct account number :\n ";
		cin >> account;
	}
	while(temp!=NULL) {
		if(temp->Acc_no==account) {
			count++;
			break;
		}
		temp=temp->next;
	}


	if(count==1) {
		cout<<"The current status of the searched perosn is :\n";
		cout<<"\nFirst Name    :"<<temp->first_name;
		cout<<"\nMiddle Name   :"<<temp->middle_name;
		cout<<"\nLast Name     :"<<temp->last_name;
		cout<<"\nGender        :"<<temp->gender;
		cout<<"\nYour Address  :"<<temp->Address;
		cout<<"\nAccount number:"<<temp->Acc_no;
		cout<<"\nAccount type  :"<<temp->Acc_type;
		cout<<"\nBalance       :"<<temp->deposit<<"\n";
	} else {
		cout<<"The searched  person is not found on our branch \n";
		temp=start;
		goto search;
	}

}
void  Modify_Account() {

	system("cls");
	int n;
	int count=0;
	node *temp = start;
	char name[10];
	cout<<"\t\t1. For modifying your fisrt name \n";
	cout<<"\t\t2. For modifying your middle name \n";
	cout<<"\t\t3. For modifying your last name \n\n";
	cout<<"What you want to modify,Enter your option:";
	cin>>n;
	cout<<"\nEnter your account number  also";

update:
	cin>>account;
	while (dataTypeChecker(account) != 0 || account < 0 ) {
		cout << "\nInvalid input, please enter the valid account number : ";
		cin >> account;
	}

	while(temp!=NULL) {
		if(account==temp->Acc_no) {
			count++;
			switch(n) {

				case 1:
					cout<<"\nEnter your new first name:";
					cin>>name;
					temp->first_name=name;
					break;
				case 2:
					cout<<"\nEnter your new first name:";
					cin>>name;
					temp->middle_name=name;
					break;
				case 3:
					cout<<"\nEnter your new first name:";
					cin>>name;
					temp->last_name=name;
					break;

			}
		}


		temp=temp->next;
	}
	if(count==1) {
		cout<<"\nYour information is successfully updated :\n";

	} else {
		cout<<"\nyou entered wrong account number , pls enter again:\n";
		temp=start;
		goto update;
	}


}

double  dataTypeChecker(double n) {
	bool cond;
	double x;
	cond = cin.fail();
	x = cond;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return x;
}


int sender_Checker( ) {
	int m;
	node *temp=start;
	cout<<"Enter sender account number \n";
again :
	cin>>account;
	while (dataTypeChecker(account) != 0 || account < 0 ) {
		cout << "\nInvalid input, please enter the valid account number : ";
		cin >> account;
	}
	while(temp!=NULL) {
		if(temp->Acc_no==account)

		{
			cout<<"Enter the amount of money you want to withdraw:";
			cin>>amount;
			while (dataTypeChecker(amount) != 0 || amount < 25 ) {
				cout << "\nMin Withdraw is 25: ";
				cin >> amount;
			}

			if(temp->deposit>amount+25) {
				m=account;
				break;
			}

		} else {
			m=0;
		}
		temp=temp->next;
	}

	return m;
}
int receiver_Checker() {
	int m;
	int Account_re;
	node *temp=start;
	cout<<"\nEnter the  Account number of receiver \n";
ab :
	cin>>Account_re;
	while (dataTypeChecker(Account_re) != 0 || Account_re < 0 ) {
		cout << "\nInvalid input, please enter the valid account number : ";
		cin >> Account_re;
	}
	while(temp!=NULL) {
		if(temp->Acc_no==Account_re) {
			m=Account_re;
			break;

		} else {

			m=0;
		}
		temp=temp->next;
	}

	return m;
}


int dataTypeChecker(int n) {
	bool cond;
	int x;
	cond = cin.fail();
	x = cond;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return x;
}





