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
    areaDesenho->setMinimumSize(500, 500);
    if (ui->areaContainer->layout()) {
        ui->areaContainer->layout()->addWidget(areaDesenho);
    } else {
        QVBoxLayout *layout = new QVBoxLayout(ui->areaContainer);
        layout->addWidget(areaDesenho);
        ui->areaContainer->setLayout(layout);
    }
    connect(ui->rotacaoTriangulo, &QPushButton::clicked, this, &MainWindow::on_rotacaoTrianguloPushButton_clicked);
    connect(ui->rotacaoQuadrado, &QPushButton::clicked, this, &MainWindow::on_rotacaoQuadradoPushButton_clicked);
    connect(ui->rotacaoReta, &QPushButton::clicked, this, &MainWindow::on_rotacaoRetaPushButton_clicked);

    connect(ui->escalaTriangulo, &QPushButton::clicked, this, &MainWindow::on_escalaTrianguloPushButton_clicked);
    connect(ui->escalaQuadrado, &QPushButton::clicked, this, &MainWindow::on_escalaQuadradoPushButton_clicked);
    connect(ui->escalaReta, &QPushButton::clicked, this, &MainWindow::on_escalaRetaPushButton_clicked);

    connect(ui->translacaoTriangulo, &QPushButton::clicked, this, &MainWindow::on_translacaoTrianguloPushButton_clicked);
    connect(ui->translacaoQuadrado, &QPushButton::clicked, this, &MainWindow::on_translacaoQuadradoPushButton_clicked);
    connect(ui->translacaoReta, &QPushButton::clicked, this, &MainWindow::on_translacaoRetaPushButton_clicked);
    connect(ui->coordenadaX, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_CoordenadaX_valueChanged);
    connect(ui->coordenadaY, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_CoordenadaY_valueChanged);


}
void MainWindow::on_CoordenadaX_valueChanged(int arg1)
{
    cx = arg1;
}
void MainWindow::on_CoordenadaY_valueChanged(int arg1)
{
    cy = arg1;
}

void MainWindow::on_rotacaoTrianguloPushButton_clicked()
{
    aplicarMudancaAoObjeto(2, 3);
}
void MainWindow::on_rotacaoQuadradoPushButton_clicked()
{
    aplicarMudancaAoObjeto(3, 3);
}
void MainWindow::on_rotacaoRetaPushButton_clicked()
{
aplicarMudancaAoObjeto(1, 3);
}
void MainWindow::on_escalaTrianguloPushButton_clicked()
{
aplicarMudancaAoObjeto(2, 2);
}
void MainWindow::on_escalaQuadradoPushButton_clicked()
{
aplicarMudancaAoObjeto(3, 2);
}
void MainWindow::on_escalaRetaPushButton_clicked()
{
aplicarMudancaAoObjeto(1, 2);
}
void MainWindow::on_translacaoTrianguloPushButton_clicked()
{
    aplicarMudancaAoObjeto(2, 1);
}
void MainWindow::on_translacaoQuadradoPushButton_clicked()
{
    aplicarMudancaAoObjeto(3, 1);
}
void MainWindow::on_translacaoRetaPushButton_clicked()
{
    aplicarMudancaAoObjeto(1, 1);
}
void MainWindow::aplicarMudancaAoObjeto(int indiceObjeto, int tipoTransformacao) {

    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");

    if (areaDesenho) {
        qDebug() << "Tamanho de displayFile:" << areaDesenho->displayFile.size();

        if (indiceObjeto < areaDesenho->displayFile.size()) {
            Objeto& objeto = areaDesenho->displayFile[indiceObjeto];

            Matriz matrizMudanca(3, 3);
            //double cx = objeto.calculaCentroX();
            //double cy = objeto.calculaCentroY();
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
