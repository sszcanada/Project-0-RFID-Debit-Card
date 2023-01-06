# Project-0-RFID-Debit-Card


Hey everyone. Over the holidays I created a small "debit card" system that uses RFID cards and a Mini RC522 scanner along with an app I made in Unreal. 

This is lovingly called Project Zero as it's an unofficial start to this year of new projects. I did not have a chance to film everything so there is no way I can count this as a full project. I will be working on a new and improved version later in the year as well 🙂 

In this system the RFID cards and scanner control most things. You scan a card and if it's found in the database it will return the users info, if not it will go to the add new users screen. 
After a card is scanned and the info is up on the screen you can edit the details, or start a sale. 
The sale has a input box you can just put in how much the things costs with your number pad or use it as a slider.  It will tell you how much balance is left after the transaction. If the balance is positive you can scan the card a second time to confirm the sale and it will adjust the users blance in database.
You can also access the user data manually in the save folder in case you want to make edits to a card without having the actual card to scan. Everything is held in plain text to easily edit in a text program.

# Included
STL files for 3D printed RFID card cases as well as the electronics housing
/n
the frtizing diagram
/n
the Arduino .ino code
/n
Unreal Engine app to run it all precompiled or source code for Unreal Engine 4.27

*The case for the electronics was designed to be solder free.


# What you will need 

Arduino Nano
Mini Breadboard
Mini RFID-RC522
0.96 Inch 4Pin I2C OLED
Wires 
Compiled version of the Unreal app

# How To Make it work

To make the system work you firstly assemble the components as shown in the fritzing diagram. 
Than upload the .ino sketch to your Arduino
Open the Unreal app and go into settings and set the COM port that your Arduino is using. 
Scan an RFID card while the app is open to add a new user
