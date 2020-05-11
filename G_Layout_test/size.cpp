#include "size.h"

Size::Size()
{
    qDebug("Size Default Constructor\n");
    w =0;
    h = 0;
}

Size::Size(int width, int height)
{
    qDebug("Size argument Constructor\n");

    w = width;
    h = height;
}
void Size::set(int width,int height)
{
    w = width;
    h = height;
}

Size::~Size()
{

}
