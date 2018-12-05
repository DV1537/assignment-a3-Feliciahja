#include "Functions.h"

//Determining the shape by comparing the number of coords read in from file
Shape& getShape(int numCoords, double *xCoord, double *yCoord)
{
    Shape* s;
    int vertices = (numCoords / 2);

    if(numCoords > 6)
    {
        s = new Polygon(xCoord, yCoord, vertices);
        
    }
    else if(numCoords == 6)
    {
        s = new Triangle(xCoord, yCoord, vertices);

    }
    else if(numCoords == 4)
    {
        s = new Line(xCoord, yCoord, vertices);

    }
    else if(numCoords == 2) 
    {
        s = new Point(xCoord, yCoord, vertices);
    }
    return *s;
}