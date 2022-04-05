#############################################################################
# Makefile for building: GrandPrix
# Generated by qmake (3.1) (Qt 5.12.8)
# Project:  GrandPrix.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile GrandPrix.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DGP_VERSION=4.0.2 -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -Iinclude -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I.moc -I.ui -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = GrandPrix1.0.0
DISTDIR = /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.obj/GrandPrix1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = .obj/

####### Files

SOURCES       = src/logger.cpp \
		src/main.cpp \
		src/grandprix.cpp \
		src/gpcontrolview.cpp \
		src/gpmapview.cpp \
		src/gpmapselector.cpp \
		src/gpcontrol.cpp \
		src/gpdriverselector.cpp \
		src/finishdialog.cpp \
		src/gpprogression.cpp \
		src/car.cpp \
		src/headless.cpp \
		src/stderrview.cpp .rcc/qrc_res.cpp \
		.moc/moc_grandprix.cpp \
		.moc/moc_gpcontrolview.cpp \
		.moc/moc_gpmapview.cpp \
		.moc/moc_gpmapselector.cpp \
		.moc/moc_gpcontrol.cpp \
		.moc/moc_gpdriverselector.cpp \
		.moc/moc_finishdialog.cpp \
		.moc/moc_gpprogression.cpp \
		.moc/moc_headless.cpp \
		.moc/moc_stderrview.cpp
OBJECTS       = .obj/logger.o \
		.obj/main.o \
		.obj/grandprix.o \
		.obj/gpcontrolview.o \
		.obj/gpmapview.o \
		.obj/gpmapselector.o \
		.obj/gpcontrol.o \
		.obj/gpdriverselector.o \
		.obj/finishdialog.o \
		.obj/gpprogression.o \
		.obj/car.o \
		.obj/headless.o \
		.obj/stderrview.o \
		.obj/qrc_res.o \
		.obj/moc_grandprix.o \
		.obj/moc_gpcontrolview.o \
		.obj/moc_gpmapview.o \
		.obj/moc_gpmapselector.o \
		.obj/moc_gpcontrol.o \
		.obj/moc_gpdriverselector.o \
		.obj/moc_finishdialog.o \
		.obj/moc_gpprogression.o \
		.obj/moc_headless.o \
		.obj/moc_stderrview.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		GrandPrix.pro include/grandprix.h \
		include/gpcontrolview.h \
		include/gpmapview.h \
		include/gpmapselector.h \
		include/gpcontrol.h \
		include/gpdriverselector.h \
		include/finishdialog.h \
		include/gpprogression.h \
		include/car.h \
		include/headless.h \
		include/logger.h \
		include/stderrview.h src/logger.cpp \
		src/main.cpp \
		src/grandprix.cpp \
		src/gpcontrolview.cpp \
		src/gpmapview.cpp \
		src/gpmapselector.cpp \
		src/gpcontrol.cpp \
		src/gpdriverselector.cpp \
		src/finishdialog.cpp \
		src/gpprogression.cpp \
		src/car.cpp \
		src/headless.cpp \
		src/stderrview.cpp
QMAKE_TARGET  = GrandPrix
DESTDIR       = 
TARGET        = GrandPrix


first: all
####### Build rules

GrandPrix: .ui/ui_grandprix.h .ui/ui_gpcontrolview.h .ui/ui_gpmapview.h .ui/ui_gpmapselector.h .ui/ui_gpdriverselector.h .ui/ui_finishdialog.h .ui/ui_gpprogression.h .ui/ui_stderrview.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GrandPrix.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		GrandPrix.pro \
		res.qrc
	$(QMAKE) -o Makefile GrandPrix.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
GrandPrix.pro:
res.qrc:
qmake: FORCE
	@$(QMAKE) -o Makefile GrandPrix.pro

qmake_all: FORCE


all: Makefile GrandPrix

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents res.qrc $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents include/grandprix.h include/gpcontrolview.h include/gpmapview.h include/gpmapselector.h include/gpcontrol.h include/gpdriverselector.h include/finishdialog.h include/gpprogression.h include/car.h include/headless.h include/logger.h include/stderrview.h $(DISTDIR)/
	$(COPY_FILE) --parents src/logger.cpp src/main.cpp src/grandprix.cpp src/gpcontrolview.cpp src/gpmapview.cpp src/gpmapselector.cpp src/gpcontrol.cpp src/gpdriverselector.cpp src/finishdialog.cpp src/gpprogression.cpp src/car.cpp src/headless.cpp src/stderrview.cpp $(DISTDIR)/
	$(COPY_FILE) --parents ui/grandprix.ui ui/gpcontrolview.ui ui/gpmapview.ui ui/gpmapselector.ui ui/gpdriverselector.ui ui/finishdialog.ui ui/gpprogression.ui ui/stderrview.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: .rcc/qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) .rcc/qrc_res.cpp
.rcc/qrc_res.cpp: res.qrc \
		/usr/lib/qt5/bin/rcc \
		res/current.png \
		res/goal.png \
		res/oil.png \
		res/available2.png \
		res/car3.png \
		res/available1.png \
		res/car2.png \
		res/sand.png \
		res/normal.png \
		res/grand_prix.png \
		res/out.png \
		res/car1.png \
		res/available3.png
	/usr/lib/qt5/bin/rcc -name res res.qrc -o .rcc/qrc_res.cpp

compiler_moc_predefs_make_all: .moc/moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) .moc/moc_predefs.h
.moc/moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -std=gnu++11 -Wall -W -dM -E -o .moc/moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: .moc/moc_grandprix.cpp .moc/moc_gpcontrolview.cpp .moc/moc_gpmapview.cpp .moc/moc_gpmapselector.cpp .moc/moc_gpcontrol.cpp .moc/moc_gpdriverselector.cpp .moc/moc_finishdialog.cpp .moc/moc_gpprogression.cpp .moc/moc_headless.cpp .moc/moc_stderrview.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) .moc/moc_grandprix.cpp .moc/moc_gpcontrolview.cpp .moc/moc_gpmapview.cpp .moc/moc_gpmapselector.cpp .moc/moc_gpcontrol.cpp .moc/moc_gpdriverselector.cpp .moc/moc_finishdialog.cpp .moc/moc_gpprogression.cpp .moc/moc_headless.cpp .moc/moc_stderrview.cpp
.moc/moc_grandprix.cpp: include/grandprix.h \
		include/gpcontrolview.h \
		include/gpcontrol.h \
		include/car.h \
		include/gpdriverselector.h \
		include/stderrview.h \
		include/gpmapview.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/grandprix.h -o .moc/moc_grandprix.cpp

.moc/moc_gpcontrolview.cpp: include/gpcontrolview.h \
		include/gpcontrol.h \
		include/car.h \
		include/gpdriverselector.h \
		include/stderrview.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/gpcontrolview.h -o .moc/moc_gpcontrolview.cpp

.moc/moc_gpmapview.cpp: include/gpmapview.h \
		include/gpcontrol.h \
		include/car.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/gpmapview.h -o .moc/moc_gpmapview.cpp

.moc/moc_gpmapselector.cpp: include/gpmapselector.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/gpmapselector.h -o .moc/moc_gpmapselector.cpp

.moc/moc_gpcontrol.cpp: include/gpcontrol.h \
		include/car.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/gpcontrol.h -o .moc/moc_gpcontrol.cpp

.moc/moc_gpdriverselector.cpp: include/gpdriverselector.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/gpdriverselector.h -o .moc/moc_gpdriverselector.cpp

.moc/moc_finishdialog.cpp: include/finishdialog.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/finishdialog.h -o .moc/moc_finishdialog.cpp

.moc/moc_gpprogression.cpp: include/gpprogression.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/gpprogression.h -o .moc/moc_gpprogression.cpp

.moc/moc_headless.cpp: include/headless.h \
		include/gpcontrol.h \
		include/car.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/headless.h -o .moc/moc_headless.cpp

.moc/moc_stderrview.cpp: include/stderrview.h \
		.moc/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/.moc/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan -I/home/tangui-stei/Documents/challenge-prog/projectFF1-challenge_de_prog-OpelKapitan/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/stderrview.h -o .moc/moc_stderrview.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: .ui/ui_grandprix.h .ui/ui_gpcontrolview.h .ui/ui_gpmapview.h .ui/ui_gpmapselector.h .ui/ui_gpdriverselector.h .ui/ui_finishdialog.h .ui/ui_gpprogression.h .ui/ui_stderrview.h
compiler_uic_clean:
	-$(DEL_FILE) .ui/ui_grandprix.h .ui/ui_gpcontrolview.h .ui/ui_gpmapview.h .ui/ui_gpmapselector.h .ui/ui_gpdriverselector.h .ui/ui_finishdialog.h .ui/ui_gpprogression.h .ui/ui_stderrview.h
.ui/ui_grandprix.h: ui/grandprix.ui \
		/usr/lib/qt5/bin/uic \
		include/gpcontrolview.h \
		include/gpmapview.h \
		include/gpcontrol.h \
		include/car.h \
		include/gpdriverselector.h \
		include/stderrview.h \
		include/gpcontrol.h \
		include/car.h
	/usr/lib/qt5/bin/uic ui/grandprix.ui -o .ui/ui_grandprix.h

.ui/ui_gpcontrolview.h: ui/gpcontrolview.ui \
		/usr/lib/qt5/bin/uic \
		include/gpmapselector.h
	/usr/lib/qt5/bin/uic ui/gpcontrolview.ui -o .ui/ui_gpcontrolview.h

.ui/ui_gpmapview.h: ui/gpmapview.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ui/gpmapview.ui -o .ui/ui_gpmapview.h

.ui/ui_gpmapselector.h: ui/gpmapselector.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ui/gpmapselector.ui -o .ui/ui_gpmapselector.h

.ui/ui_gpdriverselector.h: ui/gpdriverselector.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ui/gpdriverselector.ui -o .ui/ui_gpdriverselector.h

.ui/ui_finishdialog.h: ui/finishdialog.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ui/finishdialog.ui -o .ui/ui_finishdialog.h

.ui/ui_gpprogression.h: ui/gpprogression.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ui/gpprogression.ui -o .ui/ui_gpprogression.h

.ui/ui_stderrview.h: ui/stderrview.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic ui/stderrview.ui -o .ui/ui_stderrview.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

.obj/logger.o: src/logger.cpp include/logger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/logger.o src/logger.cpp

.obj/main.o: src/main.cpp include/grandprix.h \
		include/gpcontrolview.h \
		include/gpcontrol.h \
		include/car.h \
		include/gpdriverselector.h \
		include/stderrview.h \
		include/gpmapview.h \
		include/headless.h \
		include/logger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o src/main.cpp

.obj/grandprix.o: src/grandprix.cpp include/grandprix.h \
		include/gpcontrolview.h \
		include/gpcontrol.h \
		include/car.h \
		include/gpdriverselector.h \
		include/stderrview.h \
		include/gpmapview.h \
		.ui/ui_grandprix.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/grandprix.o src/grandprix.cpp

.obj/gpcontrolview.o: src/gpcontrolview.cpp include/car.h \
		include/finishdialog.h \
		include/gpcontrol.h \
		include/gpcontrolview.h \
		include/gpdriverselector.h \
		include/stderrview.h \
		include/logger.h \
		.ui/ui_gpcontrolview.h \
		include/gpmapselector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gpcontrolview.o src/gpcontrolview.cpp

.obj/gpmapview.o: src/gpmapview.cpp include/gpmapview.h \
		include/gpcontrol.h \
		include/car.h \
		.ui/ui_gpmapview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gpmapview.o src/gpmapview.cpp

.obj/gpmapselector.o: src/gpmapselector.cpp include/gpmapselector.h \
		.ui/ui_gpmapselector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gpmapselector.o src/gpmapselector.cpp

.obj/gpcontrol.o: src/gpcontrol.cpp include/gpcontrol.h \
		include/car.h \
		include/logger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gpcontrol.o src/gpcontrol.cpp

.obj/gpdriverselector.o: src/gpdriverselector.cpp include/gpdriverselector.h \
		.ui/ui_gpdriverselector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gpdriverselector.o src/gpdriverselector.cpp

.obj/finishdialog.o: src/finishdialog.cpp include/finishdialog.h \
		.ui/ui_finishdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/finishdialog.o src/finishdialog.cpp

.obj/gpprogression.o: src/gpprogression.cpp include/gpprogression.h \
		.ui/ui_gpprogression.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gpprogression.o src/gpprogression.cpp

.obj/car.o: src/car.cpp include/car.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/car.o src/car.cpp

.obj/headless.o: src/headless.cpp include/headless.h \
		include/gpcontrol.h \
		include/car.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/headless.o src/headless.cpp

.obj/stderrview.o: src/stderrview.cpp include/stderrview.h \
		.ui/ui_stderrview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/stderrview.o src/stderrview.cpp

.obj/qrc_res.o: .rcc/qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/qrc_res.o .rcc/qrc_res.cpp

.obj/moc_grandprix.o: .moc/moc_grandprix.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_grandprix.o .moc/moc_grandprix.cpp

.obj/moc_gpcontrolview.o: .moc/moc_gpcontrolview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gpcontrolview.o .moc/moc_gpcontrolview.cpp

.obj/moc_gpmapview.o: .moc/moc_gpmapview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gpmapview.o .moc/moc_gpmapview.cpp

.obj/moc_gpmapselector.o: .moc/moc_gpmapselector.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gpmapselector.o .moc/moc_gpmapselector.cpp

.obj/moc_gpcontrol.o: .moc/moc_gpcontrol.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gpcontrol.o .moc/moc_gpcontrol.cpp

.obj/moc_gpdriverselector.o: .moc/moc_gpdriverselector.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gpdriverselector.o .moc/moc_gpdriverselector.cpp

.obj/moc_finishdialog.o: .moc/moc_finishdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_finishdialog.o .moc/moc_finishdialog.cpp

.obj/moc_gpprogression.o: .moc/moc_gpprogression.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gpprogression.o .moc/moc_gpprogression.cpp

.obj/moc_headless.o: .moc/moc_headless.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_headless.o .moc/moc_headless.cpp

.obj/moc_stderrview.o: .moc/moc_stderrview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_stderrview.o .moc/moc_stderrview.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

