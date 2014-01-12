#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QMap>
#include "finddialog.h"

class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;

 class ImageViewer : public QWidget
 {
     Q_OBJECT

 public:
     ImageViewer(QWidget *parent = 0);
     enum Mode { NavigationMode, AddingMode, EditingMode };

 public slots:
     void addImage();
     void editImage();
     void submitImage();
     void cancel();
     void removeImage();
     void findImage();
     void next();
     void previous();
     void saveToFile();
     void loadFromFile();

 private:
     void updateInterface(Mode mode);

     QPushButton *addButton;
     QPushButton *editButton;
     QPushButton *removeButton;
     QPushButton *findButton;
     QPushButton *submitButton;
     QPushButton *cancelButton;
     QPushButton *nextButton;
     QPushButton *previousButton;
     QPushButton *loadButton;
     QPushButton *saveButton;
     QLineEdit *nameLine;
     QTextEdit *image;

     QMap<QString, QString> fileNames;
     FindDialog *dialog;
     QString oldName;
     QString oldImage;
     Mode currentMode;
 };

#endif // IMAGEVIEWER_H
