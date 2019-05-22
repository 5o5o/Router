//
//  main.cpp
//  DDD222
//
//  Created by khloud ghattas on 5/21/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
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

//class CellNode
//{
//public:
//    int x;
//    int y;
//    double cost;
//    double currentCost;
//    bool isvia;
//    char viaChar;
//    bool isvisited;
//    char obstcaleChar;
//    char pathChar;
//    int Ngrid;
//    bool isobstacle;
//
//    CellNode()
//    {
//        x = 0;
//        y = 0;
//        cost = 0;
//        currentCost = 0;
//        isvia = false;
//        obstcaleChar = '#';
//        pathChar = '@';
//        viaChar = 'V';
//        Ngrid = 0;
//        isvisited = false;
//        isobstacle = false;
//    }
//    CellNode(int cX, int cY, double cC, bool obst)
//    {
//        x = cX;
//        y = cY;
//        cost = cC;
//        currentCost = 0;
//        isvia = false;
//        obstcaleChar = '#';
//        pathChar = '@';
//        Ngrid = 0;
//        isvisited = false;
//        isobstacle = obst;
//        viaChar = 'V';
//    }
//    CellNode(int cX, int cY, double cC, int nG, bool isobs, bool via)
//    {
//        x = cX;
//        y = cY;
//        cost = cC;
//        Ngrid = nG;
//        currentCost = 0;
//        isvia = false;
//        obstcaleChar = '#';
//        pathChar = '@';
//        viaChar = 'V';
//        isvisited = false;
//        isobstacle = false;
//        isvia = via;
//    }
//    bool isequal(CellNode cell)
//    {
//        return ((x == cell.x) && (y == cell.y) && Ngrid == cell.Ngrid);
//
//    }
//
//    bool operator == (const CellNode& cell)
//    {
//        return ((x == cell.x) && (y == cell.y) && Ngrid == cell.Ngrid);
//    }
//
//    void showCell()
//    {
//        cout << "(" << x << "," << y << "," << Ngrid << ")";
//    }
//};
//class Node
//{
//public:
//    CellNode element;
//    Node* next;
//    Node* parent;
//    Node(CellNode cell)
//    {
//        element = cell;
//    }
//    ~Node()
//    {
//
//        while (parent != NULL)
//        {
//        }
//    }
//};

/*class Grid
 {
 public:
 int Width;
 int Height;
 vector <CellNode> CellNodes;
 int layerNumber;
 Grid()
 {
 Width = 0;
 Height = 0;
 initializeCells();
 layerNumber;
 }
 Grid(int W, int H, int lN)
 {
 Width = W;
 Height = H;
 layerNumber = lN;
 initializeCells();
 
 }
 bool isvalid(CellNode cell)
 {
 return !(cell.isvisited || cell.isobstacle || cell.x >= Width || cell.y >= Height);
 
 }
 void initializeCells()
 {
 for (int i = 0; i<Width; i++)
 for (int j = 0; j<Height; j++)
 {
 CellNode cell(i, j, layerNumber + 1, layerNumber, false, false);
 CellNodes.push_back(cell);
 }
 
 CellNodes[13].isobstacle = true;
 CellNodes[14].isobstacle = true;
 CellNodes[45].isobstacle = true;
 CellNodes[46].isobstacle = true;
 CellNodes[55].isobstacle = true;
 CellNodes[56].isobstacle = true;
 }
 void initializeCellsFromUsers(vector <CellNode> cNodes)
 {
 CellNodes = cNodes;
 }
 void Draw()
 {
 cout << "Layer" << layerNumber + 1 << ":" << endl;
 for (size_t i = 0; i < Width; i++)
 cout << "---";
 cout << endl;
 for (int i = 0; i<CellNodes.size(); i++)
 {
 if (CellNodes[i].isobstacle)
 cout << "|" << CellNodes[i].obstcaleChar << "|";
 else if (CellNodes[i].isvia)
 cout << "|" << CellNodes[i].viaChar << "|";
 else
 cout << "|" << CellNodes[i].cost << "|";
 if ((i + 1) % 10 == 0)
 cout << endl;
 }
 for (size_t i = 0; i < Width; i++)
 cout << "---";
 cout << endl;
 }
 void Draw(vector<CellNode> path)
 {
 cout << "\n Layer" << layerNumber + 1 << ":\n";
 for (size_t i = 0; i < Width; i++)
 cout << "---";
 cout << endl;
 for (int i = 0; i<CellNodes.size(); i++)
 {
 bool isPath = false;
 for (int j = 0; j < path.size(); j++)
 if (path[j] == CellNodes[i])
 isPath = true;
 if (isPath)
 cout << "|" << CellNodes[i].pathChar << "|";
 else if (CellNodes[i].isobstacle)
 cout << "|" << CellNodes[i].obstcaleChar << "|";
 else if (CellNodes[i].isvia)
 cout << "|" << CellNodes[i].viaChar << "|";
 else
 cout << "|" << CellNodes[i].cost << "|";
 if ((i + 1) % 10 == 0)
 {
 cout << endl;
 }
 }
 for (size_t i = 0; i < Width; i++)
 cout << "---";
 }
 CellNode getCellNode(int X, int Y)
 {
 int i = (X * Width + Y);
 return  CellNodes[i];
 }
 void setViaCellNode(int X, int Y, bool via)
 {
 int i = (X * Width + Y);
 if (i >= 0 && i < Width*Height)
 CellNodes[i].isvia = via;
 }
 };*/
/*class RoutingPath
 {
 public:
 linkedList <CellNode> TargetPath;
 double PathCost;
 RoutingPath()
 {
 PathCost = 0;
 }
 void showPath()
 {
 vector <CellNode> targetList = TargetPath.getList();
 for (int i = 0; i < targetList.size(); i++)
 {
 targetList[i].showCell();
 cout << endl;
 }
 cout << PathCost << endl;
 }
 };*/
/*class Maze
 {
 public:
 int nlayer;
 CellNode cSource;
 CellNode cTarget;
 int nlS, nlT;
 RoutingPath targetRoutePath;
 vector <Grid> Grids;
 Maze()
 {
 nlayer = 1;
 
 }
 Maze(int ML)
 {
 nlayer = ML;
 initializeMazes();
 }
 void initializeMazes()
 {
 Grid grid(10, 10, 0);
 Grids.push_back(grid);
 }
 void initializeMazesFromUsers(int W, int H, int ML)
 {
 nlayer = ML;
 for (int i = 0; i<ML; i++)
 {
 Grid grid(W, H, i);
 Grids.push_back(grid);
 }
 }
 void DrawMaze()
 {
 for (int i = 0; i< nlayer; i++)
 {
 Grids[i].Draw();
 
 }
 }
 void DrawMaze(vector<CellNode> path)
 {
 for (int i = 0; i< nlayer; i++)
 {
 Grids[i].Draw(path);
 
 }
 }
 bool setSource(int X, int Y, int Ngrid)
 {
 cSource = Grids[Ngrid].getCellNode(X, Y);
 nlS = Ngrid;
 return true;
 }
 bool setTarget(int X, int Y, int Ngrid)
 {
 cTarget = Grids[Ngrid].getCellNode(X, Y);
 nlT = Ngrid;
 return true;
 }
 void setVia(int X, int Y)
 {
 for (int i = 0; i<nlayer; i++)
 Grids[i].setViaCellNode(X, Y, true);
 }
 CellNode getCellNode(int X, int Y, int Ngrid)
 {
 return Grids[Ngrid].getCellNode(X, Y);
 }
 
 RoutingPath findPath_AStar()
 {
 RoutingPath targetPath;
 targetPath = findPath_AStar(cSource, cTarget, nlS, nlT);
 return targetPath;
 }
 
 RoutingPath findPath_AStar(int X1, int Y1, int N1, int X2, int Y2, int N2)
 {
 RoutingPath targetPath;
 setSource(X1, Y1, N1);
 setSource(X2, Y2, N2);
 return targetPath;
 }
 
 int getNextLayer(int nL)
 {
 if (nL == 0 && cTarget.Ngrid > 0)
 return nL + 1;
 else if (nL == 1 && cTarget.Ngrid > 1)
 return nL + 1;
 else if (nL == 1 && cTarget.Ngrid < 1)
 return nL - 1;
 else if (nL == 2 && cTarget.Ngrid < 2)
 return nL - 1;
 else
 return nL;
 
 }
 
 using NodeSet = std::set<Node*>;
 RoutingPath findPath_AStar(CellNode Source, CellNode Target, int nlS, int nlT)
 {
 RoutingPath targetPath;
 vector<CellNode> closedSet;
 vector<CellNode> openSet;
 NodeSet copenset;
 NodeSet cclosedSet;
 copenset.insert(new Node(Source));
 openSet.push_back(Source);
 CellNode current;
 Node* cCurrent = nullptr;
 vector <int> rD = { 1,-1,0,0,0 };
 vector <int> cD = { 0,0,1,-1,0 };
 int currentCost = 0;
 int SucCost = 0;
 while (!openSet.empty())
 {
 current = openSet[0];
 
 for (int i = 0; i< openSet.size(); i++)
 {
 if (openSet[i].currentCost < current.currentCost)
 {
 current = openSet[i];
 }
 }
 cCurrent = *copenset.begin();
 for (auto node : copenset) {
 if (node->element == current) {
 cCurrent = node;
 }
 }
 currentCost = current.currentCost;
 closedSet.push_back(current);
 cclosedSet.insert(cCurrent);
 
 if (current.isequal(Target))
 {
 break;
 }
 
 openSet.erase(find(openSet.begin(), openSet.end(), current));
 
 for (int i = 0; i < 5; i++)
 {
 int X = current.x + rD[i];
 int Y = current.y + cD[i];
 bool isViaCell = false;
 if (i == 4) {
 if (!current.isvia)
 continue;
 else
 isViaCell = true;
 }
 if ((X >= 0 && X < Grids[0].Width && Y >= 0 && Y < Grids[0].Height))
 {
 int nL = current.Ngrid;
 if (isViaCell)
 nL = getNextLayer(nL);
 
 CellNode Neighbour = getCellNode(current.x + rD[i], current.y + cD[i], nL);
 if (Neighbour.isobstacle)
 continue;
 bool isinOpenL = false;
 for (int i = 0; i < openSet.size(); i++)
 {
 if (Neighbour.isequal(openSet[i]))
 {
 Neighbour = openSet[i];
 isinOpenL = true;
 }
 
 }
 
 bool isv = false;
 for (int i = 0; i < closedSet.size(); i++)
 {
 if (Neighbour.isequal(closedSet[i]))
 {
 Neighbour = closedSet[i];
 isv = true;
 }
 }
 
 SucCost = current.currentCost + Neighbour.cost;
 Node* cNeighbor = new Node(Neighbour);
 if (isinOpenL)
 {
 if (SucCost >= Neighbour.currentCost) continue;
 }
 else if (isv && !(Neighbour.isequal(Source)))
 {
 if (SucCost >= Neighbour.currentCost)
 continue;
 closedSet.erase(find(closedSet.begin(), closedSet.end(), Neighbour));
 openSet.push_back(Neighbour);
 cNeighbor->parent = cCurrent;
 copenset.insert(cNeighbor);
 }
 else if (!(Neighbour.isequal(Source)))
 {
 Neighbour.isvisited = true;
 Neighbour.currentCost = SucCost;
 openSet.push_back(Neighbour);
 copenset.insert(cNeighbor);
 }
 cNeighbor->parent = cCurrent;
 
 }
 }
 
 }
 
 // A* algorithim
 while (cCurrent != NULL || cCurrent != nullptr)
 {
 targetRoutePath.TargetPath.addBack(cCurrent->element);
 cCurrent = cCurrent->parent;
 }
 
 targetRoutePath.PathCost = currentCost;
 return targetRoutePath;
 }
 };*/

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
int main()
{
    ImportLefFile("/Users/khloudghattas/Desktop/osu035.lef");
    
    ImportDefFile("/Users/khloudghattas/Desktop/cpu_unroute.def");
    CellNode SC;
    CellNode TC;
    vector<Grid> grids;
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
            
            for (int r = 0; r < compnents[i].Macro.Pins[j].Port.Rect.size(); r++)
            {
                
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
                        cell.RectID = r;
                        break;
                    }
                if (Tracks[gn].Direction == "X")
                {
                    /*cell.x =(compnents[i].pX + (compnents[i].Macro.Pins[j].Port.Rect[r].eX - compnents[i].Macro.Pins[j].Port.Rect[r].sX) * 100) / Tracks[gn].STEP;
                     cell.y = (compnents[i].pY + (compnents[i].Macro.Pins[j].Port.Rect[r].eY - compnents[i].Macro.Pins[j].Port.Rect[r].sY) * 100) / 200;*/
                    cell.x = (compnents[i].pX ) / Tracks[gn].STEP -1;
                    cell.y = (compnents[i].pY ) / 200 -1;
                }
                if (Tracks[gn].Direction == "Y")
                {
                    /*cell.y = (compnents[i].pY + (compnents[i].Macro.Pins[j].Port.Rect[r].eY - compnents[i].Macro.Pins[j].Port.Rect[r].sY) * 100) / Tracks[gn].STEP;
                     cell.x = (compnents[i].pX + (compnents[i].Macro.Pins[j].Port.Rect[r].eX - compnents[i].Macro.Pins[j].Port.Rect[r].sX) * 100) / 160;*/
                    cell.y = (compnents[i].pY + 100) / Tracks[gn].STEP -1 ;
                    cell.x = (compnents[i].pX ) / 160 -1;
                    if (cell.x < 0)
                        cell.x = 0;
                }
                
            }
            Cells.push_back(cell);
            //grids[gn].CellNodes[cell.x*grids[gn].Width + cell.y] = cell;
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
            grids[0].CellNodes[i*grids[0].Width + j] = cell;
        }
    }
    /*( NAND3X1_4 A )
     ( AOI22X1_8 Y )*/
    RoutingMaze.Grids=grids;
    RoutingMaze.nlayer = grids.size();
    
    for (int i = 0; i <grids.size(); i++)
    {
        for (int j = 0; j < grids[i].CellNodes.size(); j++)
        {
            if (grids[i].CellNodes[j].compName == "NAND3X1_4")
            {
                SC = grids[i].CellNodes[j];
            }
            if (grids[i].CellNodes[j].compName == "AOI22X1_8")
            {
                TC = grids[i].CellNodes[j];
            }
        }
        
    }
    RoutingPath rPath = RoutingMaze.findPath_AStar(SC , TC , SC.Ngrid, TC.Ngrid);
    grids[0].Draw();
    rPath.showPath();
    return 0;
}

