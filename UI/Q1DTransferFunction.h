/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2008 Scientific Computing and Imaging Institute,
   University of Utah.

   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/


//!    File   : Q1DTransferFunction.h
//!    Author : Jens Krueger
//!             SCI Institute
//!             University of Utah
//!    Date   : July 2008
//
//!    Copyright (C) 2008 SCI Institute

#pragma once

#ifndef Q1DTRANSFERFUNCTION
#define Q1DTRANSFERFUNCTION

#include <QtGui/QWidget>
#include <IO/TransferFunction1D.h>

class MasterController;

class Q1DTransferFunction : public QWidget
{
  Q_OBJECT

public:

  enum paintMode { PAINT_NONE=0, PAINT_RED=1, PAINT_GREEN=2,
		   PAINT_BLUE=4, PAINT_ALPHA=8, PAINT_UNDEF=16 };

  enum executionMode { UNKNOWN=0, CONTINUOUS=1, ONRELEASE=2, MANUAL=4 };

public:
  Q1DTransferFunction(MasterController& masterController, QWidget *parent=0);
  virtual ~Q1DTransferFunction(void);

  void SetData(const Histogram1D* vHistrogram, TransferFunction1D* Trans);

  const TransferFunction1D* GetTrans() {return m_pTrans;}

  void SetPaintMode(paintMode iPaintMode) {
    if (iPaintMode < PAINT_UNDEF) m_iPaintMode = iPaintMode;};

  void SetExecutionMode(executionMode iExecutionMode) {
    m_iExecutionMode = iExecutionMode;
  }

  void ApplyFunction();

public slots:
  bool LoadFromFile(const QString& strFilename);
  bool SaveToFile(const QString& strFilename);

protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);
  virtual void changeEvent(QEvent * event);

private:
  // states
  MasterController& m_MasterController;

  NormalizedHistogram1D m_vHistrogram;
  TransferFunction1D* m_pTrans;

  unsigned int m_iPaintMode;
  unsigned int m_iExecutionMode;

  // cached image of the backdrop
  bool		 m_bBackdropCacheUptodate;
  unsigned int m_iCachedHeight;
  unsigned int m_iCachedWidth;
  QPixmap*	 m_pBackdropCache;
  QImage*	 m_pPreviewBack;
  QImage*	 m_pPreviewColor;

  // borders, may be changed in the constructor 
  unsigned int m_iLeftBorder;
  unsigned int m_iBottomBorder;
  unsigned int m_iTopPreviewHeight;
  unsigned int m_iTopPreviewDist;

  // automatically computed borders (computed by DrawCoordinateSystem)
  unsigned int m_iRightBorder;
  unsigned int m_iTopBorder;

  // colors, may be changed in the setcolor 
  QColor m_colorHistogram;
  QColor m_colorBack;
  QColor m_colorBorder;
  QColor m_colorScale;
  QColor m_colorLargeScale;
  QColor m_colorRedLine;
  QColor m_colorGreenLine;
  QColor m_colorBlueLine;
  QColor m_colorAlphaLine;

  void SetColor(bool bIsEnabled);

  // scale apearance, may be changed in the constructor 
  unsigned int m_iMarkersX;
  unsigned int m_iMarkersY;
  unsigned int m_iBigMarkerSpacingX;
  unsigned int m_iBigMarkerSpacingY;
  unsigned int m_iMarkerLength;
  unsigned int m_iBigMarkerLength;

  // mouse motion handling
  int m_iLastIndex;
  float m_fLastValue;

  // drawing routines
  void DrawCoordinateSystem(QPainter& painter);
  void DrawHistogram(QPainter& painter);
  void DrawFunctionPlots(QPainter& painter);

  void PreparePreviewData();
  void RedrawPreviewBarBack();
};


#endif // Q1DTRANSFERFUNCTION
