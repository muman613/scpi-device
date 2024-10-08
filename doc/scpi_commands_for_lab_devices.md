
# SCPI Commands for Lab Devices

## 1. Digital Multimeter (DVM) - OWON XDM1041

| Command                   | Description                                        |
|---------------------------|----------------------------------------------------|
| `*IDN?`                   | Query the identification of the device             |
| `MEASure:VOLTage:DC?`     | Measure DC voltage                                 |
| `MEASure:VOLTage:AC?`     | Measure AC voltage                                 |
| `MEASure:CURRent:DC?`     | Measure DC current                                 |
| `MEASure:CURRent:AC?`     | Measure AC current                                 |
| `MEASure:RESistance?`     | Measure resistance                                 |
| `MEASure:FRESistance?`    | Measure four-wire resistance (if supported)        |
| `MEASure:FREQuency?`      | Measure frequency                                  |
| `MEASure:CAPacitance?`    | Measure capacitance                                |
| `CONFigure:VOLTage:DC`    | Configure the device to measure DC voltage         |
| `CONFigure:CURRent:DC`    | Configure the device to measure DC current         |
| `SYSTem:ERRor?`           | Query system error                                 |
| `DISPlay:TEXT "<msg>"`    | Display a message on the multimeter screen         |

## 2. Programmable Power Supply (e.g., 0-30V, 0-10A Model)

| Command                   | Description                                        |
|---------------------------|----------------------------------------------------|
| `*IDN?`                   | Query the identification of the device             |
| `VOLTage <value>`         | Set output voltage (e.g., `VOLTage 12.5`)          |
| `VOLTage?`                | Query the output voltage                           |
| `CURRent <value>`         | Set output current (e.g., `CURRent 2.0`)           |
| `CURRent?`                | Query the output current                           |
| `OUTPut ON`               | Enable the output                                  |
| `OUTPut OFF`              | Disable the output                                 |
| `OUTPut?`                 | Query output state (on or off)                     |
| `MEASure:VOLTage?`        | Measure the output voltage                         |
| `MEASure:CURRent?`        | Measure the output current                         |
| `SYSTem:ERRor?`           | Query system error                                 |

## 3. Digital Oscilloscope - Hantek DSO2D15

| Command                            | Description                                                         |
|------------------------------------|---------------------------------------------------------------------|
| `*IDN?`                            | Query the identification of the device                              |
| `ACQuire:TYPE NORMal`              | Set acquisition type to normal                                      |
| `MEASure:VOLTage:DC?`              | Measure DC voltage level                                            |
| `MEASure:VOLTage:AC?`              | Measure AC voltage level                                            |
| `MEASure:FREQuency?`               | Measure signal frequency                                            |
| `MEASure:PERiod?`                  | Measure signal period                                               |
| `TIMebase:SCALe <value>`           | Set the time base scale (e.g., `TIMebase:SCALe 0.001`)              |
| `CHANnel1:SCALe <value>`           | Set vertical scale for channel 1                                    |
| `CHANnel1:OFFSet <value>`          | Set vertical offset for channel 1                                   |
| `CHANnel1:DISPlay ON`              | Turn on channel 1 display                                           |
| `CHANnel1:DISPlay OFF`             | Turn off channel 1 display                                          |
| `TRIGger:EDGE:SOURce CHANnel1`     | Set trigger source to channel 1                                     |
| `TRIGger:EDGE:LEVel <value>`       | Set trigger level (e.g., `TRIGger:EDGE:LEVel 1.0`)                  |
| `RUN`                              | Start acquiring data                                                |
| `STOP`                             | Stop acquiring data                                                 |
| `WAVeform:DATA?`                   | Retrieve waveform data (usually in binary or ASCII format)          |
| `DISPlay:CLEar`                    | Clear the display                                                   |
| `SYSTem:ERRor?`                    | Query system error                                                  |
