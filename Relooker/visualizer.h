#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QWidget>
#include <QMouseEvent>
#include "twodimension.h"

class Visualizer : public QWidget
{
    Q_OBJECT
public:
    explicit Visualizer(QWidget *parent = 0);
    void setMode(int);
    virtual void mouseMoveEvent(QMouseEvent*);
    void set2(TwoDimension*);
    int getHeight();
    int getIndex();
protected:
    void paintEvent(QPaintEvent *);
private:
    int mode;
    int itemsCol;
    int itemSize;
    int index;
    TwoDimension* tdim;

    void paintDefault();
    void paintTwoD();
signals:
    
public slots:
    
};

#endif // VISUALIZER_H
