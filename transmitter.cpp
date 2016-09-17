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

#include "transmitter.h"
#define id "AB10"
Transmitter::Transmitter(QWidget *parent)
    : QObject(parent)
{
    //connect(&timer,SIGNAL(timeout()),this,SLOT(send_messages()));
    //timer.start(10);
    udpmessagehandler = new UDPMessageHandler();
    xmit_socket = new QUdpSocket(this);
    xmit_socket->bind(QHostAddress::Any,1234);

}
bool Transmitter::set_RC_server(QString server)
{
    RC_Server = server;
    return true;
}
bool Transmitter::send_RemoteControl_0xAB10(int axis1,int axis2,int axis3,int axis4,int axis5,int axis6,int axis7,int axis8,
                                                                           int button1,int button2,int button3,int button4, int button5,int button6,int button7,int button8)
{
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    //std::string sendstr("123,456");
    QString buffer = udpmessagehandler->encode_RemoteControlUDP(axis1,axis2,axis3,axis4,axis5,axis6,axis7,axis8,
                                                                button1,button2,button3,button4,button5,button6,button7,button8);
   /* buffer.append(id);
    buffer.append(",");
    buffer.append(QString::number(axis1));
    buffer.append(",");
    buffer.append(QString::number(axis2));
    buffer.append(",");
    buffer.append(QString::number(axis3));
    buffer.append(",");
    buffer.append(QString::number(axis4));
    buffer.append(",");
    buffer.append(QString::number(axis5));
    buffer.append(",");
    buffer.append(QString::number(axis6));
    buffer.append(",");
    buffer.append(QString::number(axis7));
    buffer.append(",");
    buffer.append(QString::number(axis8));
    buffer.append(",");
    buffer.append(QString::number(button1));
    buffer.append(",");
    buffer.append(QString::number(button2));
    buffer.append(",");
    buffer.append(QString::number(button3));
    buffer.append(",");
    buffer.append(QString::number(button4));
    buffer.append(",");
    buffer.append(QString::number(button5));
    buffer.append(",");
    buffer.append(QString::number(button6));
    buffer.append(",");
    buffer.append(QString::number(button7));
    buffer.append(",");
    buffer.append(QString::number(button8));
    */
    /*sendstr.append("AB10,");
    sendstr.append(
    sendstr.append(",");
    out << "AB10,";
    out << axis1 << "," << axis2 << "," << axis3 << "," << axis4 << "," << axis5 << "," << axis6 << "," << axis7 << "," << axis8 << ",";
    out << button1 << "," << button2 << "," << button3 << "," << button4 << "," << button5 << "," << button6 << "," << button7 << "," << button8 << ",";
    QString buffer = QString::fromStdString(sendstr);
    */
    xmit_socket->writeDatagram(buffer.toUtf8(),QHostAddress(RC_Server),5678);
    qDebug() << "Send AB10 to" << RC_Server << " : " << buffer << endl;
}
