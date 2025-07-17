#include <iostream>
#include <string>
using namespace std;
class Doctor
 {
public:
    string name, specialization;
    int slots;
    Doctor(string n, string s, int sl) 
	{
        name=n;
        specialization=s;
        slots=sl;
    }
    void show(int i)
	 {
        cout<< i + 1 <<". Dr. " <<name <<" - " <<specialization <<" - Slots: "<<slots <<endl;
    }
};
class Patient
 {
    string name, problem;
    int age;
public:
    void getInfo() 
	{
        cout<<"Enter Patient Name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Age: ";
        cin>>age;
        cout<<"Enter Problem (fever, cough, child, women, brain): ";
        cin.ignore();
        getline(cin, problem);
    }
    string getProblem() 
	{
	 return problem;
	  }
    void suggest()
	 {
        if (problem == "fever")
            cout << "Take Panadol and rest.\n";
        else if (problem == "cough")
            cout << "Avoid cold items. Try warm drinks.\n";
        else if (problem == "child")
            cout << "Visit a child specialist.\n";
        else if (problem == "women")
            cout << "Consult a gynecologist soon.\n";
        else if (problem == "brain")
            cout << "Consult a neurologist.\n";
        else
            cout << "General advice: take care and see a doctor.\n";
    }
};
int main() {
    cout << "============================\n";
    cout << "  WELCOME TO HEALTHCARE+ HOSPITAL\n";
    cout << "============================\n";
    Patient p;
    p.getInfo();
    p.suggest();
    string book;
    cout << "Do you want to book a doctor? (yes/no): ";
    cin >> book;
    if (book == "yes") {
        Doctor d[4] = {
            Doctor("Hassan Raza", "Child Specialist", 2),
            Doctor("Sana Malik", "Gynecologist", 1),
            Doctor("Junaid Ali", "General Doctor", 3),
            Doctor("Naila Khan", "Neurologist", 0)
        };

        cout << "\nAvailable Doctors:\n";
        for (int i = 0; i < 4; i++)
            d[i].show(i);

        int choice;
        cout << "Enter doctor number to book: ";
        cin >> choice;

        if (choice < 1 || choice > 4)
            cout << "Invalid selection.\n";
        else if (d[choice - 1].slots > 0) {
            cout<< "Appointment booked with Dr. " << d[choice - 1].name << ".\n";
            cout<< "Day: Monday\nDate: 1 July 2025\nTime: 11:00 AM\n";
        } 
		else
		 {
            cout<< "No slots available for Dr. " << d[choice - 1].name << ". Try another doctor.\n";
        }
    } 
	else 
	{
        cout<< "Okay. Stay healthy.\n";
    }
    return 0;
}
