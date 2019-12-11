//Equipment.h
#include <iostream>
/*
Equipment class invoked by ticket class as no equipment can be dropped off if there is no customer, 
and each order is tracked by a ticket
Since Equipment is reliant on ticket, there is no status stored in Equipment. 
A general staus is stored in Ticket.
*/
#ifndef EQUIPMENT_H
#define EQUIPMENT_H
class Equipment{
Public:
       //constructors
       Equipment();
       Equipment(int eqID, int custID, std::string eqDesc);
       //mutators
       void setEQID(int eqID);
       void setCustID(int custID;
       void setEqDesc(std::string eqDesc);
       //accessors
       int getEQID();
       int getCustID();
       std::string getEqDesc();
       //print function for Equipment
       print(); 
Private:
        /*Equipment details to track
                    Equ9pment ID
                    Customer equipment belongs to
                    Brief description of equipment
                          Example: PC, Laptop
                    
        The customer ID should be taken from an id strored in the ticket that is attributed to the customer.
        */
        int eqID;
        int custID;
        std::string eqDesc;
}

#endif
