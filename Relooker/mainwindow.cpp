#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalTabsList_itemClicked(QListWidgetItem *item)
{
    int index = item->listWidget()->row( item );
    ui->stackedEditor->setCurrentIndex(index);
}

void MainWindow::on_verticalTabsList_currentRowChanged(int currentRow)
{
    ui->stackedEditor->setCurrentIndex(currentRow);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"./","All Files (*.*)");
    if(!filename.isEmpty())
    {
        binaire = new Fichier(filename.toUtf8().constData());
	    unsigned int size = binaire->getSize();

	    ui->labelNameValue->setText(filename);
	    ui->labelSizeValue->setText(QString::number(size)+" Bytes");

        tdim = new TwoDimension(binaire->getContent(),size);

        ui->visuWidget->set2(tdim);
        ui->visuWidget->setMode(1);

        QSize sizeScroll = QSize(ui->scrollArea->width(),ui->visuWidget->height());
        ui->scrollAreaWidgetContents->resize(sizeScroll);

        ui->visuWidget->update();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,
                             tr("RElooker"),
                             tr("Created by Alex Bouffard\nhttps://www.github.com/mixbo/relooker")
                             );
}
