#ifndef LAYOUT_TEST_ITEM_H
#define LAYOUT_TEST_ITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPainter>
#include "mainwindow.h"

class MainWindow;

class Layout_test_Item : public QGraphicsLayoutItem,public QGraphicsItem//public QGraphicsPixmapItem
{
public:
    Layout_test_Item(QGraphicsItem *parent = nullptr);

    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:    
    QPixmap PXMP;

public:
    //void set_Pixmap(QPixmap pxmp);
    void set_Pixmap(QPixmap pxmp,int width,int height);

private:
    int View_width;
    int View_height;

};

#endif // LAYOUT_TEST_ITEM_H
