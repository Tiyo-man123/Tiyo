#include <iostream>

using namespace std;

const int MAX = 2000;
  
struct Student {
    int id;
    char name[50];
    float gpa;
    float  numGrades;
    float averageGPA;
    int year;
	float phone;
    
};

Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        cout << "Maximum student limit reached"<<endl;
        return;
    }
    cout << "Enter ID: ";
    cin >> students[count].id;
    cin.ignore(); 
    cout << "Enter Full Name: ";
    cin.getline(students[count].name, 50);
    
  int year ; 
          cout << "Enter year of admission : ";
           cin>>students[count].year;
   int phone ; 
          cout << "Enter phone number : ";
           cin>>students[count].phone;
       
  
     int numGrades;
    cout << "Enter the number of corses thaken: ";
    cin >> numGrades;

    float totalGPA = 0.0;

    for (int i = 0; i < numGrades; ++i) {
        float grade;
        cout << "Enter grade of corse " << (i + 1) << " (Out of 100%): ";
       cin >> grade;

        float gpa;
        if (grade >= 90) gpa = 4.0;
        else if (grade >= 80) gpa = 3.0;
        else if (grade >= 70) gpa = 2.0;
        else if (grade >= 60) gpa = 1.0;
        else gpa = 0.0;

        totalGPA += gpa;
       
    }
       float averageGPA = totalGPA / numGrades;
        students[count].averageGPA = averageGPA;
        students[count].numGrades = numGrades;

    
    count++;
    cout << endl<<endl<< "Student added successfully.";
    cout<<endl<<endl<<endl<<endl<<endl;
}

void update(int id) {
    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            cout << "Found: ID: " << students[i].id<<endl;
          int choice;
		      
            	cout << "__________________________________"<<endl<<endl;
            	cout<<"Whate do you whant to update ?"<<endl;
            		cout<< "|   1.ID: " << students[i].id<<endl;
                 cout << "|   2.Name: " << students[i].name<<endl;
         cout << "|   3.N.o of corse taken " << students[i].numGrades<<endl;
		cout << "|   4.GPA : "<< students[i].averageGPA << endl;
		cout << "|   5.year of addmission : "<<students[i].year<< endl;
		cout << "|   6.phone number : "<<students[i].phone<< endl;
		cout <<"|"<< "__________________________________"<<endl<<endl<<endl<<endl;
		cin>>choice;
		 switch(choice)
   {
    case 1:
     cout<<" Enter new id : ";
     cin>>students[i].id;
     break;
    case 2:
     cout<<" Enter new full Name : ";
     cin>>students[i].name;
    
     break;
    case 3:
     cout<<" Enter N.o of corse taken : ";
     cin>>students[i].numGrades;
    
     break;
    case 4:
     cout<<"a correction on gpa : ";
     cin>>students[i].averageGPA;
    break;
    case 5:
     cout<<"year of addmission  : ";
     cin>>students[i].year;
     break;
      case 6:
     cout<<"phoen number  : ";
     cin>>students[i].phone;
     break;
	
            return;
        }
    }
    cout << endl<<endl<<"student Record updated successfully "<<endl;
    cout<<endl<<endl<<endl;
}
}

void searchStudent(int id) {
    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            cout << "Found: ID: " << students[i].id<<endl;
            	cout << "__________________________________"<<endl<<endl;
            		cout<< "|   ID: " << students[i].id<<endl;
                 cout << "|   Name: " << students[i].name<<endl;
         cout << "|   N.o of corse taken : " << students[i].numGrades<<endl;
		cout << "|   GPA : "<< students[i].averageGPA << endl;
		cout << "|   year of addmission : "<<students[i].year<< endl;
		cout << "|   phone number : "<<students[i].phone<< endl;
		
		cout <<"|"<< "__________________________________"<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl;
		
            return;
        }
    }
    cout << "Student not found.";
    cout<<endl<<endl<<endl<<endl<<endl;
}

int main() {
    int choice;
    do {
    	
    cout<<"/=============/   Wellcom to st.mary university   /=============/"<<endl<<endl;
    
    	cout << "__________________________________"<<endl<<endl;
        cout <<"|"<< "1. Add Student Record"<<endl;
		 cout <<"|"<<"2. update student Record "<<endl;
	  cout <<"|"<<"3. Search Student"<<endl;
		cout <<"|"<<"4. Exit"<<endl;
		
		cout <<"|"<< "______________________________"<<endl;
    cout <<"|"<< "Enter choice: ";
    cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2){
        	{
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            update(id);
        }
		}
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            searchStudent(id);
        }
		    else if (choice == 4) {
            cout << "Exiting..."<<endl;
        } else {
            cout << "Invalid choice. Try again"<<endl;
            cout<<endl<<endl<<endl<<endl<<endl;
        }
    } while (choice != 4);

    return 0;
}
