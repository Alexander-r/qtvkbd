/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -m -a qtvkbdadaptor -i mainwidget.h -l MainWidget /home/edge/progects/qtvkbd/src/org.kde.qtvkbd.Qtvkbd.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "qtvkbdadaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class QvkbdAdaptor
 */

QvkbdAdaptor::QvkbdAdaptor(MainWidget *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

QvkbdAdaptor::~QvkbdAdaptor()
{
    // destructor
}

bool QvkbdAdaptor::alone() const
{
    // get the value of property alone
    return qvariant_cast< bool >(parent()->property("alone"));
}

bool QvkbdAdaptor::locked() const
{
    // get the value of property locked
    return qvariant_cast< bool >(parent()->property("locked"));
}

void QvkbdAdaptor::setLocked(bool value)
{
    // set the value of property locked
    parent()->setProperty("locked", QVariant::fromValue(value));
}

bool QvkbdAdaptor::visible() const
{
    // get the value of property visible
    return qvariant_cast< bool >(parent()->property("visible"));
}

void QvkbdAdaptor::setVisible(bool value)
{
    // set the value of property visible
    parent()->setProperty("visible", QVariant::fromValue(value));
}


#include "qtvkbdadaptor.moc"
