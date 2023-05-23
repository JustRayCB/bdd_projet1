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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *editMP;
    QLineEdit *editMPText;
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
        widget = new QWidget(accountPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 70, 290, 24));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        editMP = new QComboBox(widget);
        editMP->addItem(QString());
        editMP->addItem(QString());
        editMP->setObjectName(QString::fromUtf8("editMP"));

        horizontalLayout_2->addWidget(editMP);

        editMPText = new QLineEdit(widget);
        editMPText->setObjectName(QString::fromUtf8("editMPText"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editMPText->sizePolicy().hasHeightForWidth());
        editMPText->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(editMPText);

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
#if QT_CONFIG(whatsthis)
        pages->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        loginPic->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connectez-vous", nullptr));
        nissLabel->setText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        editMP->setItemText(0, QCoreApplication::translate("MainWindow", "Nouveau Pharmacien", nullptr));
        editMP->setItemText(1, QCoreApplication::translate("MainWindow", "Nouveau M\303\251decin", nullptr));

#if QT_CONFIG(whatsthis)
        editMPText->setWhatsThis(QCoreApplication::translate("MainWindow", "salut", nullptr));
#endif // QT_CONFIG(whatsthis)
        editMPText->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        menuInscription->setTitle(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
