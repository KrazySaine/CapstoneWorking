/********************************************************************************
** Form generated from reading UI file 'UserDashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDASHBOARD_H
#define UI_USERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDashboard
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *checkBalanceButton;
    QPushButton *depositButton;
    QPushButton *withdrawButton;
    QPushButton *transferButton;
    QPushButton *logoutButton;

    void setupUi(QWidget *UserDashboard)
    {
        if (UserDashboard->objectName().isEmpty())
            UserDashboard->setObjectName("UserDashboard");
        UserDashboard->resize(300, 250);
        verticalLayout = new QVBoxLayout(UserDashboard);
        verticalLayout->setObjectName("verticalLayout");
        checkBalanceButton = new QPushButton(UserDashboard);
        checkBalanceButton->setObjectName("checkBalanceButton");

        verticalLayout->addWidget(checkBalanceButton);

        depositButton = new QPushButton(UserDashboard);
        depositButton->setObjectName("depositButton");

        verticalLayout->addWidget(depositButton);

        withdrawButton = new QPushButton(UserDashboard);
        withdrawButton->setObjectName("withdrawButton");

        verticalLayout->addWidget(withdrawButton);

        transferButton = new QPushButton(UserDashboard);
        transferButton->setObjectName("transferButton");

        verticalLayout->addWidget(transferButton);

        logoutButton = new QPushButton(UserDashboard);
        logoutButton->setObjectName("logoutButton");

        verticalLayout->addWidget(logoutButton);


        retranslateUi(UserDashboard);

        QMetaObject::connectSlotsByName(UserDashboard);
    } // setupUi

    void retranslateUi(QWidget *UserDashboard)
    {
        UserDashboard->setWindowTitle(QCoreApplication::translate("UserDashboard", "User Dashboard", nullptr));
        checkBalanceButton->setText(QCoreApplication::translate("UserDashboard", "Check Balance", nullptr));
        depositButton->setText(QCoreApplication::translate("UserDashboard", "Deposit", nullptr));
        withdrawButton->setText(QCoreApplication::translate("UserDashboard", "Withdraw", nullptr));
        transferButton->setText(QCoreApplication::translate("UserDashboard", "Transfer", nullptr));
        logoutButton->setText(QCoreApplication::translate("UserDashboard", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDashboard: public Ui_UserDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDASHBOARD_H
