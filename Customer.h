#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

class Customer
{
    int customer_id;
    string name;
    string phone;
    string email;
    int age;

public:

    int getcustomer_id();
    string getname();
    string getphone();
    string getemail();
    int getage();

    void setcustomer_id(int customer_id);
    void setname(string name);
    void setphone(string phone);
    void setemail(string email);
    void setage(int age);

    Customer();
    Customer(int customer_id, string name, string phone, string email, int age);
    Customer(const Customer& c);
    Customer(int customer_id);
    Customer(int customer_id, string name);
    Customer& operator =(const Customer& c);

    void modify(vector <Customer>& listaCustomer);
    void deleting(vector <Customer>& listaCustomer);
    void filtru(vector <Customer>& listaCustomer);
    
    friend ostream& operator << (ostream& out, const Customer& c);
    friend istream& operator >> (istream& in, Customer& c);
    bool operator ==(const Customer& c);
    bool operator <(const Customer& c);
    bool operator <(int a);
    friend bool operator <(int a, const Customer& c);
    bool operator <=(const Customer& c);
    bool operator <=(int a);
    friend bool operator <=(int a, const Customer& c);
    bool operator >(const Customer& c);
    bool operator >(int a);
    friend bool operator >(int a, const Customer& c);
    bool operator >=(const Customer& c);
    bool operator >=(int a);
    friend bool operator >=(int a, const Customer& c);
    Customer& operator ++();
    Customer operator ++(int);
    Customer& operator --();
    Customer operator --(int);
    Customer operator +(const Customer& c);
    Customer operator +(int a);
    friend Customer operator +(int a, const Customer& c);
    Customer operator -(const Customer& c);
    Customer operator -(int a);
    friend Customer operator -(int a, const Customer& c);
    Customer operator !();
    explicit operator int();
    ~Customer();
};

