#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <vector>
#include "User.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(std::vector<User>& usersRef, QWidget *parent = nullptr);
    ~LoginDialog();

    int getLoggedInUserIndex() const;
    bool isAdminLoggedIn() const;

private slots:
    void on_loginButton_clicked();
    void on_createUserButton_clicked();

private:
    Ui::LoginDialog *ui;
    std::vector<User>& users;
    int loggedInIndex = -1;
    bool adminLoggedIn = false;
};

#endif // LOGINDIALOG_H
