# Smart Farming System using Arduino
![Smart Farming System](https://github.com/smhamidi/AUT_Instrumentation_SmartFarming_Arduino/blob/main/pictures/Lights_OFF.jpg)
## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Code Explanation](#code-explanation)
- [License](#license)

## Introduction

The Smart Farming System is a project that uses Arduino to automate and monitor various aspects of farming. This system is designed to increase the efficiency and effectiveness of farming by automating tasks and collecting data that can be used to improve farming practices.

## Features

- **Temperature and Humidity Monitoring**: The system uses a DHT sensor to monitor the temperature and humidity levels in the farm environment.
- **Distance Sensing**: Ultrasonic sensors are used to detect the presence of objects or obstacles in the farm.
- **Light Intensity Detection**: Light detectors are used to monitor the light intensity in the farm environment.
- **Alert System**: A buzzer is used to alert the user when certain conditions are met, such as when an object is detected by the ultrasonic sensors.
- **Fan Control**: A fan is controlled based on the temperature readings from the DHT sensor.
- **LED Indication**: An LED is used to indicate when the light intensity exceeds a certain threshold.

## Hardware Requirements

- Arduino board
- DHT sensor
- Ultrasonic sensors
- Light detectors
- Buzzer
- Fan
- LED
![Smart Farming System](https://github.com/smhamidi/AUT_Instrumentation_SmartFarming_Arduino/blob/main/pictures/Lights_ON.jpg)
## Software Requirements

- Arduino IDE

## Installation

1. Clone this repository to your local machine.
2. Open the Arduino IDE.
3. Load the `.ino` file from the cloned repository.
4. Connect your Arduino board to your computer.
5. Upload the code to your Arduino board.

## Code Explanation

The code for this project is written in the Arduino programming language. It includes several functions to read data from the various sensors and control the fan, buzzer, and LED based on the sensor readings.

The `setup()` function initializes the pin modes for the sensors and output devices and starts the serial communication.

The `loop()` function continuously reads data from the sensors and controls the output devices based on the sensor readings. It also prints the sensor data to the serial monitor.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
