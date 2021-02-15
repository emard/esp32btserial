# ESP32 Arduino to bluetooth GPS

ESP32 is bluetooth master (initiates connection)
and GPS is bluetooth device providing serial port.
Standard bluetooth serial is used (non-BLE).

If ESP32 is rebooted, subsequent connections succeeds
but no serial traffic appears with "Garmin GLO" GPS I
have tested. To restore traffic, GPS has be manually
turned OFF and ON. I don't know how to handle that
automatically.
