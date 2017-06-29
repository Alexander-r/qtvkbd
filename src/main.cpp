/*
 * This file is part of the Kvkbd project.
 * Copyright (C) 2007-2014 Todor Gyumyushev <yodor1@gmail.com>
 * Copyright (C) 2008 Guillaume Martres <smarter@ubuntu.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */



#include "qtvkbdapp.h"
#include <QCommandLineParser>

//static const char version[] = "0.7.2";

#include <X11/Xlib.h>

void findLoginWindow()
{
	unsigned int numkids, i,mapped,scrn;
	Window r, p;
	Window *kids=0;
	//XWindowAttributes attr;
	Window root;
	Display *dipsy=0;
	char *win_name=0;

	dipsy = XOpenDisplay(0);
	if (!dipsy)return;

	scrn = DefaultScreen(dipsy);
	root = RootWindow(dipsy, scrn);
	
	mapped = 0;
	XQueryTree(dipsy, root, &r, &p, &kids, &numkids);
		

	for (i = 0; i < numkids;  ++i)
	{
			XFetchName(dipsy, kids[i], &win_name);
			QString c(win_name);
			
            if (c=="qtvkbd.login")
 			{
 				long wid = kids[i];
				XDestroyWindow(dipsy,wid);
				XFlush(dipsy);
				i=numkids;
 			}
			XFree(win_name);
	} 
	XCloseDisplay(dipsy);
}

int main(int argc, char **argv)
{
    QCommandLineParser parser;
    parser.setApplicationDescription("A virtual keyboard");
    parser.addHelpOption();
    parser.addOption(
        {{"l", "loginhelper"},
            QCoreApplication::translate("main", "Stand alone version for use with KDM or XDM.\n"
                                                "See qtvkbd Handbook for information on how to use this option.")}
    );
    parser.addOption(
        {{"m", "minimized"},
            QCoreApplication::translate("main", "Start minimized.")}
    );
    QStringList arguments;
    for (int a = 0; a < argc; ++a)
    {
        arguments.append(QString::fromLocal8Bit(argv[a]));
    }
    parser.parse(arguments);

    bool is_login = parser.isSet("loginhelper");
    bool minimized = parser.isSet("minimized");
    if (is_login) {
      findLoginWindow();
    }
	
    QtvkbdApp app(argc, argv, minimized, is_login);
    parser.process(app);

    return app.exec();
    
}
