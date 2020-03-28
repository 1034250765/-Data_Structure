#include<iostream>
#define Max  100
using namespace std;
typedef int Elemtype;
typedef struct List
{
    Elemtype elem[Max];
    int last;
}List;

void Set_List(List *H)      //初始化顺序表
{
    H -> last = -1;
}

int Empaty(List *H)         //判断是否为空
{
    if(H -> last == -1)
    return 1;
    else 
    return 0;
}

int Length(List *H)         //计算线性表的长度
{
    return H -> last + 1; 
}

int CreatList(List *H, Elemtype a[], int n) //将数组元素存入线性表中
{   
    int i;
    if(n > Max)                          
    {
        cout<<"顺序表空间不足，无法创建" <<  endl;
        return 0;
    }
    for( i = 0; i<n; i++)
        H ->elem[i] = a[i];
    H -> last = i - 1;
    return 1;
}

int FindElem(List *H, int i)      //按序号查找指定元素并输出
{
    if(i < 1 || i > H -> last+1)
    {
        cout <<"查找失败\n";
        return 0;
    }
    else
    {
        cout <<"顺序表第"<< i <<"个元素为" << H->elem[i-1];
        return 1;
    }
    
}

int main()                         
{   
    List *H;
    int n;
    cout <<"请输入顺序表的长度"<<endl;
    cin >> n;
    Set_List(H);
    cout <<"顺序表已创建" <<endl;
    if(Empaty(H))
        cout <<"顺序表为空" <<endl;
    int array[10000];
    cout <<"请输入顺序表的元素:"<<endl; 
    for(int i; i<n;i++)
    {
        cin >> array[i];
    }
    CreatList(H, array, n );
    int L = Length(H);
    cout <<"顺序表的长度为:"<< L <<endl;
    cout <<"请输入要查找元素的序号:" <<endl;
    int serial;
    cin >> serial;
    FindElem(H, serial);
    return 0;
}



