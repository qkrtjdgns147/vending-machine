#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    changeEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);

    changeEnable();
}

void Widget::changeEnable() {
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbTang->setEnabled(money >= 300);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    int rs500, rs100, rs50, rs10;

    rs500 = money / 500;
    money %= 500;

    rs100 = money / 100;
    money = money % 100;

    rs50 = money / 50;
    money = money % 50;

    rs10 = money / 10;
    money = money % 10;

    QString msg = "";
    if (rs500) {
        msg += "500 : " + QString::number(rs500);
    }
    if (rs100) {
        if (msg != "") {
            msg = msg + "\n";
        }
        msg = msg + "100 : " + QString::number(rs100);
    }
    if (rs50) {
        if (msg != "") {
            msg = msg + "\n";
        }
        msg = msg + "50 : " + QString::number(rs50);
    }
    if (rs10) {
        if (msg != "") {
            msg = msg + "\n";
        }
        msg += "10 : " + QString::number(rs10);
    }

    if (msg == "") {
        msg = "No money to return.";
    }

    QMessageBox mb;
    mb.information(nullptr, "title", msg);

    changeMoney(0);
}

