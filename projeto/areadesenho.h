#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QWidget>
#include <vector>
#include <memory>
#include "objetos.h"

class AreaDesenho : public QWidget {
    Q_OBJECT

public:
    std::vector<std::shared_ptr<Objeto>> objetos;

    void adicionarObjeto(std::shared_ptr<Objeto> obj);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // AREADESENHO_H
