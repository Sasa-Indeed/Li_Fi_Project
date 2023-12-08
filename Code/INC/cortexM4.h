#ifndef _CORTEXM4_H_
#define _CORTEXM4_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "types.h"


/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm("CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm("CPSID F") 

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")

//*****************************************************************************
//
// GPIO registers (APB)
//
//*****************************************************************************
#define GPIO_Port_A_APB_BASE                           ((volatile unsigned long *)0x40004000)
#define GPIO_Port_B_APB_BASE                           ((volatile unsigned long *)0x40005000)
#define GPIO_Port_C_APB_BASE                           ((volatile unsigned long *)0x40006000)
#define GPIO_Port_D_APB_BASE                           ((volatile unsigned long *)0x40007000)
#define GPIO_Port_E_APB_BASE                           ((volatile unsigned long *)0x40024000)
#define GPIO_Port_F_APB_BASE                           ((volatile unsigned long *)0x40025000)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-
#define GPIODATA_BASE                                  (0x3FC)         //GPIO Data
#define GPIODIR_BASE                                   (0x400)         //GPIO Direction
#define GPIOIS_BASE                                    (0x404)         //GPIO Interrupt Sense
#define GPIOIBE_BASE                                   (0x408)         //GPIO Interrupt Both Edges
#define GPIOIEV_BASE                                   (0x40C)         //GPIO Interrupt Event
#define GPIOIM_BASE                                    (0x410)         //GPIO Interrupt Mask
#define GPIORIS_BASE                                   (0x414)         //GPIO Raw Interrupt Status
#define GPIOMIS_BASE                                   (0x418)         //GPIO Masked Interrupt Status
#define GPIOICR_BASE                                   (0x41C)         //GPIO Interrupt Clear
#define GPIOAFSEL_BASE                                 (0x420)         //GPIO Alternate Function Select
#define GPIODR2R_BASE                                  (0x500)         //GPIO 2-mA Drive Select
#define GPIODR4R_BASE                                  (0x504)         //GPIO 4-mA Drive Select
#define GPIODR8R_BASE                                  (0x508)         //GPIO 8-mA Drive Select
#define GPIOODR_BASE                                   (0x50C)         //GPIO Open Drain Select
#define GPIOPUR_BASE                                   (0x510)          //GPIO Pull-Up Select
#define GPIOPDR_BASE                                   (0x514)         //GPIO Pull-Down Select
#define GPIOSLR_BASE                                   (0x518)         //GPIO Slew Rate Control Select
#define GPIODEN_BASE                                   (0x51C)         //GPIO Digital Enable
#define GPIOLOCK_BASE                                  (0x520)         //GPIO Lock
#define GPIOCR_BASE                                    (0x524)         //GPIO Commit
#define GPIOAMSEL_BASE                                 (0x528)         //GPIO Analog Mode Select
#define GPIOPCTL_BASE                                  (0x52C)         //GPIO Port Control
#define GPIOADCCTL_BASE                                (0x530)         //GPIO ADC Control
#define GPIODMACTL_BASE                                (0x534)         //GPIO DMA Control


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-
//#define GPIOA 		((gpio_typedef *) GPIO_Port_A_APB_BASE)
//#define GPIOB 		((gpio_typedef *) GPIO_Port_B_APB_BASE)
//#define GPIOC		((gpio_typedef *) GPIO_Port_C_APB_BASE)
//#define GPIOD		((gpio_typedef *) GPIO_Port_D_APB_BASE)
//#define GPIOE		((gpio_typedef *) GPIO_Port_E_APB_BASE)
//#define GPIOF		((gpio_typedef *) GPIO_Port_F_APB_BASE)
#define GPIOA 		GPIO_Port_A_APB_BASE
#define GPIOB 		GPIO_Port_B_APB_BASE
#define GPIOC		GPIO_Port_C_APB_BASE
#define GPIOD		GPIO_Port_D_APB_BASE
#define GPIOE		GPIO_Port_E_APB_BASE
#define GPIOF		GPIO_Port_F_APB_BASE

//*****************************************************************************
//
// System Control registers (SYSCTL)
//
//*****************************************************************************
#define SYSCTL_DID0_R           (*((volatile unsigned long *)0x400FE000))
#define SYSCTL_DID1_R           (*((volatile unsigned long *)0x400FE004))
#define SYSCTL_DC0_R            (*((volatile unsigned long *)0x400FE008))
#define SYSCTL_DC1_R            (*((volatile unsigned long *)0x400FE010))
#define SYSCTL_DC2_R            (*((volatile unsigned long *)0x400FE014))
#define SYSCTL_DC3_R            (*((volatile unsigned long *)0x400FE018))
#define SYSCTL_DC4_R            (*((volatile unsigned long *)0x400FE01C))
#define SYSCTL_DC5_R            (*((volatile unsigned long *)0x400FE020))
#define SYSCTL_DC6_R            (*((volatile unsigned long *)0x400FE024))
#define SYSCTL_DC7_R            (*((volatile unsigned long *)0x400FE028))
#define SYSCTL_DC8_R            (*((volatile unsigned long *)0x400FE02C))
#define SYSCTL_PBORCTL_R        (*((volatile unsigned long *)0x400FE030))
#define SYSCTL_SRCR0_R          (*((volatile unsigned long *)0x400FE040))
#define SYSCTL_SRCR1_R          (*((volatile unsigned long *)0x400FE044))
#define SYSCTL_SRCR2_R          (*((volatile unsigned long *)0x400FE048))
#define SYSCTL_RIS_R            (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_IMC_R            (*((volatile unsigned long *)0x400FE054))
#define SYSCTL_MISC_R           (*((volatile unsigned long *)0x400FE058))
#define SYSCTL_RESC_R           (*((volatile unsigned long *)0x400FE05C))
#define SYSCTL_RCC_R            (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_GPIOHBCTL_R      (*((volatile unsigned long *)0x400FE06C))
#define SYSCTL_RCC2_R           (*((volatile unsigned long *)0x400FE070))
#define SYSCTL_MOSCCTL_R        (*((volatile unsigned long *)0x400FE07C))
#define SYSCTL_RCGC0_R          (*((volatile unsigned long *)0x400FE100))
#define SYSCTL_RCGC1_R          (*((volatile unsigned long *)0x400FE104))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_SCGC0_R          (*((volatile unsigned long *)0x400FE110))
#define SYSCTL_SCGC1_R          (*((volatile unsigned long *)0x400FE114))
#define SYSCTL_SCGC2_R          (*((volatile unsigned long *)0x400FE118))
#define SYSCTL_DCGC0_R          (*((volatile unsigned long *)0x400FE120))
#define SYSCTL_DCGC1_R          (*((volatile unsigned long *)0x400FE124))
#define SYSCTL_DCGC2_R          (*((volatile unsigned long *)0x400FE128))
#define SYSCTL_DSLPCLKCFG_R     (*((volatile unsigned long *)0x400FE144))
#define SYSCTL_SYSPROP_R        (*((volatile unsigned long *)0x400FE14C))
#define SYSCTL_PIOSCCAL_R       (*((volatile unsigned long *)0x400FE150))
#define SYSCTL_PIOSCSTAT_R      (*((volatile unsigned long *)0x400FE154))
#define SYSCTL_PLLFREQ0_R       (*((volatile unsigned long *)0x400FE160))
#define SYSCTL_PLLFREQ1_R       (*((volatile unsigned long *)0x400FE164))
#define SYSCTL_PLLSTAT_R        (*((volatile unsigned long *)0x400FE168))
#define SYSCTL_DC9_R            (*((volatile unsigned long *)0x400FE190))
#define SYSCTL_NVMSTAT_R        (*((volatile unsigned long *)0x400FE1A0))
#define SYSCTL_PPWD_R           (*((volatile unsigned long *)0x400FE300))
#define SYSCTL_PPTIMER_R        (*((volatile unsigned long *)0x400FE304))
#define SYSCTL_PPGPIO_R         (*((volatile unsigned long *)0x400FE308))
#define SYSCTL_PPDMA_R          (*((volatile unsigned long *)0x400FE30C))
#define SYSCTL_PPHIB_R          (*((volatile unsigned long *)0x400FE314))
#define SYSCTL_PPUART_R         (*((volatile unsigned long *)0x400FE318))
#define SYSCTL_PPSSI_R          (*((volatile unsigned long *)0x400FE31C))
#define SYSCTL_PPI2C_R          (*((volatile unsigned long *)0x400FE320))
#define SYSCTL_PPUSB_R          (*((volatile unsigned long *)0x400FE328))
#define SYSCTL_PPCAN_R          (*((volatile unsigned long *)0x400FE334))
#define SYSCTL_PPADC_R          (*((volatile unsigned long *)0x400FE338))
#define SYSCTL_PPACMP_R         (*((volatile unsigned long *)0x400FE33C))
#define SYSCTL_PPPWM_R          (*((volatile unsigned long *)0x400FE340))
#define SYSCTL_PPQEI_R          (*((volatile unsigned long *)0x400FE344))
#define SYSCTL_PPEEPROM_R       (*((volatile unsigned long *)0x400FE358))
#define SYSCTL_PPWTIMER_R       (*((volatile unsigned long *)0x400FE35C))
#define SYSCTL_SRWD_R           (*((volatile unsigned long *)0x400FE500))
#define SYSCTL_SRTIMER_R        (*((volatile unsigned long *)0x400FE504))
#define SYSCTL_SRGPIO_R         (*((volatile unsigned long *)0x400FE508))
#define SYSCTL_SRDMA_R          (*((volatile unsigned long *)0x400FE50C))
#define SYSCTL_SRHIB_R          (*((volatile unsigned long *)0x400FE514))
#define SYSCTL_SRUART_R         (*((volatile unsigned long *)0x400FE518))
#define SYSCTL_SRSSI_R          (*((volatile unsigned long *)0x400FE51C))
#define SYSCTL_SRI2C_R          (*((volatile unsigned long *)0x400FE520))
#define SYSCTL_SRUSB_R          (*((volatile unsigned long *)0x400FE528))
#define SYSCTL_SRCAN_R          (*((volatile unsigned long *)0x400FE534))
#define SYSCTL_SRADC_R          (*((volatile unsigned long *)0x400FE538))
#define SYSCTL_SRACMP_R         (*((volatile unsigned long *)0x400FE53C))
#define SYSCTL_SRPWM_R          (*((volatile unsigned long *)0x400FE540))
#define SYSCTL_SRQEI_R          (*((volatile unsigned long *)0x400FE544))
#define SYSCTL_SREEPROM_R       (*((volatile unsigned long *)0x400FE558))
#define SYSCTL_SRWTIMER_R       (*((volatile unsigned long *)0x400FE55C))
#define SYSCTL_RCGCWD_R         (*((volatile unsigned long *)0x400FE600))
#define SYSCTL_RCGCTIMER_R      (*((volatile unsigned long *)0x400FE604))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_RCGCDMA_R        (*((volatile unsigned long *)0x400FE60C))
#define SYSCTL_RCGCHIB_R        (*((volatile unsigned long *)0x400FE614))
#define SYSCTL_RCGCUART_R       (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_RCGCSSI_R        (*((volatile unsigned long *)0x400FE61C))
#define SYSCTL_RCGCI2C_R        (*((volatile unsigned long *)0x400FE620))
#define SYSCTL_RCGCUSB_R        (*((volatile unsigned long *)0x400FE628))
#define SYSCTL_RCGCCAN_R        (*((volatile unsigned long *)0x400FE634))
#define SYSCTL_RCGCADC_R        (*((volatile unsigned long *)0x400FE638))
#define SYSCTL_RCGCACMP_R       (*((volatile unsigned long *)0x400FE63C))
#define SYSCTL_RCGCPWM_R        (*((volatile unsigned long *)0x400FE640))
#define SYSCTL_RCGCQEI_R        (*((volatile unsigned long *)0x400FE644))
#define SYSCTL_RCGCEEPROM_R     (*((volatile unsigned long *)0x400FE658))
#define SYSCTL_RCGCWTIMER_R     (*((volatile unsigned long *)0x400FE65C))
#define SYSCTL_SCGCWD_R         (*((volatile unsigned long *)0x400FE700))
#define SYSCTL_SCGCTIMER_R      (*((volatile unsigned long *)0x400FE704))
#define SYSCTL_SCGCGPIO_R       (*((volatile unsigned long *)0x400FE708))
#define SYSCTL_SCGCDMA_R        (*((volatile unsigned long *)0x400FE70C))
#define SYSCTL_SCGCHIB_R        (*((volatile unsigned long *)0x400FE714))
#define SYSCTL_SCGCUART_R       (*((volatile unsigned long *)0x400FE718))
#define SYSCTL_SCGCSSI_R        (*((volatile unsigned long *)0x400FE71C))
#define SYSCTL_SCGCI2C_R        (*((volatile unsigned long *)0x400FE720))
#define SYSCTL_SCGCUSB_R        (*((volatile unsigned long *)0x400FE728))
#define SYSCTL_SCGCCAN_R        (*((volatile unsigned long *)0x400FE734))
#define SYSCTL_SCGCADC_R        (*((volatile unsigned long *)0x400FE738))
#define SYSCTL_SCGCACMP_R       (*((volatile unsigned long *)0x400FE73C))
#define SYSCTL_SCGCPWM_R        (*((volatile unsigned long *)0x400FE740))
#define SYSCTL_SCGCQEI_R        (*((volatile unsigned long *)0x400FE744))
#define SYSCTL_SCGCEEPROM_R     (*((volatile unsigned long *)0x400FE758))
#define SYSCTL_SCGCWTIMER_R     (*((volatile unsigned long *)0x400FE75C))
#define SYSCTL_DCGCWD_R         (*((volatile unsigned long *)0x400FE800))
#define SYSCTL_DCGCTIMER_R      (*((volatile unsigned long *)0x400FE804))
#define SYSCTL_DCGCGPIO_R       (*((volatile unsigned long *)0x400FE808))
#define SYSCTL_DCGCDMA_R        (*((volatile unsigned long *)0x400FE80C))
#define SYSCTL_DCGCHIB_R        (*((volatile unsigned long *)0x400FE814))
#define SYSCTL_DCGCUART_R       (*((volatile unsigned long *)0x400FE818))
#define SYSCTL_DCGCSSI_R        (*((volatile unsigned long *)0x400FE81C))
#define SYSCTL_DCGCI2C_R        (*((volatile unsigned long *)0x400FE820))
#define SYSCTL_DCGCUSB_R        (*((volatile unsigned long *)0x400FE828))
#define SYSCTL_DCGCCAN_R        (*((volatile unsigned long *)0x400FE834))
#define SYSCTL_DCGCADC_R        (*((volatile unsigned long *)0x400FE838))
#define SYSCTL_DCGCACMP_R       (*((volatile unsigned long *)0x400FE83C))
#define SYSCTL_DCGCPWM_R        (*((volatile unsigned long *)0x400FE840))
#define SYSCTL_DCGCQEI_R        (*((volatile unsigned long *)0x400FE844))
#define SYSCTL_DCGCEEPROM_R     (*((volatile unsigned long *)0x400FE858))
#define SYSCTL_DCGCWTIMER_R     (*((volatile unsigned long *)0x400FE85C))
#define SYSCTL_PRWD_R           (*((volatile unsigned long *)0x400FEA00))
#define SYSCTL_PRTIMER_R        (*((volatile unsigned long *)0x400FEA04))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))
#define SYSCTL_PRDMA_R          (*((volatile unsigned long *)0x400FEA0C))
#define SYSCTL_PRHIB_R          (*((volatile unsigned long *)0x400FEA14))
#define SYSCTL_PRUART_R         (*((volatile unsigned long *)0x400FEA18))
#define SYSCTL_PRSSI_R          (*((volatile unsigned long *)0x400FEA1C))
#define SYSCTL_PRI2C_R          (*((volatile unsigned long *)0x400FEA20))
#define SYSCTL_PRUSB_R          (*((volatile unsigned long *)0x400FEA28))
#define SYSCTL_PRCAN_R          (*((volatile unsigned long *)0x400FEA34))
#define SYSCTL_PRADC_R          (*((volatile unsigned long *)0x400FEA38))
#define SYSCTL_PRACMP_R         (*((volatile unsigned long *)0x400FEA3C))
#define SYSCTL_PRPWM_R          (*((volatile unsigned long *)0x400FEA40))
#define SYSCTL_PRQEI_R          (*((volatile unsigned long *)0x400FEA44))
#define SYSCTL_PREEPROM_R       (*((volatile unsigned long *)0x400FEA58))
#define SYSCTL_PRWTIMER_R       (*((volatile unsigned long *)0x400FEA5C))

//*****************************************************************************
//
// NVIC registers (NVIC)
//
//*****************************************************************************
#define NVIC_ACTLR_R            (*((volatile unsigned long *)0xE000E008))
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_R              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_R              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_R              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_R              (*((volatile unsigned long *)0xE000E110))
#define NVIC_DIS0_R             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_R             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_R             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_R             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_R             (*((volatile unsigned long *)0xE000E190))
#define NVIC_PEND0_R            (*((volatile unsigned long *)0xE000E200))
#define NVIC_PEND1_R            (*((volatile unsigned long *)0xE000E204))
#define NVIC_PEND2_R            (*((volatile unsigned long *)0xE000E208))
#define NVIC_PEND3_R            (*((volatile unsigned long *)0xE000E20C))
#define NVIC_PEND4_R            (*((volatile unsigned long *)0xE000E210))
#define NVIC_UNPEND0_R          (*((volatile unsigned long *)0xE000E280))
#define NVIC_UNPEND1_R          (*((volatile unsigned long *)0xE000E284))
#define NVIC_UNPEND2_R          (*((volatile unsigned long *)0xE000E288))
#define NVIC_UNPEND3_R          (*((volatile unsigned long *)0xE000E28C))
#define NVIC_UNPEND4_R          (*((volatile unsigned long *)0xE000E290))
#define NVIC_ACTIVE0_R          (*((volatile unsigned long *)0xE000E300))
#define NVIC_ACTIVE1_R          (*((volatile unsigned long *)0xE000E304))
#define NVIC_ACTIVE2_R          (*((volatile unsigned long *)0xE000E308))
#define NVIC_ACTIVE3_R          (*((volatile unsigned long *)0xE000E30C))
#define NVIC_ACTIVE4_R          (*((volatile unsigned long *)0xE000E310))
#define NVIC_PRI0_R             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_R             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_R             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_R             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_R             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_R             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_R             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_R             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_R             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_R            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_R            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_R            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_R            (*((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_R            (*((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_R            (*((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_R            (*((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_R            (*((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_R            (*((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_R            (*((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_R            (*((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_R            (*((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_R            (*((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_R            (*((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_R            (*((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_R            (*((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_R            (*((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_R            (*((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_R            (*((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_R            (*((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_R            (*((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_R            (*((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_R            (*((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_R            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_R            (*((volatile unsigned long *)0xE000E488))
#define NVIC_CPUID_R            (*((volatile unsigned long *)0xE000ED00))
#define NVIC_INT_CTRL_R         (*((volatile unsigned long *)0xE000ED04))
#define NVIC_VTABLE_R           (*((volatile unsigned long *)0xE000ED08))
#define NVIC_APINT_R            (*((volatile unsigned long *)0xE000ED0C))
#define NVIC_SYS_CTRL_R         (*((volatile unsigned long *)0xE000ED10))
#define NVIC_CFG_CTRL_R         (*((volatile unsigned long *)0xE000ED14))
#define NVIC_SYS_PRI1_R         (*((volatile unsigned long *)0xE000ED18))
#define NVIC_SYS_PRI2_R         (*((volatile unsigned long *)0xE000ED1C))
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))
#define NVIC_SYS_HND_CTRL_R     (*((volatile unsigned long *)0xE000ED24))
#define NVIC_FAULT_STAT_R       (*((volatile unsigned long *)0xE000ED28))
#define NVIC_HFAULT_STAT_R      (*((volatile unsigned long *)0xE000ED2C))
#define NVIC_DEBUG_STAT_R       (*((volatile unsigned long *)0xE000ED30))
#define NVIC_MM_ADDR_R          (*((volatile unsigned long *)0xE000ED34))
#define NVIC_FAULT_ADDR_R       (*((volatile unsigned long *)0xE000ED38))
#define NVIC_CPAC_R             (*((volatile unsigned long *)0xE000ED88))
#define NVIC_MPU_TYPE_R         (*((volatile unsigned long *)0xE000ED90))
#define NVIC_MPU_CTRL_R         (*((volatile unsigned long *)0xE000ED94))
#define NVIC_MPU_NUMBER_R       (*((volatile unsigned long *)0xE000ED98))
#define NVIC_MPU_BASE_R         (*((volatile unsigned long *)0xE000ED9C))
#define NVIC_MPU_ATTR_R         (*((volatile unsigned long *)0xE000EDA0))
#define NVIC_MPU_BASE1_R        (*((volatile unsigned long *)0xE000EDA4))
#define NVIC_MPU_ATTR1_R        (*((volatile unsigned long *)0xE000EDA8))
#define NVIC_MPU_BASE2_R        (*((volatile unsigned long *)0xE000EDAC))
#define NVIC_MPU_ATTR2_R        (*((volatile unsigned long *)0xE000EDB0))
#define NVIC_MPU_BASE3_R        (*((volatile unsigned long *)0xE000EDB4))
#define NVIC_MPU_ATTR3_R        (*((volatile unsigned long *)0xE000EDB8))
#define NVIC_DBG_CTRL_R         (*((volatile unsigned long *)0xE000EDF0))
#define NVIC_DBG_XFER_R         (*((volatile unsigned long *)0xE000EDF4))
#define NVIC_DBG_DATA_R         (*((volatile unsigned long *)0xE000EDF8))
#define NVIC_DBG_INT_R          (*((volatile unsigned long *)0xE000EDFC))
#define NVIC_SW_TRIG_R          (*((volatile unsigned long *)0xE000EF00))
#define NVIC_FPCC_R             (*((volatile unsigned long *)0xE000EF34))
#define NVIC_FPCA_R             (*((volatile unsigned long *)0xE000EF38))
#define NVIC_FPDSC_R            (*((volatile unsigned long *)0xE000EF3C))

//*****************************************************************************
//
// System Timer registers (SysTick)
//
//*****************************************************************************
#define SYSTICK_STCTRL_R       (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_STRELOAD_R     (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_STCURRENT_R    (*((volatile unsigned long *)0xE000E018))


//*****************************************************************************
//
// Timers registers (TIMER)
//
//*****************************************************************************
typedef struct{
  vuint32 GPTMCFG;                      // GPTM Configuration
  vuint32 GPTMTAMR;                     // GPTM Timer A Mode
  vuint32 GPTMTBMR;                     // GPTM Timer B Mode
  vuint32 GPTMCTL;                      // GPTM Control
  vuint32 GPTMSYNC;                     // GPTM Synchronize
  vuint32 reserved;                     // Reserved
  vuint32 GPTMIMR;                      // GPTM Interrupt Mask
  vuint32 GPTMRIS;                      // GPTM Raw Interrupt Status
  vuint32 GPTMMIS;                      // GPTM Masked Interrupt Status
  vuint32 GPTMICR;                      // GPTM Interrupt Clear
  vuint32 GPTMTAILR;                    // GPTM Timer A Interval Load
  vuint32 GPTMTBILR;                    // GPTM Timer B Interval Load
  vuint32 GPTMTAMATCHR;                 // GPTM Timer A Match
  vuint32 GPTMTBMATCHR;                 // GPTM Timer B Match
  vuint32 GPTMTAPR;                     // GPTM Timer A Prescale
  vuint32 GPTMTBPR;                     // GPTM Timer B Prescale
  vuint32 GPTMTAPMR;                    // GPTM TimerA Prescale Match
  vuint32 GPTMTBPMR;                    // GPTM TimerB Prescale Match
  vuint32 GPTMTAR;                      // GPTM Timer A
  vuint32 GPTMTBR;                      // GPTM Timer B
  vuint32 GPTMTAV;                      // GPTM Timer A Value
  vuint32 GPTMTBV;                      // GPTM Timer B Value
  vuint32 GPTMRTCPD;                    // GPTM RTC Predivide
  vuint32 GPTMTAPS;                     // GPTM Timer A Prescale Snapshot
  vuint32 GPTMTBPS;                     // GPTM Timer B Prescale Snapshot
  vuint32 GPTMTAPV;                     // GPTM Timer A Prescale Value
  vuint32 GPTMTBPV;                     // GPTM Timer B Prescale Value
}timer_typedef;


#define TIMER0_BASE                                     0x40030000UL
#define TIMER1_BASE                                     0x40031000UL
#define TIMER2_BASE                                     0x40032000UL
#define TIMER3_BASE                                     0x40033000UL
#define TIMER4_BASE                                     0x40034000UL
#define TIMER5_BASE                                     0x40035000UL
#define WTIMER0_BASE                                    0x40036000UL
#define WTIMER1_BASE                                    0x40037000UL
#define WTIMER2_BASE                                    0x4004C000UL
#define WTIMER3_BASE                                    0x4004D000UL
#define WTIMER4_BASE                                    0x4004E000UL
#define WTIMER5_BASE                                    0x4004F000UL


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-
#define TIMER0                                          ((timer_typedef *) TIMER0_BASE)
#define TIMER1                                          ((timer_typedef *) TIMER1_BASE)
#define TIMER2                                          ((timer_typedef *) TIMER2_BASE)
#define TIMER3                                          ((timer_typedef *) TIMER3_BASE)
#define TIMER4                                          ((timer_typedef *) TIMER4_BASE)
#define TIMER5                                          ((timer_typedef *) TIMER5_BASE)
#define WTIMER0                                         ((timer_typedef *) WTIMER0_BASE)
#define WTIMER1                                         ((timer_typedef *) WTIMER1_BASE)
#define WTIMER2                                         ((timer_typedef *) WTIMER2_BASE)
#define WTIMER3                                         ((timer_typedef *) WTIMER3_BASE)
#define WTIMER4                                         ((timer_typedef *) WTIMER4_BASE)
#define WTIMER5                                         ((timer_typedef *) WTIMER5_BASE)


//*****************************************************************************
//
// UART registers (UART0)
//
//*****************************************************************************
#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))
#define UART0_RSR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_ECR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_ILPR_R            (*((volatile unsigned long *)0x4000C020))
#define UART0_IBRD_R            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_R            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH_R            (*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))
#define UART0_IFLS_R            (*((volatile unsigned long *)0x4000C034))
#define UART0_IM_R              (*((volatile unsigned long *)0x4000C038))
#define UART0_RIS_R             (*((volatile unsigned long *)0x4000C03C))
#define UART0_MIS_R             (*((volatile unsigned long *)0x4000C040))
#define UART0_ICR_R             (*((volatile unsigned long *)0x4000C044))
#define UART0_DMACTL_R          (*((volatile unsigned long *)0x4000C048))
#define UART0_9BITADDR_R        (*((volatile unsigned long *)0x4000C0A4))
#define UART0_9BITAMASK_R       (*((volatile unsigned long *)0x4000C0A8))
#define UART0_PP_R              (*((volatile unsigned long *)0x4000CFC0))
#define UART0_CC_R              (*((volatile unsigned long *)0x4000CFC8))







#endif /* _CORTEXM4_H_ */