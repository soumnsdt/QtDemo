#include "Add_Calc.h"


// 构造函数
Add_Calc::Add_Calc(void)
{
    // 界面初始化
    setWindowTitle("加法计算器");

    // 左操作数，this为当前父窗口指针
    m_editX = new QLineEdit(this);
    // 设置文本对齐：右对齐
    m_editX->setAlignment(Qt::AlignRight);
    // 设置数字验证器，只能输入数字形式内容
    m_editX->setValidator(new QDoubleValidator(this));

    // 右操作数，this为当前父窗口指针
    m_editY = new QLineEdit(this);
    // 设置文本对齐：右对齐
    m_editY->setAlignment(Qt::AlignRight);
    // 设置数字验证器，只能输入数字形式内容
    m_editY->setValidator(new QDoubleValidator(this));

    // 显示结果，this为当前父窗口指针
    m_editZ = new QLineEdit(this);
    // 设置文本对齐：右对齐
    m_editZ->setAlignment(Qt::AlignRight);
    // 设置显示结果只读
    m_editZ->setReadOnly(true);

    // +
    m_label = new QLabel("+",this);

    // =
    m_Button = new QPushButton("=",this);
    m_Button->setEnabled(false);  // 设置禁用

    // 创建布局器
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_editX);
    layout->addWidget(m_label);
    layout->addWidget(m_editY);
    layout->addWidget(m_Button);
    layout->addWidget(m_editZ);

    //设置布局器
    setLayout(layout);


    // 信号和槽函数的连接
    // 左右操作数文本改变时，发送信号textChangeed()
    connect(m_editX,SIGNAL(textChanged(QString)),
            this,SLOT(enableButton(void)));
    connect(m_editY,SIGNAL(textChanged(QString)),
            this,SLOT(enableButton(void)));
    connect(m_Button,SIGNAL(clicked(void)),
            this,SLOT(calcClicked(void)));
}
// 使能等号按钮的槽操作数
void Add_Calc::enableButton(void)
{
    bool bXok,bYok;
    m_editX->text().toDouble(&bXok);
    m_editY->text().toDouble(&bYok);
    m_Button->setEnabled(bXok && bYok);
}

void Add_Calc::calcClicked(void)
{
    double res = m_editX->text().toDouble() +
            m_editY->text().toDouble();
    QString str = QString::number(res);
    m_editZ->setText(str);
}
