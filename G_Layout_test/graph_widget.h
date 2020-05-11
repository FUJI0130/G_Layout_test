#ifndef GRAPH_WIDGET_H
#define GRAPH_WIDGET_H

#include "layout_test_Item.h"
#include <QGraphicsWidget>

#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>
#include <QImage>
#include "layout_test_Item.h"


class Layout_test_Item;

class Graph_Widget :public QGraphicsWidget
{
    Q_OBJECT
public:
    Graph_Widget(QGraphicsWidget *parent = nullptr);

    /*
public:
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
*/




public:
    Layout_test_Item *Item;

public:
    int View_width = 0;
    int View_height = 0;

    void set_Item();

public:
    QGraphicsLinearLayout *windowLayout;
    QGraphicsLinearLayout *linear;

    QPixmap test1;

private:
    QRectF geom_test;

};

#endif // GRAPH_WIDGET_H
