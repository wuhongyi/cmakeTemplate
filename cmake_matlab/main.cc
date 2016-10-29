// example.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 二 2月 25 19:03:12 2014 (+0800)
// Last-Updated: 五 8月 15 08:53:46 2014 (-0400)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 31
// URL: http://wuhongyi.cn 

#include <iostream>
#include <cmath>
#include <engine.h>

#include <QtGui/QApplication>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
  // Test 1：将C++中的数据送入Matlab执行
  // [1] 启动Matlab引擎
  Engine *ep = engOpen(NULL);
  if (!ep)
    {   // 定义Matlab引擎指针，启动引擎；失败则返回NULL
      cout << "Can’t start Matlab engine!";
      exit(-1);
    }
  engSetVisible(ep, false);

  // [2] 在C++内存空间构造需要计算或者画图的数据
  const int N_SIZE = 10;
  double x[N_SIZE],y[N_SIZE];
  for (int i=0; i<N_SIZE; i++) //计算数组x和y
    {
      x[i] = (i+1);
      y[i] = sin(x[i]); //产生正弦值
    }

  // [3] 在C++内存空间定义Matlab数组
  mxArray *xx = mxCreateDoubleMatrix(1,N_SIZE, mxREAL); // 定义mxArray，为行，N_SIZE 列的实数数组
  mxArray *yy = mxCreateDoubleMatrix(1,N_SIZE, mxREAL);
  // [4] 将数据拷贝到数组中
  memcpy(mxGetPr(xx), x, N_SIZE*sizeof(double)); // 将数组x复制到mxarray数组xx中
  memcpy(mxGetPr(yy), y, N_SIZE*sizeof(double));
  // [5] 将C++内存空间的数据传输到Matlab引擎中
  engPutVariable(ep, "xx",xx);  // 将mxArray数组xx写入到Matlab工作空间，命名为xx
  engPutVariable(ep, "yy",yy);
  // [6] 执行Matlab引擎
  //engEvalString(ep, "plot(xx, yy); "); // 向Matlab引擎发送画图命令
  engEvalString(ep, "xx=xx+yy;yy=yy+xx; "); 

  // [7] 销毁C++内存空间的数据
  mxDestroyArray(xx);    // 销毁mxArray数组xx和yy
  mxDestroyArray(yy);

  // Test 3：从Matlab引擎传回数据
  mxArray *_xx = engGetVariable(ep, "xx");
  double *_x = mxGetPr(_xx);
  mxArray *_yy = engGetVariable(ep, "yy");
  double *_y = mxGetPr(_yy);
  for (int i = 0; i < N_SIZE; i++)
    {
      cout << "i=" <<  i << "|" << _x[i] <<" "<< _y[i]<<endl;
    }
  // 销毁mxArray数组_xx和_yy
  mxDestroyArray(_xx);
  mxDestroyArray(_yy);

  engClose(ep); //关闭Matlab引擎

  cout<<"!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  return 0;
}


// 
// example.cc ends here
