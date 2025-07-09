#include "clip.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clip w;
    w.show();
    return a.exec();
}
