//  File      : QAD_FileDlg.h
//  Created   : UI team, 17.09.02
//  Descr     : Open/Save File dialog

//  Modified  : Tue Sep 17 11:02:12 2002
//  Author    : 
//  Project   : SALOME
//  Module    : SALOMEGUI
//  Copyright : Open CASCADE 2001
//  $Header$

#ifndef QAD_FILEDIALOG_H
#define QAD_FILEDIALOG_H

#include <qfiledialog.h>
#include <qcombobox.h>
#include "QAD.h"
#include "QAD_FileValidator.h"

class QAD_EXPORT QAD_FileDlg : public QFileDialog
{
    Q_OBJECT

public:
    QAD_FileDlg( QWidget* parent, bool open, bool showQuickDir = true, bool modal = true );
    ~QAD_FileDlg();

public:    
    bool               isOpenDlg()    const;    
    QString            selectedFile() const;

    void               setValidator( QAD_FileValidator* );

    static QString     getFileName( QWidget*           parent, 
				    const QString&     initial, 
				    const QStringList& filters, 
				    const QString&     caption,
				    bool               open,
				    bool               showQuickDir = true,
				    QAD_FileValidator* validator = 0);
    static QString     getExistingDirectory ( QWidget*       parent,
					      const QString& initial,
					      const QString& caption, 
					      bool           showQuickDir = true);
private:
    bool               acceptData();
    void               addExtension();
    bool               processPath( const QString& path );

protected slots:
    void               accept();        
    void               reject(); 
    void               quickDir(const QString&);

protected:
    bool               myOpen;             /* open/save selector  */      
    QString            mySelectedFile;     /* selected filename   */    
    QAD_FileValidator* myValidator;        /* file validator      */
    static QString     myLastVisitedPath;  /* last visited path   */
    QComboBox*         myQuickCombo;       /* quick dir combo box */

};

#endif