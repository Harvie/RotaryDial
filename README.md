# Rotary Dial Arduino Library

Arduino library to read numbers from a rotary dial (or otherwise using pulse dialing; see [Wikipedia: Rotary dial](http://en.wikipedia.org/wiki/Rotary_dial)).

![front of a rotary telephone dial](http://www.markfickett.com/umbrella/images/111105rotarydialfront-sm.jpg "Rotary Dial")

This implementation is for the North American system, where [1, 9] pulses correspond to the numbers [1, 9], and 0 is represented by 10 pulses. This library was written for use with the dial [demonstrated here](http://commons.wikimedia.org/wiki/File:Rotary_Dial,_Dialing_Back_with_LEDs.ogv) and pictured above.

## Connection & Circuit

This library uses interrupts, so you have to connect the dial to pin which supports interrupts (this is different for different arduinos, but most common boards can do interrupts on pins 2 and 3).

Unfortunataly this library is static, so currently you can use it only once at a time (= with one dial).

Internal pullup is used, so all you need is to connect NC terminals of rotary dial to GND and Pin 2 (or whatever pin you choose in the code).

## See also

  * Rotary-Dialer Library by Mark Fickett https://github.com/markfickett/Rotary-Dial
    * Similar library, but does not use interrupts and needs third wire with "enable" signal
  * Brmlab Hackerspace Prague http://brmlab.cz/
