#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QWidget>
#include "twodimension.h"

class Visualizer : public QWidget
{
    Q_OBJECT
public:
    explicit Visualizer(QWidget *parent = 0);
    void setMode(int);
    void set2(TwoDimension*);
protected:
    void paintEvent(QPaintEvent *);
private:
    int mode;
    TwoDimension* tdim;

    void paintDefault();
    void paintTwoD();
signals:
    
public slots:
    
};

#endif // VISUALIZER_H
