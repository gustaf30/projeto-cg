#include "areadesenho.h"
#include <QPainter>
#include <QFrame>

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent) {

}

void AreaDesenho::paintEvent(QPaintEvent *event) {
    int i, j;

    if(displayFile.isEmpty()) {
        window.setRect(1030, 190, 500, 500);
        Objeto w;
        Ponto pw1(1030, 190), pw2(1530, 190), pw3(1530, 690), pw4(1030, 690);
        w.pontos << pw1 << pw2 << pw3 << pw4;

        Objeto p1("ponto 1", 780, 300), p2("ponto 2", 1285, 580),
            l1("linha 1", 1000, 500, 600, 700);

        displayFile << w << p1 << p2 << l1;
    }

    QFrame::paintEvent(event);
    QPainter painter(this);

    //desenha
    for(i = 1; i < displayFile.size(); i++) {
        if(displayFile[i].pontos.size() == 1) {
            painter.setPen(QPen(Qt::red, 2));
            painter.drawPoint(QPoint(displayFile[i].pontos[0].x(), displayFile[i].pontos[0].y()));
        }
        if(displayFile[i].pontos.size() == 2) {
            painter.setPen(QPen(Qt::green, 2));
            painter.drawLine(QLine(displayFile[i].pontos[0].x(), displayFile[i].pontos[0].y(), displayFile[i].pontos[1].x(), displayFile[i].pontos[1].y()));
        }
    }
}

/*
#include "meuframe.h"
#include <QPainter>
#include <QList>
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

MeuFrame::MeuFrame(QWidget *parent)
    : QFrame{parent}
{

}

void MeuFrame::paintEvent(QPaintEvent *event)
{
    int i, j;

    //definicao dos objetos
    if((displayFile).isEmpty()) {

        //definicao da window
        window.setRect(1030, 190, 500, 500);
        Objeto w;
        Ponto pw1(1030, 190), pw2(1530, 190), pw3(1530, 690), pw4(1030, 690);

        w.pontos << pw1 << pw2 << pw3 << pw4;

        Objeto ponto1(780.0, 300.0), ponto2(1285.0, 580.0), ponto3(1315.0, 580.0),
               ponto4(1275.0, 499.0), ponto5(1275.0, 446.0), ponto6(1275.0, 393.0),
               ponto7(1325.0, 499.0), ponto8(1325.0, 446.0), ponto9(1325.0, 393.0),
               ponto10(1990.0, 300.0), ponto11(2010.0, 300.0), linha1(0.0, 200.0, 2600.0, 200.0),
               linha2(225.0, 100.0, 425.0, 100.0), linha3(875.0, 100.0, 1075.0, 100.0),
               linha4(1525.0, 100.0, 1725.0, 100.0), linha5(2175.0, 100.0, 2375.0, 100.0),
               linha6(900.0, 1550.0, 1000.0, 1500.0), linha7(1000.0, 1500.0, 1100.0, 1550.0),
               linha8(1300.0, 600.0, 1300.0, 590.0), linha9(1300.0, 595.0, 1290.0, 600.0),
               linha10(1300.0, 595.0, 1310.0, 600.0), linha11(1280.0, 570.0, 1320.0, 570.0),
               linha12(1210.0, 380.0, 1260.0, 448.5), linha13(1390.0, 380.0, 1340.0, 448.5),
               linha14(1280.0, 315.0, 1280.0, 200.0), linha15(1320.0, 315.0, 1320.0, 200.0),
               linha16(2050.0, 1400.0, 2050.0, 1650.0), linha17(2000.0, 1450.0, 2100.0, 1450.0),
               linha18(2000.0, 1600.0, 2100.0, 1600.0), triangulo1(800.0, 900.0, 600.0, 600.0, 1000.0, 600.0),
               retangulo1(600.0, 600.0, 1000.0, 600.0, 1000.0, 200.0, 600.0, 200.0),
               retangulo2(700.0, 400.0, 800.0, 400.0, 800, 200.0, 700.0, 200.0),
               retangulo3(850.0, 500.0, 950.0, 500.0, 950.0, 400.0, 850.0, 400.0),
               retangulo4(1260.0, 590.0, 1340.0, 590.0, 1340.0, 550.0, 1260.0, 550.0),
               retangulo5(1260.0, 530.0, 1340.0, 530.0, 1340.0, 315.0, 1260.0, 315.0),
               retangulo6(1290.0, 550.0, 1310.0, 550.0, 1310.0, 530.0, 1290.0, 530.0),
               retangulo7(1270.0, 510.0, 1330.0, 510.0, 1330.0, 335.0, 1270.0, 335.0),
               retangulo8(1260.0, 230.0, 1280.0, 230.0, 1280.0, 200.0, 1260.0, 200.0),
               retangulo9(1320.0, 230.0, 1340.0, 230.0, 1340.0, 200.0, 1320.0, 200.0),
               retangulo10(1700.0, 1400.0, 2300.0, 1400.0, 2300.0, 200.0, 1700.0, 200.0),
               retangulo11(1900.0, 400.0, 2000.0, 400.0, 2000.0, 200.0, 1900.0, 200.0),
               retangulo12(2000.0, 400.0, 2100.0, 400.0, 2100.0, 200.0, 2000.0, 200.0),
               retangulo13(1720.0, 1350.0, 1880.0, 1350.0, 1880.0, 1150.0, 1720.0, 1150.0),
               retangulo14(1920.0, 1350.0, 2080.0, 1350.0, 2080.0, 1150.0, 1920.0, 1150.0),
               retangulo15(2120.0, 1350.0, 2280.0, 1350.0, 2280.0, 1150.0, 2120.0, 1150.0),
               retangulo16(1720.0, 1050.0, 1880.0, 1050.0, 1880.0, 850.0, 1720.0, 850.0),
               retangulo17(1920.0, 1050.0, 2080.0, 1050.0, 2080.0, 850.0, 1920.0, 850.0),
               retangulo18(2120.0, 1050.0, 2280.0, 1050.0, 2280.0, 850.0, 2120.0, 850.0),
               retangulo19(1720.0, 750.0, 1880.0, 750.0, 1880.0, 550.0, 1720.0, 550.0),
               retangulo20(1920.0, 750.0, 2080.0, 750.0, 2080.0, 550.0, 1920.0, 550.0),
               retangulo21(2120.0, 750.0, 2280.0, 750.0, 2280.0, 550.0, 2120.0, 550.0);

        displayFile << w << ponto1 << ponto2 << ponto3 << ponto4 << ponto5 << ponto6 << ponto7 << ponto8
                    << ponto9 << ponto10 << ponto11 << linha1 << linha2 << linha3 << linha4 << linha5
                    << linha6 << linha7 << linha8 << linha9 << linha10 << linha11 << linha12 << linha13
                    << linha14 << linha15 << linha16 << linha17 << linha18 << triangulo1 << retangulo1
                    << retangulo2 << retangulo3 << retangulo4 << retangulo5 << retangulo6 << retangulo7
                    << retangulo8 << retangulo9 << retangulo10 << retangulo11 << retangulo12 << retangulo13
                    << retangulo14 << retangulo15 << retangulo16 << retangulo17 << retangulo18
                    << retangulo19 << retangulo20 << retangulo21;
    }

    QPoint pc = window.center();
    QRect viewport(10, 10, 480, 480);

    for(i = 0; i < displayFile.size(); i++) {
        for(j = 0; j < displayFile[i].pontos.size(); j++) {
            displayFile[i].pontos[j].RC[0] = false;
            displayFile[i].pontos[j].RC[1] = false;
            displayFile[i].pontos[j].RC[2] = false;
            displayFile[i].pontos[j].RC[3] = false;
        }
    }

    //algoritmo de cohen-sutherland
    for(i = 0; i < displayFile.size(); i++) {

        for(j = 0; j < displayFile[i].pontos.size(); j++) {
            if(displayFile[i].pontos[j].x() < window.topLeft().x()) displayFile[i].pontos[j].RC[3] = true;
            else if(displayFile[i].pontos[j].x() > window.topRight().x()) displayFile[i].pontos[j].RC[2] = true;
            if(displayFile[i].pontos[j].y() > window.bottomLeft().y()) displayFile[i].pontos[j].RC[1] = true;
            else if(displayFile[i].pontos[j].y() < window.topLeft().y()) displayFile[i].pontos[j].RC[0] = true;

        }
    }

    //desloca o mundo pro centro da window
    for(i = 0; i < displayFile.size(); i ++) {
        Objeto obj;

        for(j = 0; j < (displayFile[i]).pontos.size(); j++) {
            Ponto ponto(displayFile[i].pontos[j].x() - pc.x(), displayFile[i].pontos[j].y() - pc.y());
            ponto.RC[0] = displayFile[i].pontos[j].RC[0];
            ponto.RC[1] = displayFile[i].pontos[j].RC[1];
            ponto.RC[2] = displayFile[i].pontos[j].RC[2];
            ponto.RC[3] = displayFile[i].pontos[j].RC[3];

            obj.pontos.append(ponto);
        }
        listaWindow.append(obj);
    }

    //determinar VPN
    double x = 0, y = 0;
    //rotacionar em x e y
    for(i = 1; i < listaWindow.size(); i++) {
        rotacao(i, x, QString("x"), false);
        rotacao(i, y, QString("y"), false);
    }

    //projetar os pontos xp e yp usando a matriz de perspectiva
    int MP[4][4];
    int d = 10;
    MP[0][0] = 1;
    MP[0][1] = 0;
    MP[0][2] = 0;
    MP[0][3] = 0;
    MP[1][0] = 0;
    MP[1][1] = 1;
    MP[1][2] = 0;
    MP[1][3] = 0;
    MP[2][0] = 0;
    MP[2][1] = 0;
    MP[2][2] = 1;
    MP[2][3] = 0;
    MP[3][0] = 0;
    MP[3][1] = 0;
    MP[3][2] = 1/d;
    MP[3][3] = 0;

    for(i = 0; i < listaWindow.size(); i ++) {
        for(j = 0; j < listaWindow[i].pontos.size(); j++) {
            listaWindow[i].pontos[j].P[0][0] = MP[0][0] * listaWindow[i].pontos[j].P[0][0] + MP[0][1] * listaWindow[i].pontos[j].P[1][0] + MP[0][2] * listaWindow[i].pontos[j].P[2][0] + MP[0][3] * listaWindow[i].pontos[j].P[3][0];
            listaWindow[i].pontos[j].P[1][0] = MP[1][0] * listaWindow[i].pontos[j].P[0][0] + MP[1][1] * listaWindow[i].pontos[j].P[1][0] + MP[1][2] * listaWindow[i].pontos[j].P[2][0] + MP[1][3] * listaWindow[i].pontos[j].P[3][0];
            listaWindow[i].pontos[j].P[2][0] = MP[2][0] * listaWindow[i].pontos[j].P[0][0] + MP[2][1] * listaWindow[i].pontos[j].P[1][0] + MP[2][2] * listaWindow[i].pontos[j].P[2][0] + MP[2][3] * listaWindow[i].pontos[j].P[3][0];
            listaWindow[i].pontos[j].P[3][0] = MP[3][0] * listaWindow[i].pontos[j].P[0][0] + MP[3][1] * listaWindow[i].pontos[j].P[1][0] + MP[3][2] * listaWindow[i].pontos[j].P[2][0] + MP[3][3] * listaWindow[i].pontos[j].P[3][0];;;
        }
    }

    //normalização das coordenadas
    for(i = 0; i < listaWindow.size(); i ++) {
        for(j = 0; j < listaWindow[i].pontos.size(); j++) {
            listaWindow[i].pontos[j].setX((listaWindow[i].pontos[j].x)()/(window.width()/2));
            listaWindow[i].pontos[j].setY((listaWindow[i].pontos[j].y)()/(window.height()/2));
        }
    }

    //transformada de viewport
    for(i = 0; i < listaWindow.size(); i ++) {

        Objeto obj;

        for(j = 0; j < listaWindow[i].pontos.size(); j++) {
            double xp = ((listaWindow[i].pontos[j].x() + 1.0)/2.0)*viewport.width();
            double yp = (1.0 - ((listaWindow[i].pontos[j].y()+1.0)/2.0))*viewport.height();
            Ponto ponto(xp, yp);
            ponto.RC[0] = displayFile[i].pontos[j].RC[0];
            ponto.RC[1] = displayFile[i].pontos[j].RC[1];
            ponto.RC[2] = displayFile[i].pontos[j].RC[2];
            ponto.RC[3] = displayFile[i].pontos[j].RC[3];
            obj.pontos.append(ponto);

        }
        listaWindow[i] = obj;
    }

    QFrame::paintEvent(event);
    QPainter painter(this);

    //desenhar a "viewport"
    painter.setPen(QPen(Qt::lightGray, 2));
    painter.drawRect(viewport);

    //desenha
    for(i = 1; i < listaWindow.size(); i++) {

        if(listaWindow[i].pontos.size() == 1) {
            if(listaWindow[i].pontos[0].rcV()) {
                painter.setPen(QPen(Qt::red, 2));
                painter.drawPoint(QPoint(listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()));
            }
        }
        else if (listaWindow[i].pontos.size() == 2) {
            painter.setPen(QPen(Qt::black, 2));
            if(listaWindow[i].pontos[0].rcV() && listaWindow[i].pontos[1].rcV()) {
                painter.drawLine(QLine(listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y(), listaWindow[i].pontos[1].x(), listaWindow[i].pontos[1].y()));
            }
            else if(listaWindow[i].pontos[0].rcF(listaWindow[i].pontos[1])) {
                Objeto obj = modificarPontos(listaWindow[i], listaWindow[i].pontos[0].RC, listaWindow[i].pontos[1].RC, viewport);
                painter.drawLine(QLine(obj.pontos[0].x(), obj.pontos[0].y(), obj.pontos[1].x(), obj.pontos[1].y()));
            }
        }
        else if(listaWindow[i].pontos.size() == 3) {
           painter.setPen(QPen(Qt::magenta, 2));
           for(j = 0; j < listaWindow[i].pontos.size(); j++) {
               if(j == (listaWindow[i].pontos.size() - 1)) {
                   if(listaWindow[i].pontos[j].rcV() && listaWindow[i].pontos[0].rcV()) {
                       painter.drawLine(QLine(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()));
                   }
                   else if(listaWindow[i].pontos[j].rcF(listaWindow[i].pontos[0])) {
                       Objeto obj = modificarPontos(Objeto(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()), listaWindow[i].pontos[j].RC, listaWindow[i].pontos[0].RC, viewport);
                       painter.drawLine(QLine(obj.pontos[0].x(), obj.pontos[0].y(), obj.pontos[1].x(), obj.pontos[1].y()));
                   }
               }
               else if(listaWindow[i].pontos[j].rcV() && listaWindow[i].pontos[j + 1].rcV()) {
                   painter.drawLine(QLine(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[j + 1].x(), listaWindow[i].pontos[j + 1].y()));
               }
               else if(listaWindow[i].pontos[j].rcF(listaWindow[i].pontos[j + 1])) {
                   Objeto obj = modificarPontos(Objeto(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[j + 1].x(), listaWindow[i].pontos[j + 1].y()), listaWindow[i].pontos[j].RC, listaWindow[i].pontos[j + 1].RC, viewport);
                   painter.drawLine(QLine(obj.pontos[0].x(), obj.pontos[0].y(), obj.pontos[1].x(), obj.pontos[1].y()));
               }
           }
        }
        else if (listaWindow[i].pontos.size() == 4) {
            painter.setPen(QPen(Qt::blue, 2));
            for(j = 0; j < listaWindow[i].pontos.size(); j++) {
                if(j == (listaWindow[i].pontos.size() - 1)) {
                    if(listaWindow[i].pontos[j].rcV() && listaWindow[i].pontos[0].rcV()) {
                        painter.drawLine(QLine(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()));
                    }
                    else if(listaWindow[i].pontos[j].rcF(listaWindow[i].pontos[0])) {
                        Objeto obj = modificarPontos(Objeto(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()), listaWindow[i].pontos[j].RC, listaWindow[i].pontos[0].RC, viewport);
                        painter.drawLine(QLine(obj.pontos[0].x(), obj.pontos[0].y(), obj.pontos[1].x(), obj.pontos[1].y()));
                    }
                }
                else if(listaWindow[i].pontos[j].rcV() && listaWindow[i].pontos[j + 1].rcV()) {
                     painter.drawLine(QLine(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[j + 1].x(), listaWindow[i].pontos[j + 1].y()));
                }
                else if(listaWindow[i].pontos[j].rcF(listaWindow[i].pontos[j + 1])) {
                    Objeto obj = modificarPontos(Objeto(listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(), listaWindow[i].pontos[j + 1].x(), listaWindow[i].pontos[j + 1].y()), listaWindow[i].pontos[j].RC, listaWindow[i].pontos[j + 1].RC, viewport);
                    painter.drawLine(QLine(obj.pontos[0].x(), obj.pontos[0].y(), obj.pontos[1].x(), obj.pontos[1].y()));
                }
            }
        }
    }

    listaWindow.clear();
}

void MeuFrame::moverCima() {

    window.setCoords(window.topLeft().x(), window.topLeft().y() + 10, window.bottomRight().x(), window.bottomRight().y() + 10);
    ajustarCentro();

    repaint();
}

void MeuFrame::moverBaixo() {

    window.setCoords(window.topLeft().x(), window.topLeft().y() - 10, window.bottomRight().x(), window.bottomRight().y() - 10);
    ajustarCentro();

    repaint();
}
void MeuFrame::moverEsquerda() {

    window.setCoords(window.topLeft().x() - 10, window.topLeft().y(), window.bottomRight().x() - 10, window.bottomRight().y());
    ajustarCentro();

    repaint();

}
void MeuFrame::moverDireita() {

    window.setCoords(window.topLeft().x() + 10, window.topLeft().y(), window.bottomRight().x() + 10, window.bottomRight().y());
    ajustarCentro();

    repaint();
}

void MeuFrame::entradaTranslacao()
{
    int obj = QInputDialog::getInt(this, "Objeto", "escolha o objeto:", 0, 1, displayFile.size());
    int dx = QInputDialog::getInt(this, "Distância", "Distância em x:", 0);
    int dy = QInputDialog::getInt(this, "Distância", "Distância em y:", 0);
    this->translacao(obj, dx, dy);
}

void MeuFrame::entradaEscala()
{
    int obj = QInputDialog::getInt(this, "Objeto", "Escolha o objeto:", 0, 1, displayFile.size());
    int sx = QInputDialog::getInt(this, "Fator", "Fator de escala em x:", 1);
    int sy = QInputDialog::getInt(this, "Fator", "Fator de escala em y:", 1);
    this->escalonamento(obj, sx, sy);
}

void MeuFrame::entradaRotacao()
{
    int obj = QInputDialog::getInt(this, "Objeto", "escolha o objeto:", 0, 1, displayFile.size());
    double angulo = QInputDialog::getDouble(this, "Ângulo", "Ângulo em graus:", 0);
    QString eixo = QInputDialog::getText(this, "Eixo", "Rotação em torno de ('x', 'y', ou 'z':");
    this->rotacao(obj, angulo, eixo, true);
}

void MeuFrame::entradaTransformacaoWindow() {
    QString transformacao = QInputDialog::getText(this, "Transformacao da Window", "translacao = 't', escala = 'e', rotacao = 'r'");
    Objeto w(window.topLeft().x(), window.topLeft().y(), window.topRight().x(), window.topRight().y(), window.bottomRight().x(), window.bottomRight().y(), window.bottomLeft().x(), window.bottomLeft().y());
    if(transformacao.toStdString() == "t") {
        int dx = QInputDialog::getInt(this, "Distância", "Distância em x:", 0);
        int dy = QInputDialog::getInt(this, "Distância", "Distância em y:", 0);
        this->translacao(0, dx, dy);
    }
    else if(transformacao.toStdString() == "e") {
        int sx = QInputDialog::getInt(this, "Fator", "Fator de escala em x:", 1);
        int sy = QInputDialog::getInt(this, "Fator", "Fator de escala em y:", 1);
        this->escalonamento(0, sx, sy);
    }
    else if(transformacao.toStdString() == "r") {
        double angulo = QInputDialog::getDouble(this, "Ângulo", "Ângulo em graus:", 0);
        QString eixo = QInputDialog::getText(this, "Eixo", "Rotação em torno de ('x', 'y', ou 'z':");
        this->rotacao(0, angulo, eixo, true);
    }
}

void MeuFrame::translacao(int a, double dx, double dy) {
    int T[4][4], dz = 1;

    T[0][0] = 1;
    T[0][1] = 0;
    T[0][2] = 0;
    T[0][3] = dx;
    T[1][0] = 0;
    T[1][1] = 1;
    T[1][2] = 0;
    T[1][3] = dy;
    T[2][0] = 0;
    T[2][1] = 0;
    T[2][2] = 1;
    T[2][3] = dz;
    T[3][0] = 0;
    T[3][1] = 0;
    T[3][2] = 0;
    T[3][3] = 1;

    for(int i = 0; i < displayFile[a].pontos.size(); i ++) {
        displayFile[a].pontos[i].P[0][0] = T[0][0] * displayFile[a].pontos[i].P[0][0] + T[0][1] * displayFile[a].pontos[i].P[1][0] + T[0][2] * displayFile[a].pontos[i].P[2][0] + T[0][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[1][0] = T[1][0] * displayFile[a].pontos[i].P[0][0] + T[1][1] * displayFile[a].pontos[i].P[1][0] + T[1][2] * displayFile[a].pontos[i].P[2][0] + T[1][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[2][0] = T[2][0] * displayFile[a].pontos[i].P[0][0] + T[2][1] * displayFile[a].pontos[i].P[1][0] + T[2][2] * displayFile[a].pontos[i].P[2][0] + T[2][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[3][0] = 1;
    }

    if(a == 0) {
        window.setCoords(displayFile[0].pontos[0].P[0][0], displayFile[0].pontos[0].P[1][0], displayFile[0].pontos[2].P[0][0], displayFile[0].pontos[2].P[1][0]);
        ajustarCentro();
    }

    repaint();
}

void MeuFrame::escalonamento(int a, double sx, double sy) {
    int i, S[4][4], sz = 1;

    S[0][0] = sx;
    S[0][1] = 0;
    S[0][2] = 0;
    S[0][3] = 0;
    S[1][0] = 0;
    S[1][1] = sy;
    S[1][2] = 0;
    S[1][3] = 0;
    S[2][0] = 0;
    S[2][1] = 0;
    S[2][2] = sz;
    S[2][3] = 0;
    S[3][0] = 0;
    S[3][1] = 0;
    S[3][2] = 0;
    S[3][3] = 1;

    //translacao para a origem
    for(i = 0; i < displayFile[a].pontos.size(); i++) {
        displayFile[a].pontos[i].P[0][0] -= displayFile[a].centro.x();
        displayFile[a].pontos[i].P[1][0] -= displayFile[a].centro.y();
    }

    //escala
    for(i = 0; i < displayFile[a].pontos.size(); i++) {
        displayFile[a].pontos[i].P[0][0] = S[0][0] * displayFile[a].pontos[i].P[0][0] + S[0][1] * displayFile[a].pontos[i].P[1][0] + S[0][2] * displayFile[a].pontos[i].P[2][0] + S[0][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[1][0] = S[1][0] * displayFile[a].pontos[i].P[0][0] + S[1][1] * displayFile[a].pontos[i].P[1][0] + S[1][2] * displayFile[a].pontos[i].P[2][0] + S[1][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[2][0] = S[2][0] * displayFile[a].pontos[i].P[0][0] + S[2][1] * displayFile[a].pontos[i].P[1][0] + S[2][2] * displayFile[a].pontos[i].P[2][0] + S[2][3] * displayFile[a].pontos[i].P[3][0];;
        displayFile[a].pontos[i].P[3][0] = 1;
    }

    //translacao de volta ao ponto inicial
    for(i = 0; i < displayFile[a].pontos.size(); i++) {
        displayFile[a].pontos[i].P[0][0] += displayFile[a].centro.x();
        displayFile[a].pontos[i].P[1][0] += displayFile[a].centro.y();
    }

    if(a == 0) {
        window.setCoords(displayFile[0].pontos[0].P[0][0], displayFile[0].pontos[0].P[1][0], displayFile[0].pontos[2].P[0][0], displayFile[0].pontos[2].P[1][0]);
        ajustarCentro();
    }

    repaint();
}

void MeuFrame::rotacao(int a, double angulo, QString eixo, bool rp) {
    int i;
    double R[4][4], rad;
    string e = eixo.toStdString();

    rad = qDegreesToRadians(angulo);

    if(e == "x") {
        R[0][0] = 1;
        R[0][1] = 0;
        R[0][2] = 0;
        R[0][3] = 0;
        R[1][0] = 0;
        R[1][1] = qCos(rad);
        R[1][2] = (-1) * qSin(rad);
        R[1][3] = 0;
        R[2][0] = 0;
        R[2][1] = qSin(rad);
        R[2][2] = qCos(rad);
        R[2][3] = 0;
        R[3][0] = 0;
        R[3][1] = 0;
        R[3][2] = 0;
        R[3][3] = 1;
    }
    else if(e == "y") {
        R[0][0] = qCos(rad);
        R[0][1] = 0;
        R[0][2] = qSin(rad);
        R[0][3] = 0;
        R[1][0] = 0;
        R[1][1] = 1;
        R[1][2] = 0;
        R[1][3] = 0;
        R[2][0] = (-1) * qSin(rad);
        R[2][1] = 0;
        R[2][2] = qCos(rad);
        R[2][3] = 0;
        R[3][0] = 0;
        R[3][1] = 0;
        R[3][2] = 0;
        R[3][3] = 1;
    }
    else if(e == "z") {
        R[0][0] = qCos(rad);
        R[0][1] = (-1) * qSin(rad);
        R[0][2] = 0;
        R[0][3] = 0;
        R[1][0] = qSin(rad);
        R[1][1] = qCos(rad);
        R[1][2] = 0;
        R[1][3] = 0;
        R[2][0] = 0;
        R[2][1] = 0;
        R[2][2] = 1;
        R[2][3] = 0;
        R[3][0] = 0;
        R[3][1] = 0;
        R[3][2] = 0;
        R[3][3] = 1;
    }

    //translacao para a origem
    for(i = 0; i < displayFile[a].pontos.size(); i++) {
        displayFile[a].pontos[i].P[0][0] -= displayFile[a].centro.x();
        displayFile[a].pontos[i].P[1][0] -= displayFile[a].centro.y();
    }

    //rotacao
    for(i = 0; i < displayFile[a].pontos.size(); i++) {
        displayFile[a].pontos[i].P[0][0] = R[0][0] * displayFile[a].pontos[i].P[0][0] + R[0][1] * displayFile[a].pontos[i].P[1][0] + R[0][2] * displayFile[a].pontos[i].P[2][0] + R[0][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[1][0] = R[1][0] * displayFile[a].pontos[i].P[0][0] + R[1][1] * displayFile[a].pontos[i].P[1][0] + R[1][2] * displayFile[a].pontos[i].P[2][0] + R[1][3] * displayFile[a].pontos[i].P[3][0];
        displayFile[a].pontos[i].P[2][0] = R[2][0] * displayFile[a].pontos[i].P[0][0] + R[2][1] * displayFile[a].pontos[i].P[1][0] + R[2][2] * displayFile[a].pontos[i].P[2][0] + R[2][3] * displayFile[a].pontos[i].P[3][0];;
        displayFile[a].pontos[i].P[3][0] = 1;
    }

    //translacao de volta ao ponto inicial
    for(i = 0; i < displayFile[a].pontos.size(); i++) {
        displayFile[a].pontos[i].P[0][0] += displayFile[a].centro.x();
        displayFile[a].pontos[i].P[1][0] += displayFile[a].centro.y();
    }

    if(a == 0) {
        window.setTopLeft(QPoint(displayFile[0].pontos[0].P[0][0], displayFile[0].pontos[0].P[1][0]));
        window.setTopRight(QPoint(displayFile[0].pontos[1].P[0][0], displayFile[0].pontos[1].P[1][0]));
        window.setBottomRight(QPoint(displayFile[0].pontos[2].P[0][0], displayFile[0].pontos[2].P[1][0]));
        window.setBottomLeft(QPoint(displayFile[0].pontos[3].P[0][0], displayFile[0].pontos[3].P[1][0]));

        ajustarCentro();
    }

    if(rp) {
       repaint();
    }
}

Objeto MeuFrame::modificarPontos(Objeto linha, bool rc1[4], bool rc2[4], QRect vp) {
    double m;
    Objeto novo(linha.pontos[0].x(), linha.pontos[0].y(), linha.pontos[1].x(), linha.pontos[1].y());
    for(int i = 0; i < 4; i++) {
        novo.pontos[0].RC[i] = rc1[i];
        novo.pontos[1].RC[i] = rc2[i];
    }
    m = fabs((linha.pontos[1].y() - linha.pontos[0].y())/(linha.pontos[1].x() - linha.pontos[0].x()));

    if(!(novo.pontos[0].rcV())) {
        //topo
        if(novo.pontos[0].RC[0]){
            novo.pontos[0].setX(novo.pontos[0].x() + 1.0/m * (vp.topLeft().y() - novo.pontos[0].y()));
            novo.pontos[0].setY(vp.bottomLeft().y());
        }
        //base
        else if(novo.pontos[0].RC[1]){
            novo.pontos[0].setX(novo.pontos[0].x() + 1.0/m * ((vp.bottomLeft().y() - novo.pontos[0].y())/m));
            novo.pontos[0].setY(vp.topLeft().y());
        }
        //direita
        if(novo.pontos[0].RC[2]){
            novo.pontos[0].setX(vp.topRight().x());
            novo.pontos[0].setY((m * (vp.topRight().x() - novo.pontos[0].x())) + novo.pontos[0].y());
        }
        //esquerda
        else if(novo.pontos[0].RC[3]){
            novo.pontos[0].setX(vp.x());
            novo.pontos[0].setY((m * (vp.topLeft().x() - novo.pontos[0].x())) + novo.pontos[0].y());
        }
    }
    if(!(novo.pontos[1].rcV())) {
        //topo
        if(novo.pontos[1].RC[0]){
            novo.pontos[1].setX(novo.pontos[1].x() + ((vp.topLeft().y() - novo.pontos[1].y())/m));
            novo.pontos[1].setY(vp.bottomLeft().y());
        }
        //base
        else if(novo.pontos[1].RC[1]){
            novo.pontos[1].setX(novo.pontos[1].x() + ((vp.bottomLeft().y() - novo.pontos[1].y())/m));
            novo.pontos[1].setY(vp.topLeft().y());
        }
        //direita
        if(novo.pontos[1].RC[2]){
            novo.pontos[1].setX(vp.topRight().x());
            novo.pontos[1].setY((m * (vp.topRight().x() - novo.pontos[1].x())) + novo.pontos[1].y());
        }
        //esquerda
        else if(novo.pontos[1].RC[3]){
            novo.pontos[1].setX(vp.topLeft().x());
            novo.pontos[1].setY((m * (vp.topLeft().x() - novo.pontos[1].x())) + novo.pontos[1].y());
        }
    }
    return novo;
}

void MeuFrame::ajustarCentro() {
    displayFile[0].pontos.clear();
    Ponto pw1(window.topLeft().x(), window.topLeft().y()), pw2(window.topRight().x(), window.topRight().y()), pw3(window.bottomRight().x(), window.bottomRight().y()), pw4(window.bottomLeft().x(), window.bottomLeft().y());
    displayFile[0].pontos << pw1 << pw2 << pw3 << pw4;
    Ponto pc(window.center().x(), window.center().y());
    displayFile[0].centro = pc;
}

*/
