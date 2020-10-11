
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
//#include <conio.h>
#include "input.hpp"
#include<algorithm> // for sort() 

using namespace std;
void load_data();
void main_menu();
void checkImport();
void ViewBySubject();
void ViewEachSubject();
void ViewEachSubjectAll();
float MinFunc(float m);
float MaxFunc(float m);
float MeanFunc(float m);
float MedianFunc(float m);
float VarFunc(float m);
float StdFunc(float m);
void CalcMenu(string m);
void ExportTxtMenu(string m); 
void ExportTxtMenuAll(string m) ;
void ExportCompare2Subjects(int x, int y, string k);
void CalcMenuAll(string m);
void ExportFileTohtml();
void ExporttxtMenutohtml(string m);
void ExportTxtMenuAlltohtml(string m);
void ExportFreqMenutohtml(string k);
void ExportAscendingDescending(int x, int y, string z);
void ExportAscendingDescendinghtml(int x, int y, string k);

void FreqMenu();
void HistMenu();
void AboveBelowAvg();
void Compare2Subjects();
void PearsonsCorrelation();
void linearRegression();
void AscendingDescending();
void ExportReportToText();
void Report();
void ViewMore();
void CreateHTML();
void ExportFreqMenu(string k);
void ExportHistMenu(string k);
void ExportAboveBelowAvrg(string k);
void ExportHistMenutohtml(string k);
void exportlinearregression(int choice1, int choice2, string k);
void ExportPearson(int choice1, int choice2, string k);
void exportlinearregressionhtml(int choice1, int choice2, string k);
void ExportPearsonhtml(int choice1, int choice2, string k);
void ExportCompare2Subjectshtml(int x, int y, string k);
void ExportAboveBelowAvrghtml(string k);

int getChoice(int m,int j);
int columns;
int rows;
int currentSubject;
int currentCalc;
int mean;
int minimum;
string importedfile;

float Meedian(float Marks[], int n);

// Driver function to sort the 2D vector 
// Source : https://blog.csdn.net/qq_27009517/article/details/86519329
bool Descendingcol( const vector<int>& v1, const vector<int>& v2 ) 
{ 
return v1[currentSubject] > v2[currentSubject]; 
} 

bool Ascendingcol( const vector<int>& v1, 
			const vector<int>& v2 ) { 
return v1[currentSubject] < v2[currentSubject]; 
} 
bool doneImport = false;

vector<string> MarksTitles;
vector<vector<int>> Marks;
vector<vector<int>> SortedMarks;


int main() {
  cout << "Welcome to Academic Report System" << endl;
  cout << "==================================================="<<endl;
  cout << "Press any key to continue";
  getch();
  main_menu();
}

/*
===================================================
Programmer : Zaen
Name : main_menu

Task : Prints out the main menu and accepts user choice from getChoice()
Data in : Choice 
Data out : None.
=================================================
*/
  void main_menu(){
   system("clear");
   cout<<"MAIN MENU" <<endl ;
   cout << "==================================================="<<endl;
   cout<<"1. Load Data from File ";
   if (doneImport == true)
   {
     cout << "(" <<importedfile << " imported)";
   }
   cout << endl;
   cout<<"2. View by Subject" <<endl;
   cout<<"3. Compare Subjects" <<endl;
   cout<<"4. Generate Report" <<endl;
   cout<<"5. Sort Subjects" <<endl;
   cout<<"6. Exit" <<endl;
   int choice = getChoice(1,7);
   switch (choice) {
   case 1:
     load_data();
     break;
   case 2:
     checkImport();
     ViewBySubject();
     break;
   case 3:
     checkImport();
     Compare2Subjects();
     break;
   case 4:
     checkImport();
     Report();
     break;
   case 5:
     checkImport();
     AscendingDescending();
     break;
   case 6:
     system("clear");
     cout << "Exiting program... goodbye!";
     exit(0);

     break;
  }
}
/*
===================================================
Programmer : Zaen
Name : ViewBySubject

Task : Prints out the list of available subjects imported from txt file and accepts user choice from getChoice()
Data in -none
data out - none 
=================================================
*/
void ViewBySubject()
{
  system("clear");
  cout<<"View By Subjects" <<endl ;
   cout << "==================================================="<<endl;
   cout << "0. Return to main menu"<< endl;
   cout << "1. All Subjects" <<endl;
   for (int i = 2; i <(MarksTitles.size()); i++)
   {
     cout<<(i)<< ". " << MarksTitles[i] <<endl;
   }
   int choice = getChoice(0,MarksTitles.size()-1);
   switch (choice) {
   case 0:
     main_menu();
     break;
  case 1:
     ViewEachSubjectAll();
  default:
    currentSubject= choice;
    ViewEachSubject();
   }
}


/*
===================================================
Programmer : Zaen
Name : ViewEachSubject()

Task : Prints out the list of 7 available calculation options for the chosen subject and accepts user choice from getChoice()
Data in - none
Data out - none
=================================================
*/

void ViewEachSubject()
{
  system("clear");
  cout<<MarksTitles[currentSubject] <<endl ;
  cout << "==================================================="<<endl;
  cout << "0. Go back" <<endl;
  cout << "1. Minimum Mark" <<endl;
  cout << "2. Maximum Mark"<<endl;
  cout << "3. Median"<<endl;
  cout << "4. Mean"<<endl;
  cout << "5. Variance"<<endl;
  cout << "6. Standard Deviation"<<endl;
  cout << "7. View More"<<endl;
  int choice = getChoice(0, 7);
  currentCalc = choice;
    switch (choice) 
    {
    case 0:
      ViewBySubject();
      break;
    case 1:
      CalcMenu("Minimum");
      break;
    case 2:
      CalcMenu("Maximum");
      break;
    case 3:
      CalcMenu("Median");
      break;
    case 4:
      CalcMenu("Mean");
      break;  
    case 5:
      CalcMenu("Variance");
      break;  
    case 6:
      CalcMenu("Standard Deviation");
      break;  
    case 7:
      ViewMore();
      break;
   }
}
/*
===================================================
Programmer : Zaen
Name : ViewEachSubjectAll

Task : It user selected to view all subject, it will prints out the list of available calculation options for all subjects and accepts user choice from getChoice()
Data in - none
data out - none
=================================================
*/
void ViewEachSubjectAll()
{
  system("clear");
  cout<<"                      All Subjects                   " <<endl ;
  cout << "==================================================="<<endl;
  cout << "0. Go back" <<endl;
  cout << "1. Minimum Mark" <<endl;
  cout << "2. Maximum Mark"<<endl;
  cout << "3. Median"<<endl;
  cout << "4. Mean"<<endl;
  cout << "5. Variance"<<endl;
  cout << "6. Standard Deviation"<<endl;
  int choice = getChoice(0, 6);
  currentCalc = choice;
    switch (choice) 
    {
    case 0:
      ViewBySubject();
      break;
    case 1:
      CalcMenuAll("Minimum");
      break;
    case 2:
      CalcMenuAll("Maximum");
      break;
    case 3:
      CalcMenuAll("Median");
      break;
    case 4:
      CalcMenuAll("Mean");
      break;  
    case 5:
      CalcMenuAll("Variance");
      break;  
    case 6:
      CalcMenuAll("Standard Deviation");
      break;  

   }
}
/*
===================================================
Programmer : Zaen
Name : CalcMenuAll()

Function : Displays the Var for All Subjects
=================================================
*/
    
void CalcMenuAll(string m) 
{
  system("clear");
  cout<<m <<" of all Subjects" <<endl ;
  cout << "==================================================="<<endl<<endl;
  cout<<"============================================================================================="<<endl;
  cout <<setw(12)<< " ";
  for (int i = 1; i < MarksTitles.size();i++)
    {
       cout  << setw(9)<< MarksTitles[i]<<"  |  ";
    }
  cout <<endl;
  cout<<"============================================================================================="<<endl;
  cout <<setw(9) <<  m<< "  |";
  for (int i = 1; i < MarksTitles.size();i++)
  {
    //Switch currentCalc in order to determine which calculation to computer for all subjects
  switch(currentCalc)
  {
    case 1:
      cout <<setw(9) << setprecision(2)<< MinFunc(i) <<"  |  ";
      ExportTxtMenuAll("Minimum");
      ExportTxtMenuAlltohtml("Minimum");
      break;
    case 2:
      cout <<setw(9) << setprecision(2)<< MaxFunc(i)<<"  |  ";
      ExportTxtMenuAll("Maximum");
      ExportTxtMenuAlltohtml("Maximum");
      break;
    case 3:
      cout <<setw(9) << setprecision(2)<< MedianFunc(i)<<"  |  ";
      ExportTxtMenuAll("Median");
      ExportTxtMenuAlltohtml("Median");
      break;
    case 4:
      cout <<setw(9) << setprecision(2)<< MeanFunc(i)<<"  |  ";
      ExportTxtMenuAll("Mean");
      ExportTxtMenuAlltohtml("Mean");
      break;
    case 5: 
      cout<<setw(9) << setprecision(2)<< VarFunc(i)<<"  |  ";
      ExportTxtMenuAll("Variance");
      ExportTxtMenuAlltohtml("Variance");
      break;
    case 6:
      cout<<setw(9) << setprecision(2)<< StdFunc(i)<<"  |  ";
      ExportTxtMenuAll("Standard Deviation");
      ExportTxtMenuAlltohtml("Standard Deviation");
      break;
  }
  }
   cout<<endl<<"=============================================================================================";
  cout <<endl<<endl;
  cout <<"Data has been exported to "+m +"All.txt"<<endl<<endl;
  cout <<"Data has been exported to "+m +"All.html"<<endl<<endl;
  cout << "Press any key to go back"<<endl<<endl;
  getch();
  ViewEachSubjectAll();
}
/*
===================================================
Programmer : Zaen
Name : ExportTxtMenuAll(string m) 

Task : Exports a report of all the calculations for each subjects to a txt file
Data in - None
Data out - none
=================================================
*/
void ExportTxtMenuAll(string m) 
{
  ifstream read;
	ofstream write;
  ofstream NewTextFile;
  NewTextFile.open (m +"All.txt");
//Exports the chosen calculation for all subjects
  NewTextFile <<m <<" of all Subjects" <<endl ;
  NewTextFile <<"============================================================================================="<<endl<<endl;
  NewTextFile <<"============================================================================================="<<endl;
  NewTextFile <<setw(12)<< " ";
  for (int i = 1; i < MarksTitles.size();i++)
    {
       NewTextFile << setw(9)<< MarksTitles[i]<<"  |  ";
    }
  NewTextFile <<endl;
  NewTextFile <<"============================================================================================="<<endl;
  NewTextFile <<setw(9) <<  m<< "  |";
  for (int i = 1; i < MarksTitles.size();i++)
  {
  switch(currentCalc)
  {
    case 1:
      NewTextFile <<setw(9) << setprecision(2)<< MinFunc(i) <<"  |  ";
      break;
    case 2:
      NewTextFile <<setw(9) << setprecision(2)<< MaxFunc(i)<<"  |  ";
      break;
    case 3:
      NewTextFile <<setw(9) << setprecision(2)<< MedianFunc(i)<<"  |  ";
      break;
    case 4:
      NewTextFile <<setw(9) << setprecision(2)<< MeanFunc(i)<<"  |  ";
      break;
    case 5: 
      NewTextFile <<setw(9) << setprecision(2)<< VarFunc(i)<<"  |  ";
      break;
    case 6:
      NewTextFile <<setw(9) << setprecision(2)<< StdFunc(i)<<"  |  ";
      break;
  }
  }
  NewTextFile <<endl<<"=============================================================================================";
}

/*
===================================================
Programmer : Zaen
Name : CalcMenu(string m)

Task : Displays the calculation of the selected subject
=================================================
*/
void CalcMenu(string m)
{
  system("clear");
  cout<<MarksTitles[currentSubject] <<endl ;
  cout << "==================================================="<<endl;
  cout << m << " : ";

  switch(currentCalc)
  {
  case 1:
    cout << MinFunc(currentSubject);
    ExportTxtMenu("Minimum");
    ExporttxtMenutohtml("Minimum");
    break;  
  case 2:
    cout << MaxFunc(currentSubject);
    ExportTxtMenu("Maximum");
    ExporttxtMenutohtml("Maximum");
    break;  
  case 3:
    cout << MedianFunc(currentSubject);
    ExportTxtMenu("Median");
    ExporttxtMenutohtml("Median");
    break;  
  case 4:
    cout << MeanFunc(currentSubject);
    ExportTxtMenu("Mean");
    ExporttxtMenutohtml("Mean");
    break;  
  case 5:
    cout << VarFunc(currentSubject);
    ExportTxtMenu("Variance");
    ExporttxtMenutohtml("Variance");
    break;  
  case 6:
    cout << StdFunc(currentSubject);
    ExportTxtMenu("Standard Deviation");
    ExporttxtMenutohtml("Standard Deviation");
    break;  
  }
  cout <<endl <<endl;
  cout <<"Data has been exported to " << m + MarksTitles[currentSubject]+".txt"<<endl<<endl;
  cout <<"Data has been exported to " << m + MarksTitles[currentSubject]+".html"<<endl<<endl;
  cout << "Press any key to go back"<<endl<<endl;
  getch();
  ViewEachSubject();
}


/*
===================================================
Programmer : Zaen
Name : ExportTxtMenu()

Task : Export Menu to a text file
data in- none
data out - none
=================================================
*/
void ExportTxtMenu(string m) 
{
  ifstream read; 
	ofstream write; 
  ofstream NewTextFile;
  NewTextFile.open (m + MarksTitles[currentSubject]+".txt"); //writes to this txt file
  NewTextFile <<MarksTitles[currentSubject] <<endl ;
  NewTextFile << "==================================================="<<endl;
  NewTextFile <<m<< " : ";
  
  //Depending on value of currentCalc from ViewEachSubject(), function for the respective calculations are run
  switch(currentCalc)
  {
  case 1:
    NewTextFile << MinFunc(currentSubject);
    break;  
  case 2:
    NewTextFile << MaxFunc(currentSubject);
    break;  
  case 3:
    NewTextFile << MedianFunc(currentSubject);
    break;  
  case 4:
    NewTextFile << MeanFunc(currentSubject);
    break;  
  case 5:
    NewTextFile << VarFunc(currentSubject);
    break;  
  case 6:
    NewTextFile << StdFunc(currentSubject);
    break;  
  }
}


/*
===================================================
Programmer : Zaen
Name : MinFunc()

Function : Calculates the Minimum mark of the selected column
Data in - int currentSubject / column of the subject
data out - minimum value
=================================================
*/

float MinFunc(float m)
{
  int minimum = Marks[0][m];
  for (int i = 1; i < Marks.size(); i++) 
  {
    if(Marks[i][m] < minimum)
    {
      minimum = Marks[i][m];
    } 
  }
  return minimum;
}


/*
===================================================
Programmer : 
Name : MaxFunc()

Task : Calculates the Maximum mark of the selected column
Data in - int currentSubject / column of the subject
data out - Maximum value
=================================================
*/

float MaxFunc(float m)
{
  int maximum = Marks[0][m];
  for (int i = 1; i < Marks.size(); i++) 
  {
    if(Marks[i][m] > maximum)
    {
      maximum = Marks[i][m];
    } 
  }
  return maximum;
}


/*
===================================================
Programmer : Zaen
Name : MeanFunc()

Function : Calculates the Mean  of the selected column
Data in - int currentSubject / column of the subject
data out - Mean 
=================================================
*/

float MeanFunc(float m)
{
  float mean = 0;
  for (int i = 0; i < Marks.size(); i++)
  {
    mean += Marks[i][m];
  }
  mean = (mean / Marks.size());
  return (mean);
}


/*
===================================================
Programmer : Zaen
Name : MedianFunc()

Function : Calculates the Median of the selected column
Data in - int currentSubject / column of the subject
data out - Median
=================================================
*/


float MedianFunc(float m)
{
  float median;
  vector<float> medcolumn;
  for (int i =0; i<Marks.size(); i++)
  {
    medcolumn.push_back(Marks[i][m]);
  }
  sort(medcolumn.begin(), medcolumn.end()); 
  if (medcolumn.size()%2 == 0)
  {
     median = (medcolumn[(medcolumn.size() /2)-1] +  medcolumn[medcolumn.size() /2]) /2;
  }
  else 
  {
    median = medcolumn[((medcolumn.size()/2) + 0.5)-1];
  }
  return median;
}




/*
===================================================
Programmer : Zaen
Name : VarFunc()

Function : Calculates the Variance of the selected column
Data in - int currentSubject / column of the subject
data out - Variance
=================================================
*/

float VarFunc(float m)
{
  float mean = 0;
  for (int i = 0; i < Marks.size(); i++)
  {
    mean += Marks[i][m];
  }
  mean = float(mean / Marks.size());

  float var,sum = 0;
  for (int i = 0; i < Marks.size(); i++)
  {
    sum+= pow(Marks[i][m] - mean,2); 
  }
  var = sum / Marks.size();
  return var;
}


/*
===================================================
Programmer : Zaen
Name : StdFunc()

Function : Calculates the Standard Deviation of the selected column
Data in - int currentSubject / column of the subject
data out -Standard Deviation
=================================================
*/


float StdFunc(float m)
{
  float std;
  std = sqrt(VarFunc(m));
  return std;
}



  /*
===================================================
Programmer : Zaen
Name : ViewMore

Task : Prints out the list of 5 more available calculation options and accepts user choice from getChoice()
Data in - None
Data out - None
=================================================
*/

void ViewMore()
{
  system("clear");
  cout<<MarksTitles[currentSubject] <<endl ;
  cout << "==================================================="<<endl;
  cout << "0. Go back" <<endl;
  cout << "1. Marks Frequency Distribution"<<endl;
  cout << "2. Histogram"<<endl;
  cout << "3. Above/Below Average"<<endl;
  cout << "4. Pearson Correlation"<<endl;
  cout << "5. Linear Regression Line"<<endl;
  int choice = getChoice(0, 5);
   switch (choice) 
   {
   case 0:
     ViewEachSubject();
     break;
   case 1:
     FreqMenu();
     break;
   case 2:
     HistMenu();
     break;
   case 3:
     AboveBelowAvg();
     break;
   case 4:
     PearsonsCorrelation();
     break;  
   case 5:
     linearRegression();
     break;  
   }
}


  
/*
===================================================
Programmer : Zaen
Name : FreqMenu

Task : Prints out the Frequency distribution table of data in the selected column
Data in - none
Data out - none
=================================================
*/
void FreqMenu()
{
  system("clear");
  cout << "====================================================="<<endl;
  cout << "Marks Frequency Distribution of " << MarksTitles[currentSubject] <<endl;
  cout << "==================================================="<<endl<<endl;
    cout << "=================================="<<endl;
  cout <<   "| Marks     |  Frequency         |"<<endl;
  int num;
  int freq= 0;
  for (int num=0; num < 101; num++)
  {
    for (int i=0; i < Marks.size(); i++)
    {
      if (Marks[i][currentSubject] == num)
      {
        freq +=1;
      }
    }
    if (freq >= 1)
    {
      cout << "| " << setw(2) <<  num << "        |       " << freq <<  "            |" << endl;
      int i = 0;
      freq=0;
    }
  }
  cout << "=================================="<<endl<<endl;

  cout <<"File has been exported to Frequency"+MarksTitles[currentSubject]+".txt"<<endl<<endl;
  cout <<"File has been exported to Frequency"+MarksTitles[currentSubject]+".html"<<endl<<endl;
  ExportFreqMenu("Frequency"+MarksTitles[currentSubject]+".txt");
  ExportFreqMenutohtml("Frequency"+MarksTitles[currentSubject]+".html");
  cout <<endl << "Press any key to go back";
  getch();
  ViewMore();
}

/*
===================================================
Programmer : Zaen
Name : ExportHistMenu

Task : Exports the histogram table to a text file
Data in - none
Data out - none
=================================================
*/
void ExportHistMenu(string k)
{
  
  ofstream NewTextFile(k);
  NewTextFile << "====================================================="<<endl;
  NewTextFile << "Histogram of " << MarksTitles[currentSubject] <<endl;
  NewTextFile << "==================================================="<<endl<<endl;
  NewTextFile << "=================================================="<<endl;
  NewTextFile <<   "| Marks                  |  Frequency         |"<<endl;
  NewTextFile << "=================================================="<<endl;
  int min = 0;
  int max = 9;
  int freq= 0;
  for (int i=0; i < Marks.size()+1; i++)
  {
    if ((Marks[i][currentSubject] >= min) && (Marks[i][currentSubject] <= max))
    {
      freq +=1;
    }
    if (i == Marks.size()-1)
    {
      string sfreq(freq, '*');
      NewTextFile << "| " << setw(5)<< min << "   -<" << setw(5)<< max << setw(10)<< "        |       " << sfreq << setw(5) <<  "            |" << endl;
      min += 10;
      max += 10;
      i = 0;
      freq=0;
    }
    if (max == 109)
    {
      i = Marks.size();
    }
  }
  NewTextFile << "==================================================="<<endl;
  NewTextFile <<endl << "Press any key to go back";
}

/*
===================================================
Programmer : Zaen
Name : Histmenu

Task : Prints out the Histogram of data in the selected column
Data in - none
Data out - none
=================================================
*/
void HistMenu()
{
  system("clear");
  cout << "====================================================="<<endl;
  cout << "Histogram of " << MarksTitles[currentSubject] <<endl;
  cout << "==================================================="<<endl<<endl;
  cout << "=================================================="<<endl;
  cout <<   "| Marks                  |  Frequency         |"<<endl;
  cout << "=================================================="<<endl;
  int min = 0;
  int max = 9;
  int freq= 0;
  for (int i=0; i < Marks.size()+1; i++)
  {
    if ((Marks[i][currentSubject] >= min) && (Marks[i][currentSubject] <= max))
    {
      freq +=1;
    }
    if (i == Marks.size()-1)
    {
      string sfreq(freq, '*');
      cout << "| " << setw(5)<< min << "   -<" << setw(5)<< max << setw(10)<< "        |       " << sfreq << setw(5) <<  "            |" << endl;
      min += 10;
      max += 10;
      i = 0;
      freq=0;
    }
    if (max == 109)
    {
      i = Marks.size();
    }
  }
  cout << "=================================================="<<endl<<endl;
  cout <<"File has been exported to Histogram"+MarksTitles[currentSubject]+".txt"<<endl<<endl;
  cout <<"File has been exported to Histogram"+MarksTitles[currentSubject]+".html"<<endl<<endl;
  ExportHistMenu("Histogram"+MarksTitles[currentSubject]+".txt");
  ExportHistMenutohtml("Histogram"+MarksTitles[currentSubject]+".html");
  cout <<endl << "Press any key to go back";
  getch();
  ViewMore();
}

/*
===================================================
Programmer : Zaen
Name : checkImport

task : Determines if the user has already imported the data and goes back to main menu if they haven't 
Data in - none
Data out - none
=================================================
*/
void checkImport()
{
    system("clear");
    if (doneImport == false) {
        cout<<"You have to import first!" <<endl ;
        cout << "==================================================="<<endl;
        cout << "Press any key to continue";
        getch();
        main_menu();
    }
}

/*
===================================================
Programmer : Zaen
Name : getChoice

Function : Receives user input and makes sure it is and integer between int m and int j  
Data in - 
Data out - choice
Refrence : http://www.cplusplus.com/forum/beginner/58833/
=================================================
*/

int getChoice(int m,int j)
{
  int ch;
  string strj = to_string(j);
  //This is a while loop that obtains the user choice between m-j
  while (true)
  {
    cout << "Select Choice (" << to_string(m) << "..."<< to_string(j) << ") : " ;
    cin >> ch;
    if (!cin){
      cout <<"Error! You did not enter an integer!\n";
      cin.clear();
      cin.ignore();
      continue;
    }
    for (int i=m;i <= j;i++)
    {
      if (ch == i)
      {
        return ch;
        break;
        //The loop will break if it obtains an input that is m-j give out an error message if it doesnt not recieve a number  in that range
      }
    }
    cout << "Error! Only enter a number between " << to_string(m) << "-" << to_string(j) << endl;
  }
}

/*
===================================================
Programmer : Zaen
Name : load_data
Reference : https://www.tutorialspoint.com/parsing-a-comma-delimited-std-string-in-cplusplus

Task : Imports data from txt/csv file using getline and strings are split by comma and converted into integers using stoi(). Columns, Rows, Marks, and MarksTitles.
Data in - None
Data out - None
=================================================
*/

void load_data()
{
  system("clear");
  string filename;   // Imports from Data.txt
  ifstream myFile (filename); //It will constantly loop until the entered filename is valid
while (true) 
  {
    cout<<"Load File" <<endl ;
    cout << "==================================================="<<endl;
    cout << "Press enter file name : ";
    cin >> filename;
    myFile.open(filename);
    if (myFile.is_open())   //if file can be opened, break the loop
    {
      break;
    }
    system("clear");
    cout << "File could not be found!" << endl;
    cout << "==================================================="<<endl;
    cout << "Press any key to continue";
    getch();
    system("clear");
  }
  importedfile = filename;
  system("clear");
  string line;
  getline(myFile, line); //imports first line
  columns = stoi(line);  
  getline(myFile, line);   
  stringstream s_stream(line);
  while(s_stream.good()) 
  {
    string substr;
    getline(s_stream, substr, ','); //line 1 is split by commas and inserted in vector
    MarksTitles.push_back(substr);  
  }
  getline(myFile, line);   
  rows = stoi(line);
  vector<int> eachMarks; 
  while (getline(myFile, line))  
  {
    stringstream s_stream(line); 
    while(s_stream.good())
    {
    string substr;
    getline(s_stream, substr, ','); 
    eachMarks.push_back(stoi(substr)); 
    }
    Marks.push_back(eachMarks);     //inserts each row data (vector eachMarks) into vector Marks to form a 2d vector 
    eachMarks.clear(); 
  }
    doneImport = true;
    cout << "Import successful!" << endl;
    cout << "==================================================="<<endl;
    cout << "Press any key to continue";
    getch();
    main_menu();
}

/*
===================================================
Programmer : Abir
Name : AboveBelowAvg

Task : Displays data above/below mean for the selected column
Data in - none
Data out - none
=================================================
*/


void AboveBelowAvg()
{
  system("clear");
  int average;
  float SumofMarks = 0;
  float AboveAverage = 0;
  float BelowAverage = 0;
  for (int i = 0; i < Marks.size(); i++) 
  {
    SumofMarks += Marks[i][currentSubject];
  }
  float AverageofMarks = SumofMarks/Marks.size();
  cout << "======================================================="<<endl;
  cout << "Above and Below Mean of " << MarksTitles[currentSubject] <<endl;
  cout << "======================================================="<<endl<<endl;
  cout << "======================================================="<<endl;
  cout << "These students scored greater or same marks as average " << endl;
  cout << "======================================================="<<endl;
  for (int i = 0; i < Marks.size(); i++)
  {
    if(Marks[i][currentSubject] >= AverageofMarks)
    { 
      cout << Marks[i][0] << "     |     " << Marks[i][currentSubject] << endl;
    }
  }
  cout << "======================================================="<<endl;
  cout << "These students scored less than average" << endl;
  cout << "======================================================="<<endl;
  for (int i = 0; i < Marks.size(); i++)
  {
    if(Marks[i][currentSubject] < AverageofMarks)
    { 
      cout << Marks[i][0] << "     |     " << Marks[i][currentSubject]<< endl;
    }
  }
  cout << "======================================================="<<endl<<endl;
  cout <<"File has been exported to AboveBelowAvg"+MarksTitles[currentSubject]+".txt"<<endl<<endl;
  ExportAboveBelowAvrg("AboveBelowAvg"+MarksTitles[currentSubject]+".txt");
  cout <<"File has been exported to AboveBelowAvg"+MarksTitles[currentSubject]+".html"<<endl<<endl;
  ExportAboveBelowAvrghtml("AboveBelowAvg"+MarksTitles[currentSubject]+".html");
  cout << "Press any key to go back" << endl;
  getch();
  ViewMore();
}

/*
===================================================
Programmer : Zaen
Name : ExportAboveBelowAvrg

Task : Exports the Above Below average marks to text file.
Data in - none
Data out - none
=================================================
*/
void ExportAboveBelowAvrg(string k)
{
  ofstream NewTextFile(k);
  int average;
  float SumofMarks = 0;
  float AboveAverage = 0;
  float BelowAverage = 0;
  for (int i = 0; i < Marks.size(); i++) 
  {
    SumofMarks += Marks[i][currentSubject];
  }
  float AverageofMarks = SumofMarks/Marks.size();
  NewTextFile << "======================================================="<<endl;
  NewTextFile << "Above and Below Mean of " << MarksTitles[currentSubject] <<endl;
  NewTextFile << "======================================================="<<endl<<endl;
  NewTextFile << "======================================================="<<endl;
  NewTextFile << "These students scored greater or same marks as average " << endl;
  NewTextFile << "======================================================="<<endl;
  for (int i = 0; i < Marks.size(); i++)
  {
    if(Marks[i][currentSubject] >= AverageofMarks)
    { 
      NewTextFile << Marks[i][0] << "     |     " << Marks[i][currentSubject] << endl;
    }
  }
  NewTextFile << "======================================================="<<endl;
  NewTextFile << "These students scored less than average" << endl;
  NewTextFile << "======================================================="<<endl;
  for (int i = 0; i < Marks.size(); i++)
  {
    if(Marks[i][currentSubject] < AverageofMarks)
    { 
      NewTextFile << Marks[i][0] << "     |     " << Marks[i][currentSubject]<< endl;
    }
  }
  NewTextFile << "======================================================="<<endl<<endl;
  
}

/*
===================================================
Programmer : Abir
Name : ExportAboveBelowAvrghtml

Task : Exports the Above Below average marks to html file.
Data in - none
Data out - none
=================================================
*/
void ExportAboveBelowAvrghtml(string k)
{
  ofstream htmlfile(k);
  int average;
  float SumofMarks = 0;
  float AboveAverage = 0;
  float BelowAverage = 0;
  for (int i = 0; i < Marks.size(); i++) 
  {
    SumofMarks += Marks[i][currentSubject];
  }
  float AverageofMarks = SumofMarks/Marks.size();
  htmlfile << "======================================================="<<"<p>";
  htmlfile << "Above and Below Mean of " << MarksTitles[currentSubject] <<"<p>";
  htmlfile << "======================================================="<<"<p>""<p>";
  htmlfile << "======================================================="<<"<p>";
  htmlfile << "These students scored greater or same marks as average " << "<p>";
  htmlfile << "<table>======================================================="<<"<p>";
  for (int i = 0; i < Marks.size(); i++)
  {
    htmlfile << "<tr>";
    if(Marks[i][currentSubject] >= AverageofMarks)
    { 
      htmlfile <<"<th>"<< Marks[i][0] << "</th><td>" << Marks[i][currentSubject] << "</td>" <<"</tr>";
    }
  }
  htmlfile << "</table>======================================================="<<"<br>";
  htmlfile << "These students scored less than average" << "<br>";
  htmlfile << "<table>======================================================="<<"<br>";
  for (int i = 0; i < Marks.size(); i++)
  {
    if(Marks[i][currentSubject] < AverageofMarks)
    { 
      htmlfile << "<tr>";
      htmlfile <<"<th>" << Marks[i][0] << "</th><td>"<< Marks[i][currentSubject]<< "</td>" <<"</tr>";
    }
  }
  htmlfile << "</table>======================================================="<<"<br>""<br>";
}

/*
===================================================
Programmer : Abir
Name : Compare2Subjects()

Task : Displays data for the two selected columns for comparison
Data in - none
Data out - none
=================================================
*/
void Compare2Subjects()
{
  system("clear");
  float Subject1Marks=0, Subject2Marks=0,multiply=0,squaresub1=0,squaresub2=0,totalsub1=0,totalsub2=0, totalmultiply=0,totalsquaresub1=0, totalsquaresub2=0;
  string subject1, subject2;
  int i;
  cout << "Select the first subject" << endl;
  cout << "0. Go back"<<endl;
  for (int i = 1; i <(MarksTitles.size()-1); i++)
  {
    cout<<(i)<< ". " << MarksTitles[i+1] <<endl;
  }
  int choice1 = getChoice(0,MarksTitles.size()-2);
  switch (choice1) 
  {
   case 0:
     main_menu();
     break;
   default:
    currentSubject= choice1+1;
    subject1 = MarksTitles[currentSubject];
  }
    system("clear");
    cout << "Select the second subject" << endl;
    cout << "0. Go back"<<endl;
    for (int i = 1; i <(MarksTitles.size()-1); i++)
    {
    cout<<(i)<< ". " << MarksTitles[i+1] <<endl;
    }
    int choice2 = getChoice(0,MarksTitles.size()-2);
     ExportCompare2Subjects(choice1, choice2, "Compare"+subject1+subject2+".txt");
  switch (choice2) 
  {
   case 0:
     main_menu();
     break;
   default:
    currentSubject= choice2+1;
    subject2 = MarksTitles[currentSubject];
  }
  system("clear");
  cout << "========================================================================================================="<<endl;
  cout <<"                  " << subject1 <<" vs " << subject2<<"                 "<<endl;
  cout <<"                   A         B                 "<<endl; 
  cout << "========================================================================================================="<<endl<<endl;
  cout << "========================================================================================================="<<endl;
  cout <<"| "<<setw(14)<< "Student ID"<< " | " <<setw(14)<< "A" << " | "  <<setw(14)<< "B" << " | "   <<setw(14)<<"AB"   << " | "  <<setw(14)<< "A2" << " | "  <<setw(14) << "B2" << " | " << endl;
  cout << "========================================================================================================="<<endl;
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1+1];
    Subject2Marks= Marks[i][choice2+1];
    totalsub1+= Subject1Marks;
    totalsub2+= Subject2Marks;
    multiply = Marks[i][choice1+1]*Marks[i][choice2+1];
    totalmultiply += multiply;
    squaresub1 = Marks[i][choice1+1]*Marks[i][choice1+1];
    totalsquaresub1+=squaresub1;
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];
    totalsquaresub2+=squaresub2;

    cout <<"| "<<setw(14)<< Marks[i][0] << " | " <<setw(14)<< Subject1Marks << " | "   <<setw(14)<< Subject2Marks << " | "  <<setw(14) << multiply << " | "  <<setw(14)  << squaresub1  << " | " <<setw(14)<< squaresub2 << " | " << endl;
  }
  cout << "========================================================================================================="<<endl;
  
  cout <<"| "<<setw(14)<< "Total"  << " | " <<setw(14)<< totalsub1 << " | "   <<setw(14)<< totalsub2 << " | "  <<setw(14) << totalmultiply << " | "   <<setw(14)<< totalsquaresub1   << " | " <<setw(14)<< totalsquaresub2 << " | " << endl;
  cout << "========================================================================================================="<<endl<<endl;
  cout <<"Press any key to continue"<< endl;
  cout <<"Data has been exported to Compare"+subject1+".txt"<< endl;
  cout <<"Data has been exported to Compare"+subject1+".html"<< endl;
  ExportCompare2Subjectshtml(choice1, choice2, "Compare"+subject1+subject2+".html");
  getch();
  Compare2Subjects();
}

/*
===================================================
Programmer : Zaen
Name : ExportCompare2Subjects

Task : Exports the compare 2 subjects data to a text file
Data in - none
Data out - none
=================================================
*/
void ExportCompare2Subjects(int x, int y, string k)
{
  ofstream NewTextFile(k);
  float Subject1Marks=0, Subject2Marks=0,multiply=0,squaresub1=0,squaresub2=0,totalsub1=0,totalsub2=0, totalmultiply=0,totalsquaresub1=0, totalsquaresub2=0;
  string subject1, subject2;
  int i;
  
    currentSubject= x+1;
    subject1 = MarksTitles[currentSubject];
  
    currentSubject= y+1;
    subject2 = MarksTitles[currentSubject];
  
  
  NewTextFile<< "========================================================================================================="<<endl;
  NewTextFile<<"                  " << subject1 <<" vs " << subject2<<"                 "<<endl;
  NewTextFile<<"                   A         B                 "<<endl; 
  NewTextFile<< "========================================================================================================="<<endl<<endl;
  NewTextFile<< "========================================================================================================="<<endl;
  NewTextFile<<"| "<<setw(14)<< "Student ID"<< " | " <<setw(14)<< "A" << " | "  <<setw(14)<< "B" << " | "   <<setw(14)<<"AB"   << " | "  <<setw(14)<< "A2" << " | "  <<setw(14) << "B2" << " | " << endl;
  NewTextFile<< "========================================================================================================="<<endl;
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][x+1];
    Subject2Marks= Marks[i][y+1];
    totalsub1+= Subject1Marks;
    totalsub2+= Subject2Marks;
    multiply = Marks[i][x+1]*Marks[i][y+1];
    totalmultiply += multiply;
    squaresub1 = Marks[i][x+1]*Marks[i][x+1];
    totalsquaresub1+=squaresub1;
    squaresub2 = Marks[i][y+1]*Marks[i][y+1];
    totalsquaresub2+=squaresub2;

    NewTextFile<<"| "<<setw(14)<< Marks[i][0] << " | " <<setw(14)<< Subject1Marks << " | "   <<setw(14)<< Subject2Marks << " | "  <<setw(14) << multiply << " | "  <<setw(14)  << squaresub1  << " | " <<setw(14)<< squaresub2 << " | " << endl;
  }
  NewTextFile<< "========================================================================================================="<<endl;
  
  NewTextFile<<"| "<<setw(14)<< "Total"  << " | " <<setw(14)<< totalsub1 << " | "   <<setw(14)<< totalsub2 << " | "  <<setw(14) << totalmultiply << " | "   <<setw(14)<< totalsquaresub1   << " | " <<setw(14)<< totalsquaresub2 << " | " << endl;
  NewTextFile<< "========================================================================================================="<<endl<<endl;
}

/*
===================================================
Programmer : Abir
Name : ExportCompare2Subjectshtml

Task : Exports the compare 2 subjects data to a html page
Data in - none
Data out - none
=================================================
*/
void ExportCompare2Subjectshtml(int x, int y, string k)
{
ofstream htmlfile(k);
htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "table {font-family: arial, sans-serif;border-collapse: collapse;width: 100%;}"

"td, th {"
  "border: 1px solid #dddddd;"
  "text-align: left;"
  "padding: 8px;"
"}"

"tr:nth-child(even) {"
  "background-color: #dddddd;"
"}"
"</style>";
float Subject1Marks=0, Subject2Marks=0,multiply=0,squaresub1=0,squaresub2=0,totalsub1=0,totalsub2=0, totalmultiply=0,totalsquaresub1=0, totalsquaresub2=0;
  string subject1, subject2;
  int i;
  
    currentSubject= x+1;
    subject1 = MarksTitles[currentSubject];
  
    currentSubject= y+1;
    subject2 = MarksTitles[currentSubject];
  
  
  htmlfile<< "=========================================================================================================================================================================="<<"<br>";
  htmlfile << "<h2 style='text-align:center';> "<< subject1 << " vs " << subject2 << "</h2><br>";
  htmlfile<<"<h2 style='text-align:center';> A vs B </h2><br>"; 
  htmlfile<< "==========================================================================================================================================================================""<br>""<br>";
  htmlfile<<"<table><tr><th>Student ID</th><th>A</th><th>B</th><th>AB</th><th>A2</th><th>B2</th></tr>";
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][x+1];
    Subject2Marks= Marks[i][y+1];
    totalsub1+= Subject1Marks;
    totalsub2+= Subject2Marks;
    multiply = Marks[i][x+1]*Marks[i][y+1];
    totalmultiply += multiply;
    squaresub1 = Marks[i][x+1]*Marks[i][x+1];
    totalsquaresub1+=squaresub1;
    squaresub2 = Marks[i][y+1]*Marks[i][y+1];
    totalsquaresub2+=squaresub2;

    htmlfile<< "<tr><td>" << Marks[i][0] << "</td><td>" << Subject1Marks << "</td><td>" << Subject2Marks << "</td><td>"  << multiply << "</td><td>"    << squaresub1  << "</td><td>" << squaresub2 << "</td></tr>";
  }
  htmlfile<<"<tr><td>Total</td><td>"<< totalsub1 << "</td><td>" << totalsub2 <<"</td><td>" << totalmultiply << "</td><td>"<< totalsquaresub1   << "</td><td>"<< totalsquaresub2 << "</td></tr>";
  htmlfile<< 
  "</table>""=========================================================================================================================================================================="<<"<p><p>";
}


 /*
===================================================
Programmer : Abir
Name : PearsonsCorrelation()
Task : Calculates and displays Pearson Correlation for the two selected columns
Data in - None
Data out - none
=================================================
*/
void PearsonsCorrelation()
{
  int i;
  float Subject1Marks=0, Subject2Marks=0,totalsub1=0,totalsub2=0,squaresub1=0,squaresub2=0,totalsquaresub1=0,totalsquaresub2=0,multiplysubs=0,totalmultiply=0;
  string subject1, subject2;
  int choice1 = currentSubject;
  system("clear");
  cout << "Select the y axis" << endl;
  for (int i = 1; i <(MarksTitles.size()-1); i++)
  {
    cout<<(i)<< ". " << MarksTitles[i+1] <<endl;
  }
  int choice2 = getChoice(0,MarksTitles.size()-2);
  switch (choice2) 
  {
   case 0:
     main_menu();
     break;
   default:
    currentSubject= choice2+1;
    subject2 = MarksTitles[currentSubject];
  }
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1];
    Subject2Marks= Marks[i][choice2+1];
    totalsub1+= Subject1Marks;
    totalsub2+= Subject2Marks;
    squaresub1 = Marks[i][choice1]*Marks[i][choice1];
    totalsquaresub1+=squaresub1;
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];
    totalsquaresub2+=squaresub2;
    multiplysubs = Marks[i][choice1]*Marks[i][choice2+1];
    totalmultiply += multiplysubs;
  }
  int rowsnew = i;
  float x = rowsnew*(totalmultiply)-(totalsub1*totalsub2);
  float y = (rowsnew*totalsquaresub1)-(totalsub1*totalsub1);
  float z = (rowsnew*totalsquaresub2)-(totalsub2*totalsub2);
  float squareroot = sqrt(float (y*z));
  float r = (x/squareroot);
  system("clear");
  cout << "Pearson's Correlation of subjects " << MarksTitles[choice1] << " and " << MarksTitles[choice2+1] << " are: " << endl;
  cout << "===================================="<<endl;
  cout << "Pearson's Correlation   | "<<setprecision(4) << r << "    |" << endl;
  cout << "===================================="<<endl;
  cout <<"Data has been exported to Pearson"+subject1+subject2+".txt"<< endl << endl;
  ExportPearson(choice1, choice2, "Pearson"+subject1+subject2+".txt");
  cout <<"Data has been exported to Pearson"+subject1+subject2+".html"<< endl << endl;
  ExportPearsonhtml(choice1, choice2, "Pearson"+subject1+subject2+".html");
  cout << "Press any key to go back";
  currentSubject=choice1;
  getch();
  ViewMore();
}

/*
===================================================
Programmer : Abir
Name : ExportPearson

Task : Exports the Pearson Correlation data to a text file
Data in - none
Data out - none
=================================================
*/
void ExportPearson(int choice1, int choice2, string k)
{
  ofstream NewTextFile(k);
  int i;
  float Subject1Marks=0, Subject2Marks=0,totalsub1=0,totalsub2=0,squaresub1=0,squaresub2=0,totalsquaresub1=0,totalsquaresub2=0,multiplysubs=0,totalmultiply=0;
  string subject1, subject2;
  currentSubject= choice1;
  subject1 = MarksTitles[currentSubject];
  
  currentSubject= choice2+1;
  subject2 = MarksTitles[currentSubject];
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1];
    Subject2Marks= Marks[i][choice2+1];
    totalsub1+= Subject1Marks;
    totalsub2+= Subject2Marks;
    squaresub1 = Marks[i][choice1]*Marks[i][choice1];
    totalsquaresub1+=squaresub1;
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];
    totalsquaresub2+=squaresub2;
    multiplysubs = Marks[i][choice1]*Marks[i][choice2+1];
    totalmultiply += multiplysubs;
  }
  int rowsnew = i;
  float x = rowsnew*(totalmultiply)-(totalsub1*totalsub2);
  float y = (rowsnew*totalsquaresub1)-(totalsub1*totalsub1);
  float z = (rowsnew*totalsquaresub2)-(totalsub2*totalsub2);
  float squareroot = sqrt(float (y*z));
  float r = (x/squareroot);

  NewTextFile << "Pearson's Correlation of subjects " << MarksTitles[choice1] << " and " << MarksTitles[choice2+1] << " are: " << endl;
  NewTextFile << "===================================="<<endl;
  NewTextFile << "Pearson's Correlation   | "<<setprecision(4) << r << "    |" << endl;
  NewTextFile << "===================================="<<endl;
}

/*
===================================================
Programmer : Abir
Name : ExportPearsonhtml

Task : Exports the Pearson Correlation data to a html file
Data in - none
Data out - none
=================================================
*/
void ExportPearsonhtml(int choice1, int choice2, string k)
{
  ofstream htmlfile(k);
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "table {font-family: arial, sans-serif;border-collapse: collapse;width: 50%;}"

  "td, th {"
  "border: 1px solid #dddddd;"
  "text-align: left;"
  "padding: 8px;"
  "}"

  "tr:nth-child(even) {"
  "background-color: #dddddd;"
  "}"
  "</style>";
  int i;
  float Subject1Marks=0, Subject2Marks=0,totalsub1=0,totalsub2=0,squaresub1=0,squaresub2=0,totalsquaresub1=0,totalsquaresub2=0,multiplysubs=0,totalmultiply=0;
  string subject1, subject2;
  currentSubject= choice1;
  subject1 = MarksTitles[currentSubject];
  
  currentSubject= choice2+1;
  subject2 = MarksTitles[currentSubject];
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1];
    Subject2Marks= Marks[i][choice2+1];
    totalsub1+= Subject1Marks;
    totalsub2+= Subject2Marks;
    squaresub1 = Marks[i][choice1]*Marks[i][choice1];
    totalsquaresub1+=squaresub1;
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];
    totalsquaresub2+=squaresub2;
    multiplysubs = Marks[i][choice1]*Marks[i][choice2+1];
    totalmultiply += multiplysubs;
  }
  int rowsnew = i;
  float x = rowsnew*(totalmultiply)-(totalsub1*totalsub2);
  float y = (rowsnew*totalsquaresub1)-(totalsub1*totalsub1);
  float z = (rowsnew*totalsquaresub2)-(totalsub2*totalsub2);
  float squareroot = sqrt(float (y*z));
  float r = (x/squareroot);
  htmlfile <<"=========================================================================================================================================================================="<<"<br>";
  htmlfile << "<h2 style='text-align:center';>Pearson's Correlation of subjects " << MarksTitles[choice1] << " and " << MarksTitles[choice2+1] << " are: " << "</h2><br>";
  htmlfile <<"=========================================================================================================================================================================="<<"<br>";
  htmlfile << "<table class = center><tr>";
  htmlfile << "<th>Pearson's Correlation</th></tr><tr><td>"<< r << "</td></tr></table><br>";
  htmlfile <<"=========================================================================================================================================================================="<<"<br>";
}

 /*
===================================================
Programmer : Abir
Name : linearRegression()
Task : Calculates and displays Linear Regression Line for the two selected columns
Data in - none
data out - none
=================================================
*/

void linearRegression()
{
  int i; //Set i as an integer
  float Subject1Marks=0, Subject2Marks=0,totalsub1=0,totalsub2=0,squaresub1=0,squaresub2=0,totalsquaresub1=0,totalsquaresub2=0,multiplysubs=0,totalmultiply=0;
  string subject1, subject2;  // Set all these as float
  int choice1 = currentSubject; // It will store the data of the subject that the person has currently chosen.
  system("clear");
  cout << "Select the y axis" << endl;
  for (int i = 1; i <(MarksTitles.size()-1); i++)
  {
    cout<<(i)<< ". " << MarksTitles[i+1] <<endl;
  }
  int choice2 = getChoice(0,MarksTitles.size()-2);//Stores the data of the other subject that the person chose.
  switch (choice2) 
  {
   case 0:
     main_menu();
     break;
   default:
    currentSubject= choice2+1;
    subject2 = MarksTitles[currentSubject];
  }
  system("clear");
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1];//store the mark of the first subject.
    Subject2Marks= Marks[i][choice2+1];// store the mark of the second subject.
    totalsub1+= Subject1Marks;//Adds each of the marks of the first subject. 
    totalsub2+= Subject2Marks;//Adds each of the marks of the second subject.
    squaresub1 = Marks[i][choice1]*Marks[i][choice1];//square the marks of the first subject.
    totalsquaresub1+=squaresub1;//adds all the squared marks of the first subject.
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];//square the marks of the second subject.
    totalsquaresub2+=squaresub2;//adds all the squared marks of the second subject.
    multiplysubs = Marks[i][choice1]*Marks[i][choice2+1];
    totalmultiply += multiplysubs;

  }
  int rows = i;
  float x = (totalsub2*totalsquaresub1-totalsub1*(totalmultiply))/(rows*(totalsquaresub1)-totalsub1*totalsub1);//total marks of second subject is multiplied by total squared marks of first subject minus total marks of first subject multiplied by the addition of the total marks of first and second subject.
  float y = (rows*(totalmultiply)-totalsub1*totalsub2)/(rows*(totalsquaresub1)-totalsub1*totalsub1);
  cout << "Linear Regression of subjects " << MarksTitles[choice1] << " and " << MarksTitles[choice2+1] << " are: " << endl;
  cout << "===================================="<<endl;
  cout << "y' = " << x << " + " << y << "x" << endl;
  cout << "===================================="<<endl;
  cout <<"File has been exported to Linear Regression"+MarksTitles[currentSubject]+".txt"<<endl<<endl;
  exportlinearregression(choice1, choice2, "Regressionline"+subject1+subject2+".txt");
  cout <<"File has been exported to Linear Regression"+MarksTitles[currentSubject]+".html"<<endl<<endl;
  exportlinearregressionhtml(choice1, choice2, "Regressionline"+subject1+subject2+".html");
  cout << "Press any key to go back";
  currentSubject=choice1;
  getch();
  ViewMore();
}

 /*
===================================================
Programmer : Abir
Name : exportlinearregression(int choice1, int choice2, string k)
Task : Exports the Linear Regression to a text file
Data  in - None
Data out - None
=================================================
*/

void exportlinearregression(int choice1, int choice2, string k)
{
  ofstream NewTextFile(k);
  int i; //Set i as an integer
  float Subject1Marks=0, Subject2Marks=0,totalsub1=0,totalsub2=0,squaresub1=0,squaresub2=0,totalsquaresub1=0,totalsquaresub2=0,multiplysubs=0,totalmultiply=0;
  string subject1, subject2;  // Set all these as float

  currentSubject= choice1;
  subject1 = MarksTitles[currentSubject];
  
  currentSubject= choice2+1;
  subject2 = MarksTitles[currentSubject];
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1];//store the mark of the first subject.
    Subject2Marks= Marks[i][choice2+1];// store the mark of the second subject.
    totalsub1+= Subject1Marks;//Adds each of the marks of the first subject. 
    totalsub2+= Subject2Marks;//Adds each of the marks of the second subject.
    squaresub1 = Marks[i][choice1]*Marks[i][choice1];//square the marks of the first subject.
    totalsquaresub1+=squaresub1;//adds all the squared marks of the first subject.
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];//square the marks of the second subject.
    totalsquaresub2+=squaresub2;//adds all the squared marks of the second subject.
    multiplysubs = Marks[i][choice1]*Marks[i][choice2+1];
    totalmultiply += multiplysubs;

  }
  int rows = i;
  float x = (totalsub2*totalsquaresub1-totalsub1*(totalmultiply))/(rows*(totalsquaresub1)-totalsub1*totalsub1);//total marks of second subject is multiplied by total squared marks of first subject minus total marks of first subject multiplied by the addition of the total marks of first and second subject.
  float y = (rows*(totalmultiply)-totalsub1*totalsub2)/(rows*(totalsquaresub1)-totalsub1*totalsub1);
  NewTextFile << "Linear Regression of subjects " << MarksTitles[choice1] << " and " << MarksTitles[choice2+1] << " are: " << endl;
  NewTextFile << "===================================="<<endl;
  NewTextFile << "y' = " << x << " + " << y << "x" << endl;
  NewTextFile << "===================================="<<endl;
}


 /*
===================================================
Programmer : Abir
Name : exportlinearregressionhtml(int choice1, int choice2, string k)
Task : Exports the Linear Regression to a html file
Data in - none
Data out - none
=================================================
*/

void exportlinearregressionhtml(int choice1, int choice2, string k)
{
  ofstream htmlfile(k);
  int i; //Set i as an integer
  float Subject1Marks=0, Subject2Marks=0,totalsub1=0,totalsub2=0,squaresub1=0,squaresub2=0,totalsquaresub1=0,totalsquaresub2=0,multiplysubs=0,totalmultiply=0;
  string subject1, subject2;  // Set all these as float

  currentSubject= choice1;
  subject1 = MarksTitles[currentSubject];
  
  currentSubject= choice2+1;
  subject2 = MarksTitles[currentSubject];
  for(i=0;i<Marks.size();i++)
  {
    Subject1Marks= Marks[i][choice1];//store the mark of the first subject.
    Subject2Marks= Marks[i][choice2+1];// store the mark of the second subject.
    totalsub1+= Subject1Marks;//Adds each of the marks of the first subject. 
    totalsub2+= Subject2Marks;//Adds each of the marks of the second subject.
    squaresub1 = Marks[i][choice1]*Marks[i][choice1];//square the marks of the first subject.
    totalsquaresub1+=squaresub1;//adds all the squared marks of the first subject.
    squaresub2 = Marks[i][choice2+1]*Marks[i][choice2+1];//square the marks of the second subject.
    totalsquaresub2+=squaresub2;//adds all the squared marks of the second subject.
    multiplysubs = Marks[i][choice1]*Marks[i][choice2+1];
    totalmultiply += multiplysubs;

  }
  int rows = i;
  float x = (totalsub2*totalsquaresub1-totalsub1*(totalmultiply))/(rows*(totalsquaresub1)-totalsub1*totalsub1);//total marks of second subject is multiplied by total squared marks of first subject minus total marks of first subject multiplied by the addition of the total marks of first and second subject.
  float y = (rows*(totalmultiply)-totalsub1*totalsub2)/(rows*(totalsquaresub1)-totalsub1*totalsub1);
  htmlfile << "Linear Regression of subjects " << MarksTitles[choice1] << " and " << MarksTitles[choice2+1] << " are: " << endl;
  htmlfile << "===================================="<<"<br>";
  htmlfile << "y' = " << x << " + " << y << "x" <<"<br>";
  htmlfile << "====================================<br>";
}

 /*
===================================================
Programmer : Zaen 60%, Abir 40%
Name : AscendingDescending()
Task : Calculates and displays the imported data in ascending or descending order
Data in - None
Data out - None
=================================================
*/
void AscendingDescending()
{
  system("clear");
  int i;
  bool asc;
  bool Descendingcol(const vector<int> &v1, const vector<int> &v2);
  vector<vector<int>> tempMarks = Marks;
  cout << "What do you want to sort?" << endl;
  cout << "0. Go back"<<endl;
  for (i=0;i<MarksTitles.size();i++)
  {
    cout<<(i+1)<< ". " << MarksTitles[i] <<endl;
  }
  int choice = getChoice(0,MarksTitles.size());
  switch (choice) 
  {
   case 0:
     main_menu();
     break;
   default:
   currentSubject= choice-1;
   system("clear");
   cout <<"How do you want to sort it?" << endl << "1. Ascending order" << endl << "2. Descending order" << endl;
   int choice2 = getChoice(1,2);
  ExportAscendingDescending(choice, choice2, MarksTitles[currentSubject] +".txt");
  ExportAscendingDescendinghtml(choice, choice2, MarksTitles[currentSubject] +".html");
   switch(choice2)
   {
     case 1:
      sort(tempMarks.begin(), tempMarks.end(),Ascendingcol); 
      break;
     case 2:
      sort(tempMarks.begin(), tempMarks.end(),Descendingcol);
      break;
   }
	} 
  cout <<endl<<endl;
	// Use of "sort()" for sorting on basis 
	// of 2nd column 
	// Displaying the 2D vector after sorting 
  cout << "=======================================================" <<endl;
	cout << "                    Sorted Data                     " <<endl;
  cout << "=======================================================" <<endl<<endl;
  cout<<"-------------------------------------------------------------------------------------------"<<endl;
  for (int i =0; i< MarksTitles.size();i++)
  {
  cout  <<" | "<< setw(10)  << MarksTitles[i]; 
  }
  
   cout<<endl<<"-------------------------------------------------------------------------------------------"<<endl;
	for (int i=0; i<Marks.size(); i++) 
	{ 
		for (int j=0; j<Marks[0].size();j++) 
			cout  <<" | "<< setw(10)  << tempMarks[i][j]; 

		cout << " |" <<endl 
    <<"-------------------------------------------------------------------------------------------"<<endl;
	} 
cout <<"Press any key to continue"<<endl<<endl;
cout <<"File has been exported to "+ MarksTitles[currentSubject] +".txt";
cout <<"File has been exported to "+ MarksTitles[currentSubject] +".html";
  getch();
  AscendingDescending();

}


 /*
===================================================
Programmer : Zaen
Name : ExportAscendingDescending()
Task : Calculates and exports a table of the data in ascending or descending order in a txt file
Data in - None
Data out - None
=================================================
*/
void ExportAscendingDescending(int x, int y, string z)
{
  ofstream NewTextFile(z);
  int i;
  bool asc;
  bool Descendingcol(const vector<int> &v1, const vector<int> &v2);
  vector<vector<int>> tempMarks = Marks;
   currentSubject= x-1;
   switch(y)
   {
     case 1:
      sort(tempMarks.begin(), tempMarks.end(),Ascendingcol); 
      break;
     case 2:
      sort(tempMarks.begin(), tempMarks.end(),Descendingcol);
      break;
   }
  cout <<endl<<endl;
	// Use of "sort()" for sorting on basis 
	// of 2nd column 
	// Displaying the 2D vector after sorting 
  NewTextFile << "=======================================================" <<endl;
	NewTextFile << "                    Sorted Data                     " <<endl;
  NewTextFile << "=======================================================" <<endl<<endl;
  NewTextFile <<"-------------------------------------------------------------------------------------------"<<endl;
  for (int i =0; i< MarksTitles.size();i++)
  {
  NewTextFile <<" | "<< setw(10)  << MarksTitles[i]; 
  }
   NewTextFile <<endl<<"-------------------------------------------------------------------------------------------"<<endl;
	for (int i=0; i<Marks.size(); i++) 
	{ 
		for (int j=0; j<Marks[0].size();j++) 
			NewTextFile <<" | "<< setw(10)  << tempMarks[i][j]; 

		NewTextFile << " |" <<endl 
    <<"-------------------------------------------------------------------------------------------"<<endl; 
	} 
}





 /*
===================================================
Programmer : Zaen
Name : ExportFreqMenu(string k)
Task : Exports the Frequency table to a text file
Data in - none
Data out - none
=================================================
*/
void ExportFreqMenu(string k)
{
  ofstream NewTextFile(k);
    NewTextFile << "====================================================="<<endl;
    NewTextFile << "Marks Frequency Distribution of " << MarksTitles[currentSubject] <<endl;
    NewTextFile << "==================================================="<<endl<<endl;
    NewTextFile << "=================================="<<endl;
    NewTextFile <<   "| Marks     |  Frequency         |"<<endl;
    NewTextFile << "=================================="<<endl;
    int num;
    int freq= 0;
    for (int num=0; num < 101; num++)
    {
      for (int i=0; i < Marks.size(); i++)
      {
        if (Marks[i][currentSubject] == num)
        {
          freq +=1;
        }
      }
      if (freq >= 1)
      {
        NewTextFile << "| " << setw(2) <<  num << "        |       " << freq <<  "            |" << endl;
        int i = 0;
        freq=0;
      }
    }
    NewTextFile << "=================================="<<endl<<endl;
  }

 /*
===================================================
Programmer : Zaen
Name : ExportReportToText()
Task : Exports a report of all the data to a text file.
Data in - none
Data out - none
=================================================
*/

void ExportReportToText()
{ 
  ifstream read;
	ofstream write;
  ofstream NewTextFile;
  NewTextFile.open ("Report.txt");
  for (int i = 1; i < Marks[0].size(); i++)
  {
   NewTextFile <<MarksTitles[i] <<" Report"<<endl ;
   NewTextFile  << "==================================================="<<endl;
   NewTextFile  <<setw(20)  << "Min Mark"<<" : " << setprecision(4) <<MinFunc(i)<<endl;
   NewTextFile <<setw(20) << "Max Mark" <<" : "<< setprecision(4) <<MaxFunc(i) <<endl;
   NewTextFile  <<setw(20)<< "Mean Mark" <<" : "<< setprecision(4) <<MeanFunc(i) <<endl;
   NewTextFile  <<setw(20)<< "Median Mark" <<" : "<< setprecision(4) <<MedianFunc(i) <<endl;
   NewTextFile  <<setw(20)<< "Variance Mark" <<" : "<< setprecision(4) <<VarFunc(i) <<endl;
   NewTextFile  <<setw(20) << "Standard Deviation" <<" : "<< setprecision(4) <<StdFunc(i) <<endl;
   NewTextFile  << "==================================================="<<endl<<endl;
  }

}

 /*
===================================================
Programmer : Zaen
Name : Report()
Task : Displays a report of all the data.
Data in - none
Data out - none
=================================================
*/

void Report()
{ 
  system("clear");

  for (int i = 1; i < Marks[0].size(); i++)
  {
   cout<<MarksTitles[i] <<" Report"<<endl ;
   cout<< "==================================================="<<endl;
   cout<<setw(20)  << "Min Mark"<<" : " << setprecision(4) <<MinFunc(i)<<endl;
   cout<<setw(20) << "Max Mark" <<" : "<< setprecision(4) <<MaxFunc(i) <<endl;
   cout<<setw(20)<< "Mean Mark" <<" : "<< setprecision(4) <<MeanFunc(i) <<endl;
   cout<<setw(20)<< "Median Mark" <<" : "<< setprecision(4) <<MedianFunc(i) <<endl;
   cout<<setw(20)<< "Variance Mark" <<" : "<< setprecision(4) <<VarFunc(i) <<endl;
   cout<<setw(20) << "Standard Deviation" <<" : "<< setprecision(4) <<StdFunc(i) <<endl;
   cout<< "==================================================="<<endl<<endl;
  }
  cout <<"Data has been exported to Report.txt"<<endl;
  cout <<"Data has been exported to Report.html"<<endl;
  cout <<"Press any key to continue";
  ExportReportToText();
  CreateHTML();
  getch();
  main_menu();

}
 /*
===================================================
Programmer : Abir
Name : CreateHTML()
Task : Exports the Statistically calculated data to a html file. Select overall report to display this in a html file.
Data in - none
Data out - none
=================================================
*/


void CreateHTML()
{
  ofstream htmlfile;
  htmlfile.open ("Report.html");
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "td, th {"
  "border: 1px solid #dddddd"
  "text-align: center"
  "padding: 8px" 
  "}"
  "tr:nth-child(even) {"
  "background-color: #dddddd;"
  "}"
  "</style>";
  htmlfile << "Below is the table of the statistical data"
  "<table width='100%' border='1' bgcolor='#FFFFDD' align='center'>"
  "<tr>"
  "<th>" << "Subjects" << "</th>"
    "<th>" << "Min Mark" << "</th>"
    "<th>" << "Max Mark" << "</th>"
    "<th>" << "Mean Mark" << "</th>"
    "<th>" << "Median Mark" << "</th>"
    "<th>" << "Variance" << "</th>"
    "<th>" << "Standard Deviation" << "</th>";
  htmlfile << "Below is the table of the statistical data";
  for (int i=2; i< Marks[0].size(); i++)
  {
   
    htmlfile <<
    "<tr>"
    "<td>" << MarksTitles[i] << "</td>"
    "<td>" << MinFunc(i) << "</td>"
    "<td>" << MaxFunc(i) << "</td>"
    "<td>" << MeanFunc(i) << "</td>"
    "<td>" << MedianFunc(i) << "</td>"
    "<td>" << VarFunc(i) << "</td>"
    "<td>" << StdFunc(i) << "</td>";

  }
  htmlfile << "</table>";
  htmlfile << "</body></html>";
  htmlfile.close();

}

 /*
===================================================
Programmer : Abir
Name : ExportFileTohtml()
Task : Exports the Statistically calculated data to a html page.
Data in - none
Data out - none
=================================================
*/

void ExportFileTohtml()
{ 
  ofstream htmlfile;
  htmlfile.open ("C:\\report.html");
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "td, th {"
  "border: 1px solid #dddddd"
  "text-align: center"
  "padding: 8px" 
  "}"
  "tr:nth-child(even) {"
  "background-color: #dddddd;"
  "}"
  "</style>";
  htmlfile << "Below is the table of the statistical data"
  "<table width='100%' border='1' bgcolor='#FFFFDD' align='center'>"
  "<tr>"
  "<th>" << "Subjects" << "</th>"
    "<th>" << "Min Mark" << "</th>"
    "<th>" << "Max Mark" << "</th>"
    "<th>" << "Mean Mark" << "</th>"
    "<th>" << "Median Mark" << "</th>"
    "<th>" << "Variance" << "</th>"
    "<th>" << "Standard Deviation" << "</th>";
  htmlfile << "Below is the table of the statistical data";
  for (int i=2; i< Marks[0].size(); i++)
  {
   
    htmlfile <<
    "<tr>"
    "<td>" << MarksTitles[i] << "</td>"
    "<td>" << MinFunc(i) << "</td>"
    "<td>" << MaxFunc(i) << "</td>"
    "<td>" << MeanFunc(i) << "</td>"
    "<td>" << MedianFunc(i) << "</td>"
    "<td>" << VarFunc(i) << "</td>"
    "<td>" << StdFunc(i) << "</td>";

  }
  htmlfile << "</table>";
  htmlfile << "</body></html>";
  htmlfile.close();
}

 /*
===================================================
Programmer : Abir
Name : ExporttxtMenutohtml
Task - Exports menu to a html file
data in - none
Data out - none
=================================================
*/
void ExporttxtMenutohtml(string m) 
{
  ofstream htmlfile;
  htmlfile.open (m + MarksTitles[currentSubject]+".html");
  htmlfile <<MarksTitles[currentSubject]<<"<p>";
  htmlfile << "=========================================================================================================================================================================="<<"<p>";
  htmlfile <<m<< " : ";
  
  switch(currentCalc)
  {
  case 1:
    htmlfile << MinFunc(currentSubject) << "<p>";
    break;  
  case 2:
    htmlfile << MaxFunc(currentSubject) << "<p>";
    break;  
  case 3:
    htmlfile << MedianFunc(currentSubject) << "<p>";
    break;  
  case 4:
    htmlfile << MeanFunc(currentSubject) << "<p>";
    break;  
  case 5:
    htmlfile << VarFunc(currentSubject) << "<p>";
    break;  
  case 6:
    htmlfile << StdFunc(currentSubject) << "<p>";
    break;  
  }
}

/*
===================================================
Programmer : Abir
Name : ExportTxtMenuAlltohtml(string m) 
Task : Exports a report of all the calculations for each subjects to a html file
Data in - None
Data out - none
=================================================
*/
void ExportTxtMenuAlltohtml(string m) 
{
  ofstream htmlfile;
  htmlfile.open (m + "All.html");
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "td, th {"
  "border: 1px solid #dddddd"
  "text-align: center"
  "padding: 8px" 
  "}"
  "tr:nth-child(even) {"
  "background-color: #dddddd;"
  "}"
  "</style>";

  htmlfile <<m <<" of all Subjects" <<"<p>" ;
  htmlfile << "=========================================================================================================================================================================="<<"<p>";
  htmlfile <<" "
  "<table>";

  for (int i = 1; i < MarksTitles.size();i++)
  {
      htmlfile <<
    "<tr>"
    "<th>" << MarksTitles[i] << "</th>"
    "</tr>";
  switch(currentCalc)
  {
      htmlfile <<"<tr>";
    case 1:
      htmlfile <<"<td>"<< "Minimum = " << MinFunc(i) <<"</td>";
      break;
    case 2:
      htmlfile <<"<td>"<< "Maximum = " << MaxFunc(i)<<"</td>";
      break;
    case 3:
      htmlfile <<"<td>"<< "Median = " <<MedianFunc(i)<<"</td>";
      break;
    case 4:
      htmlfile <<"<td>"<< "Mean = " << MeanFunc(i)<<"</td>";
      break;
    case 5: 
      htmlfile <<"<td>"<< "Varriance = " << VarFunc(i)<<"</td>";
      break;
    case 6:
      htmlfile <<"<td>"<< "Standard Deviation = " <<StdFunc(i)<<"</td>";
      break;
      htmlfile << "</tr>";
  }
  }
  htmlfile << "</table></body></html>";
  htmlfile <<"<p>"<<"==========================================================================================================================================================================";
  htmlfile.close();
}
 /*
===================================================
Programmer : Abir
Name : ExportFreqMenutohtml(string k)
task : Exports the Frequency Table to a html file.
Data in - none
Data out - none
=================================================
*/
void ExportFreqMenutohtml(string k)
{
  ofstream htmlfile(k);
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "table {"
  "font-family: arial, sans-serif;"
  "border-collapse: collapse;"
  "width: 50%;"
  "}"

"td, th {"
  "border: 1px solid #dddddd;"
  "text-align: left;"
  "padding: 8px;"
"}"

"tr:nth-child(even) {"
  "background-color: #dddddd;"
"}"
"</style>";
    htmlfile << "=========================================================================================================================================================================="<<"<br>";
    htmlfile << "<h2>Marks Frequency Distribution of " << MarksTitles[currentSubject] <<"</h2><br>";
    htmlfile << "=========================================================================================================================================================================="<<"<br>";
    htmlfile <<   "<table><tr><th>Marks</th><th>Frequency</th></tr>";
    int num;
    int freq= 0;
    for (int num=0; num < 101; num++)
    {
      for (int i=0; i < Marks.size(); i++)
      {
        if (Marks[i][currentSubject] == num)
        {
          freq +=1;
        }
      }
      if (freq >= 1)
      {
        htmlfile<< "<tr><td>"<<  num << "</td><td>" << freq << "</td></tr>";
        int i = 0;
        freq=0;
      }
    }
    htmlfile << "</table>";
    htmlfile << "=========================================================================================================================================================================="<<"<br><br>";
  }

 /*
===================================================
Programmer : Abir
Name : ExportHistMenutohtml(string k)
Task : Exports the Histogram table to a html file of a subject selected by the user.
Data in - none
Data out - none
=================================================
*/
void ExportHistMenutohtml(string k)
{
  
  ofstream htmlfile(k);
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "table {"
  "font-family: arial, sans-serif;"
  "border-collapse: collapse;"
  "width: 100%;"
  "}"

"td, th {"
  "border: 1px solid #dddddd;"
  "text-align: left;"
  "padding: 8px;"
"}"

"tr:nth-child(even) {"
  "background-color: #dddddd;"
"}"
"</style>";
  htmlfile << "=========================================================================================================================================================================="<<"<br>";
  htmlfile << "<h2>Histogram of " << MarksTitles[currentSubject] <<"</h2><p>";
  htmlfile << "=========================================================================================================================================================================="<<"<br>";
  htmlfile <<   "<table><tr><th>Marks</th><th>Frequency</th>"<<"</tr><p>";
  int min = 0;
  int max = 9;
  int freq= 0;
  for (int i=0; i < Marks.size()+1; i++)
  {
    if ((Marks[i][currentSubject] >= min) && (Marks[i][currentSubject] <= max))
    {
      freq +=1;
    }
    if (i == Marks.size()-1)
    {
      string sfreq(freq, '*');
      htmlfile << "<tr><td>"<<  max <<"</td><td>" << sfreq << "</td></tr>" << "<p>";
      min += 10;
      max += 10;
      i = 0;
      freq=0;
    }
    if (max == 109)
    {
      i = Marks.size();
    }
  }
  htmlfile << "=========================================================================================================================================================================="<<"<br>";
}

/*
===================================================
Programmer : Abir
Name : ExportAscendingDescendinghtml(int x, int y, string k)
Task : Exports the table of the data in a descending or ascending order to html
Data in - none
Data out - none
=================================================
*/
void ExportAscendingDescendinghtml(int x, int y, string k)
{
  ofstream htmlfile(k);
  htmlfile << "<!DOCTYPE html><html><head></head><body><style>"
  "table {"
  "font-family: arial, sans-serif;"
  "border-collapse: collapse;"
  "}"

"td, th {"
  "border: 1px solid #dddddd;"
  "text-align: left;"
  "padding: 8px;"
"}"

"tr:nth-child(even) {"
  "background-color: #dddddd;"
"}"
"</style>";
  int i;
  bool asc;
  bool Descendingcol(const vector<int> &v1, const vector<int> &v2);
  vector<vector<int>> tempMarks = Marks;
   currentSubject= x-1;
   switch(y)
   {
     case 1:
      sort(tempMarks.begin(), tempMarks.end(),Ascendingcol); 
      break;
     case 2:
      sort(tempMarks.begin(), tempMarks.end(),Descendingcol);
      break;
   }
	// Use of "sort()" for sorting on basis 
	// of 2nd column 
	// Displaying the 2D vector after sorting 
  htmlfile << "<h2 style='text-align:center';>""=======================================================<br>"
	"Sorted Data by " << MarksTitles[currentSubject] << "<br>"
 "=======================================================</h2><br>";
  htmlfile << "<table>";
  htmlfile << "<tr>";
  for (int i =0; i< Marks.size();i++)
  {
  for (int j=0; j<Marks[0].size();j++) 
			{
        htmlfile <<"<td>"<< tempMarks[i][j]<<"</td>";
      }
      htmlfile << "</tr>";
  }
  htmlfile <<"</table>"<< "=========================================================================================================================================================================="<<"<br>";
}