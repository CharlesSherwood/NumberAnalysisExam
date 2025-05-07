/*FileName:NumberAnalysisExam.cpp
Programmer Name:Charles Sherwood
Date:5/2025
Requirements:This Program Should Ask The User For A File 
And Go Through The File And Display Whats In It 
It Should Display The Lowest Number The Highest Number 
The Total Numbers And The Average Of The Numbers.
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;


// Constant for formatting output
const int WIDTH = 40;

// Function Prototypes
void Welcome();
void GetAverage(const vector<double>& numbers);
void CheckFile(const string& fullPath, vector<double>& numbers);
void Display(const vector<double>& numbers);
void UserInput();
bool Repeat();


//Main Function 
int main()
{
    Welcome();

    do
    {
        UserInput();
    } while (Repeat());

    cout << "\nThank you for using the Number Analysis Program!\n";
    return 0;
}


//Welcome Message for the user 
void Welcome()
{
    cout << "------------------------------------------\n";
    cout << "!! Welcome To The Number Analysis Program !!\n";
    cout << "------------------------------------------\n";
}


//This Will Get The Users PathFile And FileName.
void UserInput()
{
    string filePath, fileName, fullPath;
    vector<double> numbers;

    cout << "\nEnter the full directory path to the file (e.g., C:\\\\Users\\\\YourName\\\\Documents\\\\):\n";
    cin.ignore(); // Clear leftover newline
    getline(cin, filePath);

    cout << "Enter the filename (e.g., numbers.txt): ";
    getline(cin, fileName);

    fullPath = filePath + fileName;

    CheckFile(fullPath, numbers);

    if (!numbers.empty())
    {
        Display(numbers);
        GetAverage(numbers);
    }
    else
    {
        cout << "\nNo valid numbers found in the file or file couldn't be opened.\n";
    }
}




//Checks To See If File Can Be Opened
void CheckFile(const string& fullPath, vector<double>& numbers)
{
    ifstream file(fullPath);
    string line;
    double num;

    if (!file)
    {
        cerr << "\nError: File \"" << fullPath << "\" could not be opened. Please check the path and filename.\n";
        return;
    }

    while (getline(file, line))
    {
        try
        {
            num = stod(line);
            numbers.push_back(num);
        }
        catch (invalid_argument&)
        {
            cerr << "Warning: Skipping invalid entry -> \"" << line << "\"\n";
        }
    }

    file.close();
}


//Displays Everything For The User At The End 
void Display(const vector<double>& numbers)
{
    double min = numeric_limits<double>::max();
    double max = numeric_limits<double>::lowest();
    double total = 0;

    for (double n : numbers)
    {
        if (n < min) min = n;
        if (n > max) max = n;
        total += n;
    }

    cout << fixed << setprecision(2);
    cout << "\n" << string(WIDTH, '-') << "\n";
    cout << "Lowest Number:  " << min << endl;
    cout << "Highest Number: " << max << endl;
    cout << "Total:          " << total << endl;
}


//This Function Calculates The Average Of Whats In The File
void GetAverage(const vector<double>& numbers)
{
    if (numbers.empty()) return;

    double sum = 0;
    for (double n : numbers)
    {
        sum += n;
    }

    double average = sum / numbers.size();
    cout << "Average:        " << fixed << setprecision(2) << average << endl;
    cout << string(WIDTH, '-') << "\n";
}


//Asks The User If They Have Another File They Would Like To Check 
bool Repeat()
{
    char choice;
    cout << "\nDo You Have Another File That You Need Analyzed? (Y/N): ";
    cin >> choice;
    return choice == 'Y' || choice == 'y';
}

