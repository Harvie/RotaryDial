# Rotary Dial Arduino Library


<p align="center"><img src="https://i.imgur.com/SHSXXla.png" /></p>

This library was written for use with the dial pictured above (Dial from Czech telephone Tesla AS-10, green and yellow wire). But it should work with anything capable of producing bursts of pulses.

This implementation is for the North American system, where [1, 9] pulses correspond to the numbers [1, 9], and 0 is represented by 10 pulses.

## Connection & Circuit

This library uses interrupts, so you have to connect the dial to pin which supports interrupts (this is different for different arduinos, but most common boards can do interrupts on pins 2 and 3).

Unfortunataly this library is static, so currently you can use it only once at a time (= with one dial).

Internal pullup is used, so all you need is to connect NC terminals of rotary dial to GND and Pin 2 (or whatever pin you choose in the code).

## TODO

  * Possibility to register callback for processing received numbers
  * Make timing constants user configurable
  * Allow inverting of logic to use NO instead of NC dials (not sure if there are such)
  * Allow more than one dial at the same time
  * Provide method to detach interrupt if needed
  * Handle dial timeout directly in library? (= send ENTER when user is done typing numbers, currently we handle this in example sketch)

## See also

  * Wikipedia: Rotary dial http://en.wikipedia.org/wiki/Rotary_dial
  * Rotary-Dialer Library by Mark Fickett https://github.com/markfickett/Rotary-Dial
    * Similar library, but does not use interrupts and needs third wire with "enable" signal
  * Do you want to make PS2 keyboard using rotary dial as an input? https://github.com/Harvie/ps2dev/
  * Brmlab Hackerspace Prague http://brmlab.cz/
