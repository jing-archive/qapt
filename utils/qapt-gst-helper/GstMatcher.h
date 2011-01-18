//
//  Copyright (C) 2010 Daniel Nicoletti <dantti85-pk@yahoo.com.br>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; see the file COPYING.  If not, write to
//  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
//  Boston, MA 02111-1307, USA.
//

#ifndef GSTMATCHER_H
#define GSTMATCHER_H

#include <QtCore/QVector>

#include <glib.h>

#include <string>

using namespace std;

namespace QApt {
    class Package;
}

typedef struct {
    string   version;
    string   type;
    string   data;
    string   opt;
    void    *caps;
} Match;

class GstMatcher
{
public:
    GstMatcher(gchar **values);
    ~GstMatcher();

    bool matches(QApt::Package *package);
    bool hasMatches() const;

private:
    QVector<Match> m_matches;
};

#endif
