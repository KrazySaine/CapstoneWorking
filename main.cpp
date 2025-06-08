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

    while (true) {
        loadUsers();
        LoginDialog login(kids);
        if (login.exec() == QDialog::Accepted) {
            if (login.isAdminLoggedIn()) {
                AdminDashboard *adminDash = new AdminDashboard(kids);
                adminDash->show();

                return a.exec();  // Exit after admin closes dashboard
            } else {
                int userIndex = login.getLoggedInUserIndex();
                UserDashboard *userDash = new UserDashboard(kids, userIndex);

                // Handle logout signal
                QObject::connect(userDash, &UserDashboard::userLoggedOut, [&]() {
                    userDash->deleteLater();
                    qApp->exit(1001);
                });

                userDash->show();
                int result = a.exec();
                if (result == 1001) {
                    continue;
                }
                return result;
            }
        } else {
            break;
        }
    }

    return 0;
}
