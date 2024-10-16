#ifndef OBJETOS_H
#define OBJETOS_H

#include <QString>
#include <QPainter>
#include <QPolygon>
#include <vector>

class Ponto {
public:
    double x, y;
    Ponto(double _x, double _y);
};

class Objeto {
public:
    QString nome;
    QString tipo;
    std::vector<Ponto> pontos;

    Objeto(QString _nome, QString _tipo);
    virtual void desenhar(QPainter &painter) = 0;
};

class PontoObjeto : public Objeto {
public:
    PontoObjeto(QString _nome, Ponto p);
    void desenhar(QPainter &painter) override;
};

class RetaObjeto : public Objeto {
public:
    RetaObjeto(QString _nome, Ponto p1, Ponto p2);
    void desenhar(QPainter &painter) override;
};

class PoligonoObjeto : public Objeto {
public:
    PoligonoObjeto(QString _nome, std::vector<Ponto> pts);
    void desenhar(QPainter &painter) override;
};

#endif // OBJETOS_H
