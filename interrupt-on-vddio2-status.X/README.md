<!-- Please do not change this logo with link -->
[![MCHP](images/microchip.png)](https://www.microchip.com)

# Interrupt on VDDIO2 Status
This example shows how to configure the Multi Voltage IO (MVIO) on the AVR® DB Family of microcontrollers with the Melody MCC Library, to generate and interrupt if the VDDIO2 voltage below of minimum acceptable voltage. 

<p>
	<img width=700px height=auto src="images/AVR128DB48_CNANO_HDW_MOD.png">
</p>

## Related Documentation

- [AVR128DB48 device page](https://www.microchip.com/wwwproducts/en/AVR128DB48)
- [MPLAB Code Configurator](https://www.microchip.com/en-us/development-tools-tools-and-software/embedded-software-center/mplab-code-configurator)
- [AVR128DB48 Curiosity Nano Hardware User Guide](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV35L43A)


## Software Used

- [MPLAB® X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide) or newer
- [MPLAB® Xpress IDE](https://www.microchip.com/xpress) (alternative to MPLAB X IDE)
- [XC8 Compiler v2.31](https://www.microchip.com/mplab/compilers) or newer
- [MPLAB® Code Configurator (MCC) v4.1.0](https://www.microchip.com/mplab/mplab-code-configurator) or newer
- [MPLAB® Melody Library 1.37.26 or newer](https://www.microchip.com/mplab/mplab-code-configurator) or newer
- [MCC Device Libraries 8-bit AVR MCUs 2.7.0](https://www.microchip.com/mplab/mplab-code-configurator) or newer
- [Microchip AVR128DB48 Device Support Pack AVR-Dx_DFP 1.2.88](https://packs.download.microchip.com/) or newer
-  MPLAB Data Visualizer in MPLAB X IDE or any other serial terminal application


## Hardware Used

- Variable external power supply (1.5V - 3.3V)
- [AVR128DB48 Curiosity Nano](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV35L43A)


## Peripherals Configuration using MCC

### Added Peripherals

- Add the MVIO Driver found under *Device Resources*

![MVIO_driver](images/MCC_Melody_adding_MVIO_driver.png)

- The **Builder** tab shows the system, with the added *MVIO peripheral*.  Click on the *MVIO block*, to enable the VDDIO2 interrupt in the driver configuration *Easy View*.

![Builder](images/MCC_Melody_mvio.png)

- Enabling *Global Interrupts* is set in the *Interrupt Manager*.

![Interrupts](images/MCC_Melody_interrupt_manager.png)

- Configure the IO PIN *PB3* as output, which is connected to the LED0 on the CNANO, and name it *IO_LED0_PB3*.

![IO_pins](images/MCC_Melody_pins_PB3_LED0.png)

- The driver **mvio.c** file contains the function *ISR(MVIO_MVIO_vect)*, which contains code to toggle the CNANO LED0.

```c
ISR(MVIO_MVIO_vect)
{
    /* Insert your MVIO interrupt handling code here */
    /* Toggle the CNANO LED on interrupt*/
    IO_LED0_PB3_Toggle();
    
    /* Clear the VDDIO2 interrupt flag */
    MVIO.INTFLAGS |= MVIO_VDDIO2IF_bm;
}
```


### Main code

- Modify the *SYSTEM_Initialize()* function in **main.c** will call setup functions and enable both global and mvio interrupt.

```c
/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    
    while(1)
    {
    }    
}
```

- The value that triggers the VDDIO2 below range can be found in the datasheet under [Datasheet - Electrical Characteristics](https://www.microchip.com/wwwproducts/en/AVR64DB48), check the website for latest datasheet.

![Datasheet - Electrical Characteristics](images/VDDIO2_supply_range.png)


## Setup

- Connect the hardware together as documented in the image above, with details in [TB3287 - Getting Started With MVIO](https://microchip.com/DS90003287)
- Note this example is part of the series *Getting Started with MVIO*, see the series  [**README.md**](../README.md) for more information.
- Connect the AVR128DB48 Curiosity Nano board to your computer using a USB cable
- Download and install all software components as listed under 'Software Used' (note that MPLAB Xpress IDE is an online tool that cannot be downloaded)


## Operation

1. Download the zip file or clone the example to get the source code
1. Open the .X file with the MPLAB® X IDE
1. Program the project to the AVR128DB48 Curiosity Nano: 
	- First clean and build the project by pressing the *Clean and Build Main Project* button
	![clean_and_build](images/clean_and_build.png)
	- Then make and program the project to the AVR128DB48 by clicking the *Make and Program Device Main Project* button
	![make_and_prog](images/make_and_prog.png)
1. Lower the external voltage supply to 1.5V and LED should toggle, increasing the voltage above the MVIO typical minimum value will not toggle the LED.

## Summary

This example shows how to:
* Add and configure MVIO driver support with interrupts enabled
* Toggle the CNANO LED when MVIO is interrupt executed, when the MVIO supply voltage is below typical minimum
