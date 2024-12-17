/**
 *@file kvector.cpp
 *source code file of kvector header file
 */
#include<List.hpp>
#include<kvector.hpp> 
kvector::kvector()
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
this->allocationFlag=0;
}
//---------------------------------------------------------------
kvector::kvector(int bufferSize)
{
this->allocationFlag=0;
if(bufferSize<=0)
{
this->ptr=new int*[10];
this->ptr[0]=new int [10];
this->capacity=10;
this->size=0;
}
else
{
int rows;
int numberOfPointers;
rows=bufferSize/10;
if(bufferSize%10!=0)rows++;
numberOfPointers=(10+(rows%10))+rows;
this->ptr=new int *[numberOfPointers];
for(int e=0;e<rows;e++)
{
this->ptr[e]=new int[10];
}
this->capacity=rows*10;
this->size=0;
}
}
//-----------------------------------------------------------------
kvector::kvector(const kvector& other)
{
this->allocationFlag=0;
int bufferSize=other.size;
if(bufferSize<=0)
{
this->ptr=new int*[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
}
else
{
int rows;
int numberOfPointers;
rows=bufferSize/10;
if(rows%10!=0)rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new int*[numberOfPointers];
for(int e=0;e<rows;e++)
{
this->ptr[e]=new int[10];
}
this->capacity=rows*10;
this->size=0;
}
bool succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}
//----------------------------------------------------------------
kvector::~kvector()
{
if(allocationFlag==0)
{
int rows=this->capacity/10;
int j;
for(j=0;j<=rows;j++)
{
delete[]this->ptr[j];
}
delete []this->ptr;
}
}
//---------------------------------------
kvector& kvector::operator=(const kvector& other)
{
bool succ;
if(other.allocationFlag==0)
{
this->size=0;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}
else
{
int rows=this->capacity/10;
int j;
for(j=0;j<rows;j++)
{
delete [] this->ptr;
}
delete[] this->ptr;
this->ptr=other.ptr;
this->capacity=other.capacity;
this->size=other.size;
}
return *this;
}
//----------------------------------------------------------------------
void kvector::operator+=(const kvector& other)
{
bool succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}
//---------------------------------------------------------------------
kvector kvector::operator+(const kvector& other)
{
kvector k;
bool succ;
for(int e=0;e<this->size;e++)
{
k.add(this->get(e,&succ),&succ);
}
for(int e=0;e<other.size;e++)
{
k.add(other.get(e,&succ),&succ);
}
return k;
}
//---------------------------------------------
int & kvector::operator[](int index)
{
//if(index<=0 || index>=this->size)return 0;
int rowIndex=index/10;
int columnIndex=index%10;
return this->ptr[rowIndex][columnIndex];
}
//---------------------------------------
bool kvector::addRow()
{
if(capacity%100==0)
{
int numberOfPointers;
numberOfPointers=this->capacity/10;
int **tmp=new int *[numberOfPointers+10];
if(tmp==NULL)return false;
for(int e=0;e<numberOfPointers;e++)
{
tmp[e]=this->ptr[e];
}
delete []ptr;
this->ptr=tmp;
}
int i=this->capacity/10;
this->ptr[i]=new int [10];
if(this->ptr[i]==NULL)return false;
this->capacity=this->capacity+10;
return true;
}
//-----------------------------------------------
void kvector::add(int data,bool*success)
{
if(success)*success=false;
if(this->size==this->capacity)
{
if(!addRow())return;
}
int rowIndex,columnIndex;
rowIndex=this->size/10;
columnIndex=this->size%10;
this->ptr[rowIndex][columnIndex]=data;
this->size++;
if(success)*success=true;
}
//----------------------------------------------
int kvector::getSize()const
{
return this->size;
}
//-----------------------------------------
int  kvector::get(int index,bool *success)const
{
if(success)*success=false;
if(index<=0 || index>=this->size)return 0;
int rowIndex=index/10;
int columnIndex=index%10;
if(success)*success=true;
return this->ptr[rowIndex][columnIndex];
}
//------------------------------------------------------------
void kvector::insertAt(int index,int data,bool *success)
{
if(success)*success=false;
if(index<=0 || index>this->size)return ;
if(index==this->size)
{
this->add(data,success);
}
bool succ;
int k=this->get(this->size-1,&succ);
this->add(k,&succ);
if(succ==false)return;
int j;
j=this->size-3;
while(j>=index)
{
this->update(j+1,this->get(j,&succ),&succ);
j--;
}
this->update(index,data,&succ);
if(success)*success=true;
}
//---------------------------------------------------------
int kvector::removeAt(int index ,bool *success)
{
if(success)*success=false;
if(index<=0 || index>=this->size)return 0;
bool succ;
int j;
int ep=this->size-2;
j=index;
while(j<=ep)
{
this->update(j,this->get(j+1,&succ),&succ);
j++;
}
this->size--;
if(success)*success=true;
return 1;
}
//-------------------------------------------------------------
void kvector::update(int index,int data,bool *success)
{
if(success)*success=false;
if(index<=0 || index>=this->size)return ;
int rowIndex=index/10;
int columnIndex=index%10;
this->ptr[rowIndex][columnIndex]=data;
if(success)*success=true;
}
//---------------------------------------------------------------
void kvector::removeAll()
{
 this->size=0;
}
//----------------------------------------------------------------
void kvector::clear()
{
 this->size=0;
}

