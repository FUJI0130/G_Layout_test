#ifndef CUSTOM_LINEARLAYOUT_H
#define CUSTOM_LINEARLAYOUT_H
#include <QGraphicsLinearLayout>
#include <QGraphicsItem>

class custom_LinearLayout : public QGraphicsLinearLayout, public QGraphicsItem
{
public:
    custom_LinearLayout(QGraphicsLayoutItem *parent = Q_NULLPTR);
    ~custom_LinearLayout();

    //~QGraphicsLinearLayout();

};

#endif // CUSTOM_LINEARLAYOUT_H
