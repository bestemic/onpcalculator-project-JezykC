#include "stack.hpp"

std::stack<double> stos;

int Operation(string slowo)
{
    char* p;
    double zmienna = strtod(slowo.c_str(), &p);
    if(*p)
    {
        if(slowo == "add")
        {
            return add();
        }
        else if(slowo == "sub")
        {
            return sub();
        }
        else if(slowo == "mul")
        {
            return mul();
        }
        else if(slowo == "div")
        {
            return divide();
        }
        else if(slowo == "pow")
        {
            return power();
        }
        else if(slowo == "neg")
        {
            return neg();
        }
        else if(slowo == "abs")
        {
            return absolut();
        }
        else if(slowo == "sin")
        {
            return sinus();
        }
        else if(slowo == "cos")
        {
            return cosinus();
        }
        else if(slowo == "log")
        {
            return logarytm();
        }
        else if(slowo == "exp")
        {
            return exponenta();
        }
        else if(slowo == "?" || slowo == "h" || slowo == "help")
        {
            cout<<"Operacje arytmetyczne:"<<endl;
            cout<<"add, sub, mul, div, pow, neg, abs, sin, cos, log, exp"<<endl;
            cout<<"Inne:"<<endl;
            cout<<"?, h, help, q, quit, =, pstack"<<endl;
            return 0;
        }
        else if(slowo == "q" || slowo == "quit")
        {
            if(StackSize()==0)
            {
                cout<<"Stos jest pusty nie mozna wypisac"<<endl;
                exit(0);
            }
            else
            {
                StackPeek(StackSize());
                exit(0);
            } 
        }
        else if(slowo == "=")
        {
            if(StackSize()==0)
            {
                cout<<"Stos jest pusty"<<endl;
                return -1;
            }
            else
            {
                StackPeek(0);
                return 0;
            }  
        }
        else if(slowo == "pstack")
        {
            if(StackSize()==0)
            {
                cout<<"Stos jest pusty"<<endl;
                return -1;
            }
            else
            {
                StackPeek(StackSize());
                return 0;
            }   
        }
        else
        {
            if(StackSize()>0) StackPeek(StackSize());
            cout<<"Niewlasciwy operator"<<endl;
            return -1;
        }  
    }
    else 
    {
        StackPush(zmienna);
        return 0;
    }
        
}

void StackPush(double x)
{
    stos.push(x);
}

int StackSize()
{
    return stos.size();
}

double StackPop()
{
    double liczba = stos.top();
    stos.pop();
    return liczba;
}

void StackPeek(int n)
{
    stack<double> pom;
    double pom1;
    if(n==0)
    {
        cout<<stos.top()<<endl;
    }
    else
    { 
        for(int i=0; i<n; i++)
        {
            pom1 = StackPop();
            pom.push(pom1);
        }
        while(!pom.empty())
        {
            pom1 = pom.top();
            cout<<pom1<<" ";
            StackPush(pom1);
            pom.pop();
        }
        cout<<endl;
    }
}

int add()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(b+a);
        return 0;
    }
    
}

int sub()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(b-a);
        return 0;
    }
    
}

int mul()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(b*a);
        return 0;
    }
    
}

int divide()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        if(a==0)
        {
            StackPush(a);
            StackPeek(StackSize());
            cout<<"Nie mozna dzielic przez 0"<<endl;
            return -1;
        }
        else
        {
            b = StackPop();
            StackPush(b/a);
            return 0;
        }
    }
    
}

int power()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(pow(b, a));
        return 0;
    }
}

int neg()
{
    double a; 
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(a*(-1));
        return 0;
    }
    
}

int absolut()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(fabs(a));
        return 0;
    }  
}

int sinus()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(sin(a));
        return 0;
    }  
}

int cosinus()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(cos(a));
        return 0;
    }  
}

int logarytm()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        if(a<=0)
        {
            StackPush(a);
            StackPeek(StackSize());
            cout<<"Nie mozna obliczyc logarytmu z liczy niedodatniej"<<endl;
            return -1;
        }
        else
        {
            StackPush(log(a));
            return 0;
        }       
    }  
}

int exponenta()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(exp(a));
        return 0;
    }  
}