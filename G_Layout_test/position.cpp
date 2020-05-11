#include "position.h"

Position::Position()
{

}

Position::Position(int pos_x, int pos_y)
{
    x = pos_x;
    y = pos_y;
}

Position::~Position()
{

}

void Position ::set(int pos_x,int pos_y)
{
    x = pos_x;
    y = pos_y;
}



QPointF Position::Pos_PointF(int pos_x,int pos_y)
{
    x = pos_x;
    y = pos_y;

    imagePos = QPointF(x,y);

    return imagePos;
}

int Position::Pos_Raw(int pos_x, int pos_y)
{
    x = pos_x;
    y = pos_y;

    return x,y;
}
