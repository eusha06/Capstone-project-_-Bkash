
// Bank Management system (BKASH):
// FINAL CODE


#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct pass {
	char username[50];
	int date, month, year;
	char pnumber[15];
	char nidnum[20];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char password[50];
	int total = 0;
	int count = 0;
};




struct pass currentUser;


struct money {
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass {
	char password[50];
};


// Declaring all the functions

void transfermoney(void);
void display(char*);
void mainpage(void);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);
void deposit_money(void);
void withdraw_money(void);
void checkDetail(void);
void LastDetail(void);
void transaction_details(void);
void account_details(void);
void mobile_recharge(void);
void edufee(void);
void payment(void);
void password_change(void);

 int main(){
    FILE *ptr = fopen("Account.txt", "w");
 int i, a, b, choice;
	int passwordlength;

gotoxy(24, 10);

	for (i=0; i<62; i++){
        printf("*");
	}
	gotoxy(19,11);
	printf("     *");

	gotoxy(82,11);
	printf("   *");

	gotoxy(82,12);
	printf("   *");
	gotoxy(85,13);
	printf("*");
	gotoxy(21, 12);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set text color to red
    printf("   *");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);


	printf("\t\tWELCOME TO BKASH BANKING SYSTEM\n\n");

	 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	 gotoxy(21,13);
	 printf("   *");

	gotoxy(18, 14);


	printf("\t");
	for (i=0; i<62; i++){
        printf("*");
	}

	 printf("\n\nLoading");

    for (i = 0; i < 3; i++) {
        printf(".");
        Sleep(100); // Delay for 1 second
    }

mainpage();

 }

 void mainpage(void){
int choice;
     system("cls");
 gotoxy(20, 13);
	printf("1.... CREATE A BIKASH ACCOUNT");

	gotoxy(20, 15);
	printf("2.... ALREADY AN USER? SIGN IN");
	gotoxy(20, 17);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE.. ");



	scanf("%d", &choice);


// choice made

	switch (choice) {
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		account();
		break;

	case 2:
		login();
		break;

	case 3:
    exit(0);
    break;

case 4:

    break;


		getch();
	}

 }

void account(void) {
 char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	//struct userpass p1;

	//struct userpass u2;

    // Opening file to
    // write data of a user
    fp = fopen("username.txt", "ab");

      printf("\n\n!!!!!CREATE ACCOUNT!!!!!\n");



    printf("\nFIRST NAME: ");
    fflush(stdin);
    scanf("%[^\n]%*c", u1.fname);
    //u1.fname[strcspn(u1.fname, "\n")] = '\0';
    fflush(stdin);

    printf("\nLAST NAME: ");
    scanf("%[^\n]s", u1.lname);
fflush(stdin);

    printf("\nFATHER's NAME: ");
    scanf("%[^\n]%*c", u1.fathname);
    fflush(stdin);

    printf("\nMOTHER's NAME: ");
    scanf("%[^\n]%*c", u1.mothname);
    fflush(stdin);
  //  getchar();

    printf("\nDATE OF BIRTH\n");
    printf("DATE: ");
    scanf("%d", &u1.date);
    printf("MONTH: ");
    scanf("%d", &u1.month);
    printf("YEAR: ");
    scanf("%d", &u1.year);
    if (u1.year >2007){
        printf("Your age is under 18 years old\n");
        printf("Please try again\n");

	getch();
	mainpage();
    }


    getchar();

    printf("\nNID NUMBER: ");
    scanf("%[^\n]%*c", u1.nidnum);
    int dhori = 0;
    FILE *f;

    f = fopen("te.txt", "r+");
    if (f == NULL) {
        f = fopen("te.txt", "w");
        if (f == NULL) {
            fseek(f, 0, SEEK_END);
            fputs(u1.nidnum, f);
            fputs("\n", f);
            fclose(f);
        }
        fputs(u1.nidnum, f);
        fputs("\n", f);
        fclose(f);
    } else {
        char s[20];
        while (fgets(s, sizeof(s), f)) {
            s[strcspn(s, "\n")] = 0;
            if (strcmp(s, u1.nidnum) == 0) {
                dhori++;
                break;
            }
        }
        if (dhori > 0) {
            printf("The NID number is already taken.\n");
            printf("Please try again\n");
            fclose(f);
            mainpage();
        } else {

            fseek(f, 0, SEEK_END);
            fputs(u1.nidnum, f);
            fputs("\n", f);
            fclose(f);
        }
    }
    fflush(stdin);

    printf("\nPHONE NUMBER: ");
   scanf("%[^\n]%*c", u1.pnumber);
    fflush(stdin);


    printf("\nUSERNAME: ");
   scanf("%s", u1.username);
    fflush(stdin);
 //printf("%s new", u1.username);
    printf("\nPASSWORD: ");
for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			u1.password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	// new
strcpy(currentUser.fname, u1.fname);
    strcpy(currentUser.lname, u1.lname);
    strcpy(currentUser.fathname, u1.fathname);
    strcpy(currentUser.mothname, u1.mothname);
    strcpy(currentUser.nidnum, u1.nidnum);
    strcpy(currentUser.pnumber, u1.pnumber);
    strcpy(currentUser.username, u1.username);
    strcpy(currentUser.password, u1.password);
    currentUser.date = u1.date;
    currentUser.month = u1.month;
    currentUser.year = u1.year;
 currentUser.total = u1.total;
currentUser.count = u1.count;



    fwrite(&u1, sizeof(u1), 1, fp);

    fclose(fp);

    accountcreated();
}



// Successful account creation
void accountcreated(void)
{
	int i;
	char ch;
	system("cls");
	printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(40, 10);
	printf("\n\n\n\t\t\t\t\t\t\t\tWELCOME TO BIKASH.....\n");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch();
	login();
}


// Login function to check


void login(void)
{
	system("cls");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;
	//struct pass u1;
	// struct userpass u2;
	fflush(stdin);
	// Opening file of
	// user data
	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34, 2);
	 SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf(" \t\tACCOUNT LOGIN ");
	 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	gotoxy(7, 5);
	printf("\t\t***********************************************"
		"********************************");
printf("\n");
	gotoxy(35, 10);
	printf("\t\t==== LOG IN ====");


//printf("%s",currentUser.password);
	// Take input
	gotoxy(35, 12);
	printf("USERNAME.. ");

scanf("%s", username);

	gotoxy(35, 14);
	printf("PASSWORD..");
for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	if (strcmp(currentUser.username,username)==0){


			loginsu();
			//fflush(stdin);
			display(username);
			fclose(fp);
	}
	else {
        printf("Your username is not matched\n");

	printf("Please try again\n");

	getch();
	login();
	}

	// Closing the file

}



 //Redirect after
// successful login
void loginsu(void)
{
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue......");

	getch();
}



// Display function to show the
// data of the user on screen
void display(char username1[])
{
system("cls");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	struct pass u1;
	if (fp == NULL) {
		printf("error in opening file");
	}
	gotoxy(0, 5);
 SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("\t\t\t\t\t\t\tHOME ");
	gotoxy(0, 7);
	 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("\t\t\t\t");
	for (int i=0; i<60; i++){
        printf("*");
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	gotoxy(30, 7);
	printf("CURRENT AMOUNT %d Tk\n,", currentUser.total);


	 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

	gotoxy(30,11);
	printf(" 1..... Account Details");
	gotoxy(30,12);
	printf(" 2....PAYMENT\n\n");
	gotoxy(30,13);
	printf(" 3....CASH IN ");
	gotoxy(30,14);
	printf(" 4....SEND MONEY");

	gotoxy(30,15);
	printf(" 5......CASH OUT MONEY");
	gotoxy(30,16);
	printf(" 6......ALL TRANSACTION DETAILS");
	gotoxy(30,17);
    printf(" 7......MOBILE RECHARGE");
    gotoxy(30,18);
    printf(" 8......EDUCATION FEE");
    gotoxy(30,19);
printf(" 9....LOG OUT");
gotoxy(30,20);
printf(" 10......password change");
gotoxy(30,21);

	printf(" ENTER YOUR CHOICES..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		 account_details();
	   break;

	case 2:
		payment();
		break;

	case 3:
		deposit_money();
        break;

        case 4:
	   transfermoney();
	   break;

        case 5:
            withdraw_money();
            break;

        case 6:
            transaction_details();
            break;

        case 7:
            mobile_recharge();
            break;

        case 8:
            edufee();
            break;

        case 9:
            logout();
		login();
		break;

		case 10:
            password_change();
            break;

	default:
	printf("................Invalid Choice...........\n");
	getch();
    display(currentUser.username);

	}
}


void account_details(void){
system("cls");
 printf("\t\t\t==========================================\n");
    printf("\t\t\t            ACCOUNT DETAILS\n");
    printf("\t\t\t==========================================\n\n");
	//gotoxy(30, 1);
	gotoxy(30,3);
	fflush(stdin);
	  printf("\n\nWELCOME, %s\n\n\n", currentUser.username);
	  gotoxy(55, 4);
    printf("NAME         : %s %s\n", currentUser.fname, currentUser.lname);
    gotoxy(55, 6);
    printf("FATHER's NAME: %s\n", currentUser.fathname);
    gotoxy(55, 8);
    printf("MOTHER's NAME: %s\n", currentUser.mothname);
    gotoxy(55, 10);
    printf("NID NUMBER   : %s\n", currentUser.nidnum);
    gotoxy(55,12);
    printf("MOBILE NUMBER: %s\n", currentUser.pnumber);
    gotoxy(55,14);
    printf("DATE OF BIRTH: %d-%d-%d\n", currentUser.date, currentUser.month, currentUser.year);


    printf("Press any key to continue.\n");
  getch();
  display(currentUser.username);
}

// Function to transfer

void transfermoney(void)
{
    system("cls");
     FILE *ptr = fopen("Account.txt", "a");
    int ac,trans_amt,i,j;
    time_t tm;
    time(&tm);
    printf("*****TRANSFERRING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

    if (currentUser.total < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        currentUser.total = currentUser.total - trans_amt;
        	gotoxy(0, 24);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 27);
	printf("transferring Money, Please wait..");

	gotoxy(10, 27);
	for (i = 0; i < 60; i++) {
		for (j = 0; j < 120000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(32, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....\n");
        printf("Current balance : %d\n", currentUser.total);
        fprintf(ptr, "\nTk %d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        currentUser.count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
    display(currentUser.username);


}



void deposit_money(void){

	system("cls");
	FILE *ptr = fopen("Account.txt", "a");
	int i,d;
 time_t tm;
    time(&tm);
    printf("*****DEPOSITING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("AMOUNT : ");
    scanf("%d",&d);
    currentUser.total += d;
    gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait..");

    printf("*****Money Deposited Successfully****\n");
    printf("Current Balance : %d\n",currentUser.total);

    fprintf(ptr,"\nTk %d had been Added in the account\n",d);
    fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
currentUser.count++;

printf("Press any key...");

	getch();

	display(currentUser.username);

}


void withdraw_money(void){

    system("cls");
     FILE *ptr = fopen("Account.txt", "a");
int i,j,ac,trans_amt;
time_t tm;
    time(&tm);
    printf("*****WITHDRAWING MONEY*****\n");
    for ( i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &ac);

    if (currentUser.total < ac)
    {
        printf("****Insufficient balance*****\n");
    }
    else
    {
        currentUser.total = currentUser.total - ac;
         gotoxy(0, 16);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

        gotoxy(0, 29);
	printf("Withdrawing the money,\n Please wait..");

        printf("\n*****Money withdrawn successful*****\n");
        printf("Current balance : %d\n", currentUser.total);
        fprintf(ptr, "\nTk%d had been withdrawn from your account \n", ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        currentUser.count++;
    }
    fclose(ptr);
    printf("Press any key....\n");

    getch();
display(currentUser.username);



}


void transaction_details(void)
{

    system("cls");
int i;
    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("TRANSACTION DETAILS\n");
      for (i=0; i<50; i++){
        printf("-");
      }

        printf("\n*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
         for (i=0; i<50; i++){
        printf("-");
      }
        printf("\n%d transactions have been made from your account \n", currentUser.count);
        while (c != EOF) // EOF=End of file
        {
            printf("%c", c);
            c = fgetc(ptr);

        }
    }
printf("ClICK ANYWHERE TO CONTINUE..........\n");
    getch();
    display(currentUser.username);
}


void mobile_recharge(void){

 system("cls");
     FILE *ptr = fopen("Account.txt", "a");
    int trans_amt,i,j;
    char ac[12];
    time_t tm;
    time(&tm);
    printf("*****MOBILE RECHARGING*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the mobile number for recharge : ");
    scanf("%s", &ac);
    printf("\nEnter the amount you want to recharge \n");
    scanf("%d", &trans_amt);

    if (currentUser.total < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        currentUser.total = currentUser.total - trans_amt;
        	gotoxy(0, 18);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 20);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 21);
	printf("Recharge ongoing, Please wait..");

	gotoxy(10, 27);
	for (i = 0; i < 60; i++) {
		for (j = 0; j < 120000; j++) {
			j++;
			j--;
		}
		printf("*");
	}
printf("\n");
	gotoxy(35, 40);
	printf("RECHARGE SUCCESSFUL....\n");
        printf("\nCurrent balance : %d\n", currentUser.total);
        fprintf(ptr, "\nTk %d had been mobile recharge from your account to %s\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        currentUser.count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
    display(currentUser.username);


}



void edufee(void){
    system("cls");
     FILE *ptr = fopen("Account.txt", "a");
    int trans_amt,i,j;
    char ac[50];
    time_t tm;
    time(&tm);
    printf("*****EDUCATIONAL FEE PAYMENT*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the institution name in which you want to transfer the money : ");
   fflush(stdin);
   gets(ac);
   fflush(stdin);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

    if (currentUser.total < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        currentUser.total = currentUser.total - trans_amt;
        	gotoxy(0, 24);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	printf("\t\t\t\t\t\tTransferring Money, Please wait..");

	gotoxy(20, 27);
	for (i = 0; i < 60; i++) {
		for (j = 0; j < 120000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(22, 30);
	printf("SUCCESSFULLY TRANSFERRED....\n");
        printf("Current balance : %d\n", currentUser.total);
        fprintf(ptr, "\nTk %d had been transferred from your account to %s\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        currentUser.count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
    display(currentUser.username);

}



void payment(void){

 system("cls");
     FILE *ptr = fopen("Account.txt", "a");
    int trans_amt,i,j;
    char ac[50];
    time_t tm;
    time(&tm);
    printf("*****PAYMENT FEE *****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the institution name in which you want to transfer the money : ");
   fflush(stdin);
   gets(ac);
   fflush(stdin);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

    if (currentUser.total < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        currentUser.total = currentUser.total - trans_amt;
        	gotoxy(0, 24);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	printf("\t\t\t\t\nTransferring Money, Please wait............\n");

	for (i = 0; i < 60; i++) {
		for (j = 0; j < 120000; j++) {
			j++;
			j--;
		}
		printf("*");
	}
printf("\n");
	gotoxy(22, 30);
	printf("SUCCESSFULLY TRANSFERRED....\n");
        printf("Current balance : %d\n", currentUser.total);
        fprintf(ptr, "\nTk %d had been transferred from your account to %s\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        currentUser.count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
    display(currentUser.username);



}

// password change feature

void password_change(void) {
    system("cls");
    FILE* ptr = fopen("Account.txt", "a");
    char s[50];
    char p[50];
    int d, i;

    gotoxy(20, 5);
    printf("1.. Change the current password\n");
    gotoxy(20,7);
    printf("2.. Back to the Menu bar\n");

    gotoxy(20, 9);
    printf("Enter your choice: \n");
    scanf("%d", &d);

    switch (d) {
    case 1:
        printf("ENTER THE PREVIOUS PASSWORD: ");
        scanf("%s", s);
        if (strcmp(s, currentUser.password) == 0) {
            printf("New Password : \n");
            scanf("%s", s);
            printf("Rewrite the new password: \n");
            scanf("%s", p);
            if (strcmp(s, p) == 0) {
                strcpy(currentUser.password, s);
                printf("Password Change Successful....\n");
                printf("Click anywhere to continue....");
                getch();
                display(currentUser.username);
            } else {
                printf("Given Password doesn't match.\n");
                getch();
                password_change();
            }
        } else {
            printf("YOUR GIVEN PASSWORD DOESN'T MATCH THE PREVIOUS PASSWORD.\n PLEASE TRY AGAIN.....\n");
            getch();
            password_change();
        }

        break;

    case 2:
        getch();
        display(currentUser.username);
        break;

    default:
        password_change();
    }

    getch();
    display(currentUser.username);

}




// Logout function to bring
// user to the login screen
void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 2500000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}
