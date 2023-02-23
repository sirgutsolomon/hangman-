#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<ctime>

using namespace std;


void random();
void printBody(int mistakes, char *body);
void displayword(char hword[],char ht[], int lng);
void usedlet_man(int mistake, char* attempt,char let);
void disp_usedlet(int mistake, char* attempt);
char verify;
int main()
{
char word1[40];
string clue;

const int MAX = 6;
int choose;


cout << endl << endl << "     \xB2\xB2  \xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2  \xB2\xB2\xB2    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2" << endl;
cout << "     \xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2   \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2   \xB2\xB2  \xB2\xB2" << endl;
cout << "     \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2   \xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2  \xB2\xB2   \xB2\xB2\xB2\xB2\xB2\xB2" << endl;
cout <<endl<< endl << "           WELCOME TO HANGMAN GAME"  << endl << endl;
cout << endl << endl << "           STANDARD RULES THAT YOU NEED TO FOLLOW: " << endl;
cout << endl << "           1. Enter a word only." << endl << endl;
cout << "           2. Use a word without space for clue words." << endl << endl;
cout << "           3. Use lowecase letters for characters and words." << endl << endl;
cout << "\n\n          \xB2\xB2\xB2\xB2 HOW DO YOU WANT TO PLAY? """;
cout << "\n\n          \xB2\xB2\xB2\xB2 1. Single player";
cout << "\n\n          \xB2\xB2\xB2\xB2 2. Multiplayer" << endl;
cout << "              ---------------------------------" <<endl;
cout <<"               ";
cin >> choose;

if(choose == 1)
{
	random();
}

else if(choose == 2)

{

do{
	
const int MAX1 = 40;
char word1[MAX1];

const int MAX = 6;

char hint[100];
char *body = new char[MAX+1];
for(int i = 0; i < MAX; i++)
body[i] =' ';
cout << endl << endl <<"           Player1 input the word:  ";
cin >> word1;
cout << endl << endl << "           Please enter a hint:  ";
cin >> hint;


system("CLS");
cout << endl << endl << "           Here is the hint : ----------- " <<  hint << " -----------";

int length = strlen(word1);
char word2[length];
for(int z = 0; z < length; z++)
word2[z] = '-';
char *attempt = new char[10];

int rigthGuess, los;

int *grt = &rigthGuess;

int *lrt = &los;
	
    rigthGuess = 0;
    
	los = 0;
	
	

do{

cout << endl << endl << "            Player2 plz enter a letter to guess the word : 	";
char guessChar;

int matchNum = 0;
cin >> guessChar;

for(int i = 0; i < length; i++)
{
	if(word1[i] == guessChar){
	matchNum++;
	if(word2[i] == guessChar)
	continue;
	word2[i] = guessChar;
    rigthGuess++;
}
if(i == (length-1))
{
	if(matchNum == 0)
	{
		system("CLS");
	
	los++;
	displayword(word2,hint, length);
	printBody(los,body);
	usedlet_man(los,attempt,guessChar);
	disp_usedlet(los,attempt);
	}
		

	else
	{
		system("CLS");
		

    displayword(word2,hint, length);
	printBody(los,body);
	disp_usedlet(los,attempt);
	}
		

}
	
if(rigthGuess == length){
	cout << endl << endl << "           Congratulations you won!!";
}
else if(los == 6)
cout << endl << endl << "           You are dead!!";
}

}


while(*grt < length && *lrt < MAX);
delete [] body;
cout << endl << endl << "           Do you want to continue(Y/N) : ";
cin >> verify;

}while(verify == 'Y');

}
return 0;
}

 
 void printBody(int mistakes, char *body)
{

switch(mistakes){
case 6: body[6] = '\\';
break;
case 5: body[5] = '/';
break;
case 4: body[4] = '\\'; 
break;
case 3: body[3] = '|'; 
break;
case 2: body[2] = '/'; 
break;
case 1: body[1] = ' ', body[0] = 'O';
break;
default: break;
}
cout<<"\t_________\n";
cout<<"\t|       |\n";
cout<<"\t|"<<setw(7)<<" "<<body[0]<<body[1]<<"\n";
cout<<"\t|"<<setw(6)<<" "<<body[2]<<body[3]<<body[4]<<"\n";
cout<<"\t|"<<setw(6)<<"  "<<body[5]<<setw(2)<<body[6]<<"\n";
cout<<"\t|            \n";
cout<<"\t|            "; 
cout<<endl;
}


void displayword(char hword[],char ht[], int lng)
{
	cout << endl;
	for(int i = 0; i < lng; i++)
	cout << hword[i];
	cout <<"			Hint: "<<ht<<endl;
	
}

void usedlet_man(int mistake, char* attempt,char let)
{
	int value= mistake-1;
    attempt[value]=let;
}


	
	
void disp_usedlet(int mistake, char* attempt)
{
	if (mistake == 0)
	cout<< endl << endl << "           No wrong letter yet\n";
	else
	{
		cout << endl << endl <<"           Used wrong letter: [";
	
	    for(int i = 0; i < mistake; i++)
	    {
	    	cout <<" "<< attempt[i];
		}
	    
	
	    cout << "]\n";
	}
	
	

}
	
	


void random()
{


	string letters[50];
	string words[50] = { "dog", "animal", "ronaldo", "messi", "justin" };
	string guesseOf;
	int n;


do{

	int trial = 5;
	cout << endl << endl << "           The sample words are : dog , animal , ronaldo , messi , justin ";
	while (trial >= 0) {

		srand(time(NULL));

		//Use the %5 to keep the random number between 0-4
		string gues = words[rand() % 5];



		cout << endl << endl << "           gues the word please : ";

		cin >> guesseOf;

		if (guesseOf == gues)

			cout << endl << endl << "           congratulations! you gues the word correctly!";
		else
		{
			cout << endl << "          YOU ARE DEAD!!" << endl;
			cout << "           ____________" << endl;
			cout << "          |            |" << endl;
			cout << "          |            o" << endl;
			cout << "          |           /|\\"" " << endl;
			cout << "          |           / \\" "" << endl;
			cout << "          |" ;
			cout << endl << endl << "          oops the word was : " << gues << endl << endl;
			
		}

		trial--;

	}
	cout << endl << endl << "           Do you want to play again? ( Y/N) : ";
	cin >> verify;
}while(verify == 'Y');

}






