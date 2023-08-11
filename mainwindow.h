#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Inclui a biblioteca SQLite com suporte a codificação (provavelmente SQLCipher)
#include <sqlcipher/sqlite3.h>
#include <dqlite.h>

// Inclui as bibliotecas Qt necessárias
#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QByteArray>
#include <QFile>
#include <QUrl>
#include <QUrlQuery>
#include <QSqlError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

// Define o namespace Ui para a classe MainWindow
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Declara a classe MainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Construtor da classe MainWindow
    MainWindow(QWidget *parent = nullptr);

    // Destrutor da classe MainWindow
    ~MainWindow();

private slots:
    // Função que é chamada quando o botão "Select" é clicado
    void on_btnSelect_clicked();

    // Função que é chamada quando o botão "Criar" é clicado
    void on_btnCriar_clicked();

private:
    // Declara uma variável do tipo Ui::MainWindow para acessar os elementos da interface gráfica
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
