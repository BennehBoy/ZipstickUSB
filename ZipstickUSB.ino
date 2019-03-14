#include "USBComposite.h" // https://github.com/arpruss/USBHID_stm32f1

#define LED_BUILTIN PA1 // change to match your board ; PB12 for some black pills ; PC13 for blue/red pill

const uint32 leftSwitch = PA7;
const uint32 rightSwitch = PA6;
const uint32 upSwitch = PA5;
const uint32 downSwitch = PA4;
const uint32 fireSwitch = PA3;
const bool switchActive = 1; // 1 if microswitch is connected to VCC and pulled down

USBHID HID;
HIDJoystick Joystick(HID);

void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PA7, INPUT_PULLDOWN);
    pinMode(PA6, INPUT_PULLDOWN);
    pinMode(PA5, INPUT_PULLDOWN);
    pinMode(PA4, INPUT_PULLDOWN);
    pinMode(PA3, INPUT_PULLDOWN);
    USBComposite.setVendorId(0x040B);
    USBComposite.setProductId(0x6533);
    USBComposite.setProductString("Speed-Link Competition Pro");
    HID.begin(HID_JOYSTICK);
    digitalWrite(LED_BUILTIN, 1);     
    adc_set_sample_rate(ADC1, ADC_SMPR_13_5); // ADC_SMPR_13_5, ADC_SMPR_1_5
    Joystick.setManualReportMode(true);
} 

void loop() 
{
 if (digitalRead(leftSwitch) == switchActive) Joystick.X(0);  
 else if (digitalRead(rightSwitch) == switchActive) Joystick.X(1023);
 else Joystick.X(512);
 if (digitalRead(upSwitch) == switchActive) Joystick.Y(0); 
 else if (digitalRead(downSwitch) == switchActive) Joystick.Y(1023);
 else Joystick.Y(512);
 if (digitalRead(fireSwitch) == switchActive) Joystick.button(1,true);
 else Joystick.button(1,false);
 Joystick.send();
}
