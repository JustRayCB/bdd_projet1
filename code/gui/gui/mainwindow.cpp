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
   if (db.connectUser(niss.toStdString())){
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


void MainWindow::on_submit_clicked()
{
   int choosenOne = ui->editMP->currentIndex();
   std::string inami = ui->editMPText->text().trimmed().toStdString();
   ui->editMPText->clear();
   int result = db.changeMP(inami, choosenOne);
   std::string i = (choosenOne) ? "Pharmacien" : "Médecin";
   std::string j  = (not choosenOne) ? "Pharmacien" : "Médecin";
   if (result == -1){
       QMessageBox::critical(this, "Erreur", QString::fromStdString("Le " + i + " n'existe pas dans notre base de données"));
   }
   else if (result == -2){
       QMessageBox::critical(this, "Erreur", QString::fromStdString("Il y a une erreur dans le format de l'INAMI\nVeillez à ce qu'il ait 11 chiffres et pas de lettres"));
   }
   else if (result == -3)
       QMessageBox::critical(this, "Erreur", QString::fromStdString("Le numéro inami donné n'est pas un " + i + " mais un " + j ));
   else {
       QMessageBox::information(this, "Succès", QString::fromStdString("Votre changement de " + i + " a été appliqué"));
   }
}

