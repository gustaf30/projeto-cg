#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include "objetos.h"

class AreaDesenho : public QFrame {
    Q_OBJECT
public:

    QVector<Objeto> displayFile;
    void preencherDisplayFile();
    explicit AreaDesenho(QWidget *parent = nullptr);
    QPoint worldToViewport(double xw, double yw);
    void recalcularSCN();
    void transformarViewport(double fatorEscala, double deslocamentoX, double deslocamentoY);
    void transformarWindow(double fatorEscala, double deslocamentoX, double deslocamentoY);
    void normalizarCoordenadas();

protected:

    void paintEvent(QPaintEvent *event) override;

private:

    QRect window;
    QVector<Objeto> listaWindow;
};

#endif // AREADESENHO_H
