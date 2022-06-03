/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on June 2, 2022, 3:09 PM
 */

#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "PalaceArcade.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    static const int MAX_ARCADE_SIZE = 30;
    PalaceArcade arcadeArray[MAX_ARCADE_SIZE];
    int menuChoice = 0;
    string inputString = "";
    int tempInt = 0;
    int machineCounter = 0;
    int slotToUse = MAX_ARCADE_SIZE-1;
    string fileMachineName,fileYear,fileManufacturer,fileNumQuarters,fullMachineLine;
    string filename = "machines.txt";
    ifstream infile;
    ofstream outfile;
    
    
    while(true)
    {
        cout << "Welcome to Hawkins Palace! Please input a menu option followed by the 'Enter' key:" << endl;
        cout << "\t1. Load Machines from File" << endl;
        cout << "\t2. Manually Enter a New Machine" << endl;
        cout << "\t3. See Which Games You can Afford to Play" << endl;
        cout << "\t4. Print Info for All Games" << endl;
        cout << "\t5. Quit and Save All Games to File" << endl;
        cout << ">>";
        
        getline(cin, inputString);
        
        while(true) 
        {
            stringstream filterStream(inputString);
            if (filterStream >> menuChoice && menuChoice > 0 && menuChoice < 6)
                break;
            else 
            {
                cout << "Invalid Input! Please try again" << endl;
                cout << ">>";
                getline(cin, inputString);
            }
        }
        
        switch(menuChoice)
        {
            case 1:  
                infile.open(filename);
                if(infile.fail())
                {
                    cout << "Open file failed... exiting now.\n";
                    break;
                }
                while(infile.peek() != EOF)
                {
                    getline(infile, fullMachineLine);
                    fileMachineName = "";
                    fileYear = "";
                    fileManufacturer = "";
                    fileNumQuarters = "";
                    for (int i=0; i<fullMachineLine.size(); i++)
                    {
                        while (fullMachineLine[i] != ',')
                        {
                            fileMachineName += fullMachineLine[i];
                            i++;
                        }
                        i++;
                        
                        while (fullMachineLine[i] != ',')
                        {
                            fileYear += fullMachineLine[i];
                            i++;
                        }
                        i++;
                        
                        while (fullMachineLine[i] != ',')
                        {
                            fileManufacturer += fullMachineLine[i];
                            i++;
                        }
                        i++;
                        
                        while (i<fullMachineLine.size())
                        {
                            fileNumQuarters += fullMachineLine[i];
                            i++;
                        }
                    }
                    for (int i=0; i<MAX_ARCADE_SIZE; i++)
                    {
                        if (arcadeArray[i].getMachineName() == "")
                        {
                            slotToUse = i;
                            break;
                        }                                         
                    }
                    arcadeArray[slotToUse].setMachineName(fileMachineName);
                    stringstream filterstream2(fileYear);
                    if(filterstream2 >> tempInt)
                    {
                        arcadeArray[slotToUse].setYear(tempInt);
                    }
                    arcadeArray[slotToUse].setManufacturer(fileManufacturer);
                    stringstream filterstream3(fileNumQuarters);
                    if(filterstream3 >> tempInt)
                    {
                        arcadeArray[slotToUse].setNumQuartersNeeded(tempInt);
                    }
                }
                infile.close();
                break;
                
            case 2:                
                for (int i=0; i<MAX_ARCADE_SIZE; i++)
                {
                    if (arcadeArray[i].getMachineName() == "")
                    {
                        slotToUse = i;
                        break;
                    }
                }                
                cout << "Welcome to machine creator! Please type a non-empty machine name followed by the 'Enter' key:" << endl;
                cout << ">>";
                getline(cin, inputString);
                
                while(true) 
                    {                        
                        if (inputString !="")
                        {
                            arcadeArray[slotToUse].setMachineName(inputString);
                            break;
                        }
                        else 
                        {
                            cout << "Invalid Input! Please try again" << endl;
                            cout << ">>";
                            getline(cin, inputString);
                        }
                    }
                
                cout << "Enter a 4 digit year followed by the 'Enter' key:" << endl;
                cout << ">>";
                getline(cin, inputString);
        
                while(true) 
                {   
                    stringstream filterStream4(inputString);
                    if (filterStream4 >> tempInt && tempInt > 1929 && tempInt < 3000)
                    {
                        arcadeArray[slotToUse].setYear(tempInt);
                        break;
                    }
                    else 
                    {
                        cout << "Invalid Input! Please try again" << endl;
                        cout << ">>";
                        getline(cin, inputString);
                    }
                }
                
                cout << "Enter a non-empty manufacturer name followed by the 'Enter' key:" << endl;
                cout << ">>";
                getline(cin, inputString);
                
                while(true) 
                    {                        
                        if (inputString !="")
                        {
                            arcadeArray[slotToUse].setManufacturer(inputString);
                            break;
                        }
                        else 
                        {
                            cout << "Invalid Input! Please try again" << endl;
                            cout << ">>";
                            getline(cin, inputString);
                        }
                    }
                
                cout << "Enter the number of quarters required to play (1-12) followed by the 'Enter' key:" << endl;
                cout << ">>";
                getline(cin, inputString);
        
                while(true) 
                {   
                    stringstream filterStream(inputString);
                    if (filterStream >> tempInt && tempInt > 0 && tempInt < 13)
                    {
                        arcadeArray[slotToUse].setNumQuartersNeeded(tempInt);
                        break;
                    }
                    else 
                    {
                        cout << "Invalid Input! Please try again" << endl;
                        cout << ">>";
                        getline(cin, inputString);
                    }
                }
                break;
                
            case 3:
                cout << "Enter the number of quarters you have (1-999) followed by the 'Enter' key:" << endl;
                cout << ">>";
                getline(cin, inputString);
        
                while(true) 
                {   
                    stringstream filterStream(inputString);
                    if (filterStream >> tempInt && tempInt > 0 && tempInt < 999)
                    {
                        
                        break;
                    }
                    else 
                    {
                        cout << "Invalid Input! Please try again" << endl;
                        cout << ">>";
                        getline(cin, inputString);
                    }
                }
                
                machineCounter = 0;
                
                for (int i=0; i<MAX_ARCADE_SIZE; i++)
                {
                    if (arcadeArray[i].canPlayWithNumQuarters(tempInt))
                    {
                        machineCounter++;
                    }
                }
                
                if (machineCounter == 0)
                    cout << "Sorry, you are unable to play any games with that number of quarters" << endl;
                else
                {   
                    cout << "You can play " << machineCounter << " game";
                    if (machineCounter > 1)
                        cout << "s:" << endl;
                    else 
                        cout << ":" << endl;
                    for (int i=0; i<MAX_ARCADE_SIZE; i++)
                    {
                        if (arcadeArray[i].canPlayWithNumQuarters(tempInt))
                        {
                            cout << "\t" << arcadeArray[i].getMachineName() << endl;
                        }
                    }
                }
                
                break;
                
            case 4:
                for (int i=0; i<MAX_ARCADE_SIZE; i++)
                {
                    if(!arcadeArray[i].isEmpty())
                    {
                        cout << "Machine " << i+1 << ":" << endl;
                        arcadeArray[i].printArcade();
                    }
                }
                
                break;
            case 5:
                outfile.open(filename);
                if(outfile.fail())
                {
                    cout << "Open file for saving failed... exiting now.\n";
                    break;
                }
                for (int i=0; i<MAX_ARCADE_SIZE; i++)
                {
                    if(!arcadeArray[i].isEmpty() && outfile.is_open())
                    {
                        outfile << arcadeArray[i].getMachineName() << ",";
                        outfile << arcadeArray[i].getYear() << ",";
                        outfile << arcadeArray[i].getManufacturer() << ",";
                        outfile << arcadeArray[i].getNumQuartersNeeded() << "\n";
                    }
                }
                outfile.close();
                return 0;
                break;
        }
    }

    return 0;
}