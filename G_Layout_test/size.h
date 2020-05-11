#ifndef SIZE_H
#define SIZE_H

#include <QDebug>

class Size
{
public:
    int w;
    int h;
public:
    explicit Size();
    ~Size();
    Size(int width,int height);
    void set(int width,int height);

};

#endif // SIZE_H
