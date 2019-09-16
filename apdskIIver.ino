//-----------------------------------------------------------------------------
//  
//  Program to verify Apple Disk II PROM content   v1.00
//  
//  Date: 2019-09-16
//  
//  João Ricardo Pagotto
//  https://github.com/joaopagotto
//  
//  This is free open-source software, distributed under a very liberal license 
//  (the well-known MIT license). It may be used for any purpose, including 
//  commercial purposes, at absolutely no cost. Just download it and use it.
//
//-----------------------------------------------------------------------------

int a0 = 22;
int a1 = 24;
int a2 = 26;
int a3 = 28;
int a4 = 30;
int a5 = 27; 
int a6 = 25; 
int a7 = 23; 

int g1 = 31; 
int g2 = 29; 

int q0 = 32;
int q1 = 34;
int q2 = 36;
int q3 = 38;
int q4 = 39; 
int q5 = 37; 
int q6 = 35; 
int q7 = 33; 

char buffer[128];
unsigned char data_read[256];

unsigned char column;
unsigned short address;
unsigned char enable;
unsigned char value;
unsigned char valid;

//-----------------------------------------------------------------------------
// Empty Set

char str_rom_empty[] = "Empty Set.bin\0";

unsigned char rom_empty[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//-----------------------------------------------------------------------------
// Apple Disk II 13 Sector Interface Card ROM P5 - 341-0009.bin

char str_romP5_341_0009[] = "Apple Disk II 13 Sector Interface Card ROM P5 - 341-0009.bin\0";

unsigned char romP5_341_0009[] = {
  0xa2, 0x20, 0xa0, 0x00, 0xa9, 0x03, 0x85, 0x3c, 0x18, 0x88, 0x98, 0x24, 0x3c, 0xf0, 0xf5, 0x26,
  0x3c, 0x90, 0xf8, 0xc0, 0xd5, 0xf0, 0xed, 0xca, 0x8a, 0x99, 0x00, 0x08, 0xd0, 0xe6, 0x20, 0x58,
  0xff, 0xba, 0xbd, 0x00, 0x01, 0x48, 0x0a, 0x0a, 0x0a, 0x0a, 0x85, 0x2b, 0xaa, 0xa9, 0xd0, 0x48,
  0xbd, 0x8e, 0xc0, 0xbd, 0x8c, 0xc0, 0xbd, 0x8a, 0xc0, 0xbd, 0x89, 0xc0, 0xa0, 0x50, 0xbd, 0x80,
  0xc0, 0x98, 0x29, 0x03, 0x0a, 0x05, 0x2b, 0xaa, 0xbd, 0x81, 0xc0, 0xa9, 0x56, 0x20, 0xa8, 0xfc,
  0x88, 0x10, 0xeb, 0xa9, 0x03, 0x85, 0x27, 0xa9, 0x00, 0x85, 0x26, 0x85, 0x3d, 0x18, 0x08, 0xbd,
  0x8c, 0xc0, 0x10, 0xfb, 0x49, 0xd5, 0xd0, 0xf7, 0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0xc9, 0xaa, 0xd0,
  0xf3, 0xea, 0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0xc9, 0xb5, 0xf0, 0x09, 0x28, 0x90, 0xdf, 0x49, 0xad,
  0xf0, 0x1f, 0xd0, 0xd9, 0xa0, 0x03, 0x84, 0x2a, 0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0x2a, 0x85, 0x3c,
  0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0x25, 0x3c, 0x88, 0xd0, 0xee, 0x28, 0xc5, 0x3d, 0xd0, 0xbe, 0xb0,
  0xbd, 0xa0, 0x9a, 0x84, 0x3c, 0xbc, 0x8c, 0xc0, 0x10, 0xfb, 0x59, 0x00, 0x08, 0xa4, 0x3c, 0x88,
  0x99, 0x00, 0x08, 0xd0, 0xee, 0x84, 0x3c, 0xbc, 0x8c, 0xc0, 0x10, 0xfb, 0x59, 0x00, 0x08, 0xa4,
  0x3c, 0x91, 0x26, 0xc8, 0xd0, 0xef, 0xbc, 0x8c, 0xc0, 0x10, 0xfb, 0x59, 0x00, 0x08, 0xd0, 0x8d,
  0x60, 0xa8, 0xa2, 0x00, 0xb9, 0x00, 0x08, 0x4a, 0x3e, 0xcc, 0x03, 0x4a, 0x3e, 0x99, 0x03, 0x85,
  0x3c, 0xb1, 0x26, 0x0a, 0x0a, 0x0a, 0x05, 0x3c, 0x91, 0x26, 0xc8, 0xe8, 0xe0, 0x33, 0xd0, 0xe4,
  0xc6, 0x2a, 0xd0, 0xde, 0xcc, 0x00, 0x03, 0xd0, 0x03, 0x4c, 0x01, 0x03, 0x4c, 0x2d, 0xff, 0xff
};

//-----------------------------------------------------------------------------
// Apple Disk II 13 Sector Interface Card ROM P6 - 341-0010.bin

char str_romP6_341_0010[] = "Apple Disk II 13 Sector Interface Card ROM P6 - 341-0010.bin\0";

unsigned char romP6_341_0010[] = {
  0xb8, 0xb8, 0x88, 0xc8, 0x0a, 0x0a, 0x0a, 0x0a, 0x88, 0xc9, 0x88, 0xc9, 0x88, 0xcb, 0x88, 0xcb,
  0x88, 0xc8, 0x08, 0xc8, 0x0a, 0x0a, 0x0a, 0x0a, 0x88, 0xc9, 0x88, 0xc9, 0x88, 0xcb, 0x88, 0xcb,
  0xb8, 0x3d, 0xb8, 0xb8, 0x0a, 0x0a, 0x0a, 0x0a, 0x98, 0xd9, 0x98, 0xd9, 0x98, 0xdb, 0x98, 0xdb,
  0x98, 0xdd, 0x98, 0xd8, 0x0a, 0x0a, 0x0a, 0x0a, 0x98, 0xd9, 0x98, 0xd9, 0x98, 0xdb, 0x98, 0xdb,
  0xb8, 0xb8, 0xb8, 0xb8, 0x0a, 0x0a, 0x0a, 0x0a, 0xa8, 0xe8, 0xa8, 0xe8, 0xa8, 0xe8, 0xa8, 0xe8,
  0xa8, 0xe8, 0xa8, 0xe8, 0x0a, 0x0a, 0x0a, 0x0a, 0xa8, 0xe8, 0xa8, 0xe8, 0xa8, 0xe8, 0xa8, 0xe8,
  0xb9, 0xfd, 0xb8, 0xf8, 0x0a, 0x0a, 0x0a, 0x0a, 0xb8, 0xf8, 0xb8, 0xf8, 0xb8, 0xf8, 0xb8, 0xf8,
  0xb9, 0xfd, 0x50, 0xf8, 0x0a, 0x0a, 0x0a, 0x0a, 0xb8, 0xf8, 0xb8, 0xf8, 0xb8, 0xf8, 0xb8, 0xf8,
  0xb8, 0xb8, 0x48, 0xb8, 0x0a, 0x0a, 0x0a, 0x0a, 0x48, 0x28, 0x48, 0x28, 0x48, 0x28, 0x48, 0x28,
  0x48, 0x28, 0x48, 0x28, 0x0a, 0x0a, 0x0a, 0x0a, 0x48, 0x28, 0x48, 0x28, 0x48, 0x28, 0x48, 0x28,
  0xb8, 0xb9, 0xb8, 0xb8, 0x0a, 0x0a, 0x0a, 0x0a, 0x58, 0x38, 0x58, 0x38, 0x58, 0x38, 0x58, 0x38,
  0x09, 0xc9, 0x58, 0x38, 0x0a, 0x0a, 0x0a, 0x0a, 0x58, 0x38, 0x58, 0x38, 0x58, 0x38, 0x58, 0x38,
  0xb8, 0xb8, 0xb8, 0xb8, 0x0a, 0x0a, 0x0a, 0x0a, 0x68, 0x08, 0x68, 0x18, 0x68, 0x08, 0x68, 0x18,
  0x68, 0x18, 0x68, 0x18, 0x0a, 0x0a, 0x0a, 0x0a, 0x68, 0x08, 0x68, 0x18, 0x68, 0x08, 0x68, 0x18,
  0x8d, 0xbd, 0x78, 0x70, 0x0a, 0x0a, 0x0a, 0x0a, 0x78, 0x18, 0x78, 0x08, 0x78, 0x18, 0x78, 0x08,
  0x0d, 0x2d, 0x78, 0x70, 0x0a, 0x0a, 0x0a, 0x0a, 0x78, 0x18, 0x78, 0x08, 0x78, 0x18, 0x78, 0x08
};

//-----------------------------------------------------------------------------
// Apple Disk II 16 Sector Interface Card ROM P5 - 341-0027.bin

char str_romP5_341_0027[] = "Apple Disk II 16 Sector Interface Card ROM P5 - 341-0027.bin\0";

unsigned char romP5_341_0027[] = {
  0xa2, 0x20, 0xa0, 0x00, 0xa2, 0x03, 0x86, 0x3c, 0x8a, 0x0a, 0x24, 0x3c, 0xf0, 0x10, 0x05, 0x3c,
  0x49, 0xff, 0x29, 0x7e, 0xb0, 0x08, 0x4a, 0xd0, 0xfb, 0x98, 0x9d, 0x56, 0x03, 0xc8, 0xe8, 0x10,
  0xe5, 0x20, 0x58, 0xff, 0xba, 0xbd, 0x00, 0x01, 0x0a, 0x0a, 0x0a, 0x0a, 0x85, 0x2b, 0xaa, 0xbd,
  0x8e, 0xc0, 0xbd, 0x8c, 0xc0, 0xbd, 0x8a, 0xc0, 0xbd, 0x89, 0xc0, 0xa0, 0x50, 0xbd, 0x80, 0xc0,
  0x98, 0x29, 0x03, 0x0a, 0x05, 0x2b, 0xaa, 0xbd, 0x81, 0xc0, 0xa9, 0x56, 0x20, 0xa8, 0xfc, 0x88,
  0x10, 0xeb, 0x85, 0x26, 0x85, 0x3d, 0x85, 0x41, 0xa9, 0x08, 0x85, 0x27, 0x18, 0x08, 0xbd, 0x8c,
  0xc0, 0x10, 0xfb, 0x49, 0xd5, 0xd0, 0xf7, 0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0xc9, 0xaa, 0xd0, 0xf3,
  0xea, 0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0xc9, 0x96, 0xf0, 0x09, 0x28, 0x90, 0xdf, 0x49, 0xad, 0xf0,
  0x25, 0xd0, 0xd9, 0xa0, 0x03, 0x85, 0x40, 0xbd, 0x8c, 0xc0, 0x10, 0xfb, 0x2a, 0x85, 0x3c, 0xbd,
  0x8c, 0xc0, 0x10, 0xfb, 0x25, 0x3c, 0x88, 0xd0, 0xec, 0x28, 0xc5, 0x3d, 0xd0, 0xbe, 0xa5, 0x40,
  0xc5, 0x41, 0xd0, 0xb8, 0xb0, 0xb7, 0xa0, 0x56, 0x84, 0x3c, 0xbc, 0x8c, 0xc0, 0x10, 0xfb, 0x59,
  0xd6, 0x02, 0xa4, 0x3c, 0x88, 0x99, 0x00, 0x03, 0xd0, 0xee, 0x84, 0x3c, 0xbc, 0x8c, 0xc0, 0x10,
  0xfb, 0x59, 0xd6, 0x02, 0xa4, 0x3c, 0x91, 0x26, 0xc8, 0xd0, 0xef, 0xbc, 0x8c, 0xc0, 0x10, 0xfb,
  0x59, 0xd6, 0x02, 0xd0, 0x87, 0xa0, 0x00, 0xa2, 0x56, 0xca, 0x30, 0xfb, 0xb1, 0x26, 0x5e, 0x00,
  0x03, 0x2a, 0x5e, 0x00, 0x03, 0x2a, 0x91, 0x26, 0xc8, 0xd0, 0xee, 0xe6, 0x27, 0xe6, 0x3d, 0xa5,
  0x3d, 0xcd, 0x00, 0x08, 0xa6, 0x2b, 0x90, 0xdb, 0x4c, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00
};

//-----------------------------------------------------------------------------
// Apple Disk II 16 Sector Interface Card ROM P6 - 341-0028.bin

char str_romP6_341_0028[] = "Apple Disk II 16 Sector Interface Card ROM P6 - 341-0028.bin\0";

unsigned char romP6_341_0028[] = {
  0x18, 0xd8, 0x18, 0x08, 0x0a, 0x0a, 0x0a, 0x0a, 0x18, 0x39, 0x18, 0x39, 0x18, 0x3b, 0x18, 0x3b,
  0x18, 0x38, 0x18, 0x28, 0x0a, 0x0a, 0x0a, 0x0a, 0x18, 0x39, 0x18, 0x39, 0x18, 0x3b, 0x18, 0x3b,
  0x2d, 0xd8, 0x38, 0x48, 0x0a, 0x0a, 0x0a, 0x0a, 0x28, 0x48, 0x28, 0x48, 0x28, 0x48, 0x28, 0x48,
  0x2d, 0x48, 0x38, 0x48, 0x0a, 0x0a, 0x0a, 0x0a, 0x28, 0x48, 0x28, 0x48, 0x28, 0x48, 0x28, 0x48,
  0xd8, 0xd8, 0xd8, 0xd8, 0x0a, 0x0a, 0x0a, 0x0a, 0x58, 0x78, 0x58, 0x78, 0x58, 0x78, 0x58, 0x78,
  0x58, 0x78, 0x58, 0x78, 0x0a, 0x0a, 0x0a, 0x0a, 0x58, 0x78, 0x58, 0x78, 0x58, 0x78, 0x58, 0x78,
  0xd8, 0xd8, 0xd8, 0xd8, 0x0a, 0x0a, 0x0a, 0x0a, 0x68, 0x08, 0x68, 0x88, 0x68, 0x08, 0x68, 0x88,
  0x68, 0x88, 0x68, 0x88, 0x0a, 0x0a, 0x0a, 0x0a, 0x68, 0x08, 0x68, 0x88, 0x68, 0x08, 0x68, 0x88,
  0xd8, 0xcd, 0xd8, 0xd8, 0x0a, 0x0a, 0x0a, 0x0a, 0x98, 0xb9, 0x98, 0xb9, 0x98, 0xbb, 0x98, 0xbb,
  0x98, 0xbd, 0x98, 0xb8, 0x0a, 0x0a, 0x0a, 0x0a, 0x98, 0xb9, 0x98, 0xb9, 0x98, 0xbb, 0x98, 0xbb,
  0xd8, 0xd9, 0xd8, 0xd8, 0x0a, 0x0a, 0x0a, 0x0a, 0xa8, 0xc8, 0xa8, 0xc8, 0xa8, 0xc8, 0xa8, 0xc8,
  0x29, 0x59, 0xa8, 0xc8, 0x0a, 0x0a, 0x0a, 0x0a, 0xa8, 0xc8, 0xa8, 0xc8, 0xa8, 0xc8, 0xa8, 0xc8,
  0xd9, 0xfd, 0xd8, 0xf8, 0x0a, 0x0a, 0x0a, 0x0a, 0xd8, 0xf8, 0xd8, 0xf8, 0xd8, 0xf8, 0xd8, 0xf8,
  0xd9, 0xfd, 0xa0, 0xf8, 0x0a, 0x0a, 0x0a, 0x0a, 0xd8, 0xf8, 0xd8, 0xf8, 0xd8, 0xf8, 0xd8, 0xf8,
  0xd8, 0xdd, 0xe8, 0xe0, 0x0a, 0x0a, 0x0a, 0x0a, 0xe8, 0x88, 0xe8, 0x08, 0xe8, 0x88, 0xe8, 0x08,
  0x08, 0x4d, 0xe8, 0xe0, 0x0a, 0x0a, 0x0a, 0x0a, 0xe8, 0x88, 0xe8, 0x08, 0xe8, 0x88, 0xe8, 0x08
};

//-----------------------------------------------------------------------------

unsigned char checkProm(unsigned char *prom_read, unsigned char *prom_content)
{
  address = 0x00;
  while ( address <= 0xff )
  {
    if ( prom_read[address] != prom_content[address] )
    {
      return false;      
    }
    address++;
  }
  return true;  
}

//-----------------------------------------------------------------------------

void setup() 
{
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(a5, OUTPUT);
  pinMode(a6, OUTPUT);
  pinMode(a7, OUTPUT);

  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  
  pinMode(q0, INPUT);
  pinMode(q1, INPUT);
  pinMode(q2, INPUT);
  pinMode(q3, INPUT);
  pinMode(q4, INPUT);
  pinMode(q5, INPUT);
  pinMode(q6, INPUT);
  pinMode(q7, INPUT);

  Serial.begin(9600, SERIAL_8N1);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

//-----------------------------------------------------------------------------

void loop() 
{

  Serial.write("Apple Disk II PROM Reader v1.00\r\n\n");

  enable = 0xff;

  address = 0x00;
  while ( address <= 0xff )
  {
    //---------------------
    // Define Address
      
    digitalWrite(a0, bitRead(address, 0));
    digitalWrite(a1, bitRead(address, 1));
    digitalWrite(a2, bitRead(address, 2));
    digitalWrite(a3, bitRead(address, 3));
    digitalWrite(a4, bitRead(address, 4));
    digitalWrite(a5, bitRead(address, 5));
    digitalWrite(a6, bitRead(address, 6));
    digitalWrite(a7, bitRead(address, 7));
      
    //---------------------
    // Define Enable

    digitalWrite(q1, bitRead(enable, 6));
    digitalWrite(q2, bitRead(enable, 7));

    //---------------------
    // Delay

    delayMicroseconds(45);

    //---------------------
    // Read Data

    value = 0x00;
    bitWrite(value, 0, digitalRead(q0));
    bitWrite(value, 1, digitalRead(q1));
    bitWrite(value, 2, digitalRead(q2));
    bitWrite(value, 3, digitalRead(q3));
    bitWrite(value, 4, digitalRead(q4));
    bitWrite(value, 5, digitalRead(q5));
    bitWrite(value, 6, digitalRead(q6));
    bitWrite(value, 7, digitalRead(q7));

    data_read[address] = value;

    //---------------------
    // Write serial
      
    sprintf(buffer, "%02x ", value);
    Serial.write(buffer);

    column++;
    if ( column == 16 ) {        
      column = 0;
      Serial.write("\r\n");    
    }

    address++;
  }

  //--------------------------------------  

  unsigned char valid = false;

  if ( checkProm(data_read, rom_empty) ) {
    sprintf(buffer, "- The content is: [%s]\r\n", str_rom_empty);
    Serial.write(buffer);	  
	valid = true;
  }

  if ( checkProm(data_read, romP5_341_0009) ) {
    sprintf(buffer, "- The content is: [%s]\r\n", str_romP5_341_0009);
    Serial.write(buffer);		  
	valid = true;
  }

  if ( checkProm(data_read, romP6_341_0010) ) {
    sprintf(buffer, "- The content is: [%s]\r\n", str_romP6_341_0010);
    Serial.write(buffer);		  
	valid = true;
  }

  if ( checkProm(data_read, romP5_341_0027) ) {
    sprintf(buffer, "- The content is: [%s]\r\n", str_romP5_341_0027);
    Serial.write(buffer);		  
	valid = true;
  }

  if ( checkProm(data_read, romP6_341_0028) ) {
    sprintf(buffer, "- The content is: [%s]\r\n", str_romP6_341_0028);
    Serial.write(buffer);		  
	valid = true;
  }

  if ( ! valid  ) {
    sprintf(buffer, "# Content not recognized . . . :(\r\n");
    Serial.write(buffer);		  
  }
  
  //--------------------------------------

  Serial.write("\r\n[EOF]\r\n\r\n");    

  while ( true ); // Stop program
        
}

//-----------------------------------------------------------------------------