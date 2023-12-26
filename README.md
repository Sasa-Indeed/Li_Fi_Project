
# Li-Fi Project

Li-Fi or Light fidelity is a wireless Communication Technology that uses the light to transmit data and information among different devices. Li-Fi can send the data at a very high speed, Theoretically up to 100 Gbit/sec, over the normal visible light, Infrared, or Ultraviolet spectrum. The theory here is that we have a transmitter board and receiver board commuincating through the light.
 


## Note

You need to install Tivaware for this project to work. If you are using IAR here are the following steps to add Tivaware to your project:

- Project options->C/C++ compiler ->Preprocessor -> Additional Include Libraries -> Add the Tivaware Directory in your PC 

- Project options->C/C++ compiler ->Preprocessor -> Define Symbols -> Type the following: ewarm PART_TM4C123GH6PM TARGET_IS_TM4C123_RB1 (You may be required to put each word in a sperate line)

- Project options-> Linker -> Add Additional library -> Add the following file from your tivaware directory ti\TivaWare_C_Series-2.1.4.178\driverlib\ewarm\Exe\driverlib.a



