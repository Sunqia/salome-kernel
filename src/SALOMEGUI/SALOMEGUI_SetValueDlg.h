//  File      : SALOMEGUI_SetValueDlg.h
//  Created   : Wed Jan 21 16:38:42 2001
//  Author    : Vadim SANDLER
//  Project   : SALOME
//  Module    : SALOMEGUI
//  Copyright : Open CASCADE
//  $Header$

#ifndef SALOMEGUI_SETVALUEDLG_H
#define SALOMEGUI_SETVALUEDLG_H

#include <qdialog.h>

class QLineEdit;
class QPushButton;
class QValidator;
class QLabel;

//=================================================================================
// class    : SALOMEGUI_SetValueDlg
// purpose  : Common dialog box for setting integer, double and string values
//=================================================================================
class SALOMEGUI_SetValueDlg : public QDialog
{ 
public:
  static QString  getString ( const QString& caption, 
			      const QString& label, 
 			      const QString& oldValue = QString::null,
			      bool*          ok = 0, 
			      QWidget*       parent = 0 );
  static int      getInteger( const QString& caption, 
			      const QString& label, 
 			      const int      oldValue = 0,
			      bool*          ok = 0, 
			      QWidget*       parent = 0 );
  static double   getDouble ( const QString& caption, 
			      const QString& label, 
 			      const double   oldValue = 0.0,
			      bool*          ok = 0, 
			      QWidget*       parent = 0 );

private:
  SALOMEGUI_SetValueDlg( QWidget* parent = 0 );
  ~SALOMEGUI_SetValueDlg();
  
  void            setValue( const QString& value );
  QString         value();
  void            setValidator( QValidator* v );
  void            setLabel( const QString& label );
    
private:
  QLabel*         myLabel;
  QLineEdit*      myLineEdit;
  QPushButton*    myButtonOk;
  QPushButton*    myButtonCancel;
};

#endif // SALOMEGUI_SETVALUEDLG_H