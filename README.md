# Rotary Dial Arduino Library


<div style="text-align:center"><img src="https://i.imgur.com/SHSXXla.png" /></div>

This library was written for use with the dial pictured above (Dial from Czech telephone Tesla AS-10). But it should work with anything capable of producing bursts of pulses.

This implementation is for the North American system, where [1, 9] pulses correspond to the numbers [1, 9], and 0 is represented by 10 pulses.

## Connection & Circuit

This library uses interrupts, so you have to connect the dial to pin which supports interrupts (this is different for different arduinos, but most common boards can do interrupts on pins 2 and 3).

Unfortunataly this library is static, so currently you can use it only once at a time (= with one dial).

Internal pullup is used, so all you need is to connect NC terminals of rotary dial to GND and Pin 2 (or whatever pin you choose in the code).

## See also

  * Wikipedia: Rotary dial http://en.wikipedia.org/wiki/Rotary_dial
  * Rotary-Dialer Library by Mark Fickett https://github.com/markfickett/Rotary-Dial
    * Similar library, but does not use interrupts and needs third wire with "enable" signal
  * Brmlab Hackerspace Prague http://brmlab.cz/
