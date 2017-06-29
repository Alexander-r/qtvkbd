/*
 * This file is part of the Qtvkbd project.
 * Copyright (C) 2016-2017 Alexander Ryapolov <srwork@gmail.com>
 * Copyright (C) 2007-2014 Todor Gyumyushev <yodor1@gmail.com>
 * Copyright (C) 2008 Guillaume Martres <smarter@ubuntu.com>
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

#include "qtvkbdapp.h"

//#include <QDebug>
#include <QDesktopWidget>
#include <QDomDocument>
#include <QFile>
#include <QGridLayout>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QFileInfo>

#include <QSettings>
#include <QFontDialog>

#include <X11/Xatom.h>
#include <X11/Xlib.h>

QList<VButton*> modKeys;

#define DEFAULT_WIDTH 	640
#define DEFAULT_HEIGHT 	210

#include "x11keyboard.h"


// TODO: Allow only one application instance
QtvkbdApp::QtvkbdApp(int &argc, char **argv, bool minimized, bool loginhelper) : QApplication(argc, argv), is_login(loginhelper)
{

    signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(buttonAction(const QString &)));

    widget = new ResizableDragWidget(0);
    widget->setContentsMargins(10,10,10,10);
    widget->setProperty("name", "main");

    QSettings cfg(QSettings::IniFormat, QSettings::UserScope, "qtvkbd", "qtvkbd");

    if (!is_login) {
      widget->setAttribute(Qt::WA_ShowWithoutActivating);
      widget->setAttribute(Qt::WA_DeleteOnClose, false);
    }

    widget->setWindowFlags( Qt::ToolTip | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint );

    dock = new KbdDock(widget->winId());
    connect(dock, SIGNAL(requestVisibility()), widget, SLOT(toggleVisibility()));

    tray = new KbdTray(widget);
    connect(tray, SIGNAL(requestVisibility()), widget, SLOT(toggleVisibility()));
   
    
    layout = new QGridLayout(widget);
    layout->setContentsMargins(0,0,0,0);
    widget->setLayout(layout);


    xkbd = new X11Keyboard(this);


    themeLoader = new ThemeLoader(widget);


    connect(themeLoader, SIGNAL(partLoaded(MainWidget*, int, int)), this, SLOT(partLoaded(MainWidget*, int, int)));
    connect(themeLoader, SIGNAL(buttonLoaded(VButton*)), this, SLOT(buttonLoaded(VButton*)));



    
    //QMenu *cmenu = tray->contextMenu();
    QMenu *cmenu = new QMenu(widget);

    QAction *chooseFontAction = new QAction(tr("Choose Font..."), this);
    connect(chooseFontAction, SIGNAL(triggered(bool)), this, SLOT(chooseFont()) );
    cmenu->addAction(chooseFontAction);

    QAction *autoResizeAction = new QAction(tr("Auto Resize Font"), this);
    autoResizeAction->setCheckable(true);
    bool autoResizeEnabled = cfg.value("autoresfont", QVariant(true)).toBool();
    autoResizeAction->setChecked(autoResizeEnabled);
    widget->setProperty("autoresfont", autoResizeEnabled);
    cmenu->addAction(autoResizeAction);
    connect(autoResizeAction,SIGNAL(triggered(bool)), this, SLOT(autoResizeFont(bool)));


    bool blur = cfg.value("blurBackground", QVariant(true)).toBool();

    QAction *blurBackgroundAction = new QAction(tr("Blur Background"), this);
    blurBackgroundAction->setCheckable(true);
    blurBackgroundAction->setChecked(blur);
    cmenu->addAction(blurBackgroundAction);
    widget->blurBackground(blur);
    connect(blurBackgroundAction,SIGNAL(triggered(bool)), widget, SLOT(blurBackground(bool)));
    dock->blurBackground(blur);
    connect(blurBackgroundAction,SIGNAL(triggered(bool)), dock, SLOT(blurBackground(bool)));
    widget->blurBackground(blur);
    dock->blurBackground(blur);

    bool dockVisible = cfg.value("showdock", QVariant(false)).toBool();
    QAction *showDockAction = new QAction(tr("Show Dock"), this);
    showDockAction->setCheckable(true);
    showDockAction->setChecked(dockVisible);
    cmenu->addAction(showDockAction);
    connect(showDockAction,SIGNAL(triggered(bool)), dock, SLOT(setVisible(bool)));

    bool isLocked = cfg.value("locked", QVariant(false)).toBool();
    QAction *lockOnScreenAction = new QAction(tr("Lock on Screen"), this);
    lockOnScreenAction->setCheckable(true);
    lockOnScreenAction->setChecked(isLocked);
    cmenu->addAction(lockOnScreenAction);
    connect(lockOnScreenAction,SIGNAL(triggered(bool)), widget, SLOT(setLocked(bool)));

    bool stickyModKeys = cfg.value("stickyModKeys", QVariant(false)).toBool();
    QAction *stickyModKeysAction = new QAction(tr("Sticky Modifier Keys"), this);
    lockOnScreenAction->setCheckable(true);
    stickyModKeysAction->setChecked(stickyModKeys);
    cmenu->addAction(stickyModKeysAction);
    connect(stickyModKeysAction,SIGNAL(triggered(bool)), this, SLOT(setStickyModKeys(bool)));
    widget->setProperty("stickyModKeys", stickyModKeys);
    
    
    QFont font;
    font.fromString(cfg.value("font", widget->font().toString()).toString());
    widget->setFont(font);

    QString colorsFilename = cfg.value("colors").toString();
    QMenu *colors = new QMenu(widget);
    themeLoader->findColorStyles(colors, colorsFilename);
    cmenu->addMenu(colors);
    connect(themeLoader, SIGNAL(colorStyleChanged()), widget, SLOT(repaint()));
    connect(themeLoader, SIGNAL(colorStyleChanged()), dock, SLOT(repaint()));


    QAction *quitAction = new QAction(tr("Quit"), this);
    cmenu->addAction(quitAction);
    connect(quitAction,SIGNAL(triggered(bool)), this, SLOT(quit()));

    tray->setContextMenu(cmenu);

    QString themeName = cfg.value("layout", "standart").toString();
    themeLoader->loadTheme(themeName);
    widget->setProperty("layout", themeName);


    QSize defaultSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
    QDesktopWidget *pDesktop = QApplication::desktop();

    QRect screenGeometry = pDesktop->availableGeometry(pDesktop->underMouse());
    //qDebug() << "ScreenGeometry: " << screenGeometry;

    QPoint bottomRight = screenGeometry.bottomRight()-QPoint(defaultSize.width(), defaultSize.height());

    QRect widgetGeometry(bottomRight, defaultSize);
    //qDebug() << "widgetGeometry: " << widgetGeometry;

    QRect c_geometry = cfg.value("geometry", widgetGeometry).toRect();
    if (!screenGeometry.contains(c_geometry, true)) {
        c_geometry = widgetGeometry;
    }
    widget->setGeometry(c_geometry);

    QPoint pos = c_geometry.topLeft();
    pos.setY(pos.y()-dock->height());

    QRect dockGeometry(pos, dock->size());
    
    QRect c_dock_geometry = cfg.value("dockGeometry", dockGeometry).toRect();
    if (!screenGeometry.contains(c_dock_geometry, true)) {
    c_dock_geometry = dockGeometry;
    }
    dock->setGeometry(c_dock_geometry);
    
    widget->show();

    
    bool extensionVisible = cfg.value("extentVisible", QVariant(true)).toBool();
    if (!extensionVisible) {
        toggleExtension();
    }

    
    
    setQuitOnLastWindowClosed (is_login);
    
    connect(this, SIGNAL(aboutToQuit()), this, SLOT(storeConfig()));
    emit fontUpdated(widget->font());

    if (dockVisible && !is_login) {
      dock->show();
    }
    
    xkbd->start();

    if (!is_login) {
      //bool vis = cfg.value("visible", QVariant(true)).toBool();
      //if (!vis || minimized) {
      if (minimized) {
          widget->showMinimized();
          widget->setVisible(false);
      }
      widget->setWindowTitle("qtvkbd");
      tray->show();
    }
    else {
	QTimer *timer = new QTimer(this);
	timer->setInterval(1000);
	connect(timer, SIGNAL(timeout()), widget, SLOT(raise()));
	timer->start();
    widget->setWindowTitle("qtvkbd.login");
    }

}

QtvkbdApp::~QtvkbdApp()
{

}

void QtvkbdApp::storeConfig()
{
    QSettings cfg(QSettings::IniFormat, QSettings::UserScope, "qtvkbd", "qtvkbd");
    
    cfg.setValue("visible", widget->isVisible());
    cfg.setValue("geometry", widget->geometry());
    cfg.setValue("locked", widget->isLocked());
    cfg.setValue("stickyModKeys", widget->property("stickyModKeys").toBool());
    
    cfg.setValue("showdock", dock->isVisible());
    cfg.setValue("dockGeometry", dock->geometry());
    
    cfg.setValue("layout", widget->property("layout").toString());
    cfg.setValue("colors", widget->property("colors").toString());
    cfg.setValue("font", widget->font().toString());
    cfg.setValue("autoresfont", widget->property("autoresfont").toBool());
    cfg.setValue("blurBackground", widget->property("blurBackground").toBool());

    MainWidget *prt = parts.value("extension");
    if (prt) {
        cfg.setValue("extentVisible", prt->isVisible());
    }

    cfg.sync();

}


void QtvkbdApp::autoResizeFont(bool mode)
{
    widget->setProperty("autoresfont", QVariant(mode));
    emit fontUpdated(widget->font());

}
void QtvkbdApp::setStickyModKeys(bool mode)
{
    widget->setProperty("stickyModKeys", QVariant(mode));
}

void QtvkbdApp::chooseFont()
{
    bool restore = false;

    if (widget->isVisible()) {
        widget->hide();
        restore = true;
    }

    QFont widgetFont = widget->font();

    bool result;
    widgetFont = QFontDialog::getFont(&result, widget->font(), widget);
    if ( result ) {

        widget->setFont(widgetFont);
        emit fontUpdated(widgetFont);

    }

    if (restore) {
        widget->show();
    }
}




void QtvkbdApp::buttonLoaded(VButton *btn)
{
    if (btn->property("modifier").toBool() == true) {
        modKeys.append(btn);
    }
    else {
        QObject::connect(btn, SIGNAL(keyClick(unsigned int)), xkbd, SLOT(processKeyPress(unsigned int)) );
    }
    QString bAction = btn->property("action").toString();

    if (bAction.length()>0) {
        connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(btn, bAction);
        actionButtons.insertMulti(bAction, btn);
    }

    QString tooltip = btn->property("tooltip").toString();
    if (tooltip.length()>0) {
        btn->setToolTip(tooltip);

    }

}
void QtvkbdApp::partLoaded(MainWidget *vPart, int total_rows, int total_cols)
{
    //cout << "Col Strech: " << total_cols << endl;
    // cout << "Row Strech: " << total_rows << endl;

    QString partName = vPart->property("part").toString();

    int row_pos = 0;
    int col_pos = 0;

    if (layoutPosition.count()>0) {
        QString partName = layoutPosition.keys().at(0);
        QRect lp = layoutPosition.value(partName);
        col_pos = lp.width();
    }

    layout->addWidget(vPart,row_pos,col_pos,total_rows,total_cols);
    //cout << "Insert to layout: " << qPrintable(partName) << " RowStart: " << row_pos << " ColStart: " << col_pos << " RowSpan: " << total_rows << " ColSpan: " << total_cols << endl;
    parts.insert(partName, vPart);
    layoutPosition.insert(partName, QRect(col_pos,row_pos,total_cols,total_rows));

    QObject::connect(xkbd, SIGNAL(layoutUpdated(int,QString)), vPart, SLOT(updateLayout(int,QString)));
    QObject::connect(xkbd, SIGNAL(groupStateChanged(const ModifierGroupStateMap&)), vPart, SLOT(updateGroupState(const ModifierGroupStateMap&)));
    QObject::connect(xkbd, SIGNAL(keyProcessComplete(unsigned int)), this, SLOT(keyProcessComplete(unsigned int)));
    
    QObject::connect(this, SIGNAL(textSwitch(bool)), vPart, SLOT(textSwitch(bool)));
    QObject::connect(this, SIGNAL(fontUpdated(const QFont&)), vPart, SLOT(updateFont(const QFont&)));



}
void QtvkbdApp::keyProcessComplete(unsigned int)
{
    if (widget->property("stickyModKeys").toBool()) return;
    
    QListIterator<VButton *> itr(modKeys);
    while (itr.hasNext()) {
        VButton *mod = itr.next();
        if (mod->isChecked()) {
            mod->click();
        }
    }
}

void QtvkbdApp::buttonAction(const QString &action)
{

    if (QString::compare(action , "toggleVisibility")==0) {
        if (!is_login) {
	  widget->toggleVisibility();
	}
    }
    else if (QString::compare(action , "toggleExtension")==0) {

        toggleExtension();
    }
    else if (QString::compare(action, "shiftText")==0) {
        if (actionButtons.contains(action)) {
            QList<VButton*> buttons = actionButtons.values(action);
            QListIterator<VButton *> itr(buttons);
            bool setShift = false;
            while (itr.hasNext()) {
                VButton *btn = itr.next();
                if (btn->isCheckable() && btn->isChecked()) setShift=true;
            }
            emit textSwitch(setShift);
        }
    }
}
void QtvkbdApp::toggleExtension()
{
    MainWidget *prt = parts.value("extension");
    if (prt->isVisible()) {
        prt->hide();
        layout->removeWidget(prt);
    }
    else {
        QString partName = prt->property("part").toString();
        QRect span = layoutPosition.value(partName);
        layout->addWidget(prt,span.y(),span.x(), span.height(), span.width());
        prt->show();
    }
}
