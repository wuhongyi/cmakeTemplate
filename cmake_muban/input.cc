#include "date1.hh"
#include "Circle.hh"
#include "iostream"
using namespace std;

int main()
{
  Date *oneDay;
  Date *today=new Date(2013,9,29);
  
  oneDay=new Date(2000);
  cout<<"One day is:";
  oneDay->Display();
  
  cout<<"Today is:";
  today->Display();
  
  delete oneDay;
  delete today;
  Circle c(3);
  cout<<"Area="<<c.Area()<<endl;
  
  return 0;
  
}
