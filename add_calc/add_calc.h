#ifndef __ADD_CALC_H
#define __ADD_CALC_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDoubleValidator> // 验证器

class Add_Calc:public QWidget{
    Q_OBJECT   //MOC
public:
    Add_Calc();
public slots:
    void enableButton(void);
    void calcClicked(void);
private:
    QLineEdit* m_editX;
    QLineEdit* m_editY;
    QLineEdit* m_editZ;
    QLabel* m_label;
    QPushButton* m_Button;
};

#endif // ADD_CALC_H
