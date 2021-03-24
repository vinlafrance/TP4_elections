#include "tp4.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TP4 w;
    w.show();
    return a.exec();
}
