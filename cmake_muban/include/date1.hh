#include <iostream>
using namespace std;

class Date
{
 private:
  int year;
  int month;
  int day;
 public:
  Date(int y=2013,int m=9,int d=29);
  void Display();
  int GetYear();
  int GetMonth();
  int GetDay();  
  ~Date();
};