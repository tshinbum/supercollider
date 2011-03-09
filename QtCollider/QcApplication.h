/************************************************************************
*
* Copyright 2010 Jakob Leben (jakob.leben@gmail.com)
*
* This file is part of SuperCollider Qt GUI.
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
************************************************************************/

#ifndef QC_APPLICATION_H
#define QC_APPLICATION_H

#include "Common.h"

#include <QApplication>
#include <QMutex>

class QcApplication : public QApplication
{
  public:
    QcApplication( int & argc, char ** argv );
    virtual ~QcApplication();
    static void postSyncEvent( QcSyncEvent *e, QObject *rcv );
    static void postSyncEvent( QcSyncEvent *e, EventHandlerFn handler );

  private:
    bool event( QEvent * );
    void customEvent( QEvent * );

    static QMutex _mutex;
    static QcApplication *_instance;
};

#endif // QC_APPLICATION_H