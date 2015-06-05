#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>

class pieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit pieChartWidget(QWidget *parent = 0);
    void setOccurence(float *);
private:
	float * rangeOccurence;
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:

};

#endif // PIECHARTWIDGET_H
