#include "MainWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(1000, 1000);
    w.show();
    return a.exec();
}