#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>


int main(int argc, const char * argv[])
{
    int arraySize = 4;
    double *shape1 = new double [arraySize];
    double *shape2 = new double [arraySize];
    int numCoords1 = 0; 
    int numCoords2 = 0;
    double value;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);

    //Testing for file open errors before processing it
    if(myReadFile)
    {
        std::string firstLine;
        std::getline(myReadFile, firstLine);
        std::istringstream iss(firstLine);

        while (iss >> value)
        {
            //Expand array if no space left
            if(numCoords1 == arraySize) 
            {
                double *tempArray = new double[arraySize * 2];
                for(int i = 0; i < arraySize; i++)
                {
                    tempArray[i] = shape1[i];
                }
                arraySize = arraySize * 2;
                delete [] shape1;
                shape1 = tempArray; 
                tempArray = nullptr;
            }
            shape1[numCoords1] = value;
            numCoords1++;
        }
        //The condition will evaluate to true if the attempted file operation failed and it was not the end of the file
        if (iss.fail() && !(iss.eof()))
        {
            std::cout << "The file contained invalid input.\nThe program will terminate." << std::endl;
            exit(EXIT_FAILURE);
        }

        std::string secondLine;
        std::getline(myReadFile, secondLine);
        iss.clear();
        iss.str(secondLine);
        arraySize = 4;

         while (iss >> value)
        {
            //Expand array if no space left
            if(numCoords2 == arraySize) 
            {
                double *tempArray = new double[arraySize * 2];
                for(int i = 0; i < arraySize; i++)
                {
                    tempArray[i] = shape2[i];
                }
                arraySize = arraySize * 2;
                delete [] shape2;
                shape2 = tempArray; 
                tempArray = nullptr;
            }
            shape2[numCoords2] = value;
            numCoords2++;
        }
        //The condition will evaluate to true if the attempted file operation failed and it was not the end of the file
        if (iss.fail() && !(iss.eof()))
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

    double *xCoord1 = new double[numCoords1/2];
    double *yCoord1 = new double[numCoords1/2];

//Storing the x and y coords in seperate arrays
    for(int count = 0; count < numCoords1; count++) 
    {
        int coordIndex = (count / 2);
        if(count % 2 == 0)
            xCoord1[coordIndex] = shape1[count];
        else
            yCoord1[coordIndex] = shape1[count];
    }

    double *xCoord2 = new double[numCoords2/2];
    double *yCoord2 = new double[numCoords2/2];

    for(int count = 0; count < numCoords2; count++) 
    {
        int coordIndex = (count / 2);
        if(count % 2 == 0)
            xCoord2[coordIndex] = shape2[count];
        else
            yCoord2[coordIndex] = shape2[count];
    }

    if(numCoords1 == 0 || numCoords1 % 2 == 1)
    {
        std::cout << "That is not a shape.." << std::endl;
        exit(EXIT_FAILURE);
    }    
        
    if(numCoords2 == 0 || numCoords2 % 2 == 1)
    {
        std::cout << "That is not a shape.." << std::endl;
        exit(EXIT_FAILURE);
    }

    Shape &firstShape = getShape(numCoords1, xCoord1, yCoord1);
    Shape &secondShape = getShape(numCoords2, xCoord2, yCoord2);

    Shape &combinedShapes = firstShape + secondShape;

    double area = combinedShapes.area();
    double roundedArea = round(area * 1000) / 1000.0;

    std::cout << roundedArea << std::endl;


    std::getchar();

    return 0;

}


