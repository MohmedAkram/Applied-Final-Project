#include "creditcardwidget.h"

CreditCardWidget::CreditCardWidget(Customer* c,QWidget *parent)
    : QWidget(parent),
    cardNumberLineEdit(new QLineEdit(this)),
    cvcLineEdit(new QLineEdit(this)),
    checkoutButton(new QPushButton("Checkout", this)) {

    setupUI();
    cust = c;

    connect(checkoutButton, &QPushButton::clicked, this, &CreditCardWidget::onCheckoutClicked);
}

void CreditCardWidget::setupUI() {
    // Configure line edits
    cardNumberLineEdit->setPlaceholderText("Enter Card Number");
    cardNumberLineEdit->setMaxLength(16);
    cardNumberLineEdit->setStyleSheet(
        "padding: 10px; font-size: 18px; border: 2px solid #FF69B4; border-radius: 5px;"
        );

    cvcLineEdit->setPlaceholderText("Enter CVC");
    cvcLineEdit->setMaxLength(3);
    cvcLineEdit->setEchoMode(QLineEdit::Password);
    cvcLineEdit->setStyleSheet(
        "padding: 10px; font-size: 18px; border: 2px solid #FF69B4; border-radius: 5px;"
        );

    // Configure the button
    checkoutButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;"
        );

    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 40, 40, 40);
    mainLayout->setSpacing(20);

    mainLayout->addWidget(cardNumberLineEdit);
    mainLayout->addWidget(cvcLineEdit);
    mainLayout->addWidget(checkoutButton);

    setLayout(mainLayout);
    setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;");
    setFixedSize(400, 300);
    setWindowTitle("Credit Card Checkout");
}

void CreditCardWidget::onCheckoutClicked() {
    QString cardNumber = cardNumberLineEdit->text();
    QString cvc = cvcLineEdit->text();

    if (cardNumber.isEmpty() || cvc.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    if (cardNumber.length() != 16 || cvc.length() != 3) {
        QMessageBox::warning(this, "Error", "Invalid card number or CVC.");
        return;
    }

    hide();
    AccountPage* a = new AccountPage(cust);
    a->show();



}
