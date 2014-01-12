#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QHttp>
#include <QFile>
#include <QDebug>
#include<QTcpSocket>
class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = 0);

    void Do_Download();
    void connectTcp();

    QTcpSocket *pSocket;

signals:

public slots:
    void stateChanged(int state);
    void responseHeaderReceived(const QHttpResponseHeader &resp);
    void requestFinished(int id, bool error);
    void readTcpData();

private:
    QHttp *http;
};


#endif // DOWNLOADER_H
