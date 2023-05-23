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
    QAction *actionMedecin;
    QAction *actionPharmacien;
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *editMP;
    QLineEdit *editMPText;
    QPushButton *submit;
    QWidget *signPatient;
    QLabel *label;
    QWidget *signMedecin;
    QLabel *label_2;
    QWidget *signPharmacien;
    QLabel *label_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuInscription;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1004, 639);
        actionPatient = new QAction(MainWindow);
        actionPatient->setObjectName("actionPatient");
        actionMedecin = new QAction(MainWindow);
        actionMedecin->setObjectName("actionMedecin");
        actionPharmacien = new QAction(MainWindow);
        actionPharmacien->setObjectName("actionPharmacien");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 131, 41));
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName("pages");
        pages->setGeometry(QRect(10, 60, 971, 531));
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        loginPic = new QLabel(loginPage);
        loginPic->setObjectName("loginPic");
        loginPic->setGeometry(QRect(140, 130, 261, 251));
        loginPic->setPixmap(QPixmap(QString::fromUtf8("pictures/login.png")));
        loginPic->setScaledContents(true);
        groupBox = new QGroupBox(loginPage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(460, 180, 261, 111));
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

        pages->addWidget(loginPage);
        accountPage = new QWidget();
        accountPage->setObjectName("accountPage");
        groupBox_2 = new QGroupBox(accountPage);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 30, 381, 121));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 361, 71));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        editMP = new QComboBox(layoutWidget);
        editMP->addItem(QString());
        editMP->addItem(QString());
        editMP->setObjectName("editMP");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editMP->sizePolicy().hasHeightForWidth());
        editMP->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(editMP);

        editMPText = new QLineEdit(layoutWidget);
        editMPText->setObjectName("editMPText");
        sizePolicy1.setHeightForWidth(editMPText->sizePolicy().hasHeightForWidth());
        editMPText->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(editMPText);


        verticalLayout_2->addLayout(horizontalLayout_2);

        submit = new QPushButton(layoutWidget);
        submit->setObjectName("submit");
        sizePolicy1.setHeightForWidth(submit->sizePolicy().hasHeightForWidth());
        submit->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(submit);

        pages->addWidget(accountPage);
        signPatient = new QWidget();
        signPatient->setObjectName("signPatient");
        label = new QLabel(signPatient);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 110, 57, 14));
        pages->addWidget(signPatient);
        signMedecin = new QWidget();
        signMedecin->setObjectName("signMedecin");
        label_2 = new QLabel(signMedecin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 160, 57, 14));
        pages->addWidget(signMedecin);
        signPharmacien = new QWidget();
        signPharmacien->setObjectName("signPharmacien");
        label_3 = new QLabel(signPharmacien);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 200, 57, 14));
        pages->addWidget(signPharmacien);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1004, 19));
        menuInscription = new QMenu(menubar);
        menuInscription->setObjectName("menuInscription");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuInscription->menuAction());
        menuInscription->addAction(actionPatient);
        menuInscription->addAction(actionMedecin);
        menuInscription->addAction(actionPharmacien);

        retranslateUi(MainWindow);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPatient->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        actionMedecin->setText(QCoreApplication::translate("MainWindow", "M\303\251decin", nullptr));
        actionPharmacien->setText(QCoreApplication::translate("MainWindow", "Pharmacien", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Show tables", nullptr));
        loginPic->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connectez-vous", nullptr));
        nissLabel->setText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Modifiez vos informations !", nullptr));
        editMP->setItemText(0, QCoreApplication::translate("MainWindow", "Nouveau M\303\251decin", nullptr));
        editMP->setItemText(1, QCoreApplication::translate("MainWindow", "Nouveau Pharmacien", nullptr));

        editMPText->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        submit->setText(QCoreApplication::translate("MainWindow", "Soumettre", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "M\303\251decin", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pharma", nullptr));
        menuInscription->setTitle(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
