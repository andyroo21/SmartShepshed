# SmartShepshed
Project - Smart ShepshedJanuary 20, 2018
OVERVIEW
1.	Project Scope

The main aim of this project is to provide real time weather data for the area of Shepshed.  The data will be obtained by an Arduino based node network and displayed via a website and historical data stored for future analysis.

The idea came from various projects of a similar nature that are happening in larger cities.  The reason for this project is to gather metrological data of our microclimate and what effects it has on the town.  
The data collected will be used by the population of Shepshed, institutions and businesses. The project will be solely funded by Andrew Grimley initially, but there may be need for outside funding for further development of the network. 
Further development would include design and manufacturing of bespoke PCB/controllers specifically for Smart Shepshed, the research and implementation of more precise sensors and more sensor nodes installed.

The project is due to start January 2018.

The project will be advertised by social media and local media/news outlets.

2.	Requirements

The requirements for this project are as follows
  
  •	Gateway to control all nodes and obtain data from them.  The Gateway is the main part of the network, it will communicate with the installed sensor nodes by using the 868 radio frequency.  It controls the nodes by issuing commands via software and asking them to take sensor readings and send the data back to the gateway. 

•	Phase one of the project will see 10 sensor nodes installed at various sites around Shepshed.  Each individual node is addressed and “listen out “ for their command which is sent from the Gateway.  Once the command has been received the Sensor node takes readings form all its connected sensors and relays that information back to the gateway.  Measurements will happen every 90 seconds.

•	Sensors for nodes will include Temperature, Relative Humidity, Barometric pressure and rain detection

•	Webserver to serve the Smart Shepshed website to the outside world

•	A MYSQL database to store data from all the sensor nodes and in turn serve that data to the hosted Smart Shepshed website via PHP and JavaScript.

•	Data visualisation on the Smart Shepshed website in the form of graphs and dials.  Giving the real time and historical data   

•	Software for gateway.  The software will communicate with each individual node in turn and collect each nodes sensor data. In turn it will then send all data to the server MYSQL database. 

•	Software for sensor nodes. The software for each node “listens out” out for their command from the main gateway,  once the command has been received the sensor node then takes measurements of its connected sensors.  Once this has been completed the data is then sent back to the main gate way for storage.

•	Software for populating database. The gateway is physically connected to the server via a USB port.  The database insertion software waits for data being sent to the serial port from the gateway when this has been received the database is opened and variables are inserted into their relevant fields 

•	Website design and launch
Gateway and sensor nodes programmed through Arduino IDE. The arduino IDE is a platform that is commly used by hobbyists to program development boards. 

•Software for data base insertion Python programme.Python has been choosen mainly for it's ease of implementation and strength 

•Website is coded using Bootstrap4, CSS, and JavaScript. 

•Web/file server is running on Ubuntu 16.04.
3. Components

Gateway.

•	Arduino Uno clone 

•	Dragino V2 Lora RFM95 radio HAT

•	-14dB 868mhz antenna

•	Enclosure 

•	Mounting bracket 
	

Sensor Nodes

•	Lora 32u4 RFM95 Lora dev board (3.3v)- Manufactured by BSFrance

•	868 Antenna

•	3.7V battery pack(3000mAh)

•	5v Solar panel

•	Sht75 air temperature and relative humidity sensor

•	BMP280 Barometric pressure sensor

•	Wetness sensing grid, piezo transducer for rain detection. 

Website, data storage

•	Reclaimed pc 

•	Ubuntu 16.04

•	Lamp Server

•	MySQL data base 

•	Python Software
 
