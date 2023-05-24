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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPatient;
    QAction *actionMedecin;
    QAction *actionPharmacien;
    QAction *actionDossier;
    QAction *actionM_dicament;
    QAction *actionPathologie;
    QAction *actionM_decin;
    QAction *actionSp_cialit;
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
    QWidget *layoutWidget1;
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
    QWidget *Dossier;
    QTextBrowser *textBrowser;
    QWidget *Medicament;
    QTextBrowser *textBrowser_2;
    QWidget *Pathologie;
    QTextBrowser *textBrowser_3;
    QWidget *Medecin;
    QTextBrowser *textBrowser_4;
    QWidget *page;
    QTextBrowser *textBrowser_5;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuInscription;
    QMenu *menuTables;

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
        actionDossier = new QAction(MainWindow);
        actionDossier->setObjectName("actionDossier");
        actionM_dicament = new QAction(MainWindow);
        actionM_dicament->setObjectName("actionM_dicament");
        actionPathologie = new QAction(MainWindow);
        actionPathologie->setObjectName("actionPathologie");
        actionM_decin = new QAction(MainWindow);
        actionM_decin->setObjectName("actionM_decin");
        actionSp_cialit = new QAction(MainWindow);
        actionSp_cialit->setObjectName("actionSp_cialit");
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
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 30, 341, 411));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        nissPatient = new QLineEdit(layoutWidget1);
        nissPatient->setObjectName("nissPatient");

        horizontalLayout_3->addWidget(nissPatient);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        namePatient = new QLineEdit(layoutWidget1);
        namePatient->setObjectName("namePatient");

        horizontalLayout_4->addWidget(namePatient);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        fnamePatient = new QLineEdit(layoutWidget1);
        fnamePatient->setObjectName("fnamePatient");

        horizontalLayout_5->addWidget(fnamePatient);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        genderPatient = new QComboBox(layoutWidget1);
        genderPatient->addItem(QString());
        genderPatient->addItem(QString());
        genderPatient->addItem(QString());
        genderPatient->setObjectName("genderPatient");

        horizontalLayout_6->addWidget(genderPatient);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        birthPatient = new QDateEdit(layoutWidget1);
        birthPatient->setObjectName("birthPatient");
        birthPatient->setDateTime(QDateTime(QDate(1999, 12, 31), QTime(0, 0, 0)));
        birthPatient->setMaximumDateTime(QDateTime(QDate(2023, 5, 30), QTime(23, 59, 59)));
        birthPatient->setMaximumDate(QDate(2023, 5, 30));
        birthPatient->setCurrentSection(QDateTimeEdit::DaySection);
        birthPatient->setCalendarPopup(true);

        horizontalLayout_7->addWidget(birthPatient);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");

        horizontalLayout_8->addWidget(label_9);

        mailPatient = new QLineEdit(layoutWidget1);
        mailPatient->setObjectName("mailPatient");

        horizontalLayout_8->addWidget(mailPatient);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");

        horizontalLayout_9->addWidget(label_10);

        phonePatient = new QLineEdit(layoutWidget1);
        phonePatient->setObjectName("phonePatient");

        horizontalLayout_9->addWidget(phonePatient);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");

        horizontalLayout_10->addWidget(label_11);

        refP = new QLineEdit(layoutWidget1);
        refP->setObjectName("refP");

        horizontalLayout_10->addWidget(refP);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName("label_12");

        horizontalLayout_11->addWidget(label_12);

        refM = new QLineEdit(layoutWidget1);
        refM->setObjectName("refM");

        horizontalLayout_11->addWidget(refM);


        verticalLayout_3->addLayout(horizontalLayout_11);

        signPatient_2 = new QPushButton(layoutWidget1);
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
        Dossier = new QWidget();
        Dossier->setObjectName("Dossier");
        textBrowser = new QTextBrowser(Dossier);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(430, 170, 71, 31));
        pages->addWidget(Dossier);
        Medicament = new QWidget();
        Medicament->setObjectName("Medicament");
        textBrowser_2 = new QTextBrowser(Medicament);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(430, 200, 231, 31));
        pages->addWidget(Medicament);
        Pathologie = new QWidget();
        Pathologie->setObjectName("Pathologie");
        textBrowser_3 = new QTextBrowser(Pathologie);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(360, 180, 271, 51));
        pages->addWidget(Pathologie);
        Medecin = new QWidget();
        Medecin->setObjectName("Medecin");
        textBrowser_4 = new QTextBrowser(Medecin);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(450, 200, 71, 31));
        pages->addWidget(Medecin);
        page = new QWidget();
        page->setObjectName("page");
        textBrowser_5 = new QTextBrowser(page);
        textBrowser_5->setObjectName("textBrowser_5");
        textBrowser_5->setGeometry(QRect(450, 190, 71, 31));
        pages->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1004, 24));
        menuInscription = new QMenu(menubar);
        menuInscription->setObjectName("menuInscription");
        menuTables = new QMenu(menubar);
        menuTables->setObjectName("menuTables");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuInscription->menuAction());
        menubar->addAction(menuTables->menuAction());
        menuInscription->addAction(actionPatient);
        menuInscription->addAction(actionMedecin);
        menuInscription->addAction(actionPharmacien);
        menuTables->addAction(actionDossier);
        menuTables->addAction(actionM_dicament);
        menuTables->addAction(actionPathologie);
        menuTables->addAction(actionM_decin);
        menuTables->addAction(actionSp_cialit);

        retranslateUi(MainWindow);

        pages->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPatient->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        actionMedecin->setText(QCoreApplication::translate("MainWindow", "M\303\251decin", nullptr));
        actionPharmacien->setText(QCoreApplication::translate("MainWindow", "Pharmacien", nullptr));
        actionDossier->setText(QCoreApplication::translate("MainWindow", "dossier", nullptr));
        actionM_dicament->setText(QCoreApplication::translate("MainWindow", "medicament", nullptr));
        actionPathologie->setText(QCoreApplication::translate("MainWindow", "pathologie", nullptr));
        actionM_decin->setText(QCoreApplication::translate("MainWindow", "medecin", nullptr));
        actionSp_cialit->setText(QCoreApplication::translate("MainWindow", "specialite", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Show tables", nullptr));
        loginPic->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connectez-vous", nullptr));
        nissLabel->setText(QCoreApplication::translate("MainWindow", "NISS", nullptr));
        nissText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Votre NISS", nullptr));
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
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Dossier</p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">M\303\251dicament</p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pathologie</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">M\303\251decin</p></body></html>", nullptr));
        textBrowser_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Sp\303\251cialit\303\251</p></body></html>", nullptr));
        menuInscription->setTitle(QCoreApplication::translate("MainWindow", "Inscription", nullptr));
        menuTables->setTitle(QCoreApplication::translate("MainWindow", "Tables", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
