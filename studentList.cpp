/*
 * C++ Student List
 * ADD and DELETE students to your Student List.
 * Program will keep track of student names, ID, and GPA.
 * 10/22/2024
 * Santiago Gaete
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student { //create student struct
  char first[20];
  char last[20];
  int id;
  float gpa;
};

//all functions pass the vector of Student pointers by reference
void adder(vector<Student*> &stu);
void printer(vector<Student*> &stu);
void deleter(vector<Student*> &stu);
void quitter(vector<Student*> &stu, bool &input);

int main()
{
  vector<Student*> stu; //create vector of Student pointers
  bool input = true; //while loop condition
  while (input == true) {
    
    cout << "Input a command." << endl;
    char command[6] = "";

    cin >> command; //read input
    cin.ignore();
    
    if (strcmp(command, "ADD") == 0) {
      adder(stu);
      input = true; //run command loop again
    }
    else if (strcmp(command, "PRINT") == 0) {
      printer(stu);
      input = true;
    }
    else if (strcmp(command, "DELETE") == 0) {
      deleter(stu);
      input = true;
    }
    else if (strcmp(command, "QUIT") == 0) {
      quitter(stu, input);
    }
    else { //if command isn't 1 of the 4
      cout << "Invalid input! Try again." << endl;
    }
  }
}

void adder(vector<Student*> &stu) {
  Student* newStu = new Student; //add new student

  //prompt input
  cout << "First name?" << endl;
  cin >> newStu->first;
  cout << "Last name?" << endl;
  cin >> newStu->last;
  cout << "ID Number?" << endl;
  cin >> newStu->id;
  cout << "Grade Point Average?" << endl;
  cin >> newStu->gpa;

  stu.push_back(newStu); //add to vector
  cout << newStu->first << " has been added." << endl;
}

void printer(vector<Student*> &stu) {
  for (auto it = stu.begin(); it != stu.end(); ++it) { //use iterator to print each
    cout << (*it)->first << " " << (*it)->last << ", " << (*it)->id << ", " <<
      fixed << setprecision(2) << (*it)->gpa << endl; //make sure to round gpa float
  }
}

void deleter(vector<Student*> &stu) {
    int deleteID;
    cout << "Enter the ID of the student to be deleted: ";
    cin >> deleteID; //store id to be deleted
    //different iterator for fun
    vector<Student*>::iterator first = stu.begin();
    vector<Student*>::iterator last = stu.end();
    while (first != last) { //go through whole list
      if (deleteID == (*first)->id) { //if we reach the student to be deleted
	cout << "Deleting student " << (*first)->first << "..." << endl;
	delete *first; //delete the data in memory
	stu.erase(first); //erase the pointer to that memory
      }
      first++; //continue
    }
}

void quitter(vector<Student*> &stu, bool &input) {
  cout << "Goodbye!" << endl;
  input = false; //end loop (passed by reference)
}
