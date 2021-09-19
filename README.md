# Safety-helmet
A safety helmet that sends messages to the user incase of emergencies

The project uses an ESP8266 to read data from a 3 axis Accelerometer, the ESP8266 is also set to read the geolocation of the user through a python script, the computation and recording of values happens in the Thingspeak Cloud.
Link to thingspeak cloud:

If the value of the Accelerometer excceds a certain value, an email alert will be sent to the user's contacts using the thingspeak alerts API.

Circut Diagram:

