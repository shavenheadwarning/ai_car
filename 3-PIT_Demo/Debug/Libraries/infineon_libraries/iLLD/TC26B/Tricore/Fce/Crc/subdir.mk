################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/IfxFce_Crc.c 

OBJS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/IfxFce_Crc.o 

COMPILED_SRCS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/IfxFce_Crc.src 

C_DEPS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/IfxFce_Crc.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/%.src: ../Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\CODE" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\doc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Configurations" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Build" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Impl" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_PinMap" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Asc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Lin" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Spi" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Icu" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Timer" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif\Cam" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\CStart" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Irq" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Trap" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma\Dma" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Dsadc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Rdc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts\Dts" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Emem" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Emem\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray\Eray" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth\Phy_Pef7071" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce\Crc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft\Fft" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Flash" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Flash\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12\IncrEnc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tim" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Trig" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl\Hssl" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c\I2c" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom\Driver" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc\Msc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Mtu" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Mtu\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican\Can" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port\Io" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5\Psi5" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s\Psi5s" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\SpiMaster" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\SpiSlave" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Scu" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Scu\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent\Sent" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Smu" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Smu\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Src" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Src\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm\Timer" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc\Adc" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc\Std" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra\Platform" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra\Platform\Tricore" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra\Platform\Tricore\Compilers" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra\Sfr" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra\Sfr\TC26B" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Infra\Sfr\TC26B\_Reg" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Service" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Service\CpuGeneric" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Service\CpuGeneric\_Utilities" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Service\CpuGeneric\If" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Service\CpuGeneric\StdIf" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\infineon_libraries\Service\CpuGeneric\SysSe" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\seekfree_libraries" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\seekfree_libraries\common" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\Libraries\seekfree_peripheral" -I"D:\ELECTRONMAGNETISM_CAR\USER_WORKSPACE2\3-PIT_Demo\USER" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1; sed -i -e '/ctc\\include/d' -e '/Libraries\\iLLD/d' -e '/Libraries\\Infra/d' -e 's/\(.*\)".*\\3-PIT_Demo\(\\.*\)"/\1\.\.\2/g' -e 's/\\/\//g' $(@:.src=.d) && \
	echo $(@:.src=.d) generated
	@echo 'Finished building: $<'
	@echo ' '

Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/%.o: ./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Crc/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


