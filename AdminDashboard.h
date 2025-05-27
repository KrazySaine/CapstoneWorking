#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QWidget>
#include <vector>
#include "User.h"

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit AdminDashboard(std::vector<User>& usersRef, QWidget *parent = nullptr);
    ~AdminDashboard();

private slots:
    void on_viewUsersButton_clicked();
    void on_searchUserButton_clicked();
    void on_deleteUserButton_clicked();
    void on_addFundsButton_clicked();
    void on_resetPasswordButton_clicked();
    void on_summaryButton_clicked();

private:
    void saveUsersToFile();
    Ui::AdminDashboard *ui;
    std::vector<User>& users;
};

#endif // ADMINDASHBOARD_H
