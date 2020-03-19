# Smart-Lighting-System---Basic
In this project the LDR sensor checks for the amount of light present in the room and if the LDR value is below the defined threshold value then, it turns on the light.

Hardware Used:
1. NodeMCu(ESP8266) WiFi Module
2. LED's - 4
3. LDR (Light Dependant Resistor)
4. 10K Resistor

Software Used: Arduino IDE

Cloud Platform: ThingSpeak IOT (Create your own ThingSpeak Account & create new channel)

Hardware Connections:
1.Led1 Anode - GPIO16 (NodeMCu)
2.Led2 Anode - GPIO5 (NodeMCu)
3.Led3 Anode - GPIO4 (NodeMCu)
4.Led4 Anode - GPIO12 (NodeMCu)
5.LDR Sensor - A0 Pin (NodeMCu)

Google - connection of LDR with NodeMCu/Arduino

Libraries to be downloaded & installed for Arduino code:
1. ThingSpeak.h
2. ESP8266WiFi.h
3. WiFiClient.h


Edit required in the code:
1. Change the 'ssid' and 'pass' value with your WiFi(ssid) name and its respective password.
2. Create a Channel on Thingspeak Cloud and get the Channel_ID, Write Api Key and Read API Key.
3. Replace the Channel_ID, Write Api Key and Read API Key in the code.
4. Check the pins connected are correct.

Now, it is time to upload a code and start your IOT Smart Light System.
