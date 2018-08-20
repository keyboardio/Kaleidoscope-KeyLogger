/* -*- mode: c++ -*-
 * Kaleidoscope-KeyLogger -- A key logger
 * Copyright (C) 2016, 2017, 2018  Gergely Nagy
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
 */

#include <Kaleidoscope-KeyLogger.h>

namespace kaleidoscope {

EventHandlerResult KeyLogger::onKeyswitchEvent(Key &mapped_key, byte row, byte col, uint8_t key_state) {
  if (!keyToggledOn(key_state) && !keyToggledOff(key_state))
    return EventHandlerResult::OK;
  if (key_state & INJECTED)
    return EventHandlerResult::OK;

  Serial.print(F("KL: row="));
  Serial.print(row, DEC);
  Serial.print(F(", col="));
  Serial.print(col, DEC);
  Serial.print(F(", pressed="));
  Serial.print(keyToggledOn(key_state), DEC);
  Serial.print(F(", defaultLayer="));
  Serial.print(Layer.defaultLayer(), DEC);
  Serial.print(F(", layerState="));
  Serial.print(Layer.getLayerState(), BIN);
  Serial.print(F(", mapped_key.flags="));
  Serial.print(mapped_key.flags, BIN);
  Serial.print(F(", mapped_key.keyCode="));
  Serial.print(mapped_key.keyCode, HEX);
  Serial.print(F(", timestamp="));
  Serial.println(millis(), DEC);

  return EventHandlerResult::OK;
}

}

kaleidoscope::KeyLogger KeyLogger;
