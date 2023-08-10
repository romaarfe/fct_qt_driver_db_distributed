#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sqlcipher/sqlite3.h>  // Inclui a biblioteca SQLite com suporte a codificação (provavelmente SQLCipher)
#include <dqlite.h>

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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSelect_clicked();

    void on_btnCriar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
