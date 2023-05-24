#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    Database db;
    enum {LOGIN, PATIENT_ACCOUNT, SIGN_PATIENT, SIGN_MEDECIN, SIGN_PHARMA, DOSSIER, MEDICAMENT, PATHOLOGIE, MEDECIN, SPECIALITE};
};
#endif // MAINWINDOW_HPP
