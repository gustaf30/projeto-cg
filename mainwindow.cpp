#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadesenho.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AreaDesenho *areaDesenho = new AreaDesenho(this);
    areaDesenho->setObjectName("areaDesenho");
    setCentralWidget(areaDesenho);

    aplicarMudancaAoObjeto(5, 3);

    areaDesenho->update();
}


void MainWindow::aplicarMudancaAoObjeto(int indiceObjeto, int tipoTransformacao) {

    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");

    if (areaDesenho) {
        qDebug() << "Tamanho de displayFile:" << areaDesenho->displayFile.size();

        if (indiceObjeto < areaDesenho->displayFile.size()) {
            Objeto& objeto = areaDesenho->displayFile[indiceObjeto];

            Matriz matrizMudanca(3, 3);
            double cx = objeto.calculaCentroX();
            double cy = objeto.calculaCentroY();
            switch(tipoTransformacao) {
            case 1:
                matrizMudanca = matrizMudanca.translacao();
                break;
            case 2:
                matrizMudanca = matrizMudanca.escala();
                break;
            case 3:
                matrizMudanca = matrizMudanca.rotacao(cx, cy);
                break;
            default:
                qDebug() << "Tipo de transformação inválido.";
                return;
            }

            for (Ponto& ponto : objeto.pontos) {
                Matriz pontoMatriz(3, 1);
                pontoMatriz(0, 0) = ponto.x();
                pontoMatriz(1, 0) = ponto.y();
                pontoMatriz(2, 0) = 1;

                pontoMatriz = matrizMudanca * pontoMatriz;

                ponto.setX(pontoMatriz(0, 0));
                ponto.setY(pontoMatriz(1, 0));
            }

            areaDesenho->update();
        } else {
            qDebug() << "Índice do objeto fora dos limites: " << indiceObjeto;
        }
    } else {
        qDebug() << "ÁreaDesenho não encontrada.";
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
