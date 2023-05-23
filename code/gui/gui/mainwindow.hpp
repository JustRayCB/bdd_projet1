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

private:
    Ui::MainWindow *ui;
    Database db;
    enum {LOGIN, PATIENT_ACCOUNT};
};
#endif // MAINWINDOW_HPP
