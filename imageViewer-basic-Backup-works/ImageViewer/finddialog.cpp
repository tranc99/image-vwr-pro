#include <QtGui>
 #include "finddialog.h"

 FindDialog::FindDialog(QWidget *parent)
     : QDialog(parent)
 {
     QLabel *findLabel = new QLabel(tr("Enter the filename:"));
     lineEdit = new QLineEdit;

     findButton = new QPushButton(tr("&Find"));
     findText = "";

     QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(findLabel);
     layout->addWidget(lineEdit);
     layout->addWidget(findButton);

     setLayout(layout);
     setWindowTitle(tr("Find an Image"));
     connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
     connect(findButton, SIGNAL(clicked()), this, SLOT(accept()));
 }

 void FindDialog::findClicked()
 {
     QString text = lineEdit->text();

     if (text.isEmpty()) {
         QMessageBox::information(this, tr("Empty Field"),
             tr("Please enter a title"));
         return;
     } else {
         findText = text;
         lineEdit->clear();
         hide();
     }
 }

 QString FindDialog::getFindText()
 {
     return findText;
 }
