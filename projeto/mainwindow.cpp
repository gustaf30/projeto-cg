#include "mainwindow.h"
#include <QVBoxLayout>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    areaDesenho = new AreaDesenho;

    botaoDesenhar = new QPushButton("Desenhar Ponto", this);
    botaoDesenharLinha = new QPushButton("Desenhar Linha", this);
    botaoDesenharQuadrado = new QPushButton("Desenhar Quadrado", this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(botaoDesenhar);
    layout->addWidget(botaoDesenharLinha);
    layout->addWidget(botaoDesenharQuadrado);
    layout->addWidget(areaDesenho);

    setCentralWidget(centralWidget);

    connect(botaoDesenhar, &QPushButton::clicked, this, &MainWindow::desenharObjeto);
    connect(botaoDesenharLinha, &QPushButton::clicked, this, &MainWindow::desenharLinha);
    connect(botaoDesenharQuadrado, &QPushButton::clicked, this, &MainWindow::desenharQuadrado);
}

void MainWindow::desenharObjeto() {
    std::shared_ptr<PontoObjeto> ponto = std::make_shared<PontoObjeto>("Ponto", Ponto(200, 200));
    areaDesenho->adicionarObjeto(ponto);
}

void MainWindow::desenharLinha() {
    std::shared_ptr<RetaObjeto> reta = std::make_shared<RetaObjeto>("Reta", Ponto(100, 100), Ponto(300, 300));
    areaDesenho->adicionarObjeto(reta);
}

void MainWindow::desenharQuadrado() {
    std::vector<Ponto> quadradoPontos = {
        Ponto(100, 100),
        Ponto(200, 100),
        Ponto(200, 200),
        Ponto(100, 200)
    };
    std::shared_ptr<PoligonoObjeto> quadrado = std::make_shared<PoligonoObjeto>("Quadrado", quadradoPontos);
    areaDesenho->adicionarObjeto(quadrado);
}
