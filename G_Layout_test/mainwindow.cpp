#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->show();
    check_w = 0;
    check_h = 0;
    check_w = ui->graphicsView->width();
    check_h = ui->graphicsView->height();

    qDebug("check_w: %d\n",check_w);
    qDebug("check_h : %d\n",check_h);

    scene = new QGraphicsScene();
    Graph_Widgets = new Graph_Widget;

    ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop);

    Graph_Widgets->View_width = check_w;
    Graph_Widgets->View_height = check_h;

    Graph_Widgets->set_Item();

    scene->addItem(Graph_Widgets);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->repaint();



    scene2 = new QGraphicsScene();
    Graph_Widgets2 = new Graph_Widget;

    ui->graphicsView_2->setAlignment(Qt::AlignLeft|Qt::AlignBottom);
    ui->graphicsView_2->setBackgroundBrush(Qt::black);
    ui->graphicsView_2->setFrameStyle(QFrame::NoFrame);
    ui->graphicsView_2->setContentsMargins(0,0,0,0);
    check_x2 = ui->graphicsView_2->x();
    check_y2 = ui->graphicsView_2->y();
    //ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QRect ref_Rect2 = QRect((qreal)check_x2,(qreal)check_y2,(qreal)check_w,(qreal)check_h);
    ui->graphicsView_2->setGeometry(ref_Rect2);
    scene2->setSceneRect(0,0,(qreal)check_w,(qreal)check_h);
    ui->graphicsView_2->setScene(scene2);



    Graph_Widgets2->View_width = check_w;
    Graph_Widgets2->View_height = check_h;
    Graph_Widgets2->setContentsMargins(0,0,0,0);
    Graph_Widgets2->setWindowFrameMargins(0,0,0,0);
    Graph_Widgets2->set_Item();
    scene2->addItem(Graph_Widgets2);


    qDebug("Graph_Widgets->View_width : %d\n",Graph_Widgets->View_width);
    qDebug("Graph_Widgets->View_height : %d\n",Graph_Widgets->View_height);
    //qDebug("check_w :%3.2lf\n",(qreal)check_w);
    //qDebug("check_h :%3.2lf\n",(qreal)check_h);

    ui->graphicsView_2->show();


    scene3 = new QGraphicsScene();

    check_x = ui->graphicsView_3->x();
    check_y = ui->graphicsView_3->y();

    QRect ref_Rect = QRect((qreal)check_x,(qreal)check_y,(qreal)check_w,(qreal)check_h);
    //ui->graphicsView_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_3->setGeometry(ref_Rect);
    ui->graphicsView_3->setBackgroundBrush(Qt::blue);
    ui->graphicsView_3->setContentsMargins(0,0,0,0);
    //ui->graphicsView_3->setAlignment(Qt::AlignLeft|Qt::AlignBottom);

    //これ必須っぽい。(消すと画像表示しない)
    scene3->setSceneRect(0,0,(qreal)check_w,(qreal)check_h);
    ui->graphicsView_3->setScene(scene3);
    QRectF sceneRect = ui->graphicsView_3->sceneRect();

     QPixmap pixmap = QPixmap("/home/pi/G_Layout_test/nukiro.jpeg");
     qDebug("sceneRect.width(): %3.2lf\n",sceneRect.width());
    pixmap = pixmap.scaledToWidth(sceneRect.width());
    QGraphicsPixmapItem* pPixmap = new QGraphicsPixmapItem();
    pPixmap->setPixmap(pixmap);
    scene3->addItem(pPixmap);


    //ui->graphicsView_3->fitInView(pPixmap);
    //ui->graphicsView_3->show();
    qDebug("graphicsView3-show after");




    qDebug("Graph_Widgets->View_width : %d\n",Graph_Widgets->View_width);
    qDebug("Graph_Widgets->View_height : %d\n",Graph_Widgets->View_height);
    //qDebug("check_w :%3.2lf\n",(qreal)check_w);
    //qDebug("check_h :%3.2lf\n",(qreal)check_h);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    qDebug("showEvent\n");
    //ui->graphicsView_2->fitInView(scene2->sceneRect(),Qt::KeepAspectRatio);
    //ui->graphicsView_3->fitInView(scene3->sceneRect(),Qt::KeepAspectRatio);
    ui->graphicsView_2->show();
    ui->graphicsView_3->show();
    ui->graphicsView_4->show();
}
