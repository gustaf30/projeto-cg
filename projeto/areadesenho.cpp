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

        Objeto p1("ponto 1", 100, 300), p2("ponto 2", 200, 240),
            l1("linha 1", 500, 500, 100, 100), l2("linha 2", 200, 260, 200, 100),
            t1("triangulo 1", 200, 200, 500, 200, 350, 100),
            r1("retangulo 1", 300, 200, 190, 200, 190, 300, 500, 300);

        displayFile << w << p1 << p2 << l1 << l2 << t1 << r1;
    }

    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect viewport = rect();

    auto worldToViewport = [&](double xw, double yw) -> QPoint {
        double xt = (xw - window.left()) / window.width() * viewport.width();
        double yt = (1 - (yw - window.top()) / window.height()) * viewport.height();
        return QPoint(static_cast<int>(xt), static_cast<int>(yt));
    };

    for (i = 0; i < displayFile.size(); i++) {
        listaWindow.append(displayFile[i]);
        for (j = 0; j < listaWindow[i].pontos.size(); j++) {
            Ponto& ponto = listaWindow[i].pontos[j];
            QPoint pontoConvertido = worldToViewport(ponto.x(), ponto.y());
            ponto.setX(pontoConvertido.x());
            ponto.setY(pontoConvertido.y());
        }
    }

    //desenha
    for (i = 1; i < listaWindow.size(); i++) {
        if (listaWindow[i].tipo == "ponto") {
            painter.setPen(QPen(Qt::red, 2));
            painter.drawPoint(listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y());
        }

        else if (listaWindow[i].tipo == "linha") {
            painter.setPen(QPen(Qt::green, 2));
            painter.drawLine(
                listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y(),
                listaWindow[i].pontos[1].x(), listaWindow[i].pontos[1].y()
                );
        }

        else if (listaWindow[i].tipo == "triangulo") {
            painter.setPen(QPen(Qt::blue, 2));
            for (j = 0; j < listaWindow[i].pontos.size() - 1; j++) {
                painter.drawLine(
                    listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(),
                    listaWindow[i].pontos[j + 1].x(), listaWindow[i].pontos[j + 1].y()
                    );
            }
            painter.drawLine(
                listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(),
                listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()
                );
        }

        else if (listaWindow[i].tipo == "retangulo") {
            painter.setPen(QPen(Qt::magenta, 2));
            for (j = 0; j < listaWindow[i].pontos.size() - 1; j++) {
                painter.drawLine(
                    listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(),
                    listaWindow[i].pontos[j + 1].x(), listaWindow[i].pontos[j + 1].y()
                    );
            }
            painter.drawLine(
                listaWindow[i].pontos[j].x(), listaWindow[i].pontos[j].y(),
                listaWindow[i].pontos[0].x(), listaWindow[i].pontos[0].y()
                );
        }
    }
}
