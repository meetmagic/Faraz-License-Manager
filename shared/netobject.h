#ifndef NETOBJECT_H
#define NETOBJECT_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include "netconst.h"
#include "license.h"

class NetObject : public QObject
{
    Q_OBJECT
public:
    explicit NetObject(quint16 listenPort, QObject *parent = 0);

protected:
    QUdpSocket udp;
    virtual void processTheDatagram(QByteArray &datagram, QHostAddress &sender, quint16 senderPort) = 0;

private:
    QTimer timer;

signals:

public slots:

private slots:
    void readPendingDatagrams();
    virtual void timerTimeout() = 0;

};

#endif // NETOBJECT_H
