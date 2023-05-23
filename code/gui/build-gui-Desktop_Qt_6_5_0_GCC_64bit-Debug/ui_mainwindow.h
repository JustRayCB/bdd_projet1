/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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
    QGroupBox *groupBox_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *nissPatient;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *namePatient;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *fnamePatient;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *genderPatient;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDateEdit *birthPatient;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *mailPatient;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *phonePatient;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *refP;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QLineEdit *refM;
    QPushButton *signPatient_2;
    QWidget *signMedecin;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLineEdit *inamiM;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QLineEdit *nameM;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_15;
    QLineEdit *fnameM;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QLineEdit *mailM;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_19;
    QLineEdit *specM;
    QPushButton *signM;
    QWidget *signPharmacien;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_16;
    QLineEdit *inamiP;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_17;
    QLineEdit *namePhar;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_20;
    QLineEdit *fnamePhar;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_21;
    QLineEdit *mailPhar;
    QPushButton *signPhar;
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
        groupBox_3 = new QGroupBox(signPatient);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(310, 30, 341, 441));
        widget = new QWidget(groupBox_3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 30, 341, 411));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        nissPatient = new QLineEdit(widget);
        nissPatient->setObjectName("nissPatient");

        horizontalLayout_3->addWidget(nissPatient);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        namePatient = new QLineEdit(widget);
        namePatient->setObjectName("namePatient");

        horizontalLayout_4->addWidget(namePatient);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        fnamePatient = new QLineEdit(widget);
        fnamePatient->setObjectName("fnamePatient");

        horizontalLayout_5->addWidget(fnamePatient);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        genderPatient = new QComboBox(widget);
        genderPatient->addItem(QString());
        genderPatient->addItem(QString());
        genderPatient->addItem(QString());
        genderPatient->setObjectName("genderPatient");

        horizontalLayout_6->addWidget(genderPatient);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        birthPatient = new QDateEdit(widget);
        birthPatient->setObjectName("birthPatient");
        birthPatient->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        birthPatient->setMaximumDateTime(QDateTime(QDate(2023, 5, 30), QTime(1, 59, 59)));
        birthPatient->setMaximumDate(QDate(2023, 5, 30));
        birthPatient->setCurrentSection(QDateTimeEdit::DaySection);
        birthPatient->setCalendarPopup(true);

        horizontalLayout_7->addWidget(birthPatient);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        horizontalLayout_8->addWidget(label_9);

        mailPatient = new QLineEdit(widget);
        mailPatient->setObjectName("mailPatient");

        horizontalLayout_8->addWidget(mailPatient);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        horizontalLayout_9->addWidget(label_10);

        phonePatient = new QLineEdit(widget);
        phonePatient->setObjectName("phonePatient");

        horizontalLayout_9->addWidget(phonePatient);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");

        horizontalLayout_10->addWidget(label_11);

        refP = new QLineEdit(widget);
        refP->setObjectName("refP");

        horizontalLayout_10->addWidget(refP);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_12 = new QLabel(widget);
        label_12->setObjectName("label_12");

        horizontalLayout_11->addWidget(label_12);

        refM = new QLineEdit(widget);
        refM->setObjectName("refM");

        horizontalLayout_11->addWidget(refM);


        verticalLayout_3->addLayout(horizontalLayout_11);

        signPatient_2 = new QPushButton(widget);
        signPatient_2->setObjectName("signPatient_2");

        verticalLayout_3->addWidget(signPatient_2);

        pages->addWidget(signPatient);
        signMedecin = new QWidget();
        signMedecin->setObjectName("signMedecin");
        groupBox_4 = new QGroupBox(signMedecin);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(300, 30, 341, 441));
        layoutWidget_2 = new QWidget(groupBox_4);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(0, 30, 341, 411));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName("label_13");

        horizontalLayout_12->addWidget(label_13);

        inamiM = new QLineEdit(layoutWidget_2);
        inamiM->setObjectName("inamiM");

        horizontalLayout_12->addWidget(inamiM);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName("label_14");

        horizontalLayout_13->addWidget(label_14);

        nameM = new QLineEdit(layoutWidget_2);
        nameM->setObjectName("nameM");

        horizontalLayout_13->addWidget(nameM);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName("label_15");

        horizontalLayout_14->addWidget(label_15);

        fnameM = new QLineEdit(layoutWidget_2);
        fnameM->setObjectName("fnameM");

        horizontalLayout_14->addWidget(fnameM);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName("label_18");

        horizontalLayout_17->addWidget(label_18);

        mailM = new QLineEdit(layoutWidget_2);
        mailM->setObjectName("mailM");

        horizontalLayout_17->addWidget(mailM);


        verticalLayout_4->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_19 = new QLabel(layoutWidget_2);
        label_19->setObjectName("label_19");

        horizontalLayout_18->addWidget(label_19);

        specM = new QLineEdit(layoutWidget_2);
        specM->setObjectName("specM");

        horizontalLayout_18->addWidget(specM);


        verticalLayout_4->addLayout(horizontalLayout_18);

        signM = new QPushButton(layoutWidget_2);
        signM->setObjectName("signM");

        verticalLayout_4->addWidget(signM);

        pages->addWidget(signMedecin);
        signPharmacien = new QWidget();
        signPharmacien->setObjectName("signPharmacien");
        groupBox_5 = new QGroupBox(signPharmacien);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(300, 40, 341, 441));
        layoutWidget_3 = new QWidget(groupBox_5);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(0, 30, 341, 411));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_16 = new QLabel(layoutWidget_3);
        label_16->setObjectName("label_16");

        horizontalLayout_15->addWidget(label_16);

        inamiP = new QLineEdit(layoutWidget_3);
        inamiP->setObjectName("inamiP");

        horizontalLayout_15->addWidget(inamiP);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_17 = new QLabel(layoutWidget_3);
        label_17->setObjectName("label_17");

        horizontalLayout_16->addWidget(label_17);

        namePhar = new QLineEdit(layoutWidget_3);
        namePhar->setObjectName("namePhar");

        horizontalLayout_16->addWidget(namePhar);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_20 = new QLabel(layoutWidget_3);
        label_20->setObjectName("label_20");

        horizontalLayout_19->addWidget(label_20);

        fnamePhar = new QLineEdit(layoutWidget_3);
        fnamePhar->setObjectName("fnamePhar");

        horizontalLayout_19->addWidget(fnamePhar);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_21 = new QLabel(layoutWidget_3);
        label_21->setObjectName("label_21");

        horizontalLayout_20->addWidget(label_21);

        mailPhar = new QLineEdit(layoutWidget_3);
        mailPhar->setObjectName("mailPhar");

        horizontalLayout_20->addWidget(mailPhar);


        verticalLayout_5->addLayout(horizontalLayout_20);

        signPhar = new QPushButton(layoutWidget_3);
        signPhar->setObjectName("signPhar");

        verticalLayout_5->addWidget(signPhar);

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

        pages->setCurrentIndex(4);


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
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Inscrire un Nouveau Patient", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        nissPatient->setPlaceholderText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Votre Nom", nullptr));
        namePatient->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Votre Pr\303\251nom", nullptr));
        fnamePatient->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Votre Genre", nullptr));
        genderPatient->setItemText(0, QCoreApplication::translate("MainWindow", "Homme", nullptr));
        genderPatient->setItemText(1, QCoreApplication::translate("MainWindow", "Femme", nullptr));
        genderPatient->setItemText(2, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        genderPatient->setPlaceholderText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Date de Naissance", nullptr));
        birthPatient->setDisplayFormat(QCoreApplication::translate("MainWindow", "d MMM yyyy", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Votre Email", nullptr));
        mailPatient->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de T\303\251l\303\251phone", nullptr));
        phonePatient->setPlaceholderText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Pharmacien de r\303\251f\303\251rence", nullptr));
        refP->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI Pharmacien", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "M\303\251decin de r\303\251f\303\251rence", nullptr));
        refM->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI M\303\251decin", nullptr));
        signPatient_2->setText(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Inscrire un Nouveau M\303\251decin", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        inamiM->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        nameM->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        fnameM->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        mailM->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialisation", nullptr));
        specM->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom de la Sp\303\251cialisation", nullptr));
        signM->setText(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Inscrire un Nouveau Pharmacien", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        inamiP->setPlaceholderText(QCoreApplication::translate("MainWindow", "INAMI", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        namePhar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        fnamePhar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        mailPhar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        signPhar->setText(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
        menuInscription->setTitle(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
