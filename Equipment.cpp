//Equipment.cpp
#include "Equipment.h"

Equipment::(){
     eqID = 000;
     custID = 000;
     eqDesc = "CPU Fan";
}

Equipment::Equipment(int eq, int cust, std::string eqd){
     eqID = eq;
     custID = cust;
     eqDesc = eqd;
}

void Equipment;:setEQID(int eq){
     eqID = eq;
}

void Equipment;:setCustID(int cust){
     custId = cust;
}

void Equipment::setEqDesc(std::string desc){
     eqDesc = desc;
}

int Equipment::getEQID(){ return eqID;}

int Equipment::getCustId(){ return custID;}

std::string Equipment::getEqDesc(){return eqDesc;}

void Equipmen::print(){
        std::cout<< "=================================== \n"
            << "Equipment Information: \n"
            << "Equipment ID#: "<< eqid<< "\n"
            << "Customer Number: "<< custID<< "\n"
            << "Equipment Description: "<< eqDesc<< "\n"
            << "==================================="<< endl;
}
