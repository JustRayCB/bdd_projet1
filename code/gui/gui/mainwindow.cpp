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


void MainWindow::on_actionPatient_triggered()
{
   ui->pages->setCurrentIndex(SIGN_PATIENT);
}


void MainWindow::on_actionPharmacien_triggered()
{
   ui->pages->setCurrentIndex(SIGN_PHARMA);
}


void MainWindow::on_actionMedecin_triggered()
{
   ui->pages->setCurrentIndex(SIGN_MEDECIN);

}


void MainWindow::on_signPatient_2_clicked()
{
   std::string niss = ui->nissPatient->text().trimmed().toStdString();
   std::string name = ui->namePatient->text().trimmed().toStdString();
   std::string fname= ui->fnamePatient->text().trimmed().toStdString();
   std::string gender = ui->genderPatient->text().trimmed().toStdString();
   std::string birth = ui->birthPatient->text().trimmed().toStdString();
   std::string mail = ui->mailPatient->text().trimmed().toStdString();
   std::string phone= ui->phonePatient->text().trimmed().toStdString();
   std::string pharmacien = ui->refP->text().trimmed().toStdString();
   std::string medecin = ui->refM->text().trimmed().toStdString();

   int res = db.insertPatient(niss, name, fname, gender, birth, mail, phone, pharmacien, medecin);
   std::string error;

   if (res ==  -1){
       error = "Le patient possède déjà un dossier !!";
       ui->nissPatient->clear();
   }
   else if (res == -2) {
       error= "Certains champs sont vide, veuillez les remplir !!";
   }
   else if (res == -3){
       error = "Veuillez rentrer un NISS valide";
       ui->nissPatient->clear();
   }
   else if (res == -4){
       error= "Veuillez rentrer un mail valide !!";
       ui->mailPatient->clear();
   }
   else if (res == -5) {
       error = "Veuillez rentre un numéro de téléphone valide !!";
       ui->phonePatient->clear();
   }
   else if (res == -6){
       error = "Veuillez rentrer une date de naissance valide !!";
       ui->birthPatient->clear();
   }
   else {
       ui->nissPatient->text().clear();
       ui->namePatient->text().clear();
       ui->fnamePatient->text().clear();
       ui->genderPatient->text().clear();
       ui->birthPatient->text().clear();
       ui->mailPatient->text().clear();
       ui->phonePatient->text().clear();
       ui->refP->text().clear();
       ui->refM->text().clear();
       QMessageBox::information(this, "Succès", "Inscription du nouveau patient effectuée avec succès");
       return;
   }
   QMessageBox::warning(this, "Erreur", QString::fromStdString(error));

}


void MainWindow::on_actionM_decin_triggered()
{
   ui->pages->setCurrentIndex(MEDECIN);
}


void MainWindow::on_actionDossier_triggered()
{
   ui->pages->setCurrentIndex(DOSSIER);
}


void MainWindow::on_actionM_dicament_triggered()
{
   ui->pages->setCurrentIndex(MEDICAMENT);
}


void MainWindow::on_actionPathologie_triggered()
{
   ui->pages->setCurrentIndex(PATHOLOGIE);
}


void MainWindow::on_actionSp_cialit_triggered()
{
   ui->pages->setCurrentIndex(SPECIALITE);
}


void MainWindow::on_signM_clicked()
{

}


void MainWindow::on_signPhar_clicked()
{

}

