#include "loginadmin.h"
#include "ui_loginadmin.h"

Loginadmin::Loginadmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Loginadmin)
{
    ui->setupUi(this);
}

Loginadmin::~Loginadmin()
{
    delete ui;
}
