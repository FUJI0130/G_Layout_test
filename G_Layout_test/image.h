#ifndef IMAGE_H
#define IMAGE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QImage>
#include <QPixmap>
#include <QPointF>


#include <position.h>
#include <size.h>


//class Img_Pxmp;
class Position;
class Size;

class Image
{    
public:
    QImage add_Img;
    Size *SIZE;
    Position *POS;

public:
    explicit Image();
     ~Image();
    Image(QImage &img,Size *size,Position *pos);


    int flag;
    QPixmap pixmap;    
    void Image_Init(QImage &img, int width,int height,int x, int y);

    QGraphicsPixmapItem *Imageitem;

    QGraphicsPixmapItem Image_setPos(QGraphicsPixmapItem *img_item);

private:
    void Image_Pixmap(QImage &img);


/*
    QGraphicsScene IMG(QGraphicsScene *scene);

private:
    QGraphicsScene *scene;    
    QPixmap *pixmap;
    QGraphicsPixmapItem *imageItem;
    QPointF *imagePos;

    Img_Pxmp *PXMP;
    Position *POS;
    void IMG_Init();
*/
};
/*
class Image1 :public Image
{
public:
    //Image1();
    Image1(QImage img1, Size size1, Position pos1) : Image(img1,size1,pos1){}
};

class Image2 :public Image
{
public:
    Image2(QImage img2, Size size2, Position pos2) : Image(img2,size2,pos2){}
};
*/

#endif // IMAGE_H
