#ifndef HEXVISU_H
#define HEXVISU_H

#include <QWidget>

class HexVisu : public QWidget
{
    Q_OBJECT
public:
    explicit HexVisu(QWidget *parent = 0);
    void setContent(char*,int);
    void highlight(bool);    // Highlight Strings
protected:
    void paintEvent(QPaintEvent *);
private:
    int index; // Value hovered by cursor
    int size;
    char* content;
    bool isHighlight;
signals:

public slots:
    void setIndex(int);
};

#endif // HEXVISU_H
