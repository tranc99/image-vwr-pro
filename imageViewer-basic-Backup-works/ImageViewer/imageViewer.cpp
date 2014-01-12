#include <QtGui>
#include "imageViewer.h"

ImageViewer::ImageViewer(QWidget *parent)
     : QWidget(parent)
 {
     QLabel *nameLabel = new QLabel(tr("FileName:"));
     nameLine = new QLineEdit;
     nameLine->setReadOnly(true);

     QLabel *imageLabel = new QLabel(tr("Current Image:"));
     image = new QTextEdit;
     image->setReadOnly(true);

     addButton = new QPushButton(tr("&Fetch"));

     editButton = new QPushButton(tr("&Stop"));
     editButton->setEnabled(false);
     removeButton = new QPushButton(tr("&Remove"));
     removeButton->setEnabled(false);
     findButton = new QPushButton(tr("&Find"));
     findButton->setEnabled(false);
     submitButton = new QPushButton(tr("&Submit"));
     submitButton->hide();
     cancelButton = new QPushButton(tr("&Cancel"));
     cancelButton->hide();

     nextButton = new QPushButton(tr("&Next"));
     nextButton->setEnabled(false);
     previousButton = new QPushButton(tr("&Previous"));
     previousButton->setEnabled(false);

     loadButton = new QPushButton(tr("&Load..."));
     loadButton->setToolTip(tr("Load image from a file"));
     saveButton = new QPushButton(tr("Sa&ve..."));
     saveButton->setToolTip(tr("Save image to a file"));
     saveButton->setEnabled(false);

     dialog = new FindDialog;

     connect(addButton, SIGNAL(clicked()), this, SLOT(addImage()));
     connect(submitButton, SIGNAL(clicked()), this, SLOT(submitImage()));
     connect(editButton, SIGNAL(clicked()), this, SLOT(editImage()));
     connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
     connect(removeButton, SIGNAL(clicked()), this, SLOT(removeImage()));
     connect(findButton, SIGNAL(clicked()), this, SLOT(findImage()));
     connect(nextButton, SIGNAL(clicked()), this, SLOT(next()));
     connect(previousButton, SIGNAL(clicked()), this, SLOT(previous()));
     connect(loadButton, SIGNAL(clicked()), this, SLOT(loadFromFile()));
     connect(saveButton, SIGNAL(clicked()), this, SLOT(saveToFile()));

     QVBoxLayout *buttonLayout1 = new QVBoxLayout;
     buttonLayout1->addWidget(addButton);
     buttonLayout1->addWidget(editButton);
     buttonLayout1->addWidget(removeButton);
     buttonLayout1->addWidget(findButton);
     buttonLayout1->addWidget(submitButton);
     buttonLayout1->addWidget(cancelButton);
     buttonLayout1->addWidget(loadButton);
     buttonLayout1->addWidget(saveButton);
     buttonLayout1->addStretch();

     QHBoxLayout *buttonLayout2 = new QHBoxLayout;
     buttonLayout2->addWidget(previousButton);
     buttonLayout2->addWidget(nextButton);

     QGridLayout *mainLayout = new QGridLayout;
     mainLayout->addWidget(nameLabel, 0, 0);
     mainLayout->addWidget(nameLine, 0, 1);
     mainLayout->addWidget(imageLabel, 1, 0, Qt::AlignTop);
     mainLayout->addWidget(image, 1, 1);
     mainLayout->addLayout(buttonLayout1, 1, 2);
     mainLayout->addLayout(buttonLayout2, 2, 1);

     setLayout(mainLayout);
     setWindowTitle(tr("Simple Image Viewer"));
 }

 void ImageViewer::addImage()
 {
     oldName = nameLine->text();
     oldImage = image->toPlainText();

     nameLine->clear();
     image->clear();

     updateInterface(AddingMode);
 }

 void ImageViewer::editImage()
 {
     oldName = nameLine->text();
     oldImage = image->toPlainText();

     updateInterface(EditingMode);
 }

 void ImageViewer::submitImage()
 {
     QString name = nameLine->text();
     QString fileContents = image->toPlainText();

     if (name == "" || fileContents == "") {
         QMessageBox::information(this, tr("Empty Field"),
             tr("Please enter a filename and select a file."));
     }

     if (currentMode == AddingMode) {

         if (!fileNames.contains(name)) {
             fileNames.insert(name, fileContents);
             QMessageBox::information(this, tr("Add Successful"),
                 tr("\"%1\" has been added.").arg(name));
         } else {
             QMessageBox::information(this, tr("Add Unsuccessful"),
                 tr("Sorry, \"%1\" is already in your images").arg(name));
         }
     } else if (currentMode == EditingMode) {

         if (oldName != name) {
             if (!fileNames.contains(name)) {
                 QMessageBox::information(this, tr("Edit Successful"),
                     tr("\"%1\" has been edited").arg(oldName));
                 fileNames.remove(oldName);
                 fileNames.insert(name, fileContents);
             } else {
                 QMessageBox::information(this, tr("Edit Unsuccessful"),
                     tr("Sorry, \"%1\" is already in your images").arg(name));
             }
         } else if (oldImage != fileContents) {
             QMessageBox::information(this, tr("Edit Successful"),
                 tr("\"%1\" has been edited").arg(name));
             fileNames[name] = fileContents;
         }
     }

     updateInterface(NavigationMode);
 }

 void ImageViewer::cancel()
 {
     nameLine->setText(oldName);
     image->setText(oldImage);
     updateInterface(NavigationMode);
 }

 void ImageViewer::removeImage()
 {
     QString name = nameLine->text();
     QString contents = image->toPlainText();

     if (fileNames.contains(name)) {

         int button = QMessageBox::question(this,
             tr("Confirm Remove"),
             tr("Are you sure you want to remove \"%1\"?").arg(name),
             QMessageBox::Yes | QMessageBox::No);

         if (button == QMessageBox::Yes) {

             previous();
             fileNames.remove(name);

             QMessageBox::information(this, tr("Remove Successful"),
                 tr("\"%1\" has been removed from the image directory").arg(name));
         }
     }

     updateInterface(NavigationMode);
 }

 void ImageViewer::next()
 {
     QString name = nameLine->text();
     QMap<QString, QString>::iterator i = fileNames.find(name);

     if (i != fileNames.end())
         i++;

     if (i == fileNames.end())
         i = fileNames.begin();

     nameLine->setText(i.key());
     image->setText(i.value());
 }

 void ImageViewer::previous()
 {
     QString name = nameLine->text();
     QMap<QString, QString>::iterator i = fileNames.find(name);

     if (i == fileNames.end()) {
         nameLine->clear();
         image->clear();
         return;
     }

     if (i == fileNames.begin())
         i = fileNames.end();

     i--;
     nameLine->setText(i.key());
     image->setText(i.value());
 }

 void ImageViewer::findImage()
 {
     dialog->show();

     if (dialog->exec() == 1) {
         QString imgName = dialog->getFindText();

         if (fileNames.contains(imgName)) {
             nameLine->setText(imgName);
             image->setText(fileNames.value(imgName));
         } else {
             QMessageBox::information(this, tr("Image Not Found"),
                 tr("Sorry, \"%1\" is not contained in your images").arg(imgName));
             return;
         }
     }

     updateInterface(NavigationMode);
 }

 void ImageViewer::updateInterface(Mode mode)
 {
     currentMode = mode;

     switch (currentMode) {

     case AddingMode:
     case EditingMode:

         nameLine->setReadOnly(false);
         //TEN_INSERt
         nameLine->setReadOnly(true);
         nameLine->setFocus(Qt::OtherFocusReason);
         image->setReadOnly(false);
         //TEN_INSERt
         image->setReadOnly(true);

         addButton->setEnabled(false);
         editButton->setEnabled(false);
         removeButton->setEnabled(false);

         nextButton->setEnabled(false);
         previousButton->setEnabled(false);

         submitButton->show();
         cancelButton->show();

         loadButton->setEnabled(false);
         saveButton->setEnabled(false);
         break;

     case NavigationMode:

         if (fileNames.isEmpty()) {
             nameLine->clear();
             image->clear();
         }

         nameLine->setReadOnly(true);
         image->setReadOnly(true);
         addButton->setEnabled(true);

         int number = fileNames.size();
         editButton->setEnabled(number >= 1);
         removeButton->setEnabled(number >= 1);
         findButton->setEnabled(number > 2);
         nextButton->setEnabled(number > 1);
         previousButton->setEnabled(number > 1);

         submitButton->hide();
         cancelButton->hide();

         loadButton->setEnabled(true);
         saveButton->setEnabled(number >= 1);
         break;
     }
 }

 void ImageViewer::saveToFile()
 {
     QString fileName = QFileDialog::getSaveFileName(this,
         tr("Save Image File"), "",
         tr("Image file (*.png);;All Files (*)"));

     if (fileName.isEmpty())
         return;
     else {
         QFile file(fileName);
         if (!file.open(QIODevice::WriteOnly)) {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }

         QDataStream out(&file);
         out.setVersion(QDataStream::Qt_4_5);
         out << fileNames;
     }
 }

 void ImageViewer::loadFromFile()
 {
     QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image file"), "",
         tr("Image File (*.png);;All Files (*)"));

     if (fileName.isEmpty())
         return;
     else {

         QFile file(fileName);

         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }

         QDataStream in(&file);
         in.setVersion(QDataStream::Qt_4_5);
         fileNames.empty();   // empty existing data
         in >> fileNames;

         if (fileNames.isEmpty()) {
             QMessageBox::information(this, tr("No contents in file"),
                 tr("The file you are attempting to open contains no data"));
         } else {
             QMap<QString, QString>::iterator i = fileNames.begin();
             nameLine->setText(i.key());
             image->setText(i.value());


         }
     }

     updateInterface(NavigationMode);
 }
