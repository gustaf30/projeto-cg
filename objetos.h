#ifndef OBJETOS_H
#define OBJETOS_H

#include <QString>
#include <QPainter>
#include <QPolygon>
#include "matriz.h"

class Ponto {
private:
    Matriz P;
public:
    Ponto(): P(3, 1){
        this->P(0,0) = 1;
        this->P(1,0) = 1;
        this->P(2,0) = 1;
    }

    Ponto(double x, double y): P(3,1){
        this->P(0,0) = x;
        this->P(1,0) = y;
        this->P(2,0) = 1;
    }

    double x() const{
        return this->P(0,0);
    }

    double y() const{
        return this->P(1, 0);
    }

    void setX(double x) {
        this->P(0,0) = x;
    }

    void setY(double y) {
        this->P(1, 0) = y;
    }
    Ponto transforma(const Matriz& matrizTransformacao) const {
        Matriz resultado = matrizTransformacao * P;
        return Ponto(resultado(0, 0), resultado(1, 0));
    }

};

class Objeto {
public:
    QString nome;
    QString tipo;
    QList<Ponto> pontos;
    Ponto centro;

    Objeto(){}

    void aplicaTransformacao(const Matriz& matrizTransformacao) {
        for (Ponto& ponto : pontos) {
            ponto = ponto.transforma(matrizTransformacao);
        }
    }
    //ponto
    Objeto(QString _nome, double _x, double _y) {
        this->nome = _nome;
        this->tipo = "ponto";
        /*Ponto pt(_x, _y);
        this->pontos.append(pt);*/
        pontos.append(Ponto(_x, _y));
        centro = Ponto(_x, _y);
    };

    //linha
    Objeto(QString _nome, double _x1, double _y1, double _x2, double _y2) {
        this->nome = _nome;
        this->tipo = "linha";
        /*Ponto pt(_x1, _y1);
        this->pontos.append(pt);
        pt.setX(_x2);
        pt.setY(_y2);
        this->pontos.append(pt);*/
        pontos.append(Ponto(_x1, _y1));
        pontos.append(Ponto(_x2, _y2));
        centro = Ponto(((_x1 + _x2)/2), ((_y1 + _y2)/2));
    }

    //triangulo
    Objeto(QString _nome, double _x1, double _y1, double _x2, double _y2, double _x3, double _y3) {
        this->nome = _nome;
        this->tipo = "triangulo";
        /*Ponto pt(_x1, _y1);
        this->pontos.append(pt);

        pt.setX(_x2);
        pt.setY(_y2);
        this->pontos.append(pt);

        pt.setX(_x3);
        pt.setY(_y3);
        this->pontos.append(pt);*/
        pontos.append(Ponto(_x1, _y1));
        pontos.append(Ponto(_x2, _y2));
        pontos.append(Ponto(_x3, _y3));

        centro = Ponto(((_x1 + _x2 + _x3)/3), ((_y1 + _y2 + _y3)/3));
    }

    //retangulo
    Objeto(QString _nome, double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4) {
        this->nome = _nome;
        this->tipo = "retangulo";
        /*Ponto pt(_x1, _y1);
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

        centro = Ponto(((_x1 + _x2)/2), ((_y1 + _y4)/2));*/

        pontos.append(Ponto(_x1, _y1));
        pontos.append(Ponto(_x2, _y2));
        pontos.append(Ponto(_x3, _y3));
        pontos.append(Ponto(_x4, _y4));

        centro = Ponto(((_x1 + _x2) / 2), ((_y1 + _y4) / 2));
    }
    double calculaCentroX() const {
        double somaX = 0.0;
        for (const Ponto& ponto : pontos) {
            somaX += ponto.x();
        }
        return pontos.isEmpty() ? 0 : somaX / pontos.size();
    }

    double calculaCentroY() const {
        double somaY = 0.0;
        for (const Ponto& ponto : pontos) {
            somaY += ponto.y();
        }
        return pontos.isEmpty() ? 0 : somaY / pontos.size();
    }

};

#endif // OBJETOS_H

