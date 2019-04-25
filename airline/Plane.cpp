/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plane.cpp
 * Author: R1711787
 * 
 * Created on April 21, 2019, 18:26 AM
 */


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <valarray>
#include "Plane.h"


using namespace std;

int Plane::GetTicketNum(){
    return ticketnum;
}
void Plane::AddPassanger() {

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter Phone number: ";
    cin >> phone;
    cout << "Enter Destination: ";
    cin >> destination;
    cout << "Enter time: ";
    cin >> time;
    cout << "Enter Date: ";
    cin >> date;
    cout << "Enter Ticketnum: ";
    cin >> ticketnum;
    

}

void Plane::Status() {

    cout << "Name             :  " << name << "\n";
    cout << "Surname          :  " << surname << "\n";
    cout << "Phone Number     :  " << phone << "\n";
    cout << "Destination      :  " << destination << "\n";
    cout << "Time             :  " << time << "\n";
    cout << "Date             :  " << date << "\n";
    cout << "Ticketnum        :  " << ticketnum << "\n";
    cout << "Seatnum          :  " << (seats+ticketnum) << "\n";
            
}

void Plane::Save() {

    Plane p;
    ofstream outfile("Planet//Pass.txt",ios::app|ios::binary);
    p.AddPassanger();
    outfile.write((char*) &p, sizeof (p));
    outfile.close();

}

void Plane::Read() {
    Plane p;
    ifstream infile("Planet//Pass.txt", ios::in|ios::binary);
    while (infile.read((char*) &p, sizeof (p))) {
        p.Status();

    }
    infile.close();
}

void Plane::Search(int n) {
    Plane p;
   
     ifstream infile("Planet//Pass.txt", ios::in|ios::binary);
   // infile.seekg(sizeof (p)*(ticket - 1));
    while(infile.read((char*) &p, sizeof (p))){
        
        if(p.GetTicketNum()==n){
          p.Status();
        }
    }
    infile.close();
}

void Plane::Delete(int n){
       
       Plane p;
       ifstream ifile("Planet//Pass.txt",ios::in);
       ofstream ofile("PlaneX//Pass.txt",ios::out|ios::binary);
       if(ifile.read((char*)&p,sizeof(p)))
       {
           if(p.GetTicketNum()!=n){
               cout << "\ndeleting product..." << endl;
               ofile.write((char*)&p,sizeof(p));
               cout << "\nProduct deleted" << endl;
               
           }
       }
       ifile.close();
       ofile.close();
       remove("Planet//Pass.txt");
       rename("PlaneX//Pass.txt","Planet//Pass.txt");
   }
   void Plane::Edit(int n){
      Plane p;
       fstream file("Planet//Pass",ios::binary);
       while(file.read((char*)&p,sizeof(p)))
       {
           if(p.GetTicketNum()==n){
               cout << "attempting to write...\n" << endl;
               p.AddPassanger();
               file.seekg(sizeof(p)*-1,ios::cur);
               file.write((char*)&p,sizeof(p));
               file.flush();
               
               
           }
       }
       file.close();
   }
