#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


//while(fscanf(ke,"%s %s %s",&(p.First_name),&(p.Second_name),&(p.age),&(p.Gender),&(p.problem),&(p.DoctorName))!=EOF)
//printf("%s %s %s %s %s %s",p.First_name,p.Second_name,p.age,p.Gender,p.problem,p.DoctorName); 


void gotoxy(short x,short y)
{
	COORD pos = { x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct patient 
{
	// features of patient
	char First_name[20];
	char Second_name[20];
	char age[3];
	char problem[20];
	char DoctorName[20];
	char Gender[20];
};
struct patient p;
/////////////////////////////////////////////////
void welcome_screen(){
	printf("\n\n\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("\t\t  -\t\t\t\t\t\t\t     -\n");
	printf("\t\t  =\t\t\t\t\t\t\t     =\n");
	printf("\t\t  -\t\tWelcome to Ruslan's Hospital\t\t     -\n");
	printf("\t\t  =\t\t\t\t\t\t\t     =\n");
	printf("\t\t  -\t\t\t\t\t\t\t     -\n");
	printf("\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n\n");
	
	printf("\t\t\t   <<<--- USE ANY KEY FOR CONTINUE --->>>");
	
	getch();	
};
//////////////////////////////////////////////////
void header(){
	printf("\n\n\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
	printf("\t\t\t\t\tRuslan's Hospital\t\t   \n\n");
	printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n\n");
};
/////////////////////////////////////////////////////////////
void login_screen(){
	
	header();
	
	printf("\t\t\t\t--------> SIGN IN <--------\n\n");
	
	
	int keep_going = 0;
	char password[5];
	char user_name[15];
	// Reception's account information
	char original_password[15] = "2021"; 
	char original_username[15] = "Ruslan";
	
	do{	
		printf("\t\t\t\tPlease enter the username: ");
		scanf("%s",&user_name);
		
		printf("\t\t\t\tPlease enter the password: ");		
		scanf("%s",&password);
		if(strcmp(user_name,original_username)==0 && strcmp(password,original_password)==0) //are they same?
		{
			printf("\t\t\t\tLogin succesfull...");
			getch();
			main_menu();
			break;
		}
		else
		{
			printf("\t\t\t\tIncorrect password or username. Try again\n\n");
			keep_going++;
		}	
	}while(keep_going<=2);
	
	if(keep_going>2)
	printf("\t\t\t\tYou enter wrong informations several times. You cannot login again..."); // limit for entring to account
	getch();
	ex_it();
};
//////////////////////////////////////////////////////
void add(){	
	
	system("cls");
	header();
	
	///////////////////////////// Adding patient info
	FILE *r;	// open file(database)
	r = fopen("C:\\Users\\User\\Desktop\\Recording4.dat","a");
	
	int h;
			
	gotoxy(16,10);
	printf("====================== ADDING PATIENT ===================\n\n\n\n");		
	//***************add first name***************
	name:
	printf("\t\tEnter the name: ");
	scanf("%s",&(p.First_name));
	p.First_name[0]=toupper(p.First_name[0]);
	
	if(strlen(p.First_name) > 20 || strlen(p.First_name)<2)//checking length
	{
		printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
		goto name;
	}
	else
	{	
		for(h = 0;h<strlen(p.First_name);h++)// checking being alphabetic 
		{ 
			if(isalpha((p.First_name[h]))==0)
			{
				printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
				goto name;
			}
		}
	}	
	//***************add Last name***************
	l_name:
	printf("\t\tEnter the last name: ");
	scanf("%s",&(p.Second_name));	
	p.Second_name[0]=toupper(p.Second_name[0]);
	
	if(strlen(p.Second_name) > 20 || strlen(p.Second_name)<2)
	{
		printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
		goto l_name;
	}
	else
	{
		int h;
		
		for(h = 0;h<strlen(p.Second_name);h++){
			if(isalpha(p.Second_name[h])==0)
			{
				printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
				goto l_name;
			}
		}
	}		
	//***************add age***************
	age:
	printf("\t\tEnter age: ");
	scanf("%s",&(p.age));
	
	if(p.age[0]=='0' || strlen(p.age)>=3 || strlen(p.age)<0)
	{
		printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
		goto age;
	}
		
	int i;
	
	for(i=0;i<strlen((p.age));i++) 
	{
		if(isdigit(p.age[i])==0) //checking numeric character
		{
			printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
			goto age;
		}
	}
		//*******************Add gender**************
	Gender:
	printf("\t\tEnter Gender: ");
	scanf("%s",(p.Gender));
	
	p.Gender[0]=toupper((p.Gender[0]));
	
	if(strlen(p.Gender) > 20 || strlen(p.Gender)<2)
	{
		printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
		goto Gender;
	}
	else
	{
		int h;
		
		for(h = 0;h<strlen(p.Gender);h++){
			if(isalpha(p.Gender[h])==0)
			{
				printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
				goto Gender;
			}
		}
	}
	
	//*******************Add problem***************
	problem:
	
	printf("\t\tWhat is patient's problem?");
	scanf("%s",(p.problem));
	
	p.problem[0]=toupper((p.problem[0]));
	
	if(strlen(p.problem) > 20 || strlen(p.problem)<2)
	{
		printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
		goto problem;
	}
	else
	{
		int h;
		
		for(h = 0;h<strlen(p.problem);h++){
			if(isalpha(p.problem[h])==0)
			{
				printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
				goto problem;
			}
		}
	}	
	//**************Add Doctor******************
	
	Doctor:
	
	printf("\n\t\t\t\t1.Dr.Joe --> Simple problems\n\t\t\t\t2.Dr.Jasmine --> Head problems\n\t\t\t\t3.Dr.Henry --> Ear problems\n\t\t\t\t4.Dr.Dispenza --> Heart problems\n\t\t\t\t5.Dr.Robert --> Skin problems\n\n");
	
	printf("\t\tEnter doctor's name:(without Dr.) ");
	scanf("%s",(p.DoctorName));
	
	p.DoctorName[0]=toupper((p.DoctorName[0]));
	
	if(strlen(p.DoctorName) > 20 || strlen(p.DoctorName)<2)
	{
		printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
		goto Doctor;
	}
	else
	{
		int h;
		
		for(h = 0;h<strlen(p.DoctorName);h++){
			if(isalpha(p.DoctorName[h])==0)
			{
				printf("\n\t\t\t\tOoops...Wrong input.Try again\n\n");
				goto Doctor;
			}
		}
	}	
	fprintf(r," %s %s %s %s %s %s\n",(p.First_name),(p.Second_name),(p.age),(p.Gender),(p.problem),(p.DoctorName)); //writing informations to file(database)
	
	printf("SUCCESSFUL ADDITION ...\n");	
	getch();
	
	fclose(r);//closing open files
	main_menu();	
};
void search(){
	
	FILE *ke;
	ke = fopen("C:\\Users\\User\\Desktop\\Recording4.dat","r");
	
	char name[20];
	int row,count,fnd;
	
	again:
	
		system("cls");
		header();
		
		gotoxy(16,10);
		printf("====================== SEARCHING PATIENT ===================");	
		gotoxy(30,13);
		printf("Enter the name of patient: ");
		scanf("%s",name);
		//fflush(stdin);	
		name[0]= toupper(name[0]);
			
		system("cls");
		header();
		
		gotoxy(16,10);
		printf("======================== FOUND RESULT =====================");	
		
		gotoxy(1,13);
		printf("No.");
		gotoxy(6,13);
		printf("Full name");
		gotoxy(25,13);	
		printf("Gender");
		gotoxy(35,13);
		printf("Age");
		gotoxy(41,13);
		printf("Problem");
		gotoxy(55,13);
		printf("Doctor name\n");
		printf("========================================================================================\n");
		row = 15;
		count = 1;
		fnd = 0;
		
		while(fscanf(ke,"%s %s %s %s %s %s",&(p.First_name),&(p.Second_name),&(p.age),&(p.Gender),&(p.problem),&(p.DoctorName))!=EOF) // scaning till the end of file
			{
				if(strcmp(p.First_name,name)==0)
				{
					gotoxy(1,row);
					printf("%d.",count);
					gotoxy(6,row);
					printf("%s %s",p.First_name,p.Second_name);
					gotoxy(25,row);
					printf("%s",p.Gender);
					gotoxy(35,row);
					printf("%s",p.age);
					gotoxy(41,row);
					printf("%s",p.problem);
					gotoxy(55,row);
					printf("%s",p.DoctorName);
					row++;
					count++;
					fnd++;
				}
			}
			if(fnd == 0)
			{
				system("cls"); //clean screen
				header();
				gotoxy(37,15);
				printf("PATIENT NOT FOUND...\n");			
			}			
			fclose(ke); //close file
			getch(); //get character for passing that screen
			main_menu();	
};
int ex_it(){
	
	system("cls"); //clean screen
	header();
	printf("Thanks for all of operations...");
	getch();
	return 0;	
};

void list(){
	
	FILE *r;
	r = fopen("C:\\Users\\User\\Desktop\\Recording4.dat","r");
	int row,count;
	system("cls");
	header();
	
	gotoxy(16,10);
	printf("====================== LIST OF PATIENTS ====================");	
	gotoxy(1,13);
	printf("No.");
	gotoxy(6,13);
	printf("Full name");
	gotoxy(25,13);	
	printf("Gender");
	gotoxy(35,13);
	printf("Age");
	gotoxy(41,13);
	printf("Problem");
	gotoxy(55,13);
	printf("Doctor name\n");
	printf("========================================================================================\n");
	row = 15;
	count = 1;
	while(fscanf(r," %s %s %s %s %s %s \n ",&(p.First_name),&(p.Second_name),&(p.age),&(p.Gender),&(p.problem),&(p.DoctorName))!=EOF)
	{	
		gotoxy(1,row);
		printf("%d.",count);
		gotoxy(6,row);
		printf("%s %s",p.First_name,p.Second_name);
		gotoxy(25,row);
		printf("%s",p.Gender);
		gotoxy(35,row);
		printf("%s",p.age);
		gotoxy(41,row);
		printf("%s",p.problem);
		gotoxy(55,row);
		printf("%s",p.DoctorName);
		row++;
		count++;
	}

	fclose(r);
	getch();
	main_menu();	
}

void edit(){
	system("cls");
	header();
	gotoxy(16,10);
	printf("====================== EDIT INFORMATION OF PATIENT ====================\n\n\n");		
	
	FILE *ke;
	FILE *update;
	
	update = fopen("C:\\Users\\User\\Desktop\\UpdateRec.dat","a");
	ke = fopen("C:\\Users\\User\\Desktop\\Recording4.dat","r");
	
	char name[20];
	
	printf("\t\t\t\tEnter the name of patient: ");
	scanf("%s",name);
	name[0]= toupper(name[0]);
	
	int fnd;
	fnd=0;
	
	while(fscanf(ke,"%s %s %s %s %s %s\n",&(p.First_name),&(p.Second_name),&(p.age),&(p.Gender),&(p.problem),&(p.DoctorName))!=EOF)
		{
			if(strcmp(p.First_name,name)!=0)
			{				
				fprintf(update,"%s %s %s %s %s %s \n",p.First_name,p.Second_name,p.age,p.Gender,p.problem,p.DoctorName);				
			}
			else
			{
				fnd = 1;
			}
		}//EndOfLoop
		
		if(fnd == 0)
		{
			printf("\t\t\t\tRecord not found!");
		}		
		else
		{					
			printf("\t\t\t\tEnter new name: ");
			scanf("%s",&(p.First_name));	
			p.First_name[0]=toupper(p.First_name[0]);
			
			printf("\t\t\t\tEnter new last name: ");
			scanf("%s",&(p.Second_name));	
			p.Second_name[0]=toupper(p.Second_name[0]);
			
			printf("\t\t\t\tEnter new age: ");
			scanf("%s",&(p.age));
			
			printf("\t\t\t\tEnter new Gender: ");
			scanf("%s",&(p.Gender));	
			p.Gender[0]=toupper(p.Gender[0]);
			
			printf("\t\t\t\tEnter new problem: ");
			scanf("%s",&(p.problem));	
			p.problem[0]=toupper(p.problem[0]);
			
			printf("\n\t\t\t\t1.Dr.Joe --> Simple problems\n\t\t\t\t2.Dr.Jasmine --> Head problems\n\t\t\t\t3.Dr.Henry --> Ear problems\n\t\t\t\t4.Dr.Dispenza --> Heart problems\n\t\t\t\t5.Dr.Robert --> Skin problems\n\n");
			printf("\t\t\t\tEnter doctor's name: ");
			scanf("%s",&(p.DoctorName));	
			p.DoctorName[0]=toupper(p.DoctorName[0]);
	
			fprintf(update,"%s %s %s %s %s %s",p.First_name,p.Second_name,p.age,p.Gender,p.problem,p.DoctorName);
			
			fclose(ke);	
			fclose(update);
								
			remove("C:\\Users\\User\\Desktop\\Recording4.dat");
			rename("C:\\Users\\User\\Desktop\\UpdateRec.dat","C:\\Users\\User\\Desktop\\Recording4.dat");
	}
	main_menu();
}
void dl_t(){	

	system("cls");
	header();
	gotoxy(16,10);
	printf("====================== DELETE INFORMATION OF PATIENT ====================\n\n\n");
	
	FILE *ke, *dlt;
	ke = fopen("C:\\Users\\User\\Desktop\\Recording4.dat","r");
	dlt = fopen("C:\\Users\\User\\Desktop\\deleting_names.dat","a");
	
	char name[20];
	
	printf("\t\t\t\tEnter the name of patient: ");
	scanf("%s",name);
	name[0]=toupper(name[0]);
	
	int found;
	found = 0;
	
	while(fscanf(ke,"%s %s %s %s %s %s",&(p.First_name),&(p.Second_name),&(p.age),&(p.Gender),&(p.problem),&(p.DoctorName))!=EOF)
	{
		if(strcmp((name),(p.First_name))!=0)
		{
			fprintf(dlt,"%s %s %s %s %s %s",(p.First_name),(p.Second_name),(p.age),(p.Gender),(p.problem),(p.DoctorName));
		}
		else
		{
			printf("\t\t\t\t%s %s %s %s %s %s\n\n\n",(p.First_name),(p.Second_name),(p.age),(p.Gender),(p.problem),(p.DoctorName));
			found = 1;
		}
	}
	if(found == 0)
	{
		printf("Record not found");
	}
	if(found != 0)
	{		
		fclose(ke);
		fclose(dlt);
		remove("C:\\Users\\User\\Desktop\\Recording4.dat");
		rename("C:\\Users\\User\\Desktop\\deleting_names.dat","C:\\Users\\User\\Desktop\\Recording4.dat");
		getch();
		printf("\t\t\t\tSUCCESSFUL DELETING PATIENT");
	}
	getch();
	main_menu();	
}
void main_menu(){
	
	system("cls");
	
	header();
	printf("\n\t\t\t\t\t1.Add Patients.\n");
	printf("\t\t\t\t\t2.List Patients.\n");
	printf("\t\t\t\t\t3.Search Patients.\n");
	printf("\t\t\t\t\t4.Edit Patients.\n");
	printf("\t\t\t\t\t5.Delete Patients.\n");
	printf("\t\t\t\t\t6.Exit\n\n");
	
	int choosing;
	
	printf("\t\t\t\tSelect one operation: ");
	scanf("%d",&choosing);


	switch(choosing)
	{
	
		case 1:
			add();
			break;
		case 2:
			list();
			break;
		case 3:
			search();
			break;
		case 4:
			edit();
			break;
		case 5:
			dl_t();
			break;
		case 6:
			ex_it();
			break;
		default:
			printf("\t\t\t\tWrong select...\n\n");
	}
};

int main(){
	welcome_screen();
	system("cls");

	login_screen();

	
	return 0;
}
