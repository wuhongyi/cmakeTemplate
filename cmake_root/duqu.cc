//打开要读取的文件
//我们经常要读入诸如数据等文件

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
 ifstream myinput;   //生成一个ifstream目标模块（名字任意）……
 myinput.open("123.txt");   //打开一个已经存在的文件
 
 //检查上述操作是否正常
 if(myinput.fail())
 {
  cout<<"Sorry,could't open file"<<endl;
  exit(1);   //from cstdlib
 }
 
 
 //读入数据流
 //通过下面方式把数据从文件中读出：
//  float x,y,z;
//  for(int i=1;i<4;i++)
//  {
//   myinput>>x>>y>>z;
//   cout<<"Read "<<x<<" "<<y<<" "<<z<<endl;
//  }
 
 
 //另一种读入数据流的方式
 //通常情况下，我们不知道文件有多少行，此时，可以使用所谓的文件结尾（eof)函数：
 float x,y,z;
 int line=0;
 while(!myinput.eof())
 {
  myinput>>x>>y>>z;
  if(!myinput.eof())
  {
   line++;
   cout<<x<<" "<<y<<" "<<z<<endl;
  }
  cout<<line<<" lines read from file"<<endl;
 }
 
 
 
 myinput.close();   //close when finished
}  