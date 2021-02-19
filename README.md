# ESP32 Arduino to bluetooth GPS

ESP32 is bluetooth master (initiates connection)
and GPS is bluetooth device providing serial port.
Standard bluetooth serial is used (non-BLE).

For Garmin GLO usb-serial, firmware 2.60 should
be upgraded to 3.00.

For Garmin GLO firmware 2.60: If ESP32 is rebooted,
ESP32 connects to bluetooth serial but no serial traffic
appears with "Garmin GLO" GPS I have tested with firmware 2.60. 

The silent GPS also doesn't provide traffic to PC when it connects.
To restore traffic, GPS must be turned OFF and ON.
Firmware upgrade to 3.00 fixes it.
