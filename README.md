<h3 align="center"> 
  🚧 TESTE DO DRIVER DATABASE E DISTRIBUIÇÃO DA BASE DE DADOS 🚧
</h3>

---
#### ⚙️ ETAPAS / FUNCIONALIDADES:

- [x] Criação de nova base de dados no QT utilizando o driver/plugin (QSQLCIPHER)
- [x] Promover encriptação através do SQLCipher (no driver)
- [x] Permitir que este driver, QSQLCipher, trabalhe tanto com SQLite quanto com SQLCipher
- [x] Implementação do código associado
- [x] Testes da funcionalidades através da apresentação de seu conteúdo
- [x] Criação do primeiro nó (leader) por linha de comando e associação por código (linhas de comando -- precisar adaptar código)
- [x] Criar novos nós (inicialmente 3), gerando um cluster e distribuir de fato a base de dados (linhas de comando -- precisar adaptar código)
- [x] Simulação de quebra de ligação entre os nós ao derrubar um deles (primeiro teste com líder) (linhas de comando -- precisar adaptar código)
- [x] Simulação de quebra de ligação entre os nós ao derrubar um deles (segundo teste com outros dois nós) (linhas de comando -- precisar adaptar código)

---
#### ⚠️ NOTAS IMPORTANTES:

- O **.setPasword()** do próprio QT (QSqlDatabase) ainda trabalha com SQLite, que por sua vez não concebe uso de senhas
- Para encriptação utilizar um **.exec()** e **"PRAGMA key = 'sua_senha_aqui';"**

---
#### 🔧 FERRAMENTAS / TECNOLOGIAS:

- C
- C++
- CMake
- QT Framework
- SQLite (QSQLite)
- SQLCipher
- RQLite
- JSON

---
##### 👨‍💻 Desenvolvido na SDILAB - Research & Software Development 
##### ⚖️ Balanças Marques - Grupo José Pimenta Marques
##### 📖 Projeto para Formação em Contexto de Trabalho - IEFP
