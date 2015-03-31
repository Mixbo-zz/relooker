#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QScrollBar>
#include <QMessageBox>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->binaire = NULL;
    this->tdim = new TwoDimension();
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
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"./","All Files (*)");
    if(!filename.isEmpty())
    {
        QString title = "RElooker - "+filename; // Include filename in window's title
        this->setWindowTitle(title);

        this->binaire = new Fichier(filename.toUtf8().constData()); // Create the Fichier Instance
	    int size = binaire->getSize();

        ui->comboBox_mode->setCurrentIndex(0); // Initialize settings
        ui->comboBox_algo->setCurrentIndex(0);

        ui->labelNameValue->setText(filename);  // Display basic stats
	    ui->labelSizeValue->setText(QString::number(size)+" Bytes");

        this->tdim->setContent(this->binaire->getContent(),size); // Give a pointer of file to the 2dimentional representation and hex
        ui->hexVisuWidget->setContent(binaire->getContent(),size);

        ui->visuWidget->set2(tdim); // Set tdim as the 2dimentional representation of file
        ui->visuWidget->setMode(1); // initialize mode to range

        QSize sizeScroll = QSize(ui->scrollArea->width(),ui->visuWidget->getHeight()); // Resize the scroll area to show the scrollbar
        ui->scrollAreaWidgetContents->resize(sizeScroll);

        this->setHexEditor();

        ui->visuWidget->update();

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update_hex_view())); // Refresh hex view every 100ms
        timer->start(100);
    }
}
void MainWindow::setHexEditor()
{
    connect(ui->hexEditWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->hexEditAsciiWidget->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->hexEditAsciiWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->hexEditWidget->verticalScrollBar(), SLOT(setValue(int)));
    ui->hexEditWidget->setColumnCount(16);
    ui->hexEditAsciiWidget->setColumnCount(16);

    for(int i=0;i<16;++i)
        ui->hexEditWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(i,16).toUpper()));
    for(int i=0;i<16;++i)
        ui->hexEditAsciiWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(i,16).toUpper()));

    ui->hexEditWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->hexEditAsciiWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    int hexEditorSize = this->binaire->getSize()/16;
    if (this->binaire->getSize()%16 != 0)
        ++hexEditorSize;
    ui->hexEditWidget->setRowCount(hexEditorSize);
    ui->hexEditAsciiWidget->setRowCount(hexEditorSize);



    QString hexValue;
    QString charValue;
    QString hexAddress;

    QFont fnt;
    fnt.setPixelSize(10);

    int baseIndex = ui->visuWidget->getIndex();
    int characterInt;


    int num = QString::number(hexEditorSize,16).toUpper().size();
    int diff = 0;

    for(int j=0;j<hexEditorSize;++j)
    {
        hexAddress = QString::number(j*16,16).toUpper();
        diff = num-hexAddress.size();
        for(int i=0;i<diff;++i)
            hexAddress = "0"+hexAddress;
        ui->hexEditWidget->setVerticalHeaderItem(j, new QTableWidgetItem(hexAddress));
        ui->hexEditAsciiWidget->setVerticalHeaderItem(j, new QTableWidgetItem(""));

        for(int i = 0;i<16;++i)
        {
            if(i+j*16 < this->binaire->getSize())
            {
                characterInt = (int)(unsigned char)this->binaire->getContent()[baseIndex+j*16+i]; // The read character as a number

                if(characterInt == 9 || characterInt == 10 || characterInt == 13 ||(characterInt >= 32 && characterInt <= 127)) // If ASCII
                {
                    charValue = this->binaire->getContent()[baseIndex+j*16+i]; // Display Character instead of "."
                }
                else
                    charValue = ".";

                hexValue = QString::number( characterInt ,16).toUpper(); // Converted to hex
                if (hexValue.size() == 1)
                    hexValue = "0"+hexValue;

                ui->hexEditWidget->setItem(j,i,new QTableWidgetItem(hexValue));
                ui->hexEditAsciiWidget->setItem(j,i,new QTableWidgetItem(charValue));

                ui->hexEditWidget->item(j,i)->setFont(fnt);
            }
        }
    }

    ui->hexEditWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->hexEditAsciiWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,
                             tr("RElooker"),
                             tr("Created by Alex Bouffard\nhttps://www.github.com/mixbo/relooker")
                             );
}

void MainWindow::update_hex_view()
{
    //cout << "Updating hex" << endl;
    ui->hexVisuWidget->setIndex(ui->visuWidget->getIndex()); // Give the last cursor position on 2d to hex
}

void MainWindow::on_comboBox_mode_currentIndexChanged(int index)
{
    ui->stackedView->setCurrentIndex(index); // Changed representation (2d/3d) -> select stacked frame
}

void MainWindow::on_checkBox_strings_toggled(bool checked)
{
    ui->hexVisuWidget->highlight(checked); // Highlight strings if checked
}

void MainWindow::on_comboBox_algo_currentIndexChanged(int index)
{
    if(index > 0)
    {
        QMessageBox::information(this,
                             tr("RElooker"),
                             tr("Missing Feature")
                             );
  
    } 
    else
        ui->visuWidget->setMode(index+1); // Set mode to the combo box index+1 because why not
}
