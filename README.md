# Arduino Lazer Tag
This is the public repository for my school project of creating lazerguns using Arduino's. Our lazer guns worked by shooting the opposite person/gun once you killed someone you would have to reload your gun by hitting the button on the bottom. If you were shot you would have to wait a few seconds before you could shoot again

![IMG_0133](https://user-images.githubusercontent.com/61181739/75017129-b52cfb00-548c-11ea-9102-b14d7b8ecdae.JPG)

# Disclaimer
This project involves hardware and power there is always the chance that you may shortcircuit a board or part. Please build this at your own risk and consult an expert. I am not an expert and this code is just what i used. I am not responsible for any damages you create

⚠️⚠️WARNING⚠️⚠️ This project also involves lazers, these are dangerous and should only be used by responsible people under supervision. Please be safe and be carefull. Shining these in peoples eye can seriously hurt them! I am not responsible for any damages you create using this code.

# Required Hardware
- 2x Arduino - I used two arduino nano's
- At least 1 USB cable
- working computer with the Arduino IDE running 
- 2x IR receiver
- 2x IR blaster or IR LED
- 4x Pushbutton's
- Resistors, for the led's, buttons and other components
- Batteries, kinda essential for mobility (with connector)
- Wires

Optional items that we used
- 2x LED lazer, for extra shooting effects
- 2x Piezo speaker, for buzzing sounds when you shoot, get shot or die
- 2x RBG LED, to signal your team and current health status
- Water pistols
- Lots of hot glue for sealing the water pistols


# How to build
To build this project you will need the materials listed above. You can connect everything to the pins that are defined in the arduino sketch

```
const int buttonPin = 2;    
const int ledPin =  13;      

// RGB LED
int redPin = 5;
int greenPin = 6;
int bluePin = 7;

int lazer = 9;

int piezo = 8;

int blue_LED = 13;
```

Dont forget to add a reload button which was directly connected to the reset (RST) and grond (GND) pin. 

After connecting all the pins to the arduino you should connect all the modules to ground and VCC we removed one of the powerrails of a breadboard to do this, since the arduino doesn't have enough pins all of the modules. 

Next upload the code using the arduino ide. You might get an error saying that you dont have all the required libaries. Then you should download the IRremote libary created by Shirriff at the following link https://www.arduinolibraries.info/libraries/i-rremote

After uploading the code and checking if it all works it is time to connect the battery. 
⚠️⚠️WARNING ⚠️⚠️ NEVER POWER THE ARDUINO USING BOTH THE BATTERY AND THE USB CALBE! this might overload your arduino and cause it to burn up

Once your done with it all you can enclose it in a housing and go play with it

Have fun!

# Future development ideas
- 3d printing the housings to make them more stirdy
- Use an esp8266 node mcu
  - Use an esp8266 node mcu instead of the arduino nano to make an app and connect your phone to the gun for extra statistics and game/team selection
  - Use the node mcu's wifi to connect to local wifi and to a server on a computer or raspberry pi to count live statistics and maybe even live location data to see where your freinds are

# Credits
Credits to the IRremote libary by Shirriff! More info on his libary can be found here
https://www.arduinolibraries.info/libraries/i-rremote
