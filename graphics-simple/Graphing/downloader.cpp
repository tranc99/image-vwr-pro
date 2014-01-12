#include "downloader.h"
#include <iostream>
using namespace std;




Downloader::Downloader(QObject *parent) : QObject(parent)
{

}

void Downloader::connectTcp()
{
    QByteArray data;

    pSocket = new QTcpSocket(this);
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(readTcpData()) );

    pSocket->connectToHost("192.168.1.244", 8282);
    if(pSocket->waitForConnected()) {
        data = pSocket->readAll();
    }
}

void Downloader::readTcpData()
{
   QByteArray data = pSocket->readAll();
   QByteArray secondData = data.toHex();
   const char *stringData = secondData.data();
   std::string arraystringhex(stringData);
   qDebug() << data.toHex();

   //first, redirect stdout to file
   std::streambuf *psbuf, *backup;
   //set standard output to file
   std::freopen("data.txt", "w", stdout);

   //write buffer to std::out while formating it
   int testint = 0;
   for (int i = 2; i < (arraystringhex.size()-2); i=i+2) {
       //print number "1." on first line as well [do it in hex]
       if(testint == 0)
           std::cout << std::hex << "\n" << 1 << ".\t";
       //print a row of 16 bytes
       std::cout <<arraystringhex[i-2] << arraystringhex[i-1] << "  ";
       testint++;
       //then start counting the rest of the rows on 2 and so on [do it in hex]
       if(testint % 16 == 0)
           std::cout << std::hex << "\n" << (testint / 16 + 1) << ".\t";
       //std::cout << "testint is now: " << testint << "\n";
   }

   //write buffer to std::out
   //std::cout << secondData.data();

   //reset to standard output again
   //std::cout.rdbuf(backup);
}

void Downloader::Do_Download()
{
    http = new QHttp(this);

    connect(http, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int)));
    connect(http, SIGNAL(responseHeaderReceived(QHttpResponseHeader)),
            this, SLOT(responseHeaderReceived(QHttpResponseHeader)));
    connect(http, SIGNAL(requestFinished(int,bool)),
            this, SLOT(requestFinished(int,bool)));

    http->setHost("bogotobogo.com");

    //get default file
    http->get("/");
}

void Downloader::stateChanged(int state)
{
    switch(state)
    {
        case 0:
            qDebug() << "Unconnected";
            break;
        case 1:
            qDebug() << "Host lookup";
            break;
        case 2:
            qDebug() << "Connecting";
            break;
        case 3:
            qDebug() << "Sending";
            break;
        case 4:
            qDebug() << "Reading";
            break;
        case 5:
            qDebug() << "Connect";
            break;
        case 6:
            qDebug() << "Closing";
            break;

    }
}


void Downloader::responseHeaderReceived(const QHttpResponseHeader &resp)
{
    qDebug() << "Size" << resp.contentLength();
    qDebug() << "Type" << resp.contentType();
    qDebug() << "Status" << resp.statusCode();
}

void Downloader::requestFinished(int id, bool error)
{
    if(error)
    {
        qDebug() << "ERROR!";
    }
    else
    {
        qDebug() << "OK!";
        QFile *file = new QFile("/downloaded.txt");
        if (file->open(QFile::Append))
        {
            file->write(http->readAll());
            file->flush();
            file->close();
        }
        delete file;
    }


}



