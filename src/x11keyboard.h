/*
 * This file is part of the Qtvkbd project.
 * Copyright (C) 2016-2017 Alexander Ryapolov <srwork@gmail.com>
 * Copyright (C) 2014 Todor Gyumyushev <yodor1@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef X11KEYBOARD_H
#define X11KEYBOARD_H

#include <QObject>
#include <QTimer>
#include <QStringList>
#include <QChar>
#include <QMap>

#include "vkeyboard.h"

#include "keysymconvert.h"

class X11Keyboard : public VKeyboard
{
    Q_OBJECT

public:
    X11Keyboard(QObject *parent=0);
    virtual ~X11Keyboard();
    void textForKeyCode(unsigned int keyCode, QString& text);

public slots:
    virtual void processKeyPress(unsigned int);
    virtual void queryModState();
    virtual void constructLayouts();
    virtual void layoutChanged();
    virtual void start();

protected:

    void sendKey(unsigned int keycode);

    QStringList layouts;
    int layout_index;

    KeySymConvert kconvert;


    bool queryModKeyState(KeySym keyCode);
    ModifierGroupStateMap groupState;
    QTimer *groupTimer;

};

#endif // X11KEYBOARD_H
