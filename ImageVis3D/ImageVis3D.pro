######################################################################
# Generated by Jens Krueger
######################################################################

TEMPLATE          = app
TARGET            = ../Build/ImageVis3D
RCC_DIR           = ../Build/rcc
OBJECTS_DIR       = ../Build/objects
UI_DIR            = UI/AutoGen
MOC_DIR           = UI/AutoGen
DEPENDPATH       += .
INCLUDEPATH      += .
QT               += opengl
LIBS              = -L../Tuvok/Build -lTuvok

# Input
HEADERS += StdDefines.h \
           UI/SettingsDlg.h \
           UI/BrowseData.h \
           UI/ImageVis3D.h \
           UI/PleaseWait.h \
           UI/QTransferFunction.h \
           UI/Q1DTransferFunction.h \
           UI/Q2DTransferFunction.h \
           UI/QDataRadioButton.h \
           UI/RenderWindow.h \
           UI/RAWDialog.h \           
           DebugOut/QTOut.h \
           DebugOut/QTLabelOut.h \
           IO/DialogConverter.h

FORMS += UI/UI/BrowseData.ui UI/UI/ImageVis3D.ui UI/UI/PleaseWait.ui UI/UI/SettingsDlg.ui UI/UI/RAWDialog.ui

SOURCES += UI/BrowseData.cpp \
           UI/ImageVis3D.cpp \
           UI/ImageVis3D_Capturing.cpp \
           UI/ImageVis3D_Progress.cpp \
           UI/ImageVis3D_1DTransferFunction.cpp \
           UI/ImageVis3D_2DTransferFunction.cpp \
           UI/ImageVis3D_FileHandling.cpp \
           UI/ImageVis3D_WindowHandling.cpp \
           UI/ImageVis3D_DebugWindow.cpp \
           UI/ImageVis3D_Settings.cpp \
           UI/ImageVis3D_Locking.cpp \
           UI/ImageVis3D_Stereo.cpp \
           UI/PleaseWait.cpp \
           UI/QTransferFunction.cpp \
           UI/Q1DTransferFunction.cpp \
           UI/Q2DTransferFunction.cpp \
           UI/QDataRadioButton.cpp \
           UI/RenderWindow.cpp \
           UI/SettingsDlg.cpp \
           UI/RAWDialog.cpp \
           DebugOut/QTOut.cpp \
           DebugOut/QTLabelOut.cpp \
           IO/DialogConverter.cpp
           main.cpp
