/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPatient;
    QAction *actionPharmacien;
    QAction *actionM_decin;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nissLabel;
    QLineEdit *nissText;
    QPushButton *connectionButton;
    QLabel *loginPic;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuInscription;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 722);
        actionPatient = new QAction(MainWindow);
        actionPatient->setObjectName(QString::fromUtf8("actionPatient"));
        actionPharmacien = new QAction(MainWindow);
        actionPharmacien->setObjectName(QString::fromUtf8("actionPharmacien"));
        actionM_decin = new QAction(MainWindow);
        actionM_decin->setObjectName(QString::fromUtf8("actionM_decin"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 131, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(470, 240, 261, 111));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nissLabel = new QLabel(groupBox);
        nissLabel->setObjectName(QString::fromUtf8("nissLabel"));

        horizontalLayout->addWidget(nissLabel);

        nissText = new QLineEdit(groupBox);
        nissText->setObjectName(QString::fromUtf8("nissText"));

        horizontalLayout->addWidget(nissText);


        verticalLayout->addLayout(horizontalLayout);

        connectionButton = new QPushButton(groupBox);
        connectionButton->setObjectName(QString::fromUtf8("connectionButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(connectionButton->sizePolicy().hasHeightForWidth());
        connectionButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(connectionButton);

        loginPic = new QLabel(centralwidget);
        loginPic->setObjectName(QString::fromUtf8("loginPic"));
        loginPic->setGeometry(QRect(140, 180, 261, 251));
        loginPic->setPixmap(QPixmap(QString::fromUtf8("pictures/login.png")));
        loginPic->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 19));
        menuInscription = new QMenu(menubar);
        menuInscription->setObjectName(QString::fromUtf8("menuInscription"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuInscription->menuAction());
        menuInscription->addAction(actionPatient);
        menuInscription->addAction(actionPharmacien);
        menuInscription->addAction(actionM_decin);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPatient->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        actionPharmacien->setText(QCoreApplication::translate("MainWindow", "Pharmacien", nullptr));
        actionM_decin->setText(QCoreApplication::translate("MainWindow", "M\303\251decin", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Show tables", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connectez-vous", nullptr));
        nissLabel->setText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        loginPic->setText(QString());
        menuInscription->setTitle(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
