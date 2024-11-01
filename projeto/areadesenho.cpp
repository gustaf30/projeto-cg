#include "areadesenho.h"
#include <QPainter>
#include <QFrame>

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent) {
    window.setRect(1030, 190, 500, 500);
    preencherDisplayFile();
}

void AreaDesenho::preencherDisplayFile() {
    if (displayFile.isEmpty()) {
        Objeto w;
        Ponto pw1(1030, 190), pw2(1530, 190), pw3(1530, 690), pw4(1030, 690);
        w.pontos << pw1 << pw2 << pw3 << pw4;

        Objeto //p1("ponto 1", 100, 300), p2("ponto 2", 190, 250),
            l1("linha 1", 400, 500, 100, 100), //l2("linha 2", 50, 260, 50, 100),
            t1("triangulo 1", 200, 200, 500, 200, 350, 100),
            r1("retangulo 1", 100, 400, 200, 400, 200, 500, 100, 500);

        displayFile.append(w);
        //displayFile.append(p1);
        //displayFile.append(p2);
        displayFile.append(l1);
        //displayFile.append(l2);
        displayFile.append(t1);
        displayFile.append(r1);
        qDebug() << "Tamanho de displayFile após preenchimento:" << displayFile.size();
    }
}

QPoint AreaDesenho::worldToViewport(double xw, double yw, const QRect& viewport) {
    double xt = (xw - window.left()) / window.width() * viewport.width();
    double yt = (1 - (yw - window.top()) / window.height()) * viewport.height();
    return QPoint(static_cast<int>(xt), static_cast<int>(yt));
}

void AreaDesenho::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect viewport(0, 0, 500, 500);
    painter.drawRect(viewport);

    listaWindow.clear();

    for (const Objeto& objeto : displayFile) {
        listaWindow.append(objeto);
        for (const Ponto& ponto : objeto.pontos) {
            Ponto pontoModificado = ponto;
            QPoint pontoConvertido = worldToViewport(ponto.x(), ponto.y(), viewport);
            pontoModificado.setX(pontoConvertido.x());
            pontoModificado.setY(pontoConvertido.y());
        }
    }

    // Desenha os objetos
    for (const Objeto& objeto : listaWindow) {
        if (objeto.tipo == "ponto") {
            painter.setPen(QPen(Qt::red, 2));
            painter.drawPoint(objeto.pontos[0].x(), objeto.pontos[0].y());
        } else if (objeto.tipo == "linha") {
            painter.setPen(QPen(Qt::green, 2));
            painter.drawLine(objeto.pontos[0].x(), objeto.pontos[0].y(),
                             objeto.pontos[1].x(), objeto.pontos[1].y());
        } else if (objeto.tipo == "triangulo") {
            painter.setPen(QPen(Qt::blue, 2));
            for (int j = 0; j < objeto.pontos.size() - 1; j++) {
                painter.drawLine(objeto.pontos[j].x(), objeto.pontos[j].y(),
                                 objeto.pontos[j + 1].x(), objeto.pontos[j + 1].y());
            }
            painter.drawLine(objeto.pontos.last().x(), objeto.pontos.last().y(),
                             objeto.pontos[0].x(), objeto.pontos[0].y());
        } else if (objeto.tipo == "retangulo") {
            painter.setPen(QPen(Qt::magenta, 2));
            for (int j = 0; j < objeto.pontos.size() - 1; j++) {
                painter.drawLine(objeto.pontos[j].x(), objeto.pontos[j].y(),
                                 objeto.pontos[j + 1].x(), objeto.pontos[j + 1].y());
            }
            painter.drawLine(objeto.pontos.last().x(), objeto.pontos.last().y(),
                             objeto.pontos[0].x(), objeto.pontos[0].y());
        }
    }
}


