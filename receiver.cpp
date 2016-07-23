/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtNetwork>

#include "receiver.h"

Receiver::Receiver(QWidget *parent)
    : QObject(parent)
{
}
void Receiver::Start()
{
    groupAddress = QHostAddress("239.255.43.21");
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    udpSocket->joinMulticastGroup(groupAddress);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

void Receiver::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QList<QByteArray> items = datagram.split(',');
        //qDebug() << "New Message";
        //qDebug() << items.at(0) << DIAGNOSTIC_ID;
        int message_id = items.at(0).toInt();
        Diagnostic newdiag;


        switch(message_id)
        {
            case DIAGNOSTIC_ID:
            {
                //qDebug() << "Matched!";
                Diagnostic newdiag;
                newdiag.NodeName = items.at(1).toStdString();
                newdiag.System = items.at(2).toInt();
                newdiag.Subsystem = items.at(3).toInt();
                newdiag.Component = items.at(4).toInt();
                newdiag.DiagnosticType = items.at(5).toInt();
                newdiag.Level = items.at(6).toInt();
                newdiag.Message = items.at(7).toInt();
                newdiag.Description = items.at(8).toStdString();
                emit new_diagnosticmessage(newdiag);
                break;
            }
            default:
            {
                //qDebug() << "No Match";
                break;
            }
        }
        foreach (const QByteArray &item,items)
        {
            //qDebug() << item;
        }



        //statusLabel->setText(tr("Received datagram: \"%1\"")
        //                     .arg(datagram.data()));
    }
}
