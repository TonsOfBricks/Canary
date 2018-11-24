#include "canarygui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CanaryGui w;
    w.show();

    return a.exec();
}
