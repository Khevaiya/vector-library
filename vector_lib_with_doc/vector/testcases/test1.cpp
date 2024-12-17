//for windows
//g++ -c *.cpp -I..\include 
//ar rcs  ..\lib\kvector.lib  *.o 
//g++ test1.cpp -o test1.exe -I..\include -L ..\lib -l kvector
/*iostream me bhi bool he too define kiya tha as an macros to error double redefination of header file  issiliye hta diya #define bool int */

//for ubuntu
// to make o file= g++ -Wall -Werror -I ../include kvector.cpp
//to make library file =ar rcs ../lib/libkg.a  *.o
//// to compile on ubuntu ++ test1.cpp -L../lib -lkg -I../include -o test1.out
#include<kvector.hpp>
#include<iostream>
int main()
{
//-----add() & get() & parameterized constructor()-----------
cout<<" parameterized constructor & add() & get()"<<endl;
kvector k(20);
bool succ;
for(int e=0;e<=10;e++)
{
k.add(e,&succ);
}
for(int e=0;e<=10;e++)
{
cout<<k.get(e,&succ)<<endl;
}
//-----------------------------insertA()-------------
cout<<"insertAt()"<<endl;
bool success;
cout<<"size of kvector= "<<k.getSize()<<endl;
k.insertAt(10,20,&success);
for(int e=0;e<=11;e++)
{
cout<<k.get(e,&success)<<endl;
}
cout<<"size of kvector: "<<k.getSize()<<endl;
//-----------------------------removeAt()----------------
cout<<"removeAt"<<endl;
k.removeAt(10,&success);
for(int e=0;e<=10;e++)
{
cout<<k.get(e,&success)<<endl;
}
cout<<"size of kvector: "<<k.getSize()<<endl;
//-----------------------------update()-------------------
cout<<"update()"<<endl;
k.update(10,100,&succ);
for(int e=0;e<=10;e++)
{
cout<<k.get(e,&success)<<endl;
}
cout<<"size of kvector: "<<k.getSize()<<endl;
//------------------------------operator+ & operator=  -----------
cout<<" operator + and ="<<endl;
kvector i,j;
i=j+k;
for(int e=0;e<=10;e++)
{
cout<<i.get(e,&success)<<endl;
}
cout<<"size of kvector: "<<k.getSize()<<endl;
//-------------------------------operator+=--------------------
cout<<"operaor+="<<endl;
kvector l;
l+=i;
for(int e=0;e<=10;e++)
{
cout<<l.get(e,&success)<<endl;
}
//-------------------------------copy constructor----------------
cout<<"copy constructor "<<endl;
kvector m(l);
for(int e=0;e<=10;e++)
{
cout<<m.get(e,&success)<<endl;
}
//--------------------operator[]---------------
cout<<"operator[]"<<endl;
m[0]=1000;
for(int e=0;e<=10;e++)
{
cout<<m[e]<<endl;
}
//--------------------------removeAll()--------
cout<<"removeAll() or clear() against m object"<<endl;
m.removeAll();
m.clear();
cout<<m.getSize()<<endl;
for(int e=0;e<=m.getSize();e++)
{
cout<<m[e]<<endl;
}
//------------too test randomly----------
kvector x;
for(int e=0;e<=100;e++)
{
x.add(e,&succ);
}
cout<<"-----------------------------"<<endl;
for(int e=0;e<x.getSize();e++)
{
cout<<x.get(e,&succ)<<endl;
}

return 0;
}
