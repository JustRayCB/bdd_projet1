/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 722);
        actionPatient = new QAction(MainWindow);
        actionPatient->setObjectName("actionPatient");
        actionPharmacien = new QAction(MainWindow);
        actionPharmacien->setObjectName("actionPharmacien");
        actionM_decin = new QAction(MainWindow);
        actionM_decin->setObjectName("actionM_decin");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 131, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(470, 240, 261, 111));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nissLabel = new QLabel(groupBox);
        nissLabel->setObjectName("nissLabel");

        horizontalLayout->addWidget(nissLabel);

        nissText = new QLineEdit(groupBox);
        nissText->setObjectName("nissText");

        horizontalLayout->addWidget(nissText);


        verticalLayout->addLayout(horizontalLayout);

        connectionButton = new QPushButton(groupBox);
        connectionButton->setObjectName("connectionButton");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(connectionButton->sizePolicy().hasHeightForWidth());
        connectionButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(connectionButton);

        loginPic = new QLabel(centralwidget);
        loginPic->setObjectName("loginPic");
        loginPic->setGeometry(QRect(140, 180, 261, 251));
        loginPic->setPixmap(QPixmap(QString::fromUtf8("pictures/login.png")));
        loginPic->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 19));
        menuInscription = new QMenu(menubar);
        menuInscription->setObjectName("menuInscription");
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
