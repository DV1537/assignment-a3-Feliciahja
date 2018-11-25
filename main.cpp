#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include "Triangle.h"
#include "Polygon.h"
#include <iostream>
#include <fstream>
#include <cmath>


int main(int argc, const char * argv[])
{
    int arraySize = 4;
    double *vertices = new double [arraySize];
    int numCoords;
    double value;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);

    //Testing for file open errors before processing it
    if(myReadFile)
    {
        while (myReadFile >> value)
        {
            //Expand array if no space left
            if(numCoords == arraySize) 
            {
                double *tempArray = new double[arraySize * 2];
                for(int i = 0; i < arraySize; i++)
                {
                    tempArray[i] = vertices[i];
                }
                arraySize = arraySize * 2;
                delete [] vertices;
                vertices = tempArray; 
                tempArray = nullptr;
            }
            vertices[numCoords] = value;
            numCoords++;
        }
        //The condition will evaluate to true if the attempted file operation failed and it was not the end of the file
        if (myReadFile.fail() && !(myReadFile.eof()))
        {
            std::cout << "The file contained invalid input.\nThe program will terminate." << std::endl;
            exit(EXIT_FAILURE);
        }
        myReadFile.close();
    }
    else
    {
        std::cout << "Error opening the file.\n"; 
        exit(EXIT_FAILURE);
    }

    double *xCoord = new double[numCoords/2];
    double *yCoord = new double[numCoords/2];

//Storing the x and y coords in seperate arrays
    for(int count = 0; count < numCoords; count++) 
    {
        int coordIndex = count / 2;
        if(count % 2 == 0)
            xCoord[coordIndex] = vertices[count];
        else
            yCoord[coordIndex] = vertices[count];
    }

//Determining the shape by comparing the number of coords read in from file
    if(numCoords > 6)
    {
        if(numCoords % 2 == 0)
        {    
            int vertices = (numCoords / 2);
            Polygon polygon(xCoord, yCoord, vertices);
            double area = polygon.area();
            double roundedArea = round(area * 1000) / 1000.0;
            std::cout << roundedArea;
        }
    }
    else if(numCoords == 6)
    {
        Triangle triangle(xCoord, yCoord);
        double area = triangle.area();
        double roundedArea = round(area * 1000) / 1000.0;
        std::cout << roundedArea;
    }
    else if(numCoords == 4)
    {
        Line line(xCoord, yCoord);
        std::cout << line.area();
    }
    else if(numCoords == 2) 
    {
        Point point(xCoord, yCoord);
        std::cout << point.area();
    }
    else
        std::cout << "That is not a shape.." << std::endl;

    std::getchar();

    return 0;

}


