# purple-haze

A Iot project that monitor loudness of the environment and then try to virtualize it using P5

Current state: The backend of this project has been roughly completed, include a very basic data uploading system which upload the sensor data to the cloud server every 3 seconds.

The server data can be retrieve using this following REST address(standard GET method will do) https://api.mlab.com/api/1/databases/p-fire/collections/purplegarage?apiKey=ge3hUcuINpHsOkUhoayG7tL2vTpkrETR



TODO:

Server side: 
1.Don't publish any data if the loudness is less than 1 (which mean quite) -----DONE
2.Instead of using the sound info in that moment, try to get the maximum value during that period to achieve a better result with more information resolution.

Front-end:
Create a proper JSON parsing method that can queue by day(or a specific period of time)
Create a tiny hook that can connect to P5JS
