#define _CRT_SECURE_NO_WARNINGS

#include "Location.h"
#include <iostream>
#include <vector>
using namespace std;

int Location::getlocation_id() { return this->location_id; }
string Location::getvenue() { return this->venue; }
int Location::getmax_nr_seats() { return this->max_nr_seats; }
int Location::getnr_rows() { return this->nr_rows; }
string Location::getzones() { return this->zones; }
int* Location::getseats() { return this->seats; }

void Location::setlocation_id(int location_id)
{
    if (location_id != 0)
        this->location_id = location_id;
    else
        throw runtime_error("Invalid imput");
}
void Location::setvenue(string venue)
{
    if (venue != "\n")
        this->venue = venue;
    else
        throw runtime_error("Invalid imput");
}
void Location::setmax_nr_seats(int max_nr_seats)
{
    if (max_nr_seats >= 0 && max_nr_seats <= 100000)
        this->max_nr_seats = max_nr_seats;
    else
        throw runtime_error("Invalid imput");
}
void Location::setnr_rows(int nr_rows)
{
    if (nr_rows >= 0 && nr_rows <= 100)
        this->nr_rows = nr_rows;
    else
        throw runtime_error("Invalid imput");
}
void Location::setzones(string zones)
{
    if (zones != "\n")
        this->zones = zones;
    else
        throw runtime_error("Invalid imput");
}
void Location::setseats(int* seat)
{
    if (this->seats != nullptr)
        delete[] this->seats;
    this->seats = new int[this->nr_rows];
    for (int i = 0; i < this->nr_rows; i++)
        this->seats[i] = seat[i];
}



int Location:: operator [](int i)
{
    if (i<0 || i>this->nr_rows)
        throw runtime_error("Out of range");
    else
        return this->seats[i];
}
bool Location:: operator ==(const Location& l)
{
    Location aux(*this);
    if (aux.venue == l.venue &&
        aux.max_nr_seats == l.max_nr_seats &&
        aux.nr_rows == l.nr_rows &&
        aux.zones == l.zones)
    {
        for (int i = 0; i < aux.nr_rows; i++)
            if (aux.seats != l.seats)
                return false;
        return true;
    }
    return false;
}
bool Location:: operator <(const Location& t)
{
    return this->max_nr_seats < t.max_nr_seats;
}
bool Location:: operator <(int p)
{
    return this->max_nr_seats < p;
}
bool operator <(int p, const Location& t)
{
    return p < t.max_nr_seats;
}
bool Location:: operator <=(const Location& t)
{
    return this->max_nr_seats <= t.max_nr_seats;
}
bool Location:: operator <=(int p)
{
    return this->max_nr_seats <= p;
}
bool operator <=(int p, const Location& t)
{
    return p <= t.max_nr_seats;
}
bool Location:: operator >(const Location& t)
{
    return this->max_nr_seats > t.max_nr_seats;
}
bool Location:: operator >(int p)
{
    return this->max_nr_seats > p;
}
bool operator >(int p, const Location& t)
{
    return p > t.max_nr_seats;
}
bool Location:: operator >=(const Location& t)
{
    return this->max_nr_seats >= t.max_nr_seats;
}
bool Location:: operator >=(int p)
{
    return this->max_nr_seats >= p;
}
bool operator >=(int p, const Location& t)
{
    return p >= t.max_nr_seats;
}
Location& Location:: operator ++()
{
    this->max_nr_seats++;
    return *this;
}
Location Location:: operator ++(int)
{
    Location aux(*this);
    this->max_nr_seats++;
    return aux;
}
Location& Location:: operator --()
{
    this->max_nr_seats--;
    return *this;
}
Location Location:: operator --(int)
{
    Location aux(*this);
    this->max_nr_seats--;
    return aux;
}
Location Location:: operator +(const Location& t)
{
    Location aux(*this);
    aux.max_nr_seats = t.max_nr_seats + aux.max_nr_seats;
    return aux;
}
Location Location:: operator +(int p)
{
    Location aux(*this);
    aux.max_nr_seats = aux.max_nr_seats + p;
    return aux;
}
Location operator +(int p, const Location& t)
{
    Location aux(t);
    aux.max_nr_seats = aux.max_nr_seats + p;
    return aux;
}
Location Location:: operator -(const Location& t)
{
    Location aux(*this);
    aux.max_nr_seats = aux.max_nr_seats - t.max_nr_seats;
    return aux;
}
Location Location:: operator -(int p)
{
    Location aux(*this);
    aux.max_nr_seats = aux.max_nr_seats - p;
    return aux;
}
Location operator -(int p, const Location& t)
{
    Location aux(t);
    aux.max_nr_seats = p - aux.max_nr_seats;
    return aux;
}
bool Location:: operator !()
{
    if (this->nr_rows == 100)
        return true;
    return false;
}
Location::operator string()
{
    return this->venue;
}


Location::Location() {}
Location::Location(int id, string venue, int max_nr_seats, int nr_rows, string zones, int* seats)
{
    setlocation_id(id);
    setvenue(venue);
    setmax_nr_seats(max_nr_seats);
    setnr_rows(nr_rows);
    setzones(zones);
    setseats(seats);
}
Location::Location(const Location& l)
{
    setlocation_id(l.location_id);
    setvenue(l.venue);
    setmax_nr_seats(l.max_nr_seats);
    setnr_rows(l.nr_rows);
    setzones(l.zones);
    setseats(l.seats);
}
void Location::modify(vector <Location>& listaLocation)
{
    int id, ci, nr, max = 0, locuri = 0;
    cout << "Which is the id of the location that you want to modify? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaLocation.size(); i++)
        if (listaLocation[i].getlocation_id() == id)
        {
            ci = i;
            break;
        }
    cout << "Which is the new number of rows? ";
    cin >> nr;
    cout << endl;
    if (nr > listaLocation[ci].getnr_rows())
    {
        int* aux = new int[nr];
        for (int i = 0; i < listaLocation[ci].getnr_rows(); i++)
            aux[i] = listaLocation[ci].getseats()[i];
        for (int i = listaLocation[ci].getnr_rows(); i < nr; i++)
        {
            cout << "How many seats are available? ";
            cin >> aux[i];
            locuri = locuri + aux[i];
            cout << endl;
        }
        listaLocation[ci].setnr_rows(nr);
        listaLocation[ci].setseats(aux);
        max = listaLocation[ci].getmax_nr_seats() + locuri;
        listaLocation[ci].setmax_nr_seats(max);
    }
    else
    {
        int* aux = new int[nr];
        int max = INT_MIN;
        for (int i = 0; i < nr; i++)
        {
            aux[i] = listaLocation[ci].getseats()[i];
            max += aux[i];
        }

        listaLocation[ci].setnr_rows(nr);
        listaLocation[ci].setseats(aux);
        listaLocation[ci].setmax_nr_seats(max);
    }
}
void Location::deleting(vector <Location>& listaLocation)
{
    int id, ci;
    cout << "Which is the id of the location that you want to delete? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaLocation.size(); i++)
        if (listaLocation[i].getlocation_id() == id)
        {
            ci = i;
            break;
        }
    listaLocation.erase(listaLocation.begin() + ci);
}
void Location::filtru(vector <Location>& listaLocation)
{
    int id;
    cout << "Which is the id of the location that you want to find? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaLocation.size(); i++)
        if (listaLocation[i].getlocation_id() == id)
        {
            cout << listaLocation[i] << endl;
            break;
        }
}
Location& Location::operator =(const Location& l)
{
    if (this != &l)
    {
        this->venue = l.venue;
        this->max_nr_seats = l.max_nr_seats;
        this->nr_rows = l.nr_rows;
        this->zones = l.zones;
        this->seats = l.seats;
    }
    return *this;
}

ostream& operator <<(ostream& out, const Location& p)
{
    out << "The location of the id is: " << p.location_id << endl;
    out << "The location of the venue is: " << p.venue << endl;
    out << "The maximum number of seats is: " << p.max_nr_seats << endl;
    out << "The number of rows is: " << p.nr_rows << endl;
    out << "The zone is: " << p.zones << endl;
    out << "The number of seats per row are: ";
    for (int i = 0; i < p.nr_rows; i++)
        out << p.seats[i] << endl;
    return out;
}
istream& operator >>(istream& in, Location& p)
{
    cout << "The location of the id is: ";
    in >> p.location_id;
    cout << endl;
    cout << "The location of the venue is: ";
    in >> p.venue;
    cout << endl;
    cout << "The maximum number of seats is: ";
    in >> p.max_nr_seats;
    cout << endl;
    cout << "The number of rows is: ";
    in >> p.nr_rows;
    cout << endl;
    cout << "The zone is: ";
    in >> p.zones;
    cout << endl;
    cout << "The number of seats per row are: ";
    p.seats = new int[p.nr_rows];
    for (int i = 0; i < p.nr_rows; i++)
    {
        in >> p.seats[i];
        cout << endl;
    }
    return in;
}
