#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSelect_clicked()
{
    // Adiciona uma base de dados SQLite com suporte a codificação (SQLCipher)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");

    // Define o nome da base de dados como "basedados.db"
    db.setDatabaseName("basedados.db");

    // Abre a conexão com a base de dados
    db.open();

    // Cria um objeto QSqlQuery para executar consultas SQL
    QSqlQuery *query = new QSqlQuery();

    // Define a consulta SQL a ser executada
    query->prepare("PRAGMA key = 'senha';");

    // Cria um modelo para a tabela de consulta
    QSqlQueryModel *model = new QSqlQueryModel();

    // Define a consulta SQL a ser executada
    query->prepare("SELECT * FROM tabela");

    // Executa a consulta SQL
    query->exec();
    model->setQuery(*query);

    // Define o modelo para a tabela na interface gráfica
    ui->tbvTabela->setModel(model);

    // Fecha a conexão com a base de dados
    db.close();
}


void MainWindow::on_btnCriar_clicked()
{
    // Adiciona uma base de dados SQLite com suporte a codificação (SQLCipher)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");

    // Define o nome da base de dados como "basedados.db"
    db.setDatabaseName("basedados.db");

    // Abre a conexão com a base de dados
    db.open();

    // Define a chave de criptografia para a base de dados
    QSqlQuery query;
    query.exec("PRAGMA key = 'senha';");

    // Cria uma tabela se ela não existir
    if (!query.exec("CREATE TABLE IF NOT EXISTS tabela (id INT PRIMARY KEY, nome TEXT, idade INT)")) {
        qDebug() << "Erro ao criar tabela!";
    }

    // Insere registros na tabela
    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (1, 'Luke', 18)");
    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (2, 'Leia', 18)");
    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (3, 'Han', 25)");
    query.exec("INSERT INTO tabela (id, nome, idade) VALUES (4, 'Yoda', 800)");

    // Fecha a conexão com a base de dados
    db.close();

}

