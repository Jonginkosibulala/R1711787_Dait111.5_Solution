/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plane.h
 * Author: R1711787
 *
 * Created on April 21, 2019, 18:26 AM
 */

#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <cstdlib>
#include <fstream>


using namespace std;

class Plane {
public:
    
    int GetTicketNum();
    void AddPassanger();
    void Status();
    void Save();
    void Read();
    string GetName();
    void Search(int n);
    void Delete(int n);
    void Edit(int n);
    
private:

    string phone;
    string name;
    int time;
    string surname;
    string date;
    string destination;
    
protected:
    
    int ticketnum;
    int seats=0;
    
};

#endif /* PLANE_H */

