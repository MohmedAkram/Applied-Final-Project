#include "accountpage.h"
#include "ui_accountpage.h"

AccountPage::AccountPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AccountPage)
{
    ui->setupUi(this);
}

AccountPage::~AccountPage()
{
    delete ui;
}
