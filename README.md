# arduino_2018

## Week2

### Interesting Arduino Project

#### 1. Sleep quality meter http://people.ece.cornell.edu/land/courses/ece4760/FinalProjects/f2017/nas256_jbc262/nas256_jbc262/website/index.html

This project is a system that monitors the quality of the sleep of the user by tracking heart rate, breathing rate, and movement. 

#### 2. Duvet Eating alarm clock
http://www.instructables.com/id/Duvet-Eating-Alarm-Clock/

This project is making an alarm clock machine that removes your blanket. 

#### 3. Music Sequencer Table Plays Michael Jackson
Link: https://www.youtube.com/watch?v=mIvc6uBDGzU

(I'm not sure this is arduino project, but I found it interesting)
This is an interactive music table with glowing LED sensors added to the table top. As you put transparent balls on the sensors, the tune becomes a remix of Michael Jackson's Billy Jean.

### Sensors
: Detect what's going on in the world and act on that information.

#### FSR(Force Sensitive Resistor) : detect physical pressure
	- Consist of 2 layers separated by a spacer.
	- More pressure(More active element dots) makes resistance go down.
	- FSRs are basically a resistor.
	- Easy to use but rarely accurate.
	- Resistance range : 100KΩ (light pressure) to 200Ω (max. pressure)
	- Force range : 0 to 20lb
	- Power supply : Any

#### Photocells : detect brightness, simple object
	- Often referred to as CdS(Cadmium-Sulfide) cells, light-dependent resistors(LDR), and photoresistors.
	- Changes its resistive value depending on how much light is shining onto the squiggly face.
	- Low cost, but inaccurate.
	- Resistance range: 200KΩ (dark) to 10KΩ (10 lux brightness)
	- Sensitivity range: CdS cells respond to light between 400nm (violet) and 600nm (orange) wavelengths, peaking at about 520nm (green).
	- Power supply: pretty much anything up to 100V, uses less than 1mA of current on average (depends on power supply voltage)

#### Temperature TMP 36 Sensor
	- Tells you what the ambient temperature is.
	- Uses a solid-state technique
	- Uses the fact as temperature increases, the voltage across a diode increases at a known rate.
	- By precisely amplifying the voltage change, it is easy to generate an analog signal that is directyl proportional to temperature.
	- The calculation is inside the chip.
	- Precise and never wear out.
	- Temperature range: -40°C to 150°C / -40°F to 302°F
	- Output range: 0.1V (-40°C) to 2.0V (150°C) but accuracy decreases after 125°C
	- Power supply: 2.7V to 5.5V only, 0.05 mA current draw
  
#### Tilt Sensor : detect orientation or incliation
	- Usually made by a cavity of some sort and a conductive free mass inside
	- End of cavity : two conductive elements(poles)
	- Sensitivity range: > +-15 degrees
	- Power supply: Up to 24V, switching less than 5mA

#### PIR motion Sensor : detect motion / whether a human has moved in or out of the sensor range
	- PIR, Passive Infrared, Pyroelectric, IR motion
	- Basically made of a pyroelectric sensor
	- Takes the output of the sensor and does some minor processing on it to emit a digital output pulse from the analog sensor.


## Week3

### Ideas for Project1
1. LEDs on the panel lights up if people approach close to them or even walk by them. And if you touch the lightening LEDs, they'll make a sound. As you move your hands, the tone changes. 

Can I make the light or sound react by gestures?<br>

How about interacting with other physical objects? For example, if you flip book pages the sound volume increases. Or if you touch an orange the light turns on and off. 

2. A cup plate that recognizes the temperature of your drink and tells you when it's  a perfect time to drink. There will be three lights on the plate: Red, white, and Blue. Red means it's too hot, Blue means it's too cold, and white means it's at the right temperature. When the drink reaches the good temperature zone, it makes the sound to let the user know about it. 
References for the project

#### Sketches/Ideation
(I put an image, but it's not showing up for some reason...)
<html>
<img src = "https://github.com/TaeyoungYun49/arduino_2018/blob/master/Project1_Ideation.jpg">
</html>

#### Reference for Schematic
#### Plant Communicator
Ever wished you could talk with your plants?<br>
https://create.arduino.cc/projecthub/arduino/plant-communicator-7ea06f?ref=platform&ref_id=424_trending___&offset=21<br>
#### Arduino Sunflower
The sunflower follows the light using a servo motor and two photoresistors. <br>
https://create.arduino.cc/projecthub/Rick_Findus/arduino-sunflower-c4fd84?ref=platform&ref_id=424_trending___&offset=63<br>
#### Motion controlled color changer
Using the power of motion, swipe in 4 directions to change the color of an LED! <br>
https://create.arduino.cc/projecthub/gatoninja236/motion-controlled-color-changer-299217?ref=tag&ref_id=sensor&offset=10<br>
#### Arduino Temperature - Humidity - Rain Sensor
On the display is printed temperature (celsius) and humidity (%) with a DHT11. When it's raining the LED lights up. You need a rain sensor!<br>
https://create.arduino.cc/projecthub/Rick_Findus/arduino-temperature-humidity-rain-sensor-4ef707?ref=tag&ref_id=sensor&offset=27<br>
#### Reactive LED Coffee Table - Arduino
https://www.youtube.com/watch?v=xkohbr9ApMo<br>
#### DIY Interactive Coffee Table
https://www.youtube.com/watch?v=L3l-zJafOnc&t=100s
