# Apple Disk II PROM Verify

For test Disk II Interface Card

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
`` PROM | ARDUINO MEGA ``<br/>
``------+--------------``<br/>
``  VCC |    +5V       ``<br/>
``  a0  |     22       ``<br/>
``  a1  |     24       ``<br/>
``  a2  |     26       ``<br/>
``  a3  |     28       ``<br/>
``  a4  |     30       ``<br/>
``  a5  |     27       ``<br/>
``  a6  |     25       ``<br/>
``  a7  |     23 	     ``<br/>
``  g1  |     31       ``<br/>
``  g2  |     29 	     ``<br/>
``  q0  |     32       ``<br/>
``  q1  |     34       ``<br/>
``  q2  |     36       ``<br/>
``  q3  |     38       ``<br/>
``  q4  |     39       ``<br/>
``  q5  |     37       ``<br/>
``  q6  |     35       ``<br/>
``  q7  |     33       ``<br/>
``  GND |    GND       ``<br/>
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
