# Safety-helmet
## A safety helmet that sends messages to the user incase of emergencies

The project uses an ESP8266 to read data from a 3 axis Accelerometer, the ESP8266 is also set to read the geolocation of the user through a python script, the computation and recording of values happens in the Thingspeak Cloud.
Link to thingspeak cloud:

If the value of the Accelerometer excceds a certain value, an email alert will be sent to the user's contacts using the thingspeak alerts API.

Circut Diagram:

![image](https://user-images.githubusercontent.com/69049502/133926558-26a5680a-3a79-4ab3-9935-4dab7e66aa95.png)


Alert Demo:

![image](https://user-images.githubusercontent.com/69049502/133926576-926c40c4-2b0b-4eca-9faf-dd6a3d483557.png)
