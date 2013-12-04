/*
   DrawPile - a collaborative drawing program.

   Copyright (C) 2013 Calle Laakkonen

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <cstring>
#include "login.h"

namespace protocol {

Login *Login::deserialize(const uchar *data, uint len)
{
	return new Login(QByteArray((const char*)data, len));
}

int Login::serializePayload(uchar *data) const
{
	memcpy(data, _msg.constData(), _msg.length());
	return _msg.length();
}

int Login::payloadLength() const
{
    return _msg.length();
}


}