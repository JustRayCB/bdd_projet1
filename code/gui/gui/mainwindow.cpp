#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QStandardItemModel>
#include <QStandardItem>
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
   std::string gender = ui->genderPatient->currentText().trimmed().toStdString();
   if (gender == "Homme")
       gender = "1";
   else if (gender == "Femme")
       gender = "2";
   else
       gender = "3";
   std::string birth = ui->birthPatient->text().trimmed().toStdString();
   std::string mail = ui->mailPatient->text().trimmed().toStdString();
   std::string phone= ui->phonePatient->text().trimmed().toStdString();
   std::string pharmacien = ui->refP->text().trimmed().toStdString();
   std::string medecin = ui->refM->text().trimmed().toStdString();

   int res = db.insertPatient(niss, name, fname, gender, birth, mail, phone, pharmacien, medecin);
   // int res = 0;
   //qDebug() << "Voici la date : " << birth;
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
       ui->nissPatient->clear();
       ui->namePatient->clear();
       ui->fnamePatient->clear();
       ui->birthPatient->clear();
       ui->mailPatient->clear();
       ui->phonePatient->clear();
       ui->refP->clear();
       ui->refM->clear();
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
   if (ui->comboBox_Dos->currentIndex() == 0) {
       ui->lineEdit_Med->hide();
       ui->labelMedDCI->hide();
       ui->labelDateDelivrance->hide();
       ui->labelDatePrescription->hide();
       ui->labelMedNom->hide();
       ui->dateEdit->hide();
   }
   ui->pages->setCurrentIndex(DOSSIER);
}


void MainWindow::on_actionM_dicament_triggered()
{
   if (ui->comboBox->currentIndex() == 0) {
       ui->medicamentLabelDCI->hide();
       ui->medicamentLineEditDCI->hide();
       ui->medicamentlabelDate->hide();
       ui->dateEdit2->hide();
   }
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
   std::string inami = ui->inamiM->text().trimmed().toStdString();
   std::string name = ui->nameM->text().trimmed().toStdString();
   std::string phone = ui->phoneM->text().trimmed().toStdString();
   std::string mail = ui->mailM->text().trimmed().toStdString();
   std::string specialisation = ui->specM->text().trimmed().toStdString();

   int res = db.insertMedecin(inami, name, mail, phone, specialisation);
   std::string error;

   if (res ==  -1){
       error = "Le médecin est déjà dans a bade de donnée !!";
       ui->inamiM->clear();
   }
   else if (res == -2) {
       error= "L'INAMI appartient à un Pharmacien !!";
       ui->inamiM->clear();
   }
   else if (res == -3){
       error= "Certains champs sont vide, veuillez les remplir !!";
   }
   else if (res == -4){
       error= "Veuillez rentrer un numéro INAMI valide !!";
       ui->inamiM->clear();
   }
   else if (res == -5) {
       error = "Veuillez rentre un mail valide !!";
       ui->mailM->clear();
   }
   else if (res == -6){
       error = "Veuillez rentrer un numéro de téléphone valide !!";
       ui->phoneM->clear();
   }
   else if (res == -7){
       error = "La spécialisation entré n'existe pas !!";
       ui->specM->clear();
   }
   else {
       ui->inamiM->clear();
       ui->nameM->clear();
       ui->phoneM->clear();
       ui->mailM->clear();
       ui->specM->clear();

       QMessageBox::information(this, "Succès", "Inscription du nouveau médecin à été effectuée avec succès !!");
       return;
   }
   QMessageBox::warning(this, "Erreur", QString::fromStdString(error));


}


void MainWindow::on_signPhar_clicked()
{
   std::string inami = ui->inamiP->text().trimmed().toStdString();
   std::string name = ui->namePhar->text().trimmed().toStdString();
   std::string phone = ui->phonePhar->text().trimmed().toStdString();
   std::string mail = ui->mailPhar->text().trimmed().toStdString();

   int res = db.insertPharmacien(inami, name, mail, phone);
   std::string error;

   if (res ==  -1){
       error = "Le pharmacien est déjà dans a bade de donnée !!";
       ui->inamiP->clear();
   }
   else if (res == -2) {
       error= "L'INAMI appartient à un Médecin!!";
       ui->inamiP->clear();
   }
   else if (res == -3){
       error= "Certains champs sont vide, veuillez les remplir !!";
   }
   else if (res == -4){
       error= "Veuillez rentrer un numéro INAMI valide !!";
       ui->inamiP->clear();
   }
   else if (res == -5) {
       error = "Veuillez rentre un mail valide !!";
       ui->mailPhar->clear();
   }
   else if (res == -6){
       error = "Veuillez rentrer un numéro de téléphone valide !!";
       ui->phonePhar->clear();
   }
   else {
       ui->inamiP->clear();
       ui->namePhar->clear();
       ui->phonePhar->clear();
       ui->mailPhar->clear();

       QMessageBox::information(this, "Succès", "Inscription du nouveau pharmacien à été effectuée avec succès !!");
       return;
   }
   QMessageBox::warning(this, "Erreur", QString::fromStdString(error));


}


void MainWindow::on_boutonLoadDossier_clicked()
{
   QTableView *tableView = ui->tableViewDossier;
   QStandardItemModel *model = new QStandardItemModel(this);
   tableView->setModel(model);
   std::vector<std::string> fields;
   sql::ResultSet *res;
   QString query;
   QString Nom=ui->lineEdit_Med->text();
   QString date2=ui->dateEdit->text();

   if (ui->comboBox_Dos->currentIndex()==1){
       // QUERY 4
       fields = {"Niss", "Nom",  "Prenom", "Mail", "NumTel"};
       query="SELECT DISTINCT d.Niss,d.Nom,d.Prenom,d.Mail,d.NumTel FROM Dossier d JOIN Prescription p ON d.Niss=p.DossierID JOIN PharmacienDelivreMedicament pdm ON p.ID=pdm.PrescriptionID WHERE p.MedicamentNom='"+Nom+"' AND pdm.DateDelivrance>'"+date2+"'";
   } else if (ui->comboBox_Dos->currentIndex()==2){
       // QUERY 5
       fields = {"Niss", "Nom",  "Prenom", "Mail", "NumTel"};
       query="SELECT DISTINCT d.Niss,d.Nom,d.Prenom,d.Mail,d.NumTel FROM Dossier d JOIN Prescription p ON d.Niss=p.DossierID JOIN PharmacienDelivreMedicament pdm ON p.ID=pdm.PrescriptionID JOIN Medicament m ON pdm.MedicamentID=m.ID WHERE p.DatePrescription<'"+date2+"' AND DATE_ADD(pdm.DateDelivrance,INTERVAL p.DureeTraitement DAY)<'"+date2+"' AND m.DCI='"+Nom+"'";
   } else if (ui->comboBox_Dos->currentIndex()==3){
       // QUERY 9
       fields = {"Niss", "Nom",  "Prenom", "NombreMedecinsPrescripteurs"};
       query = "SELECT D.Niss,D.Nom,D.Prenom, COUNT(DISTINCT P.MedecinINAMI) AS NombreMedecinsPrescripteurs FROM Dossier D LEFT JOIN Prescription P ON D.Niss=P.DossierID GROUP BY D.Niss,D.Nom,D.Prenom";
   } else {
       fields = {"Niss","Nom",  "Prenom", "Genre","DateNaissance", "Mail", "NumTel", "PharmacienINAMI","MedecinINAMI"};
       query = "SELECT * FROM Dossier";
   }
   res = db.getResFromQuery(query.toStdString());
   int nbCol = fields.size();
   model->setColumnCount(nbCol);
   for (int idx = 0; idx<nbCol; idx++) {
       model->setHeaderData(idx, Qt::Horizontal, QString::fromStdString(fields[idx]));
   }
   int row=0;
   while (res->next()) {
       for (int col=0; col<nbCol; col++) {
           QString data = QString::fromStdString(res->getString(fields[col]));
           model->setItem(row,col,new QStandardItem(data));
       }
       row++;
   }
}

void MainWindow::on_boutonLoadMedicament_clicked()
{
   QTableView *tableView = ui->tableViewMedicament;
   QStandardItemModel *model = new QStandardItemModel(this);
   tableView->setModel(model);

   std::vector<std::string> fields;
   sql::ResultSet *res;
   QString query;

   QString DCI=ui->medicamentLineEditDCI->text();
   QString date=ui->dateEdit2->text();
   if (ui->comboBox->currentIndex()==1){
       // QUERY 1
       fields = {"Nom", "Conditionnement"};
       query="SELECT distinct m.Nom, m.Conditionnement FROM Medicament AS m WHERE m.DCI='"+DCI+"' AND m.NOM IS NOT NULL ORDER BY m.NOM,m.Conditionnement ";
   } else if (ui->comboBox->currentIndex()==2) {
       // QUERY 7
       fields = {"Decade", "Medicament", "Nombre_Patients"};
       query="SELECT CONCAT(Decade, '0') As Decade, Medicament,Nombre_Patients FROM (SELECT SUBSTRING(d.DateNaissance, 1, 3) AS Decade,m.Nom AS Medicament,COUNT(*) AS Nombre_Patients,ROW_NUMBER() OVER (PARTITION BY SUBSTRING(d.DateNaissance, 1, 3) ORDER BY COUNT(*) DESC) AS RowNum FROM Dossier AS d JOIN Prescription AS p ON d.Niss = p.DossierID JOIN Medicament AS m ON p.MedicamentNom = m.Nom WHERE SUBSTRING(d.DateNaissance, 1, 3) BETWEEN '195' AND '202' GROUP BY Decade, Medicament) AS T WHERE RowNum = 1 ORDER BY Decade;";
   } else if (ui->comboBox->currentIndex()==3) {
       // QUERY 10
       fields = {"MedicamentNom"};
       query = "SELECT DISTINCT MedicamentNom FROM Prescription WHERE DatePrescription <'"+date+"'";
   } else {
       fields = {"ID", "DCI",  "Nom", "Conditionnement", "SystemeAnatomiqueNom"};
       query = "SELECT * FROM Medicament";
   }
   res = db.getResFromQuery(query.toStdString());
   int nbCol = fields.size();
   model->setColumnCount(nbCol);
   for (int idx = 0; idx<nbCol; idx++) {
       model->setHeaderData(idx, Qt::Horizontal, QString::fromStdString(fields[idx]));
   }
   int row=0;
   while (res->next()) {
       for (int col=0; col<nbCol; col++) {
           QString data = QString::fromStdString(res->getString(fields[col]));
           model->setItem(row,col,new QStandardItem(data));
       }
       row++;
   }
}


void MainWindow::on_boutonLoadPathologie_clicked()
{
   QTableView *tableView = ui->tableViewPathologie;
   QStandardItemModel *model = new QStandardItemModel(this);
   tableView->setModel(model);

   std::vector<std::string> fields;
   sql::ResultSet *res;
   QString query;

   if (ui->comboBox_2->currentIndex()==1){
       // QUERY 2
       fields = {"Nom"};
       query = "SELECT p.Nom FROM Pathologie p GROUP BY p.Nom HAVING COUNT(DISTINCT p.SpecialisationNom)=1";
   } else  if (ui->comboBox_2->currentIndex()==2){
       // QUERY 8
       fields = {"PathologieNom", "NombreDiagnostiques"};
       query = "SELECT PathologieNom, COUNT(*) AS NombreDiagnostiques FROM DossierContientPathologie GROUP BY PathologieNom ORDER BY NombreDiagnostiques DESC LIMIT 1;";
   } else {
       fields = {"Nom", "SpecialisationNom"};
       query = "SELECT * FROM Pathologie";
   }
   res = db.getResFromQuery(query.toStdString());
   int nbCol = fields.size();
   model->setColumnCount(nbCol);
   for (int idx = 0; idx<nbCol; idx++) {
       model->setHeaderData(idx, Qt::Horizontal, QString::fromStdString(fields[idx]));
   }
   int row=0;
   while (res->next()) {
       for (int col=0; col<nbCol; col++) {
           QString data = QString::fromStdString(res->getString(fields[col]));
           model->setItem(row,col,new QStandardItem(data));
       }
       row++;
   }
}


void MainWindow::on_boutonLoadMedecin_clicked()
{
   QTableView *tableView = ui->tableViewMedecin;
   QStandardItemModel *model = new QStandardItemModel(this);
   tableView->setModel(model);

   std::vector<std::string> fields;
   sql::ResultSet *res;
   QString query;

   if (ui->comboBoxMedecin->currentIndex() == 1){
       // QUERY 6
       fields = {"INAMI", "Nom"};
       query = "SELECT M.INAMI, M.Nom FROM Medecin M INNER JOIN Prescription P ON M.INAMI = P.MedecinINAMI INNER JOIN Medicament Med ON P.MedicamentNom = Med.Nom LEFT JOIN Specialisation S ON M.SpecialisationNom = S.Nom LEFT JOIN SpecialisationSpecialiseSysAnatomique SSA ON S.Nom = SSA.SpecialisationNom LEFT JOIN SystemeAnatomique SA ON SSA.SystemeAnatomiqueNom = SA.Nom WHERE Med.SystemeAnatomiqueNom NOT IN ( SELECT SSA.SystemeAnatomiqueNom FROM SpecialisationSpecialiseSysAnatomique SSA WHERE SSA.SpecialisationNom = M.SpecialisationNom) OR (Med.SystemeAnatomiqueNom IS NULL AND M.SpecialisationNom IS NOT NULL) GROUP BY M.INAMI, M.Nom, M.NumTel, M.Mail, M.SpecialisationNom;";
   } else {
       fields = {"INAMI", "Nom", "NumTel", "Mail", "SpecialisationNom"};
       query = "SELECT * FROM Medecin";
   }
   res = db.getResFromQuery(query.toStdString());
   int nbCol = fields.size();
   model->setColumnCount(nbCol);
   for (int idx = 0; idx<nbCol; idx++) {
       model->setHeaderData(idx, Qt::Horizontal, QString::fromStdString(fields[idx]));
   }
   int row=0;
   while (res->next()) {
       for (int col=0; col<nbCol; col++) {
           QString data = QString::fromStdString(res->getString(fields[col]));
           model->setItem(row,col,new QStandardItem(data));
       }
       row++;
   }
}



void MainWindow::on_boutonLoadSpecialite_clicked()
{
   QTableView *tableView = ui->tableViewSpecialite;
   QStandardItemModel *model = new QStandardItemModel(this);
   tableView->setModel(model);

   std::vector<std::string> fields;
   sql::ResultSet *res;
   QString query;

   if (ui->comboBoxSpecialite->currentIndex() == 1){
       // QUERY 3
       fields = {"SpecialisationNom", "total_prescriptions"};
       query = "SELECT m.SpecialisationNom, COUNT(*) AS total_prescriptions FROM Medecin m JOIN Prescription p ON m.INAMI = p.MedecinINAMI GROUP BY m.SpecialisationNom ORDER BY total_prescriptions DESC LIMIT 1;";
   } else {
       fields = {"Nom"};
       query = "SELECT * FROM Specialisation";
   }
   res = db.getResFromQuery(query.toStdString());
   int nbCol = fields.size();
   model->setColumnCount(nbCol);
   for (int idx = 0; idx<nbCol; idx++) {
       model->setHeaderData(idx, Qt::Horizontal, QString::fromStdString(fields[idx]));
   }
   int row=0;
   while (res->next()) {
       for (int col=0; col<nbCol; col++) {
           QString data = QString::fromStdString(res->getString(fields[col]));
           model->setItem(row,col,new QStandardItem(data));
       }
       row++;
   }
}


void MainWindow::on_comboBox_Dos_activated(int index)
{
   if (index==0) {
       // LOAD
       ui->lineEdit_Med->hide();
       ui->labelMedDCI->hide();
       ui->labelDateDelivrance->hide();
       ui->labelDatePrescription->hide();
       ui->labelMedNom->hide();
       ui->dateEdit->hide();
   } else if (index==1) {
       // QUERY 4
       ui->lineEdit_Med->show();
       ui->labelMedDCI->hide();
       ui->labelDateDelivrance->show();
       ui->labelDatePrescription->hide();
       ui->labelMedNom->show();
       ui->dateEdit->show();
   } else if (index==2) {
       // QUERY 5
       ui->lineEdit_Med->show();
       ui->labelMedDCI->show();
       ui->labelDateDelivrance->hide();
       ui->labelDatePrescription->show();
       ui->labelMedNom->hide();
       ui->dateEdit->show();

   } else if (index==3) {
       // QUERY 9
       ui->lineEdit_Med->hide();
       ui->labelMedDCI->hide();
       ui->labelDateDelivrance->hide();
       ui->labelDatePrescription->hide();
       ui->labelMedNom->hide();
       ui->dateEdit->hide();
   }
}


void MainWindow::on_comboBox_activated(int index)
{
   if (index==0) {
       // LOAD
       ui->medicamentLabelDCI->hide();
       ui->medicamentLineEditDCI->hide();
       ui->medicamentlabelDate->hide();
       ui->dateEdit2->hide();
   } else if (index==1) {
       // QUERY 1
       ui->medicamentLabelDCI->show();
       ui->medicamentLineEditDCI->show();
       ui->medicamentlabelDate->hide();
       ui->dateEdit2->hide();
   } else if (index==2) {
       // QUERY 7
       ui->medicamentLabelDCI->hide();
       ui->medicamentLineEditDCI->hide();
       ui->medicamentlabelDate->hide();
       ui->dateEdit2->hide();
   } else if (index==3) {
       // QUERY 10
       ui->medicamentLabelDCI->hide();
       ui->medicamentLineEditDCI->hide();
       ui->medicamentlabelDate->show();
       ui->dateEdit2->show();
   }
}

