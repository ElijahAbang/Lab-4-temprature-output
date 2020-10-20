/*
Elijah Abang
C++ 2020
Due: 10/10/19
Lab 4 Temperature Output
Description: Design and write a C++ program that inputs a series of hourly temperature from a file, and outputs a bar chart (using stars) of the temperatures. 
The temperature should be printed to the left of the corresponding bar, and there should be a heading that gives the scale of the chart. 
The range of temperatures should be from  -30 to 120. Because it is hard to display 150 characters on the screen, you should have each star represent a range of 3 degrees. 
That way, the bars will be at most 50 characters wide. Use meaningful variable names, proper indentation, and appropriate comments. 
Thoroughly test the program using your own data sets. Make sure to vet the values from the input file.
*/

#include<iostream> 
#include<fstream>  //fstream is to deal with file input
#include<iomanip>  //iomanip is included for the functions

using namespace std;

void header(); 

void positiveData(float); 

void negativeData(float); 

int main()
{
	float Tempinput; //this creates a variable for the temperatures from the file to be stored
	string Tempin = " C:/Users/El.J/Desktop/C++/Lab 4/Lab 4 temprature output/Lab 4 temprature output/Tempin.txt ";
	ifstream inFile;
	inFile.open("Tempinput");
	inFile >> Tempinput;

	if (!inFile) //This if statements purpose is to check if the stream of the file is valid, if it is invalid the user will be prompeted to check the files name
	{           
		cout << "Cannot locate file. Please recheck check the file name.";
		return 1;
	}
	
	if (!inFile)  //This statement checks for invalid character inputs and then ends the program with code 0
	{            
		cout << "Cannot read file data: End of File or Invalid Input. (Please do not use characters.)" << endl;
		return 0;
	}

	header(); 

	while (inFile) //this is a loop test that displays the bar chart to the screen. This loop  will repeat as long as the file stream is valid
	{              
				 

		if (Tempinput < -30 || Tempinput> 120) // this is the control structure that evaluates whether "Tempinput" is within the valid range
		{                                     
			cout << setw(8) << Tempinput << " this is an invalid temperature" << endl;
		}
		else if (Tempinput >= 1.5)  //Nested if statement that calls the "positiveData" if "Temmpinput" is a positive value greater than 1.5 within the valid range
		{                           
			positiveData(Tempinput); 
		}
		else if (Tempinput <= -1.5)  // this is a Nested if statement that calls the "negativeData" if "Tempinput" is a negative value less than -1.5 within the valid range
		{                           
			negativeData(Tempinput); 
		}
		else if (Tempinput < 1.5 && Tempinput > -1.5)
		{
			cout << setw(8) << Tempinput;      //if the Tempinput falls in the range between -1.5 and 1.5 then the following cout will be outputed to the screen 
			cout << "           |" << endl;     
		}                                      

		inFile >> Tempinput; //this statement gives "Tempinput" another value
							 

		if (!inFile) //this outputs a statement that marks the end of the file then closes the program
		{            
			cout << "Cannot read file data: End of File or Invalid Input. (Please do not use characters.)" << endl;
			return 0;
		}
	}

	return 0;
}

void header() //definition for the "header" function
{
	string space = "        ";

	cout << "Temperatures for 24 hours:" << endl;
	cout << "        " << -30 << space << "0" << space << "30" << space << "60" << space << "90" << space << "120" << endl;
}

void positiveData(float Tempinput) //defintion for the "positiveData" function
{                                 
	int count1 = 1;
	float star = (Tempinput / float(3)); //the star variable represents how many starts should be outputed
										
	cout << setw(8) << Tempinput;
	cout << "           |";             //first the function displays the temperature and a space
										

	while (count1 <= int(star + 0.5))   
	{                                   
		cout << "*";                    
		count1++;
		if (count1 > int(star + 0.5))
		{
			cout << endl;
		}
	}
}

void negativeData(float Tempinput) //function definition for "negativeData"
{                                 
	int count1 = 1;
	float star = (Tempinput / float(3)); //the star variable is a representation of how many stars should be outputted
										
	cout << setw(8) << Tempinput;
	cout << setw(int(star - 0.5) + 12);   //the space between the temperature and the stars
										

	while (count1 <= int((-(star)) + 0.5)) 
	{                                      
		cout << "*";                       
										   
		count1++;
		if (count1 > int((-(star)) + 0.5))
		{
			cout << "|" << endl;
		}
	}
}