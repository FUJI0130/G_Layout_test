#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>
#include <QPixmap>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qdebug.h>
#include "graph_widget.h"
#include "layout_test_Item.h"
#include "custom_linearlayout.h"


class Graph_Widget;
class custom_LinearLayout;
class Layout_test_Item;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    Graph_Widget *Graph_Widgets;
    Graph_Widget *Graph_Widgets2;

private:
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QGraphicsScene *scene3;
    QGraphicsScene *scene4;

public:
    int check_x;
    int check_y;
    int check_w;
    int check_h;

    int check_x2;
    int check_y2;
    int check_x4;
    int check_y4;

private:
    //custom_LinearLayout *cus_Linear;
    //Layout_test_Item *test_Item;




protected:
    void showEvent(QShowEvent *event);

    /*
private:
    QGraphicsLinearLayout *windowLayout;
    QGraphicsLinearLayout *linear;

    QPixmap test1;

public:
    Layout_test_Item *Item;
*/

};

#endif // MAINWINDOW_H
