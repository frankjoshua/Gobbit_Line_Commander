#define sketchVersion "12222016a"
/*
 *  Motor Direction Testing sketch to determine correct wiring
 *  of Left and Right gear motors with basic robot chassis.
 *
 *  For wiring diagram see:
 *  http://www.zagrosrobotics.com/files/ZagrosLineMazeFollowWiring_08232015a.pdf
 *  
 *  For detailed instructions on installing the Arduino IDE, Redboard drivers,  
 *  uploading sketches, and testing motors for proper wiring for this sketch see:
 *  http://www.zagrosrobotics.com/files/ZagrosArduinoInstallation_08232015a.pdf 
 *  
 *  Parts list:
 *
 *    1) Zagros Robot Starter Kit - Gobbit
 *       (http://www.zagrosrobotics.com/)
 *       Included components needed:
 *          Gobbit Chassis with motors and battery holder
 *          Sparkfun Redboard
 *          Motor Driver Shield
 *            Sparkfun Ardumoto Shield 
 *            or
 *            Adafruit Motorshield v2.3
 *          Jumper wires
 *          Breadboard optional
 *
 *  The motor engagement code within this sketch should work without
 *  changes if the Gobbit chassis is used and wired following Zagros Robotics'
 *  instructions.  This sketch will help confirm wiring is correct, or
 *  with different chassis, help determine what wires may need to be
 *  swapped.
 *
 *  To Use: 
 *    1) Upload sketch to Arduino/Redboard.
 *    2) Run the Serial Monitor with your Arduino/Redboard connected to your computer via USB.
 *    3) Test the motors individually first.  
 *        ***MAKE SURE BOTH WIRES FROM A SINGLE MOTOR ARE CONNECTED TO ONLY A SINGLE CHANNEL (M1/M2/M3/M4 on Adafruit vs. A/B Ardumoto)***
 *        a) If the wrong motor moves, swap the pairs of wires for your left motor with right motor.
 *        b) If the correct motor moves, but the wrong direction, swap the black and red 
 *           motor wires for just that motor.
 *        c) Re-test individual motors after any wiring changes.
 *    4) Test both motors together to confirm individual setup is correct.
 *    
 */

// #define ADAFRUIT_MS if the Adafruit motor shield v2.3 is to be used.
  // M1 and M2 will be used.  Right motor on M1, Left on M2.
  // No define will default to Sparkfun Ardumoto or other makes of Dir 
  // and PWM pin driven style drivers similar to the Ardumoto and those
  // based upon the L298 driver.  The default pin settings will be used 
  // except where new values have been declared.
  // UnComment the next line if you are using the Adafruit shield
//#define ADAFRUIT_MS 

#include <GobbitLineCommand.h>

GobbitLineCommand MyBot;

// incoming Serial data vars
int incomingByte = 0;	//  for incoming serial data input


void setup()
{
  MyBot.beginGobbit();

  Serial.begin(115200);

  Serial.println("Zagros Robotics, Inc.");
  Serial.println("Motor Direction Test PC Control");
  Serial.print("Version ");
  Serial.println(sketchVersion);
  Serial.println();
  incomingByte = '*';
}


void loop() // start main loop
{

  Serial.println("Which motor do you want to test?");
  Serial.println("  (l)eft");
  Serial.println("  (r)ight");
  Serial.println("  (b)oth");
  Serial.println();
  incomingByte = '*';

  while (Serial.available() == 0); // wait for serial input

  // read the incoming serial byte:
  incomingByte = Serial.read();

  // Left Motor only
  if (incomingByte == 'l')
  {

    incomingByte = '*';

    while (incomingByte != 'x')
    {

      Serial.println("Left motor only.");
      Serial.println("What direction?");
      Serial.println("  (f)orward");
      Serial.println("  (b)ackward");
      Serial.println("  (s)top");
      Serial.println("   e(x)it to motor selection menu.");
      Serial.println();
      incomingByte = '*';

      while (Serial.available() == 0); // wait for serial input

      // read the incoming serial byte:
      incomingByte = Serial.read();

      switch (incomingByte) // start left motor command switch
      {
        // stop
        case 's':
          MyBot.setMotors(0,0);
          Serial.println("Left Stop\n");
          incomingByte = '*';

          break;

        // forward
        case 'f':
          MyBot.setMotors(100,0);
          Serial.println("Left Forward\n");
          incomingByte = '*';
          break;

        // backward
        case 'b':
          MyBot.setMotors(-100,0);
          Serial.println("Left Backward\n");
          incomingByte = '*';
          break;

      }  // end Left motor command switch

    }  // end while right motor to return to prior menu at "x" input

    // stop
    MyBot.setMotors(0,0);

  } // end left motor option from main menu


  // Right Motor only
  else if (incomingByte == 'r')
  {
    incomingByte = '*';

    while (incomingByte != 'x')
    {

      Serial.println("Right motor only.");
      Serial.println("What direction?");
      Serial.println("  (f)orward");
      Serial.println("  (b)ackward");
      Serial.println("  (s)top");
      Serial.println("   e(x)it to motor selection menu.");
      Serial.println();
      incomingByte = '*';

      while (Serial.available() == 0); // wait for serial input

      // read the incoming serial byte:
      incomingByte = Serial.read();

      switch (incomingByte) // start right motor command switch
      {
        // stop
        case 's':
          MyBot.setMotors(0,0);
          Serial.println("Right Stop\n");
          incomingByte = '*';

          break;

        // forward
        case 'f':
          MyBot.setMotors(0,100);
          Serial.println("Right Forward\n");
          incomingByte = '*';
          break;

        // backward
        case 'b':
          MyBot.setMotors(0,-100);
          Serial.println("Right Backward\n");
          incomingByte = '*';
          break;

      }  // end Right motor command switch

    }  // end while right motor to return to prior menu at "x" input

    // stop
    MyBot.setMotors(0,0);

  } // end right motor option from main menu


  // Both Motors
  else if (incomingByte == 'b')
  {
    incomingByte = '*';

    while (incomingByte != 'x')
    {

      Serial.println("Both motors.");
      Serial.println("What direction?");
      Serial.println("  (f)orward");
      Serial.println("  (b)ackward");
      Serial.println("  (l)eft");
      Serial.println("  (r)ight");
      Serial.println("  (s)top");
      Serial.println("   e(x)it to motor selection menu.");
      Serial.println();
      incomingByte = '*';

      while (Serial.available() == 0); // wait for serial input

      // read the incoming serial byte:
      incomingByte = Serial.read();

      switch (incomingByte) // start both motor command switch
      {
        // stop
        case 's':
          MyBot.setMotors(0,0);
          Serial.println("Both Stop\n");
          incomingByte = '*';

          break;

        // forward
        case 'f':
          MyBot.setMotors(100,100);
          Serial.println("Both Forward\n");
          incomingByte = '*';
          break;

        // backward
        case 'b':
          MyBot.setMotors(-100,-100);
          Serial.println("Both Backward\n");
          incomingByte = '*';
          break;

        // Rotate left
        case 'l':
          MyBot.setMotors(-100,100);
          Serial.println("Rotate Left\n");
          incomingByte = '*';
          break;

        // Rotate right
        case 'r':
          MyBot.setMotors(100,-100);
          Serial.println("Rotate Right\n");
          incomingByte = '*';
          break;

      }  // end both motor command switch

    }  // end while both motors to return to prior menu at "x" input

    // stop
    MyBot.setMotors(0,0);

    incomingByte = '*';

  } // end both motor option from main menu

  else incomingByte = '*';

  delay(10);

}  // end main loop




