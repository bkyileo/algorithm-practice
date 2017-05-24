#include<iostream>  
using namespace std;  
  
class A  
{  
public:  
    void foo()  
    {  
        printf("1\n");  
    }  
    virtual void fun()  
    {  
        printf("2\n");  
    }  
};  
class B : public A  
{  
public:  
    void foo()  
    {  
        printf("3\n");  
    }  
    void fun()  
    {  
        printf("4\n");  
    }  
};
  
int main(void)  
{  
    A a;  
    B b;
	 
    A *p = &a;  
    p->foo();  
    p->fun();  
    p = &b;  
    p->foo();  
    p->fun();
    
	/* 
    B *ptr = (B *)&a; //强制转换 给出子类的地址固定偏移量  
	ptr->foo();
	ptr->fun();
	*/ 
    return 0;  
}  
