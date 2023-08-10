#define SQLITE_HAS_CODEC // Habilita o uso de codificação no SQLite (provavelmente para criptografia)
#define DQLITE_API

#include "mainwindow.h"

class RequestHandler : public QObject {
    Q_OBJECT

public:
    explicit RequestHandler(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    bool performLocalDatabaseOperations() {

        // Crie uma conexão para a base de dados com SQLCipher
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");
        db.setDatabaseName("basedados.db"); // Use uma conexão temporária em memória para desencriptar

        if (db.open()) {
            qDebug() << "Conexão com a base de dados estabelecida com sucesso.";

            // Executar a desencriptação
            QSqlQuery query(db);
            query.exec("PRAGMA key = senha");

            // Consulta SELECT que você deseja executar
            QString selectQuery = "SELECT * FROM tabela";

            if (query.exec(selectQuery)) {
                while (query.next()) {
                    int id = query.value(0).toInt();
                    QString nome = query.value(1).toString();
                    int idade = query.value(2).toInt();
                    qDebug() << "ID:" << id << "Nome:" << nome << "Idade:" << idade;
                }
            } else {
                qDebug() << "Erro na consulta SQL:" << query.lastError().text();
            }
        } else {
            qDebug() << "Erro ao abrir a base de dados:" << db.lastError().text();
        }
        return true;
    }

    void startRequest() {
        // Operações de base de dados locais
        bool databaseSuccess = performLocalDatabaseOperations();

        if (databaseSuccess) {
            // Inicialização do QNetworkAccessManager
            QNetworkAccessManager *manager = new QNetworkAccessManager(this);

            // Criação da solicitação GET
            QNetworkRequest request;
            request.setUrl(QUrl("http://127.0.0.1:4001/db/query?q=PRAGMA%20key%20=%20senha%3B"));

            request.setUrl(QUrl("http://127.0.0.1:4001/db/query?q=SELECT%20*%20FROM%20tabela"));

            // Execução da solicitação GET
            QNetworkReply *reply = manager->get(request);

            // Conexão do sinal finished usando um lambda para lidar com a resposta
            connect(reply, &QNetworkReply::finished, this, [=]() {
                handleReply(reply);
            });
        }
    }


    void handleReply(QNetworkReply *reply) {
        if (!reply)
            return;

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            qDebug() << "Resposta do rqlite:" << responseData;
        } else {
            qDebug() << "Erro na solicitação HTTP:" << reply->errorString();
        }

        reply->deleteLater();
    }

};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    RequestHandler handler;
    handler.startRequest(); // Iniciar a solicitação

    MainWindow w;
    w.show();

    return a.exec();    // Executa o loop de eventos da aplicação
}

#include "main.moc"
