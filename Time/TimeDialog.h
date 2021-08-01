#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTime>
#include <QDebug>


class TimeDialog:public QDialog
{
    Q_OBJECT
public:
    // 构造函数
    TimeDialog(void);
public slots:
    // 获取系统的槽函数
    void getTime(void);
private:
    QLabel* m_label;
    QPushButton* m_button;
};

#endif // TIMEDIALOG_H
