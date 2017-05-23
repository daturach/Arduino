This sketch simulates a Schmitt Trigger. It takes the sensor (CNY70) analog output that feeds A0.
When the signal is above a certain level, it outputs a pulse. That pulse drives a transistor
which reset the Wemos device (https://github.com/daturach/ESP8266/tree/master/wemos_gaz)
When the same signal goes below a certain level, it "releases" the Wemos device.
At that point, the device generates a pulse and sends it to a server via an http request.
Then it falls into a deep sleep (zzzzzzzz!)

Compiled with Arduino 1.0.5
