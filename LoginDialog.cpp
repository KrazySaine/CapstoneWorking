#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QMessageBox>
#include <QInputDialog>

LoginDialog::LoginDialog(std::vector<User>& usersRef, QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialog), users(usersRef)
{
    ui->setupUi(this);
    setWindowTitle("Login");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username == "admin" && password == "admin123") {
        adminLoggedIn = true;
        accept();
        return;
    }

    for (int i = 0; i < users.size(); ++i) {
        if (users[i].username == username.toStdString() && users[i].password == password.toStdString()) {
            loggedInIndex = i;
            accept();
            return;
        }
    }

    QMessageBox::warning(this, "Login Failed", "Invalid credentials.");
}

void LoginDialog::on_createUserButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Username and password cannot be empty.");
        return;
    }

    // Check if user already exists
    for (const auto& user : users) {
        if (user.username == username.toStdString()) {
            QMessageBox::warning(this, "Error", "Username already exists.");
            return;
        }
    }

    // Create new user
    User newUser;
    newUser.username = username.toStdString();
    newUser.password = password.toStdString();
    users.push_back(newUser);

    QMessageBox::information(this, "Success", "User created successfully.");
}

int LoginDialog::getLoggedInUserIndex() const
{
    return loggedInIndex;
}

bool LoginDialog::isAdminLoggedIn() const
{
    return adminLoggedIn;
}

