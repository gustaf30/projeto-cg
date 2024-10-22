#ifndef OBJETOS_H
#define OBJETOS_H

#include <QString>
#include <QPainter>
#include <QPolygon>

class Ponto {
public: double P[3][1];

    Ponto() {
        this->P[0][0] = 1;
        this->P[1][0] = 1;
        this->P[2][0] = 1;
    }

    Ponto(double x, double y) {
        this->P[0][0] = x;
        this->P[1][0] = y;
        this->P[2][0] = 1;
    }

    double x() {
        return this->P[0][0];
    }

    double y() {
        return this->P[1][0];
    }

    void setX(double x) {
        this->P[0][0] = x;
    }

    void setY(double y) {
        this->P[1][0] = y;
    }
};

class Objeto {
public:
    QString nome;
    QString tipo;
    QList<Ponto> pontos;
    Ponto centro;

    Objeto(){}

    //ponto
    Objeto(QString _nome, double _x, double _y) {
        this->nome = _nome;
        this->tipo = "ponto";
        Ponto pt(_x, _y);
        this->pontos.append(pt);
        centro = pt;
    };

    //linha
    Objeto(QString _nome, double _x1, double _y1, double _x2, double _y2) {
        this->nome = _nome;
        this->tipo = "linha";
        Ponto pt(_x1, _y1);
        this->pontos.append(pt);
        pt.setX(_x2);
        pt.setY(_y2);
        this->pontos.append(pt);
        centro = Ponto(((_x1 + _x2)/2), ((_y1 + _y2)/2));
    }

    //triangulo
    Objeto(QString _nome, double _x1, double _y1, double _x2, double _y2, double _x3, double _y3) {
        this->nome = _nome;
        this->tipo = "triangulo";
        Ponto pt(_x1, _y1);
        this->pontos.append(pt);

        pt.setX(_x2);
        pt.setY(_y2);
        this->pontos.append(pt);

        pt.setX(_x3);
        pt.setY(_y3);
        this->pontos.append(pt);

        centro = Ponto(((_x1 + _x2 + _x3)/3), ((_y1 + _y2 + _y3)/3));
    }

    //retangulo
    Objeto(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4) {
        Ponto pt(_x1, _y1);
        this->pontos.append(pt);

        pt.setX(_x2);
        pt.setY(_y2);
        this->pontos.append(pt);

        pt.setX(_x3);
        pt.setY(_y3);
        this->pontos.append(pt);

        pt.setX(_x4);
        pt.setY(_y4);
        this->pontos.append(pt);

        centro = Ponto(((_x1 + _x2)/2), ((_y1 + _y4)/2));
    }
};

#endif // OBJETOS_H
