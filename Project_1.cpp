#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <Windows.h>

#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include "Customer.h"
#include "Payment.h"

using namespace std;





int main()
{
    bool stop = false;
    int i;
    vector <Location> listaLocation;
    vector <Event> listaEvent;
    vector <Ticket> listaTicket;
    vector <Customer> listaCustomer;
    vector <Payment> listaPayment;

    while (stop != true)
    {
        cout << "Type 1 if you want to add a data" << endl;
        cout << "Type 2 if you want to see the list of values" << endl;
        cout << "Type 3 if you want to modify an existing value" << endl;
        cout << "Type 4 if you want to delete an existing value" << endl;
        cout << "Type 5 if you want to filter after a price" << endl;
        cout << "Type 6 if you want to see the events in a day" << endl;
        cout << "Type 7 if you want to filter by age" << endl;
        cout << "Type 8 pentru stop" << endl;
        cout << "Choose a comand: " << endl;
        int comanda1, comanda2, comanda3;
        cin >> comanda1;
        switch (comanda1)
        {
        case 1:
        {
            cout << "Type 1 if you want to add a data in the class event" << endl;
            cout << "Type 2 if you want to add a data in the class ticket" << endl;
            cout << "Type 3 if you want to add a data in the class customer" << endl;
            cout << "Type 4 if you want to add a data in the class payment" << endl;
            cout << "Type 5 if you want to add a data in the class location" << endl;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                Event a;
                cin >> a;
                listaEvent.push_back(a);
                break;
            }
            case 2:
            {
                Ticket a;
                cin >> a;
                listaTicket.push_back(a);
                break;
            }
            case 3:
            {
                Customer a;
                cin >> a;
                listaCustomer.push_back(a);
                break;
            }
            case 4:
            {
                Payment a;
                cin >> a;
                listaPayment.push_back(a);
                break;
            }
            case 5:
            {
                Location a;
                cin >> a;
                listaLocation.push_back(a);
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 2:
        {
            cout << "Type 1 if you want to display the data in the class event" << endl;
            cout << "Type 2 if you want to display the data in the class ticket" << endl;
            cout << "Type 3 if you want to display the data in the class customer" << endl;
            cout << "Type 4 if you want to display the data in the class payment" << endl;
            cout << "Type 5 if you want to display the data in the class location" << endl;
            cin >> comanda3;
            switch (comanda3)
            {
            case 1:
            {
                for (int i = 0; i < listaEvent.size(); i++)
                {
                    cout << listaEvent[i];
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                for (int i = 0; i < listaTicket.size(); i++)
                {
                    cout << listaTicket[i];
                    cout << endl;
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < listaCustomer.size(); i++)
                {
                    cout << listaCustomer[i];
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                for (int i = 0; i < listaPayment.size(); i++)
                {
                    cout << listaPayment[i];
                    cout << endl;
                }
                break;
            }
            case 5:
            {
                for (int i = 0; i < listaLocation.size(); i++)
                {
                    cout << listaLocation[i];
                    cout << endl;
                }
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 3:
        {
            cout << "Type 1 if you want to modify a value in the class event" << endl;
            cout << "Type 2 if you want to modify a value in the class ticket" << endl;
            cout << "Type 3 if you want to modify a value in the class customer" << endl;
            cout << "Type 4 if you want to modify a value in the class payment" << endl;
            cout << "Type 5 if you want to modify a value in the class location" << endl;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                listaEvent[0].modify(listaEvent);
                break;
            }
            case 2:
            {
                listaTicket[0].modify(listaTicket);
                break;
            }
            case 3:
            {
                listaCustomer[0].modify(listaCustomer);
                break;
            }
            case 4:
            {
                listaPayment[0].modify(listaPayment);
                break;
            }
            case 5:
            {
                listaLocation[0].modify(listaLocation);
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 4:
        {
            cout << "Type 1 if you want to delete an existing value from the class event" << endl;
            cout << "Type 2 if you want to delete an existing value from the class ticket" << endl;
            cout << "Type 3 if you want to delete an existing value from the class customer" << endl;
            cout << "Type 4 if you want to delete an existing value from the class payment" << endl;
            cout << "Type 5 if you want to delete an existing value from the class location" << endl;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                listaEvent[0].deleting(listaEvent);
                break;
            }
            case 2:
            {
                listaTicket[0].deleting (listaTicket);
                break;
            }
            case 3:
            {
                listaCustomer[0].deleting(listaCustomer);
                break;
            }
            case 4:
            {
                listaPayment[0].deleting(listaPayment);
                break;
            }
            case 5:
            {
                listaLocation[0].deleting(listaLocation);
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 5:
        {
            cout << "Type 1 if you want to filter by the date of an event" << endl;
            cout << "Type 2 if you want to filter by the price of a ticket" << endl;
            cout << "Type 3 if you want to filter by the age of a customer" << endl;
            cout << "Type 4 if you want to filter by the price of a payment" << endl;
            cout << "Type 5 if you want to filter by the id of a location" << endl;
            int comanda4;
            cin >> comanda4;
            switch (comanda4)
            {
            case 1:
            {
                listaEvent[0].filtru(listaEvent);
                break;
            }
            case 2:
            {
                listaTicket[0].filtru(listaTicket);
                break;
            }
            case 3:
            {
                listaCustomer[0].filtru(listaCustomer);
                break;
            }
            case 4:
            {
                listaPayment[0].filtru(listaPayment);
                break;
            }
            case 5:
            {
                listaLocation[0].filtru(listaLocation);
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 6:
        {
            listaEvent[0].filtru(listaEvent);
            break;
        }
        case 7:
        {
            listaCustomer[0].filtru(listaCustomer);
            break;
        }
        case 8:
        {
            stop = true;
            break;
        }
        default:
        {
            cout << "Incorect comand" << endl;
            break;
        }
        }
    }
}
