/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PalaceArcade.cpp
 * Author: admin
 * 
 * Created on June 2, 2022, 3:11 PM
 */

#include "PalaceArcade.h"

PalaceArcade::PalaceArcade() 
{
    machineName = "";
    year = 0;
    manufacturer = "";
    numQuartersNeeded = 0;
}

PalaceArcade::PalaceArcade(const PalaceArcade& orig) 
{
    machineName = orig.machineName;
    year = orig.year;
    manufacturer = orig.manufacturer;
    numQuartersNeeded = orig.numQuartersNeeded;
}

PalaceArcade::~PalaceArcade(){}

string PalaceArcade::getMachineName() const
{
    return machineName;
}
int PalaceArcade::getYear() const
{
    return year;
}
string PalaceArcade::getManufacturer() const
{
    return manufacturer;
}
int PalaceArcade::getNumQuartersNeeded() const
{
    return numQuartersNeeded;
}

void PalaceArcade::setMachineName(string inputMachineName)
{
    machineName = inputMachineName;
}

void PalaceArcade::setYear(int yearInput)
{
    year = yearInput;
}

void PalaceArcade::setManufacturer(string inputManufacturer)
{
    manufacturer = inputManufacturer;
}

void PalaceArcade::setNumQuartersNeeded(int inputNumQuarters)
{
    numQuartersNeeded = inputNumQuarters;
}

bool PalaceArcade::canPlayWithNumQuarters(const int inputNumQuarters)
{
    if (inputNumQuarters >= numQuartersNeeded && machineName != "")
        return true;
    else return false;
}
bool PalaceArcade::isEmpty()
{
    if (machineName == "")
        return true;
    else return false;
}
void PalaceArcade::printArcade() const
{
    cout << "\tMachine Name: " << machineName << endl;
    cout << "\tYear: " << year << endl;
    cout << "\tManufacturer: " << manufacturer << endl;
    cout << "\tNumber of Quarters to Play: " << numQuartersNeeded << endl;
}


