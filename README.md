<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="artwork/smartimu.png" alt="Project logo"></a>
</p>

<h3 align="center">Smart IMU</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()


</div>

---


<p align="center"> Smart IMU
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Circuit](#circuit)
- [Usage](#usage)
- [Built Using](#built_using)
- [Authors](#authors)


## 🧐 About <a name = "about"></a>

This repo contains

- Firmware
- Circuit Diagram
- Detailed instructions

for Smart IMU.



## Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your system.


### Prerequisites

Things you need to install the FW.

```
- Arduino IDE
```

### Installing <a name = "installing"></a>

A step by step series that tell you how to get the Firmware and Backend running

#### ESP32 Configuration

You should have Arduino IDE Installed

  1.  Add ESP32 Board to your Arduino IDE
    1. In your Arduino IDE, go to File> Preferences
        Installing ESP32 Add-on in Arduino IDE Windows, Mac OS X, Linux open preferences
    2. Enter ```https://dl.espressif.com/dl/package_esp32_index.json``` 
        into the “Additional Board Manager URLs” field then, click the “OK” button:
        Note: if you already have the ESP32 boards URL, you can separate the URLs with a comma(each board will go to neaw line) as follows:
        ```https://dl.espressif.com/dl/package_esp32_index.json,\n http://arduino.esp8266.com/stable/package_esp8266com_index.json```
    
    
  2. Open the Boards Manager. Go to Tools > Board > Boards Manager…
  3. Search for ESP32 and press install button for the ESP32 by Espressif Systems“:
  4. That’s it. It should be installed after a few seconds.
  5.   In your Arduino sketchbook directory, create tools directory if it doesn't exist yet.
  6.  Unpack the tool into tools directory(present in libs/ESP32FS-1.0.zip) (the path will look like <home_dir>/Arduino/tools/ESP32FS/tool/esp32fs.jar).
  7.  Close and re-open the Arduino IDE.

  8.  Now copy the contents of the libs folder to the libraries directory of your Arduino
      1. If you are using windows, the libraries directory will be Documents/Arduino/libraries

##### ESP32 Node FW Uploading
  1.  Select ESP32 Dev Module from Tools->Board->ESP32
  2.  Select the correct port from Tools->Port
  3.  Then open Firmware.ino file,
  4.  Select Tools > ESP32 Sketch Data Upload menu item. This should start uploading the files into ESP32 flash file system.
  5.  Now Upload the Code to your ESP32 Dev Module.
  6.  Your ESP32 is now ready to be used.



## Circuit <a name = "circuit"></a>


### ESP32 Dev Module Pinout


Follow the pinout diagram given below to connect different components to your TTGO LORA32 board.

![LoraPinout](Circuit/ESP32-Pinout.jpg)

### Other Components

```http
Other components pin connection details
```


#### IMU MPU6050

```MPU6050 Connections```

| MPU6050 Pins | ESP32 Dev Module Pins| 
| :--- | :--- | 
| `SCL` | `D22` |
| `SDA` | `D21` |
| `VCC` | `3.3V` |
| `GND` | `GND` | 


### Complete Circuit Diagram

Here's the complete circuit diagram of the system.

![CircuitDiagram](Circuit/Circuit_bb.png)

## Usage <a name = "usage"></a>

1.  Power on your ESP32, it will present you with an AP named ```OEE``` (while ```OEE``` can be changed in the portal)
2.  Default captive portal password `12345678AP` which can be changed in captive portal.
3.  Connect to the ESP32 access point and open the web-browser and navigate to the link ```http://esp32.local/_ac```. This link will work on most of the operating systems but if your operating system is not allowing to open it, you may want to check the captive portal IP Address from the serial monitor and can use that IP address inplace of the above mentioned URL.
4.  The default access IP Address is ```http://192.168.4.1/_ac```
5.  You will be presented with a main dashboard as shown below(based on your device)
   ![SCR1](artwork/scr1.png)

5.  Once connected to a WiFi network, you can again access the captive portal using same URL or the IP Address from the Serial monitor.
6.  The data is published to the MQTT Topic ```OEE/{hostname}``` while the hostname is the one which you can define in Settings page of the captive portal.


### Changing Timezone

1.  Open Settings tab
2.  Enter timezone string from https://en.wikipedia.org/wiki/List_of_tz_database_time_zones 'TZ database name' column.
3.  Click Save&Start

### API Endpoints and HTML URLS
```API Endpoints```

| Endpoint | Description | 
| :--- | :--- | 
| `/api-now` | `API: live sensor readings in JSON format` |
| `/LiveSensors` | `HTML PAGE: Live Sensor Data` |
| `/data` | `HTML PAGE: Historical Sensor Data` | 
| `/mqtt_settings` | `HTML PAGE: Settings. Default username: AP Name, Default Password: admin` | 
| `/_ac` | `HTML PAGE: Main Captive portal page` | 
| `/` | `HTML PAGE: Historical Sensor Data` | 


1.  **Connect to WiFi** tab allows searching of nearby WiFi APs and adding them to the ESP32.
   ![SCR3](artwork/scr3.png)
2.  **Saved WiFi Networks** tab allows connecting to the saved access points.
   ![SCR4](artwork/scr4.png)
3.  **Reset...** tab allows reseting of the device to factory settings.
    ![SCR5](artwork/scr5.png)
4.  **Settings** tab contains settings related to MQTT and sensors.
    ![SCR6](artwork/scr6.png)
5. **api-now** tab gives the live-sensor data in JSON format.
    ![SCR7](artwork/scr7.png)
6. **LiveSensors** tab shows live values of the sensors.
    ![SCR8](artwork/scr8.png)

### MQTT Details

From Device the data should be published to the topic `ACC/#` in the format below:
* Replace `#` with the device MAC Address.

```json
timestamp; AccX, AccY, AccZ, GyroX, GyroY, GyroZ
```

## List of Components <a name = "list"></a>

Following components are used to make this project

1.  [ESP32 Dev Kit Module](https://www.amazon.com/Development-Microcontroller-Integrated-Antenna-Amplifiers/dp/B09GK74F7N/ref=sr_1_2_sspa?crid=1YV8TC1236O37&keywords=esp32&qid=1695308378&sprefix=esp32%2Caps%2C172&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

2.  [Vibration Sensor (IMU) (MPU6050)](https://www.amazon.com/WWZMDiB-Accelerometer-Gyroscope-Converter-Raspberry/dp/B0B793846N/ref=sr_1_7?crid=3LE8YT4PKK866&keywords=mpu9250+soldered&qid=1695308492&sprefix=mpu9250+soldered%2Caps%2C166&sr=8-7)


3. [Micro USB Cable](https://www.amazon.com/AmazonBasics-Double-Braided-Nylon-Charger/dp/B074VM7SMM/ref=sr_1_7_ffob_sspa?crid=1NZP9TAZ3C5AT&keywords=usb+micro+b+cable&qid=1695308556&sprefix=usb+micro+b+cabl%2Caps%2C171&sr=8-7-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&psc=1)

4. Breadboard and Jumper Wires and Power Supply Module

## ⛏️ Built Using <a name = "built_using"></a>

- [Arduino](https://www.arduino.cc/) - Embedded Framework and IDE - For Sensor Node Design

## ✍️ Authors <a name = "authors"></a>

- [@Nauman3S](https://github.com/Nauman3S) - Development and Deployment
