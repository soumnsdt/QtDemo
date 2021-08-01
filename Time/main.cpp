#include "TimeDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeDialog time;
    time.show();
    return a.exec();
}
