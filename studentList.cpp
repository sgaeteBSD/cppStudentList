#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student {
  char first[10];
  char last[10];
  int id;
  float gpa;
};

void adder(vector<Student*> &stu);
void printer(vector<Student*> &stu);
void deleter(vector<Student*> &stu);
void quitter(vector<Student*> &stu, bool &input);

int main()
{
  /*Student george;
  vector<Student*> stu;
  cin >> george.first;
  george.id = 123;
  george.gpa = 4.23;
  Student* ptr = &george;
  stu.push_back(ptr);
  cout << stu[0]->first << stu[0]->id << stu[0]->gpa << endl;
  adder(stu);*/

  vector<Student*> stu;
  bool input = true;
  while (input == true) {
    
    cout << "Input a command." << endl;
    char command[6] = "";

    cin >> command; 
    cin.ignore();
    if (strcmp(command, "ADD") == 0) {
      adder(stu);
    }
    else if (strcmp(command, "PRINT") == 0) {
      printer(stu);
    }
    else if (strcmp(command, "DELETE") == 0) {
      deleter(stu);
    }
    else if (strcmp(command, "QUIT") == 0) {
      quitter(stu, input);
    }
    else {
      cout << "Invalid input! Try again." << endl;
    }
  }
}

void adder(vector<Student*> &stu) {
  Student* newStu = new Student;

  cout << "First name?" << endl;
  cin >> newStu->first;
  cout << "Last name?" << endl;
  cin >> newStu->last;
  cout << "ID Number?" << endl;
  cin >> newStu->id;
  cout << "Grade Point Average?" << endl;
  cin >> newStu->gpa;

  stu.push_back(newStu);
  cout << newStu->first << " has been added." << endl;
}

void printer(vector<Student*> &stu) {
  for (auto it = stu.begin(); it != stu.end(); ++it) {
    cout << (*it)->first << " " << (*it)->last << ", " << (*it)->id << ", " <<
      fixed << setprecision(2) << (*it)->gpa << endl;
  }
}

void deleter(vector<Student*> &stu) {
    int deleteID;
    cout << "Enter the ID of the student to be deleted: ";
    cin >> deleteID;

    for (auto it = stu.begin(); it != stu.end();) {
        if (deleteID == (*it)->id) {
            cout << "Deleting student..." << endl;
            stu.erase(it);
        } else {
            ++it; // Move to the next student only if not deleted
        }
    }
}

void quitter(vector<Student*> &stu, bool &input) {
  cout << "Goodbye!" << endl;
  input = false;
}
