#include "reserved.h"
#include "ui_reserved.h"

Reserved::Reserved(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Reserved)
{
    ui->setupUi(this);

}

Reserved::~Reserved()
{
    delete ui;
}
