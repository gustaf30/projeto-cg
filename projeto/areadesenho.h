#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include "objetos.h"

class AreaDesenho : public QFrame {
    Q_OBJECT
public:
    QRect window;
    QList<Objeto> displayFile;
    QList<Objeto> listaWindow;
    explicit AreaDesenho(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
};

#endif // AREADESENHO_H
