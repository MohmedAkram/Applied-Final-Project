#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap(":/Background1/Screenshot 2024-11-25 at 7.31.06 PM.png");
    backgroundLabel->setPixmap(backgroundPixmap);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->resize(this->size());
    backgroundLabel->lower();
}

MainWindow::~MainWindow()
{
    delete ui;
}
