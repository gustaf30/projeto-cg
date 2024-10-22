#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadesenho.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AreaDesenho *areaDesenho = new AreaDesenho(this);
    setCentralWidget(areaDesenho);
}

MainWindow::~MainWindow()
{
    delete ui;
}
