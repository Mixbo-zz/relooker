#ifndef HEXVISU_H
#define HEXVISU_H

#include <QWidget>

class HexVisu : public QWidget
{
    Q_OBJECT
public:
    explicit HexVisu(QWidget *parent = 0);
    void setContent(char*,int);
protected:
    void paintEvent(QPaintEvent *);
private:
    int index;
    int size;
    char* content;
signals:

public slots:
    void setIndex(int);
};

#endif // HEXVISU_H
