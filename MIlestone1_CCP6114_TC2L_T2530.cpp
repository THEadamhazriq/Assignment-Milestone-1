//-----------------------------------------------------------------------------------------------------------------------
// Program: Milestone1_
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC2L
// Tutorial Class: TT8L
// Trimester: 2530
// Member_1: 253UC255QH | Megat Harith Na'il bin Mohd Husaini | MEGAT.HARITH.NAIL@student.mmu.edu.my | +601111305728
// Member_2: 252UC2422B | Muhammad Adam Hazriq Bin MOHD Amiruddin | MUHAMMAD.ADAM.HAZRIQ1@student.mmu.edu.my | +60126500498
// Member_3: 252UC243LL | MOHAMAD ZAIRUL NAIM | MOHAMAD.ZAIRUL.NAIM1@student.mmu.edu.my | +60167481189
// Member_4: 253UC256HA | AHMED OSAMA ELEASHID ALI | AHMED.OSAMA.ELRASHID@student.mmu.edu.my | +60175795884
// -----------------------------------------------------------------------------------------------------------------------
// Task Distribution
// Member_1: NIGGERSSSSSS
// Member_2:
// Member_3:
// Member_4:
// -----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// First step is to set Constants and Arrays
const int maxRows = 100;
const int maxColumns = 10;

string Sheet_Name;
string Name_Column[maxColumns];
int Number_Column = 0;

//Parallel Arrays to store student data
int Student_ID[maxRows]; // Stores student ID
string Student_Name[maxRows]; // Store student name
string Attendance_Status[maxRows]; //  store status e.g present, absent
int Row_Counter = 0;

// Second step is defining the functions for sheet names and columns
void Sheet_Create(){
    cout << "Enter the name of attendance sheet: ";
    getline(cin, Sheet_Name);

    cout << "Define number of columns (maximum is 10): ";
    cin >>  Number_Column;

    if (Number_Column > maxColumns) Number_Column = maxColumns;
    cin.ignore();
    for (int a = 0; a < Number_Column; a++){
        cout << "Enter Column " << (a + 1) << " name: ";
        getline(cin, Name_Column[a]);
    }


}


void Row_Insert(){
    if (Row_Counter >= maxRows){
        cout << "Error: The sheet is full. try again." << endl;
        return;
    }
    cout << "------------------------------------------------------" << endl;
    cout << "Create new Attendance Row " << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "Enter Student ID: ";


    cout << "Enter the StudentID: ";
    while (!(cin >> Student_ID[Row_Counter])){
        cout << "Error: Please enter a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, Student_Name[Row_Counter]);

    cout << "Enter Status (Present: 1,  Absent: 0): ";
    getline(cin, Attendance_Status[Row_Counter]);

    Row_Counter++;

    cout << "Row inserted successfully." << endl;
}

void Sheet_ViewCSV(){
    cout << "-------------------------------------------" << endl;
    cout << "View Attendance Sheet in CSV Mode" << endl;
    cout << "-------------------------------------------" << endl;

    for ( int a  = 0; a < Number_Column; a++){
        cout << Name_Column[a];
        if (a < Number_Column - 1){
            cout << ", ";
        }
    }

        for (int a = 0; a < Row_Counter; a++){
            cout << Student_ID[a] << ", ";
            cout << Student_Name[a] << ", ";
            cout << Attendance_Status[a] << endl;
        }
}

int main(){
    int choice;

    cout << "*****************************************" << endl;
    cout << "        STUDENT ATTENDANCE TRACKER       " << endl;
    cout << "*****************************************" << endl;

    Sheet_Create();

    do{
        cout << "\n---- Menue ----" << endl;
        cout << "1: Create new Attendance Row" << endl;
        cout << "2: View Attendance Sheet in CSV" << endl;
        cout << "3: Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)){
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice){
            case 1: Row_Insert(); break;
            case 2: Sheet_ViewCSV(); break;
            case 3: cout << "***************************" << endl;
                    cout << "End of Attendance Tracker" << endl;
                    cout << "***************************" << endl;
                    break;

            default:
                cout << "Error. Try again." << endl;


        }


    } while (choice != 3);

    return 0;


}



















