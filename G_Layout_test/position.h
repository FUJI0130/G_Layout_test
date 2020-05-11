#ifndef POSITION_H
#define POSITION_H
#include <QPointF>

class Position
{
public:
    int x;
    int y;

public:
    explicit Position();
    ~Position();
    Position(int pos_x,int pos_y);
    void set(int x,int y);

public:
    QPointF imagePos;

    QPointF Pos_PointF(int pos_x,int pos_y);
    int Pos_Raw(int pos_x,int pos_y);

};

#endif // POSITION_H
