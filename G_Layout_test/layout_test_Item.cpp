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
