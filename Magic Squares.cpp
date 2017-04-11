//Programmer: Bobby Clasemann
//File: Magic Squares.cpp
//Date: 1/19/2017
//Lab Experience 2
//Creating and displaying an n X n magic square based on the size 
//the user inputs.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

const int NUM_ROWS = 15;
const int NUM_COLS = 15;

typedef int magicSquare[NUM_ROWS][NUM_COLS];

void getTable(int n, magicSquare &aTable);
void printTable(int n, magicSquare &aTable);
bool magicSquareChecker(int n, magicSquare &aTable);
void constructor(int n, magicSquare &aTable);

int main(){

	char answer;
	int size;
	magicSquare square = {0};

	cout << "Do you wish to generate a magic square? (Y/N): ";
	cin >> answer;
	cout << endl;
	
	
	if(toupper(answer) != 'Y' && toupper(answer) != 'N'){		//checks input validation
		do{
			cout << "Answer is invalid. Do you wish to generate a magic square? (Y/N): ";
			cin >> answer;
		}while(toupper(answer) != 'Y' && toupper(answer) != 'N');
	}//end if

	if(toupper(answer) == 'Y'){
		cout << "Please enter an odd number for the size n of the n X n magic square: ";
		cin >> size;
		cout << endl;
		while(size % 2 != 1){                                     //checks size is odd
			cout << "Number is not odd. Please enter an odd number: ";	
			cin >> size;
			cout << endl;
		}//end while

		constructor(size, square);
		printTable(size, square);
		magicSquareChecker(size, square);

	}//end if

	else if(toupper(answer) == 'N'){
		cout << "Please enter an odd number for the size n of the n X n magic square: ";
		cin >> size;
		cout << endl;
		while(size % 2 != 1){                                     //checks size is odd
			cout << "Number is not odd. Please enter an odd number: ";	
			cin >> size;
			cout << endl;
		}//end while

		getTable(size, square);
		cout << endl;
		printTable(size, square);
		cout << endl;
		magicSquareChecker(size, square);
	}//end else if


	return 0;

}//end main


/*-----------------------------------------------------------
Gets each element for the magic square array.

Precondition: User must not choose to generate a magic square
			  and size n must be declared.
Postcondition: User generated square of size n X n.
------------------------------------------------------------*/

void getTable(int n, magicSquare &aTable){
	
	cout << "Enter the elements of the " << n << " x " << n << " square: " << endl;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> aTable[i][j];

}//end getTable

/*-----------------------------------------------------------
Displays the contents of the magic square

Precondition: Magic square is an n X n square of integers 
			  with n > 0.
Postcondition: Displays the square to the user.
------------------------------------------------------------*/

void printTable(int n, magicSquare &aTable){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << setw(4) << aTable[i][j];
		}//end for
		cout << endl;
	}//end for

}//end printTable


/*-----------------------------------------------------------
Checks if the array is a magic square.

Precondition: Magic square is an n X n square of integers 
			  with n > 0.
Postcondition: Returns false if the array is not a magic 
			   square and returns true if the array is a 
			   magic square and displays the magic number 
			   if true.
------------------------------------------------------------*/


bool magicSquareChecker(int n, magicSquare &aTable){

	double check = (n * (pow(n, 2) + 1))/2;  //total number each section should add up to
	int total = 0;
	bool magic = false;

	//adds array elements of each row
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			total += aTable[i][j];			
		if(total != check){
			cout << "The square is not a magic square. " << endl << endl;

			return magic;
		}//end if
		total = 0;
	}//end for


	//adds array elements of each column
	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++)			
			total += aTable[j][i];
		if(total != check){
			cout << "The square is not a magic square. " << endl << endl;
			return magic;
		}//end if
		total = 0;
	}//end for


	//adds array elements from top right to bottom left
	for(int i = n - 1; i >= 0; i--)
			total += aTable[i][i];			
		if(total != check){
			cout << "The square is not a magic square. " << endl << endl;
			return magic;
		}//end if


	total = 0;			//resets total for next diagonal check

	//adds array elements from top left to bottom right
	for(int i = 0; i < n; i++)
			total += aTable[i][i];			
		if(total != check){
			cout << "The square is not a magic square. " << endl << endl;
			return magic;
		}//end if

	cout << endl;
	cout << "This is a magic square. " << endl <<
			 "The magic number is: " << check << endl;
	cout << endl;
	magic = true;
	return magic;

}//end magicSquareChecker

/*-----------------------------------------------------------
Constructs a magic square for an n X n array.

Precondition: n must be an odd number.
Postcondition: Created magic square based off rule sets
			   to make a magic square. 
------------------------------------------------------------*/


void constructor(int n, magicSquare &aTable){

	int k = 1;
	int i = 0;		//start k in top middle of array
	int j = (n/2);	//same

	while(k <= (n * n)){

		//moves k+1 to bottom of array
		if(i < 0 && j < n)
			i += n;				

		//moves k+1 to left of array
		else if(i >= 0 && j >= n)
			j = 0;				

		//moves k+1 to below previous k
		else if(i < 0 && j >= n){
			i += 2;				
			j -= 1;	
		}//end if

		//moves k+1 to below previous k
		else if(aTable[i][j] != 0){
			i += 2;				
			j -= 1;
		}//end if

		aTable[i][j] = k;
		i--;
		j++;
		k++;

	}//end while


}//end constructor