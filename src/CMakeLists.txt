find_package(Qt5Widgets REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(LibXslt REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(qtvkbd_SRCS vkeyboard.cpp 
    x11keyboard.cpp
    dragwidget.cpp
    mainwidget.cpp
    vbutton.cpp
    main.cpp
    resizabledragwidget.cpp
    keysymconvert.cpp
    kbddock.cpp
    qtvkbdapp.cpp
    kbdtray.cpp
    themeloader.cpp
    sliderdialog.cpp
    )



SET(qtvkbd_RESOURCES resources.qrc)


qt5_add_resources(qtvkbd_RESOURCES_RCC ${qtvkbd_RESOURCES})

qt5_add_dbus_adaptor(qtvkbd_SRCS org.kde.qtvkbd.Qtvkbd.xml
                       mainwidget.h MainWidget)

qt5_add_dbus_adaptor(qtvkbd_SRCS org.kde.qtvkbd.Dock.xml
                       kbddock.h KbdDock)

add_executable(qtvkbd ${qtvkbd_SRCS} ${qtvkbd_RC_SRCS} ${qtvkbd_RESOURCES_RCC})

qt5_use_modules(qtvkbd Core Widgets Gui Xml X11Extras DBus)

target_link_libraries(qtvkbd ${QT_LIBRARIES} X11 Xtst)


install(TARGETS qtvkbd RUNTIME DESTINATION bin)

install( FILES qtvkbd.desktop  DESTINATION share/applications )
