#include <iostream>
#include <deque>
#include <iomanip>
using namespace std;

class semnal{
public:
    deque <double>s;
    int tip, P;
    semnal(deque<double>s1,int tip1,int P1)
    {
        s = s1;
        tip = tip1;
        P = P1;
    }
    virtual void afis(deque<double>s1) = 0;
};
class dsp1 :virtual public semnal {
public:
    int dim;
    dsp1(deque<double>s1, int tip1, int P1) :semnal(s1, tip1, P1) { dim = s.size(); }

    void afis(deque<double>s1)
    {
        deque <double> ::iterator it;
        for (it = s1.begin(); it != s1.end(); ++it)
            cout <<fixed<<setprecision(2)<<*it<<" ";
        cout <<endl;
    }

    int treceri_0()
    {
        int c = 0;
        for (int i = 0; i < dim-1; i++)
            if (s.at(i) * s.at(i + 1) <= 0)
                c++;
           
        return c;
    }

    void medie(bool ok)
    {
        double m = 0;
        deque<double> cop;
        cop = s;
        for (int i = 9; i < dim; i+=10)
        {
            m = 0;
            for (int j = i-9; j < i ; j++)
                m += s.at(j);
            s.at(i) = m / 9;
           
        } 
        if(ok==false)
        afis(s);
        
    }

    void semnal_praguit()
    {
        bool ok = true;
        medie(ok);
        
        for (int i = 0; i < dim; i++)
            if (s.at(i) < 15)
                s.at(i) = 0;
            else
                s.at(i) = 1;
        deque <double> ::iterator it;
        for (it = s.begin(); it != s.end(); ++it)
            cout <<setprecision(0)<< *it << " ";
        cout << endl;
    }

    void sub_esantion()
    {  
        for (int i = 0; i < dim; i +=5)
            cout <<setprecision(0)<< s.at(i)<<" ";
    }
    void afisare()
    {
        afis(s);
    }
};

class dsp2 :virtual public semnal {
public:
    int d;
    dsp2(deque<double> s1, int tip1, int P1) :semnal(s1, tip1, P1) { d = s.size(); }
    void afis(deque<double>s1)
    {
        deque <double> ::iterator it;
        for (it = s1.begin(); it != s1.end(); ++it)
            cout << fixed<<setprecision(2) << *it << " ";
        cout << endl;
    }
    void maxime(double prag)
    {
        deque<double>copie,nou;
        copie = s;
        int contor = 0, mari = 0,mici=0;
        if (s.at(0) > s.at(1))
        {
            contor = 1;
            if (s.at(0) > prag)
                mari++;
            else
                if (s.at(0) < prag)
                    s.at(0) = s.at(1)/2;
        }
        for (int i = 1; i < d - 1; i++)
            if (s.at(i) > s.at(i - 1) && s.at(i) > s.at(i + 1))
            {
                contor++;
                if (s.at(i)> prag)
                    mari++;
                else
                    if (s.at(i) < prag)
                        s.at(i) =( s.at(i-1)+s.at(i+1) )/2;
            }
    
        if (s.at(d - 1) > s.at(d - 2))
        {
            contor++;
            if (s.at(d - 1) > prag)
                mari++;
            else
                if (s.at(d - 1) < prag)
                    s.at(d - 1) = s.at(d - 2);
        }

        cout<<contor<<endl<<mari<<endl;
        afis(s);
        int k = 0;
        for (int i = 0; i < 5; i++)
            cout << 0.00<<" ";
        for (int i = 0; i < d; i++)
            cout << s.at(i) << " ";
        for (int i = 0; i < 5; i++)
            cout << 0.00 << " ";
        //afis(nou);
    }
};

int main()
{
    double nr, tip, prag;
    bool ok = false;
    deque<double> lst,copie;
    cin >> tip >> prag;
    while (cin >> nr)
    {
        lst.push_back(nr);
    }
    copie = lst;
    dsp1 ob1(lst,tip,prag);
    dsp2 ob2(lst,tip,prag);
  
    if (tip == 1)
    {
        cout << ob1.treceri_0() << endl;
        ob1.medie(ok);
        ob1.semnal_praguit();
        ob1.sub_esantion();
    }
    else
    {
        ob2.maxime(prag);
    }
}
