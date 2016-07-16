//打开要写入的文件


#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
 //生成一个ofstream目标模块（名字任意）……
 ofstream myoutput;
 myoutput.open("456.txt");   //打开一个新文件
 
 //检查上述操作是否正常
 if(myoutput.fail())
 {
  cout<<"Sorry,couldn't open file"<<endl;
  exit(1);   //from cstdlib
 }
 
 
//把数据写入文件中
//此时的ofstream目标模块运作起来像cout一样：
 for(int i=1;i<=n;i++)
 {
  myoutput<<i<<"\t"<<i*i<<endl; 
 }
//还可以采用函数setf,precision,width,等等，控制输出格式。方法与cout使用一样
//myoutput.setf(ios::fixed);
//myoutput.precision(4);


}


//文件的输出模式
//前面的例子中，程序将更新已存在文件中的内容。如果要把数据接到文件的尾部，可以通过下列方式指定：
//myoutput.open("456.txt",ios::app);
//如果要把数据以二进制格式写到文件中，以达到减小文件大小的目的，可以采用：
//myoutput.open("456.txt",ios::bin);
//可以采用“|”来实现多个选项，例如：
//myoutput.open("456.txt",ios::bin|ios::app);
//表明将数据以二进制格式写到文件尾部。








