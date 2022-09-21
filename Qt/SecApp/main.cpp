#include "mainwindow.h"

#include <QApplication>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QQuickStyle::setStyle("Fusion");
    a.setWindowIcon(QIcon(":/icon.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
