#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QPainter>
#include <QVector>
#include "objetos.h"
#include "matriz.h"

class AreaDesenho : public QFrame {
    Q_OBJECT
public:
    QVector<Objeto> displayFile;
    QRect window;  // Janela de visualização
    QRect viewport;  // Viewport de visualização

    explicit AreaDesenho(QWidget *parent = nullptr);

    void preencherDisplayFile();
    void recalcularSCN();
    void modificarWindow(double deslocamentoX, double deslocamentoY, double largura, double altura);
    void modificarViewport(double deslocamentoX, double deslocamentoY, double largura, double altura);

    QPoint worldToViewport(double xw, double yw);
    void transformarWindowParaViewport(double fatorEscalaX, double fatorEscalaY);
    void normalizarCoordenadas();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // AREADESENHO_H
