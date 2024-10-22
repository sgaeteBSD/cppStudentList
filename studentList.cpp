#include <iostream>
#include <vector>

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
void quitter(vector<Student*> &stu);

int main()
{
  Student george;
  vector<Student*> stu;
  cin >> george.first;
  george.id = 123;
  george.gpa = 4.23;
  Student* ptr = &george;
  stu.push_back(ptr);
  cout << stu[0]->first << stu[0]->id << stu[0]->gpa << endl;
  adder(stu);
  
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
