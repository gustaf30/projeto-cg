#include "objetos.h"

Ponto::Ponto(double _x, double _y) : x(_x), y(_y) {}

Objeto::Objeto(QString _nome, QString _tipo) : nome(_nome), tipo(_tipo) {}

PontoObjeto::PontoObjeto(QString _nome, Ponto p) : Objeto(_nome, "ponto") {
    pontos.push_back(p);
}

void PontoObjeto::desenhar(QPainter &painter) {
    painter.drawPoint(pontos[0].x, pontos[0].y);
}

RetaObjeto::RetaObjeto(QString _nome, Ponto p1, Ponto p2) : Objeto(_nome, "reta") {
    pontos.push_back(p1);
    pontos.push_back(p2);
}

void RetaObjeto::desenhar(QPainter &painter) {
    painter.drawLine(pontos[0].x, pontos[0].y, pontos[1].x, pontos[1].y);
}

PoligonoObjeto::PoligonoObjeto(QString _nome, std::vector<Ponto> pts) : Objeto(_nome, "poligono") {
    pontos = pts;
}

void PoligonoObjeto::desenhar(QPainter &painter) {
    QPolygon poly;
    for (auto &p : pontos) {
        poly << QPoint(p.x, p.y);
    }
    painter.drawPolygon(poly);
}
