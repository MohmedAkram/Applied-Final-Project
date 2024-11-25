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

void AccountPage::on_NameLine_cursorPositionChanged(int arg1, int arg2)
{

}


void AccountPage::on_EmailLine_cursorPositionChanged(int arg1, int arg2)
{

}


void AccountPage::on_IDLine_cursorPositionChanged(int arg1, int arg2)
{

}


void AccountPage::on_MemStautsLine_cursorPositionChanged(int arg1, int arg2)
{

}


void AccountPage::on_BalanceLine_cursorPositionChanged(int arg1, int arg2)
{

}

