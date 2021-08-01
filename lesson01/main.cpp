#include "widget.h"     // 包含我们自己写的类的头文件

#include <QApplication>  // 应用程序类
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  //创建一个应用程序类，必须要有，有且只能有一个
    QLabel label("hello QT!");   //创建标签控件
    label.show();
//    QPushButton Button("I'm a Button!");
//    Button.show();
//    QCheckBox chbox("我是一个选择框！");
//    chbox.show();

//    Widget w;   //创建窗口对象
//    w.show();   //手动显示窗口

    return app.exec();  // 应用程序消息循环
}
