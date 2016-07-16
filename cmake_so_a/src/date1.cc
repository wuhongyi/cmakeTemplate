#include <iostream>
#include "date1.hh"
using namespace std;

Date::Date(int y,int m,int d)
{
  year=y;
  month=m;
  day=d;
}

int Date::GetYear()
{
  return year;
}

int Date::GetMonth()
{
  return month;
}

int Date::GetDay()
{
  return day;
}

void Date::Display()
{
  cout<<year<<"-"<<month<<"-"<<day<<endl;
}

Date::~Date()
{
  cout<<"Destructor called"<<endl;
  
}