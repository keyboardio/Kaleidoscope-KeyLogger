/* -*- mode: c++ -*-
 * Kaleidoscope-KeyLogger -- A key logger
 * Copyright (C) 2016, 2017, 2018  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Kaleidoscope.h>
#include <Kaleidoscope-KeyLogger.h>

namespace kaleidoscope {
namespace plugin {

EventHandlerResult KeyLogger::onKeyswitchEvent(KeyEvent &event) {
  // If the plugin has already processed and released this event, ignore it.
  // There's no need to update the event tracker explicitly.
  if (event_tracker_.shouldIgnore(event))
    return EventHandlerResult::OK;

  // If `event.addr` is valid, or `event.state` is explicitly marked as
  // injected, ignore the event.
  if (! event.addr.isValid() || (event.state & INJECTED) != 0)
    return EventHandlerResult::OK;

  Runtime.serialPort().print(F("KL: row="));
  Runtime.serialPort().print(event.addr.row(), DEC);
  Runtime.serialPort().print(F(", col="));
  Runtime.serialPort().print(event.addr.col(), DEC);
  Runtime.serialPort().print(F(", pressed="));
  Runtime.serialPort().print(keyToggledOn(event.state), DEC);
  Runtime.serialPort().print(F(", layer="));
  Runtime.serialPort().print(Layer.lookupActiveLayer(event.addr), DEC);
  Runtime.serialPort().print(F(", key_flags="));
  Runtime.serialPort().print(event.key.getFlags(), BIN);
  Runtime.serialPort().print(F(", key_code="));
  Runtime.serialPort().print(event.key.getKeyCode(), HEX);
  Runtime.serialPort().print(F(", timestamp="));
  Runtime.serialPort().println(Runtime.millisAtCycleStart(), DEC);

  return EventHandlerResult::OK;
}

}
}

kaleidoscope::plugin::KeyLogger KeyLogger;
