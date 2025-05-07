/*FileName:NumberAnalysisExam.cpp
Programmer Name:Charles Sherwood
Date:5/2025
Requirements:This Program Should Ask The User For A File 
And Go Through The File And Display Whats In It 
It Should Display The Lowest Number The Highest Number 
The Total Numbers And The Average Of The Numbers.
*/


#include<string>    
#include<fstream>
#include <iostream>
using namespace std;

void Welcome();
void GetAverage();
void CheckFile();
void Display();
void UserInput();
bool Repeat();



int main()
{
    Welcome();



}


void Welcome()
{
    cout << "------------------------------------------\n";
    cout << "!!Welcome To The Number Analysis Program!!\n";
    cout << "------------------------------------------\n";
}


void UserInput()
{


}


void CheckFile()
{



}

void GetAverage()
{




}


void Display()
{


}
bool Repeat()
{
    char Choice;
    cout << "Do You Have Another File That You Need Analyized? Y/N:";
    cin >> Choice;
    return Choice == 'Y' || Choice == 'y';
}


