using namespace std;
//  File      : QAD_Message.cxx
//  Created   : Thu Jun 14 15:55:14 2001
//  Author    : Nicolas REJNERI
//  Project   : SALOME
//  Module    : SALOMEGUI
//  Copyright : Open CASCADE
//  $Header$

#include "QAD_Message.h"
#include "QAD_Application.h"
#include "QAD_Config.h"
#include "QAD_Tools.h"
#include <stdio.h>
#include <qstring.h>
#include <qpopupmenu.h>
#include <qmap.h>

enum { IdCopy, IdClear, IdSelectAll };

/*!
  \class QAD_Message QAD_Message.h
  \brief Messages window for Study. 
*/

/*!
  Constructor - creates Message Log window
*/
QAD_Message::QAD_Message(QWidget *parent, const char* name)
  : QMultiLineEdit(parent, name)
{
  // setting default title
  myTitle = tr("MESSAGE_LOG_NAME");
  // setting default prompt
  myPrompt = ">>> ";
  // setting font ( from preferences )
  QString fntSet = QAD_CONFIG->getSetting("Viewer:ConsoleFont");
  QFont myFont = QAD_Tools::stringToFont( fntSet );
//  QFont myFont("Courier", 11);
  setFont(myFont);
  setReadOnly(TRUE);
  // appending title
  setMessage(myTitle);
  // setting palette (special)
  setPalette( QAD_Application::getPalette(true) );
  setFocusPolicy( NoFocus );
  // currently no text wrap
  setWordWrap(NoWrap);
}

/*!
    Destructor
*/
QAD_Message::~QAD_Message()
{
}

/*!
  Adds message
*/
void QAD_Message::setMessage(const QString& s)
{
  int line = numLines() > 0 ? numLines()-1 : 0;
  int col  = lineLength(line);
  if (!s.isNull() && s.length() > 0) {
    QString ss = s;
    insertAt(ss, line, col, false);
  }
  append(myPrompt);
}

/*
   Processes own popup manu
*/
void QAD_Message::mousePressEvent(QMouseEvent* event)
{
  if ( event->button() == RightButton ) {
    QPopupMenu *popup = new QPopupMenu( this );
    QMap<int, int> idMap;

    int line1, col1, line2, col2;
    getMarkedRegion(&line1, &col1, &line2, &col2);
    bool allSelected = getMarkedRegion(&line1, &col1, &line2, &col2) &&
      line1 == 0 && line2 == numLines()-1 && col1 == 0 && col2 == lineLength(line2);
    int id;
    id = popup->insertItem( tr( "EDIT_COPY_CMD" ) );
    idMap.insert(IdCopy, id);
    id = popup->insertItem( tr( "EDIT_CLEAR_CMD" ) );
    idMap.insert(IdClear, id);
    popup->insertSeparator();
    id = popup->insertItem( tr( "EDIT_SELECTALL_CMD" ) );
    idMap.insert(IdSelectAll, id);
    popup->setItemEnabled( idMap[ IdCopy ], hasMarkedText() );
    popup->setItemEnabled( idMap[ IdSelectAll ],
			  (bool)text().length() && !allSelected );
    
    int r = popup->exec( event->globalPos() );
    delete popup;
    
    if ( r == idMap[ IdCopy ] ) {
      copy();
    }
    else if ( r == idMap [ IdClear ] ) {
      clear();
      setMessage(myTitle);
    }
    else if ( r == idMap[ IdSelectAll ] ) {
      selectAll();
    }
    return;
  }
  else {
    QMultiLineEdit::mousePressEvent(event);
  }
}

/*
   Sets prompt ( default is '>>> ' )
*/
void QAD_Message::setPrompt(const QString& prompt) 
{
  myPrompt = prompt;
  clear();
  setMessage(myTitle);
}