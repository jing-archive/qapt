/***************************************************************************
 *   Copyright © 2010 Jonathan Thomas <echidnaman@kubuntu.org>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU General Public License as        *
 *   published by the Free Software Foundation; either version 2 of        *
 *   the License or (at your option) version 3 or any later version        *
 *   accepted by the membership of KDE e.V. (or its successor approved     *
 *   by the membership of KDE e.V.), which shall act as a proxy            *
 *   defined in Section 14 of version 3 of the license.                    *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef QAPTWORKER_H
#define QAPTWORKER_H

#include <QtCore/QCoreApplication>
#include <QtDBus/QDBusContext>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>

#include <apt-pkg/progress.h>
#include <apt-pkg/sourcelist.h>
#include <apt-pkg/pkgrecords.h>
#include <apt-pkg/policy.h>

class QAptWorker : public QCoreApplication, protected QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kubuntu.qaptworker")
public:
    QAptWorker(int &argc, char **argv);

    virtual ~QAptWorker();

    OpProgress m_progressMeter;
    MMap *m_map;

    pkgCache *m_cache;
    pkgPolicy *m_policy;

    pkgDepCache *m_depCache;
    pkgSourceList *m_list;
    pkgRecords *m_records;
    bool m_locked;

    bool lock();
    bool initializeApt();

    bool updateCache();
};

#endif
