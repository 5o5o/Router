//
//  main.cpp
//  Demos's DD2 P2
//
//  Created by khloud ghattas on 5/22/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include<climits>
#include "Node.hpp"
#include "CellNode.hpp"
#include "Grid.hpp"
//#include "linkedList.hpp"
//#include "linkedList.cpp"
//#include "RoutingPath.hpp"
#include "Maze.hpp"
#include<string>
#include <fstream>

using namespace std;

Maze RoutingMaze;
int UNIT = 100;
vector<Grid> grids;

class DieArea
{
public:
    int sX, sY, eX, eY;
};
DieArea dieArea;
class TRACK
{
public:
    string Direction;
    int sP;
    int Do;
    int STEP;
    string LAYER;
    // TRACKS Y -400 DO 65 STEP 200 LAYER metal1 ;
};
vector<TRACK> Tracks;
class RECT
{
public:
    double sX, sY, eX, eY;
};

class LAYER
{
public:
    string Name;
    string TYPE;
    string DIRECTION;
    double PITCH;
    double WIDTH;
    double SPACING;
    double OFFSET;
};
vector<LAYER> Metals;

class VIA
{
public:
    string Name;
    vector<LAYER> Metal;
    vector<RECT> Rect;
};
vector<VIA> Vais;

class PORT
{
public:
    LAYER Metal;
    vector<RECT> Rect;
};
class OBS
{
public:
    LAYER Metal;
    vector<RECT> Rect;
};


class PIN
{
public:
    string Name;
    string DIRECTION;
    string USE;
    string SHAPE;
    PORT Port;
};
vector<PIN> Pins;

class MACRO
{
public:
    string Name;
    string CLASS ;
    double ORIGINX;
    double ORIGINY;
    double SIZEW;
    double SIZEH;
    //bool SYMMETRYX;
    //bool SYMMETRYY;
    string SITE;
    vector<PIN> Pins;
    vector<OBS> Obss;
};
vector<MACRO> Macros;

class Component
{
public:
    string compName;
    MACRO Macro;
    string compType;
    int pX; // placed x direction
    int pY; // placed y
    string compD;
    Component( string cN , string cT, int px , int py, string cD )
    {
        compName=cN;
        compType=cT;
        pX=px;
        pY=py;
        compD=cD;
    }
    void diplayComp()
    {
        cout<<compName << "  " << compType << "  Placed " << "(" << pX << "," << pY << ")" << " " << compD<<"\n" ;
    }
};
vector<Component> compnents;

class NET
{
public:
    string Name;
    vector<pair<string , string>> RComps;
};
vector<NET> NETs;

vector<string> getwords(string line)
{
    vector<string> words;   //vector of words in this line
    //line = line.replace(;
    int sPos;               //the index of the position
    string nWord;           //to get the next word
    
    sPos = line.find_first_of(" ");
    int wLength;
    
    while (sPos >= 0)
    {
        nWord = line.substr(0, sPos);
        wLength = nWord.length();
        
        if ((nWord != ""))
        {
            words.push_back(nWord);
        }
        
        line = line.substr(sPos + 1, line.length() - 1);
        sPos = line.find_first_of(" ");
    }
    
    sPos = line.find_first_of("\r");    //to get the last word
    nWord = line.substr(0, sPos);
    wLength = nWord.length();
    
    if ((nWord != ""))
    {
        words.push_back(nWord);
    }
    
    return words;
}
vector<string> getwords(string line , string dlmtr , string edlmtr)
{
    vector<string> words;   //vector of words in this line
    //line = line.replace(;
    int sPos;               //the index of the position
    string nWord;           //to get the next word
    
    sPos = line.find_first_of(dlmtr);
    int wLength;
    
    while (sPos >= 0)
    {
        nWord = line.substr(0, sPos);
        wLength = nWord.length();
        
        if ((nWord != ""))
        {
            words.push_back(nWord);
        }
        
        line = line.substr(sPos + 1, line.length() - 1);
        sPos = line.find_first_of(dlmtr);
    }
    
    sPos = line.find_first_of(edlmtr);    //to get the last word
    nWord = line.substr(0, sPos);
    wLength = nWord.length();
    
    if ((nWord != ""))
    {
        words.push_back(nWord);
    }
    
    return words;
}



void ImportLefFile(string filePath)
{
    vector<string> lineW;
    ifstream in(filePath);
    
    if (!in.fail())
    {
        string line = "";
        while (!in.eof())
        {
            getline(in, line, '\n'); //read the frist line
            lineW = getwords(line, " ", "\r");
            if (lineW.size()>0 && lineW[0] == "LAYER")
            {
                LAYER TempLayer;
                TempLayer.Name = lineW[1];
                getline(in, line, '\n'); //read Type
                lineW = getwords(line," ","\r");
                TempLayer.TYPE = lineW[1];
                if (lineW[1] == "ROUTING")
                {
                    while (lineW[0] != "END")
                    {
                        getline(in, line, '\n'); //read Dir
                        lineW = getwords(line);
                        if(lineW[0]=="DIRECTION")
                            TempLayer.DIRECTION = lineW[1];
                        else if(lineW[0] == "PITCH")
                            TempLayer.PITCH = stod(lineW[1])*UNIT;
                        else if(lineW[0] == "WIDTH")
                            TempLayer.WIDTH = stod(lineW[1])*UNIT;
                        else if (lineW[0] == "SPACING")
                            TempLayer.SPACING = stod(lineW[1])*UNIT;
                        else if (lineW[0] == "OFFSET")
                            TempLayer.OFFSET = stod(lineW[1])*UNIT;
                    }
                }
                else if (lineW[1] == "CUT")
                {
                    getline(in, line, '\n'); //read Spacing
                    lineW = getwords(line);
                    TempLayer.SPACING = stod(lineW[1])*UNIT;
                    getline(in, line, '\n'); //read END
                }
                else
                    continue;
                Metals.push_back(TempLayer);
            }
            if (lineW.size()>0 && lineW[0] == "VIA")
            {
                VIA tempVia;
                tempVia.Name = lineW[1];
                for (int i = 0; i < 3; i++)
                {
                    getline(in, line, '\n'); //read Via Metal
                    lineW = getwords(line);
                    for (int j = 0; j < Metals.size(); j++)
                    {
                        if (Metals[j].Name == lineW[1])
                            tempVia.Metal.push_back(Metals[j]);
                    }
                    getline(in, line, '\n'); //read Via Rect
                    lineW = getwords(line);
                    RECT rect;
                    rect.sX = stod(lineW[1]); rect.sY = stod(lineW[2]); rect.eX = stod(lineW[3]); rect.eY = stod(lineW[4]);
                    tempVia.Rect.push_back(rect);
                }
                Vais.push_back(tempVia);
            }
            if (lineW.size()>0 && lineW[0] == "MACRO")
            {
                MACRO TempMacro;
                TempMacro.Name = lineW[1];
                while (!(lineW[0] == "END" && lineW[1]== TempMacro.Name))
                {
                    getline(in, line, '\n'); //read Dir
                    lineW = getwords(line);
                    if (lineW[0] == "CLASS")
                        TempMacro.CLASS = lineW[1];
                    else if (lineW[0] == "SITE")
                        TempMacro.SITE = lineW[1];
                    else if (lineW[0] == "SIZE")
                    {
                        TempMacro.SIZEW = stod(lineW[1])*UNIT;
                        TempMacro.SIZEH = stod(lineW[3])*UNIT;
                    }
                    else if (lineW[0] == "ORIGIN")
                    {
                        TempMacro.ORIGINX = stod(lineW[1])*UNIT;
                        TempMacro.ORIGINY = stod(lineW[2])*UNIT;
                    }
                    else if (lineW[0] == "PIN")
                    {
                        PIN TempPin;
                        TempPin.Name = lineW[1];
                        while (!(lineW[0] == "END" && lineW[1] == TempPin.Name))
                        {
                            getline(in, line, '\n');
                            lineW = getwords(line);
                            if (lineW[0] == "DIRECTION")
                                TempPin.DIRECTION = lineW[1];
                            else if (lineW[0] == "USE")
                                TempPin.USE = lineW[1];
                            else if (lineW[0] == "SHAPE")
                                TempPin.SHAPE = lineW[1];
                            else if (lineW[0] == "PORT")
                            {
                                while (!(lineW[0] == "END"))
                                {
                                    getline(in, line, '\n');
                                    lineW = getwords(line);
                                    
                                    if (lineW[0] == "LAYER")
                                    {
                                        for (int i = 0; i < Metals.size(); i++)
                                            if (Metals[i].Name == lineW[1])
                                                TempPin.Port.Metal = Metals[i];
                                    }
                                    else if (lineW[0] == "RECT")
                                    {
                                        RECT rect;
                                        rect.sX = stod(lineW[1]); rect.sY = stod(lineW[2]); rect.eX = stod(lineW[3]); rect.eY = stod(lineW[4]);
                                        TempPin.Port.Rect.push_back(rect);
                                    }
                                    
                                }
                                getline(in, line, '\n');
                                lineW = getwords(line);
                                
                            }
                        }
                        TempMacro.Pins.push_back(TempPin);
                    }
                    else if (lineW[0] == "OBS")
                    {
                        getline(in, line, '\n');
                        lineW = getwords(line);
                        while (!(lineW[0] == "END"))
                        {
                            if (lineW[0] == "LAYER")
                            {
                                OBS tempobst;
                                for (int i = 0; i < Metals.size(); i++)
                                    if (Metals[i].Name == lineW[1])
                                        tempobst.Metal = Metals[i];
                                getline(in, line, '\n');
                                lineW = getwords(line);
                                while (lineW[0] == "RECT")
                                {
                                    RECT rect;
                                    rect.sX = stod(lineW[1]); rect.sY = stod(lineW[2]); rect.eX = stod(lineW[3]); rect.eY = stod(lineW[4]);
                                    tempobst.Rect.push_back(rect);
                                    getline(in, line, '\n');
                                    lineW = getwords(line);
                                }
                                TempMacro.Obss.push_back(tempobst);
                            }
                        }
                        getline(in, line, '\n');
                        lineW = getwords(line);
                        
                    }
                }
                Macros.push_back(TempMacro);
                
            }
            
        }
        in.close();
    }
    else
        cout << " Could not open the file " << endl;
    
}

void ImportDefFile(string filePath)
{
    vector<string> lineW;
    ifstream in(filePath);
    
    if (!in.fail())
    {
        string line = "";
        while (!in.eof())
        {
            getline(in, line, '\n'); //read the frist line
            lineW = getwords(line);
            if (lineW.size()>0 && lineW[0] == "COMPONENTS")
            {
                //compnents.resize(stoi(lineW[1]));
                int cSize = stoi(lineW[1]);
                for (int i = 0; i < cSize; i++)
                {
                    getline(in, line, '\n');
                    lineW = getwords(line);
                    Component c(lineW[1], lineW[2], stoi(lineW[6]), stoi(lineW[7]), lineW[9]);
                    for(int i=0 ; i<Macros.size();i++ )
                        if (Macros[i].Name == lineW[2])
                        {
                            c.Macro = Macros[i];
                        }
                    
                    compnents.push_back(c);
                }
            }
            if (lineW.size()>0 && lineW[0] == "NETS")
            {
                int cSize = stoi(lineW[1]);
                getline(in, line, '\n');
                lineW = getwords(line);
                for (int i = 0; i < cSize; i++)
                {
                    NET tempNet;
                    tempNet.Name = lineW[1];
                    
                    getline(in, line, '\n');
                    lineW = getwords(line);
                    while (lineW[0] == "(")
                    {
                        pair<string, string> P;
                        P.first = lineW[1];
                        P.second = lineW[2];
                        tempNet.RComps.push_back(P);
                        getline(in, line, '\n');
                        lineW = getwords(line);
                    }
                    NETs.push_back(tempNet);
                }
            }
            
            if (lineW.size() > 0 && lineW[0] == "DIEAREA")
            {
                dieArea.sX = stoi(lineW[2]);
                dieArea.sY = stoi(lineW[3]);
                dieArea.eX = stoi(lineW[6]);
                dieArea.eY = stoi(lineW[7]);
            }
            if (lineW.size() > 0 && lineW[0] == "TRACKS")
            {
                TRACK track;
                track.Direction = lineW[1];
                track.sP = stoi(lineW[2]);
                track.Do = stoi(lineW[4]);
                track.STEP = stoi(lineW[6]);
                track.LAYER = lineW[8];
                
                Tracks.push_back(track);
            }
            
            // TRACKS Y -400 DO 65 STEP 200 LAYER metal1 ;
        }
        in.close();
    }
    else
        cout << " Could not open the file " << endl;
}

void RoutandExport(string inpFile , string outFile)
{
    vector<string> lineW;
    ifstream in(inpFile);
    ofstream out(outFile);
    if (!in.fail())
    {
        string line = "";
        while (!in.eof())
        {
            getline(in, line, '\n');
            lineW = getwords(line, " ", "\r");
            
            if (lineW.size()>0 && lineW[0] == "NETS")
            {
                out << line << endl;
                int netsize = stoi(lineW[1]);
                for (int n = 0; n < NETs.size(); n++)
                {
                    getline(in, line, '\n');
                    out << line << endl;
                    for (int r = 0; r < NETs[n].RComps.size(); r++)
                    {
                        getline(in, line, '\n');
                        out << line << endl;
                    }
                    for (int r = 0; r < NETs[n].RComps.size()-1 ; r++)
                    {
                        CellNode SC; CellNode TC;
                        for (int i = 0; i <grids.size(); i++)
                        {
                            for (int j = 0; j < grids[i].CellNodes.size(); j++)
                            {
                                if (grids[i].CellNodes[j].compName == NETs[n].RComps[r].first && grids[i].CellNodes[j].pinName == NETs[n].RComps[r].second)
                                {
                                    SC = grids[i].CellNodes[j];
                                }
                                if (grids[i].CellNodes[j].compName == NETs[n].RComps[r+1].first && grids[i].CellNodes[j].pinName == NETs[n].RComps[r+1].second)
                                {
                                    TC = grids[i].CellNodes[j];
                                }
                            }
                        }
                        RoutingPath rPath = RoutingMaze.findPath_AStar(SC, TC, SC.Ngrid, TC.Ngrid);
                        string strPath = rPath.getstringPath();
                        out << strPath;
                        
                    }
                }
                
            }
            else
            {
                out << line << endl;
            }
        }
    }
    
}

int main(int argc, char* argv[])
{
    string inplefFile = "/Users/khloudghattas/Desktop/osu035.lef";
    string inpDefFile = "/Users/khloudghattas/Desktop/arbiter_unroute.def";
    
    if (argc == 3)
    {
        inplefFile = argv[1];
        inpDefFile = argv[2];
    }
    
    string outDefFile = inpDefFile.substr(0, inpDefFile.find_last_of(".")) + "_Routed.def";
    
   // std::clock_t c_start = std::clock();
    ImportLefFile(inplefFile);
    
    ImportDefFile(inpDefFile);
    CellNode SC; CellNode TC;
    
    int tXStep = INT_MAX; int tYStep = INT_MAX;
    for (int i = 0; i < Tracks.size(); i++)
    {
        if (Tracks[i].Direction == "Y")
        {
            if (Tracks[i].STEP < tYStep)
            {
                tYStep = Tracks[i].STEP;
            }
        }
        if (Tracks[i].Direction == "X")
        {
            if (Tracks[i].STEP < tXStep)
            {
                tXStep = Tracks[i].STEP;
            }
        }
    }
    
    for (int i = 0; i < Tracks.size(); i++)
    {
        int W = 1;
        int H = 1;
        if (Tracks[i].Direction == "X")
        {
            W = (dieArea.eX - dieArea.sX) / Tracks[i].STEP + 1;
            H = (dieArea.eY - dieArea.sY) / 200 + 1;
        }
        if (Tracks[i].Direction == "Y")
        {
            H = (dieArea.eY - dieArea.sY) / Tracks[i].STEP + 1;
            W = (dieArea.eX - dieArea.sX) / 160 + 1;
        }
        Grid G(H, W, i);
        G.layerName = Tracks[i].LAYER;
        G.layerNumber = i;
        G.CellNodes.resize(W*H);
        
        grids.push_back(G);
    }
    vector<CellNode> Cells;
    for (int i = 0; i < compnents.size(); i++)
    {
        CellNode cell;
        int x = 0;
        int y = 0;
        int gn = 0;
        for (int j = 0; j < compnents[i].Macro.Pins.size();j++)
        {
            
            CellNode cell;
            int x = 0;
            int y = 0;
            int gn = 0;
            for (int g = 0; g<grids.size(); g++)
                if (grids[g].layerName == compnents[i].Macro.Pins[j].Port.Metal.Name)
                {
                    gn = g;
                    cell.Ngrid = g; cell.LayerName = compnents[i].Macro.Pins[j].Port.Metal.Name;
                    cell.compName = compnents[i].compName;
                    cell.pinName = compnents[i].Macro.Pins[j].Name;
                    //cell.RectID = r;
                    break;
                }
            int rr = 0; int rrx= compnents[i].Macro.Pins[j].Port.Rect[0].sX; int rry= compnents[i].Macro.Pins[j].Port.Rect[0].sY;
            for (int r = 1; r < compnents[i].Macro.Pins[j].Port.Rect.size(); r++)
            {
                
                if (rrx < compnents[i].Macro.Pins[j].Port.Rect[r].sX && rry< compnents[i].Macro.Pins[j].Port.Rect[r].sY)
                {
                    rr = r; rrx = compnents[i].Macro.Pins[j].Port.Rect[r].sX; rry = compnents[i].Macro.Pins[j].Port.Rect[r].sY;
                }
                
                
            }
            if (Tracks[gn].Direction == "X")
            {
                /*cell.x =(compnents[i].pX + (compnents[i].Macro.Pins[j].Port.Rect[r].eX - compnents[i].Macro.Pins[j].Port.Rect[r].sX) * 100) / Tracks[gn].STEP;
                 cell.y = (compnents[i].pY + (compnents[i].Macro.Pins[j].Port.Rect[r].eY - compnents[i].Macro.Pins[j].Port.Rect[r].sY) * 100) / 200;*/
                cell.x = (compnents[i].pX) / Tracks[gn].STEP - 1;
                cell.y = (compnents[i].pY) / tYStep - 1;
                cell.yP = (compnents[i].pY + (compnents[i].Macro.Pins[j].Port.Rect[rr].sY) * 100);
                cell.xP = (compnents[i].pX + (compnents[i].Macro.Pins[j].Port.Rect[rr].sX) * 100);
            }
            if (Tracks[gn].Direction == "Y")
            {
                cell.y = (compnents[i].pY + (compnents[i].Macro.Pins[j].Port.Rect[rr].sY) * 100) / Tracks[gn].STEP;
                cell.x = (compnents[i].pX + (compnents[i].Macro.Pins[j].Port.Rect[rr].sX) * 100) / tXStep;
                cell.yP = (compnents[i].pY + (compnents[i].Macro.Pins[j].Port.Rect[rr].sY) * 100);
                cell.xP = (compnents[i].pX + (compnents[i].Macro.Pins[j].Port.Rect[rr].sX) * 100);
                /*cell.y = (compnents[i].pY + 100) / Tracks[gn].STEP -1 ;
                 cell.x = (compnents[i].pX ) / 160 -1;*/
                if (cell.x < 0)
                    cell.x = 0;
            }
            cell.RectID = rr;
            
            Cells.push_back(cell);
            //grids[gn].CellNodes[cell.x*grids[gn].Width + cell.y] = cell;
            /*if (cell.compName == "NAND3X1_4" && cell.pinName == "A")
             {
             SC = cell;
             }*/
        }
    }
    
    for (int i = 0; i < grids[0].Height; i++)
    {
        for (int j = 0; j < grids[0].Width; j++)
        {
            CellNode cell(i,j,1,0,true,false);
            
            for (int c=0; c < Cells.size(); c++)
            {
                if (cell == Cells[c])
                {
                    cell = Cells[c];
                }
            }
            int indx = i * grids[0].Width + j;
            grids[0].CellNodes[indx] = cell;
        }
    }
    
    RoutingMaze.Grids=grids;
    RoutingMaze.nlayer = grids.size();
    RoutandExport(inpDefFile, outDefFile);
    
    //std::clock_t c_end = std::clock();
   // double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    
    cout << "Input Lef File:" << inplefFile<<endl;
    cout << "Input Def File:" << outDefFile << endl;
   // cout <<"Time Elapsed: "<< time_elapsed_ms << "sec";
    return 0;
}

