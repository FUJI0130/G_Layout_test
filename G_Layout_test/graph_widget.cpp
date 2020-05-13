#include "graph_widget.h"

Graph_Widget::Graph_Widget(QGraphicsWidget *parent) : QGraphicsWidget(parent, Qt::Widget)
{
     qDebug("Graph_Widget View_width : %d\n",View_width);
     qDebug("Graph_Widget View_height : %d\n",View_height);


    windowLayout = new QGraphicsLinearLayout(Qt::Vertical);
    linear = new QGraphicsLinearLayout(Qt::Vertical,windowLayout);


    Item = new Layout_test_Item;


    windowLayout->setSpacing(0.0);
    double check_space = windowLayout->spacing();
    qDebug("check_space  windowLayout : %3.2lf",check_space);

    linear->setSpacing(0.0);
    double check_space2 = linear->spacing();
    qDebug("check_space2 linearLayout : %3.2lf",check_space2);


    windowLayout->setAlignment(Item,Qt::AlignTop|Qt::AlignLeft);
    linear->setAlignment(Item,Qt::AlignTop|Qt::AlignLeft);


    //geom_test = QRectF(0,0,(qreal)View_width,(qreal)View_height);

}



void Graph_Widget::set_Item()
{
    qDebug("Graph_Widget setItem\n");
   // geom_test = QRectF(0,0,(qreal)View_width,(qreal)View_height);

    test1 = QPixmap("/home/pi/G_Layout_test/nukiro.jpeg");
    Item->set_Pixmap(test1,View_width,View_height);    
    linear->addItem(Item);
    linear->setStretchFactor(Item, 1);


    Item = new Layout_test_Item;

    //linear->setAlignment(Item,Qt::AlignRight);

    Item->set_Pixmap(QPixmap("/home/pi/G_Layout_test/nukiro.jpeg"),View_width,View_height);

    linear->addItem(Item);
    linear->setStretchFactor(Item, 1);

    windowLayout->addItem(linear);

    setLayout(windowLayout);
    setWindowTitle(tr("Basic Graphics Layouts Example"));

}
