//  File      : QAD_ViewFrame.cxx
//  Created   : UI team, 05.09.00
//  Descrip   : Frame window for viewport in QAD-based application

//  Modified  : Mon Dec 03 15:41:43 2001
//  Author    : Nicolas REJNERI
//  Project   : SALOME
//  Module    : SALOMEGUI
//  Copyright : Open CASCADE
//  $Header$


#ifndef QAD_ViewFrame_H
#define QAD_ViewFrame_H

#include "QAD.h"
#include "QAD_Application.h"
#include "QAD_StudyFrame.h"
#include "SALOME_InteractiveObject.hxx"

// QT Include
#include <qmainwindow.h>

class vtkRenderer;

class QAD_EXPORT QAD_ViewFrame : public QMainWindow
{
  Q_OBJECT

public:
  QAD_ViewFrame(QWidget* parent, const QString& title);
  QAD_ViewFrame(QWidget* parent = 0);
  virtual ~QAD_ViewFrame();

  void                   cleanup();

  virtual ViewType       getTypeView() const = 0; 
  virtual QWidget*       getViewWidget() = 0;
  virtual vtkRenderer*   getRenderer();

  virtual void           setBackgroundColor( const QColor& ) = 0;
  virtual QColor         backgroundColor() const = 0;

  virtual void           SetSelectionMode( int mode ) = 0;

  virtual void           SetTrihedronSize( int dim ) = 0;

  /*  popup management */
  virtual void           setPopupServer( QAD_Application* ) = 0;

  /*  interactive object management */
  virtual void           highlight( const Handle(SALOME_InteractiveObject)& IObject, 
				    bool highlight, bool immediatly = true ) = 0;
  virtual void           unHighlightAll() = 0;
  virtual void           rename( const Handle(SALOME_InteractiveObject)& IObject,
				 QString newName ) = 0;
  virtual bool           isInViewer( const Handle(SALOME_InteractiveObject)& IObject ) = 0;
  virtual bool           isVisible( const Handle(SALOME_InteractiveObject)& IObject ) = 0;

  /*  undo/redo management */
  virtual void           undo(SALOMEDS::Study_var aStudy,
			      const char* StudyFrameEntry) = 0;
  virtual void           redo(SALOMEDS::Study_var aStudy,
			      const char* StudyFrameEntry) = 0;

  static bool		 isInViewer(SALOMEDS::Study_var aStudy,
				    const char* anEntry,
				    const char* StudyFrameEntry);

  /* selection */
  virtual Handle(SALOME_InteractiveObject)   FindIObject(const char* Entry) = 0;

  /* display */		
  virtual void           Display(const Handle(SALOME_InteractiveObject)& IObject, bool immediatly = true) = 0;
  virtual void           DisplayOnly(const Handle(SALOME_InteractiveObject)& IObject) = 0;
  virtual void           Erase(const Handle(SALOME_InteractiveObject)& IObject, bool immediatly = true) = 0;
  virtual void           DisplayAll() = 0;
  virtual void           EraseAll() = 0;
  virtual void           Repaint() = 0;

protected slots:
  virtual void           onViewPan() = 0; 
  virtual void           onViewZoom() = 0;
  virtual void           onViewFitAll() = 0;
  virtual void           onViewFitArea() = 0;
  virtual void           onViewGlobalPan() = 0; 
  virtual void           onViewRotate() = 0;
  virtual void           onViewReset() = 0;     
  virtual void           onViewFront() = 0; 
  virtual void           onViewBack() = 0; 
  virtual void           onViewRight() = 0; 
  virtual void           onViewLeft() = 0;     
  virtual void           onViewBottom() = 0;
  virtual void           onViewTop() = 0;
  virtual void           onViewTrihedron() = 0; 
  virtual void           onViewDump();

};

#endif
