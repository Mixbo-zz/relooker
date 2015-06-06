#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
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
    void createPixmap();

    //QImage im;
    QPixmap im;

protected:
    void paintEvent(QPaintEvent *);
private:
    int mode; // The algorithm to use in representation
    int itemsCol; // Number of items per column -> Ghettoed to 16
    int itemSize; // Size of each dots -> Ghettoed to 5
    int mousey;
    int index; // Where the cursor is
    TwoDimension* tdim; // 2dimensions representation of file

    void paintDefault();
    void paintTwoD(); // display the 2 dimensions representation with the algorithm this->mode
signals:
    
public slots:
    
};

#endif // VISUALIZER_H
