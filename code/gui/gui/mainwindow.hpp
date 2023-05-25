#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include "database.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_connectionButton_clicked();

    void on_submit_clicked();

    void on_actionPatient_triggered();

    void on_actionPharmacien_triggered();

    void on_actionMedecin_triggered();

    void on_signPatient_2_clicked();

    void on_actionM_decin_triggered();

    void on_actionDossier_triggered();

    void on_actionM_dicament_triggered();

    void on_actionPathologie_triggered();

    void on_actionSp_cialit_triggered();

    void on_signM_clicked();

    void on_signPhar_clicked();

    void on_boutonLoadDossier_clicked();

    void on_boutonLoadMedicament_clicked();

    void on_boutonLoadPathologie_clicked();

    void on_boutonLoadMedecin_clicked();

    void on_boutonLoadSpecialite_clicked();

    void on_comboBox_Dos_activated(int index);

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    Database db;
    enum {LOGIN, PATIENT_ACCOUNT, SIGN_PATIENT, SIGN_MEDECIN, SIGN_PHARMA, DOSSIER, MEDICAMENT, PATHOLOGIE, MEDECIN, SPECIALITE};
};
#endif // MAINWINDOW_HPP
