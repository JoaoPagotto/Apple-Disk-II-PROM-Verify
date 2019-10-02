# Apple Disk II PROM Verify

For test Disk II Interface Card

``<b>341-0009</b>&nbsp;Apple&nbsp;Disk&nbsp;II&nbsp;13&nbsp;Sector&nbsp;Interface&nbsp;Card&nbsp;ROM&nbsp;P5&nbsp;(BOOT)``<br/>
``<b>341-0010</b>&nbsp;Apple&nbsp;Disk&nbsp;II&nbsp;13&nbsp;Sector&nbsp;Interface&nbsp;Card&nbsp;ROM&nbsp;P6&nbsp;(LOGIC)``<br/>
``<b>341-0027</b>&nbsp;Apple&nbsp;Disk&nbsp;II&nbsp;16&nbsp;Sector&nbsp;Interface&nbsp;Card&nbsp;ROM&nbsp;P5&nbsp;(BOOT)``<br/>
``<b>341-0028</b>&nbsp;Apple&nbsp;Disk&nbsp;II&nbsp;16&nbsp;Sector&nbsp;Interface&nbsp;Card&nbsp;ROM&nbsp;P6&nbsp;(LOGIC)``<br/>
``<b>341-0027-A</b>&nbsp;Apple&nbsp;Disk&nbsp;II&nbsp;16&nbsp;Sector&nbsp;Interface&nbsp;Card&nbsp;ROM&nbsp;P5A&nbsp;1981&nbsp;(BOOT)``<br/>
``<b>342-0028-A</b>&nbsp;Apple&nbsp;Disk&nbsp;II&nbsp;16&nbsp;Sector&nbsp;Interface&nbsp;Card&nbsp;ROM&nbsp;P6A&nbsp;1981&nbsp;(LOGIC)``<br/>

![Alt text](board.jpg)

## Hardware requeriment:
- Arduino IDE
- Arduino Mega 2560

## Compatibility with BIPOLAR PROMs:

N82S135
MMI 6309-1
MMI 63S281
TBP18S22
TBP28L22
MB 7118
AM27S23
74S471
74LS471
uPB421

## Schema:

``------+--------------``<br/>
``&nbsp;PROM&nbsp;|&nbsp;ARDUINO&nbsp;MEGA&nbsp;``<br/>
``------+--------------``<br/>
``&nbsp;&nbsp;VCC&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;+5V&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a0&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;22&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a1&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;24&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a2&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;26&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a3&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;28&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a4&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;30&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a5&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;27&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a6&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;25&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;a7&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;23&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;g1&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;31&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;g2&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;29&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q0&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;32&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q1&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;34&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q2&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;36&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q3&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;38&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q4&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;39&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q5&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;37&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q6&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;35&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;q7&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;33&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``&nbsp;&nbsp;GND&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;GND&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;``<br/>
``------+--------------``<br/>

## Board to connect PROM:

![Alt text](board_01.jpg)

![Alt text](board_02.jpg)

## Program check: 

### Valid PROM:
![Alt text](valid.png)

### Invalid PROM:
![Alt text](invalid.png)

This is free open-source software, distributed under a very liberal license 
(the well-known MIT license). It may be used for any purpose, including 
commercial purposes, at absolutely no cost. Just download it and use it.
