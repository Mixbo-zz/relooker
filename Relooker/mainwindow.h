#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "fichier.h"
#include "twodimension.h"
#include "algo.h"
class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_verticalTabsList_itemClicked(QListWidgetItem *item);
    void on_verticalTabsList_currentRowChanged(int currentRow);
    void cleanInfos();
    void loadBinary(QString filename);
    void colorExplainInit();
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();
    void on_comboBox_mode_currentIndexChanged(int index);
    void on_checkBox_strings_toggled(bool checked);
    void on_comboBox_algo_currentIndexChanged(int index);

    void saveFile();
    void on_saveButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_listWidget_currentRowChanged(int currentRow);

public slots:
    void update_hex_view();

private:
    void setHexEditor();
    Ui::MainWindow *ui;
    Fichier *binaire;
    TwoDimension* tdim; // The Two Dimension Representation (with multiple algorithms)
};

#endif // MAINWINDOW_H
