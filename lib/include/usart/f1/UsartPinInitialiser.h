/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once


namespace stm32plus {


	/**
	 * Convenience template to initialise a USART pin package
	 */

	template<class TPinPackage,PeripheralName TPeripheralName>
	class UsartPinInitialiser {
		public:
			static void initialise(uint16_t mode,uint16_t flowControl,bool synchronous);
	};


	/**
	 * Initialise the pin package that we were parameterised with
	 */

	template<class TPinPackage,PeripheralName TPeripheralName>
	inline void UsartPinInitialiser<TPinPackage,TPeripheralName>::initialise(uint16_t mode,uint16_t flowControl,bool synchronous) {

			if((mode & USART_Mode_Tx)!=0)
				GpioPinInitialiser::initialise(
						(GPIO_TypeDef *)TPinPackage::Port_TX,
						TPinPackage::Pin_TX,
						Gpio::ALTERNATE_FUNCTION,
						(GPIOSpeed_TypeDef)PeripheralTraits<TPeripheralName>::GPIO_SPEED,
						Gpio::PUPD_NONE,
						Gpio::PUSH_PULL,
						GpioAlternateFunctionMapper<TPeripheralName,TPinPackage::Port_TX,TPinPackage::Pin_TX>::GPIO_AF);

			if((mode & USART_Mode_Rx)!=0)
				GpioPinInitialiser::initialise(
						(GPIO_TypeDef *)TPinPackage::Port_RX,
						TPinPackage::Pin_RX,Gpio::INPUT,
						(GPIOSpeed_TypeDef)PeripheralTraits<TPeripheralName>::GPIO_SPEED,
						Gpio::PUPD_NONE);

			if(flowControl==USART_HardwareFlowControl_CTS || flowControl==USART_HardwareFlowControl_RTS_CTS)
				GpioPinInitialiser::initialise(
						(GPIO_TypeDef *)TPinPackage::Port_CTS,
						TPinPackage::Pin_CTS,
						Gpio::INPUT,
						(GPIOSpeed_TypeDef)PeripheralTraits<TPeripheralName>::GPIO_SPEED,
						Gpio::PUPD_NONE);

			if(flowControl==USART_HardwareFlowControl_RTS || flowControl==USART_HardwareFlowControl_RTS_CTS)
				GpioPinInitialiser::initialise(
						(GPIO_TypeDef *)TPinPackage::Port_RTS,
						TPinPackage::Pin_RTS,
						Gpio::ALTERNATE_FUNCTION,
						(GPIOSpeed_TypeDef)PeripheralTraits<TPeripheralName>::GPIO_SPEED,
						Gpio::PUPD_NONE,
						Gpio::PUSH_PULL,
						GpioAlternateFunctionMapper<TPeripheralName,TPinPackage::Port_RTS,TPinPackage::Pin_RTS>::GPIO_AF);

			if(synchronous)
				GpioPinInitialiser::initialise(
						(GPIO_TypeDef *)TPinPackage::Port_CK,
						TPinPackage::Pin_CK,
						Gpio::ALTERNATE_FUNCTION,
						(GPIOSpeed_TypeDef)PeripheralTraits<TPeripheralName>::GPIO_SPEED,
						Gpio::PUPD_NONE,
						Gpio::PUSH_PULL,
						GpioAlternateFunctionMapper<TPeripheralName,TPinPackage::Port_CK,TPinPackage::Pin_CK>::GPIO_AF);
	}
}