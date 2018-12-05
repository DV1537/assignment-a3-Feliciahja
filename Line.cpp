#include "Line.h"
#include <string>


Line::Line(double *xCoord, double *yCoord, int pointCount)
{
    this -> xCoord = xCoord;
    this -> yCoord = yCoord;
    this -> pointCount = pointCount;

}

std::string Line::getType()
{
    std::string type = "Line";
    return type;
}

ObjectPosition Line::position()
{
    double centerX = (xCoord[0] + xCoord[1]) / 2;
    double centerY = (yCoord[0] + yCoord[1]) / 2;

    ObjectPosition position;
    position.x = centerX;
    position.y = centerY;

    return position; 
}

Line& Line::operator=(const Line &line)
{
    if(this == &line) 
	{	
        return *this;
	}
	
	if(pointCount > 0)
    {
        delete [] xCoord;
        delete [] yCoord;
    }
    xCoord = new double[pointCount];
    yCoord = new double[pointCount];
    
    for(int index = 0; index < pointCount; index++)
    {
        xCoord[index] = line.xCoord[index];
        yCoord[index] = line.yCoord[index];
    }
    return *this;
}

