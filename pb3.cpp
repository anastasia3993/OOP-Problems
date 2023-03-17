#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class poligon {
public:   
    double l, L, cost_precizie, cost_culoare, grosime;
    bool colorat = false;
    string tip;
    poligon()
    {
        l = L = cost_precizie = cost_culoare = grosime = 0;
    }
    virtual void get(double g, double c_p, double c_c, bool c, string t, double l1, double l2)
    {
        grosime = g;
        cost_precizie = c_p;
        cost_culoare = c_c;
        colorat = c;
        tip = t;
        l = l1;
        L = l2;
    }
    virtual double perimetru()
    {
        return (2 * l + 2 * L);
    }
    virtual double arie()
    {
        return (l* L);
    }
};


class cerc :public poligon {
    double P, A,raza,pi;
public:
    cerc()
    {
        P = 0;
        A = 0;
        raza = 0;
        pi = 2 * acos(0.0);
    }    
    void get(double g, double c_p, double c_c, bool c, string t, double l1, double l2) override
    {
        grosime = g;
        cost_precizie = c_p;
        cost_culoare = c_c;
        colorat = c;
        tip = t;
        l = l1;
        L = l2;
        raza = l1;
    }
  
    double perimetru() override
    {
        P = 2 * pi * raza;
        return P;
    }
    double arie() override
    {
        A =  pi * raza*raza;
        return A;
    }
};

class triunghi :public cerc
{
public:
    double baza,h;
    triunghi()
    {
        baza=h = 0;
    }
    void get(double g, double c_p, double c_c, bool c, string t, double l1, double l2) override
    {
        grosime = g;
        cost_precizie = c_p;
        cost_culoare = c_c;
        colorat = c;
        tip = t;
        l= l1;
        L= l2;
        baza = l1;
        h = L=l2;
    }

    double perimetru()override
    {
        return baza * 3;
    }

    double arie()override
    {
        return (baza * h)/2;
    }
};

class robot :public triunghi {
public:
    double cost1,cost2,aux,bux;
    robot()
    {
        cost1 = 0;
        cost2 = 0;
        aux = 0;
        bux = 0;
    }
    void get(double g, double c_p, double c_c, bool c, string t, double l1, double l2) override
    {
        grosime = g;
        cost_precizie = c_p;
        cost_culoare = c_c;
        colorat = c;
        tip = t;
        l = l1;
        L = l2;
    }
    double calcul()
    {
        if (colorat == false && tip=="PATRAT")
        {
            aux = poligon::perimetru();
            cost1 = grosime * aux * cost_precizie;
        }
        else
            if (colorat == false && tip == "DREPTUNGHI")
            {
                aux = poligon::perimetru();
                cost1 = grosime * aux * cost_precizie;
            }
            else
                if (colorat == false && tip == "TRIUNGHI")
                {
                    aux = triunghi::perimetru();
                    cost1 = grosime * aux * cost_precizie;
                }
             else
                    if (colorat == false && tip == "CERC")
                    {
                        double pi = 2 * acos(0.0);
                        aux = 2 * pi * l;
                        cost1 = grosime * aux * cost_precizie;
                    }
      

            if (colorat == true && tip == "PATRAT")
            {
                aux = poligon::arie();
                bux = poligon::perimetru();
                cost1 = grosime * bux * cost_precizie;
                cost2 = aux * cost_culoare;
            }
            else
                if (colorat == true && tip == "DREPTUNGHI")
                {
                    aux = poligon::arie();
                    bux = poligon::perimetru();
                    cost1 = grosime * bux * cost_precizie;
                    cost2 = aux * cost_culoare;
                }
                else
                if (colorat == true && tip == "TRIUNGHI")
                {
                    aux = triunghi::arie();
                    bux = triunghi::perimetru();
                    cost1 = grosime * bux * cost_precizie;
                    cost2 = aux * cost_culoare;
                }
                else
                    if (colorat == true && tip == "CERC")
                    {
                        double pi = 2 * acos(0.0);
                        aux =  pi * l*l;
                        bux = 2*pi*l;
                        cost1 = grosime * bux * cost_precizie;
                        cost2 = aux * cost_culoare;
                    }
            if (colorat == false)
                return cost1;
            else
                return (cost1 + cost2);

    }
    void afis()
    {
        cout << grosime << " " << cost_precizie << " " << cost_culoare << " " << colorat << " " << tip << " " << l << " " << L << endl;
    }
};
int main()
{
    double cost[4], n, gros, precizie, precizie2, latura1, latura2;
    vector<double>v;
    string cul, form;
    bool ok = false;
    cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];
    cin >> n;
    robot ob;
    poligon* p;
    for (int i = 0; i < n; i++)
    {
        cin >> gros >> precizie >> cul >> form>>latura1;
        if (precizie== 1)
            precizie = cost[0];
        else
            if ( precizie == 2)
                precizie= cost[1];
            else
                if (precizie== 3)
                    precizie = cost[2];
                
                    if (cul == "COLORATA")
                    {
                        precizie2 = cost[3];
                    }
        if (cul == "GOALA")
            ok = false;
        else
            ok = true;
        
        if (form == "TRIUNGHI" || form == "DREPTUNGHI")
        {
            cin >> latura2;
            if(cul=="GOALA")
            ob.get(gros, precizie,0, ok, form, latura1, latura2);
            else
            ob.get(gros,precizie, precizie2, ok, form, latura1, latura2);
        }
        else
            if (form == "PATRAT")
            {
                latura2 = latura1;
                if (cul == "GOALA")
                    ob.get(gros, precizie, 0, ok, form, latura1, latura2);
                else
                    ob.get(gros, precizie,precizie2, ok, form, latura1, latura2);
            }
            else
                if (form == "CERC")
                {
                    latura2 = 0;
                    if (cul == "GOALA")
                        ob.get(gros, precizie, 0, ok, form, latura1, latura2);
                    else
                        ob.get(gros,precizie,precizie2, ok, form, latura1, latura2);
                }
       // ob.afis(); 
        p = &ob;
        //cout <<fixed<<setprecision(2)<< ob.calcul() << endl;
        v.push_back( ob.calcul());
    }
    
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
        cout << fixed << setprecision(2)<<v[i] << " ";
    
}


