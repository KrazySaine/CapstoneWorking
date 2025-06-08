#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H

#include <QWidget>
#include <vector>

class User;

namespace Ui {
class UserDashboard;
}

class UserDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit UserDashboard(std::vector<User>& usersRef, int userIndex, QWidget *parent = nullptr);
    ~UserDashboard();
signals:
    void userLoggedOut();


private slots:
    void on_checkBalanceButton_clicked();
    void on_depositButton_clicked();
    void on_withdrawButton_clicked();
    void on_transferButton_clicked();
    void on_logoutButton_clicked();

private:
    void saveUsersToFile();

    Ui::UserDashboard *ui;
    std::vector<User>& users;
    int currentUserIndex;
};


#endif // USERDASHBOARD_H
