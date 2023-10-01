/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXQt - a lightweight, Qt based, desktop toolset
 * https://lxqt.org
 *
 * Copyright: 2015 LXQt team
 * Authors:
 *  Balázs Béla <balazsbela[at]gmail.com>
 *  Paulo Lieuthier <paulolieuthier@gmail.com>
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

#ifndef STATUSNOTIFIERBUTTON_H
#define STATUSNOTIFIERBUTTON_H

#include <QToolButton>
#include <functional>

#include "statusnotifieriteminterface.h"

class StatusNotifierButton : public QToolButton
{
public:
    StatusNotifierButton(QString service, QString objectPath,
                         QWidget * parent = nullptr);

private:
    void getPropertyAsync(QString const & name,
                          std::function<void(QVariant)> finished);

    void newIcon();
    void newToolTip();

    org::kde::StatusNotifierItem mSni;
    QMenu * mMenu = nullptr;

protected:
    void mouseReleaseEvent(QMouseEvent * event);
};

#endif // STATUSNOTIFIERBUTTON_H
