/*
    BitzOS (BOS) V0.1.6 - Copyright (C) 2017-2019 Hexabitz
    All rights reserved
		
    File Name     : H41Rx_MemoryMap.h
    Description   : Module MCU memory map header file.
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef H41RX_MEMORYMAP_H
#define H41RX_MEMORYMAP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Memory map: 	- STM32F745VGT6 LQFP-100 MCU
  				- Embedded FLASH memory accessible over AXI: 0x08000000 - 0x080FFFFF (1 MB)
  				- SRAM1 accessible over AXI/AHB: 0x20010000 - 0x2003C000 (240KB)
  				- SRAM2 accessible over AXI/AHB: 0x2004C000 - 0x20050000 (16KB)
  				- STM32F756xx and STM32F74xxx Flash memory organization
  								AXIM Interface				ITCM Interface
					Sector 0 0x08000000 - 0x08007FFF 	0x00200000 - 0x00207FFF 32 Kbytes
					Sector 1 0x08008000 - 0x0800FFFF 	0x00208000 - 0x0020FFFF 32 Kbytes
					Sector 2 0x08010000 - 0x08017FFF 	0x00210000 - 0x00217FFF 32 Kbytes
					Sector 3 0x08018000 - 0x0801FFFF 	0x00218000 - 0x0021FFFF 32 Kbytes
					Sector 4 0x08020000 - 0x0803FFFF 	0x00220000 - 0x0023FFFF 128 Kbytes
					Sector 5 0x08040000 - 0x0807FFFF 	0x00240000 - 0x0027FFFF 256 Kbytes
					Sector 6 0x08080000 - 0x080BFFFF 	0x00280000 - 0x002BFFFF 256 Kbytes
					Sector 7 0x080C0000 - 0x080FFFFF 	0x002C0000 - 0x002FFFFF 256 Kbytes

  				H41R7_F45 Memory Map:	TODO must update linker file
				- Application: Sectors 4 - 7: 		0x08020000 - 0x080FFFFF >> 896 KB
		 	 	- Read-only (RO): Sectors 0 & 1: 	0x08000000 - 0x0800FFFF >> 64 KB, used to store topology information and Command Snippets
				- Emulated EEPROM: Sectors 2 & 3: 	0x08010000 - 0x0801FFFF >> 64 KB, fits 1024 16-bit variables in 2 main-duplicate pages (A and B)
*/
#ifdef H41R7_F45
	#define APP_START_ADDRESS  				((uint32_t)0x08020000)
	#define RO_START_ADDRESS  				((uint32_t)0x08000000)
	#define RO_MID_ADDRESS  				((uint32_t)0x08008000) 		// Snippets are stored here
	#define EEPROM_START_ADDRESS  			((uint32_t)0x08010000)
	#define FLASH_SIZE						((uint32_t)0xE0000)			// Size of area available to application: E0000. All sizes in bytes
	#define SRAM_SIZE						((uint32_t)0x3C000)
	#define PAGE_SIZE             			((uint32_t)0x8000)  		// 32K Sector size for emulated EEPROM erase operations - TODO review eeprom code
	//#define NumOfPages						(FLASH_SIZE/PAGE_SIZE)
#endif


#ifdef __cplusplus
}
#endif

#endif /* H41RX_MEMORYMAP_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
