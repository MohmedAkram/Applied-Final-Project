// #include "halls.h"



// Halls::Halls(int id, string t, QWidget *parent)
//     : QWidget(parent), hallID(id), time(t)  // Call QWidget constructor
// {
//     // Set the style for the Halls widget
//     QString widgetStyle =
//         "background-color: #e9ecef;"    // Light gray-blue background
//         "border-radius: 12px;"          // Rounded corners for the widget
//         "border: 2px solid #007bff;"    // Blue border
//         "padding: 15px;";               // Padding for a clean layout

//     setStyleSheet(widgetStyle);

//     // Create the buttons dynamically
//     QPushButton *button1 = new QPushButton("Button 1", this);
//     QPushButton *button2 = new QPushButton("Button 2", this);
//     QPushButton *button3 = new QPushButton("Button 3", this);

//     // Define a consistent style for the buttons
//     QString buttonStyle =
//         "background-color: #007bff;"    // Blue background
//         "color: white;"                 // White text color
//         "font-size: 16px;"              // Medium font size
//         "font-weight: bold;"            // Bold text
//         "padding: 10px 20px;"           // Comfortable padding
//         "border-radius: 8px;"           // Rounded corners
//         "border: 2px solid #0056b3;"    // Border to match button color
//         "transition: background-color 0.3s ease;"  // Smooth hover transition
//         ""
//         "QPushButton:hover {"
//         "  background-color: #0056b3;"  // Darker blue on hover
//         "  border-color: #003f7f;"      // Darker border on hover
//         "}";

//     // Apply the style to all buttons
//     button1->setStyleSheet(buttonStyle);
//     button2->setStyleSheet(buttonStyle);
//     button3->setStyleSheet(buttonStyle);

//     // Create a layout to organize the buttons
//     QVBoxLayout *layout = new QVBoxLayout(this);
//     layout->addWidget(button1); // Add Button 1 to the layout
//     layout->addWidget(button2); // Add Button 2 to the layout
//     layout->addWidget(button3); // Add Button 3 to the layout

//     // Set the layout for the current widget
//     setLayout(layout);
//     // QVector<bool> vipSeats = {
//     //     false, false, false, false, false, false, false, false, false, false,
//     //     false, false, false, false, false, false, false, false, false, false,    // false = regular seats
//     //     true, true, true, true, true, true, true, true, true, true,              // true = vip seats
//     //     true, true, true, true, true, true, true, true, true, true
//     // };


// //     QObject::connect(button1, &QPushButton::clicked, [s1]() {
// //         Seats s1;
// //         s1->show();       // Show Login window
// //     });
// // }



// Halls::~Halls()
// {
//     // Destructor implementation (if necessary)
// }

