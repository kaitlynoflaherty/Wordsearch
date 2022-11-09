// Project #3: Word Search Part A
// 
// Group Members: Lisa Byrne, Kaite O'Flaherty, Alek Tunik
//
// Description: Header file for the grid class
// Assumption: 

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "d_except.h"
#include "d_matrix.h"

using namespace std;

class grid
// Read letters from a grid file and store in matrix
{
    public:
    int getRows();
    int getCols();
    matrix<char> getGrid();
    char readGrid(string grid_file);

    private:
    matrix<char> _grid;
    int _rows;
    int _cols;
    
};

int grid::getRows()
// Get number of rows
{
    return _rows;
}

int grid::getCols()
// Get number of columns
{
    return _cols;
}

matrix<char> grid::getGrid()
// Return matrix
{
    return _grid;
}

char grid::readGrid(string grid_file)
// Read letters from grid file and store in matrix
{
    // open file
	ifstream infile;
    infile.open(grid_file);
    if(!infile)
    {
        cerr << "Couldn't open file, check path" << endl;
    }

    // Grabs the first 2 integers of the txt file
    // Read in number of rows and columns
	infile >> _rows >> _cols;

    //resize the matrix to grid dimensions
    _grid.resize(_rows, _cols);

    // Populate matrix with grid elements
	for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            infile >> _grid[i][j];
        }
    }
    
    // Close the file   
	infile.close();
}



