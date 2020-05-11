#include "image.h"

Image::Image()
{
    SIZE = new Size();
    POS = new Position();
    //IMG_Init();
}
Image::Image(QImage &img, Size *size, Position *pos)
{
    add_Img = img;

    SIZE = new Size(0,0);
    POS = new Position(0,0);

    SIZE = size;
    POS = pos;
}

Image::~Image()
{
    delete SIZE;
    delete POS;
}



void Image::Image_Init(QImage &img, int width,int height,int x, int y)
{
    add_Img = img;
    SIZE->set(width,height);
    POS->set(x,y);
    Image_Pixmap(img);
}




void Image::Image_Pixmap(QImage &img)
{    
    pixmap = QPixmap::fromImage(img);
}


QGraphicsPixmapItem Image::Image_setPos(QGraphicsPixmapItem &img_item)
{
    Imageitem = img_item;
    Imageitem->setPos(POS->Pos_PointF(POS->x,POS->y));
    return &Imageitem;
}

/*
Image1::Image1(QImage img1, Size size1, Position pos1)
    :Image(img1,size1,pos1)
{
    //IMG_Init();
}

Image2::Image2(QImage img2, Size size2, Position pos2)
    :Image(img2,size2,pos2)
{
    //IMG_Init();
}
*/
