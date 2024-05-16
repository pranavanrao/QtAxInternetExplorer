#include "mainwindow.h"

#include <QApplication>
#include <QAxWidget>
#include <QMessageBox>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QAxWidget* ieWidget = new QAxWidget(&w);

    QSize mainWindowSize = w.size();

    if (!ieWidget->setControl("{8856F961-340A-11D0-A96B-00C04FD705A2}")) {
        QMessageBox::critical(nullptr, "Error", "Could not initiate Internet Explorer ActiveX control");
        return -1;
    }

    ieWidget->setGeometry(0, 0, mainWindowSize.width(), mainWindowSize.height());

    QString url = "https://upload.wikimedia.org/wikipedia/commons/thumb/8/81/Qt_logo_neon_2022.svg/1200px-Qt_logo_neon_2022.svg.png"; // Replace with your URL
    ieWidget->dynamicCall("Navigate(const QString&)", url);

     w.setCentralWidget(ieWidget);

    w.show();
    return a.exec();
}
