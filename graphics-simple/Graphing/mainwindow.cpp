#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QVBoxLayout *mainLayOut = new QVBoxLayout;
   // mainLayOut->addItem(ui);
   // mainLayOut->setEnabled(true);

    //connect(this, SIGNAL())
    //ui->graphicsView
}

MainWindow::~MainWindow()
{
    delete ui;
}
