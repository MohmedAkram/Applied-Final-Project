#ifndef RESERVED_H
#define RESERVED_H

#include <QDialog>

namespace Ui {
class Reserved;
}

class Reserved : public QDialog
{
    Q_OBJECT

public:
    explicit Reserved(QWidget *parent = nullptr);
    ~Reserved();

private:
    Ui::Reserved *ui;
};

#endif // RESERVED_H
