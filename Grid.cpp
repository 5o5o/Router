//
//  Grid.cpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//


#include "Grid.hpp"
#include <iostream>
#include <vector>
Grid::Grid()
    {
        Width = 0;
        Height = 0;
        initializeCells();
        //layerNumber;
    }
Grid::Grid(int W, int H , int lN)
    {
        Width = W;
        Height = H;
        layerNumber = lN;
        //initializeCells();
        
    }
bool Grid:: isvalid(CellNode cell)
    {
        return !(cell.isvisited || cell.isobstacle || cell.x >= Width || cell.y >= Height);
        
    }
void Grid::initializeCells()
    {
        for (int i = 0; i<Width; i++)
            for (int j = 0; j<Height; j++)
            {
                CellNode cell(i, j, 1,layerNumber,false,false);
                CellNodes.push_back(cell);
            }
        
        //CellNodes[13].isobstacle = true;
        //CellNodes[14].isobstacle = true;
        //CellNodes[45].isobstacle = true;
        //CellNodes[46].isobstacle = true;
        //CellNodes[55].isobstacle = true;
        //CellNodes[56].isobstacle = true;
    }
void Grid::initializeCellsFromUsers(vector <CellNode> cNodes)
    {
        CellNodes = cNodes;
    }
void Grid::Draw()
    {
        cout << "Layer" << layerNumber+1 << ":"<<endl;
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
            if ((i + 1) % Width == 0)
                cout << endl;
        }
        for (size_t i = 0; i < Width; i++)
            cout << "---";
        cout << endl;
    }
void Grid::Draw(vector<CellNode> path)
    {
        cout << "\n Layer" << layerNumber+1 << ":\n";
        for (size_t i = 0; i < Width; i++)
            cout << "---";
        cout << endl;
        for (int i = 0; i<CellNodes.size(); i++)
        {
            bool isPath = false;
            for (int j = 0; j < path.size(); j++)
                if (path[j] == CellNodes[i])
                    isPath = true;
            if(isPath)
                cout << "|" << CellNodes[i].pathChar<< "|";
            else if(CellNodes[i].isobstacle)
                cout << "|" << CellNodes[i].obstcaleChar << "|";
            else if(CellNodes[i].isvia)
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
CellNode Grid::getCellNode(int X, int Y)
    {
        int i = (X * Width + Y);
        return  CellNodes[i];
    }
void Grid::setViaCellNode(int X, int Y , bool via)
    {
        int i = (X * Width + Y);
        if (i >= 0 && i < Width*Height)
            CellNodes[i].isvia = via;
    }

