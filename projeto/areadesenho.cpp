#include "areadesenho.h"
#include <QPainter>
#include <QPoint>
#include <cmath>

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent), window(0, 0, 900, 600), viewport(25, 25, 450, 450) {
}

void AreaDesenho::preencherDisplayFile() {
    if (displayFile.isEmpty()) {
        Objeto vp;
        vp.nome = "viewport";
        Ponto pvp1(25, 25), pvp2(475, 25), pvp3(475, 475), pvp4(25, 475);
        vp.pontos << pvp1 << pvp2 << pvp3 << pvp4;

        Objeto l1("linha", 1000, 1000, 1200, 1200);

        Objeto t1("triangulo", 1100, 1100, 1300, 1100, 1200, 900);

        Objeto r1("retangulo", 1100, 1200, 1300, 1200, 1300, 1400, 1100, 1400);

        displayFile.append(vp);
        displayFile.append(l1);
        displayFile.append(t1);
        displayFile.append(r1);
    }
}

QPoint AreaDesenho::worldToViewport(double xw, double yw) {
    double x = (xw - window.left()) * viewport.width() / window.width() + viewport.left();
    double y = (yw - window.top()) * viewport.height() / window.height() + viewport.top();
    return QPoint(x, y);
}

void AreaDesenho::recalcularSCN() {
    normalizarCoordenadas();
}

void AreaDesenho::modificarWindow(double deslocamentoX, double deslocamentoY, double largura, double altura) {
    window.moveTopLeft(QPoint(deslocamentoX, deslocamentoY));
    window.setSize(QSize(largura, altura));

    recalcularSCN();
    update();
}

void AreaDesenho::modificarViewport(double deslocamentoX, double deslocamentoY, double largura, double altura) {
    viewport.moveTopLeft(QPoint(deslocamentoX, deslocamentoY));
    viewport.setSize(QSize(largura, altura));

    transformarWindowParaViewport(1.0, 1.0);
    update();
}

void AreaDesenho::normalizarCoordenadas() {
    for (Objeto& obj : displayFile) {
        for (Ponto& ponto : obj.pontos) {
            ponto.setX(ponto.x() * 2);
            ponto.setY(ponto.y() * 2);
        }
    }
    update();
}

void AreaDesenho::transformarWindowParaViewport(double fatorEscalaX, double fatorEscalaY) {
    for (Objeto& obj : displayFile) {
        for (Ponto& ponto : obj.pontos) {
            ponto.setX(ponto.x() * fatorEscalaX);
            ponto.setY(ponto.y() * fatorEscalaY);
        }
    }
    update();
}

void AreaDesenho::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::blue);
    painter.drawRect(viewport);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    for (const Objeto& obj : displayFile) {
        if (obj.pontos.size() < 2) {
            continue;
        }

        for (int i = 0; i < obj.pontos.size(); ++i) {
            const Ponto& ponto = obj.pontos[i];
            QPoint viewportPonto = worldToViewport(ponto.x(), ponto.y());

            if (obj.pontos.size() == 1) {
                painter.drawEllipse(viewportPonto, 3, 3);
            }

            if (i < obj.pontos.size() - 1) {
                const Ponto& proximoPonto = obj.pontos[i + 1];
                QPoint viewportProximoPonto = worldToViewport(proximoPonto.x(), proximoPonto.y());
                painter.drawLine(viewportPonto, viewportProximoPonto);
            }

            if (i == obj.pontos.size() - 1 && obj.pontos.size() > 2) {
                const Ponto& primeiroPonto = obj.pontos[0];
                QPoint viewportPrimeiroPonto = worldToViewport(primeiroPonto.x(), primeiroPonto.y());
                painter.drawLine(viewportPonto, viewportPrimeiroPonto);
            }
        }
    }
}
