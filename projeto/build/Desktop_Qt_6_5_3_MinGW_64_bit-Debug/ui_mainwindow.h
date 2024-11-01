/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *coordenadaX;
    QTextBrowser *CoordenadaX;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *coordenadaY;
    QTextBrowser *textBrowser_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *rotacaoTriangulo;
    QPushButton *rotacaoQuadrado;
    QPushButton *rotacaoReta;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *escalaTriangulo;
    QPushButton *escalaQuadrado;
    QPushButton *escalaReta;
    QTextBrowser *textBrowser_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *translacaoTriangulo;
    QPushButton *translacaoQuadrado;
    QPushButton *translacaoReta;
    QFrame *areaContainer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(906, 557);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(630, 30, 256, 484));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        coordenadaX = new QSpinBox(layoutWidget);
        coordenadaX->setObjectName("coordenadaX");

        horizontalLayout_2->addWidget(coordenadaX);

        CoordenadaX = new QTextBrowser(layoutWidget);
        CoordenadaX->setObjectName("CoordenadaX");

        horizontalLayout_2->addWidget(CoordenadaX);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        coordenadaY = new QSpinBox(layoutWidget);
        coordenadaY->setObjectName("coordenadaY");

        horizontalLayout_3->addWidget(coordenadaY);

        textBrowser_5 = new QTextBrowser(layoutWidget);
        textBrowser_5->setObjectName("textBrowser_5");

        horizontalLayout_3->addWidget(textBrowser_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        rotacaoTriangulo = new QPushButton(layoutWidget);
        rotacaoTriangulo->setObjectName("rotacaoTriangulo");

        horizontalLayout_4->addWidget(rotacaoTriangulo);

        rotacaoQuadrado = new QPushButton(layoutWidget);
        rotacaoQuadrado->setObjectName("rotacaoQuadrado");

        horizontalLayout_4->addWidget(rotacaoQuadrado);

        rotacaoReta = new QPushButton(layoutWidget);
        rotacaoReta->setObjectName("rotacaoReta");

        horizontalLayout_4->addWidget(rotacaoReta);


        verticalLayout->addLayout(horizontalLayout_4);

        textBrowser_2 = new QTextBrowser(layoutWidget);
        textBrowser_2->setObjectName("textBrowser_2");

        verticalLayout->addWidget(textBrowser_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        escalaTriangulo = new QPushButton(layoutWidget);
        escalaTriangulo->setObjectName("escalaTriangulo");

        horizontalLayout_5->addWidget(escalaTriangulo);

        escalaQuadrado = new QPushButton(layoutWidget);
        escalaQuadrado->setObjectName("escalaQuadrado");

        horizontalLayout_5->addWidget(escalaQuadrado);

        escalaReta = new QPushButton(layoutWidget);
        escalaReta->setObjectName("escalaReta");

        horizontalLayout_5->addWidget(escalaReta);


        verticalLayout->addLayout(horizontalLayout_5);

        textBrowser_3 = new QTextBrowser(layoutWidget);
        textBrowser_3->setObjectName("textBrowser_3");

        verticalLayout->addWidget(textBrowser_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        translacaoTriangulo = new QPushButton(layoutWidget);
        translacaoTriangulo->setObjectName("translacaoTriangulo");

        horizontalLayout_6->addWidget(translacaoTriangulo);

        translacaoQuadrado = new QPushButton(layoutWidget);
        translacaoQuadrado->setObjectName("translacaoQuadrado");

        horizontalLayout_6->addWidget(translacaoQuadrado);

        translacaoReta = new QPushButton(layoutWidget);
        translacaoReta->setObjectName("translacaoReta");

        horizontalLayout_6->addWidget(translacaoReta);


        verticalLayout->addLayout(horizontalLayout_6);

        areaContainer = new QFrame(centralwidget);
        areaContainer->setObjectName("areaContainer");
        areaContainer->setGeometry(QRect(70, 10, 521, 521));
        areaContainer->setFrameShape(QFrame::StyledPanel);
        areaContainer->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 906, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(rotacaoTriangulo, &QPushButton::clicked, areaContainer, qOverload<>(&QFrame::update));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Rota\303\247\303\243o dos objetos, selecione o ponto e clique no bot\303\243o do objeto que quiser rotacionar</span></p></body></html>", nullptr));
        CoordenadaX->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Coordenada X</p></body></html>", nullptr));
        textBrowser_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Coordenada Y</p></body></html>", nullptr));
        rotacaoTriangulo->setText(QCoreApplication::translate("MainWindow", "Tri\303\242ngulo", nullptr));
        rotacaoQuadrado->setText(QCoreApplication::translate("MainWindow", "Quadrado", nullptr));
        rotacaoReta->setText(QCoreApplication::translate("MainWindow", "Reta", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Escala dos objetos, clique no bot\303\243o do objeto que quiser mudar a escala</span></p></body></html>", nullptr));
        escalaTriangulo->setText(QCoreApplication::translate("MainWindow", "Tri\303\242ngulo", nullptr));
        escalaQuadrado->setText(QCoreApplication::translate("MainWindow", "Quadrado", nullptr));
        escalaReta->setText(QCoreApplication::translate("MainWindow", "Reta", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Transla\303\247\303\243o dos objetos, clique no bot\303\243o do objeto que quiser transladar</span></p></body></html>", nullptr));
        translacaoTriangulo->setText(QCoreApplication::translate("MainWindow", "Tri\303\242ngulo", nullptr));
        translacaoQuadrado->setText(QCoreApplication::translate("MainWindow", "Quadrado", nullptr));
        translacaoReta->setText(QCoreApplication::translate("MainWindow", "Reta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
