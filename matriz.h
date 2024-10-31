//Translação: Muda um objeto de lugar
// Rotação: Muda a orientação de um objeto
// Escala: Muda o tamanho de um objeto

#ifndef MATRIZ_H
#define MATRIZ_H
#include <vector>
#include <stdexcept>

class Matriz {
private:
    std::vector<std::vector<double>> info;

public:

    Matriz(int linhas, int colunas, double valor_inicial = 0.0);

    int linhas() const;
    int colunas() const;

    double& operator()(int linha, int coluna);
    double operator()(int linha, int coluna) const;

    Matriz operator+(const Matriz& outra) const;
    Matriz operator*(const Matriz& outra) const;
    Matriz identidade() const;
    Matriz translacao() const;
    Matriz escala() const;
    Matriz rotacao(double cx, double cy) const;
};

#endif // MATRIZ_H
