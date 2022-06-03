/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PalaceArcade.h
 * Author: admin
 *
 * Created on June 2, 2022, 3:11 PM
 */

#include <iostream>
using namespace std;

#ifndef PALACEARCADE_H
#define PALACEARCADE_H

class PalaceArcade {
public:
    PalaceArcade();
    PalaceArcade(const string inputName, 
        const int inputYear, 
        const string inputManufacturer, 
        const int inputNumQuarters);
    PalaceArcade(const PalaceArcade& orig);
    virtual ~PalaceArcade();
    
    string getMachineName() const;
    int getYear() const;
    string getManufacturer() const;
    int getNumQuartersNeeded() const;
    
    void setMachineName(string inputMachineName);
    void setYear(int yearInput);
    void setManufacturer(string inputManufacturer);
    void setNumQuartersNeeded(int inputNumQuarters);
    
    bool canPlayWithNumQuarters(const int inputNumQuarters); 
    bool isEmpty();
    void printArcade() const;
    
private:
    string machineName;
    int year;
    string manufacturer;
    int numQuartersNeeded;
};

#endif /* PALACEARCADE_H */

