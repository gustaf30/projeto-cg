#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void aplicarMudancaAoObjeto(int indiceObjeto, int tipoTransformacao);
    void on_CoordenadaX_valueChanged(int arg1);
    void on_CoordenadaY_valueChanged(int arg1);
    void on_rotacaoTrianguloPushButton_clicked();
    void on_rotacaoQuadradoPushButton_clicked();
    void on_rotacaoRetaPushButton_clicked();
    void on_escalaTrianguloPushButton_clicked();
    void on_escalaQuadradoPushButton_clicked();
    void on_escalaRetaPushButton_clicked();
    void on_translacaoTrianguloPushButton_clicked();
    void on_translacaoQuadradoPushButton_clicked();
    void on_translacaoRetaPushButton_clicked();

private:
    Ui::MainWindow *ui;
    double cx;
    double cy;

};
#endif // MAINWINDOW_H
