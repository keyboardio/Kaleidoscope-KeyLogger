# Kaleidoscope-KeyLogger

[![Build Status][travis:image]][travis:status]

 [travis:image]: https://travis-ci.org/keyboardio/Kaleidoscope-KeyLogger.svg?branch=master
 [travis:status]: https://travis-ci.org/keyboardio/Kaleidoscope-KeyLogger

The `KeyLogger` plugin, as the name suggests, implements a key logger for the
Kaleidoscope firmware. It logs the row and column of every key press and release,
along with the event, and the layer number, in a format that is reasonably easy
to parse, to the Serial interface.

## A word of warning

Having a key logger is as dangerous as it sounds. Anyone who can read the serial
events from the keyboard, will know exactly what keys you press, and when.
Unless you know what you are doing, and can secure your keyboard, do **not**
enable this plugin.

## Using the plugin

There is nothing configurable about the plugin, using it is as simple as
including the header file, and declaring it used:

```c++
#include <Kaleidoscope.h>
#include <Kaleidoscope-KeyLogger.h>

KALEIDOSCOPE_INIT_PLUGINS(KeyLogger);

void setup() {
  Serial.begin(9600);
  Kaleidoscope.setup();
}
```

That, in itself, will do all that is necessary to have the key logger active.

Note: For most accurate physical keypress data, KeyLogger should be the first
plugin in `KALEIDOSCOPE_INIT_PLUGINS()`, but if other plugins that change the
value of keys (e.g. Qukeys, TapDance, Leader, etc.) are also being used, it may
be useful to change the plugin order.

## The output

On the host, reading from the keyboard's serial port (or using the *Serial
Monitor* built into the Arduino IDE), one will be able to see the following
output:

```
KL: row=1, col=2, pressed=1, layer=0, key_flags=0, key_code=FF
KL: row=1, col=2, pressed=0, layer=0, key_flags=0, key_code=FF
```

## Further reading

Starting from the [example][plugin:example] is the recommended way of getting
started with the plugin.

 [plugin:example]: https://github.com/keyboardio/Kaleidoscope-KeyLogger/blob/master/examples/KeyLogger/KeyLogger.ino
