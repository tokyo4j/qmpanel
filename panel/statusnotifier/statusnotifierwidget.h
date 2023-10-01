/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * qmpanel - a minimal Qt-based desktop panel
 *
 * Copyright: 2015 LXQt team
 * Copyright: 2023 John Lindgren
 * Authors:
 *  Balázs Béla <balazsbela[at]gmail.com>
 *  Paulo Lieuthier <paulolieuthier@gmail.com>
 *  John Lindgren <john@jlindgren.net>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef STATUSNOTIFIERWIDGET_H
#define STATUSNOTIFIERWIDGET_H

#include <QWidget>

#include "statusnotifierwatcher.h"

class StatusNotifierButton;

class StatusNotifierWidget : public QWidget
{
public:
    StatusNotifierWidget(QWidget * parent = nullptr);

private:
    void itemAdded(const QString & serviceAndPath);
    void itemRemoved(const QString & serviceAndPath);

    StatusNotifierWatcher mWatcher;
    QHash<QString, StatusNotifierButton *> mServices;
};

#endif // STATUSNOTIFIERWIDGET_H
