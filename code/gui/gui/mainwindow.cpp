#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include <string>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pages->setCurrentIndex(LOGIN);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   db.showTables();
}


void MainWindow::on_connectionButton_clicked()
{
   QString niss = ui->nissText->text();
   std::cout << "This is my niss : " << niss.toStdString() << std::endl;
   ui->nissText->clear();
   niss = niss.trimmed();
   std::vector<std::string> patient = db.connectUser(niss.toStdString());
   if (not patient.empty()){
       // qDebug()<< "Je suis connecté";
       std::cout << "Je suis connecté\n" << std::flush; // car le cout peut-être mis en tampon et ne pas s'afficher tous de suite
       QMessageBox::information(this, "Connection réussie", "Vous vous êtes connecté avec succès !") ;
       ui->pages->setCurrentIndex(PATIENT_ACCOUNT);
   }
   else{
       // qDebug() << "Je ne suis pas connecté";
       std::cout << "Je ne suis pas connecté\n" << std::flush;
       QMessageBox::critical(this, "Erreur de Connection", "Veuillez rentrer un NISS correct") ;
   }
}

