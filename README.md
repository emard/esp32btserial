# ESP32 Arduino to bluetooth GPS

ESP32 is bluetooth master (initiates connection)
and GPS is bluetooth device providing serial port.
Standard bluetooth serial is used (non-BLE).

If ESP32 is rebooted, ESP32 connects to bluetooth
serial but no serial traffic appears with "Garmin GLO"
GPS I have tested. The silent GPS also doesn't provide
traffic to PC when it connects. To restore traffic,
GPS must be turned OFF and ON. I don't know better
way to restore traffic automatically.
