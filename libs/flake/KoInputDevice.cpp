/*
 *  Copyright (c) 2007 Thomas Zander <zander@kde.org>
 *
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
 */

#include "KoInputDevice.h"

class KoInputDevice::Private {
public:
    Private( QTabletEvent::TabletDevice d, QTabletEvent::PointerType p, qint64 id, bool m)
        : device(d),
        pointer(p),
        uniqueTabletId(id),
        mouse(m)
    {
    }
    QTabletEvent::TabletDevice device;
    QTabletEvent::PointerType pointer;
    qint64 uniqueTabletId;
    bool mouse;
};

KoInputDevice::KoInputDevice(QTabletEvent::TabletDevice device, QTabletEvent::PointerType pointer)
    : d(new Private(device, pointer, -1, false))
{
}

KoInputDevice::KoInputDevice(qint64 uniqueTabletId)
    : d(new Private(QTabletEvent::NoDevice, QTabletEvent::UnknownPointer, uniqueTabletId, false))
{
}

KoInputDevice::KoInputDevice()
    : d(new Private(QTabletEvent::NoDevice, QTabletEvent::UnknownPointer, -1, true))
{
}


bool KoInputDevice::operator==(const KoInputDevice &other)
{
    return d->device == other.d->device && d->pointer == other.d->pointer &&
        d->uniqueTabletId == other.d->uniqueTabletId && d->mouse == other.d->mouse;
}

bool KoInputDevice::operator!=(const KoInputDevice &other)
{
    return ! (operator==(other));
}
