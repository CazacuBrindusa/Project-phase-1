#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;


class Ticket
{
    const int ticket_id;
    static int idcontor;
    int seat_nr;
    double price;
    char status; //s=sold, a=available, r=reserved

public:

    const int getticket_id();
    static int getidcontor();
    int getseat_nr();
    double getprice();
    char getstatus();

    void setseat_nr(int seat_nr);
    void setprice(double price);
    void setstatus(char status);

    Ticket();
    Ticket(int ticket_id, int seat_nr, double price, char status);
    Ticket(const Ticket& t);
    Ticket(int seat_nr);
    Ticket(int seat_nr, double price);
    Ticket& operator =(const Ticket& t);

    void modify(vector <Ticket>& listaTicket);
    void deleting(vector <Ticket>& listaTicket);
    void filtru(vector <Ticket>& listaTicket);

    friend ostream& operator << (ostream& out, const Ticket& t);
    friend istream& operator >> (istream& in, Ticket& t);
    bool operator <(const Ticket& t);
    bool operator <(int p);
    friend bool operator <(int p, const Ticket& t);
    bool operator <=(const Ticket& t);
    bool operator <=(int p);
    friend bool operator <=(int p, const Ticket& t);
    bool operator >(const Ticket& t);
    bool operator >(int p);
    friend bool operator >(int p, const Ticket& t);
    bool operator >=(const Ticket& t);
    bool operator >=(int p);
    friend bool operator >=(int p, const Ticket& t);
    Ticket& operator ++();
    Ticket operator ++(int);
    Ticket& operator --();
    Ticket operator --(int);
    Ticket operator +(const Ticket& t);
    Ticket operator +(double p);
    friend Ticket operator +(double p, const Ticket& t);
    Ticket operator -(const Ticket& t);
    Ticket operator -(double p);
    friend Ticket operator -(double p, const Ticket& t);
    bool operator ==(const Ticket& t);
    Ticket operator !();
    explicit operator char();
    explicit operator double();
    ~Ticket();
};

