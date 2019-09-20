# Apple-Disk-II-PROM-Verify

## Program to verify Apple Disk II PROM content   v1.00

Date: 2019-09-16
João Ricardo Pagotto

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

``------+--------------``
`` PROM | ARDUINO MEGA ``
``------+--------------``
``  VCC |    +5V       ``
``  a0  |     22       ``
``  a1  |     24       ``
``  a2  |     26       ``
``  a3  |     28       ``
``  a4  |     30       ``
``  a5  |     27       ``
``  a6  |     25       ``
``  a7  |     23 	   ``
``  g1  |     31       ``
``  g2  |     29 	   `` 
``  q0  |     32       ``
``  q1  |     34       ``
``  q2  |     36       ``
``  q3  |     38       ``
``  q4  |     39       ``
``  q5  |     37       ``
``  q6  |     35       ``
``  q7  |     33       ``
``  GND |    GND       ``
``------+--------------``

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
