# Mete0rama Hardware

This document describes everything you need to build a simple weather station.

## Parts

You will need these parts:
- a micro-controller with a wifi chip. I'm using a nodeMCU v3, adjust pins accordingly.
- a BME280 pressure sensor, which also reads temperature, humidity (and can calculate our altitude)
- a raindrop sensor
- a breadboard
- jumper cables
- a power bank
- a tupperware box

Additionally you will need these for the setup:
- a tool to cut a hole into the tupperware box
- gaffa tape to fix unintentional holes in the box

## Circuit Setup

Once you have all the parts, you can setup the circuit.

The raindrop sensor gives us either an analog or digital signal. I'm going for analog so we can say something about the rain intensity instead of simply: is there rain - yes/no.

Connect the VCC and GND pins accordingly and AO pin to the nodeMCU's A0 pin.

We need I2C to talk to the BME280. Connect VCC and GND pins accordingly and the SCL pin to D1 and SDA to D2, the pins the nodeMCU uses for I2C.

## Code

Now it's time to set up the code on the board.

Download, install and open the [Arduino IDE](https://www.arduino.cc/en/Main/Software).

If you haven't already, add the nodeMCU to the supported boards of your Arduino IDE. [Here is a tutorial on how to do that](https://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/).
This will also add libraries you'll need to setup a webserver and connect to wifi.

Then you'll need [ArduinoJson](https://github.com/bblanchon/ArduinoJson), to serve a nice payload to your clients, and [Adafuit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor) and [Adafruit_BME280_Library](https://github.com/adafruit/Adafruit_BME280_Library) to read, you guessed it, from the BME280. (Note that you do **not** need a BME280 from Adafruit.)

(You also need Wire to talk I2C, but that should come pre-installed in the IDE.)

Then open the project in the Arduino IDE. [In the code](./mete0rama/mete0rama.ino#L32-L33), adjust the SSID and password to your home WiFI. Flash the program onto your board.

## The tupperware box

You'll need a container to hold the weather station that is durable enough to live outside. The goal is to have all sensors + the board protected from weather by the box, but have the rain sensor outside of the box.

I got a cheap tupperware box from the hardware store that fits a power bank that I had lying around. Whatever you have, really.

To make a hole in the bottom of the box I used a large nail and a hammer, which then resulted in a big-ish tear. Well. I could fit the cables of the raindrop sensor through and put on some gaffa tape to close the tear. It's fine.

Next, just put everything into the box (except the raindrop sensor) and close the lid. Connect the raindrop sensor with the cables from the bottom. I also used some tape to secure the sensor on top of the box and protect the pins.

This can go outside now! Find a spot that's within your WIFI range, shady (so the temperature reading is more accurate), but will stil be hit by rain when it rains.

Check your local network for `Mete0rama` (for example by checking for all local devices in your Router's configuration settings) and open the IP address in your browser (e.g. http://192.168.178.42) . This is the website served from your board! Go to `/data` (e.g. http://192.168.178.42/data) and get a nice JSON payload with measurements.

You're done! Congrats!

## Maintenance

Yes, you have to charge the power bank once in a while.

I'm also not sure how long a raindrop sensor like that makes it out in the wild without corrosion. We'll see.

## Set up the web app

Once you have this setup, you can configure the web app to have a nice display of your weather data. Move over to the [webapp setup](../mete0rama-orama/README.md)!
