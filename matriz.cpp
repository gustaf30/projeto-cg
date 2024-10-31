#include "matriz.h"
#include <iostream>
#include "objetos.h"

Matriz::Matriz(int linhas, int colunas, double valor_inicial)
    : info(linhas, std::vector<double>(colunas, valor_inicial)) {}

int Matriz::linhas() const {
    return info.size();
}

int Matriz::colunas() const {
    return info[0].size();
}

double& Matriz::operator()(int linha, int coluna) {
    return info[linha][coluna];
}

double Matriz::operator()(int linha, int coluna) const {
    return info[linha][coluna];
}

Matriz Matriz::operator+(const Matriz& outra) const {

    Matriz local(linhas(), colunas());
    for (int i = 0; i < linhas(); ++i) {
        for (int j = 0; j < colunas(); ++j) {
            local(i, j) = (*this)(i, j) + outra(i, j);
        }
    }
    return local;
}

Matriz Matriz::operator*(const Matriz& outra) const {
    Matriz local(linhas(), outra.colunas());
    for (int i = 0; i < linhas(); ++i) {
        for (int j = 0; j < outra.colunas(); ++j) {
            for (int k = 0; k < colunas(); ++k) {
                local(i, j) += (*this)(i, k) * outra(k, j);
            }
        }
    }
    return local;
}

Matriz Matriz::identidade() const {
    Matriz local(linhas(), colunas());
    for (int i = 0; i < linhas(); ++i) {
        for (int j = 0; j < colunas(); ++j) {
            local(i, j) = (i == j) ? 1.0 : 0.0;
        }
    }
    return local;
}




Matriz Matriz::translacao() const {
    Matriz matrizTranslacao = identidade();
    matrizTranslacao(0, 2) = 100;
    matrizTranslacao(1, 2) = 150;
    return matrizTranslacao;
}
Matriz Matriz::escala() const {
    Matriz matrizEscala = identidade();
    matrizEscala(0, 0) = 0.8;
    matrizEscala(1, 1) = 1.;
    return matrizEscala;
}
Matriz Matriz::rotacao(double cx, double cy) const {
    Matriz matrizRotacao = identidade();

    double angulo = M_PI / 4;//45 graus
    double cosAngulo = cos(angulo);
    double sinAngulo = sin(angulo);

    // rotacao em cx e cy
    matrizRotacao(0, 0) = cosAngulo;
    matrizRotacao(0, 1) = -sinAngulo;
    matrizRotacao(1, 0) = sinAngulo;
    matrizRotacao(1, 1) = cosAngulo;

    // volta origem
    Matriz matrizTranslacaoOrigem(3, 3);
    matrizTranslacaoOrigem = identidade();
    matrizTranslacaoOrigem(0, 2) = -cx;
    matrizTranslacaoOrigem(1, 2) = -cy;

    // volta local original
    Matriz matrizTranslacaoVolta(3, 3);
    matrizTranslacaoVolta = identidade();
    matrizTranslacaoVolta(0, 2) = cx;
    matrizTranslacaoVolta(1, 2) = cy;


    return matrizTranslacaoVolta * matrizRotacao * matrizTranslacaoOrigem;
}

//Translação: Muda um objeto de lugar
// Rotação: Muda a orientação de um objeto
// Escala: Muda o tamanho de um objeto
