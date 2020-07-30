
#include <iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class seat{};
class hour{};
class miniute{};
class identify{};

class aeroplane
{
public:
    int seating_cap;
    int ah,am,dh,dm;
    int aero_id;
    float max_wt;
    int franchise;

    virtual void details(int)=0;
    virtual int enter_details()=0;
};


class customer
{
public:
    string name;
    int cust_id;
    string dest;
    float cargo_wt;

    void enter_cust_details()
    {
        cout<<"\nenter customer details";
        cout<<"\nenter name:";cin>>name;
        cout<<"enter cust_id:";cin>>cust_id;
        cout<<"enter dest:";cin>>dest;
        cout<<"enter cargo_wt:";cin>>cargo_wt;
        cout<<endl;
    }

    void pas_details()
    {
        cout<<"name:"<<name<<endl;
        cout<<"cust_id:"<<cust_id<<endl;
        cout<<"dest:"<<dest<<endl;
        cout<<"cargo_wt:"<<cargo_wt<<endl<<endl;
    }
};


class domestic:public aeroplane
{
public:
    int n;
    string distination;
    int price;
    customer c[100];

    int enter_details()
    {
        franchise=1;
        cout<<"\nenter aero id:";cin>>aero_id;
        cout<<"enter sitting capacity:";cin>>seating_cap;
        cout<<"enter max_wt:";cin>>max_wt;
        cout<<"enter arrival time:";cin>>ah;
            if(ah>24)
        {
            throw hour();
        }
        cout<<":";
        cin>>am;
            if(am>60)
        {
            throw miniute();
        }
        cout<<"enter departure time:";cin>>dh;
            if(dh>24)
        {
            throw hour();
        }
        cout<<":";
        cin>>dm;
            if((ah>dh) || (ah==dh&&am>dm))
            {
                cout<<"\nFlight can't depart without arriving\n";
                exit(0);
            }
            if(dm>60)
        {
            throw miniute();
        }

        cout<<"enter ticket cost:";cin>>price;

        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\nenter no of passengers in this plane:";cin>>n;
        if(n>seating_cap)
           {
                    throw seat();
           }
        else
            for(int i=0;i<n;i++)
        {
            c[i].enter_cust_details();
        }
        return n;
    }

    void details(int n)
    {
        cout<<"------------------------------------------------";
        cout<<"\n\naero id is:"<<aero_id;
        cout<<"\nsitting capacity is:"<<seating_cap;
        cout<<"\nmax_wt is:"<<max_wt;

        cout<<"\narrival time is:"<<ah<<":"<<am;

        cout<<"\ndestination time is:"<<dh<<":"<<dm;
        cout<<"\nticket cost is:"<<price;

        cout<<"\n\ncustomer details  of this plane is:\n";
            for(int i=0;i<n;i++)
        {
            c[i].pas_details();
        }
    }



};


class international:public aeroplane
{
public:
    int n;
    string distination;
    int price;
    customer c[100];

    int enter_details()
    {
        franchise=2;
        cout<<"\nenter aero id:";cin>>aero_id;
        cout<<"enter sitting capacity :";cin>>seating_cap;
        cout<<"enter max_wt:";cin>>max_wt;
        cout<<"enter arrival time";cin>>ah;
            if(ah>24)
        {
            throw hour();
        }
        cout<<":";
        cin>>am;
            if(am>60)
        {
            throw miniute();
        }
        cout<<"enter departure time";cin>>dh;
            if(dh>24)
        {
            throw hour();
        }
        cout<<":";
        cin>>dm;
            if((ah>dh) || (ah==dh&&am>dm))
            {
                cout<<"\nFlight can't depart without arriving\n";
                exit(0);
            }
            if(dm>60)
        {
            throw miniute();
        }

        cout<<"enter ticket cost:";cin>>price;
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\nenter no of passengers in this plane:";cin>>n;
        if(n>seating_cap)
           {
                    throw seat();
           }

        else
            for(int i=0;i<n;i++)
        {
            c[i].enter_cust_details();
        }
        return n;
    }

    void details(int n)
    {
        cout<<"------------------------------------------------";
        cout<<"\n\naero id is:"<<aero_id;
        cout<<"\nsitting capacity is:"<<seating_cap;
        cout<<"\nmax_wt is:"<<max_wt;
        cout<<"\narrival time is:"<<ah<<":"<<am;
        cout<<"\ndestination time is:"<<dh<<":"<<dm;
        cout<<"\nticket cost is:"<<price;

        cout<<"\n\ncustomer details  of this plane is:\n";
            for(int i=0;i<n;i++)
        {
            c[i].pas_details();
        }
    }
};



class Airport{
public:
string A_name;
int num_of_runways;
int num_of_staff;
string location;
int totaero=0;
aeroplane *c[10];

void details(){
cout<<"Airport Name: "<<A_name<<endl;
cout<<"Number of staff: "<<num_of_staff<<endl;
cout<<"Airport location: "<<location<<endl;
}


void add(aeroplane *x){
    c[totaero]=x;
    totaero++;
}

int sort()
{
    int flag=0;
    for(int i=1;i<totaero;i++)
    {
        if(c[i]->ah==c[i-1]->ah && c[i]->am==c[i-1]->am){
            c[i]->am=(c[i]->am)+20;
            return (c[i]->aero_id);
        }
         if(c[i]->dh==c[i-1]->dh && c[i]->dm==c[i-1]->dm){
            c[i]->dm= (c[i]->dm)+20;
            return (c[i]->aero_id);
        }

    }
    return flag;
}

void verify()
{
        for(int i=1;i<totaero;i++)
        {
            if(c[i]->aero_id==c[i-1]->aero_id)
                throw identify();
        }
}

};

int main()
{
    Airport b;
    aeroplane *a[10];
    int ch;
    int i=0,cd=0,ci=0,so;
    int pas[10];
while(1){
    while(1)
    {
        system("cls");
        cout << "Welcome to the Airport DB" << endl;
        cout<<"\nPlease enter the flight details\npress 1->Domestic Flights\npress 2-> International Flights\npress 0->To get the details of flights\n";
        cin>>ch;
        if(ch==0)
            break;
        system("cls");
    try{
        switch(ch)
        {
            case 1:  a[i]=new domestic;
                cout<<"Welcome, plz.... Enter Domestic Flight details\n";
                pas[i]=a[i]->enter_details();
                b.add(a[i]);
                i++;
                cd++;
                break;
            case 2:  a[i]=new international;
                cout<<"Welcome, plz.... Enter International Flight details\n";
                pas[i]=a[i]->enter_details();
                b.add(a[i]);
                i++;
                ci++;
                break;
            case 0:break;
        }
       }
       catch(seat i)
       {
           cout<<"\n-----there are limited no of seats in the flight-----\n";
           exit(0);
       }
       catch(hour h)
       {
           cout<<"\n----------Hour input must be in 24 hour format,there are only 24 hours per day!! ----------\n";
           exit(0);
       }
       catch(miniute m)
       {
           cout<<"\n-----Invalid minute input,there are only 60 minutes per hour!!---------\n";
           exit(0);
       }
    }
system("cls");
    while(1)
    {
        cout<<"What kind of flight details you want?\npress 1->Domestic Flights\npress 2-> International Flights\npress 0->To Add new Flight details\n";
        cin>>ch;

        if(ch==0)
            break;
        switch(ch)
        {
            case 1:system("cls");
            if(cd==0)
                cout<<"There are no Domestic Flights in the airport!!!\n\n";
            else{
            cout<<"Domestic Flight details are:\n";
                for(int j=0;j<i;j++)
            {
                if(a[j]->franchise==1)
                {
                    try{
                        b.verify();
                    }
                    catch(identify f)
                    {
                        cout<<"\nwe have two aero_ids same,plz...verify\n";
                        exit(0);
                    }

                    so=b.sort();
                    if(so!=0)
                        cout<<"\nwe have delayed the flight id = "<<so<<"  by 20 min, becoz.. of schedule clash\n\n";

                    a[j]->details(pas[j]);
                }

            }
            }
                break;
            case 2: system("cls");
            if(ci==0)
                cout<<"There are no International Flights in the airport!!!\n\n";
            else{
                 cout<<"International Flight details are:\n";
                 for(int j=0;j<i;j++)
            {
                if(a[j]->franchise==2)
                {
                                        try{
                        b.verify();
                    }
                    catch(identify f)
                    {
                        cout<<"\nwe have two aero_id same,plz...verify\n";
                        exit(0);
                    }

                    so=b.sort();
                    if(so!=0)
                        cout<<"\nwe have delayed the flight id = "<<so<<"  by 20 min, becoz.. of schedule clash\n\n";
                    a[j]->details(pas[j]);
                }
            }
            }
                break;
            case 0:  break;
        }
    }
}
    return 0;
}
