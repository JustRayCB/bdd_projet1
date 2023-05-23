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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QStackedWidget *pages;
    QWidget *loginPage;
    QLabel *loginPic;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nissLabel;
    QLineEdit *nissText;
    QPushButton *connectionButton;
    QWidget *accountPage;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuInscription;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1004, 639);
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
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        pages->setGeometry(QRect(10, 60, 971, 531));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        loginPic = new QLabel(loginPage);
        loginPic->setObjectName(QString::fromUtf8("loginPic"));
        loginPic->setGeometry(QRect(140, 130, 261, 251));
        loginPic->setPixmap(QPixmap(QString::fromUtf8("pictures/login.png")));
        loginPic->setScaledContents(true);
        groupBox = new QGroupBox(loginPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(460, 180, 261, 111));
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

        pages->addWidget(loginPage);
        accountPage = new QWidget();
        accountPage->setObjectName(QString::fromUtf8("accountPage"));
        groupBox_2 = new QGroupBox(accountPage);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 30, 381, 121));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 40, 361, 71));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(comboBox);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(pushButton_2);

        pages->addWidget(accountPage);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1004, 19));
        menuInscription = new QMenu(menubar);
        menuInscription->setObjectName(QString::fromUtf8("menuInscription"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuInscription->menuAction());
        menuInscription->addAction(actionPatient);
        menuInscription->addAction(actionPharmacien);
        menuInscription->addAction(actionM_decin);

        retranslateUi(MainWindow);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPatient->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        actionPharmacien->setText(QCoreApplication::translate("MainWindow", "Pharmacien", nullptr));
        actionM_decin->setText(QCoreApplication::translate("MainWindow", "M\303\251decin", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Show tables", nullptr));
        loginPic->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connectez-vous", nullptr));
        nissLabel->setText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Modifiez vos informations !", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Nouveau M\303\251decin", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Nouveau Pharmacien", nullptr));

        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Soumettre", nullptr));
        menuInscription->setTitle(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
