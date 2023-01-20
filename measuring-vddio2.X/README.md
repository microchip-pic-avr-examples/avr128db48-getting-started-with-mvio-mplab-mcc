<!-- Please do not change this logo with link -->
[![MCHP](images/microchip.png)](https://www.microchip.com)

# Measuring VDDIO2 with ADC
This example shows how to configure the ADC to measure VDDIO2 on the AVR® DB Family of microcontrollers with the Melody MCC Library.

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
-  MPLAB® Data Visualizer in MPLAB® X IDE or any other serial terminal application


## Hardware Used

- Variable external power supply (1.5 V - 3.3 V)
- [AVR128DB48 Curiosity Nano](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV35L43A)

## Peripherals Configuration using MCC

### Added Peripherals

- Add the ADC Driver found under *Device Resources*

![MVIO_driver](images/MCC_Melody_adding_MVIO_driver.png)

- Add the ADC Driver found under *Device Resources*

![ADC_driver](images/MCC_Melody_adding_ADC_driver.png)

- Configure the V<sub>REF</sub> peripheral to provide a reference of 1.024 V, which will be sufficient to measure the VDDIO/10. 

![Builder](images/MCC_Melody_adding_VREF_config.png)

- Configure the differential ADC peripheral to measure 16 samples with the positive input to VDDIO2/10, and the negative input to gnd.

![Builder](images/MCC_Melody_adding_ADC_config.png)

- No configuration is necessary in the MVIO driver, since interrupts will not be used.

![Builder](images/MCC_Melody_mvio.png)


### Main code

- Modify the *main()* function in **main.c** to get an ADC conversion, and calculate the average by dividing by 16.

```c
/*
    Main application
*/

volatile uint16_t result;

int main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        /* Do ADC conversion on VDDIO/10 */
        /* shift the result 4 bits to compensate for the 16 over samples*/
        result = (ADC0_GetConversion(ADC_MUXPOS_VDDIO2DIV10_gc) >> 4);
        
        /* Maybe output data on USART to DataVisualizer */
        
    }    
}
```

## Setup

- Connect the hardware together as documented in the image above, with details in [TB3287 - Getting Started With MVIO](https://microchip.com/DS90003287)
- Note this example is part of the series *Getting Started with MVIO*, see the series  [**README.md**](../README.md) for more information.
- Connect the AVR128DB48 Curiosity Nano board to your computer using a USB cable
- Download and install all software components as listed under 'Software Used' (note that MPLAB Xpress IDE is an online tool that cannot be downloaded)


## Operation

1. Download the zip file or clone the example to get the source code.
2. Open the .X file with the MPLAB® X IDE.
3. Program the project to the AVR128DB48 Curiosity Nano: 
	- First clean and build the project by pressing the *Clean and Build Main Project* button.
	![clean_and_build](images/clean_and_build.png)
	- Then make and program the project to the AVR128DB48 by clicking the *Make and Program Device Main Project* button.
	![make_and_prog](images/make_and_prog.png)
4. Running in debug mode will allow visualization of the result variable which contains the **VDDIO2 / 10** voltage.

## Summary

This example shows how to add ADC driver support and use the driver API to measure the VDDIO2 supply.
