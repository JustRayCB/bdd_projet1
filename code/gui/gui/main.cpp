#include "mainwindow.hpp"

#include <QApplication>
#include <QDir>
#include <QCoreApplication>
/*
 * The login pic comes from here
 * https://www.flaticon.com/free-icons/login" title="login icons">Login icons created by berkahicon - Flaticon
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
