#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "areadesenho.h"
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    AreaDesenho *areaDesenho;
    QPushButton *botaoDesenhar;
    QPushButton *botaoDesenharLinha;
    QPushButton *botaoDesenharQuadrado;

private slots:
    void desenharObjeto();
    void desenharLinha();
    void desenharQuadrado();

public:
    MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H
