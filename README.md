## Maker100-Eco    THIS IS A DRAFT AND NOT YET READY!

An economical version of my successful [Maker100](https://github.com/hpssjellis/maker100) Robotics, IoT and TinyML Machine Learning in-person course this time using less expensive hardware such as the [$13.99 USD Seeedstudio XiaoEsp32s3](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) for the course basics and some [EdgeImpulse.com](https://edgeimpulse.com/) cell phone assisted machine learning and the [$14.50 USD RakWireless RAK2270StickerTracker](https://store.rakwireless.com/products/rak2270-rak-sticker-tracker?variant=43046272303302) for the LoRa/LoRaWan and Motion (x,y,z) machine learning using [tinyMLjs](https://hpssjellis.github.io/tinyMLjs/public/index.html) a static webpage webSerial Machine Learning method I have made.


Views better using the README.md [here](README.md)

This is not an online course, it is expected to be taught by a teacher or professor. Some students might be able to  do the course on their own, but many components of learning opportunities may be missed.

Price list for the equipment I will be using in 2024 [price-list-2024.md](price-list-2024.md) (Many other devices could be used but the videos then will not be accurate for those devices)



<details closed> <summary>Teacher Extras</summary>

<br><br><br>
<hr />
<details closed> <summary>Why Not use the XIAO Expansion board and Round Display?</summary>
   The Seeedstudio [$16.40 USD Exanpsion board](https://wiki.seeedstudio.com/Seeeduino-XIAO-Expansion-Board/) and [$18.00 USD Round Display](https://wiki.seeedstudio.com/get_start_round_display/) are amazing inexpensive addons to the XIAO-ESP32s3-sense and are very well explained on the Getting started sites listed above. <br><br>I have both for my classrooms and may use them as the year goes on, but I have testing to do to find out if the color round display is as fast as my grayscale OLED and I do not like students using I2C and SPI connectors that come with the expnasion board because the students naturally begin to feel that they can only use sensors and actuators that come with the correct connectors. <br><br>The students for their final projects stay away from new or unusual sensors/actuators  because those sensors do not come with the correct connectors. A possible solution is to have the [grove-4-pin-female-jumper-wire](https://ca.robotshop.com/products/grove-4-pin-female-jumper-wire) I would prefer the male pins but it is electrically safer to have the female pins. It also does not help that so many boards use different connectors. I have lots of sensors with connectors that don't work with the grove systems. If you are just starting a course and know that you are going to stick with the [Grove sensor actuator system](https://wiki.seeedstudio.com/Grove_System/) and have a few extra connectors on bare wires ordered for new devices then the expansion board might be a great way to teach.<br><br>
   If you choose to uswe the expansion board this ebook [here](https://mjrovai.github.io/XIAO_Big_Power_Small_Board-ebook/) covers working with it very well.

   
</details>

<br>
<hr />



<details closed> <summary>Teacher Tips</summary>
<ol>
  <li> Students work on term assignments in partners and make very short videos that teache what they did for each assignment.</li>
  <li>I expect all students to try to improve and change each assignment. "Until you change computer code do not expect to understand it"</li>
  <li>I expect all students to draw circuit diagrams before connecting wires and have someone check the diagram and then to connectr the wires and have someone also check before stuidents connect power or connect to the computer.</li>
  <li>I teach one assignment per class but expect several students to work ahead and solve missing parts of the prossess in small groups, also some students will fall behind, this allows us to have fewer sensors and actuators since the class rarely uses them at the same time. I can often get away with 4 sensors for an entire 30 person class</li>
  <li>The faster students finish the course the more time they have for their final projects</li> 
  <li>To pass the course everyone must complete at least one final project using a sensor connected to an actuator of their choice</li>
  <li> Students plan 2 individual main projects and possibly one group project. Each main project must include at least one sensor with one actuator</li>
  <li> Many student's will only complete one main project and that is fine. "Robotics projects are very difficult to finish" </li>
  <li> Many final projects will need structures built to support them. Any safe material is fine, we typically 3D print the sturctures although carboard and or wood is often used </li>
  <li> Final projects typically do not involve high voltage, water or drones for the obvious safety reasons.  </li>
  <li> I tell students that if every term assignment is complete the indivdual final project is there full mark if that helps their grade</li>
  <li>Teacher's may decide to make several of the advanced assignments optional or even set for bonus marks</li>
  <li>Use LLM such as ChatGPT to help understand what the code does or how to improve the assignment</li>
</ol>

</details>

<br>
<hr />

<details closed> <summary>Why Maker100-Eco?</summary>
The arduino PortentaH7 with LoRa Vision Shield is an encredible TinyML device that can do amazing things and has been a joy to teach, but I am part of an international group trying to bring tinyML to the students in developing countries called [tinyML4D](https://tinyml.seas.harvard.edu/team) and the Arduino PortentaH7 is just too expensive for student explorations. 

Since schools spend a large amount of their budget on Computers, Laptops, iPads and the technology to integrate them safely with the internet I feel that any method technology teachers can do to reduce costs is good for the entire educational system.
</details>

<br>
<hr />
<details closed> <summary>How much cheaper is the Eco version</summary>

The [Arduino PortentaH7](https://store-usa.arduino.cc/products/portenta-h7) costs $113.90 USD the [LoRa Vision Shield](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-lora%C2%AE) Costs $69 USD


The [XiaoEsp32s3-sense](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html)  costs $13.99

and the [RAK2270 Developer](https://store.rakwireless.com/products/rak2270-rak-sticker-tracker?variant=43046273286342) costs $14.50 USD


So


3 x ($113.90 + $69) =  3 x $182.90   =   548.70        >      15 x $13.99 + 15 x $14.50 =     $209.85  + 217.50  =  $427.35

3 x PortentaH7 + vision shield = $548.70 USD which is more than 15 x (XIAO-esp32s and RAK2270 ) = $427.35 USD 

Note: the rak2270 will need a few ~$10 rigs to communicate over a serial monitor

So for the price of 3 PortentaH7 with LoRa Vision shields I can get a full class set of 15 MCU of both types (XIAO-sense and RAK) that span my complete curriculum

Probably a good idea to spend a bit of money purchasing the clips (rigs) for connecting the Sticker Trackers to serial ports.


<hr>

Very hard to compare the Xiao/Rak class set for $427.35 USD with a class set of PortentaH7's ($15 x $182.90) = $2743.50 USD

</details>


<br>
<hr />


<details closed> <summary>Useful Links</summary>


<ol>

<li>The original Maker100 Course is https://github.com/hpssjellis/maker100 </li>

  
<li>SeeedStudio Link to the XiaoEsp32s3-Sense store https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html     Note: It needs headers soldered to do many of the assignments. </li>

<li>RakWireless ~$15 USD RAK2270 Sticker Tracker   store is at  https://store.rakwireless.com/products/rak2270-rak-sticker-tracker?variant=43046272303302) </li>


<li>The original XiaoEsp32s3 and RAK2270 research is at https://github.com/hpssjellis/mcu-stable-edu-launch</li>

<li>TinyMLjs is at https://github.com/hpssjellis/tinyMLjs</li>

<li>RocksettaTinyML Library is at https://github.com/hpssjellis/RocksettaTinyML</li>

</ol>
</details>

  
<br>
<hr />



<hr>
For each row the checkbox will be checked when the activity is tested and the boxes eventually will be removed.<br> <br>     


&#9745; has been tested on the relevant device, code, video and instructions are working

&#10004; This code works just the video or instructions are not yet fully ready

&#10003; Old Portenta code and video might work just not yet tested

&#10062; I know this doesn't work, just trying to figure out how to make it work

&#9744;  Means not yet tested or just plain old Portenta code

<hr>


</details>





## Seeedstudio XiaoEsp32s3 Currciulum

##
THIS IS A DRAFT AND NOT YET TESTED!






# Example One Hour Session using the XiaoEsp32s3-sense
Note: soldered headers not needed, but a USB-C cable and computer or laptop to run the code is neede
| Topic | Example Code| Video | Instructions and Prompt|
|:---|:---|:---|:---|
| &#9745; <a name="0" href="0">`0`</a>  Follow the Sensecraft Vision example  |  [wiki.seeedstudio.com/sscma/](https://wiki.seeedstudio.com/sscma/)   |   |    <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |






<br><br><br>


# One Day Conference using the XiaoEsp32s3-sense
Note: soldered headers are not needed, but a cell phone or webCam laptop is needed, along with a usb-C to USB-A cable
Students are encouraged to work ahead.

| Topic | Example Code| Video | Instructions and Prompt |
|:---|:---|:---|:---|
|  &#9744;  <a name="0" href="0">`0`</a>   Make a vision classification machine learning model using your cell phone    |     [edgeimpulse.com](https://studio.edgeimpulse.com/login)              | This is a full playlist so many other videos here might help  [<img src="https://img.youtube.com/vi/wbX_-No8kIw/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=wbX_-No8kIw&list=PL57Dnr1H_egsQPnEObWHPhK1Q4g_IDWcR&index=7)              | This website is a good starting point [https://hpssjellis.github.io/multi-language-edgeimpulse-tutorial-vision-cell-phone/](https://hpssjellis.github.io/multi-language-edgeimpulse-tutorial-vision-cell-phone/). For this assignment we are not using the microcontroller.    <details closed> <summary>More Instructions</summary> Connect your cell phone to EdgeImpulse, take 30 images of pens on various backgrounds, then take 50 images of various backgrounds, create your impulse (96 x 96), generate features, train and then switch to classification on your cell phone  </details> <details closed> <summary>ChatGPT Prompt</summary> Give me the steps to make a vision classification model on edgeimpulse.com with only an unknow label for the background and pens for the object. We will only be using our cell phone to collect the images, so it will need to be connected to the edgeimpulse site. The cell phone will allow the image labelling before I take the images. After the images are taken explain how to setup the impulse machine learning model.</details> |
| &#9744;  <a name="0" href="0">`0`</a>  Put the one hour conference Vision model on the XiaoEsp32s3  |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;   <a name="0" href="0">`0`</a>  Using your cell phone to make a FOMO model   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Put the FOMO model onto the XiaoEsp32s3  |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |







<br><br><br>
# Second Day Conference using the XiaoEsp32s3-sense
Note: soldered headers not needed, but a cell phone or webCam laptop is needed, along with a USB-C to USB-A cable and a micro sd-card
Students are encouraged to work ahead.

| Topic | Example Code| Video | Instructions and Prompt |
|:---|:---|:---|:---|
| &#9744;   <a name="0" href="0">`0`</a>  Use your cell phone to make a Sound Model   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;   <a name="0" href="0">`0`</a>  Put the sound model onto your XiaoEsp32s   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  (optional) Try the Edgeimpulse connection method  |   [edgeimpulse.com](https://studio.edgeimpulse.com/login)      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="#0">`0`</a> Edge-Impulse-Sound-Yes-No            | |              |   Follow the wizard on Edgeimpulse to make a verbal Machine Learning model using your cell phone. Then download the Arduino deployment, install the zipped Arduino library and choose the default Portenta Sound example. Then talk into your Portenta and view the Serial Monitor. Then get the onboard LED to respond to your voice.            |
| &#9744;  <a name="0" href="#0">`0`</a> Edge-Impulse-Vision-FOMO                          |      Use the Vision grayscale OLED from above and the [dot5148-advanced-fomo-individual-count](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot5-portenta-machine-learning/dot51-portenta-edge-impulse-ml/dot514-vision-fomo/dot5148-advanced-fomo-individual-count/dot5148-advanced-fomo-individual-count.ino) Note: Use the Portenta Pro Library as the include file will auto load. Then just change the deployed Edgeimpulse include file to the correct name.   |   Like the original classification model, just now with bounding boxes and you label each object to detect  |
| &#9744;  <a name="0" href="0">`0`</a> XiaoEsp32s3 camera to micro sd-card to FOMO model to XiaoEsp32s3   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  EdgeImpulse cell phone motion x,y,z model   |      |     | Do this for later in the course when we use the RAK2270StickerTracker to get an idea of what we are doing. If you have a motion sensor for the XiaoEsp32s3-sense then you could upload this model to it but that is optional  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="#0">`0`</a>  Auto Blink and Serial Print  | [dot11-hello-blink.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot1-portentaH7-examples/dot11-hello-blink/dot11-hello-blink.ino) |      [<img src="https://img.youtube.com/vi/3E5KUT115xY/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=3E5KUT115xY&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=7)         |                     Print other things and change the pattern of blinking using different colors LEDR, LEDG, LEDB, LED_BUILTIN (which is green). Note: I stay away from LEDR as red is used to show errors    |
| &#9744;  <a name="0" href="#0">`0`</a>  Flash SOS                           |     [dot71-sos](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot7-coding-curriculum/dot71-sos/dot71-sos.ino)                                                                                                                                                                         |       [<img src="https://img.youtube.com/vi/iDC3vuBGGcg/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=iDC3vuBGGcg&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=11)          |                    Get the code running to flash the LED_BUILTIN, then have it flash an SOS. 3 short flashes, 3 long flashes, 3 short flashes then a 5 second rest.     |
| &#9744;  <a name="0" href="0">`0`</a>  []()   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  []()   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |


Note: For the 2nd day of a conference users without soldered pins may want to try the IOT part of the course [#iot-part-of-the-in-person-course-using-the-xiaoesp32s3-sense](#iot-part-of-the-in-person-course-using-the-xiaoesp32s3-sense)






<br><br><br>
# In-Person Course on Sensors using the XiaoEsp32s3-sense
Note: soldered headers are now needed on the XiaoEsp32s3-sense
Students are encouraged to work ahead of the class.

| Topic | Example Code| Video | Instructions and Prompt|
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="#0">`0`</a>.  Button causes LED to blink          |       [dot228-button-control-led.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot228-button-control-led/dot228-button-control-led.ino)                                                                                                                                                                     |    [<img src="https://img.youtube.com/vi/wFw-AF8gwiY/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=wFw-AF8gwiY&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=2)           |                   <img src="media/b-b-h-button-control-led.jpg" width = 200/>  <br>        Control the LED with the button, then control multiple LED's with Multiple Buttons. Note: Can't control large current flow devices, WHY? Could you make the external LED interact like the internal LED?    |
| &#9744;  <a name="0" href="#0">`0`</a> Analog Read (Voltage divider for various 2 prong sensors (variable resistors: flex sensor, photoresistor, touch/pressure sensor))                |  [dot211-any-variable-resistor-sensor.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot21-sensors/dot211-any-variable-resistor-sensor/dot211-any-variable-resistor-sensor.ino)                                                                                                                                                                            |       [<img src="https://img.youtube.com/vi/GR3D8C6dOl8/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=GR3D8C6dOl8&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=3)            |                 Change the Resistor amount and which resistor is attached to 3V3 to get the largest most sensible range of readings.     |
| &#9744; <a name="0" href="#0">`0`</a> DAC to ADC                         |       [dot1a-DAC-to-ADC.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot1-portentaH7-examples/dot1a-DAC-to-ADC/dot1a-DAC-to-ADC.ino)                                                                                                                                                                       |    [<img src="https://img.youtube.com/vi/PWtQeHqyDUM/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=PWtQeHqyDUM&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=8)            |                    Estimate the Voltage that the digital pin converts from 0 to 1, it should be close to half of 3V3     |
| &#9744;  <a name="0" href="#0">`0`</a>  Serial SPI Pixy2                          |           [dot212-pixy2-SPI.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot21-sensors/dot212-pixy2-SPI/dot212-pixy2-SPI.ino)  Note: Dot212 Pixy example using the Portenta pro community solutions library will be pre-setup with the pixy include files!                                                                                                                                                                 |       [<img src="https://img.youtube.com/vi/p8KmFFqqU6U/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=p8KmFFqqU6U&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=14)              |                 <img src="media/pixy-connector.png" width = 200/>     <br>    The Pixy2 is so cool students will have no problem coming up with things to detect. The Pixy2 is really good for a final project since students just need to connect an actuator. Example: when you see the "orange" cat have a servo open a lever to feed it.    
|  &#9744; <a name="0" href="#0">`0`</a> Serial UART FingerPrintScanner-FPS (Video not ready)              |               [dot216-fingerprint-scanner](https://github.com/hpssjellis/portenta-pro-community-solutions/tree/main/examples/dot2-portenta-h7-with-accessories/dot21-sensors/dot216-fingerprint-scanner) | | Ask the teacher about this sensor |
| &#9744;  <a name="0" href="#0">`0`</a> GPS                           |         [dot215-grove-gps-air530.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot21-sensors/dot215-grove-gps-air530/dot215-grove-gps-air530.ino)  Only proof of connection.                                                                                                                                                                    |               |                  Try https://www.gpsvisualizer.com/ with the data saved with .GPS extension         Real Assignment: Parse the output for Latitude, Longitude, date time and height, perhaps use: TinyGPS, TinyGPS++, TinyGPSPLUS, NeoGPS libraries.  Then paste your latitude, longnitude into this url  /maps?q=lat,lon example: http://maps.google.com/maps?q=62.44,-114.4  for Yellowknife Canada |
| &#9744;  <a name="0" href="#0">`0`</a> Accelerometer                           |      Just load MKRIMU library and run the accelerometer example. Note bend the reset pin on the MKR IMU, When that is working login to edgeimpulse and make a motion model using your cell phone, to detect a wave. Then download it to the Portenta and get the onboard LED working when you wave.                                                                                                                                                                      |        |           You can do this all on your own. connect the MKR IMU to the portenta then lookup how to do the example. Note: bend the reset pin of the MKR IMU away from connecting to the Portenta. Causes issues.                          |
| &#9744;  <a name="0" href="#0">`0`</a> Range-Finder                          |      [dot214-RangeFinder.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot21-sensors/dot214-RangeFinder/dot214-RangeFinder.ino)     |     [<img src="https://img.youtube.com/vi/E1B_iE171E8/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=E1B_iE171E8&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=13) |  For this assignment a variable in the code can be changed to make the range finder work at a greater distance.  |
| &#9744;  <a name="0" href="#0">`0`</a> SD-card-Vision-Shield             | A great bit of code to run is [here-dot362-png-to-sd-card](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot3-portenta-vision-shields/dot36-camera-png-to-web/dot362-png-to-sd-card/dot362-png-to-sd-card.ino) which allows pictures in PNG format to be loaded onto the SD card based on a user set delay.   |   |       This is another one students can probably do themselves using the default programs for the Portenta. You will need a micro SD card.       Portenta examples it is called  Portenta_SDCARD  |
| &#9744;  <a name="0" href="#0">`0`</a> Microphone-Vision-Shield                          |         Example PDM then use your cell phone to make a sound model on EdgeImpulse. Such as your name. The download the arduino file and get your Portenta recognizing your name by lightening the onboard LED.     |               |                     This is another one students can probably do themselves using the default programs for the Portenta called the PDM. Instead of the serial monitor load the Serial Plotter to see your voice when you speak. Then make the edge impulse sound model and load it on your Portenta.         |







<br><br><br>
# In-Person Course on Actuators using the XiaoEsp32s3-sense
Note: soldered headers are now needed on the XiaoEsp32s3-sense
Students are encouraged to work ahead of the class.

| Topic | Example Code| Video | Instructions and Prompt|
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="#0">`0`</a> Servo                           |      [dot221-servo.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot221-servo/dot221-servo.ino)                                                                                                                                                                        |       [<img src="https://img.youtube.com/vi/4p3yIF_4pk8/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=4p3yIF_4pk8&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=6)          |                 MUST HAVE AN EXTERIOR BATTERY TO RUN THE 6 VOLT SERVO!  I have the Pololu Servo Product number 1057, Power HD High-Torque Servo 1501MG [here](https://www.pololu.com/product/1057).  <br> To connect Portenta D5 (orange wire) GND (brown wire) to servo, <br> 6 volt battery positive (red) and Negative (brown) to servo.   |
| &#9744;  <a name="0" href="#0">`0`</a> Transistor                            |      [dot224-pwm-transistor.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot224-pwm-transistor/dot224-pwm-transistor.ino)                                                                                                                                                                        |         [<img src="https://img.youtube.com/vi/XqxTnUFlMnY/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=XqxTnUFlMnY&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=17)    |     <img src="https://user-images.githubusercontent.com/5605614/156191081-89142347-8494-46d0-ae48-53566c884bc9.png" width = 200/> <br>  <img src="https://user-images.githubusercontent.com/5605614/156191554-49bd23c3-d38c-4fc5-b04f-8ec9add68763.png" width = 200/>     <br>                        Make either the PNP transistor with small motor or the NPN transistor. For higher marks do both. |
| &#9744;  <a name="90" href="#0">`0`</a> Small Dual DC Motor Driver                            |       [dot226-small-dual-dc-motor-driver.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot226-small-dual-dc-motor-driver/dot226-small-dual-dc-motor-driver.ino)  |     [<img src="https://img.youtube.com/vi/lUE-hmAddhY/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=lUE-hmAddhY&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=5)     |     <img src="media/b-b-f-small-dual-dc-motor-driver.png" width = 200/>     <br>  Get a small motor working using it's own power supply and change the code so it does what you want. Pololu #2135 DRV8835 Dual Motor Driver Carrier  [here](https://www.pololu.com/product/2135)     |
| &#9744;  <a name="0" href="#0">`0`</a> Large DC Motor Driver                          |     [dot227-big-dc-motor-driver.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot227-big-dc-motor-driver/dot227-big-dc-motor-driver.ino)                                                                                                                                                                         |       [<img src="https://img.youtube.com/vi/YcRQSFhr8MY/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=YcRQSFhr8MY&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=7)         |                  <img src="media/b-b-g-big-dc-motor-driver.png" width = 200/>   <br>     Get a 6V motor running and change code for it to do what you want. Protect the Phton from the 6 Volt motor side. Check Pololu 1451 VNH5019 Motor Driver Carrier [here](https://www.pololu.com/product/1451)     |
| &#9744;  <a name="0" href="#0">`0`</a> Stepper Motor                         |           [dot225-stepper-motor.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot225-stepper-motor/dot225-stepper-motor.ino)                                                                                                                                                                   |      [<img src="https://img.youtube.com/vi/Fru6QtzLnrI/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=Fru6QtzLnrI&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=4)            |                     <img src="media/b-b-e-stepper-motor.png" width = 200/>     <br>     Note: This stepper needs 6V, Change code to do what you want.  Pololu 2134 DRV8834 Low-Voltage Stepper Motor Driver Carrier [here](https://www.pololu.com/product/2134)   |
| &#9744;  <a name="0" href="0">`0`</a>  Multiplexer (mux)   |      |     | Connect the XIAO using I2C to a multiplexer a device that allows more pins to be used when your board runs out of pins Typically for a large project  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Use a 2nd XIAO as an I2C multiplexer   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="#0">`0`</a>  PCB Board Build using [easyEDA](https://easyeda.com/)                                                                                                                                                                                                    |  Great starter tutorial to make a PCB with a battery holder, resistor and ligtht<br>   [<img src="https://img.youtube.com/vi/gjPNYMRA0m8/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=gjPNYMRA0m8&list=PLbKMtvtYbdPMZfzGuVTdc0MWKrFvU4nsu&index=2)      ||       I have found lots of PCB design videos that are either to complex or just long and boring. The video pressented here was not made by me but is very short and many of my animation students can follow it very quickly to make their own board using easyEDA   |



<br><br><br>
# Actuators and Grayscale OLED  using the XiaoEsp32s3-sense
Note: soldered headers are now needed on the XiaoEsp32s3-sense
Students are encouraged to work ahead of the class.

| Topic | Example Code| Video | Instructions and Prompt|
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="#0">`0`</a> Serial I2C OLED                          |          [dot222-I2C-grove-OLED.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot222-I2C-grove-OLED/dot222-I2C-grove-OLED.ino)     |    [<img src="https://img.youtube.com/vi/ruykYcViWo0/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=ruykYcViWo0&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=10)       |                   <img src="media/b-b-b-I2C-grove-OLED.png" width = 200/>    <br>     Have fun with this. Have it say what you want, where you want it and for how long.     |
| &#9744;  <a name="0" href="#0">`0`</a> Camera-Vision-Shield with Grayscale OLED                           |                                                                                                                                                                              |               |   Get the Portenta Camera working with the Grayscale Waveform 128x128 OLED [dot351-camera-oled-regular.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot3-portenta-vision-shields/dot35-camera-and-oled/dot351-camera-oled-regular/dot351-camera-oled-regular.ino)               This is another one students can probably do themselves using the default programs for the Portenta.         |
| &#9744; <a name="0" href="#0">`0`</a> Rocksetta-Machine-Learning-Sine-Wave  or e-ink display                         |   TensorflowLite seems to be deprecated so try doing the e-ink display.  See Ambrose until he has a solution. preesently use the Waveshare e-ink libraries. File [here](https://github.com/hpssjellis/maker100/tree/main/downloads) <br>Must edit the epdif.h file to list which pins to use<br> Pin definition <br>#define RST_PIN     5  <br>#define DC_PIN      4  <br> #define CS_PIN      3 <br>   #define BUSY_PIN    2  <br><br>The tensorflowlite code is    [dot521-rocksetta-hello-ml-sine.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot5-portenta-machine-learning/dot52-portenta-rocksetta-ml/dot521-rocksetta-hello-ml-sine/dot521-rocksetta-hello-ml-sine.ino)       |
| &#9744;  <a name="0" href="#0">`0`</a> TFT Touch Screen or 128x128 Grayscale Fast refresh OLED                         |        [dot218-TFTV2-touchScreen.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot21-sensors/dot218-TFTV2-touchScreen/dot218-TFTV2-touchScreen.ino)  or  [dot229-128x128-gray-oled.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot2-portenta-h7-with-accessories/dot22-actuators/dot229-128x128-gray-oled/dot229-128x128-gray-oled.ino)                                                                                                                                                                    |       [<img src="https://img.youtube.com/vi/SvW3U7YzV0Y/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=SvW3U7YzV0Y&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=16)       |                           <img src="https://user-images.githubusercontent.com/5605614/235280870-60b51050-58c9-4494-a663-57518bee4e14.png" width = 200/>     <br>    Real Assignment: Presently the Touch Screen sensor is not reading completly to the edges of the screen, see if you can figure out why? Is it just the mapping of raw values to real values, the main resistor amount set at 300 ohms, the wire length. What is it? Fix it.    |
| &#9744;  <a name="0" href="0">`0`</a>  []()   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  []()   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#10004;  <a name="0" href="0">`0`</a>  Lidar   |  [a99b-lidar-oled.ino](./seeed-sketches/a99b-lidar-oled.ino)    |     | Connect the Lidar and Grayscale OLED and see if this code works. Power the Lidar seperately from the XIAO for safety sake until someone says you don't need to  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |






<br><br><br>
## IoT part of the in-person course using the XiaoEsp32s3-sense
Note: soldered headers not needed (this part of the course could be done earlier)
Students are encouraged to work ahead of the class.

| Topic | Example Code| Video | Instructions |
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="0">`0`</a>  WiFi WebServer  |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Camera Streaming   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Sound Streaming (Not yet done, maybe can't be done)   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="#0">`0`</a> Serial-putty or Linux "screen"         | This is a program to load on your computer that replaces the arduino serial monitor           |      |      Fairly easy once putty is installed. Load power shell and type mode with your Portenta programmed with a serial monitor program find the port. Then switch to Serial on Putty and Correct the COM port. Open and see if you can see serial output from the Portenta        |
| &#9744;  <a name="0" href="#0">`0`</a> Web-AdafruitIO-Connectivity                        |   [adafruit login](https://accounts.adafruit.com/users/sign_in)  <br> <br> Record your user name and access key. Both the browser web socket and the Arduino MQTT program use those values. <br><br>  MQTT-Websocket [ada-websocket02.html](https://hpssjellis.github.io/my-examples-of-iot-platforms/public/ada-websocket02.html) <br> With Arduino MQTT Portenta code  [dot184-mqtt-client-to-adafruit.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot1-portentaH7-examples/dot18-wifi-webserver/dot184-mqtt-client-to-adafruit/dot184-mqtt-client-to-adafruit.ino)<br> <br> The MQTT library to install was written by Joel Gaehwiler is is way down on the list  <br><br>Arduino https uses webhooks but might not work due to changes in the arduino code [dot183-https-to-adafruit.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot1-portentaH7-examples/dot18-wifi-webserver/dot183-https-to-adafruit/dot183-https-to-adafruit.ino)       |   Everything will be at this website <a href="https://hpssjellis.github.io/my-examples-of-iot-platforms/public/index.html">Adafruit-Connectivity</a>      | This is a good but large project. A lot for students to learn here |
| &#9744;  <a name="0" href="0">`0`</a>  Bluetooth Connectivity   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="#0">`0`</a> Web WiFi   (need router acces to make global)                         |   [dot181-wifi-webserver.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot1-portentaH7-examples/dot18-wifi-webserver/dot181-wifi-webserver/dot181-wifi-webserver.ino)                                                                                                                                                                           |         [<img src="https://img.youtube.com/vi/oygGsGLLLGM/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=oygGsGLLLGM&list=PL57Dnr1H_egv1FVzAcCZVeANJMs3Hta05&index=9)        |                   Several layers to this project. Often easier to use your cell phone hot spot as a school's WiFi often has several layers of security. I will still need to work with my School IT department to: A. get the WiFi working and B. get an outside port. Probably wont happen. Change the buttons on the webpage to control some Actuator other than an LED    |






<br><br><br>
## Advanced Part of the course, the RakWireless LoRa/LoRaWan RAK2270StickerTracker

This part of the course is much more challenging than the above. Some teachers may choose to do it for an advanced 2nd year part of the program. I typically let students who have done the course before or are going very fast through the course in the first year to do this part.



# Example One Hour Session about the RAK2270StickerTracker
Note: The actual sticker tracker would not be needed for a one hour session

| Topic | Example Code| Video | Instructions and Prompt|
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="0">`0`</a>  Overview of the Rak2270   |      |     | TrackPac, LoRaWan, then P2P LoRa Motion Machine Learning using TinyMLjs, WebSerial LoRa Summary  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
 
<br><br><br>using one RAK2270 as the P2P receiver






# One Day Conference using the RAK2270StickerTracker
Note: Each person or group will need the [RAK2270 Sticker Tracker Developer kit](https://store.rakwireless.com/products/rak2270-rak-sticker-tracker?variant=43046273220806) with serail rig called the clip

Needs testing, might need a Linux computer to run the ML programs.

| Topic | Example Code| Video | Instructions and Prompt |
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="0">`0`</a>  RAK Read values  |      |     | Use the RAK rig and connect to the Arduino serial monitor to read all the present set LoRa and LoRaWan variables  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  (Optional) RAK2270StickerTracker [trackpac.io](https://trackpac.eu.auth0.com/u/login) setup   |      |     |  If you have the original RAK2270 Sticker Tracker with TrackPac.io then set it up and monitor your deivce <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Machine learning motion x,y,z two label tinyML model   |      |     | This is advanced and uses the static website [tinyMLjs for the RAK2270StickerTracker](https://hpssjellis.github.io/tinyMLjs/public/acceleration/a00-best-acceleration-rak2270-sticker-tracker.html)  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  LoRa webSerial reciever   |      |     | Another advanced use of a static website and webSerial to connect one sticker tracker to receive P2P LoRa information from the other motion machine learning trained devices  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
<br><br><br>


## In-person course using the RAK2270StickerTracker
Students are encouraged to work ahead of the class.

| Topic | Example Code| Video | Instructions |
|:---|:---|:---|:---|
| &#9744;  <a name="0" href="0">`0`</a>  LoRa Test   |      |     | Your device should be able to send data to your tecahers device over a local P2P LoRa network <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Run Temperature and humidity   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  LoRaWan Test   |      |     |  This get s confusing, but setup a full LoRaWan, Helium to Adafruit.io connection pipeline to read both the temperature and humidity data from teh Sticker Tracker  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Run xyz acceleration   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
|  &#9744; <a name="0" href="0">`0`</a>  Sensor Fusion   |      |     | Run code with all the Sensors on the RAK2270: temperature, Humidity, 9 axis IMU: motion (xyz), gyro (xyz), magnetic (x,y,z)  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="#0">`0`</a> LoRaWan-Helium-MQTT-Adafruit (easier)                           |     [dot334-us915-helium-mqtt-adafruit-connect.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot3-portenta-vision-shields/dot33-lorawan-specific/dot334-us915-helium-mqtt-adafruit-connect/dot334-us915-helium-mqtt-adafruit-connect.ino)                |                    | <li> Check the Helium coverage map for your area [here](https://explorer.helium.com/)  <li> load libraries MKRWAN and cayenneLPP<li> Run the MKRWAN examples MKRWANUpdate_standalone to make sure the LoRaWan device is updated and active<li> Run the [dot333-helium-us915-cayenne-timer.ino](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot3-portenta-vision-shields/dot33-lorawan-specific/dot333-helium-us915-cayenne-timer/dot333-helium-us915-cayenne-timer.ino)  program with no information entered to get the Device EUI<li>Setup the Helium side: https://console.helium.com/ for what it does with the data. Add a new device and replace the given Device_EUI with the one above. Enter the other 2 values given from Helium into your sketch. The App_eui and the longer App_key. Run the program and open the Serial monitor<li> On Helium devices click the debug black icon and see if data is incoming<li> Login to [io.adafruit.com/](https://io.adafruit.com/) and collect your username and myKey to auto make a Helium-adafruit Integration. It will auto format it like the following ```mqtts://username:myKey@adafruit.io:8883``` Give your integration a number <li> In Helium flows connect the device--> function cayenneLPP --> adafruit<li> Check debug for data then Adafruit feeds for data.<li> Good luck. I use the https://io.adafruit.com/ MQTT with Cayenne encoding, but lots of other options out there.     |
| &#9744;  <a name="0" href="0">`0`</a>  Easy Pins test  |      |     |  Use the rak clip to access a few of the pins on the RAK2270 to see if you can program thme <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  Hard pins test   |      |     | Solder wires to the pads on the rak2270 and do some pin testing like you would for an Arduino  <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| &#9744;  <a name="0" href="0">`0`</a>  []()   |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |




<br><br><br>
## Final Course Projects (Student must complete an individual final project to pass my in-person course, your teacher might havwe different ideas)

| Topic | Example Code| Video | Instructions |
|:---|:---|:---|:---|
| <a name="0" href="0">`0`</a>  One sensor with one actuator final project  |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| <a name="0" href="0">`0`</a>  complex sensor, ML, actuator final project  |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |
| <a name="0" href="0">`0`</a>  group final project  |      |     |   <details closed> <summary>More Instructions</summary> ... </details> <details closed> <summary>ChatGPT Prompt</summary> ... </details>  |




<br><br><br>
## View the old [maker100](https://github.com/hpssjellis/maker100#latest-portenta-pinout) course for the Portenta Pinout Diagram
<br><br><br>

## XIAO esp32s3-sense  Pinout Diagram



 <img src="https://github.com/hpssjellis/maker100-eco/assets/5605614/c818e03f-562f-40df-8726-f0e5d5903596" width = "100%" /> 
<br><br><br>



## RAK2270 Sticker Tracker Pinout Diagram



 <img src="https://github.com/hpssjellis/maker100-eco/assets/5605614/a285279d-19f9-47ff-9b64-00c4b8f26087" width = "100%" /> 




 
#### Jeremy Ellis, ex: Rocksetta now <a href="https://ca.linkedin.com/in/jeremy-ellis-4237a9bb">LinkedIn</a>
#### High School Coding (35 Years), Robotics, Web Design, Animation and 3D Printing Teacher, BC Canada
#### Use this in-person course at your own risk!

