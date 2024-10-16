#include "areadesenho.h"
#include <QPainter>

void AreaDesenho::adicionarObjeto(std::shared_ptr<Objeto> obj) {
    objetos.push_back(obj);
    update();  // Redesenha a tela
}

void AreaDesenho::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (auto &obj : objetos) {
        obj->desenhar(painter);
    }
}
