#include "Shape.h"
#include <string>
#include <cmath>


double Shape::area()
{
    int invalidArea = -1;
    return invalidArea;
}

double Shape::circumference()
{
    int invalidCircumference = -1;
    return invalidCircumference;
}

bool Shape::isConvex()
{
    return false;
}

double Shape::distance(Shape* s)
{
    //Our position
    ObjectPosition thisObject = position();
    //Their position
    ObjectPosition otherObject = s->position();

    double xDifference = pow(thisObject.x - otherObject.x, 2);
    double yDifference = pow(thisObject.y - otherObject.y, 2);
    double distance = sqrt(xDifference + yDifference);

    return distance;
}

Shape::~Shape()
{
    delete [] xCoord;
    xCoord = nullptr;
    delete [] yCoord;
    yCoord = nullptr;
}
