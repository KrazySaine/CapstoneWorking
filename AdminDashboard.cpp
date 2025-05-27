#include "AdminDashboard.h"
#include "ui_AdminDashboard.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>

AdminDashboard::AdminDashboard(std::vector<User>& usersRef, QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminDashboard), users(usersRef)
{
    ui->setupUi(this);
    setWindowTitle("Admin Dashboard");
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::saveUsersToFile()
{
    QFile file("users.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto& user : users) {
            out << QString::fromStdString(user.username) << " "
                << QString::fromStdString(user.password) << " "
                << user.balance << "\n";
        }
        file.close();
    }
}

void AdminDashboard::on_viewUsersButton_clicked()
{
    QString result = "All Users:\n";
    for (const auto& user : users) {
        result += QString::fromStdString(user.username) + " - Balance: $" + QString::number(user.balance, 'f', 2) + "\n";
    }
    QMessageBox::information(this, "User List", result);
}

void AdminDashboard::on_searchUserButton_clicked()
{
    QString searchName = QInputDialog::getText(this, "Search User", "Enter username:");
    for (const auto& user : users) {
        if (QString::fromStdString(user.username) == searchName) {
            QMessageBox::information(this, "Found", "User: " + searchName + "\nBalance: $" + QString::number(user.balance, 'f', 2));
            return;
        }
    }
    QMessageBox::warning(this, "Not Found", "User not found.");
}

void AdminDashboard::on_deleteUserButton_clicked()
{
    QString userName = QInputDialog::getText(this, "Delete User", "Enter username:");
    for (int i = 0; i < users.size(); ++i) {
        if (QString::fromStdString(users[i].username) == userName) {
            users.erase(users.begin() + i);
            saveUsersToFile();
            QMessageBox::information(this, "Deleted", "User deleted.");
            return;
        }
    }
    QMessageBox::warning(this, "Error", "User not found.");
}

void AdminDashboard::on_addFundsButton_clicked()
{
    QString userName = QInputDialog::getText(this, "Add Funds", "Enter username:");
    double amount = QInputDialog::getDouble(this, "Amount", "Enter amount:", 0, 0);
    for (auto& user : users) {
        if (QString::fromStdString(user.username) == userName) {
            user.balance += amount;
            saveUsersToFile();
            QMessageBox::information(this, "Success", "Funds added.");
            return;
        }
    }
    QMessageBox::warning(this, "Error", "User not found.");
}

void AdminDashboard::on_resetPasswordButton_clicked()
{
    QString userName = QInputDialog::getText(this, "Reset Password", "Enter username:");
    QString newPassword = QInputDialog::getText(this, "New Password", "Enter new password:");
    for (auto& user : users) {
        if (QString::fromStdString(user.username) == userName) {
            user.password = newPassword.toStdString();
            saveUsersToFile();
            QMessageBox::information(this, "Success", "Password reset.");
            return;
        }
    }
    QMessageBox::warning(this, "Error", "User not found.");
}

void AdminDashboard::on_summaryButton_clicked()
{
    double total = 0;
    for (const auto& user : users) {
        total += user.balance;
    }
    QMessageBox::information(this, "Summary",
                             "Total Users: " + QString::number(users.size()) +
                                 "\nTotal Funds: $" + QString::number(total, 'f', 2));
}
