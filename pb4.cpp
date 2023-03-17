#include <iostream>
#include <stdlib.h>

using namespace std;

class Biblioteca
{
public:
    Biblioteca* sus, * jos, * urm;
    int val;
    Biblioteca() 
    {
        sus = jos = urm=new Biblioteca(-1) ;
    }
    Biblioteca(int x)
    {
        val = x;
    }

    void afis()
    {
        Biblioteca* crt = sus->urm;
        if (!crt)
            return;
        while (crt!= nullptr)
        {
            
            cout << crt->val << " ";
            crt = crt->urm;
     
        }
        cout << endl;
    }
    
    void pop()
    {
        sus = sus->urm;
    }
    ~Biblioteca()
    {
        if (sus)
            delete sus;
    }
};

class B_copii :public Biblioteca {
public:
    B_copii() { val = 0; }
    B_copii(int d)
    {
        val = d;
    }
    int add_sf(int d)
    {
        //val = d;
        if (jos == nullptr)
            jos = new Biblioteca(d);
        if ((jos->urm = new Biblioteca(d)))
        {
            jos = jos->urm;
            return 0; //operatie terminate cu succes
        }
        else
            return 1;
    }

    void afis1()
    {
        afis();
    }
};







class B_veche :public Biblioteca {
public:
    //B_veche(){};
    B_veche()
    {
    }
    int add_inc(int d)
    {
        Biblioteca* tmp = new Biblioteca(d);
        if (!tmp)
            return 1; 	// eroare alocare memorie
        if (jos == nullptr)
        {
            sus->urm = tmp;
            jos = tmp;
        }
        else
        {
            tmp->urm = sus->urm;
            sus->urm = tmp;
        }
        return 0;
    }
    void afis2()
    {
        afis();
    }
};
int main()
{
    B_copii ob1;
    B_veche ob2;
    int x;

    while (cin >> x)
    {
        if (x < 9999)
        { 
            ob1.add_sf(x);
            ob2.add_inc(x);
            
           
        }
        else
        { 
            ob2.pop();
            ob1.pop();
           
        }
    }
    ob2.afis2();
    ob1.afis1();
   

    return 0;
}