/********************************************************************************
** Form generated from reading UI file 'AdminDashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDASHBOARD_H
#define UI_ADMINDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminDashboard
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *viewUsersButton;
    QPushButton *searchUserButton;
    QPushButton *deleteUserButton;
    QPushButton *addFundsButton;
    QPushButton *resetPasswordButton;
    QPushButton *summaryButton;

    void setupUi(QWidget *AdminDashboard)
    {
        if (AdminDashboard->objectName().isEmpty())
            AdminDashboard->setObjectName("AdminDashboard");
        verticalLayout = new QVBoxLayout(AdminDashboard);
        verticalLayout->setObjectName("verticalLayout");
        viewUsersButton = new QPushButton(AdminDashboard);
        viewUsersButton->setObjectName("viewUsersButton");

        verticalLayout->addWidget(viewUsersButton);

        searchUserButton = new QPushButton(AdminDashboard);
        searchUserButton->setObjectName("searchUserButton");

        verticalLayout->addWidget(searchUserButton);

        deleteUserButton = new QPushButton(AdminDashboard);
        deleteUserButton->setObjectName("deleteUserButton");

        verticalLayout->addWidget(deleteUserButton);

        addFundsButton = new QPushButton(AdminDashboard);
        addFundsButton->setObjectName("addFundsButton");

        verticalLayout->addWidget(addFundsButton);

        resetPasswordButton = new QPushButton(AdminDashboard);
        resetPasswordButton->setObjectName("resetPasswordButton");

        verticalLayout->addWidget(resetPasswordButton);

        summaryButton = new QPushButton(AdminDashboard);
        summaryButton->setObjectName("summaryButton");

        verticalLayout->addWidget(summaryButton);


        retranslateUi(AdminDashboard);

        QMetaObject::connectSlotsByName(AdminDashboard);
    } // setupUi

    void retranslateUi(QWidget *AdminDashboard)
    {
        AdminDashboard->setWindowTitle(QCoreApplication::translate("AdminDashboard", "Admin Dashboard", nullptr));
        viewUsersButton->setText(QCoreApplication::translate("AdminDashboard", "View All Users", nullptr));
        searchUserButton->setText(QCoreApplication::translate("AdminDashboard", "Search User", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("AdminDashboard", "Delete User", nullptr));
        addFundsButton->setText(QCoreApplication::translate("AdminDashboard", "Add Funds", nullptr));
        resetPasswordButton->setText(QCoreApplication::translate("AdminDashboard", "Reset Password", nullptr));
        summaryButton->setText(QCoreApplication::translate("AdminDashboard", "System Summary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDashboard: public Ui_AdminDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDASHBOARD_H
