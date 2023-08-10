/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tbvTabela;
    QPushButton *btnSelect;
    QLabel *lblTexto;
    QPushButton *btnCriar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(471, 361);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tbvTabela = new QTableView(centralwidget);
        tbvTabela->setObjectName("tbvTabela");
        tbvTabela->setGeometry(QRect(10, 110, 451, 241));
        QFont font;
        font.setBold(true);
        tbvTabela->setFont(font);
        btnSelect = new QPushButton(centralwidget);
        btnSelect->setObjectName("btnSelect");
        btnSelect->setGeometry(QRect(280, 70, 181, 31));
        btnSelect->setFont(font);
        lblTexto = new QLabel(centralwidget);
        lblTexto->setObjectName("lblTexto");
        lblTexto->setGeometry(QRect(10, 70, 251, 21));
        lblTexto->setFont(font);
        btnCriar = new QPushButton(centralwidget);
        btnCriar->setObjectName("btnCriar");
        btnCriar->setGeometry(QRect(10, 10, 451, 51));
        btnCriar->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSelect->setText(QCoreApplication::translate("MainWindow", "SELECT ALL", nullptr));
        lblTexto->setText(QCoreApplication::translate("MainWindow", "BASE DE DADOS EM QSQLCIPHER", nullptr));
        btnCriar->setText(QCoreApplication::translate("MainWindow", "CRIAR BASE DE DADOS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
