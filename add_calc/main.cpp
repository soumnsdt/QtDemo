#include "widget.h"
#include "Add_Calc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Add_Calc calc;
    calc.show();
    return a.exec();
}
