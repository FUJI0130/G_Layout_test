#include "layout_test_Item.h"

Layout_test_Item::Layout_test_Item(QGraphicsItem *parent)
      :QGraphicsLayoutItem(),QGraphicsItem(parent)
{
    View_width = 0;
    View_height = 0;
    setGraphicsItem(this);
}


void Layout_test_Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
    QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    QRectF frame(QPointF(0, 0), geometry().size());

    double geom_width = frame.width();
    double geom_height = frame.height();
    double geom_pos_right = frame.right();
    double geom_pos_left = frame.left();

    qDebug("geom_width : %3.2lf\n",geom_width);
    qDebug("geom_height : %3.2lf\n",geom_height);
    qDebug("geom_pos_right : %3.2lf\n",geom_pos_right);
    qDebug("geom_pos_left: %3.2lf\n",geom_pos_left);

    QPointF pixpos = QPointF(0,0);
    painter->drawPixmap(pixpos, PXMP);

}

QRectF Layout_test_Item::boundingRect() const
{
    qDebug("boundingRect\n");
    return QRectF(QPointF(0, 0), geometry().size());
    //return QRectF(QPointF(0, 0), QSizeF(0,0));
}

void Layout_test_Item::setGeometry(const QRectF &geom)
{    
    qDebug("setGeometry\n");
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);

    setPos(geom.topLeft());
}


QSizeF Layout_test_Item::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    qDebug("sizeHint\n");
    int PXMP_width = PXMP.width();
    int PXMP_height = PXMP.height();

    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:        
        qDebug("checkPXMP width : %d",PXMP_width);
        qDebug("checkPXMP height : %d",PXMP_height);
        return PXMP.size();        
    case Qt::MaximumSize:              
        return QSizeF(1000, 1000);
    default:
        break;
    }
    return constraint;
}


void  Layout_test_Item::set_Pixmap(QPixmap pxmp , int width , int height)
{
    PXMP = pxmp;
    View_width = width;
    View_height = height;
    PXMP = PXMP.scaledToWidth(View_width,Qt::FastTransformation);
    //PXMP = PXMP.scaled(300,View_height,Qt::KeepAspectRatio,Qt::FastTransformation);
    qDebug("View_width(set_Pixmap) : %d\n",View_width);
}

/*
void Layout_test_Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
    QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    //■■■■ジオメトリのサイズ調べるために、qrealをintに変更したいので調査。　QPointFの toPointが使えるかどうか20200508
//■■ ここで、Viewのセンターの位置を導いて、画像の位置を調整する方法調べる20200507
    QRectF frame(QPointF(0, 0), geometry().size());
    //☆ピックスマップのサイズが、ここで決まってる。
    //View内の
    //frame.setSize(QSizeF(220,129));

    double geom_width = frame.width();
    double geom_height = frame.height();
    double geom_pos_right = frame.right();
    double geom_pos_left = frame.left();

    qDebug("geom_width : %3.2lf\n",geom_width);
    qDebug("geom_height : %3.2lf\n",geom_height);
    qDebug("geom_pos_right : %3.2lf\n",geom_pos_right);
    qDebug("geom_pos_left: %3.2lf\n",geom_pos_left);


    const QSize pmSize = PXMP.size();
    //QPointF pixpos = frame.center() - (QPointF(pmSize.width(), pmSize.height()) / 2);
    //QPointF pixpos = QPointF(-50,0);

    qDebug("View_width(l_test_Item) : %d\n",View_width);
    //PXMP.scaledToWidth(View_width,Qt::FastTransformation);
    painter->drawPixmap(pixpos, PXMP);
    qDebug("Paint/n");
}
QRectF Layout_test_Item::boundingRect() const
{
    qDebug("boundingRect/n");
    //QRectF・・・長方形の位置とサイズを定義する。
    //つまり、このboudingRectでは、境界のサイズの長方形の位置とサイズを定義。
    //QRectF(x,y,width,height)
    //geometryはGraphicsLayout_test_Itemの関数
    //ここで指すgeometryはsetgeometry関数を使って定義している
    //setgeometry関数は、GraphicsLayoutItemからの継承。
    return QRectF(QPointF(0, 0), geometry().size());
}

void Layout_test_Item::setGeometry(const QRectF &geom)
{
    qDebug("setGeometry/n");
    //prepareGeometryChange・・・ジオメトリ変更のためにアイテムを準備する・・・？
    //boundingRectを呼び出す前に、呼び出しとく・・・？
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    //int check_w = geom.width();
    //int check_h = geom.height();
    // qDebug("Geometry_width : %d/n",check_w);//231
    // qDebug("Geometry_height : %d/n",check_h);//129

    //上、左寄せ？
    setPos(geom.topLeft());
}

//QGraphicsLayoutItem の出力サイズの制約に使う？
QSizeF Layout_test_Item::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        qDebug("SizeHint/n");
        //フレームの大きさがpixmapより小さくならないように設定する？？
        // Do not allow a size smaller than the pixmap with two frames around it.
        //PXMP = PXMP.scaledToWidth(View_width,Qt::FastTransformation);
        return PXMP.size();
        //return PXMP.size() + QSize(12, 12);
    case Qt::MaximumSize:
        return QSizeF(1000, 1000);
    default:
        break;
    }
    return constraint;
}

//void  Layout_test_Item::set_Pixmap(QPixmap pxmp)
void  Layout_test_Item::set_Pixmap(QPixmap pxmp , int width , int height)
{
    PXMP = pxmp;
    View_width = width;
    View_height = height;
    PXMP = PXMP.scaledToWidth(View_width,Qt::FastTransformation);
    qDebug("View_width(set_Pixmap) : %d\n",View_width);

}

*/
