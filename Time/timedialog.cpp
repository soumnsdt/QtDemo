#include "TimeDialog.h"
#include <QFrame>

// 构造函数
TimeDialog::TimeDialog(void)
{
    // 初始化界面
    m_label = new QLabel(this);
    m_label->setFrameStyle(QFrame::Panel|QFrame::Sunken);   // 设置label边框消息：凹陷面板
    m_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);  // 设置label文本对齐方式：水平、垂直居中
    QFont font;// 设置label的字体大小
    font.setPointSize(20);
    m_label->setFont(font);

    m_button = new QPushButton("获取当前系统时间",this);
    m_button->setFont(font);

    // 创建垂直布局器
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(m_button);
    // 设置布局器
    setLayout(layout);

    // 信号和槽函数连接
    connect(m_button,SIGNAL(clicked()),
            this,SLOT(getTime()));
}
void TimeDialog::getTime(void)
{
    qDebug("getTime");
//    qDebug() << "getTime";
    // 获取当前的时间
    QTime time = QTime::currentTime();
    // 将时间对象转换成字符串
    QString str = time.toString("hh:mm:ss");
    // 显示当前时间
    m_label->setText(str);
}
