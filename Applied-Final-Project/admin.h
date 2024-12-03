#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    AdminWindow(QWidget* parent = nullptr);
    ~AdminWindow();

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* addAdminButton;
    QPushButton* removeAdminButton;
    QPushButton* logoutButton;

    void setupUI();

};

#endif // ADMINWINDOW_H

