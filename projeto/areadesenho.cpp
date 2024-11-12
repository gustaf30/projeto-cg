#include <QPainter>
#include <QFrame>
#include "areadesenho.h"

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent) {
    window.setRect(960, 480, 900, 600); // Definindo a window
    preencherDisplayFile(); // Preenche o displayFile com objetos de teste
    recalcularSCN(); // Inicializa listaWindow para primeira renderização
}

void AreaDesenho::preencherDisplayFile() {
    if (displayFile.isEmpty()) {
        // Criando objeto window
        Objeto w;
        w.nome = "window";
        Ponto pw1(960, 480), pw2(1860, 480), pw3(1860, 1080), pw4(960, 1080);
        w.pontos << pw1 << pw2 << pw3 << pw4;

        // Criando viewport
        Objeto viewport;
        viewport.nome = "viewport";
        viewport.pontos << Ponto(50, 50) << Ponto(450, 50) << Ponto(450, 450) << Ponto(50, 450);

        // Adicionando objetos de teste com coordenadas dobradas
        Objeto l1, /*l2("linha")*/ t1, r1;
        l1.nome = "linha1";
        t1.nome = "triangulo";
        r1.nome = "retangulo";
        l1.pontos << Ponto(0, 0) << Ponto(400, 400);
        //l2.pontos << Ponto(100, 520) << Ponto(100, 200);
        t1.pontos << Ponto(400, 400) << Ponto(1000, 400) << Ponto(700, 200);
        r1.pontos << Ponto(200, 800) << Ponto(400, 800) << Ponto(400, 1000) << Ponto(200, 1000);

        displayFile.append(w);
        displayFile.append(viewport);
        displayFile.append(l1);
        //displayFile.append(l2);
        displayFile.append(t1);
        displayFile.append(r1);
    }
}

void AreaDesenho::transformarWindow(double fatorEscala, double deslocamentoX, double deslocamentoY) {
    window.setWidth(window.width() * fatorEscala);
    window.setHeight(window.height() * fatorEscala);
    window.moveLeft(window.left() + deslocamentoX);
    window.moveTop(window.top() + deslocamentoY);

    recalcularSCN(); // Recalcula SCN ao alterar a window
    update(); // Redesenha a tela
}

void AreaDesenho::transformarViewport(double fatorEscala, double deslocamentoX, double deslocamentoY) {
    // Transformação da viewport para verificar o efeito na área de desenho
    for (Objeto& objeto : displayFile) {
        for (Ponto& ponto : objeto.pontos) {
            ponto.setX(ponto.x() * fatorEscala + deslocamentoX);
            ponto.setY(ponto.y() * fatorEscala + deslocamentoY);
        }
    }
    recalcularSCN();
    update();
}

void AreaDesenho::recalcularSCN() {
    listaWindow.clear();

    for (const Objeto& objeto : displayFile) {
        Objeto objetoViewport = objeto;

        for (Ponto& ponto : objetoViewport.pontos) {
            QPoint pontoConvertido = worldToViewport(ponto.x(), ponto.y(), rect());
            ponto.setX(pontoConvertido.x());
            ponto.setY(pontoConvertido.y());
        }

        listaWindow.append(objetoViewport);
    }
}

void AreaDesenho::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    for (const Objeto& objeto : listaWindow) {
        if (objeto.nome == "ponto") {
            painter.setPen(QPen(Qt::red, 2));
            painter.drawPoint(objeto.pontos[0].x(), objeto.pontos[0].y());
        } else if (objeto.nome == "linha") {
            painter.setPen(QPen(Qt::green, 2));
            painter.drawLine(objeto.pontos[0].x(), objeto.pontos[0].y(),
                             objeto.pontos[1].x(), objeto.pontos[1].y());
        } else if (objeto.nome == "triangulo") {
            painter.setPen(QPen(Qt::blue, 2));
            for (int j = 0; j < objeto.pontos.size() - 1; j++) {
                painter.drawLine(objeto.pontos[j].x(), objeto.pontos[j].y(),
                                 objeto.pontos[j + 1].x(), objeto.pontos[j + 1].y());
            }
            painter.drawLine(objeto.pontos.last().x(), objeto.pontos.last().y(),
                             objeto.pontos[0].x(), objeto.pontos[0].y());
        } else if (objeto.nome == "retangulo") {
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

QPoint AreaDesenho::worldToViewport(double xw, double yw, const QRect& viewport) {
    double xt = (xw - window.left()) / window.width() * viewport.width();
    double yt = (1 - (yw - window.top()) / window.height()) * viewport.height();
    return QPoint(static_cast<int>(xt), static_cast<int>(yt));
}


/*#include "areadesenho.h"
#include <QPainter>
#include <QFrame>

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent) {
    window.setRect(0, 0, 1, 1);  // Coordenadas normalizadas para a window
    preencherDisplayFile();
    update();
}

void AreaDesenho::preencherDisplayFile() {
    if (displayFile.isEmpty()) {
        Objeto w;
        Ponto pw1(0, 0), pw2(1, 0), pw3(1, 1), pw4(0, 1);
        w.pontos << pw1 << pw2 << pw3 << pw4;
        w.nome = "window";

        Objeto viewport("viewport", 0.1, 0.1, 0.9, 0.1, 0.9, 0.9, 0.1, 0.9);
        Objeto l1("linha 1", 0, 0, 0.5, 0.5), l2("linha 2", 0.1, 0.8, 0.1, 0.3);
        Objeto t1("triangulo 1", 0.2, 0.2, 0.7, 0.2, 0.5, 0.1);
        Objeto r1("retangulo 1", 0.1, 0.6, 0.3, 0.6, 0.3, 0.8, 0.1, 0.8);

        displayFile.append(w);
        displayFile.append(viewport);
        displayFile.append(l1);
        displayFile.append(l2);
        displayFile.append(t1);
        displayFile.append(r1);
    }
}

QPoint AreaDesenho::worldToViewport(double xw, double yw) {
    // Tamanhos da window e da viewport
    double worldWidth = window.width();
    double worldHeight = window.height();
    double viewportWidth = this->width();
    double viewportHeight = this->height();

    // Ajustes de escala relativos da window para a viewport
    double scaleX = viewportWidth / worldWidth;
    double scaleY = viewportHeight / worldHeight;

    // Calcula o ponto transformado na viewport
    int xt = static_cast<int>((xw - window.left()) * scaleX);
    int yt = static_cast<int>((yw - window.top()) * scaleY);

    return QPoint(xt, yt);
}


void AreaDesenho::transformarWindow(double fatorEscala, double deslocamentoX, double deslocamentoY) {
    window.setWidth(window.width() * fatorEscala);
    window.setHeight(window.height() * fatorEscala);
    window.moveLeft(window.left() + deslocamentoX);
    window.moveTop(window.top() + deslocamentoY);
    recalcularSCN();
    update();
}

void AreaDesenho::transformarViewport(double fatorEscala, double deslocamentoX, double deslocamentoY) {
    int novaLargura = static_cast<int>(this->width() * fatorEscala);
    int novaAltura = static_cast<int>(this->height() * fatorEscala);
    this->resize(novaLargura, novaAltura);
    this->move(this->x() + deslocamentoX, this->y() + deslocamentoY);
    update();
}

void AreaDesenho::recalcularSCN() {
    for (Objeto& objeto : displayFile) {
        for (Ponto& ponto : objeto.pontos) {
            ponto.setX((ponto.x() - window.left()) / window.width());
            ponto.setY((ponto.y() - window.top()) / window.height());
        }
    }
}

void AreaDesenho::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    listaWindow.clear();

    for (const Objeto& objeto : displayFile) {
        Objeto objetoModificado = objeto;
        for (const Ponto& ponto : objeto.pontos) {
            Ponto pontoModificado = ponto;
            if (objeto.nome != "window") {
                QPoint pontoConvertido = worldToViewport(ponto.x(), ponto.y());
                pontoModificado.setX(pontoConvertido.x());
                pontoModificado.setY(pontoConvertido.y());
            }
            objetoModificado.pontos.append(pontoModificado);
        }
        listaWindow.append(objetoModificado);
    }

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
            if (objeto.nome == "viewport") painter.setPen(QPen(Qt::black, 2));
            for (int j = 0; j < objeto.pontos.size() - 1; j++) {
                painter.drawLine(objeto.pontos[j].x(), objeto.pontos[j].y(),
                                 objeto.pontos[j + 1].x(), objeto.pontos[j + 1].y());
            }
            painter.drawLine(objeto.pontos.last().x(), objeto.pontos.last().y(),
                             objeto.pontos[0].x(), objeto.pontos[0].y());
        }
    }
}

#include "areadesenho.h"
#include <QPainter>
#include <QFrame>

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent) {
    window.setRect(960, 480, 900, 600);
    preencherDisplayFile();
    update();
}

void AreaDesenho::preencherDisplayFile() {
    if (displayFile.isEmpty()) {
        Objeto w;
        Ponto pw1(960, 480), pw2(1860, 480), pw3(1860, 1080), pw4(960, 1080);
        w.pontos << pw1 << pw2 << pw3 << pw4;
        w.nome = "window";

        Objeto viewport("viewport", 50, 50, 450, 50, 450, 450, 50, 450);

        Objeto //p1("ponto 1", 100, 300), p2("ponto 2", 190, 250),
            l1("linha 1", 0, 0, 200, 200), l2("linha 2", 50, 260, 50, 100),
            t1("triangulo 1", 200, 200, 500, 200, 350, 100),
            r1("retangulo 1", 100, 400, 200, 400, 200, 500, 100, 500);

        displayFile.append(w);
        displayFile.append(viewport);
        //displayFile.append(p1);
        //displayFile.append(p2);
        displayFile.append(l1);
        displayFile.append(l2);
        displayFile.append(t1);
        displayFile.append(r1);
        qDebug() << "Tamanho de displayFile após preenchimento:" << displayFile.size();
        /*
      <x>70</x>
      <y>10</y>
      <width>521</width>
      <height>521</height>

    }
}
QPoint AreaDesenho::worldToViewport(double xw, double yw) {
    // Dimensões da window e da viewport
    double worldWidth = window.width();
    double worldHeight = window.height();
    double viewportWidth = this->width();
    double viewportHeight = this->height();

    // Calcular fator de escala uniforme baseado na menor dimensão
    double scale = std::min(viewportWidth / worldWidth, viewportHeight / worldHeight);

    // Ajuste de posição e aplicação do fator de escala
    int xt = static_cast<int>((xw - window.left()) * scale);
    int yt = static_cast<int>((window.bottom() - yw) * scale);

    return QPoint(xt, yt);
}


void AreaDesenho::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    listaWindow.clear();

    for (const Objeto& objeto : displayFile) {
        Objeto objetoModificado = objeto;
        for (const Ponto& ponto : objeto.pontos) {
            Ponto pontoModificado = ponto;
            if (objeto.nome != "window") {
                QPoint pontoConvertido = worldToViewport(ponto.x(), ponto.y());
                pontoModificado.setX(pontoConvertido.x());
                pontoModificado.setY(pontoConvertido.y());
            }
            objetoModificado.pontos.append(pontoModificado);
        }
        listaWindow.append(objetoModificado);
    }
    /*for (const Objeto& objeto : displayFile) {
        listaWindow.append(objeto);
        for (const Ponto& ponto : objeto.pontos) {
            Ponto pontoModificado = ponto;
            if (objeto.nome != "window") {
                QPoint pontoConvertido = worldToViewport(ponto.x(), ponto.y());
                pontoModificado.setX(pontoConvertido.x());
                pontoModificado.setY(pontoConvertido.y());
            }
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
            if (objeto.nome == "viewport") painter.setPen(QPen(Qt::black, 2));
            for (int j = 0; j < objeto.pontos.size() - 1; j++) {
                painter.drawLine(objeto.pontos[j].x(), objeto.pontos[j].y(),
                                 objeto.pontos[j + 1].x(), objeto.pontos[j + 1].y());
            }
            painter.drawLine(objeto.pontos.last().x(), objeto.pontos.last().y(),
                             objeto.pontos[0].x(), objeto.pontos[0].y());
        }
    }
}*/


