#include "dialog.h"

#include <QApplication>

#include <QWidget>
#include <QMainWindow>
#include <QDialog>

#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog parent;
    parent.resize(320,240);

    QSlider slider(Qt::Horizontal,&parent);
    slider.move(20,100);
    slider.resize(150,20);
    slider.setRange(0, 100);

    QSpinBox spinbox(&parent);
    spinbox.move(200,95);
    spinbox.resize(60,30);
    spinbox.setRange(0, 100);

    QObject::connect(&slider,SIGNAL(valueChanged(int)),
                     &spinbox,SLOT(setValue(int)));

    QObject::connect(&spinbox,SIGNAL(valueChanged(int)),
                     &slider,SLOT(setValue(int)));



    parent.show();
    return a.exec();
}
