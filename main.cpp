#include <QApplication>
#include "User.h"
#include "LoginDialog.h"
#include "UserDashboard.h"
#include "AdminDashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>


// Global user data
std::vector<User> kids;

void loadUsers() {
    kids.clear();
    QFile file("users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString username, password;
        double balance;

        while (!in.atEnd()) {
            in >> username >> password >> balance;
            if (!username.isEmpty() && !password.isEmpty()) {
                kids.push_back({ username.toStdString(), password.toStdString(), balance });
            }
        }
        file.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loadUsers();

    LoginDialog login(kids);
    if (login.exec() == QDialog::Accepted) {
        if (login.isAdminLoggedIn()) {
            AdminDashboard *adminDash = new AdminDashboard(kids);
            adminDash->show();
        } else {
            int userIndex = login.getLoggedInUserIndex();
            UserDashboard *userDash = new UserDashboard(kids, userIndex);
            userDash->show();
        }
        return a.exec();
    }

    return 0;
}
