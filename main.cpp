#include "mainwindow.h"

#include <QApplication>
#include <QAxWidget>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QAxWidget* ieWidget = new QAxWidget(&w);

    // Set the CLSID for Internet Explorer control
    if (!ieWidget->setControl("{8856F961-340A-11D0-A96B-00C04FD705A2}")) {
        QMessageBox::critical(nullptr, "Error", "Could not initiate Internet Explorer ActiveX control");
        return -1;
    }

    w.show();
    return a.exec();
}
