#include "dialog.h"

#include <QApplication>

#include <QWidget>
#include <QMainWindow>
#include <QDialog>

#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog parent;
//    parent.move(50,50);
    parent.resize(320,240);

    // 创建标签控件，停靠在父窗口上面
    QLabel label("我是标签",&parent);
    label.move(120,40);

    // 创建按钮控件，停靠在父窗口上面
    QPushButton Button("关闭标签",&parent);
    Button.move(120,100);
    Button.resize(80,40);

//    QPushButton* button2 = new QPushButton("退出",&parent);
//    button2->move(120,150);
//    button2->resize(80,40);
    QPushButton Button2("退出",&parent);
    Button2.move(120,150);
    Button2.resize(80,40);


    parent.show();//父窗口显示，上面停靠的控件也将一起显示

    // 点击按钮关闭标签
    QObject::connect(&Button,SIGNAL(clicked(void)),
                     &label,SLOT(close(void)));

    QObject::connect(&Button2,SIGNAL(clicked(void)),
//                     &parent,SLOT(close(void)));
//                     &a,SLOT(closeAllWindows(void)));
                     &a,SLOT(quit(void)));

    return a.exec();
}
