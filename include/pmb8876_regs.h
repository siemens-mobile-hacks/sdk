#pragma once

// GPIO numbers
#define	GPIO_KP_IN0		0
#define	GPIO_KP_IN1		1
#define	GPIO_KP_IN2		2
#define	GPIO_KP_IN3		3
#define	GPIO_KP_IN4		4
#define	GPIO_KP_IN5		5
#define	GPIO_KP_IN6		6
#define	GPIO_KP_OUT0	7
#define	GPIO_KP_OUT1	8
#define	GPIO_KP_OUT2	9
#define	GPIO_KP_OUT3	10
#define	GPIO_USART0_RXD	11
#define	GPIO_USART0_TXD	12
#define	GPIO_USART0_RTS	13
#define	GPIO_USART0_CTS	14
#define	GPIO_DSPOUT0	15
#define	GPIO_USART1_RXD	16
#define	GPIO_USART1_TXD	17
#define	GPIO_USART1_RTS	18
#define	GPIO_USART1_CTS	19
#define	GPIO_USB_DPLUS	20
#define	GPIO_USB_DMINUS	21
#define	GPIO_PIN22		22
#define	GPIO_DIF_D2		23
#define	GPIO_DIF_D0		24
#define	GPIO_DIF_CD		25
#define	GPIO_DIF_CS1	26
#define	GPIO_DIF_RESET1	27
#define	GPIO_I2C_SCL	28
#define	GPIO_I2C_SDA	29
#define	GPIO_DIF_D1		30
#define	GPIO_PIN31		31
#define	GPIO_PIN32		32
#define	GPIO_PIN33		33
#define	GPIO_PIN34		34
#define	GPIO_PIN35		35
#define	GPIO_PIN36		36
#define	GPIO_PIN37		37
#define	GPIO_PIN38		38
#define	GPIO_DIF_HD		39
#define	GPIO_PIN40		40
#define	GPIO_PIN41		41
#define	GPIO_PIN42		42
#define	GPIO_T_OUT0		43
#define	GPIO_T_OUT1		44
#define	GPIO_T_OUT2		45
#define	GPIO_T_OUT3		46
#define	GPIO_T_OUT4		47
#define	GPIO_T_OUT5		48
#define	GPIO_T_OUT6		49
#define	GPIO_T_OUT7		50
#define	GPIO_T_OUT8		51
#define	GPIO_T_OUT9		52
#define	GPIO_T_OUT10	53
#define	GPIO_T_OUT11	54
#define	GPIO_T_OUT12	55
#define	GPIO_RF_STR0	56
#define	GPIO_RF_STR1	57
#define	GPIO_CLKOUT0	58
#define	GPIO_RF_CLK		59
#define	GPIO_PIN60		60
#define	GPIO_PIN61		61
#define	GPIO_DSPOUT1	62
#define	GPIO_DSPIN1		63
#define	GPIO_PIN64		64
#define	GPIO_PIN65		65
#define	GPIO_PIPESTAT2	66
#define	GPIO_PIPESTAT1	67
#define	GPIO_PIPESTAT0	68
#define	GPIO_TRACEPKT0	69
#define	GPIO_TRACEPKT1	70
#define	GPIO_TRACEPKT2	71
#define	GPIO_TRACEPKT3	72
#define	GPIO_PIN73		73
#define	GPIO_PIN74		74
#define	GPIO_PIN75		75
#define	GPIO_PIN76		76
#define	GPIO_FCDP_RB	77
#define	GPIO_CIF_D0		78
#define	GPIO_CIF_D1		79
#define	GPIO_CIF_D2		80
#define	GPIO_CIF_D3		81
#define	GPIO_CIF_D4		82
#define	GPIO_CIF_D5		83
#define	GPIO_CIF_D6		84
#define	GPIO_CIF_D7		85
#define	GPIO_CIF_PCLK	86
#define	GPIO_CIF_HSYNC	87
#define	GPIO_CIF_VSYNC	88
#define	GPIO_CLKOUT2	89
#define	GPIO_PIN90		90
#define	GPIO_DIF_D3		91
#define	GPIO_DIF_D4		92
#define	GPIO_DIF_D5		93
#define	GPIO_DIF_D6		94
#define	GPIO_DIF_D7		95
#define	GPIO_PIN96		96
#define	GPIO_DIF_WR		97
#define	GPIO_DIF_RD		98
#define	GPIO_MMCI_DAT1	99
#define	GPIO_DIF_VD		100
#define	GPIO_PIN101		101
#define	GPIO_PIN102		102
#define	GPIO_PIN103		103
#define	GPIO_MMCI_CMD	104
#define	GPIO_MMCI_DAT0	105
#define	GPIO_MMCI_CLK	106
#define	GPIO_PIN107		107
#define	GPIO_PIN108		108
#define	GPIO_PIN109		109
#define	GPIO_PIN110		110
#define	GPIO_PIN111		111
#define	GPIO_I2S1_CLK1	112
#define	GPIO_CIF_PD		113


// IRQ numbers
#define	NVIC_USART0_TX_IRQ		4
#define	NVIC_USART0_TBUF_IRQ	5
#define	NVIC_USART0_RX_IRQ		6
#define	NVIC_USART0_ERR_IRQ		7
#define	NVIC_USART0_CTS_IRQ		8
#define	NVIC_USART0_ABDET_IRQ	9
#define	NVIC_USART0_ABSTART_IRQ	10
#define	NVIC_USART0_TMO_IRQ		11
#define	NVIC_SIM_UNK0_IRQ		22
#define	NVIC_SIM_UNK1_IRQ		23
#define	NVIC_SIM_UNK2_IRQ		24
#define	NVIC_USB_IRQ			25
#define	NVIC_USART1_TX_IRQ		26
#define	NVIC_USART1_TBUF_IRQ	27
#define	NVIC_USART1_RX_IRQ		28
#define	NVIC_USART1_ERR_IRQ		29
#define	NVIC_USART1_CTS_IRQ		30
#define	NVIC_USART1_ABDET_IRQ	31
#define	NVIC_USART1_ABSTART_IRQ	32
#define	NVIC_USART1_TMO_IRQ		33
#define	NVIC_DMAC_ERR_IRQ		35
#define	NVIC_DMAC_CH0_IRQ		36
#define	NVIC_DMAC_CH1_IRQ		37
#define	NVIC_DMAC_CH2_IRQ		38
#define	NVIC_DMAC_CH3_IRQ		39
#define	NVIC_DMAC_CH4_IRQ		40
#define	NVIC_DMAC_CH5_IRQ		41
#define	NVIC_DMAC_CH6_IRQ		42
#define	NVIC_DMAC_CH7_IRQ		43
#define	NVIC_RTC_IRQ			46
#define	NVIC_SCU_EXTI0_IRQ		48
#define	NVIC_SCU_EXTI1_IRQ		49
#define	NVIC_SCU_EXTI2_IRQ		50
#define	NVIC_SCU_EXTI3_IRQ		51
#define	NVIC_SCU_EXTI4_IRQ		52
#define	NVIC_SCU_DSP0_IRQ		53
#define	NVIC_SCU_DSP1_IRQ		54
#define	NVIC_SCU_DSP2_IRQ		55
#define	NVIC_SCU_DSP3_IRQ		56
#define	NVIC_SCU_DSP4_IRQ		57
#define	NVIC_SCU_UNK0_IRQ		58
#define	NVIC_SCU_UNK1_IRQ		59
#define	NVIC_SCU_UNK2_IRQ		60
#define	NVIC_SCU_EXTI5_IRQ		61
#define	NVIC_SCU_EXTI6_IRQ		62
#define	NVIC_SCCU_UNK_IRQ		63
#define	NVIC_SCU_EXTI7_IRQ		63
#define	NVIC_SCCU_WAKE_IRQ		64
#define	NVIC_PLL_IRQ			65
#define	NVIC_ADC_INT0_IRQ		70
#define	NVIC_ADC_INT1_IRQ		71
#define	NVIC_CAPCOM0_T0_IRQ		72
#define	NVIC_CAPCOM0_T1_IRQ		73
#define	NVIC_CAPCOM0_CC0_IRQ	74
#define	NVIC_CAPCOM0_CC1_IRQ	75
#define	NVIC_CAPCOM0_CC2_IRQ	76
#define	NVIC_CAPCOM0_CC3_IRQ	77
#define	NVIC_CAPCOM0_CC4_IRQ	78
#define	NVIC_CAPCOM0_CC5_IRQ	79
#define	NVIC_CAPCOM0_CC6_IRQ	80
#define	NVIC_CAPCOM0_CC7_IRQ	81
#define	NVIC_CAPCOM1_T0_IRQ		82
#define	NVIC_CAPCOM1_T1_IRQ		83
#define	NVIC_CAPCOM1_CC0_IRQ	84
#define	NVIC_CAPCOM1_CC1_IRQ	85
#define	NVIC_CAPCOM1_CC2_IRQ	86
#define	NVIC_CAPCOM1_CC3_IRQ	87
#define	NVIC_CAPCOM1_CC4_IRQ	88
#define	NVIC_CAPCOM1_CC5_IRQ	89
#define	NVIC_CAPCOM1_CC6_IRQ	90
#define	NVIC_CAPCOM1_CC7_IRQ	91
#define	NVIC_GPTU0_SRC0_IRQ		92
#define	NVIC_GPTU0_SRC1_IRQ		93
#define	NVIC_GPTU0_SRC2_IRQ		94
#define	NVIC_GPTU0_SRC3_IRQ		95
#define	NVIC_GPTU0_SRC4_IRQ		96
#define	NVIC_GPTU0_SRC5_IRQ		97
#define	NVIC_GPTU0_SRC6_IRQ		98
#define	NVIC_GPTU0_SRC7_IRQ		99
#define	NVIC_GPTU1_SRC0_IRQ		100
#define	NVIC_GPTU1_SRC1_IRQ		101
#define	NVIC_GPTU1_SRC2_IRQ		102
#define	NVIC_GPTU1_SRC3_IRQ		103
#define	NVIC_GPTU1_SRC4_IRQ		104
#define	NVIC_GPTU1_SRC5_IRQ		105
#define	NVIC_GPTU1_SRC6_IRQ		106
#define	NVIC_GPTU1_SRC7_IRQ		107
#define	NVIC_KEYPAD_PRESS_IRQ	108
#define	NVIC_KEYPAD_UNK0_IRQ	109
#define	NVIC_KEYPAD_UNK1_IRQ	110
#define	NVIC_KEYPAD_RELEASE_IRQ	111
#define	NVIC_TPU_INT_UNK0_IRQ	113
#define	NVIC_TPU_INT_UNK1_IRQ	114
#define	NVIC_TPU_INT_UNK2_IRQ	115
#define	NVIC_TPU_INT_UNK3_IRQ	116
#define	NVIC_TPU_INT_UNK4_IRQ	117
#define	NVIC_TPU_INT_UNK5_IRQ	118
#define	NVIC_TPU_INT0_IRQ		119
#define	NVIC_TPU_INT1_IRQ		120
#define	NVIC_GPRSCU_INT0_IRQ	121
#define	NVIC_GPRSCU_INT1_IRQ	122
#define	NVIC_DIF_INT0_IRQ		134
#define	NVIC_DIF_INT1_IRQ		135
#define	NVIC_DIF_INT2_IRQ		136
#define	NVIC_DIF_INT3_IRQ		137
#define	NVIC_CIF_UNK0_IRQ		138
#define	NVIC_CIF_UNK1_IRQ		139
#define	NVIC_CIF_UNK2_IRQ		140
#define	NVIC_MCI_IRQ			148
#define	NVIC_I2C_SINGLE_REQ_IRQ	155
#define	NVIC_I2C_BURST_REQ_IRQ	156
#define	NVIC_I2C_ERROR_IRQ		157
#define	NVIC_I2C_PROTOCOL_IRQ	158


// Common regs for all modules
/* Clock Control Register */
#define	MOD_CLC_DISR						BIT(0)			 // Module Disable Request Bit
#define	MOD_CLC_DISS						BIT(1)			 // Module Disable Status Bit
#define	MOD_CLC_SPEN						BIT(2)			 // Module Suspend Enable Bit
#define	MOD_CLC_EDIS						BIT(3)			 // Module External Request Disable
#define	MOD_CLC_SBWE						BIT(4)			 // Module Suspend Bit Write Enable
#define	MOD_CLC_FSOE						BIT(5)			 // Module Fast Shut-Off Enable.
#define	MOD_CLC_RMC							GENMASK(15, 8)	 // Module Clock Divider for Normal Mode
#define	MOD_CLC_RMC_SHIFT					8

/* Module Identifier Register */
#define	MOD_ID_REV							GENMASK(7, 0)
#define	MOD_ID_REV_SHIFT					0
#define	MOD_ID_32B							GENMASK(15, 8)
#define	MOD_ID_32B_SHIFT					8
#define	MOD_ID_NUMBER						GENMASK(31, 16)
#define	MOD_ID_NUMBER_SHIFT					16

/* Service Routing Control Register */
#define	MOD_SRC_SRPN						GENMASK(7, 0)	 // IRQ priority number
#define	MOD_SRC_SRPN_SHIFT					0
#define	MOD_SRC_TOS							GENMASK(11, 10)	 // Type of service for node
#define	MOD_SRC_TOS_SHIFT					10
#define	MOD_SRC_SRE							BIT(12)			 // IRQ enable
#define	MOD_SRC_SRR							BIT(13)			 // IRQ Service Request Bit
#define	MOD_SRC_CLRR						BIT(14)			 // IRQ Request Clear Bit
#define	MOD_SRC_SETR						BIT(15)			 // IRQ Request Set Bit

#define	AMBA_PERIPH_ID0_PARTNUMBER0			GENMASK(7, 0)
#define	AMBA_PERIPH_ID0_PARTNUMBER0_SHIFT	0

#define	AMBA_PERIPH_ID1_PARTNUMBER1			GENMASK(3, 0)
#define	AMBA_PERIPH_ID1_PARTNUMBER1_SHIFT	0
#define	AMBA_PERIPH_ID1_DESIGNER0			GENMASK(11, 4)
#define	AMBA_PERIPH_ID1_DESIGNER0_SHIFT		4

#define	AMBA_PERIPH_ID2_DESIGNER1			GENMASK(3, 0)
#define	AMBA_PERIPH_ID2_DESIGNER1_SHIFT		0
#define	AMBA_PERIPH_ID2_REVISION			GENMASK(11, 4)
#define	AMBA_PERIPH_ID2_REVISION_SHIFT		4

#define	AMBA_PERIPH_ID3_CONFIGURATION		GENMASK(7, 0)
#define	AMBA_PERIPH_ID3_CONFIGURATION_SHIFT	0



// EBU [MOD_NUM=0014, MOD_REV=00, MOD_32BIT=C0]
// EBU from XMC4500 official public datasheet
#define	EBU_BASE					0xF0000000
/* Clock Control Register */
#define	EBU_CLC						MMIO32(EBU_BASE + 0x00)

/* Module Identifier Register */
#define	EBU_ID						MMIO32(EBU_BASE + 0x08)

#define	EBU_CON						MMIO32(EBU_BASE + 0x10)
#define	EBU_CON_EXTRECON			BIT(1)									 // External reconfiguration
#define	EBU_CON_EXTSVM				BIT(2)									 // Perform master in
#define	EBU_CON_EXTACC				BIT(3)									 // External access FPI-bus
#define	EBU_CON_EXTLOCK				BIT(4)									 // Lock external bus
#define	EBU_CON_ARBSYNC				BIT(5)									 // Arbitration evaluation
#define	EBU_CON_ARBMODE				GENMASK(7, 6)							 // Arbitration mode
#define	EBU_CON_ARBMODE_SHIFT		6
#define	EBU_CON_TOUTC				GENMASK(15, 8)							 // Time-out control
#define	EBU_CON_TOUTC_SHIFT			8
#define	EBU_CON_GLOBALCS			GENMASK(23, 16)							 // Global chip select signal
#define	EBU_CON_GLOBALCS_SHIFT		16
#define	EBU_CON_BUSCLK				GENMASK(25, 24)							 // Clock generation
#define	EBU_CON_BUSCLK_SHIFT		24
#define	EBU_CON_SDCMSEL				BIT(26)									 // SDRAM Clock Mode Select
#define	EBU_CON_CS0FAM				BIT(27)									 // CS0 Fills Address Map
#define	EBU_CON_EMUFAM				BIT(28)									 // CSEMU Fills Address Map
#define	EBU_CON_BFSSS				BIT(29)									 // Burst FLASH Single Stage Synchronization

#define	EBU_BFCON					MMIO32(EBU_BASE + 0x20)
#define	EBU_BFCON_FETBLEN0			GENMASK(3, 0)							 // Fetch Burst Length for Burst FLASH Type 0
#define	EBU_BFCON_FETBLEN0_SHIFT	0
#define	EBU_BFCON_FBBMSEL0			BIT(4)									 // FLASH Burst Buffer Mode Select for Burst FLASH Type 0
#define	EBU_BFCON_WAITFUNC0			BIT(5)									 // Function of WAIT Input for Burst FLASH Type 0
#define	EBU_BFCON_EXTCLOCK			GENMASK(7, 6)							 // Frequency of external clock
#define	EBU_BFCON_EXTCLOCK_SHIFT	6
#define	EBU_BFCON_BFCMSEL			BIT(8)									 // Burst FLASH Clock Mode Select
#define	EBU_BFCON_EBSE0				BIT(9)									 // Early Burst Signal Enable for Burst FLASH Type 0
#define	EBU_BFCON_DBA0				BIT(10)									 // Disable Burst Address Wrapping
#define	EBU_BFCON_FDBKEN			BIT(11)									 // Burst FLASH Clock Feedback Enable
#define	EBU_BFCON_DTALTNCY			GENMASK(15, 12)							 // Latency Cycle Control
#define	EBU_BFCON_DTALTNCY_SHIFT	12
#define	EBU_BFCON_FETBLEN1			GENMASK(19, 16)							 // Fetch Burst Length for Burst FLASH Type 1
#define	EBU_BFCON_FETBLEN1_SHIFT	16
#define	EBU_BFCON_FBBMSEL1			BIT(20)									 // FLASH Burst Buffer Mode Select for Burst FLASH Type 1
#define	EBU_BFCON_WAITFUNC1			BIT(21)									 // Function of WAIT Input for Burst FLASH Type 1
#define	EBU_BFCON_DBA1				BIT(23)									 // Disable Burst Address Wrapping
#define	EBU_BFCON_EBSE1				BIT(25)									 // Early Burst Signal Enable for Burst FLASH Type 1

#define	EBU_SDRMREF(n)				MMIO32(EBU_BASE + 0x40 + ((n) * 0x8))
#define	EBU_SDRMREF_REFRESHC		GENMASK(5, 0)							 // Refresh counter period
#define	EBU_SDRMREF_REFRESHC_SHIFT	0
#define	EBU_SDRMREF_REFRESHR		GENMASK(8, 6)							 // Number of refresh commands
#define	EBU_SDRMREF_REFRESHR_SHIFT	6
#define	EBU_SDRMREF_SELFREXST		BIT(9)									 // Self refresh exit status
#define	EBU_SDRMREF_SELFREX			BIT(10)									 // Self refresh exit
#define	EBU_SDRMREF_SELFRENST		BIT(11)									 // Self refresh entry status
#define	EBU_SDRMREF_SELFREN			BIT(12)									 // Self refresh entry
#define	EBU_SDRMREF_AUTOSELFR		BIT(13)									 // Automatic self refresh

#define	EBU_SDRMCON(n)				MMIO32(EBU_BASE + 0x50 + ((n) * 0x8))
#define	EBU_SDRMCON_CRAS			GENMASK(3, 0)							 // Row to precharge delay counter
#define	EBU_SDRMCON_CRAS_SHIFT		0
#define	EBU_SDRMCON_CRFSH			GENMASK(7, 4)							 // Refresh commands counter
#define	EBU_SDRMCON_CRFSH_SHIFT		4
#define	EBU_SDRMCON_CRSC			GENMASK(9, 8)							 // Mode register setup time
#define	EBU_SDRMCON_CRSC_SHIFT		8
#define	EBU_SDRMCON_CRP				GENMASK(11, 10)							 // Row precharge time counter
#define	EBU_SDRMCON_CRP_SHIFT		10
#define	EBU_SDRMCON_AWIDTH			GENMASK(13, 12)							 // Width of column address
#define	EBU_SDRMCON_AWIDTH_SHIFT	12
#define	EBU_SDRMCON_CRCD			GENMASK(15, 14)							 // Row to column delay counter
#define	EBU_SDRMCON_CRCD_SHIFT		14
#define	EBU_SDRMCON_CRC				GENMASK(18, 16)							 // Row cycle time counter
#define	EBU_SDRMCON_CRC_SHIFT		16
#define	EBU_SDRMCON_PAGEM			GENMASK(21, 19)							 // Mask for page tag
#define	EBU_SDRMCON_PAGEM_SHIFT		19
#define	EBU_SDRMCON_BANKM			GENMASK(24, 22)							 // Mask for bank tag
#define	EBU_SDRMCON_BANKM_SHIFT		22

#define	EBU_SDRMOD(n)				MMIO32(EBU_BASE + 0x60 + ((n) * 0x8))
#define	EBU_SDRMOD_BURSTL			GENMASK(2, 0)							 // Burst length
#define	EBU_SDRMOD_BURSTL_SHIFT		0
#define	EBU_SDRMOD_BTYP				BIT(3)									 // Burst type
#define	EBU_SDRMOD_CASLAT			GENMASK(6, 4)							 // CAS latency
#define	EBU_SDRMOD_CASLAT_SHIFT		4
#define	EBU_SDRMOD_OPMODE			GENMASK(13, 7)							 // Operation Mode
#define	EBU_SDRMOD_OPMODE_SHIFT		7

#define	EBU_SDRSTAT(n)				MMIO32(EBU_BASE + 0x70 + ((n) * 0x8))
#define	EBU_SDRSTAT_REFERR			BIT(0)									 // SDRAM Refresh Error
#define	EBU_SDRSTAT_SDRM_BUSY		BIT(1)									 // SDRAM Busy

#define	EBU_ADDRSEL(n)				MMIO32(EBU_BASE + 0x80 + ((n) * 0x8))
#define	EBU_ADDRSEL_REGENAB			BIT(0)									 // Memory Region
#define	EBU_ADDRSEL_ALTENAB			BIT(1)									 // Alternate Segment Comparison
#define	EBU_ADDRSEL_MASK			GENMASK(7, 4)							 // Address Mask
#define	EBU_ADDRSEL_MASK_SHIFT		4
#define	EBU_ADDRSEL_ALTSEG			GENMASK(11, 8)							 // Alternate Segment
#define	EBU_ADDRSEL_ALTSEG_SHIFT	8
#define	EBU_ADDRSEL_BASE			GENMASK(31, 12)							 // Base Address
#define	EBU_ADDRSEL_BASE_SHIFT		12

#define	EBU_BUSCON(n)				MMIO32(EBU_BASE + 0xC0 + ((n) * 0x8))
#define	EBU_BUSCON_MULTMAP			GENMASK(6, 0)							 // Multiplier map
#define	EBU_BUSCON_MULTMAP_SHIFT	0
#define	EBU_BUSCON_WPRE				BIT(8)									 // Weak prefetch
#define	EBU_BUSCON_AALIGN			BIT(9)									 // Address alignment
#define	EBU_BUSCON_CTYPE			GENMASK(11, 10)							 // Cycle Type
#define	EBU_BUSCON_CTYPE_SHIFT		10
#define	EBU_BUSCON_CMULT			GENMASK(15, 13)							 // Cycle multiplier
#define	EBU_BUSCON_CMULT_SHIFT		13
#define	EBU_BUSCON_ENDIAN			BIT(16)									 // Endian mode
#define	EBU_BUSCON_DLOAD			BIT(17)									 // Data upload
#define	EBU_BUSCON_PRE				BIT(18)									 // Prefetch mechanism
#define	EBU_BUSCON_WAITINV			BIT(19)									 // Reversed polarity at WAIT
#define	EBU_BUSCON_BCGEN			GENMASK(21, 20)							 // Signal timing mode
#define	EBU_BUSCON_BCGEN_SHIFT		20
#define	EBU_BUSCON_PORTW			GENMASK(23, 22)							 // Port width
#define	EBU_BUSCON_PORTW_SHIFT		22
#define	EBU_BUSCON_WAIT				GENMASK(25, 24)							 // External wait state
#define	EBU_BUSCON_WAIT_SHIFT		24
#define	EBU_BUSCON_XCMDDELAY		GENMASK(27, 26)							 // External command delay
#define	EBU_BUSCON_XCMDDELAY_SHIFT	26
#define	EBU_BUSCON_AGEN				GENMASK(30, 28)							 // Address generation
#define	EBU_BUSCON_AGEN_SHIFT		28
#define	EBU_BUSCON_WRITE			BIT(31)									 // Write protection

#define	EBU_BUSAP(n)				MMIO32(EBU_BASE + 0x100 + ((n) * 0x8))
#define	EBU_BUSAP_DTACS				GENMASK(3, 0)							 // Between different regions
#define	EBU_BUSAP_DTACS_SHIFT		0
#define	EBU_BUSAP_DTARDWR			GENMASK(7, 4)							 // Between read and write accesses
#define	EBU_BUSAP_DTARDWR_SHIFT		4
#define	EBU_BUSAP_WRRECOVC			GENMASK(10, 8)							 // After write accesses
#define	EBU_BUSAP_WRRECOVC_SHIFT	8
#define	EBU_BUSAP_RDRECOVC			GENMASK(13, 11)							 // After read accesses
#define	EBU_BUSAP_RDRECOVC_SHIFT	11
#define	EBU_BUSAP_DATAC				GENMASK(15, 14)							 // Write accesses
#define	EBU_BUSAP_DATAC_SHIFT		14
#define	EBU_BUSAP_BURSTC			GENMASK(18, 16)							 // During burst accesses
#define	EBU_BUSAP_BURSTC_SHIFT		16
#define	EBU_BUSAP_WAITWRC			GENMASK(21, 19)							 // Programmed for wait accesses
#define	EBU_BUSAP_WAITWRC_SHIFT		19
#define	EBU_BUSAP_WAITRDC			GENMASK(24, 22)							 // Programmed for read accesses
#define	EBU_BUSAP_WAITRDC_SHIFT		22
#define	EBU_BUSAP_CMDDELAY			GENMASK(27, 25)							 // Programmed command
#define	EBU_BUSAP_CMDDELAY_SHIFT	25
#define	EBU_BUSAP_AHOLDC			GENMASK(29, 28)							 // Multiplexed accesses
#define	EBU_BUSAP_AHOLDC_SHIFT		28
#define	EBU_BUSAP_ADDRC				GENMASK(31, 30)							 // Address Cycles
#define	EBU_BUSAP_ADDRC_SHIFT		30

#define	EBU_EMUAS					MMIO32(EBU_BASE + 0x160)
#define	EBU_EMUAS_REGENAB			BIT(0)									 // Memory region
#define	EBU_EMUAS_ALTENAB			BIT(1)									 // Alternate segment comparison
#define	EBU_EMUAS_MASK				GENMASK(7, 4)							 // Address mask
#define	EBU_EMUAS_MASK_SHIFT		4
#define	EBU_EMUAS_ALTSEG			GENMASK(11, 8)							 // Alternate segment
#define	EBU_EMUAS_ALTSEG_SHIFT		8
#define	EBU_EMUAS_BASE				GENMASK(31, 12)							 // Base address
#define	EBU_EMUAS_BASE_SHIFT		12

#define	EBU_EMUBC					MMIO32(EBU_BASE + 0x168)
#define	EBU_EMUBC_MULTMAP			GENMASK(6, 0)							 // Multiplier map
#define	EBU_EMUBC_MULTMAP_SHIFT		0
#define	EBU_EMUBC_WPRE				BIT(8)									 // Weak prefetch
#define	EBU_EMUBC_AALIGN			BIT(9)									 // Address alignment
#define	EBU_EMUBC_CTYPE				GENMASK(11, 10)							 // Cycle Type
#define	EBU_EMUBC_CTYPE_SHIFT		10
#define	EBU_EMUBC_CMULT				GENMASK(15, 13)							 // Cycle multiplier
#define	EBU_EMUBC_CMULT_SHIFT		13
#define	EBU_EMUBC_ENDIAN			BIT(16)									 // Endian mode
#define	EBU_EMUBC_DLOAD				BIT(17)									 // Data upload
#define	EBU_EMUBC_PRE				BIT(18)									 // Prefetch mechanism
#define	EBU_EMUBC_WAITINV			BIT(19)									 // Reversed polarity at WAIT
#define	EBU_EMUBC_BCGEN				GENMASK(21, 20)							 // Signal timing mode
#define	EBU_EMUBC_BCGEN_SHIFT		20
#define	EBU_EMUBC_PORTW				GENMASK(23, 22)							 // Port width
#define	EBU_EMUBC_PORTW_SHIFT		22
#define	EBU_EMUBC_WAIT				GENMASK(25, 24)							 // External wait state
#define	EBU_EMUBC_WAIT_SHIFT		24
#define	EBU_EMUBC_XCMDDELAY			GENMASK(27, 26)							 // External command delay
#define	EBU_EMUBC_XCMDDELAY_SHIFT	26
#define	EBU_EMUBC_AGEN				GENMASK(30, 28)							 // Address generation
#define	EBU_EMUBC_AGEN_SHIFT		28
#define	EBU_EMUBC_WRITE				BIT(31)									 // Write protection

#define	EBU_EMUBAP					MMIO32(EBU_BASE + 0x170)
#define	EBU_EMUBAP_DTACS			GENMASK(3, 0)							 // Between different regions
#define	EBU_EMUBAP_DTACS_SHIFT		0
#define	EBU_EMUBAP_DTARDWR			GENMASK(7, 4)							 // Between read and write accesses
#define	EBU_EMUBAP_DTARDWR_SHIFT	4
#define	EBU_EMUBAP_WRRECOVC			GENMASK(10, 8)							 // After write accesses
#define	EBU_EMUBAP_WRRECOVC_SHIFT	8
#define	EBU_EMUBAP_RDRECOVC			GENMASK(13, 11)							 // After read accesses
#define	EBU_EMUBAP_RDRECOVC_SHIFT	11
#define	EBU_EMUBAP_DATAC			GENMASK(15, 14)							 // Write accesses
#define	EBU_EMUBAP_DATAC_SHIFT		14
#define	EBU_EMUBAP_BURSTC			GENMASK(18, 16)							 // During burst accesses
#define	EBU_EMUBAP_BURSTC_SHIFT		16
#define	EBU_EMUBAP_WAITWRC			GENMASK(21, 19)							 // Programmed for wait accesses
#define	EBU_EMUBAP_WAITWRC_SHIFT	19
#define	EBU_EMUBAP_WAITRDC			GENMASK(24, 22)							 // Programmed for read accesses
#define	EBU_EMUBAP_WAITRDC_SHIFT	22
#define	EBU_EMUBAP_CMDDELAY			GENMASK(27, 25)							 // Programmed command
#define	EBU_EMUBAP_CMDDELAY_SHIFT	25
#define	EBU_EMUBAP_AHOLDC			GENMASK(29, 28)							 // Multiplexed accesses
#define	EBU_EMUBAP_AHOLDC_SHIFT		28
#define	EBU_EMUBAP_ADDRC			GENMASK(31, 30)							 // Address Cycles
#define	EBU_EMUBAP_ADDRC_SHIFT		30

#define	EBU_EMUOVL					MMIO32(EBU_BASE + 0x178)
#define	EBU_EMUOVL_OVERLAY			GENMASK(7, 0)							 // Overlay chip select
#define	EBU_EMUOVL_OVERLAY_SHIFT	0

#define	EBU_USERCON					MMIO32(EBU_BASE + 0x190)


// USART0 [MOD_NUM=0044, MOD_REV=00, MOD_32BIT=00]
// ASC0 from Tricore TC1766 official public datasheet
#define	USART0_BASE						0xF1000000
#define	USART0							0xF1000000

#define	USART1_BASE						0xF1800000
#define	USART1							0xF1800000

/* Clock Control Register */
#define	USART_CLC(base)					MMIO32((base) + 0x00)

#define	USART_PISEL(base)				MMIO32((base) + 0x04)

/* Module Identifier Register */
#define	USART_ID(base)					MMIO32((base) + 0x08)

#define	USART_CON(base)					MMIO32((base) + 0x10)
#define	USART_CON_M						GENMASK(2, 0)			 // ASC Mode Control.
#define	USART_CON_M_SHIFT				0
#define	USART_CON_M_SYNC_8BIT			0x0
#define	USART_CON_M_ASYNC_8BIT			0x1
#define	USART_CON_M_ASYNC_IRDA_8BIT		0x2
#define	USART_CON_M_ASYNC_PARITY_7BIT	0x3
#define	USART_CON_M_ASYNC_9BIT			0x4
#define	USART_CON_M_ASYNC_WAKE_UP_8BIT	0x5
#define	USART_CON_M_ASYNC_PARITY_8BIT	0x7
#define	USART_CON_STP					BIT(3)					 // Number of stop bits (0: 1 stop bit; 1: two stop bits)
#define	USART_CON_STP_ONE				0x0
#define	USART_CON_STP_TWO				0x8
#define	USART_CON_REN					BIT(4)					 // Receiver bit enable (0: disable; 1: enable)
#define	USART_CON_PEN					BIT(5)					 // Parity check enable (0: ignore; 1: check)
#define	USART_CON_FEN					BIT(6)					 // Framing error check (0: ignore; 1: check)
#define	USART_CON_OEN					BIT(7)					 // Overrun check enable (0: ignore; 1: check)
#define	USART_CON_PE					BIT(8)					 // Parity error flag
#define	USART_CON_FE					BIT(9)					 // Framing error flag
#define	USART_CON_OE					BIT(10)					 // Overrun error flag
#define	USART_CON_FDE					BIT(11)					 // Fraction divider enable (0: disable; 1: enable)
#define	USART_CON_ODD					BIT(12)					 // Parity selection (0: even; 1: odd)
#define	USART_CON_BRS					BIT(13)					 // Baudrate selection (0: Pre-scaler /2; 1: Pre-scaler / 3)
#define	USART_CON_LB					BIT(14)					 // Loopback mode (0: disable; 1: enable)
#define	USART_CON_CON_R					BIT(15)					 // Baud rate generator run control (0: disable; 1: enable)

#define	USART_BG(base)					MMIO32((base) + 0x14)

#define	USART_FDV(base)					MMIO32((base) + 0x18)

#define	USART_PMW(base)					MMIO32((base) + 0x1C)
#define	USART_PMW_PW_VALUE				GENMASK(7, 0)			 // IrDA Pulse Width Value
#define	USART_PMW_PW_VALUE_SHIFT		0
#define	USART_PMW_IRPW					BIT(8)					 // IrDA Pulse Width Selection

#define	USART_TXB(base)					MMIO32((base) + 0x20)

#define	USART_RXB(base)					MMIO32((base) + 0x24)

#define	USART_ABCON(base)				MMIO32((base) + 0x30)
#define	USART_ABCON_ABEN				BIT(0)					 // Autobaud detection enable
#define	USART_ABCON_AUREN				BIT(1)					 // Auto control of CON.REN (too complex for here)
#define	USART_ABCON_ABSTEN				BIT(2)					 // Start of autobaud detect interrupt (0: dis; 1: en)
#define	USART_ABCON_ABDETEN				BIT(3)					 // Autobaud detection interrupt enable (0: dis; 1: en)
#define	USART_ABCON_FCDETEN				BIT(4)					 // Fir char of two byte frame detect
#define	USART_ABCON_ABEM_ECHO_DET		BIT(8)					 // Autobaud echo mode enabled during detection
#define	USART_ABCON_ABEM_ECHO_ALWAYS	BIT(9)					 // Autobaud echo mode always enabled
#define	USART_ABCON_TXINV				BIT(10)					 // Transmit invert enable (0: disable; 1: enable)
#define	USART_ABCON_RXINV				BIT(11)					 // Receive invert enable (0: disable; 1: enable)

#define	USART_ABSTAT(base)				MMIO32((base) + 0x34)
#define	USART_ABSTAT_FCSDET				BIT(0)					 // First character with small letter detected
#define	USART_ABSTAT_FCCDET				BIT(1)					 // First character with capital letter detected
#define	USART_ABSTAT_SCSDET				BIT(2)					 // Second character with small letter detected
#define	USART_ABSTAT_SCCDET				BIT(3)					 // Second character with capital letter detected
#define	USART_ABSTAT_DETWAIT			BIT(4)					 // Autobaud detect is waiting

#define	USART_RXFCON(base)				MMIO32((base) + 0x40)
#define	USART_RXFCON_RXFEN				BIT(0)					 // Receive FIFO enable
#define	USART_RXFCON_RXFFLU				BIT(1)					 // Receive FIFO flush
#define	USART_RXFCON_RXTMEN				BIT(2)					 // Receive FIFO transparent mode enable
#define	USART_RXFCON_RXFITL				GENMASK(11, 8)			 // Receive FIFO interrupt trigger level
#define	USART_RXFCON_RXFITL_SHIFT		8

#define	USART_TXFCON(base)				MMIO32((base) + 0x44)
#define	USART_TXFCON_TXFEN				BIT(0)					 // Transmit FIFO enable
#define	USART_TXFCON_TXFFLU				BIT(1)					 // Transmit FIFO flush
#define	USART_TXFCON_TXTMEN				BIT(2)					 // Transmit FIFO transparent mode enable
#define	USART_TXFCON_TXFITL				GENMASK(11, 8)			 // Transmit FIFO interrupt trigger level
#define	USART_TXFCON_TXFITL_SHIFT		8

#define	USART_FSTAT(base)				MMIO32((base) + 0x48)
#define	USART_FSTAT_RXFFL				GENMASK(3, 0)			 // Receive FIFO filling level mask
#define	USART_FSTAT_RXFFL_SHIFT			0
#define	USART_FSTAT_TXFFL				GENMASK(11, 8)			 // Transmit FIFO filling level mask
#define	USART_FSTAT_TXFFL_SHIFT			8

#define	USART_WHBCON(base)				MMIO32((base) + 0x50)
#define	USART_WHBCON_CLRREN				BIT(4)					 // Clear receiver enable bit
#define	USART_WHBCON_SETREN				BIT(5)					 // Set receiver enable bit
#define	USART_WHBCON_CLRPE				BIT(8)					 // Clear parity error flag
#define	USART_WHBCON_CLRFE				BIT(9)					 // Clear framing error flag
#define	USART_WHBCON_CLROE				BIT(10)					 // Clear overrun error flag
#define	USART_WHBCON_SETPE				BIT(11)					 // Set parity error flag
#define	USART_WHBCON_SETFE				BIT(12)					 // Set framing error flag
#define	USART_WHBCON_SETOE				BIT(13)					 // Set overrun error flag

#define	USART_WHBABCON(base)			MMIO32((base) + 0x54)

#define	USART_WHBABSTAT(base)			MMIO32((base) + 0x58)

#define	USART_FCCON(base)				MMIO32((base) + 0x5C)
#define	USART_FCCON_CTSEN				BIT(0)					 // RTS enbled (0: disable; 1: enable)
#define	USART_FCCON_RTSEN				BIT(1)					 // CTS enable (0: disable; 1: enable)
#define	USART_FCCON_RTS					BIT(4)					 // RTS control bit
#define	USART_FCCON_RTS_TRIGGER			GENMASK(13, 8)			 // RTS receive FIFO trigger level
#define	USART_FCCON_RTS_TRIGGER_SHIFT	8

#define	USART_FCSTAT(base)				MMIO32((base) + 0x60)
#define	USART_FCSTAT_CTS				BIT(0)					 // CTS Status (0: inactive; 1: active)
#define	USART_FCSTAT_RTS				BIT(1)					 // RTS Status (0: inactive; 1: active)

#define	USART_IMSC(base)				MMIO32((base) + 0x64)
#define	USART_IMSC_TX					BIT(0)					 // Transmit interrupt mask
#define	USART_IMSC_TB					BIT(1)					 // Transmit buffer interrupt mask
#define	USART_IMSC_RX					BIT(2)					 // Receive interrupt mask
#define	USART_IMSC_ERR					BIT(3)					 // Error interrupt mask
#define	USART_IMSC_CTS					BIT(4)					 // CTS interrupt mask
#define	USART_IMSC_ABDET				BIT(5)					 // Autobaud detected interrupt mask
#define	USART_IMSC_ABSTART				BIT(6)					 // Autobaud start interrupt mask
#define	USART_IMSC_TMO					BIT(7)					 // RX timeout interrupt mask

#define	USART_RIS(base)					MMIO32((base) + 0x68)
#define	USART_RIS_TX					BIT(0)					 // Transmit interrupt mask
#define	USART_RIS_TB					BIT(1)					 // Transmit buffer interrupt mask
#define	USART_RIS_RX					BIT(2)					 // Receive interrupt mask
#define	USART_RIS_ERR					BIT(3)					 // Error interrupt mask
#define	USART_RIS_CTS					BIT(4)					 // CTS interrupt mask
#define	USART_RIS_ABDET					BIT(5)					 // Autobaud detected interrupt mask
#define	USART_RIS_ABSTART				BIT(6)					 // Autobaud start interrupt mask
#define	USART_RIS_TMO					BIT(7)					 // RX timeout interrupt mask

#define	USART_MIS(base)					MMIO32((base) + 0x6C)
#define	USART_MIS_TX					BIT(0)					 // Transmit interrupt mask
#define	USART_MIS_TB					BIT(1)					 // Transmit buffer interrupt mask
#define	USART_MIS_RX					BIT(2)					 // Receive interrupt mask
#define	USART_MIS_ERR					BIT(3)					 // Error interrupt mask
#define	USART_MIS_CTS					BIT(4)					 // CTS interrupt mask
#define	USART_MIS_ABDET					BIT(5)					 // Autobaud detected interrupt mask
#define	USART_MIS_ABSTART				BIT(6)					 // Autobaud start interrupt mask
#define	USART_MIS_TMO					BIT(7)					 // RX timeout interrupt mask

#define	USART_ICR(base)					MMIO32((base) + 0x70)
#define	USART_ICR_TX					BIT(0)					 // Transmit interrupt mask
#define	USART_ICR_TB					BIT(1)					 // Transmit buffer interrupt mask
#define	USART_ICR_RX					BIT(2)					 // Receive interrupt mask
#define	USART_ICR_ERR					BIT(3)					 // Error interrupt mask
#define	USART_ICR_CTS					BIT(4)					 // CTS interrupt mask
#define	USART_ICR_ABDET					BIT(5)					 // Autobaud detected interrupt mask
#define	USART_ICR_ABSTART				BIT(6)					 // Autobaud start interrupt mask
#define	USART_ICR_TMO					BIT(7)					 // RX timeout interrupt mask

#define	USART_ISR(base)					MMIO32((base) + 0x74)
#define	USART_ISR_TX					BIT(0)					 // Transmit interrupt mask
#define	USART_ISR_TB					BIT(1)					 // Transmit buffer interrupt mask
#define	USART_ISR_RX					BIT(2)					 // Receive interrupt mask
#define	USART_ISR_ERR					BIT(3)					 // Error interrupt mask
#define	USART_ISR_CTS					BIT(4)					 // CTS interrupt mask
#define	USART_ISR_ABDET					BIT(5)					 // Autobaud detected interrupt mask
#define	USART_ISR_ABSTART				BIT(6)					 // Autobaud start interrupt mask
#define	USART_ISR_TMO					BIT(7)					 // RX timeout interrupt mask

#define	USART_TMO(base)					MMIO32((base) + 0x7C)


// SIM [MOD_NUM=F000, MOD_REV=00, MOD_32BIT=C0]
// Looks like SIM IO module, but not sure.
#define	SIM_BASE	0xF1300000
/* Clock Control Register */
#define	SIM_CLC		MMIO32(SIM_BASE + 0x00)

/* Module Identifier Register */
#define	SIM_ID		MMIO32(SIM_BASE + 0x08)


// USB [MOD_NUM=F047, MOD_REV=00, MOD_32BIT=C0]
// Looks like USB module, but not sure.
#define	USB_BASE	0xF2200800
/* Clock Control Register */
#define	USB_CLC		MMIO32(USB_BASE + 0x00)

/* Module Identifier Register */
#define	USB_ID		MMIO32(USB_BASE + 0x08)


// NVIC [MOD_NUM=0031, MOD_REV=00, MOD_32BIT=C0]
// NVIC module, registers collected using tests on real hardware (using "black box" method).
#define	NVIC_BASE				0xF2800000
/* Module Identifier Register */
#define	NVIC_ID					MMIO32(NVIC_BASE + 0x00)

#define	NVIC_FIQ_STAT			MMIO32(NVIC_BASE + 0x08)
#define	NVIC_FIQ_STAT_NUM		GENMASK(7, 0)							 // Current fiq num
#define	NVIC_FIQ_STAT_NUM_SHIFT	0
#define	NVIC_FIQ_STAT_UNREAD	BIT(16)
#define	NVIC_FIQ_STAT_NOT_ACK	BIT(24)

#define	NVIC_IRQ_STAT			MMIO32(NVIC_BASE + 0x0C)
#define	NVIC_IRQ_STAT_NUM		GENMASK(7, 0)							 // Current irq num
#define	NVIC_IRQ_STAT_NUM_SHIFT	0
#define	NVIC_IRQ_STAT_UNREAD	BIT(16)
#define	NVIC_IRQ_STAT_NOT_ACK	BIT(24)

#define	NVIC_FIQ_ACK			MMIO32(NVIC_BASE + 0x10)

#define	NVIC_IRQ_ACK			MMIO32(NVIC_BASE + 0x14)

#define	NVIC_CURRENT_FIQ		MMIO32(NVIC_BASE + 0x18)

#define	NVIC_CURRENT_IRQ		MMIO32(NVIC_BASE + 0x1C)

#define	NVIC_CON(n)				MMIO32(NVIC_BASE + 0x30 + ((n) * 0x4))
#define	NVIC_CON_PRIORITY		GENMASK(7, 0)
#define	NVIC_CON_PRIORITY_SHIFT	0
#define	NVIC_CON_FIQ			BIT(8)


// DMAC [AMBA PL080]
// PrimeCell DMA Controller (PL080)
#define	DMAC_BASE								0xF3000000
/* Status of the DMA interrupts after masking */
#define	DMAC_INT_STATUS							MMIO32(DMAC_BASE + 0x00)
#define	DMAC_INT_STATUS_CH0						BIT(0)
#define	DMAC_INT_STATUS_CH1						BIT(1)
#define	DMAC_INT_STATUS_CH2						BIT(2)
#define	DMAC_INT_STATUS_CH3						BIT(3)
#define	DMAC_INT_STATUS_CH4						BIT(4)
#define	DMAC_INT_STATUS_CH5						BIT(5)
#define	DMAC_INT_STATUS_CH6						BIT(6)
#define	DMAC_INT_STATUS_CH7						BIT(7)

/* Interrupt terminal count request status */
#define	DMAC_TC_STATUS							MMIO32(DMAC_BASE + 0x04)
#define	DMAC_TC_STATUS_CH0						BIT(0)
#define	DMAC_TC_STATUS_CH1						BIT(1)
#define	DMAC_TC_STATUS_CH2						BIT(2)
#define	DMAC_TC_STATUS_CH3						BIT(3)
#define	DMAC_TC_STATUS_CH4						BIT(4)
#define	DMAC_TC_STATUS_CH5						BIT(5)
#define	DMAC_TC_STATUS_CH6						BIT(6)
#define	DMAC_TC_STATUS_CH7						BIT(7)

/* Terminal count request clear. */
#define	DMAC_TC_CLEAR							MMIO32(DMAC_BASE + 0x08)
#define	DMAC_TC_CLEAR_CH0						BIT(0)
#define	DMAC_TC_CLEAR_CH1						BIT(1)
#define	DMAC_TC_CLEAR_CH2						BIT(2)
#define	DMAC_TC_CLEAR_CH3						BIT(3)
#define	DMAC_TC_CLEAR_CH4						BIT(4)
#define	DMAC_TC_CLEAR_CH5						BIT(5)
#define	DMAC_TC_CLEAR_CH6						BIT(6)
#define	DMAC_TC_CLEAR_CH7						BIT(7)

/* Interrupt error status */
#define	DMAC_ERR_STATUS							MMIO32(DMAC_BASE + 0x0C)
#define	DMAC_ERR_STATUS_CH0						BIT(0)
#define	DMAC_ERR_STATUS_CH1						BIT(1)
#define	DMAC_ERR_STATUS_CH2						BIT(2)
#define	DMAC_ERR_STATUS_CH3						BIT(3)
#define	DMAC_ERR_STATUS_CH4						BIT(4)
#define	DMAC_ERR_STATUS_CH5						BIT(5)
#define	DMAC_ERR_STATUS_CH6						BIT(6)
#define	DMAC_ERR_STATUS_CH7						BIT(7)

/* Interrupt error clear. */
#define	DMAC_ERR_CLEAR							MMIO32(DMAC_BASE + 0x10)
#define	DMAC_ERR_CLEAR_CH0						BIT(0)
#define	DMAC_ERR_CLEAR_CH1						BIT(1)
#define	DMAC_ERR_CLEAR_CH2						BIT(2)
#define	DMAC_ERR_CLEAR_CH3						BIT(3)
#define	DMAC_ERR_CLEAR_CH4						BIT(4)
#define	DMAC_ERR_CLEAR_CH5						BIT(5)
#define	DMAC_ERR_CLEAR_CH6						BIT(6)
#define	DMAC_ERR_CLEAR_CH7						BIT(7)

/* Status of the terminal count interrupt prior to masking */
#define	DMAC_RAW_TC_STATUS						MMIO32(DMAC_BASE + 0x14)
#define	DMAC_RAW_TC_STATUS_CH0					BIT(0)
#define	DMAC_RAW_TC_STATUS_CH1					BIT(1)
#define	DMAC_RAW_TC_STATUS_CH2					BIT(2)
#define	DMAC_RAW_TC_STATUS_CH3					BIT(3)
#define	DMAC_RAW_TC_STATUS_CH4					BIT(4)
#define	DMAC_RAW_TC_STATUS_CH5					BIT(5)
#define	DMAC_RAW_TC_STATUS_CH6					BIT(6)
#define	DMAC_RAW_TC_STATUS_CH7					BIT(7)

/* Status of the error interrupt prior to masking */
#define	DMAC_RAW_ERR_STATUS						MMIO32(DMAC_BASE + 0x18)
#define	DMAC_RAW_ERR_STATUS_CH0					BIT(0)
#define	DMAC_RAW_ERR_STATUS_CH1					BIT(1)
#define	DMAC_RAW_ERR_STATUS_CH2					BIT(2)
#define	DMAC_RAW_ERR_STATUS_CH3					BIT(3)
#define	DMAC_RAW_ERR_STATUS_CH4					BIT(4)
#define	DMAC_RAW_ERR_STATUS_CH5					BIT(5)
#define	DMAC_RAW_ERR_STATUS_CH6					BIT(6)
#define	DMAC_RAW_ERR_STATUS_CH7					BIT(7)

/* Channel enable status */
#define	DMAC_EN_CHAN							MMIO32(DMAC_BASE + 0x1C)
#define	DMAC_EN_CHAN_CH0						BIT(0)
#define	DMAC_EN_CHAN_CH1						BIT(1)
#define	DMAC_EN_CHAN_CH2						BIT(2)
#define	DMAC_EN_CHAN_CH3						BIT(3)
#define	DMAC_EN_CHAN_CH4						BIT(4)
#define	DMAC_EN_CHAN_CH5						BIT(5)
#define	DMAC_EN_CHAN_CH6						BIT(6)
#define	DMAC_EN_CHAN_CH7						BIT(7)

/* Software burst request. */
#define	DMAC_SOFT_BREQ							MMIO32(DMAC_BASE + 0x20)
#define	DMAC_SOFT_BREQ_CH0_0					BIT(0)
#define	DMAC_SOFT_BREQ_CH0_1					BIT(1)
#define	DMAC_SOFT_BREQ_CH1_0					BIT(2)
#define	DMAC_SOFT_BREQ_CH1_1					BIT(3)
#define	DMAC_SOFT_BREQ_CH2_0					BIT(4)
#define	DMAC_SOFT_BREQ_CH2_1					BIT(5)
#define	DMAC_SOFT_BREQ_CH3_0					BIT(6)
#define	DMAC_SOFT_BREQ_CH3_1					BIT(7)
#define	DMAC_SOFT_BREQ_CH4_0					BIT(8)
#define	DMAC_SOFT_BREQ_CH4_1					BIT(9)
#define	DMAC_SOFT_BREQ_CH5_0					BIT(10)
#define	DMAC_SOFT_BREQ_CH5_1					BIT(11)
#define	DMAC_SOFT_BREQ_CH6_0					BIT(12)
#define	DMAC_SOFT_BREQ_CH6_1					BIT(13)
#define	DMAC_SOFT_BREQ_CH7_0					BIT(14)
#define	DMAC_SOFT_BREQ_CH7_1					BIT(15)

/* Software single request. */
#define	DMAC_SOFT_SREQ							MMIO32(DMAC_BASE + 0x24)
#define	DMAC_SOFT_SREQ_CH0_0					BIT(0)
#define	DMAC_SOFT_SREQ_CH0_1					BIT(1)
#define	DMAC_SOFT_SREQ_CH1_0					BIT(2)
#define	DMAC_SOFT_SREQ_CH1_1					BIT(3)
#define	DMAC_SOFT_SREQ_CH2_0					BIT(4)
#define	DMAC_SOFT_SREQ_CH2_1					BIT(5)
#define	DMAC_SOFT_SREQ_CH3_0					BIT(6)
#define	DMAC_SOFT_SREQ_CH3_1					BIT(7)
#define	DMAC_SOFT_SREQ_CH4_0					BIT(8)
#define	DMAC_SOFT_SREQ_CH4_1					BIT(9)
#define	DMAC_SOFT_SREQ_CH5_0					BIT(10)
#define	DMAC_SOFT_SREQ_CH5_1					BIT(11)
#define	DMAC_SOFT_SREQ_CH6_0					BIT(12)
#define	DMAC_SOFT_SREQ_CH6_1					BIT(13)
#define	DMAC_SOFT_SREQ_CH7_0					BIT(14)
#define	DMAC_SOFT_SREQ_CH7_1					BIT(15)

/* Software last burst request. */
#define	DMAC_SOFT_LBREQ							MMIO32(DMAC_BASE + 0x28)
#define	DMAC_SOFT_LBREQ_CH0_0					BIT(0)
#define	DMAC_SOFT_LBREQ_CH0_1					BIT(1)
#define	DMAC_SOFT_LBREQ_CH1_0					BIT(2)
#define	DMAC_SOFT_LBREQ_CH1_1					BIT(3)
#define	DMAC_SOFT_LBREQ_CH2_0					BIT(4)
#define	DMAC_SOFT_LBREQ_CH2_1					BIT(5)
#define	DMAC_SOFT_LBREQ_CH3_0					BIT(6)
#define	DMAC_SOFT_LBREQ_CH3_1					BIT(7)
#define	DMAC_SOFT_LBREQ_CH4_0					BIT(8)
#define	DMAC_SOFT_LBREQ_CH4_1					BIT(9)
#define	DMAC_SOFT_LBREQ_CH5_0					BIT(10)
#define	DMAC_SOFT_LBREQ_CH5_1					BIT(11)
#define	DMAC_SOFT_LBREQ_CH6_0					BIT(12)
#define	DMAC_SOFT_LBREQ_CH6_1					BIT(13)
#define	DMAC_SOFT_LBREQ_CH7_0					BIT(14)
#define	DMAC_SOFT_LBREQ_CH7_1					BIT(15)

/* Software last single request. */
#define	DMAC_SOFT_LSREQ							MMIO32(DMAC_BASE + 0x2C)
#define	DMAC_SOFT_LSREQ_CH0_0					BIT(0)
#define	DMAC_SOFT_LSREQ_CH0_1					BIT(1)
#define	DMAC_SOFT_LSREQ_CH1_0					BIT(2)
#define	DMAC_SOFT_LSREQ_CH1_1					BIT(3)
#define	DMAC_SOFT_LSREQ_CH2_0					BIT(4)
#define	DMAC_SOFT_LSREQ_CH2_1					BIT(5)
#define	DMAC_SOFT_LSREQ_CH3_0					BIT(6)
#define	DMAC_SOFT_LSREQ_CH3_1					BIT(7)
#define	DMAC_SOFT_LSREQ_CH4_0					BIT(8)
#define	DMAC_SOFT_LSREQ_CH4_1					BIT(9)
#define	DMAC_SOFT_LSREQ_CH5_0					BIT(10)
#define	DMAC_SOFT_LSREQ_CH5_1					BIT(11)
#define	DMAC_SOFT_LSREQ_CH6_0					BIT(12)
#define	DMAC_SOFT_LSREQ_CH6_1					BIT(13)
#define	DMAC_SOFT_LSREQ_CH7_0					BIT(14)
#define	DMAC_SOFT_LSREQ_CH7_1					BIT(15)

/* Configuration Register */
#define	DMAC_CONFIG								MMIO32(DMAC_BASE + 0x30)
#define	DMAC_CONFIG_ENABLE						BIT(0)										 // DMAC Enable
#define	DMAC_CONFIG_M1							BIT(1)										 // AHB Master 1 endianness configuration
#define	DMAC_CONFIG_M1_LE						0x0
#define	DMAC_CONFIG_M1_BE						0x2
#define	DMAC_CONFIG_M2							BIT(2)										 // AHB Master 2 endianness configuration
#define	DMAC_CONFIG_M2_LE						0x0
#define	DMAC_CONFIG_M2_BE						0x4

/* Synchronization Register */
#define	DMAC_SYNC								MMIO32(DMAC_BASE + 0x34)
#define	DMAC_SYNC_CH0_0							BIT(0)
#define	DMAC_SYNC_CH0_1							BIT(1)
#define	DMAC_SYNC_CH1_0							BIT(2)
#define	DMAC_SYNC_CH1_1							BIT(3)
#define	DMAC_SYNC_CH2_0							BIT(4)
#define	DMAC_SYNC_CH2_1							BIT(5)
#define	DMAC_SYNC_CH3_0							BIT(6)
#define	DMAC_SYNC_CH3_1							BIT(7)
#define	DMAC_SYNC_CH4_0							BIT(8)
#define	DMAC_SYNC_CH4_1							BIT(9)
#define	DMAC_SYNC_CH5_0							BIT(10)
#define	DMAC_SYNC_CH5_1							BIT(11)
#define	DMAC_SYNC_CH6_0							BIT(12)
#define	DMAC_SYNC_CH6_1							BIT(13)
#define	DMAC_SYNC_CH7_0							BIT(14)
#define	DMAC_SYNC_CH7_1							BIT(15)

#define	DMAC_CH_SRC_ADDR(n)						MMIO32(DMAC_BASE + 0x100 + ((n) * 0x20))

#define	DMAC_CH_DST_ADDR(n)						MMIO32(DMAC_BASE + 0x104 + ((n) * 0x20))

#define	DMAC_CH_LLI(n)							MMIO32(DMAC_BASE + 0x108 + ((n) * 0x20))
#define	DMAC_CH_LLI_LM							BIT(0)										 // AHB master select for loading the next LLI
#define	DMAC_CH_LLI_LM_AHB1						0x0
#define	DMAC_CH_LLI_LM_AHB2						0x1
#define	DMAC_CH_LLI_ITEM						GENMASK(30, 2)								 // Linked list item
#define	DMAC_CH_LLI_ITEM_SHIFT					2

#define	DMAC_CH_CONTROL(n)						MMIO32(DMAC_BASE + 0x10C + ((n) * 0x20))
#define	DMAC_CH_CONTROL_TRANSFER_SIZE			GENMASK(11, 0)								 // Transfer size.
#define	DMAC_CH_CONTROL_TRANSFER_SIZE_SHIFT		0
#define	DMAC_CH_CONTROL_SB_SIZE					GENMASK(14, 12)								 // Source burst size
#define	DMAC_CH_CONTROL_SB_SIZE_SHIFT			12
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_1			0x0
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_4			0x1000
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_8			0x2000
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_16			0x3000
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_32			0x4000
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_64			0x5000
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_128			0x6000
#define	DMAC_CH_CONTROL_SB_SIZE_SZ_256			0x7000
#define	DMAC_CH_CONTROL_DB_SIZE					GENMASK(17, 15)								 // Destination burst size
#define	DMAC_CH_CONTROL_DB_SIZE_SHIFT			15
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_1			0x0
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_4			0x8000
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_8			0x10000
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_16			0x18000
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_32			0x20000
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_64			0x28000
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_128			0x30000
#define	DMAC_CH_CONTROL_DB_SIZE_SZ_256			0x38000
#define	DMAC_CH_CONTROL_S_WIDTH					GENMASK(20, 18)								 // Source transfer width
#define	DMAC_CH_CONTROL_S_WIDTH_SHIFT			18
#define	DMAC_CH_CONTROL_S_WIDTH_BYTE			0x0
#define	DMAC_CH_CONTROL_S_WIDTH_WORD			0x40000
#define	DMAC_CH_CONTROL_S_WIDTH_DWORD			0x80000
#define	DMAC_CH_CONTROL_D_WIDTH					GENMASK(23, 21)								 // Destination transfer width
#define	DMAC_CH_CONTROL_D_WIDTH_SHIFT			21
#define	DMAC_CH_CONTROL_D_WIDTH_BYTE			0x0
#define	DMAC_CH_CONTROL_D_WIDTH_WORD			0x200000
#define	DMAC_CH_CONTROL_D_WIDTH_DWORD			0x400000
#define	DMAC_CH_CONTROL_S						BIT(24)										 // Source AHB master select
#define	DMAC_CH_CONTROL_S_AHB1					0x0
#define	DMAC_CH_CONTROL_S_AHB2					0x1000000
#define	DMAC_CH_CONTROL_D						BIT(25)										 // Destination AHB master select
#define	DMAC_CH_CONTROL_D_AHB1					0x0
#define	DMAC_CH_CONTROL_D_AHB2					0x2000000
#define	DMAC_CH_CONTROL_SI						BIT(26)										 // Source increment.
#define	DMAC_CH_CONTROL_DI						BIT(27)										 // Destination increment.
#define	DMAC_CH_CONTROL_PROTECTION				GENMASK(30, 28)								 // Protection.
#define	DMAC_CH_CONTROL_PROTECTION_SHIFT		28
#define	DMAC_CH_CONTROL_I						BIT(31)										 // Terminal count interrupt enable bit.

#define	DMAC_CH_CONFIG(n)						MMIO32(DMAC_BASE + 0x110 + ((n) * 0x20))
#define	DMAC_CH_CONFIG_ENABLE					BIT(0)										 // Channel enable.
#define	DMAC_CH_CONFIG_SRC_PERIPH				GENMASK(4, 1)								 // Source peripheral.
#define	DMAC_CH_CONFIG_SRC_PERIPH_SHIFT			1
#define	DMAC_CH_CONFIG_DST_PERIPH				GENMASK(9, 6)								 // Destination peripheral.
#define	DMAC_CH_CONFIG_DST_PERIPH_SHIFT			6
#define	DMAC_CH_CONFIG_FLOW_CTRL				GENMASK(13, 11)								 // Flow control and transfer type
#define	DMAC_CH_CONFIG_FLOW_CTRL_SHIFT			11
#define	DMAC_CH_CONFIG_FLOW_CTRL_MEM2MEM		0x0
#define	DMAC_CH_CONFIG_FLOW_CTRL_MEM2PER		0x800
#define	DMAC_CH_CONFIG_FLOW_CTRL_PER2MEM		0x1000
#define	DMAC_CH_CONFIG_FLOW_CTRL_PER2PER		0x1800
#define	DMAC_CH_CONFIG_FLOW_CTRL_PER2PER_DST	0x2000
#define	DMAC_CH_CONFIG_FLOW_CTRL_MEM2PER_PER	0x2800
#define	DMAC_CH_CONFIG_FLOW_CTRL_PER2MEM_PER	0x3000
#define	DMAC_CH_CONFIG_FLOW_CTRL_PER2PER_SRC	0x3800
#define	DMAC_CH_CONFIG_INT_MASK_ERR				BIT(14)										 // Interrupt error mask.
#define	DMAC_CH_CONFIG_INT_MASK_TC				BIT(15)										 // Terminal count interrupt mask.
#define	DMAC_CH_CONFIG_LOCK						BIT(16)										 // Lock.
#define	DMAC_CH_CONFIG_ACTIVE					BIT(17)										 // Active.
#define	DMAC_CH_CONFIG_HALT						BIT(18)										 // Halt.

#define	DMAC_PERIPH_ID0							MMIO32(DMAC_BASE + 0xFE0)

#define	DMAC_PERIPH_ID1							MMIO32(DMAC_BASE + 0xFE4)

#define	DMAC_PERIPH_ID2							MMIO32(DMAC_BASE + 0xFE8)

#define	DMAC_PERIPH_ID3							MMIO32(DMAC_BASE + 0xFEC)

#define	DMAC_PCELL_ID0							MMIO32(DMAC_BASE + 0xFF0)

#define	DMAC_PCELL_ID1							MMIO32(DMAC_BASE + 0xFF4)

#define	DMAC_PCELL_ID2							MMIO32(DMAC_BASE + 0xFF8)

#define	DMAC_PCELL_ID3							MMIO32(DMAC_BASE + 0xFFC)


// CAPCOM0 [MOD_NUM=0050, MOD_REV=00, MOD_32BIT=00]
// CAPCOM from drivers/clocksource/xgold_capcom_timer.c (GPL2)
#define	CAPCOM0_BASE				0xF4000000
#define	CAPCOM0						0xF4000000

#define	CAPCOM1_BASE				0xF4100000
#define	CAPCOM1						0xF4100000

/* Clock Control Register */
#define	CAPCOM_CLC(base)			MMIO32((base) + 0x00)

#define	CAPCOM_PISEL(base)			MMIO32((base) + 0x04)
#define	CAPCOM_PISEL_C1C0IS			BIT(0)
#define	CAPCOM_PISEL_C3C2IS			BIT(1)
#define	CAPCOM_PISEL_C5C4IS			BIT(2)
#define	CAPCOM_PISEL_C7C6IS			BIT(3)
#define	CAPCOM_PISEL_T0INIS			BIT(4)
#define	CAPCOM_PISEL_T1INIS			BIT(5)

/* Module Identifier Register */
#define	CAPCOM_ID(base)				MMIO32((base) + 0x08)

#define	CAPCOM_T01CON(base)			MMIO32((base) + 0x10)
#define	CAPCOM_T01CON_T0I			GENMASK(2, 0)
#define	CAPCOM_T01CON_T0I_SHIFT		0
#define	CAPCOM_T01CON_T0M			BIT(3)
#define	CAPCOM_T01CON_T0R			BIT(6)
#define	CAPCOM_T01CON_T1I			GENMASK(10, 8)
#define	CAPCOM_T01CON_T1I_SHIFT		8
#define	CAPCOM_T01CON_T1M			BIT(11)
#define	CAPCOM_T01CON_T1R			BIT(14)

#define	CAPCOM_CCM0(base)			MMIO32((base) + 0x14)
#define	CAPCOM_CCM0_MOD0			GENMASK(2, 0)
#define	CAPCOM_CCM0_MOD0_SHIFT		0
#define	CAPCOM_CCM0_ACC0			BIT(3)
#define	CAPCOM_CCM0_ACC0_TIM0		0x0
#define	CAPCOM_CCM0_ACC0_TIM1		0x8
#define	CAPCOM_CCM0_MOD1			GENMASK(6, 4)
#define	CAPCOM_CCM0_MOD1_SHIFT		4
#define	CAPCOM_CCM0_ACC1			BIT(7)
#define	CAPCOM_CCM0_ACC1_TIM0		0x0
#define	CAPCOM_CCM0_ACC1_TIM1		0x80
#define	CAPCOM_CCM0_MOD2			GENMASK(10, 8)
#define	CAPCOM_CCM0_MOD2_SHIFT		8
#define	CAPCOM_CCM0_ACC2			BIT(11)
#define	CAPCOM_CCM0_ACC2_TIM0		0x0
#define	CAPCOM_CCM0_ACC2_TIM1		0x800
#define	CAPCOM_CCM0_MOD3			GENMASK(14, 12)
#define	CAPCOM_CCM0_MOD3_SHIFT		12
#define	CAPCOM_CCM0_ACC3			BIT(15)
#define	CAPCOM_CCM0_ACC3_TIM0		0x0
#define	CAPCOM_CCM0_ACC3_TIM1		0x8000

#define	CAPCOM_CCM1(base)			MMIO32((base) + 0x18)
#define	CAPCOM_CCM1_MOD4			GENMASK(2, 0)
#define	CAPCOM_CCM1_MOD4_SHIFT		0
#define	CAPCOM_CCM1_ACC4			BIT(3)
#define	CAPCOM_CCM1_ACC4_TIM0		0x0
#define	CAPCOM_CCM1_ACC4_TIM1		0x8
#define	CAPCOM_CCM1_MOD5			GENMASK(6, 4)
#define	CAPCOM_CCM1_MOD5_SHIFT		4
#define	CAPCOM_CCM1_ACC5			BIT(7)
#define	CAPCOM_CCM1_ACC5_TIM0		0x0
#define	CAPCOM_CCM1_ACC5_TIM1		0x80
#define	CAPCOM_CCM1_MOD6			GENMASK(10, 8)
#define	CAPCOM_CCM1_MOD6_SHIFT		8
#define	CAPCOM_CCM1_ACC6			BIT(11)
#define	CAPCOM_CCM1_ACC6_TIM0		0x0
#define	CAPCOM_CCM1_ACC6_TIM1		0x800
#define	CAPCOM_CCM1_MOD7			GENMASK(14, 12)
#define	CAPCOM_CCM1_MOD7_SHIFT		12
#define	CAPCOM_CCM1_ACC7			BIT(15)
#define	CAPCOM_CCM1_ACC7_TIM0		0x0
#define	CAPCOM_CCM1_ACC7_TIM1		0x8000

#define	CAPCOM_OUT(base)			MMIO32((base) + 0x24)
#define	CAPCOM_OUT_O0				BIT(0)
#define	CAPCOM_OUT_O1				BIT(1)
#define	CAPCOM_OUT_O2				BIT(2)
#define	CAPCOM_OUT_O3				BIT(3)
#define	CAPCOM_OUT_O4				BIT(4)
#define	CAPCOM_OUT_O5				BIT(5)
#define	CAPCOM_OUT_O6				BIT(6)
#define	CAPCOM_OUT_O7				BIT(7)

#define	CAPCOM_IOC(base)			MMIO32((base) + 0x28)
#define	CAPCOM_IOC_PDS				BIT(3)
#define	CAPCOM_IOC_PDS_OUT			0x0
#define	CAPCOM_IOC_PDS_IN			0x8

#define	CAPCOM_SEM(base)			MMIO32((base) + 0x2C)
#define	CAPCOM_SEM_SEM0				BIT(0)
#define	CAPCOM_SEM_SEM1				BIT(1)
#define	CAPCOM_SEM_SEM2				BIT(2)
#define	CAPCOM_SEM_SEM3				BIT(3)
#define	CAPCOM_SEM_SEM4				BIT(4)
#define	CAPCOM_SEM_SEM5				BIT(5)
#define	CAPCOM_SEM_SEM6				BIT(6)
#define	CAPCOM_SEM_SEM7				BIT(7)

#define	CAPCOM_SEE(base)			MMIO32((base) + 0x30)
#define	CAPCOM_SEE_SEE0				BIT(0)
#define	CAPCOM_SEE_SEE1				BIT(1)
#define	CAPCOM_SEE_SEE2				BIT(2)
#define	CAPCOM_SEE_SEE3				BIT(3)
#define	CAPCOM_SEE_SEE4				BIT(4)
#define	CAPCOM_SEE_SEE5				BIT(5)
#define	CAPCOM_SEE_SEE6				BIT(6)
#define	CAPCOM_SEE_SEE7				BIT(7)

#define	CAPCOM_DRM(base)			MMIO32((base) + 0x34)
#define	CAPCOM_DRM_DR0M				GENMASK(1, 0)
#define	CAPCOM_DRM_DR0M_SHIFT		0
#define	CAPCOM_DRM_DR0M_CON			0x0
#define	CAPCOM_DRM_DR0M_DIS			0x1
#define	CAPCOM_DRM_DR0M_EN			0x2
#define	CAPCOM_DRM_DR0M_RES			0x3
#define	CAPCOM_DRM_DR1M				GENMASK(3, 2)
#define	CAPCOM_DRM_DR1M_SHIFT		2
#define	CAPCOM_DRM_DR1M_CON			0x0
#define	CAPCOM_DRM_DR1M_DIS			0x4
#define	CAPCOM_DRM_DR1M_EN			0x8
#define	CAPCOM_DRM_DR1M_RES			0xC
#define	CAPCOM_DRM_DR2M				GENMASK(5, 4)
#define	CAPCOM_DRM_DR2M_SHIFT		4
#define	CAPCOM_DRM_DR2M_CON			0x0
#define	CAPCOM_DRM_DR2M_DIS			0x10
#define	CAPCOM_DRM_DR2M_EN			0x20
#define	CAPCOM_DRM_DR2M_RES			0x30
#define	CAPCOM_DRM_DR3M				GENMASK(7, 6)
#define	CAPCOM_DRM_DR3M_SHIFT		6
#define	CAPCOM_DRM_DR3M_CON			0x0
#define	CAPCOM_DRM_DR3M_DIS			0x40
#define	CAPCOM_DRM_DR3M_EN			0x80
#define	CAPCOM_DRM_DR3M_RES			0xC0

#define	CAPCOM_WHBSSEE(base)		MMIO32((base) + 0x38)
#define	CAPCOM_WHBSSEE_SETSEE0		BIT(0)
#define	CAPCOM_WHBSSEE_SETSEE0_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE0_SET	0x1
#define	CAPCOM_WHBSSEE_SETSEE1		BIT(1)
#define	CAPCOM_WHBSSEE_SETSEE1_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE1_SET	0x2
#define	CAPCOM_WHBSSEE_SETSEE2		BIT(2)
#define	CAPCOM_WHBSSEE_SETSEE2_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE2_SET	0x4
#define	CAPCOM_WHBSSEE_SETSEE3		BIT(3)
#define	CAPCOM_WHBSSEE_SETSEE3_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE3_SET	0x8
#define	CAPCOM_WHBSSEE_SETSEE4		BIT(4)
#define	CAPCOM_WHBSSEE_SETSEE4_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE4_SET	0x10
#define	CAPCOM_WHBSSEE_SETSEE5		BIT(5)
#define	CAPCOM_WHBSSEE_SETSEE5_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE5_SET	0x20
#define	CAPCOM_WHBSSEE_SETSEE6		BIT(6)
#define	CAPCOM_WHBSSEE_SETSEE6_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE6_SET	0x40
#define	CAPCOM_WHBSSEE_SETSEE7		BIT(7)
#define	CAPCOM_WHBSSEE_SETSEE7_NOE	0x0
#define	CAPCOM_WHBSSEE_SETSEE7_SET	0x80

#define	CAPCOM_WHBCSEE(base)		MMIO32((base) + 0x3C)
#define	CAPCOM_WHBCSEE_CLRSEE0		BIT(0)
#define	CAPCOM_WHBCSEE_CLRSEE0_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE0_CLR	0x1
#define	CAPCOM_WHBCSEE_CLRSEE1		BIT(1)
#define	CAPCOM_WHBCSEE_CLRSEE1_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE1_CLR	0x2
#define	CAPCOM_WHBCSEE_CLRSEE2		BIT(2)
#define	CAPCOM_WHBCSEE_CLRSEE2_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE2_CLR	0x4
#define	CAPCOM_WHBCSEE_CLRSEE3		BIT(3)
#define	CAPCOM_WHBCSEE_CLRSEE3_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE3_CLR	0x8
#define	CAPCOM_WHBCSEE_CLRSEE4		BIT(4)
#define	CAPCOM_WHBCSEE_CLRSEE4_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE4_CLR	0x10
#define	CAPCOM_WHBCSEE_CLRSEE5		BIT(5)
#define	CAPCOM_WHBCSEE_CLRSEE5_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE5_CLR	0x20
#define	CAPCOM_WHBCSEE_CLRSEE6		BIT(6)
#define	CAPCOM_WHBCSEE_CLRSEE6_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE6_CLR	0x40
#define	CAPCOM_WHBCSEE_CLRSEE7		BIT(7)
#define	CAPCOM_WHBCSEE_CLRSEE7_NOE	0x0
#define	CAPCOM_WHBCSEE_CLRSEE7_CLR	0x80

#define	CAPCOM_T0(base)				MMIO32((base) + 0x40)
#define	CAPCOM_T0_T0				GENMASK(30, 0)
#define	CAPCOM_T0_T0_SHIFT			0
#define	CAPCOM_T0_OVF0				BIT(31)
#define	CAPCOM_T0_OVF0_CLEARED		0x0
#define	CAPCOM_T0_OVF0_SET			0x80000000

#define	CAPCOM_T0REL(base)			MMIO32((base) + 0x44)
#define	CAPCOM_T0REL_T0REL			GENMASK(30, 0)
#define	CAPCOM_T0REL_T0REL_SHIFT	0

#define	CAPCOM_T1(base)				MMIO32((base) + 0x48)
#define	CAPCOM_T1_T1				GENMASK(30, 0)
#define	CAPCOM_T1_T1_SHIFT			0
#define	CAPCOM_T1_OVF1				BIT(31)
#define	CAPCOM_T1_OVF1_CLEARED		0x0
#define	CAPCOM_T1_OVF1_SET			0x80000000

#define	CAPCOM_T1REL(base)			MMIO32((base) + 0x4C)
#define	CAPCOM_T1REL_T1REL			GENMASK(30, 0)
#define	CAPCOM_T1REL_T1REL_SHIFT	0

#define	CAPCOM_CC(base, n)			MMIO32(base + 0x50 + ((n) * 0x4))

#define	CAPCOM_T01OCR(base)			MMIO32((base) + 0x94)
#define	CAPCOM_T01OCR_CT0			BIT(0)
#define	CAPCOM_T01OCR_CT0_NOC		0x0
#define	CAPCOM_T01OCR_CT0_CSR		0x1
#define	CAPCOM_T01OCR_CT1			BIT(1)
#define	CAPCOM_T01OCR_CT1_NOC		0x0
#define	CAPCOM_T01OCR_CT1_CSR		0x2

#define	CAPCOM_WHBSOUT(base)		MMIO32((base) + 0x98)
#define	CAPCOM_WHBSOUT_SET0O		BIT(0)
#define	CAPCOM_WHBSOUT_SET1O		BIT(1)
#define	CAPCOM_WHBSOUT_SET2O		BIT(2)
#define	CAPCOM_WHBSOUT_SET3O		BIT(3)
#define	CAPCOM_WHBSOUT_SET4O		BIT(4)
#define	CAPCOM_WHBSOUT_SET5O		BIT(5)
#define	CAPCOM_WHBSOUT_SET6O		BIT(6)
#define	CAPCOM_WHBSOUT_SET7O		BIT(7)

#define	CAPCOM_WHBCOUT(base)		MMIO32((base) + 0x9C)
#define	CAPCOM_WHBCOUT_CLR0O		BIT(0)
#define	CAPCOM_WHBCOUT_CLR1O		BIT(1)
#define	CAPCOM_WHBCOUT_CLR2O		BIT(2)
#define	CAPCOM_WHBCOUT_CLR3O		BIT(3)
#define	CAPCOM_WHBCOUT_CLR4O		BIT(4)
#define	CAPCOM_WHBCOUT_CLR5O		BIT(5)
#define	CAPCOM_WHBCOUT_CLR6O		BIT(6)
#define	CAPCOM_WHBCOUT_CLR7O		BIT(7)

/* Service Routing Control Register */
#define	CAPCOM_CC7_SRC(base)		MMIO32((base) + 0xD8)

/* Service Routing Control Register */
#define	CAPCOM_CC6_SRC(base)		MMIO32((base) + 0xDC)

/* Service Routing Control Register */
#define	CAPCOM_CC5_SRC(base)		MMIO32((base) + 0xE0)

/* Service Routing Control Register */
#define	CAPCOM_CC4_SRC(base)		MMIO32((base) + 0xE4)

/* Service Routing Control Register */
#define	CAPCOM_CC3_SRC(base)		MMIO32((base) + 0xE8)

/* Service Routing Control Register */
#define	CAPCOM_CC2_SRC(base)		MMIO32((base) + 0xEC)

/* Service Routing Control Register */
#define	CAPCOM_CC1_SRC(base)		MMIO32((base) + 0xF0)

/* Service Routing Control Register */
#define	CAPCOM_CC0_SRC(base)		MMIO32((base) + 0xF4)

/* Service Routing Control Register */
#define	CAPCOM_T1_SRC(base)			MMIO32((base) + 0xF8)

/* Service Routing Control Register */
#define	CAPCOM_T0_SRC(base)			MMIO32((base) + 0xFC)


// GPIO [MOD_NUM=F023, MOD_REV=00, MOD_32BIT=C0]
// GPIO module, registers found on some "siemens club" forum, dont known source.
#define	GPIO_BASE			0xF4300000
/* Clock Control Register */
#define	GPIO_CLC			MMIO32(GPIO_BASE + 0x00)

/* Module Identifier Register */
#define	GPIO_ID				MMIO32(GPIO_BASE + 0x08)

#define	GPIO_MON_CR1		MMIO32(GPIO_BASE + 0x10)

#define	GPIO_MON_CR2		MMIO32(GPIO_BASE + 0x14)

#define	GPIO_MON_CR3		MMIO32(GPIO_BASE + 0x18)

#define	GPIO_MON_CR4		MMIO32(GPIO_BASE + 0x1C)

#define	GPIO_PIN(n)			MMIO32(GPIO_BASE + 0x20 + ((n) * 0x4))
#define	GPIO_IS				GENMASK(2, 0)
#define	GPIO_IS_SHIFT		0
#define	GPIO_IS_NONE		0x0
#define	GPIO_IS_ALT0		0x1
#define	GPIO_IS_ALT1		0x2
#define	GPIO_IS_ALT2		0x3
#define	GPIO_IS_ALT3		0x4
#define	GPIO_IS_ALT4		0x5
#define	GPIO_IS_ALT5		0x6
#define	GPIO_IS_ALT6		0x7
#define	GPIO_OS				GENMASK(6, 4)
#define	GPIO_OS_SHIFT		4
#define	GPIO_OS_NONE		0x0
#define	GPIO_OS_ALT0		0x10
#define	GPIO_OS_ALT1		0x20
#define	GPIO_OS_ALT2		0x30
#define	GPIO_OS_ALT3		0x40
#define	GPIO_OS_ALT4		0x50
#define	GPIO_OS_ALT5		0x60
#define	GPIO_OS_ALT6		0x70
#define	GPIO_PS				BIT(8)
#define	GPIO_PS_ALT			0x0
#define	GPIO_PS_MANUAL		0x100
#define	GPIO_DATA			BIT(9)
#define	GPIO_DATA_LOW		0x0
#define	GPIO_DATA_HIGH		0x200
#define	GPIO_DIR			BIT(10)
#define	GPIO_DIR_IN			0x0
#define	GPIO_DIR_OUT		0x400
#define	GPIO_PPEN			BIT(12)
#define	GPIO_PPEN_PUSHPULL	0x0
#define	GPIO_PPEN_OPENDRAIN	0x1000
#define	GPIO_PDPU			GENMASK(14, 13)
#define	GPIO_PDPU_SHIFT		13
#define	GPIO_PDPU_NONE		0x0
#define	GPIO_PDPU_PULLUP	0x2000
#define	GPIO_PDPU_PULLDOWN	0x4000
#define	GPIO_ENAQ			BIT(15)
#define	GPIO_ENAQ_OFF		0x0
#define	GPIO_ENAQ_ON		0x8000


// SCU [MOD_NUM=F040, MOD_REV=00, MOD_32BIT=C0]
// Looks like SCU module, registers collected using TC1766 official public datasheet and tests on real hardware (using "black box" method).
#define	SCU_BASE					0xF4400000
/* Clock Control Register */
#define	SCU_CLC						MMIO32(SCU_BASE + 0x00)

/* Module Identifier Register */
#define	SCU_ID						MMIO32(SCU_BASE + 0x08)

/* Reset Status Register */
#define	SCU_RST_SR					MMIO32(SCU_BASE + 0x10)
#define	SCU_RST_SR_RSSTM			BIT(0)									 // System Timer Reset Status
#define	SCU_RST_SR_RSEXT			BIT(1)									 // HDRST Line State during Last Reset
#define	SCU_RST_SR_HWCFG			GENMASK(18, 16)							 // Boot Configuration Selection Status
#define	SCU_RST_SR_HWCFG_SHIFT		16
#define	SCU_RST_SR_HWBRKIN			BIT(21)									 // Latched State of BRKIN Input
#define	SCU_RST_SR_TMPLS			BIT(22)									 // Latched State of TESTMODE Input
#define	SCU_RST_SR_PWORST			BIT(27)									 // The last reset was a power-on reset
#define	SCU_RST_SR_HDRST			BIT(28)									 // The last reset was a hardware reset.
#define	SCU_RST_SR_SFTRST			BIT(29)									 // The last reset was a software reset.
#define	SCU_RST_SR_WDTRST			BIT(30)									 // The last reset was a watchdog reset.
#define	SCU_RST_SR_PWDRST			BIT(31)									 // The last reset was a wake-up from power-down

/* Reset Request Register */
#define	SCU_RST_REQ					MMIO32(SCU_BASE + 0x18)
#define	SCU_RST_REQ_RRSTM			BIT(0)									 // Reset Request for the System Timer
#define	SCU_RST_REQ_RREXT			BIT(2)									 // Reset Request for External Devices
#define	SCU_RST_REQ_SWCFG			GENMASK(18, 16)							 // Software Boot Configuration
#define	SCU_RST_REQ_SWCFG_SHIFT		16
#define	SCU_RST_REQ_SWBRKIN			BIT(21)									 // Software Break Signal Boot Value
#define	SCU_RST_REQ_SWBOOT			BIT(24)									 // Software Boot Configuration Selection

#define	SCU_WDTCON0					MMIO32(SCU_BASE + 0x24)
#define	SCU_WDTCON0_ENDINIT			BIT(0)									 // End-of-Initialization Control Bit.
#define	SCU_WDTCON0_WDTLCK			BIT(1)									 // Lock bit to Control Access to WDT_CON0.
#define	SCU_WDTCON0_WDTHPW0			GENMASK(3, 2)							 // Hardware Password 0.
#define	SCU_WDTCON0_WDTHPW0_SHIFT	2
#define	SCU_WDTCON0_WDTHPW1			GENMASK(7, 4)							 // Hardware Password 1.
#define	SCU_WDTCON0_WDTHPW1_SHIFT	4
#define	SCU_WDTCON0_WDTPW			GENMASK(15, 8)							 // User-Definable Password Field for Access to WDT_CON0.
#define	SCU_WDTCON0_WDTPW_SHIFT		8
#define	SCU_WDTCON0_WDTREL			GENMASK(31, 16)							 // Reload Value for the Watchdog Timer.
#define	SCU_WDTCON0_WDTREL_SHIFT	16

#define	SCU_WDTCON1					MMIO32(SCU_BASE + 0x28)
#define	SCU_WDTCON1_WDTIR			BIT(2)									 // Watchdog Timer Input Frequency Request Control Bit.
#define	SCU_WDTCON1_WDTDR			BIT(3)									 // Watchdog Timer Disable Request Control Bit.

#define	SCU_WDT_SR					MMIO32(SCU_BASE + 0x2C)
#define	SCU_WDT_SR_WDTAE			BIT(0)									 // Watchdog Access Error Status Flag
#define	SCU_WDT_SR_WDTOE			BIT(1)									 // Watchdog Overflow Error Status Flag
#define	SCU_WDT_SR_WDTIS			BIT(2)									 // Watchdog Input Clock Status Flag
#define	SCU_WDT_SR_WDTDS			BIT(3)									 // Watchdog Enable/Disable Status Flag
#define	SCU_WDT_SR_WDTTO			BIT(4)									 // Watchdog Time-out Mode Flag
#define	SCU_WDT_SR_WDTPR			BIT(5)									 // Watchdog Prewarning Mode Flag
#define	SCU_WDT_SR_WDTTIM			GENMASK(31, 16)							 // Watchdog Timer Value
#define	SCU_WDT_SR_WDTTIM_SHIFT		16

#define	SCU_DSP_UNK0				MMIO32(SCU_BASE + 0x30)

#define	SCU_EXTI					MMIO32(SCU_BASE + 0x3C)
#define	SCU_EXTI_EXT0_FALLING		BIT(0)
#define	SCU_EXTI_EXT0_RISING		BIT(1)
#define	SCU_EXTI_EXT1_FALLING		BIT(2)
#define	SCU_EXTI_EXT1_RISING		BIT(3)
#define	SCU_EXTI_EXT2_FALLING		BIT(4)
#define	SCU_EXTI_EXT2_RISING		BIT(5)
#define	SCU_EXTI_EXT3_FALLING		BIT(6)
#define	SCU_EXTI_EXT3_RISING		BIT(7)
#define	SCU_EXTI_EXT4_FALLING		BIT(8)
#define	SCU_EXTI_EXT4_RISING		BIT(9)
#define	SCU_EXTI_EXT5_FALLING		BIT(10)
#define	SCU_EXTI_EXT5_RISING		BIT(11)
#define	SCU_EXTI_EXT6_FALLING		BIT(12)
#define	SCU_EXTI_EXT6_RISING		BIT(13)
#define	SCU_EXTI_EXT7_FALLING		BIT(14)
#define	SCU_EXTI_EXT7_RISING		BIT(15)

#define	SCU_EBUCLC1					MMIO32(SCU_BASE + 0x40)
#define	SCU_EBUCLC1_FLAG1			GENMASK(3, 0)
#define	SCU_EBUCLC1_FLAG1_SHIFT		0
#define	SCU_EBUCLC1_READY			GENMASK(7, 4)
#define	SCU_EBUCLC1_READY_SHIFT		4

#define	SCU_EBUCLC2					MMIO32(SCU_BASE + 0x44)
#define	SCU_EBUCLC2_FLAG1			GENMASK(3, 0)
#define	SCU_EBUCLC2_FLAG1_SHIFT		0
#define	SCU_EBUCLC2_READY			GENMASK(7, 4)
#define	SCU_EBUCLC2_READY_SHIFT		4

#define	SCU_EBUCLC					MMIO32(SCU_BASE + 0x48)
#define	SCU_EBUCLC_LOCK				BIT(0)
#define	SCU_EBUCLC_VCOBYP			BIT(8)

#define	SCU_MANID					MMIO32(SCU_BASE + 0x5C)
#define	SCU_MANID_DEPT				GENMASK(3, 0)
#define	SCU_MANID_DEPT_SHIFT		0
#define	SCU_MANID_MANUF				GENMASK(14, 4)
#define	SCU_MANID_MANUF_SHIFT		4

#define	SCU_CHIPID					MMIO32(SCU_BASE + 0x60)
#define	SCU_CHIPID_CHREV			GENMASK(7, 0)
#define	SCU_CHIPID_CHREV_SHIFT		0
#define	SCU_CHIPID_MANUF			GENMASK(15, 8)
#define	SCU_CHIPID_MANUF_SHIFT		8

#define	SCU_RTCIF					MMIO32(SCU_BASE + 0x64)

#define	SCU_BOOT_CFG				MMIO32(SCU_BASE + 0x74)
#define	SCU_BOOT_CFG_USART1			BIT(28)									 // Allow boot from USART1
#define	SCU_BOOT_CFG_BYPASS_FW		BIT(29)									 // Force boot from 0x82000, bypass firmware
#define	SCU_BOOT_CFG_USB			BIT(30)									 // Allow boot from USB

#define	SCU_BOOT_FLAG				MMIO32(SCU_BASE + 0x78)
#define	SCU_BOOT_FLAG_BOOT_OK		BIT(0)

#define	SCU_ROMAMCR					MMIO32(SCU_BASE + 0x7C)
#define	SCU_ROMAMCR_MOUNT_BROM		BIT(0)

#define	SCU_RTID					MMIO32(SCU_BASE + 0x80)

/* DMA Request Select Register */
#define	SCU_DMARS					MMIO32(SCU_BASE + 0x84)
#define	SCU_DMARS_SEL0				BIT(0)									 // Request Select Bit 0
#define	SCU_DMARS_SEL1				BIT(1)									 // Request Select Bit 1
#define	SCU_DMARS_SEL2				BIT(2)									 // Request Select Bit 2
#define	SCU_DMARS_SEL3				BIT(3)									 // Request Select Bit 3
#define	SCU_DMARS_SEL4				BIT(4)									 // Request Select Bit 4
#define	SCU_DMARS_SEL5				BIT(5)									 // Request Select Bit 5
#define	SCU_DMARS_SEL6				BIT(6)									 // Request Select Bit 6
#define	SCU_DMARS_SEL7				BIT(7)									 // Request Select Bit 7
#define	SCU_DMARS_SEL8				BIT(8)									 // Request Select Bit 8
#define	SCU_DMARS_SEL9				BIT(9)									 // Request Select Bit 9

/* Service Routing Control Register */
#define	SCU_EXTI0_SRC				MMIO32(SCU_BASE + 0xB8)

/* Service Routing Control Register */
#define	SCU_EXTI1_SRC				MMIO32(SCU_BASE + 0xBC)

/* Service Routing Control Register */
#define	SCU_EXTI2_SRC				MMIO32(SCU_BASE + 0xC0)

/* Service Routing Control Register */
#define	SCU_EXTI3_SRC				MMIO32(SCU_BASE + 0xC4)

/* Service Routing Control Register */
#define	SCU_EXTI4_SRC				MMIO32(SCU_BASE + 0xC8)

/* Service Routing Control Register */
#define	SCU_DSP_SRC(n)				MMIO32(SCU_BASE + 0xCC + ((n) * 0x4))

/* Service Routing Control Register */
#define	SCU_UNK0_SRC				MMIO32(SCU_BASE + 0xE8)

/* Service Routing Control Register */
#define	SCU_UNK1_SRC				MMIO32(SCU_BASE + 0xEC)

/* Service Routing Control Register */
#define	SCU_UNK2_SRC				MMIO32(SCU_BASE + 0xF0)

/* Service Routing Control Register */
#define	SCU_EXTI5_SRC				MMIO32(SCU_BASE + 0xF4)

/* Service Routing Control Register */
#define	SCU_EXTI6_SRC				MMIO32(SCU_BASE + 0xF8)

/* Service Routing Control Register */
#define	SCU_EXTI7_SRC				MMIO32(SCU_BASE + 0xFC)


// PLL
// Looks like a CGU module, registers collected using tests on real hardware (using "black box" method).
#define	PLL_BASE						0xF4500000
#define	PLL_OSC							MMIO32(PLL_BASE + 0xA0)
#define	PLL_OSC_LOCK					BIT(0)
#define	PLL_OSC_NDIV					GENMASK(18, 16)			 // Feedback divider (multiply by N+1)
#define	PLL_OSC_NDIV_SHIFT				16

#define	PLL_CON0						MMIO32(PLL_BASE + 0xA4)
#define	PLL_CON0_PLL1_K2				GENMASK(2, 0)			 // div by (K1 * 6 + (K2 - 1))
#define	PLL_CON0_PLL1_K2_SHIFT			0
#define	PLL_CON0_PLL1_K1				GENMASK(6, 3)
#define	PLL_CON0_PLL1_K1_SHIFT			3
#define	PLL_CON0_PLL2_K2				GENMASK(10, 8)			 // div by (K1 * 6 + (K2 - 1))
#define	PLL_CON0_PLL2_K2_SHIFT			8
#define	PLL_CON0_PLL2_K1				GENMASK(14, 11)
#define	PLL_CON0_PLL2_K1_SHIFT			11
#define	PLL_CON0_PLL3_K2				GENMASK(18, 16)			 // div by (K1 * 6 + (K2 - 1))
#define	PLL_CON0_PLL3_K2_SHIFT			16
#define	PLL_CON0_PLL3_K1				GENMASK(22, 19)
#define	PLL_CON0_PLL3_K1_SHIFT			19
#define	PLL_CON0_PLL4_K2				GENMASK(26, 24)			 // div by (K1 * 6 + (K2 - 1))
#define	PLL_CON0_PLL4_K2_SHIFT			24
#define	PLL_CON0_PLL4_K1				GENMASK(30, 27)
#define	PLL_CON0_PLL4_K1_SHIFT			27

#define	PLL_CON1						MMIO32(PLL_BASE + 0xA8)
#define	PLL_CON1_FSYS_CLKSEL			GENMASK(17, 16)			 // Source clock for fSYS (BYPASS: fSYS=fOSC, PLL: fSYS=fPLL / 2)
#define	PLL_CON1_FSYS_CLKSEL_SHIFT		16
#define	PLL_CON1_FSYS_CLKSEL_BYPASS		0x0
#define	PLL_CON1_FSYS_CLKSEL_PLL		0x20000
#define	PLL_CON1_FSYS_CLKSEL_DISABLE	0x30000
#define	PLL_CON1_AHB_CLKSEL				GENMASK(22, 20)			 // Source clock for fPLL
#define	PLL_CON1_AHB_CLKSEL_SHIFT		20
#define	PLL_CON1_AHB_CLKSEL_BYPASS		0x0
#define	PLL_CON1_AHB_CLKSEL_PLL0		0x200000
#define	PLL_CON1_AHB_CLKSEL_PLL1		0x300000
#define	PLL_CON1_AHB_CLKSEL_PLL2		0x400000
#define	PLL_CON1_AHB_CLKSEL_PLL3		0x500000
#define	PLL_CON1_AHB_CLKSEL_PLL4		0x600000
#define	PLL_CON1_FSTM_DIV_EN			BIT(25)					 // Enable fSTM divider
#define	PLL_CON1_FSTM_DIV				GENMASK(29, 28)			 // fSTM divider value (n^2)
#define	PLL_CON1_FSTM_DIV_SHIFT			28
#define	PLL_CON1_FSTM_DIV_1				0x0
#define	PLL_CON1_FSTM_DIV_2				0x10000000
#define	PLL_CON1_FSTM_DIV_4				0x20000000
#define	PLL_CON1_FSTM_DIV_8				0x30000000

#define	PLL_CON2						MMIO32(PLL_BASE + 0xAC)
#define	PLL_CON2_CPU_DIV				GENMASK(9, 8)
#define	PLL_CON2_CPU_DIV_SHIFT			8
#define	PLL_CON2_CPU_DIV_EN				BIT(12)

#define	PLL_STAT						MMIO32(PLL_BASE + 0xB0)
#define	PLL_STAT_LOCK					BIT(13)

#define	PLL_CON3						MMIO32(PLL_BASE + 0xB4)

/* Service Routing Control Register */
#define	PLL_SRC							MMIO32(PLL_BASE + 0xCC)


// SCCU
// Controlling MCU sleep. Very similar to "SCCU" description in the Teltonika TM1Q user manual.
#define	SCCU_BASE					0xF4600000
#define	SCCU_CON0					MMIO32(SCCU_BASE + 0x10)

/* Sleep timer reload */
#define	SCCU_TIMER_REL				MMIO32(SCCU_BASE + 0x14)
#define	SCCU_TIMER_REL_VALUE		GENMASK(12, 0)
#define	SCCU_TIMER_REL_VALUE_SHIFT	0

/* Sleep timer counter */
#define	SCCU_TIMER_CNT				MMIO32(SCCU_BASE + 0x18)
#define	SCCU_TIMER_CNT_VALUE		GENMASK(12, 0)
#define	SCCU_TIMER_CNT_VALUE_SHIFT	0

#define	SCCU_CON1					MMIO32(SCCU_BASE + 0x1C)
#define	SCCU_CON1_CAL				BIT(0)						 // Calibration?
#define	SCCU_CON1_TIMER_START		BIT(1)						 // Start sleep timer
#define	SCCU_CON1_TIMER_RESET		BIT(2)						 // Reset sleep timer

#define	SCCU_CAL					MMIO32(SCCU_BASE + 0x24)
#define	SCCU_CAL_VALUE0				GENMASK(12, 0)
#define	SCCU_CAL_VALUE0_SHIFT		0
#define	SCCU_CAL_VALUE1				GENMASK(25, 13)
#define	SCCU_CAL_VALUE1_SHIFT		13

#define	SCCU_TIMER_DIV				MMIO32(SCCU_BASE + 0x28)
#define	SCCU_TIMER_DIV_VALUE		GENMASK(7, 0)
#define	SCCU_TIMER_DIV_VALUE_SHIFT	0

#define	SCCU_SLEEP_CTRL				MMIO32(SCCU_BASE + 0x2C)
#define	SCCU_SLEEP_CTRL_SLEEP		BIT(0)						 // Enter sleep
#define	SCCU_SLEEP_CTRL_WAKEUP		BIT(1)						 // Force exit sleep

#define	SCCU_CON2					MMIO32(SCCU_BASE + 0x30)
#define	SCCU_CON2_UNK				GENMASK(7, 0)
#define	SCCU_CON2_UNK_SHIFT			0
#define	SCCU_CON2_REL_SUB			GENMASK(17, 16)				 // Substract this value from TIMER_REL (???)
#define	SCCU_CON2_REL_SUB_SHIFT		16

#define	SCCU_CON3					MMIO32(SCCU_BASE + 0x34)

#define	SCCU_STAT					MMIO32(SCCU_BASE + 0x40)
#define	SCCU_STAT_CPU				BIT(0)						 // CPU sleep status
#define	SCCU_STAT_CPU_SLEEP			0x0
#define	SCCU_STAT_CPU_NORMAL		0x1
#define	SCCU_STAT_TPU				BIT(1)						 // TPU sleep status
#define	SCCU_STAT_TPU_SLEEP			0x0
#define	SCCU_STAT_TPU_NORMAL		0x2

/* Service Routing Control Register */
#define	SCCU_WAKE_SRC				MMIO32(SCCU_BASE + 0xA0)

/* Service Routing Control Register */
#define	SCCU_UNK_SRC				MMIO32(SCCU_BASE + 0xA8)


// RTC [MOD_NUM=F049, MOD_REV=00, MOD_32BIT=C0]
// RTC from XC27x5X official public datasheet
#define	RTC_BASE				0xF4700000
/* Clock Control Register */
#define	RTC_CLC					MMIO32(RTC_BASE + 0x00)

/* Module Identifier Register */
#define	RTC_ID					MMIO32(RTC_BASE + 0x08)

/* RTC Shell Control Register */
#define	RTC_CTRL				MMIO32(RTC_BASE + 0x10)
#define	RTC_CTRL_RTCOUTEN		BIT(0)					 // RTC External Interrupt Output Enable
#define	RTC_CTRL_RTCINT			BIT(1)					 // RTC Interrupt Status
#define	RTC_CTRL_CLK32KEN		BIT(2)					 // 32k Clock Enable
#define	RTC_CTRL_PU32K			BIT(3)					 // 32 kHz Oscillator Power Up
#define	RTC_CTRL_CLK_SEL		BIT(4)					 // RTC Logic Clock Select
#define	RTC_CTRL_CLR_RTCINT		BIT(8)					 // Clears RTCINT
#define	RTC_CTRL_RTCBAD			BIT(9)					 // RTC Content Inconsistent Due to Power Supply Drop Down
#define	RTC_CTRL_CLR_RTCBAD		BIT(10)					 // Clears RTCBAD

/* RTC Control Register */
#define	RTC_CON					MMIO32(RTC_BASE + 0x14)
#define	RTC_CON_RUN				BIT(0)					 // RTC Run Bit
#define	RTC_CON_PRE				BIT(1)					 // RTC Input Source Prescaler (8:1) Enable
#define	RTC_CON_T14DEC			BIT(2)					 // Decrement Timer T14 Value
#define	RTC_CON_T14INC			BIT(3)					 // Increment Timer T14 Value
#define	RTC_CON_REFCLK			BIT(4)					 // RTC Input Source Prescaler (32:1) Disable
#define	RTC_CON_ACCPOS			BIT(15)					 // RTC Register Access Possible

/* Timer T14 Count/Reload Register */
#define	RTC_T14					MMIO32(RTC_BASE + 0x18)
#define	RTC_T14_REL				GENMASK(15, 0)			 // Timer T14 Reload Value
#define	RTC_T14_REL_SHIFT		0
#define	RTC_T14_CNT				GENMASK(31, 16)			 // Timer T14 Count Value
#define	RTC_T14_CNT_SHIFT		16

/* RTC Count Register */
#define	RTC_CNT					MMIO32(RTC_BASE + 0x1C)
#define	RTC_CNT_CNT				GENMASK(31, 0)			 // RTC Timer Count Value
#define	RTC_CNT_CNT_SHIFT		0

/* RTC Reload Register */
#define	RTC_REL					MMIO32(RTC_BASE + 0x20)
#define	RTC_REL_REL				GENMASK(31, 0)			 // RTC Timer Reload Value
#define	RTC_REL_REL_SHIFT		0

/* Interrupt Sub-Node Control Register */
#define	RTC_ISNC				MMIO32(RTC_BASE + 0x24)
#define	RTC_ISNC_T14IE			BIT(0)					 // T14 Overflow Interrupt Enable Control Bit
#define	RTC_ISNC_T14IR			BIT(1)					 // T14 Overflow Interrupt Request Flag
#define	RTC_ISNC_RTC0IE			BIT(2)					 // Section CNTx Interrupt Enable Control Bit
#define	RTC_ISNC_RTC0IR			BIT(3)					 // Section CNTx Interrupt Request Flag
#define	RTC_ISNC_RTC1IE			BIT(4)					 // Section CNTx Interrupt Enable Control Bit
#define	RTC_ISNC_RTC1IR			BIT(5)					 // Section CNTx Interrupt Request Flag
#define	RTC_ISNC_RTC2IE			BIT(6)					 // Section CNTx Interrupt Enable Control Bit
#define	RTC_ISNC_RTC2IR			BIT(7)					 // Section CNTx Interrupt Request Flag
#define	RTC_ISNC_RTC3IE			BIT(8)					 // Section CNTx Interrupt Enable Control Bit
#define	RTC_ISNC_RTC3IR			BIT(9)					 // Section CNTx Interrupt Request Flag
#define	RTC_ISNC_ALARMIE		BIT(10)					 // Alarm Interrupt Enable Control Bit
#define	RTC_ISNC_ALARMIR		BIT(11)					 // Alarm Interrupt Request Flag

#define	RTC_UNK0				MMIO32(RTC_BASE + 0x28)

/* RTC Alarm Register */
#define	RTC_ALARM				MMIO32(RTC_BASE + 0x2C)
#define	RTC_ALARM_VALUE			GENMASK(31, 0)
#define	RTC_ALARM_VALUE_SHIFT	0

/* Service Routing Control Register */
#define	RTC_SRC					MMIO32(RTC_BASE + 0xF0)


// GPTU0 [MOD_NUM=0001, MOD_REV=00, MOD_32BIT=C0]
// GPTU from Tricore TC1765 official public datasheet
#define	GPTU0_BASE							0xF4900000
#define	GPTU0								0xF4900000

#define	GPTU1_BASE							0xF4A00000
#define	GPTU1								0xF4A00000

/* Clock Control Register */
#define	GPTU_CLC(base)						MMIO32((base) + 0x00)

/* Module Identifier Register */
#define	GPTU_ID(base)						MMIO32((base) + 0x08)

#define	GPTU_T01IRS(base)					MMIO32((base) + 0x10)
#define	GPTU_T01IRS_T0AINS					GENMASK(1, 0)						 // T0A Input Selection
#define	GPTU_T01IRS_T0AINS_SHIFT			0
#define	GPTU_T01IRS_T0AINS_BYPASS			0x0
#define	GPTU_T01IRS_T0AINS_CNT0				0x1
#define	GPTU_T01IRS_T0AINS_CNT1				0x2
#define	GPTU_T01IRS_T0AINS_CONCAT			0x3
#define	GPTU_T01IRS_T0BINS					GENMASK(3, 2)						 // T0B Input Selection
#define	GPTU_T01IRS_T0BINS_SHIFT			2
#define	GPTU_T01IRS_T0BINS_BYPASS			0x0
#define	GPTU_T01IRS_T0BINS_CNT0				0x4
#define	GPTU_T01IRS_T0BINS_CNT1				0x8
#define	GPTU_T01IRS_T0BINS_CONCAT			0xC
#define	GPTU_T01IRS_T0CINS					GENMASK(5, 4)						 // T0C Input Selection
#define	GPTU_T01IRS_T0CINS_SHIFT			4
#define	GPTU_T01IRS_T0CINS_BYPASS			0x0
#define	GPTU_T01IRS_T0CINS_CNT0				0x10
#define	GPTU_T01IRS_T0CINS_CNT1				0x20
#define	GPTU_T01IRS_T0CINS_CONCAT			0x30
#define	GPTU_T01IRS_T0DINS					GENMASK(7, 6)						 // T0D Input Selection
#define	GPTU_T01IRS_T0DINS_SHIFT			6
#define	GPTU_T01IRS_T0DINS_BYPASS			0x0
#define	GPTU_T01IRS_T0DINS_CNT0				0x40
#define	GPTU_T01IRS_T0DINS_CNT1				0x80
#define	GPTU_T01IRS_T0DINS_CONCAT			0xC0
#define	GPTU_T01IRS_T1AINS					GENMASK(9, 8)						 // T1A Input Selection
#define	GPTU_T01IRS_T1AINS_SHIFT			8
#define	GPTU_T01IRS_T1AINS_BYPASS			0x0
#define	GPTU_T01IRS_T1AINS_CNT0				0x100
#define	GPTU_T01IRS_T1AINS_CNT1				0x200
#define	GPTU_T01IRS_T1AINS_CONCAT			0x300
#define	GPTU_T01IRS_T1BINS					GENMASK(11, 10)						 // T1B Input Selection
#define	GPTU_T01IRS_T1BINS_SHIFT			10
#define	GPTU_T01IRS_T1BINS_BYPASS			0x0
#define	GPTU_T01IRS_T1BINS_CNT0				0x400
#define	GPTU_T01IRS_T1BINS_CNT1				0x800
#define	GPTU_T01IRS_T1BINS_CONCAT			0xC00
#define	GPTU_T01IRS_T1CINS					GENMASK(13, 12)						 // T1C Input Selection
#define	GPTU_T01IRS_T1CINS_SHIFT			12
#define	GPTU_T01IRS_T1CINS_BYPASS			0x0
#define	GPTU_T01IRS_T1CINS_CNT0				0x1000
#define	GPTU_T01IRS_T1CINS_CNT1				0x2000
#define	GPTU_T01IRS_T1CINS_CONCAT			0x3000
#define	GPTU_T01IRS_T1DINS					GENMASK(15, 14)						 // T1D Input Selection
#define	GPTU_T01IRS_T1DINS_SHIFT			14
#define	GPTU_T01IRS_T1DINS_BYPASS			0x0
#define	GPTU_T01IRS_T1DINS_CNT0				0x4000
#define	GPTU_T01IRS_T1DINS_CNT1				0x8000
#define	GPTU_T01IRS_T1DINS_CONCAT			0xC000
#define	GPTU_T01IRS_T0AREL					BIT(16)								 // T0A Reload Source Selection
#define	GPTU_T01IRS_T0BREL					BIT(17)								 // T0B Reload Source Selection
#define	GPTU_T01IRS_T0CREL					BIT(18)								 // T0C Reload Source Selection
#define	GPTU_T01IRS_T0DREL					BIT(19)								 // T0D Reload Source Selection
#define	GPTU_T01IRS_T1AREL					BIT(20)								 // T1A Reload Source Selection
#define	GPTU_T01IRS_T1BREL					BIT(21)								 // T1B Reload Source Selection
#define	GPTU_T01IRS_T1CREL					BIT(22)								 // T1C Reload Source Selection
#define	GPTU_T01IRS_T1DREL					BIT(23)								 // T1D Reload Source Selection
#define	GPTU_T01IRS_T0INC					BIT(24)								 // T0 Carry Input Selection
#define	GPTU_T01IRS_T1INC					BIT(25)								 // T1 Carry Input Selection
#define	GPTU_T01IRS_T01IN0					GENMASK(29, 28)						 // T0 and T1 Global Input CNT0 Selection
#define	GPTU_T01IRS_T01IN0_SHIFT			28
#define	GPTU_T01IRS_T01IN0_OUV_T2A			0x0
#define	GPTU_T01IRS_T01IN0_POS_IN0			0x10000000
#define	GPTU_T01IRS_T01IN0_NEG_IN0			0x20000000
#define	GPTU_T01IRS_T01IN0_BOTH_IN0			0x30000000
#define	GPTU_T01IRS_T01IN1					GENMASK(31, 30)						 // T0 and T1 Global Input CNT1 Selection
#define	GPTU_T01IRS_T01IN1_SHIFT			30
#define	GPTU_T01IRS_T01IN1_OUV_T2B			0x0
#define	GPTU_T01IRS_T01IN1_POS_IN1			0x40000000
#define	GPTU_T01IRS_T01IN1_NEG_IN1			0x80000000
#define	GPTU_T01IRS_T01IN1_BOTH_IN1			0xC0000000

#define	GPTU_T01OTS(base)					MMIO32((base) + 0x14)
#define	GPTU_T01OTS_SOUT00					GENMASK(1, 0)						 // T0 Output 0 Source Selection
#define	GPTU_T01OTS_SOUT00_SHIFT			0
#define	GPTU_T01OTS_SOUT00_A				0x0
#define	GPTU_T01OTS_SOUT00_B				0x1
#define	GPTU_T01OTS_SOUT00_C				0x2
#define	GPTU_T01OTS_SOUT00_D				0x3
#define	GPTU_T01OTS_SOUT01					GENMASK(3, 2)						 // T0 Output 1 Source Selection
#define	GPTU_T01OTS_SOUT01_SHIFT			2
#define	GPTU_T01OTS_SOUT01_A				0x0
#define	GPTU_T01OTS_SOUT01_B				0x4
#define	GPTU_T01OTS_SOUT01_C				0x8
#define	GPTU_T01OTS_SOUT01_D				0xC
#define	GPTU_T01OTS_STRG00					GENMASK(5, 4)						 // T0 Trigger Output 0 Source Selection
#define	GPTU_T01OTS_STRG00_SHIFT			4
#define	GPTU_T01OTS_STRG00_A				0x0
#define	GPTU_T01OTS_STRG00_B				0x10
#define	GPTU_T01OTS_STRG00_C				0x20
#define	GPTU_T01OTS_STRG00_D				0x30
#define	GPTU_T01OTS_STRG01					GENMASK(7, 6)						 // T0 Trigger Output 1 Source Selection
#define	GPTU_T01OTS_STRG01_SHIFT			6
#define	GPTU_T01OTS_STRG01_A				0x0
#define	GPTU_T01OTS_STRG01_B				0x40
#define	GPTU_T01OTS_STRG01_C				0x80
#define	GPTU_T01OTS_STRG01_D				0xC0
#define	GPTU_T01OTS_SSR00					GENMASK(9, 8)						 // T0 Service Request 0 Source Selection
#define	GPTU_T01OTS_SSR00_SHIFT				8
#define	GPTU_T01OTS_SSR00_A					0x0
#define	GPTU_T01OTS_SSR00_B					0x100
#define	GPTU_T01OTS_SSR00_C					0x200
#define	GPTU_T01OTS_SSR00_D					0x300
#define	GPTU_T01OTS_SSR01					GENMASK(11, 10)						 // T0 Service Request 1 Source Selection
#define	GPTU_T01OTS_SSR01_SHIFT				10
#define	GPTU_T01OTS_SSR01_A					0x0
#define	GPTU_T01OTS_SSR01_B					0x400
#define	GPTU_T01OTS_SSR01_C					0x800
#define	GPTU_T01OTS_SSR01_D					0xC00
#define	GPTU_T01OTS_SOUT10					GENMASK(17, 16)						 // T1 Output 0 Source Selection
#define	GPTU_T01OTS_SOUT10_SHIFT			16
#define	GPTU_T01OTS_SOUT10_A				0x0
#define	GPTU_T01OTS_SOUT10_B				0x10000
#define	GPTU_T01OTS_SOUT10_C				0x20000
#define	GPTU_T01OTS_SOUT10_D				0x30000
#define	GPTU_T01OTS_SOUT11					GENMASK(19, 18)						 // T1 Output 1 Source Selection
#define	GPTU_T01OTS_SOUT11_SHIFT			18
#define	GPTU_T01OTS_SOUT11_A				0x0
#define	GPTU_T01OTS_SOUT11_B				0x40000
#define	GPTU_T01OTS_SOUT11_C				0x80000
#define	GPTU_T01OTS_SOUT11_D				0xC0000
#define	GPTU_T01OTS_STRG10					GENMASK(21, 20)						 // T1 Trigger Output 0 Source Selection
#define	GPTU_T01OTS_STRG10_SHIFT			20
#define	GPTU_T01OTS_STRG10_A				0x0
#define	GPTU_T01OTS_STRG10_B				0x100000
#define	GPTU_T01OTS_STRG10_C				0x200000
#define	GPTU_T01OTS_STRG10_D				0x300000
#define	GPTU_T01OTS_STRG11					GENMASK(23, 22)						 // T1 Trigger Output 1 Source Selection
#define	GPTU_T01OTS_STRG11_SHIFT			22
#define	GPTU_T01OTS_STRG11_A				0x0
#define	GPTU_T01OTS_STRG11_B				0x400000
#define	GPTU_T01OTS_STRG11_C				0x800000
#define	GPTU_T01OTS_STRG11_D				0xC00000
#define	GPTU_T01OTS_SSR10					GENMASK(25, 24)						 // T1 Service Request 0 Source Selection
#define	GPTU_T01OTS_SSR10_SHIFT				24
#define	GPTU_T01OTS_SSR10_A					0x0
#define	GPTU_T01OTS_SSR10_B					0x1000000
#define	GPTU_T01OTS_SSR10_C					0x2000000
#define	GPTU_T01OTS_SSR10_D					0x3000000
#define	GPTU_T01OTS_SSR11					GENMASK(27, 26)						 // T1 Service Request 1 Source Selection.
#define	GPTU_T01OTS_SSR11_SHIFT				26
#define	GPTU_T01OTS_SSR11_A					0x0
#define	GPTU_T01OTS_SSR11_B					0x4000000
#define	GPTU_T01OTS_SSR11_C					0x8000000
#define	GPTU_T01OTS_SSR11_D					0xC000000

#define	GPTU_T2CON(base)					MMIO32((base) + 0x18)
#define	GPTU_T2CON_T2ACSRC					GENMASK(1, 0)						 // Timer T2A Count Input Source Control
#define	GPTU_T2CON_T2ACSRC_SHIFT			0
#define	GPTU_T2CON_T2ACSRC_BYPASS			0x0
#define	GPTU_T2CON_T2ACSRC_EXT_COUNT		0x1
#define	GPTU_T2CON_T2ACSRC_QUADRATURE		0x2
#define	GPTU_T2CON_T2ACDIR					GENMASK(3, 2)						 // Timer T2A Direction Control
#define	GPTU_T2CON_T2ACDIR_SHIFT			2
#define	GPTU_T2CON_T2ACDIR_COUNT_UP			0x0
#define	GPTU_T2CON_T2ACDIR_COUNT_DOWN		0x4
#define	GPTU_T2CON_T2ACDIR_EXT_CONT_UP		0x8
#define	GPTU_T2CON_T2ACDIR_EXT_COUNT_DOWN	0xC
#define	GPTU_T2CON_T2ACCLR					GENMASK(5, 4)						 // Timer T2A Clear Control
#define	GPTU_T2CON_T2ACCLR_SHIFT			4
#define	GPTU_T2CON_T2ACCLR_EXT				0x0
#define	GPTU_T2CON_T2ACCLR_CP0_T2			0x10
#define	GPTU_T2CON_T2ACCLR_CP1_T2			0x20
#define	GPTU_T2CON_T2ACOV					GENMASK(7, 6)						 // Timer T2A Overflow/Underflow Generation Control
#define	GPTU_T2CON_T2ACOV_SHIFT				6
#define	GPTU_T2CON_T2ACOV_MODE0				0x0
#define	GPTU_T2CON_T2ACOV_MODE1				0x40
#define	GPTU_T2CON_T2ACOV_MODE2				0x80
#define	GPTU_T2CON_T2ACOV_MODE3				0xC0
#define	GPTU_T2CON_T2ACOS					BIT(8)								 // Timer T2A One-Shot Control.
#define	GPTU_T2CON_T2ADIR					BIT(12)								 // Timer T2A Direction Status Bit.
#define	GPTU_T2CON_T2ADIR_COUNT_UP			0x0
#define	GPTU_T2CON_T2ADIR_COUNT_DOWN		0x1000
#define	GPTU_T2CON_T2SPLIT					BIT(15)								 // Timer T2 Split Control.
#define	GPTU_T2CON_T2BCSRC					GENMASK(17, 16)						 // Timer T2B Count Input Source Control.
#define	GPTU_T2CON_T2BCSRC_SHIFT			16
#define	GPTU_T2CON_T2BCSRC_BYPASS			0x0
#define	GPTU_T2CON_T2BCSRC_EXT_COUNT		0x10000
#define	GPTU_T2CON_T2BCSRC_QUADRATURE		0x20000
#define	GPTU_T2CON_T2BCDIR					GENMASK(19, 18)						 // Timer T2B Direction Control.
#define	GPTU_T2CON_T2BCDIR_SHIFT			18
#define	GPTU_T2CON_T2BCDIR_COUNT_UP			0x0
#define	GPTU_T2CON_T2BCDIR_COUNT_DOWN		0x40000
#define	GPTU_T2CON_T2BCDIR_EXT_CONT_UP		0x80000
#define	GPTU_T2CON_T2BCDIR_EXT_COUNT_DOWN	0xC0000
#define	GPTU_T2CON_T2BCCLR					GENMASK(21, 20)						 // Timer T2B Clear Control.
#define	GPTU_T2CON_T2BCCLR_SHIFT			20
#define	GPTU_T2CON_T2BCCLR_EXT				0x0
#define	GPTU_T2CON_T2BCCLR_CP0_T2			0x100000
#define	GPTU_T2CON_T2BCCLR_CP1_T2			0x200000
#define	GPTU_T2CON_T2BCOV					GENMASK(23, 22)						 // Timer T2B Overflow/Underflow Generation Control.
#define	GPTU_T2CON_T2BCOV_SHIFT				22
#define	GPTU_T2CON_T2BCOV_MODE0				0x0
#define	GPTU_T2CON_T2BCOV_MODE1				0x400000
#define	GPTU_T2CON_T2BCOV_MODE2				0x800000
#define	GPTU_T2CON_T2BCOV_MODE3				0xC00000
#define	GPTU_T2CON_T2BCOS					BIT(24)								 // Timer T2B One-Shot Control.
#define	GPTU_T2CON_T2BDIR					BIT(28)								 // Timer T2B Direction Status Bit.
#define	GPTU_T2CON_T2BDIR_COUNT_UP			0x0
#define	GPTU_T2CON_T2BDIR_COUNT_DOWN		0x10000000

#define	GPTU_T2RCCON(base)					MMIO32((base) + 0x1C)
#define	GPTU_T2RCCON_T2AMRC0				GENMASK(2, 0)						 // Timer T2A Reload/Capture 0 Mode Control
#define	GPTU_T2RCCON_T2AMRC0_SHIFT			0
#define	GPTU_T2RCCON_T2AMRC1				GENMASK(6, 4)						 // Timer T2A Reload/Capture 1 Mode Control
#define	GPTU_T2RCCON_T2AMRC1_SHIFT			4
#define	GPTU_T2RCCON_T2BMRC0				GENMASK(18, 16)						 // Timer T2B Reload/Capture 0 Mode Control
#define	GPTU_T2RCCON_T2BMRC0_SHIFT			16
#define	GPTU_T2RCCON_T2BMRC1				GENMASK(22, 20)						 // Timer T2B Reload/Capture 1 Mode Control
#define	GPTU_T2RCCON_T2BMRC1_SHIFT			20

#define	GPTU_T2AIS(base)					MMIO32((base) + 0x20)
#define	GPTU_T2AIS_T2AICNT					GENMASK(2, 0)						 // Timer T2A External Count Input Selection
#define	GPTU_T2AIS_T2AICNT_SHIFT			0
#define	GPTU_T2AIS_T2AISTR					GENMASK(6, 4)						 // Timer T2A External Start Input Selection
#define	GPTU_T2AIS_T2AISTR_SHIFT			4
#define	GPTU_T2AIS_T2AISTP					GENMASK(10, 8)						 // Timer T2A External Stop Input Selection
#define	GPTU_T2AIS_T2AISTP_SHIFT			8
#define	GPTU_T2AIS_T2AIUD					GENMASK(14, 12)						 // Timer T2A External Up/Down Input Selection
#define	GPTU_T2AIS_T2AIUD_SHIFT				12
#define	GPTU_T2AIS_T2AICLR					GENMASK(18, 16)						 // Timer T2A External Clear Input Selection
#define	GPTU_T2AIS_T2AICLR_SHIFT			16
#define	GPTU_T2AIS_T2AIRC0					GENMASK(22, 20)						 // Timer T2A External Reload/Capture 0 Input Selection
#define	GPTU_T2AIS_T2AIRC0_SHIFT			20
#define	GPTU_T2AIS_T2AIRC1					GENMASK(26, 24)						 // Timer T2A External Reload/Capture 1 Input Selection
#define	GPTU_T2AIS_T2AIRC1_SHIFT			24

#define	GPTU_T2BIS(base)					MMIO32((base) + 0x24)
#define	GPTU_T2BIS_T2BICNT					GENMASK(2, 0)						 // Timer T2B External Count Input Selection
#define	GPTU_T2BIS_T2BICNT_SHIFT			0
#define	GPTU_T2BIS_T2BISTR					GENMASK(6, 4)						 // Timer T2B External Start Input Selection
#define	GPTU_T2BIS_T2BISTR_SHIFT			4
#define	GPTU_T2BIS_T2BISTP					GENMASK(10, 8)						 // Timer T2B External Stop Input Selection
#define	GPTU_T2BIS_T2BISTP_SHIFT			8
#define	GPTU_T2BIS_T2BIUD					GENMASK(14, 12)						 // Timer T2B External Up/Down Input Selection
#define	GPTU_T2BIS_T2BIUD_SHIFT				12
#define	GPTU_T2BIS_T2BICLR					GENMASK(18, 16)						 // Timer T2B External Clear Input Selection
#define	GPTU_T2BIS_T2BICLR_SHIFT			16
#define	GPTU_T2BIS_T2BIRC0					GENMASK(22, 20)						 // Timer T2B External Reload/Capture 0 Input Selection
#define	GPTU_T2BIS_T2BIRC0_SHIFT			20
#define	GPTU_T2BIS_T2BIRC1					GENMASK(26, 24)						 // Timer T2B External Reload/Capture 1 Input Selection
#define	GPTU_T2BIS_T2BIRC1_SHIFT			24

#define	GPTU_T2ES(base)						MMIO32((base) + 0x28)
#define	GPTU_T2ES_T2AECNT					GENMASK(1, 0)						 // Timer T2A External Count Input Active Edge Selection
#define	GPTU_T2ES_T2AECNT_SHIFT				0
#define	GPTU_T2ES_T2AESTR					GENMASK(3, 2)						 // Timer T2A External Start Input Active Edge Selection
#define	GPTU_T2ES_T2AESTR_SHIFT				2
#define	GPTU_T2ES_T2AESTP					GENMASK(5, 4)						 // Timer T2A External Stop Input Active Edge Selection
#define	GPTU_T2ES_T2AESTP_SHIFT				4
#define	GPTU_T2ES_T2AEUD					GENMASK(7, 6)						 // Timer T2A External Up/Down Input Active Edge Selection
#define	GPTU_T2ES_T2AEUD_SHIFT				6
#define	GPTU_T2ES_T2AECLR					GENMASK(9, 8)						 // Timer T2A External Clear Input Active Edge Selection
#define	GPTU_T2ES_T2AECLR_SHIFT				8
#define	GPTU_T2ES_T2AERC0					GENMASK(11, 10)						 // Timer T2A External Reload/Capture 0 Input Active Edge Selection
#define	GPTU_T2ES_T2AERC0_SHIFT				10
#define	GPTU_T2ES_T2AERC1					GENMASK(13, 12)						 // Timer T2A External Reload/Capture 1 Input Active Edge Selection
#define	GPTU_T2ES_T2AERC1_SHIFT				12
#define	GPTU_T2ES_T2BECNT					GENMASK(17, 16)						 // Timer T2B External Count Input Active Edge Selection
#define	GPTU_T2ES_T2BECNT_SHIFT				16
#define	GPTU_T2ES_T2BESTR					GENMASK(19, 18)						 // Timer T2B External Start Input Active Edge Selection
#define	GPTU_T2ES_T2BESTR_SHIFT				18
#define	GPTU_T2ES_T2BESTP					GENMASK(21, 20)						 // Timer T2B External Stop Input Active Edge Selection
#define	GPTU_T2ES_T2BESTP_SHIFT				20
#define	GPTU_T2ES_T2BEUD					GENMASK(23, 22)						 // Timer T2B External Up/Down Input Active Edge Selection
#define	GPTU_T2ES_T2BEUD_SHIFT				22
#define	GPTU_T2ES_T2BECLR					GENMASK(25, 24)						 // Timer T2B External Clear Input Active Edge Selection
#define	GPTU_T2ES_T2BECLR_SHIFT				24
#define	GPTU_T2ES_T2BERC0					GENMASK(27, 26)						 // Timer T2B External Reload/Capture 0 Input Active Edge Selection
#define	GPTU_T2ES_T2BERC0_SHIFT				26
#define	GPTU_T2ES_T2BERC1					GENMASK(29, 28)						 // Timer T2B External Reload/Capture 1 Input Active Edge Selection
#define	GPTU_T2ES_T2BERC1_SHIFT				28

#define	GPTU_OSEL(base)						MMIO32((base) + 0x2C)
#define	GPTU_OSEL_SO0						GENMASK(2, 0)						 // GPTU Output 0 Source Selection
#define	GPTU_OSEL_SO0_SHIFT					0
#define	GPTU_OSEL_SO0_OUT00					0x0
#define	GPTU_OSEL_SO0_OUT01					0x1
#define	GPTU_OSEL_SO0_OUT10					0x2
#define	GPTU_OSEL_SO0_OUT11					0x3
#define	GPTU_OSEL_SO0_OUV_T2A				0x4
#define	GPTU_OSEL_SO0_OUV_T2B				0x5
#define	GPTU_OSEL_SO0_UNK0					0x6
#define	GPTU_OSEL_SO0_UNK1					0x7
#define	GPTU_OSEL_SO1						GENMASK(6, 4)						 // GPTU Output 1 Source Selection
#define	GPTU_OSEL_SO1_SHIFT					4
#define	GPTU_OSEL_SO1_OUT00					0x0
#define	GPTU_OSEL_SO1_OUT01					0x10
#define	GPTU_OSEL_SO1_OUT10					0x20
#define	GPTU_OSEL_SO1_OUT11					0x30
#define	GPTU_OSEL_SO1_OUV_T2A				0x40
#define	GPTU_OSEL_SO1_OUV_T2B				0x50
#define	GPTU_OSEL_SO1_UNK0					0x60
#define	GPTU_OSEL_SO1_UNK1					0x70
#define	GPTU_OSEL_SO2						GENMASK(10, 8)						 // GPTU Output 2 Source Selection
#define	GPTU_OSEL_SO2_SHIFT					8
#define	GPTU_OSEL_SO2_OUT00					0x0
#define	GPTU_OSEL_SO2_OUT01					0x100
#define	GPTU_OSEL_SO2_OUT10					0x200
#define	GPTU_OSEL_SO2_OUT11					0x300
#define	GPTU_OSEL_SO2_OUV_T2A				0x400
#define	GPTU_OSEL_SO2_OUV_T2B				0x500
#define	GPTU_OSEL_SO2_UNK0					0x600
#define	GPTU_OSEL_SO2_UNK1					0x700
#define	GPTU_OSEL_SO3						GENMASK(14, 12)						 // GPTU Output 3 Source Selection
#define	GPTU_OSEL_SO3_SHIFT					12
#define	GPTU_OSEL_SO3_OUT00					0x0
#define	GPTU_OSEL_SO3_OUT01					0x1000
#define	GPTU_OSEL_SO3_OUT10					0x2000
#define	GPTU_OSEL_SO3_OUT11					0x3000
#define	GPTU_OSEL_SO3_OUV_T2A				0x4000
#define	GPTU_OSEL_SO3_OUV_T2B				0x5000
#define	GPTU_OSEL_SO3_UNK0					0x6000
#define	GPTU_OSEL_SO3_UNK1					0x7000
#define	GPTU_OSEL_SO4						GENMASK(18, 16)						 // GPTU Output 4 Source Selection
#define	GPTU_OSEL_SO4_SHIFT					16
#define	GPTU_OSEL_SO4_OUT00					0x0
#define	GPTU_OSEL_SO4_OUT01					0x10000
#define	GPTU_OSEL_SO4_OUT10					0x20000
#define	GPTU_OSEL_SO4_OUT11					0x30000
#define	GPTU_OSEL_SO4_OUV_T2A				0x40000
#define	GPTU_OSEL_SO4_OUV_T2B				0x50000
#define	GPTU_OSEL_SO4_UNK0					0x60000
#define	GPTU_OSEL_SO4_UNK1					0x70000
#define	GPTU_OSEL_SO5						GENMASK(22, 20)						 // GPTU Output 5 Source Selection
#define	GPTU_OSEL_SO5_SHIFT					20
#define	GPTU_OSEL_SO5_OUT00					0x0
#define	GPTU_OSEL_SO5_OUT01					0x100000
#define	GPTU_OSEL_SO5_OUT10					0x200000
#define	GPTU_OSEL_SO5_OUT11					0x300000
#define	GPTU_OSEL_SO5_OUV_T2A				0x400000
#define	GPTU_OSEL_SO5_OUV_T2B				0x500000
#define	GPTU_OSEL_SO5_UNK0					0x600000
#define	GPTU_OSEL_SO5_UNK1					0x700000
#define	GPTU_OSEL_SO6						GENMASK(26, 24)						 // GPTU Output 6 Source Selection
#define	GPTU_OSEL_SO6_SHIFT					24
#define	GPTU_OSEL_SO6_OUT00					0x0
#define	GPTU_OSEL_SO6_OUT01					0x1000000
#define	GPTU_OSEL_SO6_OUT10					0x2000000
#define	GPTU_OSEL_SO6_OUT11					0x3000000
#define	GPTU_OSEL_SO6_OUV_T2A				0x4000000
#define	GPTU_OSEL_SO6_OUV_T2B				0x5000000
#define	GPTU_OSEL_SO6_UNK0					0x6000000
#define	GPTU_OSEL_SO6_UNK1					0x7000000
#define	GPTU_OSEL_SO7						GENMASK(30, 28)						 // GPTU Output 7 Source Selection
#define	GPTU_OSEL_SO7_SHIFT					28
#define	GPTU_OSEL_SO7_OUT00					0x0
#define	GPTU_OSEL_SO7_OUT01					0x10000000
#define	GPTU_OSEL_SO7_OUT10					0x20000000
#define	GPTU_OSEL_SO7_OUT11					0x30000000
#define	GPTU_OSEL_SO7_OUV_T2A				0x40000000
#define	GPTU_OSEL_SO7_OUV_T2B				0x50000000
#define	GPTU_OSEL_SO7_UNK0					0x60000000
#define	GPTU_OSEL_SO7_UNK1					0x70000000

#define	GPTU_OUT(base)						MMIO32((base) + 0x30)
#define	GPTU_OUT_OUT0						BIT(0)								 // GPTU Output State Bit 0
#define	GPTU_OUT_OUT1						BIT(1)								 // GPTU Output State Bit 1
#define	GPTU_OUT_OUT2						BIT(2)								 // GPTU Output State Bit 2
#define	GPTU_OUT_OUT3						BIT(3)								 // GPTU Output State Bit 3
#define	GPTU_OUT_OUT4						BIT(4)								 // GPTU Output State Bit 4
#define	GPTU_OUT_OUT5						BIT(5)								 // GPTU Output State Bit 5
#define	GPTU_OUT_OUT6						BIT(6)								 // GPTU Output State Bit 6
#define	GPTU_OUT_OUT7						BIT(7)								 // GPTU Output State Bit 7
#define	GPTU_OUT_CLRO0						BIT(8)								 // GPTU Output 0 Clear Bit
#define	GPTU_OUT_CLRO1						BIT(9)								 // GPTU Output 1 Clear Bit
#define	GPTU_OUT_CLRO2						BIT(10)								 // GPTU Output 2 Clear Bit
#define	GPTU_OUT_CLRO3						BIT(11)								 // GPTU Output 3 Clear Bit
#define	GPTU_OUT_CLRO4						BIT(12)								 // GPTU Output 4 Clear Bit
#define	GPTU_OUT_CLRO5						BIT(13)								 // GPTU Output 5 Clear Bit
#define	GPTU_OUT_CLRO6						BIT(14)								 // GPTU Output 6 Clear Bit
#define	GPTU_OUT_CLRO7						BIT(15)								 // GPTU Output 7 Clear Bit
#define	GPTU_OUT_SETO0						BIT(16)								 // GPTU Output 0 Set Bit
#define	GPTU_OUT_SETO1						BIT(17)								 // GPTU Output 1 Set Bit
#define	GPTU_OUT_SETO2						BIT(18)								 // GPTU Output 2 Set Bit
#define	GPTU_OUT_SETO3						BIT(19)								 // GPTU Output 3 Set Bit
#define	GPTU_OUT_SETO4						BIT(20)								 // GPTU Output 4 Set Bit
#define	GPTU_OUT_SETO5						BIT(21)								 // GPTU Output 5 Set Bit
#define	GPTU_OUT_SETO6						BIT(22)								 // GPTU Output 6 Set Bit
#define	GPTU_OUT_SETO7						BIT(23)								 // GPTU Output 7 Set Bit

/* T0 Count register (32 bit) */
#define	GPTU_T0DCBA(base)					MMIO32((base) + 0x34)
#define	GPTU_T0DCBA_T0A						GENMASK(7, 0)
#define	GPTU_T0DCBA_T0A_SHIFT				0
#define	GPTU_T0DCBA_T0B						GENMASK(15, 8)
#define	GPTU_T0DCBA_T0B_SHIFT				8
#define	GPTU_T0DCBA_T0C						GENMASK(23, 16)
#define	GPTU_T0DCBA_T0C_SHIFT				16
#define	GPTU_T0DCBA_T0D						GENMASK(31, 24)
#define	GPTU_T0DCBA_T0D_SHIFT				24

/* T0 Count register (24 bit) */
#define	GPTU_T0CBA(base)					MMIO32((base) + 0x38)
#define	GPTU_T0CBA_T0A						GENMASK(7, 0)
#define	GPTU_T0CBA_T0A_SHIFT				0
#define	GPTU_T0CBA_T0B						GENMASK(15, 8)
#define	GPTU_T0CBA_T0B_SHIFT				8
#define	GPTU_T0CBA_T0C						GENMASK(23, 16)
#define	GPTU_T0CBA_T0C_SHIFT				16

/* T0 Reload register (32 bit) */
#define	GPTU_T0RDCBA(base)					MMIO32((base) + 0x3C)
#define	GPTU_T0RDCBA_T0RA					GENMASK(7, 0)
#define	GPTU_T0RDCBA_T0RA_SHIFT				0
#define	GPTU_T0RDCBA_T0RB					GENMASK(15, 8)
#define	GPTU_T0RDCBA_T0RB_SHIFT				8
#define	GPTU_T0RDCBA_T0RC					GENMASK(23, 16)
#define	GPTU_T0RDCBA_T0RC_SHIFT				16
#define	GPTU_T0RDCBA_T0RD					GENMASK(31, 24)
#define	GPTU_T0RDCBA_T0RD_SHIFT				24

/* T0 Reload register (24 bit) */
#define	GPTU_T0RCBA(base)					MMIO32((base) + 0x40)
#define	GPTU_T0RCBA_T0RA					GENMASK(7, 0)
#define	GPTU_T0RCBA_T0RA_SHIFT				0
#define	GPTU_T0RCBA_T0RB					GENMASK(15, 8)
#define	GPTU_T0RCBA_T0RB_SHIFT				8
#define	GPTU_T0RCBA_T0RC					GENMASK(23, 16)
#define	GPTU_T0RCBA_T0RC_SHIFT				16

/* T1 Count register (32 bit) */
#define	GPTU_T1DCBA(base)					MMIO32((base) + 0x44)
#define	GPTU_T1DCBA_T1A						GENMASK(7, 0)
#define	GPTU_T1DCBA_T1A_SHIFT				0
#define	GPTU_T1DCBA_T1B						GENMASK(15, 8)
#define	GPTU_T1DCBA_T1B_SHIFT				8
#define	GPTU_T1DCBA_T1C						GENMASK(23, 16)
#define	GPTU_T1DCBA_T1C_SHIFT				16
#define	GPTU_T1DCBA_T1D						GENMASK(31, 24)
#define	GPTU_T1DCBA_T1D_SHIFT				24

/* T1 Count register (24 bit) */
#define	GPTU_T1CBA(base)					MMIO32((base) + 0x48)
#define	GPTU_T1CBA_T1A						GENMASK(7, 0)
#define	GPTU_T1CBA_T1A_SHIFT				0
#define	GPTU_T1CBA_T1B						GENMASK(15, 8)
#define	GPTU_T1CBA_T1B_SHIFT				8
#define	GPTU_T1CBA_T1C						GENMASK(23, 16)
#define	GPTU_T1CBA_T1C_SHIFT				16

/* T1 Reload register (32 bit) */
#define	GPTU_T1RDCBA(base)					MMIO32((base) + 0x4C)
#define	GPTU_T1RDCBA_T1RA					GENMASK(7, 0)
#define	GPTU_T1RDCBA_T1RA_SHIFT				0
#define	GPTU_T1RDCBA_T1RB					GENMASK(15, 8)
#define	GPTU_T1RDCBA_T1RB_SHIFT				8
#define	GPTU_T1RDCBA_T1RC					GENMASK(23, 16)
#define	GPTU_T1RDCBA_T1RC_SHIFT				16
#define	GPTU_T1RDCBA_T1RD					GENMASK(31, 24)
#define	GPTU_T1RDCBA_T1RD_SHIFT				24

/* T1 Reload register (24 bit) */
#define	GPTU_T1RCBA(base)					MMIO32((base) + 0x50)
#define	GPTU_T1RCBA_T1RA					GENMASK(7, 0)
#define	GPTU_T1RCBA_T1RA_SHIFT				0
#define	GPTU_T1RCBA_T1RB					GENMASK(15, 8)
#define	GPTU_T1RCBA_T1RB_SHIFT				8
#define	GPTU_T1RCBA_T1RC					GENMASK(23, 16)
#define	GPTU_T1RCBA_T1RC_SHIFT				16

#define	GPTU_T2(base)						MMIO32((base) + 0x54)
#define	GPTU_T2_T2A							GENMASK(15, 0)						 // T2A Contents
#define	GPTU_T2_T2A_SHIFT					0
#define	GPTU_T2_T2B							GENMASK(31, 16)						 // T2B Contents
#define	GPTU_T2_T2B_SHIFT					16

#define	GPTU_T2RC0(base)					MMIO32((base) + 0x58)
#define	GPTU_T2RC0_T2ARC0					GENMASK(15, 0)						 // T2A Reload/Capture Value
#define	GPTU_T2RC0_T2ARC0_SHIFT				0
#define	GPTU_T2RC0_T2BRC0					GENMASK(31, 16)						 // T2B Reload/Capture Value
#define	GPTU_T2RC0_T2BRC0_SHIFT				16

#define	GPTU_T2RC1(base)					MMIO32((base) + 0x5C)
#define	GPTU_T2RC1_T2ARC1					GENMASK(15, 0)						 // T2A Reload/Capture Value
#define	GPTU_T2RC1_T2ARC1_SHIFT				0
#define	GPTU_T2RC1_T2BRC1					GENMASK(31, 16)						 // T2B Reload/Capture Value
#define	GPTU_T2RC1_T2BRC1_SHIFT				16

#define	GPTU_T012RUN(base)					MMIO32((base) + 0x60)
#define	GPTU_T012RUN_T0ARUN					BIT(0)								 // Timer T0A Run Control.
#define	GPTU_T012RUN_T0BRUN					BIT(1)								 // Timer T0B Run Control.
#define	GPTU_T012RUN_T0CRUN					BIT(2)								 // Timer T0C Run Control.
#define	GPTU_T012RUN_T0DRUN					BIT(3)								 // Timer T0D Run Control.
#define	GPTU_T012RUN_T1ARUN					BIT(4)								 // Timer T1A Run Control.
#define	GPTU_T012RUN_T1BRUN					BIT(5)								 // Timer T1B Run Control.
#define	GPTU_T012RUN_T1CRUN					BIT(6)								 // Timer T1C Run Control.
#define	GPTU_T012RUN_T1DRUN					BIT(7)								 // Timer T1D Run Control.
#define	GPTU_T012RUN_T2ARUN					BIT(8)								 // Timer T2A Run Status Bit.
#define	GPTU_T012RUN_T2ASETR				BIT(9)								 // Timer T2A Run Set Bit.
#define	GPTU_T012RUN_T2ACLRR				BIT(10)								 // Timer T2A Run Clear Bit.
#define	GPTU_T012RUN_T2BRUN					BIT(12)								 // Timer T2B Run Status Bit.
#define	GPTU_T012RUN_T2BSETR				BIT(13)								 // Timer T2B Run Set Bit.
#define	GPTU_T012RUN_T2BCLRR				BIT(14)								 // Timer T2B Run Clear Bit.

/* Service Request Source Selection Register */
#define	GPTU_SRSEL(base)					MMIO32((base) + 0xDC)
#define	GPTU_SRSEL_SSR7						GENMASK(3, 0)						 // GPTU IRQ 7 Source Selection
#define	GPTU_SRSEL_SSR7_SHIFT				0
#define	GPTU_SRSEL_SSR7_START_A				0x0
#define	GPTU_SRSEL_SSR7_STOP_A				0x1
#define	GPTU_SRSEL_SSR7_UPDOWN_A			0x2
#define	GPTU_SRSEL_SSR7_CLEAR_A				0x3
#define	GPTU_SRSEL_SSR7_RLCP0_A				0x4
#define	GPTU_SRSEL_SSR7_RLCP1_A				0x5
#define	GPTU_SRSEL_SSR7_OUV_T2A				0x6
#define	GPTU_SRSEL_SSR7_OUV_T2B				0x7
#define	GPTU_SRSEL_SSR7_START_B				0x8
#define	GPTU_SRSEL_SSR7_STOP_B				0x9
#define	GPTU_SRSEL_SSR7_RLCP0_B				0xA
#define	GPTU_SRSEL_SSR7_RLCP1_B				0xB
#define	GPTU_SRSEL_SSR7_SR00				0xC
#define	GPTU_SRSEL_SSR7_SR01				0xD
#define	GPTU_SRSEL_SSR7_SR10				0xE
#define	GPTU_SRSEL_SSR7_SR11				0xF
#define	GPTU_SRSEL_SSR6						GENMASK(7, 4)						 // GPTU IRQ 6 Source Selection
#define	GPTU_SRSEL_SSR6_SHIFT				4
#define	GPTU_SRSEL_SSR6_START_A				0x0
#define	GPTU_SRSEL_SSR6_STOP_A				0x10
#define	GPTU_SRSEL_SSR6_UPDOWN_A			0x20
#define	GPTU_SRSEL_SSR6_CLEAR_A				0x30
#define	GPTU_SRSEL_SSR6_RLCP0_A				0x40
#define	GPTU_SRSEL_SSR6_RLCP1_A				0x50
#define	GPTU_SRSEL_SSR6_OUV_T2A				0x60
#define	GPTU_SRSEL_SSR6_OUV_T2B				0x70
#define	GPTU_SRSEL_SSR6_START_B				0x80
#define	GPTU_SRSEL_SSR6_STOP_B				0x90
#define	GPTU_SRSEL_SSR6_RLCP0_B				0xA0
#define	GPTU_SRSEL_SSR6_RLCP1_B				0xB0
#define	GPTU_SRSEL_SSR6_SR00				0xC0
#define	GPTU_SRSEL_SSR6_SR01				0xD0
#define	GPTU_SRSEL_SSR6_SR10				0xE0
#define	GPTU_SRSEL_SSR6_SR11				0xF0
#define	GPTU_SRSEL_SSR5						GENMASK(11, 8)						 // GPTU IRQ 5 Source Selection
#define	GPTU_SRSEL_SSR5_SHIFT				8
#define	GPTU_SRSEL_SSR5_START_A				0x0
#define	GPTU_SRSEL_SSR5_STOP_A				0x100
#define	GPTU_SRSEL_SSR5_UPDOWN_A			0x200
#define	GPTU_SRSEL_SSR5_CLEAR_A				0x300
#define	GPTU_SRSEL_SSR5_RLCP0_A				0x400
#define	GPTU_SRSEL_SSR5_RLCP1_A				0x500
#define	GPTU_SRSEL_SSR5_OUV_T2A				0x600
#define	GPTU_SRSEL_SSR5_OUV_T2B				0x700
#define	GPTU_SRSEL_SSR5_START_B				0x800
#define	GPTU_SRSEL_SSR5_STOP_B				0x900
#define	GPTU_SRSEL_SSR5_RLCP0_B				0xA00
#define	GPTU_SRSEL_SSR5_RLCP1_B				0xB00
#define	GPTU_SRSEL_SSR5_SR00				0xC00
#define	GPTU_SRSEL_SSR5_SR01				0xD00
#define	GPTU_SRSEL_SSR5_SR10				0xE00
#define	GPTU_SRSEL_SSR5_SR11				0xF00
#define	GPTU_SRSEL_SSR4						GENMASK(15, 12)						 // GPTU IRQ 4 Source Selection
#define	GPTU_SRSEL_SSR4_SHIFT				12
#define	GPTU_SRSEL_SSR4_START_A				0x0
#define	GPTU_SRSEL_SSR4_STOP_A				0x1000
#define	GPTU_SRSEL_SSR4_UPDOWN_A			0x2000
#define	GPTU_SRSEL_SSR4_CLEAR_A				0x3000
#define	GPTU_SRSEL_SSR4_RLCP0_A				0x4000
#define	GPTU_SRSEL_SSR4_RLCP1_A				0x5000
#define	GPTU_SRSEL_SSR4_OUV_T2A				0x6000
#define	GPTU_SRSEL_SSR4_OUV_T2B				0x7000
#define	GPTU_SRSEL_SSR4_START_B				0x8000
#define	GPTU_SRSEL_SSR4_STOP_B				0x9000
#define	GPTU_SRSEL_SSR4_RLCP0_B				0xA000
#define	GPTU_SRSEL_SSR4_RLCP1_B				0xB000
#define	GPTU_SRSEL_SSR4_SR00				0xC000
#define	GPTU_SRSEL_SSR4_SR01				0xD000
#define	GPTU_SRSEL_SSR4_SR10				0xE000
#define	GPTU_SRSEL_SSR4_SR11				0xF000
#define	GPTU_SRSEL_SSR3						GENMASK(19, 16)						 // GPTU IRQ 3 Source Selection
#define	GPTU_SRSEL_SSR3_SHIFT				16
#define	GPTU_SRSEL_SSR3_START_A				0x0
#define	GPTU_SRSEL_SSR3_STOP_A				0x10000
#define	GPTU_SRSEL_SSR3_UPDOWN_A			0x20000
#define	GPTU_SRSEL_SSR3_CLEAR_A				0x30000
#define	GPTU_SRSEL_SSR3_RLCP0_A				0x40000
#define	GPTU_SRSEL_SSR3_RLCP1_A				0x50000
#define	GPTU_SRSEL_SSR3_OUV_T2A				0x60000
#define	GPTU_SRSEL_SSR3_OUV_T2B				0x70000
#define	GPTU_SRSEL_SSR3_START_B				0x80000
#define	GPTU_SRSEL_SSR3_STOP_B				0x90000
#define	GPTU_SRSEL_SSR3_RLCP0_B				0xA0000
#define	GPTU_SRSEL_SSR3_RLCP1_B				0xB0000
#define	GPTU_SRSEL_SSR3_SR00				0xC0000
#define	GPTU_SRSEL_SSR3_SR01				0xD0000
#define	GPTU_SRSEL_SSR3_SR10				0xE0000
#define	GPTU_SRSEL_SSR3_SR11				0xF0000
#define	GPTU_SRSEL_SSR2						GENMASK(23, 20)						 // GPTU IRQ 2 Source Selection
#define	GPTU_SRSEL_SSR2_SHIFT				20
#define	GPTU_SRSEL_SSR2_START_A				0x0
#define	GPTU_SRSEL_SSR2_STOP_A				0x100000
#define	GPTU_SRSEL_SSR2_UPDOWN_A			0x200000
#define	GPTU_SRSEL_SSR2_CLEAR_A				0x300000
#define	GPTU_SRSEL_SSR2_RLCP0_A				0x400000
#define	GPTU_SRSEL_SSR2_RLCP1_A				0x500000
#define	GPTU_SRSEL_SSR2_OUV_T2A				0x600000
#define	GPTU_SRSEL_SSR2_OUV_T2B				0x700000
#define	GPTU_SRSEL_SSR2_START_B				0x800000
#define	GPTU_SRSEL_SSR2_STOP_B				0x900000
#define	GPTU_SRSEL_SSR2_RLCP0_B				0xA00000
#define	GPTU_SRSEL_SSR2_RLCP1_B				0xB00000
#define	GPTU_SRSEL_SSR2_SR00				0xC00000
#define	GPTU_SRSEL_SSR2_SR01				0xD00000
#define	GPTU_SRSEL_SSR2_SR10				0xE00000
#define	GPTU_SRSEL_SSR2_SR11				0xF00000
#define	GPTU_SRSEL_SSR1						GENMASK(27, 24)						 // GPTU IRQ 1 Source Selection
#define	GPTU_SRSEL_SSR1_SHIFT				24
#define	GPTU_SRSEL_SSR1_START_A				0x0
#define	GPTU_SRSEL_SSR1_STOP_A				0x1000000
#define	GPTU_SRSEL_SSR1_UPDOWN_A			0x2000000
#define	GPTU_SRSEL_SSR1_CLEAR_A				0x3000000
#define	GPTU_SRSEL_SSR1_RLCP0_A				0x4000000
#define	GPTU_SRSEL_SSR1_RLCP1_A				0x5000000
#define	GPTU_SRSEL_SSR1_OUV_T2A				0x6000000
#define	GPTU_SRSEL_SSR1_OUV_T2B				0x7000000
#define	GPTU_SRSEL_SSR1_START_B				0x8000000
#define	GPTU_SRSEL_SSR1_STOP_B				0x9000000
#define	GPTU_SRSEL_SSR1_RLCP0_B				0xA000000
#define	GPTU_SRSEL_SSR1_RLCP1_B				0xB000000
#define	GPTU_SRSEL_SSR1_SR00				0xC000000
#define	GPTU_SRSEL_SSR1_SR01				0xD000000
#define	GPTU_SRSEL_SSR1_SR10				0xE000000
#define	GPTU_SRSEL_SSR1_SR11				0xF000000
#define	GPTU_SRSEL_SSR0						GENMASK(31, 28)						 // GPTU IRQ 0 Source Selection
#define	GPTU_SRSEL_SSR0_SHIFT				28
#define	GPTU_SRSEL_SSR0_START_A				0x0
#define	GPTU_SRSEL_SSR0_STOP_A				0x10000000
#define	GPTU_SRSEL_SSR0_UPDOWN_A			0x20000000
#define	GPTU_SRSEL_SSR0_CLEAR_A				0x30000000
#define	GPTU_SRSEL_SSR0_RLCP0_A				0x40000000
#define	GPTU_SRSEL_SSR0_RLCP1_A				0x50000000
#define	GPTU_SRSEL_SSR0_OUV_T2A				0x60000000
#define	GPTU_SRSEL_SSR0_OUV_T2B				0x70000000
#define	GPTU_SRSEL_SSR0_START_B				0x80000000
#define	GPTU_SRSEL_SSR0_STOP_B				0x90000000
#define	GPTU_SRSEL_SSR0_RLCP0_B				0xA0000000
#define	GPTU_SRSEL_SSR0_RLCP1_B				0xB0000000
#define	GPTU_SRSEL_SSR0_SR00				0xC0000000
#define	GPTU_SRSEL_SSR0_SR01				0xD0000000
#define	GPTU_SRSEL_SSR0_SR10				0xE0000000
#define	GPTU_SRSEL_SSR0_SR11				0xF0000000

/* Service Routing Control Register */
#define	GPTU_SRC(base, n)					MMIO32(base + 0xE0 + ((n) * 0x4))


// STM [MOD_NUM=0000, MOD_REV=00, MOD_32BIT=C0]
// STM from Tricore TC1766 official public datasheet
#define	STM_BASE	0xF4B00000
/* Clock Control Register */
#define	STM_CLC		MMIO32(STM_BASE + 0x00)

/* Module Identifier Register */
#define	STM_ID		MMIO32(STM_BASE + 0x08)

#define	STM_TIM0	MMIO32(STM_BASE + 0x10)

#define	STM_TIM1	MMIO32(STM_BASE + 0x14)

#define	STM_TIM2	MMIO32(STM_BASE + 0x18)

#define	STM_TIM3	MMIO32(STM_BASE + 0x1C)

#define	STM_TIM4	MMIO32(STM_BASE + 0x20)

#define	STM_TIM5	MMIO32(STM_BASE + 0x24)

#define	STM_TIM6	MMIO32(STM_BASE + 0x28)

#define	STM_CAP		MMIO32(STM_BASE + 0x2C)


// ADC [MOD_NUM=F024, MOD_REV=00, MOD_32BIT=C0]
// ADC. Datasheet not found.
#define	ADC_BASE				0xF4C00000
/* Clock Control Register */
#define	ADC_CLC					MMIO32(ADC_BASE + 0x00)

/* Module Identifier Register */
#define	ADC_ID					MMIO32(ADC_BASE + 0x08)

#define	ADC_CON0				MMIO32(ADC_BASE + 0x14)

#define	ADC_CON1				MMIO32(ADC_BASE + 0x18)
#define	ADC_CON1_CH				GENMASK(5, 0)							 // Gains: M0=0.5, M1=0.44, M2=0.5, M9=0.5, M0_M9=1
#define	ADC_CON1_CH_SHIFT		0
#define	ADC_CON1_CH_OFF			0x0
#define	ADC_CON1_CH_M0_P		0x1
#define	ADC_CON1_CH_M1_P		0x2
#define	ADC_CON1_CH_M2_P		0x3
#define	ADC_CON1_CH_M7_N		0x8
#define	ADC_CON1_CH_M8_N		0x9
#define	ADC_CON1_CH_M9_N		0xA
#define	ADC_CON1_CH_M10_N		0xB
#define	ADC_CON1_CH_M0_M9_N		0x12
#define	ADC_CON1_PREAMP_INV		BIT(6)
#define	ADC_CON1_PREAMP_FAST	BIT(11)
#define	ADC_CON1_MODE			GENMASK(14, 12)
#define	ADC_CON1_MODE_SHIFT		12
#define	ADC_CON1_MODE_V			0x0
#define	ADC_CON1_MODE_I_30		0x1000
#define	ADC_CON1_MODE_I_60		0x2000
#define	ADC_CON1_MODE_I_90		0x3000
#define	ADC_CON1_MODE_I_120		0x4000
#define	ADC_CON1_MODE_I_150		0x5000
#define	ADC_CON1_MODE_I_180		0x6000
#define	ADC_CON1_MODE_I_210		0x7000
#define	ADC_CON1_FREQ			GENMASK(18, 16)
#define	ADC_CON1_FREQ_SHIFT		16
#define	ADC_CON1_COUNT			GENMASK(21, 19)
#define	ADC_CON1_COUNT_SHIFT	19
#define	ADC_CON1_REF_CH			GENMASK(24, 22)
#define	ADC_CON1_REF_CH_SHIFT	22
#define	ADC_CON1_REF_CH_OFF		0x0
#define	ADC_CON1_REF_CH_M0_P	0x400000
#define	ADC_CON1_REF_CH_M1_P	0x800000
#define	ADC_CON1_REF_CH_M2_P	0xC00000
#define	ADC_CON1_REF_CH_M7_N	0x2000000
#define	ADC_CON1_REF_CH_M8_N	0x2400000
#define	ADC_CON1_REF_CH_M9_N	0x2800000
#define	ADC_CON1_REF_CH_M10_N	0x2C00000
#define	ADC_CON1_REF_CH_M0_M9_N	0x4800000
#define	ADC_CON1_SINGLE			BIT(27)
#define	ADC_CON1_TRIG			BIT(28)
#define	ADC_CON1_ON				BIT(29)
#define	ADC_CON1_START			BIT(31)

#define	ADC_STAT				MMIO32(ADC_BASE + 0x1C)
#define	ADC_STAT_INDEX			GENMASK(2, 0)
#define	ADC_STAT_INDEX_SHIFT	0
#define	ADC_STAT_BUSY			BIT(30)
#define	ADC_STAT_READY			BIT(31)

#define	ADC_FIFO(n)				MMIO32(ADC_BASE + 0x20 + ((n) * 0x4))

#define	ADC_PLLCON				MMIO32(ADC_BASE + 0x40)
#define	ADC_PLLCON_K			GENMASK(7, 0)
#define	ADC_PLLCON_K_SHIFT		0
#define	ADC_PLLCON_L			GENMASK(15, 8)
#define	ADC_PLLCON_L_SHIFT		8

/* Service Routing Control Register */
#define	ADC_SRC(n)				MMIO32(ADC_BASE + 0xF0 + ((n) * 0x4))


// KEYPAD [MOD_NUM=F046, MOD_REV=00, MOD_32BIT=C0]
// Keypad scaner module, registers collected using tests on real hardware (using "black box" method).
#define	KEYPAD_BASE			0xF4D00000
/* Module Identifier Register */
#define	KEYPAD_ID			MMIO32(KEYPAD_BASE + 0x08)

#define	KEYPAD_CON			MMIO32(KEYPAD_BASE + 0x10)

#define	KEYPAD_PORT(n)		MMIO32(KEYPAD_BASE + 0x18 + ((n) * 0x4))

#define	KEYPAD_ISR			MMIO32(KEYPAD_BASE + 0x24)
#define	KEYPAD_ISR_PRESS	BIT(2)
#define	KEYPAD_ISR_RELEASE	BIT(3)

/* Service Routing Control Register */
#define	KEYPAD_PRESS_SRC	MMIO32(KEYPAD_BASE + 0xF0)

/* Service Routing Control Register */
#define	KEYPAD_UNK0_SRC		MMIO32(KEYPAD_BASE + 0xF4)

/* Service Routing Control Register */
#define	KEYPAD_UNK1_SRC		MMIO32(KEYPAD_BASE + 0xF8)

/* Service Routing Control Register */
#define	KEYPAD_RELEASE_SRC	MMIO32(KEYPAD_BASE + 0xFC)


// DSP [MOD_NUM=F022, MOD_REV=00, MOD_32BIT=C0]
// Looks like DSP module, but not sure.
#define	DSP_BASE	0xF6000000
/* Clock Control Register */
#define	DSP_CLC		MMIO32(DSP_BASE + 0x00)

/* Module Identifier Register */
#define	DSP_ID		MMIO32(DSP_BASE + 0x08)

#define	DSP_UNK0	MMIO32(DSP_BASE + 0x1C)

#define	DSP_UNK1	MMIO32(DSP_BASE + 0x24)

#define	DSP_RAM(n)	MMIO32(DSP_BASE + 0x1000 + ((n) * 0x4))


// GPRSCU [MOD_NUM=F003, MOD_REV=00, MOD_32BIT=C0]
// Looks like GPRS Cypher Uinit module, but not sure.
#define	GPRSCU_BASE		0xF6200000
/* Clock Control Register */
#define	GPRSCU_CLC		MMIO32(GPRSCU_BASE + 0x00)

/* Module Identifier Register */
#define	GPRSCU_ID		MMIO32(GPRSCU_BASE + 0x08)

/* Service Routing Control Register */
#define	GPRSCU_SRC(n)	MMIO32(GPRSCU_BASE + 0xF8 + ((n) * 0x4))


// AFC [MOD_NUM=F004, MOD_REV=00, MOD_32BIT=C0]
// Looks like AFC (Automatic Frequency Correction???) module, but not sure.
#define	AFC_BASE	0xF6300000
/* Clock Control Register */
#define	AFC_CLC		MMIO32(AFC_BASE + 0x00)

/* Module Identifier Register */
#define	AFC_ID		MMIO32(AFC_BASE + 0x08)


// TPU [MOD_NUM=F021, MOD_REV=00, MOD_32BIT=C0]
// Looks like TPU (time processing module) module, registers collected using tests on real hardware (using "black box" method).
#define	TPU_BASE					0xF6400000
/* Clock Control Register */
#define	TPU_CLC						MMIO32(TPU_BASE + 0x00)

/* Module Identifier Register */
#define	TPU_ID						MMIO32(TPU_BASE + 0x08)

#define	TPU_UNK0					MMIO32(TPU_BASE + 0x10)

#define	TPU_UNK1					MMIO32(TPU_BASE + 0x14)

#define	TPU_UNK2					MMIO32(TPU_BASE + 0x18)

#define	TPU_CORRECTION				MMIO32(TPU_BASE + 0x1C)
#define	TPU_CORRECTION_VALUE		GENMASK(14, 0)
#define	TPU_CORRECTION_VALUE_SHIFT	0
#define	TPU_CORRECTION_CTRL			BIT(16)

#define	TPU_OVERFLOW				MMIO32(TPU_BASE + 0x20)
#define	TPU_OVERFLOW_VALUE			GENMASK(14, 0)
#define	TPU_OVERFLOW_VALUE_SHIFT	0

#define	TPU_INT(n)					MMIO32(TPU_BASE + 0x24 + ((n) * 0x4))
#define	TPU_INT_VALUE				GENMASK(14, 0)
#define	TPU_INT_VALUE_SHIFT			0

#define	TPU_OFFSET					MMIO32(TPU_BASE + 0x2C)
#define	TPU_OFFSET_VALUE			GENMASK(14, 0)
#define	TPU_OFFSET_VALUE_SHIFT		0
#define	TPU_OFFSET_CTRL				BIT(16)

#define	TPU_SKIP					MMIO32(TPU_BASE + 0x30)
#define	TPU_SKIP_SKIPN				BIT(0)
#define	TPU_SKIP_SKIPC				BIT(1)

#define	TPU_COUNTER					MMIO32(TPU_BASE + 0x34)
#define	TPU_COUNTER_VALUE			GENMASK(14, 0)
#define	TPU_COUNTER_VALUE_SHIFT		0

#define	TPU_UNK3					MMIO32(TPU_BASE + 0x38)

#define	TPU_UNK4					MMIO32(TPU_BASE + 0x3C)

#define	TPU_UNK5					MMIO32(TPU_BASE + 0x40)

#define	TPU_UNK6					MMIO32(TPU_BASE + 0x44)

#define	TPU_PARAM					MMIO32(TPU_BASE + 0x5C)
#define	TPU_PARAM_TINI				BIT(0)
#define	TPU_PARAM_FDIS				BIT(1)

#define	TPU_UNK7					MMIO32(TPU_BASE + 0x60)

#define	TPU_PLLCON0					MMIO32(TPU_BASE + 0x68)
#define	TPU_PLLCON0_K_DIV			GENMASK(29, 0)
#define	TPU_PLLCON0_K_DIV_SHIFT		0

#define	TPU_PLLCON1					MMIO32(TPU_BASE + 0x6C)
#define	TPU_PLLCON1_L_DIV			GENMASK(29, 0)
#define	TPU_PLLCON1_L_DIV_SHIFT		0

#define	TPU_PLLCON2					MMIO32(TPU_BASE + 0x70)
#define	TPU_PLLCON2_LOAD			BIT(0)
#define	TPU_PLLCON2_INIT			BIT(1)

/* Service Routing Control Register */
#define	TPU_UNK_SRC(n)				MMIO32(TPU_BASE + 0xE0 + ((n) * 0x4))

/* Service Routing Control Register */
#define	TPU_SRC(n)					MMIO32(TPU_BASE + 0xF8 + ((n) * 0x4))

#define	TPU_RAM(n)					MMIO32(TPU_BASE + 0x1000 + ((n) * 0x4))


// CIF [MOD_NUM=F052, MOD_REV=00, MOD_32BIT=C0]
// Looks like DIF (Camera Interface) module, but not sure.
#define	CIF_BASE	0xF7000000
/* Clock Control Register */
#define	CIF_CLC		MMIO32(CIF_BASE + 0x00)

#define	CIF_UNK0	MMIO32(CIF_BASE + 0x00)

/* Module Identifier Register */
#define	CIF_ID		MMIO32(CIF_BASE + 0x08)

#define	CIF_UNK1	MMIO32(CIF_BASE + 0x20)

#define	CIF_UNK2	MMIO32(CIF_BASE + 0x24)

#define	CIF_UNK3	MMIO32(CIF_BASE + 0x28)

#define	CIF_UNK4	MMIO32(CIF_BASE + 0x90)

#define	CIF_UNK5	MMIO32(CIF_BASE + 0x98)

#define	CIF_UNK6	MMIO32(CIF_BASE + 0xA4)

#define	CIF_UNK7	MMIO32(CIF_BASE + 0xAC)


// DIF [MOD_NUM=F043, MOD_REV=00, MOD_32BIT=C0]
// DIF (Display Interface)
#define	DIF_BASE				0xF7100000
/* Clock Control Register */
#define	DIF_CLC					MMIO32(DIF_BASE + 0x00)

/* Module Identifier Register */
#define	DIF_ID					MMIO32(DIF_BASE + 0x08)

/* RUN Control Register */
#define	DIF_RUNCTRL				MMIO32(DIF_BASE + 0x10)
#define	DIF_RUNCTRL_RUN			BIT(0)									 // Enable DIF Interface

#define	DIF_CON0				MMIO32(DIF_BASE + 0x20)

#define	DIF_CON1				MMIO32(DIF_BASE + 0x24)
#define	DIF_CON1_UNK0			BIT(0)
#define	DIF_CON1_UNK1			BIT(1)
#define	DIF_CON1_CS				BIT(6)									 // Use CS1 or CS2
#define	DIF_CON1_CS_CS1			0x0
#define	DIF_CON1_CS_CS2			0x40

/* FIFO config */
#define	DIF_FIFOCFG				MMIO32(DIF_BASE + 0x28)
#define	DIF_FIFOCFG_MODE		BIT(0)									 // DATA: CD=1, CMD: CD=0
#define	DIF_FIFOCFG_MODE_DATA	0x0
#define	DIF_FIFOCFG_MODE_CMD	0x1
#define	DIF_FIFOCFG_UNK0		BIT(1)
#define	DIF_FIFOCFG_UNK1		BIT(4)
#define	DIF_FIFOCFG_BS			GENMASK(6, 5)							 // Rx/Tx burst size
#define	DIF_FIFOCFG_BS_SHIFT	5
#define	DIF_FIFOCFG_BS_8		0x0
#define	DIF_FIFOCFG_BS_16		0x20
#define	DIF_FIFOCFG_BS_24		0x40
#define	DIF_FIFOCFG_BS_32		0x60

#define	DIF_CON3				MMIO32(DIF_BASE + 0x2C)

#define	DIF_CON4				MMIO32(DIF_BASE + 0x30)

#define	DIF_STAT				MMIO32(DIF_BASE + 0x38)
#define	DIF_STAT_BUSY			BIT(0)

#define	DIF_CON5				MMIO32(DIF_BASE + 0x3C)

#define	DIF_CON6				MMIO32(DIF_BASE + 0x40)

#define	DIF_CON7				MMIO32(DIF_BASE + 0x44)

#define	DIF_CON8				MMIO32(DIF_BASE + 0x48)

#define	DIF_CON9				MMIO32(DIF_BASE + 0x4C)

#define	DIF_PROG(n)				MMIO32(DIF_BASE + 0x50 + ((n) * 0x4))

#define	DIF_CON10				MMIO32(DIF_BASE + 0x68)

#define	DIF_CON11				MMIO32(DIF_BASE + 0x6C)

#define	DIF_CON12				MMIO32(DIF_BASE + 0x70)

#define	DIF_CON13				MMIO32(DIF_BASE + 0xA0)

#define	DIF_TX_SIZE				MMIO32(DIF_BASE + 0xA4)

/* Raw Interrupt Status Register */
#define	DIF_RIS					MMIO32(DIF_BASE + 0xC0)
#define	DIF_RIS_EVENT0			BIT(0)
#define	DIF_RIS_EVENT1			BIT(1)
#define	DIF_RIS_EVENT2			BIT(2)
#define	DIF_RIS_EVENT3			BIT(3)
#define	DIF_RIS_EVENT4			BIT(4)
#define	DIF_RIS_EVENT5			BIT(5)
#define	DIF_RIS_EVENT6			BIT(6)
#define	DIF_RIS_EVENT7			BIT(7)
#define	DIF_RIS_EVENT8			BIT(8)

/* Interrupt Mask Control Register */
#define	DIF_IMSC				MMIO32(DIF_BASE + 0xC4)
#define	DIF_IMSC_EVENT0			BIT(0)
#define	DIF_IMSC_EVENT1			BIT(1)
#define	DIF_IMSC_EVENT2			BIT(2)
#define	DIF_IMSC_EVENT3			BIT(3)
#define	DIF_IMSC_EVENT4			BIT(4)
#define	DIF_IMSC_EVENT5			BIT(5)
#define	DIF_IMSC_EVENT6			BIT(6)
#define	DIF_IMSC_EVENT7			BIT(7)
#define	DIF_IMSC_EVENT8			BIT(8)

/* Masked Interrupt Status */
#define	DIF_MIS					MMIO32(DIF_BASE + 0xC8)
#define	DIF_MIS_EVENT0			BIT(0)
#define	DIF_MIS_EVENT1			BIT(1)
#define	DIF_MIS_EVENT2			BIT(2)
#define	DIF_MIS_EVENT3			BIT(3)
#define	DIF_MIS_EVENT4			BIT(4)
#define	DIF_MIS_EVENT5			BIT(5)
#define	DIF_MIS_EVENT6			BIT(6)
#define	DIF_MIS_EVENT7			BIT(7)
#define	DIF_MIS_EVENT8			BIT(8)

/* Interrupt Clear Register */
#define	DIF_ICR					MMIO32(DIF_BASE + 0xCC)
#define	DIF_ICR_EVENT0			BIT(0)
#define	DIF_ICR_EVENT1			BIT(1)
#define	DIF_ICR_EVENT2			BIT(2)
#define	DIF_ICR_EVENT3			BIT(3)
#define	DIF_ICR_EVENT4			BIT(4)
#define	DIF_ICR_EVENT5			BIT(5)
#define	DIF_ICR_EVENT6			BIT(6)
#define	DIF_ICR_EVENT7			BIT(7)
#define	DIF_ICR_EVENT8			BIT(8)

/* Interrupt Set Register */
#define	DIF_ISR					MMIO32(DIF_BASE + 0xD0)
#define	DIF_ISR_EVENT0			BIT(0)
#define	DIF_ISR_EVENT1			BIT(1)
#define	DIF_ISR_EVENT2			BIT(2)
#define	DIF_ISR_EVENT3			BIT(3)
#define	DIF_ISR_EVENT4			BIT(4)
#define	DIF_ISR_EVENT5			BIT(5)
#define	DIF_ISR_EVENT6			BIT(6)
#define	DIF_ISR_EVENT7			BIT(7)
#define	DIF_ISR_EVENT8			BIT(8)

#define	DIF_CON14				MMIO32(DIF_BASE + 0xD4)

#define	DIF_FIFO				MMIO32(DIF_BASE + 0x8000)


// MMCI [MOD_NUM=F041, MOD_REV=00, MOD_32BIT=C0]
// Module wrapper for AMBA PL180 (MMC/SD controller)
#define	MMCI_BASE	0xF7300000
/* Clock Control Register */
#define	MMCI_CLC	MMIO32(MMCI_BASE + 0x00)

/* Module Identifier Register */
#define	MMCI_ID		MMIO32(MMCI_BASE + 0x08)


// MCI [AMBA PL180]
// ARM PrimeCell Multimedia Card Interface (PL180)
#define	MCI_BASE						0xF7301000
#define	MCI_POWER						MMIO32(MCI_BASE + 0x00)
#define	MCI_POWER_CTRL					GENMASK(1, 0)
#define	MCI_POWER_CTRL_SHIFT			0
#define	MCI_POWER_CTRL_POWER_OFF		0x0
#define	MCI_POWER_CTRL_RESERVED			0x1
#define	MCI_POWER_CTRL_POWER_UP			0x2
#define	MCI_POWER_CTRL_POWER_ON			0x3
#define	MCI_POWER_VOLTAGE				GENMASK(5, 2)
#define	MCI_POWER_VOLTAGE_SHIFT			2
#define	MCI_POWER_OPENDRAIN				BIT(6)
#define	MCI_POWER_ROD					BIT(7)

#define	MCI_CLOCK						MMIO32(MCI_BASE + 0x04)
#define	MCI_CLOCK_CLKDIV				GENMASK(7, 0)							 // MCLCLK frequency = MCLK / [2x(ClkDiv+1)].
#define	MCI_CLOCK_CLKDIV_SHIFT			0
#define	MCI_CLOCK_ENABLE				BIT(8)
#define	MCI_CLOCK_PWRSAVE				BIT(9)
#define	MCI_CLOCK_BYPASS				BIT(10)
#define	MCI_CLOCK_WIDEBUS				BIT(11)

#define	MCI_ARGUMENT					MMIO32(MCI_BASE + 0x08)
#define	MCI_ARGUMENT_CMDARG				GENMASK(31, 0)
#define	MCI_ARGUMENT_CMDARG_SHIFT		0

#define	MCI_COMMAND						MMIO32(MCI_BASE + 0x0C)
#define	MCI_COMMAND_CMDINDEX			GENMASK(5, 0)
#define	MCI_COMMAND_CMDINDEX_SHIFT		0
#define	MCI_COMMAND_RESPONSE			BIT(6)
#define	MCI_COMMAND_LONGRSP				BIT(7)
#define	MCI_COMMAND_INTERRUPT			BIT(8)
#define	MCI_COMMAND_PENDING				BIT(9)
#define	MCI_COMMAND_ENABLE				BIT(10)

#define	MCI_RESPCMD						MMIO32(MCI_BASE + 0x10)
#define	MCI_RESPCMD_CMDINDEX			GENMASK(5, 0)
#define	MCI_RESPCMD_CMDINDEX_SHIFT		0

#define	MCI_RESPONSE0					MMIO32(MCI_BASE + 0x14)

#define	MCI_RESPONSE1					MMIO32(MCI_BASE + 0x18)

#define	MCI_RESPONSE2					MMIO32(MCI_BASE + 0x1C)

#define	MCI_RESPONSE3					MMIO32(MCI_BASE + 0x20)

#define	MCI_DATATIMER					MMIO32(MCI_BASE + 0x24)
#define	MCI_DATATIMER_TIMER				GENMASK(31, 0)
#define	MCI_DATATIMER_TIMER_SHIFT		0

#define	MCI_DATALENGTH					MMIO32(MCI_BASE + 0x28)
#define	MCI_DATALENGTH_LENGTH			GENMASK(15, 0)
#define	MCI_DATALENGTH_LENGTH_SHIFT		0

#define	MCI_DATACTRL					MMIO32(MCI_BASE + 0x2C)
#define	MCI_DATACTRL_EMABLE				BIT(0)
#define	MCI_DATACTRL_DIRECTION			BIT(1)									 // 0 = From controller to card, 1 = From card to controller
#define	MCI_DATACTRL_DIRECTION_WRITE	0x0
#define	MCI_DATACTRL_DIRECTION_READ		0x2
#define	MCI_DATACTRL_MODE				BIT(2)
#define	MCI_DATACTRL_MODE_BLCOK			0x0
#define	MCI_DATACTRL_MODE_STREAM		0x4
#define	MCI_DATACTRL_DMAENABLE			BIT(3)
#define	MCI_DATACTRL_BLOCKSIZE			GENMASK(7, 4)
#define	MCI_DATACTRL_BLOCKSIZE_SHIFT	4

#define	MCI_DATACNT						MMIO32(MCI_BASE + 0x30)
#define	MCI_DATACNT_COUNT				GENMASK(15, 0)
#define	MCI_DATACNT_COUNT_SHIFT			0

#define	MCI_STATUS						MMIO32(MCI_BASE + 0x34)
#define	MCI_STATUS_CMDCRCFAIL			BIT(0)									 // Command response received (CRC check failed)
#define	MCI_STATUS_DATACRCFAIL			BIT(1)									 // Data block sent/received (CRC check failed)
#define	MCI_STATUS_CMDTIMEOUT			BIT(2)									 // Command response timeout
#define	MCI_STATUS_DATATIMEOUT			BIT(3)									 // Data timeout
#define	MCI_STATUS_TXUNDERRUN			BIT(4)									 // Transmit FIFO underrun error
#define	MCI_STATUS_RXOVERRUN			BIT(5)									 // Receive FIFO overrun error
#define	MCI_STATUS_CMDRESPEND			BIT(6)									 // Command response received (CRC check passed)
#define	MCI_STATUS_CMDSENT				BIT(7)									 // Command sent (no response required)
#define	MCI_STATUS_DATAEND				BIT(8)									 // Data end (data counter is zero)
#define	MCI_STATUS_STARTBITERR			BIT(9)									 // Start bit not detected on all data signals in wide bus mode
#define	MCI_STATUS_DATABLOCKEND			BIT(10)									 // Data block sent/received (CRC check passed)
#define	MCI_STATUS_CMDACTIVE			BIT(11)									 // Command transfer in progress
#define	MCI_STATUS_TXACTIVE				BIT(12)									 // Data transmit in progress
#define	MCI_STATUS_RXACTIVE				BIT(13)									 // Data receive in progress
#define	MCI_STATUS_TXFIFOHALFEMPTY		BIT(14)									 // Transmit FIFO half empty
#define	MCI_STATUS_RXFIFOHALFFULL		BIT(15)									 // Receive FIFO half full
#define	MCI_STATUS_TXFIFOFULL			BIT(16)									 // Transmit FIFO full
#define	MCI_STATUS_RXFIFOFULL			BIT(17)									 // Receive FIFO full
#define	MCI_STATUS_TXFIFOEMPTY			BIT(18)									 // Transmit FIFO empty
#define	MCI_STATUS_RXFIFOEMPTY			BIT(19)									 // Receive FIFO empty
#define	MCI_STATUS_TXDATAAVLBL			BIT(20)									 // Data available in transmit FIFO
#define	MCI_STATUS_RXDATAAVLBL			BIT(21)									 // Data available in receive FIFO

#define	MCI_CLEAR						MMIO32(MCI_BASE + 0x38)
#define	MCI_CLEAR_CMDCRCFAILCLR			BIT(0)
#define	MCI_CLEAR_DATACRCFAILCLR		BIT(1)
#define	MCI_CLEAR_CMDTIMEOUTCLR			BIT(2)
#define	MCI_CLEAR_DATATIMEOUTCLR		BIT(3)
#define	MCI_CLEAR_TXUNDERRUNCLR			BIT(4)
#define	MCI_CLEAR_RXOVERRUNCLR			BIT(5)
#define	MCI_CLEAR_CMDRESPENDCLR			BIT(6)
#define	MCI_CLEAR_CMDSENTCLR			BIT(7)
#define	MCI_CLEAR_DATAENDCLR			BIT(8)
#define	MCI_CLEAR_STARTBITERRCLR		BIT(9)
#define	MCI_CLEAR_DATABLOCKENDCLR		BIT(10)

#define	MCI_MASK0						MMIO32(MCI_BASE + 0x3C)
#define	MCI_MASK0_CMDCRCFAILMASK		BIT(0)
#define	MCI_MASK0_DATACRCFAILMASK		BIT(1)
#define	MCI_MASK0_CMDTIMEOUTMASK		BIT(2)
#define	MCI_MASK0_DATATIMEOUTMASK		BIT(3)
#define	MCI_MASK0_TXUNDERRUNMASK		BIT(4)
#define	MCI_MASK0_RXOVERRUNMASK			BIT(5)
#define	MCI_MASK0_CMDRESPENDMASK		BIT(6)
#define	MCI_MASK0_CMDSENTMASK			BIT(7)
#define	MCI_MASK0_DATAENDMASK			BIT(8)
#define	MCI_MASK0_STARTBITERRMASK		BIT(9)
#define	MCI_MASK0_DATABLOCKENDMASK		BIT(10)
#define	MCI_MASK0_CMDACTIVEMASK			BIT(11)
#define	MCI_MASK0_TXACTIVEMASK			BIT(12)
#define	MCI_MASK0_RXACTIVEMASK			BIT(13)
#define	MCI_MASK0_TXFIFOHALFEMPTYMASK	BIT(14)
#define	MCI_MASK0_RXFIFOHALFFULLMASK	BIT(15)
#define	MCI_MASK0_TXFIFOFULLMASK		BIT(16)
#define	MCI_MASK0_RXFIFOFULLMASK		BIT(17)
#define	MCI_MASK0_TXFIFOEMPTYMASK		BIT(18)
#define	MCI_MASK0_RXFIFOEMPTYMASK		BIT(19)
#define	MCI_MASK0_TXDATAAVLBLMASK		BIT(20)
#define	MCI_MASK0_RXDATAAVLBLMASK		BIT(21)

#define	MCI_MASK1						MMIO32(MCI_BASE + 0x40)
#define	MCI_MASK1_CMDCRCFAILMASK		BIT(0)
#define	MCI_MASK1_DATACRCFAILMASK		BIT(1)
#define	MCI_MASK1_CMDTIMEOUTMASK		BIT(2)
#define	MCI_MASK1_DATATIMEOUTMASK		BIT(3)
#define	MCI_MASK1_TXUNDERRUNMASK		BIT(4)
#define	MCI_MASK1_RXOVERRUNMASK			BIT(5)
#define	MCI_MASK1_CMDRESPENDMASK		BIT(6)
#define	MCI_MASK1_CMDSENTMASK			BIT(7)
#define	MCI_MASK1_DATAENDMASK			BIT(8)
#define	MCI_MASK1_STARTBITERRMASK		BIT(9)
#define	MCI_MASK1_DATABLOCKENDMASK		BIT(10)
#define	MCI_MASK1_CMDACTIVEMASK			BIT(11)
#define	MCI_MASK1_TXACTIVEMASK			BIT(12)
#define	MCI_MASK1_RXACTIVEMASK			BIT(13)
#define	MCI_MASK1_TXFIFOHALFEMPTYMASK	BIT(14)
#define	MCI_MASK1_RXFIFOHALFFULLMASK	BIT(15)
#define	MCI_MASK1_TXFIFOFULLMASK		BIT(16)
#define	MCI_MASK1_RXFIFOFULLMASK		BIT(17)
#define	MCI_MASK1_TXFIFOEMPTYMASK		BIT(18)
#define	MCI_MASK1_RXFIFOEMPTYMASK		BIT(19)
#define	MCI_MASK1_TXDATAAVLBLMASK		BIT(20)
#define	MCI_MASK1_RXDATAAVLBLMASK		BIT(21)

#define	MCI_SELECT						MMIO32(MCI_BASE + 0x44)
#define	MCI_SELECT_SDCARD				GENMASK(3, 0)
#define	MCI_SELECT_SDCARD_SHIFT			0

#define	MCI_FIFOCNT						MMIO32(MCI_BASE + 0x48)
#define	MCI_FIFOCNT_COUNT				GENMASK(15, 0)
#define	MCI_FIFOCNT_COUNT_SHIFT			0

#define	MCI_FIFO(n)						MMIO32(MCI_BASE + 0x80 + ((n) * 0x4))

#define	MCI_PERIPH_ID0					MMIO32(MCI_BASE + 0xFE0)

#define	MCI_PERIPH_ID1					MMIO32(MCI_BASE + 0xFE4)

#define	MCI_PERIPH_ID2					MMIO32(MCI_BASE + 0xFE8)

#define	MCI_PERIPH_ID3					MMIO32(MCI_BASE + 0xFEC)

#define	MCI_PCELL_ID0					MMIO32(MCI_BASE + 0xFF0)

#define	MCI_PCELL_ID1					MMIO32(MCI_BASE + 0xFF4)

#define	MCI_PCELL_ID2					MMIO32(MCI_BASE + 0xFF8)

#define	MCI_PCELL_ID3					MMIO32(MCI_BASE + 0xFFC)


// I2C [MOD_NUM=F057, MOD_REV=00, MOD_32BIT=C0]
// I2C from Tricore TC27x official public datasheet
#define	I2C_BASE							0xF7600000
/* Clock Control Register */
#define	I2C_CLC								MMIO32(I2C_BASE + 0x00)

/* Module Identifier Register */
#define	I2C_ID								MMIO32(I2C_BASE + 0x08)

/* RUN Control Register */
#define	I2C_RUNCTRL							MMIO32(I2C_BASE + 0x10)
#define	I2C_RUNCTRL_RUN						BIT(0)						 // Enable I2C-bus Interface

/* End Data Control Register */
#define	I2C_ENDDCTRL						MMIO32(I2C_BASE + 0x14)
#define	I2C_ENDDCTRL_SETRSC					BIT(0)						 // Set Restart Condition
#define	I2C_ENDDCTRL_SETEND					BIT(1)						 // Set End of Transmission

/* Fractional Divider Configuration Register */
#define	I2C_FDIVCFG							MMIO32(I2C_BASE + 0x18)
#define	I2C_FDIVCFG_DEC						GENMASK(10, 0)				 // Decrement Value of Fractional Divider
#define	I2C_FDIVCFG_DEC_SHIFT				0
#define	I2C_FDIVCFG_INC						GENMASK(23, 16)				 // Increment Value of Fractional Divider
#define	I2C_FDIVCFG_INC_SHIFT				16

/* Fractional Divider High-speed Mode Configuration Register */
#define	I2C_FDIVHIGHCFG						MMIO32(I2C_BASE + 0x1C)
#define	I2C_FDIVHIGHCFG_DEC					GENMASK(10, 0)				 // Decrement Value of Fractional Divider
#define	I2C_FDIVHIGHCFG_DEC_SHIFT			0
#define	I2C_FDIVHIGHCFG_INC					GENMASK(23, 16)				 // Increment Value of Fractional Divider
#define	I2C_FDIVHIGHCFG_INC_SHIFT			16

/* Address Configuration Register */
#define	I2C_ADDRCFG							MMIO32(I2C_BASE + 0x20)
#define	I2C_ADDRCFG_ADR						GENMASK(9, 0)				 // I2C-bus Device Address (slave)
#define	I2C_ADDRCFG_ADR_SHIFT				0
#define	I2C_ADDRCFG_TBAM					BIT(16)						 // Ten Bit Address Mode
#define	I2C_ADDRCFG_GCE						BIT(17)						 // General Call Enable
#define	I2C_ADDRCFG_MCE						BIT(18)						 // Master Code Enable
#define	I2C_ADDRCFG_MnS						BIT(19)						 // Master / not Slave
#define	I2C_ADDRCFG_SONA					BIT(20)						 // Stop on Not-acknowledge
#define	I2C_ADDRCFG_SOPE					BIT(21)						 // Stop on Packet End

/* Bus Status Register */
#define	I2C_BUSSTAT							MMIO32(I2C_BASE + 0x24)
#define	I2C_BUSSTAT_BS						GENMASK(2, 1)				 // Bus Status
#define	I2C_BUSSTAT_BS_SHIFT				1
#define	I2C_BUSSTAT_BS_FREE					0x0
#define	I2C_BUSSTAT_BS_BUSY_OTHER_MASTER	0x2
#define	I2C_BUSSTAT_BS_BUSY_MASTER			0x4
#define	I2C_BUSSTAT_BS_BUSY_SLAVE			0x6
#define	I2C_BUSSTAT_RnW						BIT(3)						 // Read/not Write

/* FIFO Configuration Register */
#define	I2C_FIFOCFG							MMIO32(I2C_BASE + 0x28)
#define	I2C_FIFOCFG_RXBS					GENMASK(1, 0)				 // RX Burst Size
#define	I2C_FIFOCFG_RXBS_SHIFT				0
#define	I2C_FIFOCFG_RXBS_1_WORD				0x0
#define	I2C_FIFOCFG_RXBS_2_WORD				0x1
#define	I2C_FIFOCFG_RXBS_4_WORD				0x2
#define	I2C_FIFOCFG_TXBS					GENMASK(5, 4)				 // TX Burst Size
#define	I2C_FIFOCFG_TXBS_SHIFT				4
#define	I2C_FIFOCFG_TXBS_1_WORD				0x0
#define	I2C_FIFOCFG_TXBS_2_WORD				0x10
#define	I2C_FIFOCFG_TXBS_4_WORD				0x20
#define	I2C_FIFOCFG_RXFA					GENMASK(9, 8)				 // RX FIFO Alignment
#define	I2C_FIFOCFG_RXFA_SHIFT				8
#define	I2C_FIFOCFG_RXFA_BYTE				0x0
#define	I2C_FIFOCFG_RXFA_HALF_WORLD			0x100
#define	I2C_FIFOCFG_RXFA_WORD				0x200
#define	I2C_FIFOCFG_TXFA					GENMASK(13, 12)				 // TX FIFO Alignment
#define	I2C_FIFOCFG_TXFA_SHIFT				12
#define	I2C_FIFOCFG_TXFA_BYTE				0x0
#define	I2C_FIFOCFG_TXFA_HALF_WORLD			0x1000
#define	I2C_FIFOCFG_TXFA_WORD				0x2000
#define	I2C_FIFOCFG_RXFC					BIT(16)						 // RX FIFO Flow Control
#define	I2C_FIFOCFG_TXFC					BIT(17)						 // TX FIFO Flow Control

/* Maximum Received Packet Size Control Register */
#define	I2C_MRPSCTRL						MMIO32(I2C_BASE + 0x2C)
#define	I2C_MRPSCTRL_MRPS					GENMASK(13, 0)				 // Maximum Received Packet Size
#define	I2C_MRPSCTRL_MRPS_SHIFT				0

/* Received Packet Size Status Register */
#define	I2C_RPSSTAT							MMIO32(I2C_BASE + 0x30)
#define	I2C_RPSSTAT_RPS						GENMASK(13, 0)				 // Received Packet Size
#define	I2C_RPSSTAT_RPS_SHIFT				0

/* Transmit Packet Size Control Register */
#define	I2C_TPSCTRL							MMIO32(I2C_BASE + 0x34)
#define	I2C_TPSCTRL_TPS						GENMASK(13, 0)				 // Transmit Packet Size
#define	I2C_TPSCTRL_TPS_SHIFT				0

/* Filled FIFO Stages Status Register */
#define	I2C_FFSSTAT							MMIO32(I2C_BASE + 0x38)
#define	I2C_FFSSTAT_FFS						GENMASK(5, 0)				 // Filled FIFO Stages
#define	I2C_FFSSTAT_FFS_SHIFT				0

/* Timing Configuration Register */
#define	I2C_TIMCFG							MMIO32(I2C_BASE + 0x40)
#define	I2C_TIMCFG_SDA_DEL_HD_DAT			GENMASK(5, 0)				 // SDA Delay Stages for Data Hold Time
#define	I2C_TIMCFG_SDA_DEL_HD_DAT_SHIFT		0
#define	I2C_TIMCFG_HS_SDA_DEL_HD_DAT		GENMASK(8, 6)				 // SDA Delay Stages for Data Hold Time in Highspeed Mode
#define	I2C_TIMCFG_HS_SDA_DEL_HD_DAT_SHIFT	6
#define	I2C_TIMCFG_SCL_DEL_HD_STA			GENMASK(11, 9)				 // SCL Delay Stages for Hold Time Start (Restart) Bit
#define	I2C_TIMCFG_SCL_DEL_HD_STA_SHIFT		9
#define	I2C_TIMCFG_EN_SCL_LOW_LEN			BIT(14)						 // Enable Direct Configuration of SCL Low Period Length in Fast Mode
#define	I2C_TIMCFG_FS_SCL_LOW				BIT(15)						 // Set Fast Mode SCL Low Period Timing
#define	I2C_TIMCFG_HS_SDA_DEL				GENMASK(18, 16)				 // SDA Delay Stages for Start/Stop bit in Highspeed Mode
#define	I2C_TIMCFG_HS_SDA_DEL_SHIFT			16
#define	I2C_TIMCFG_SCL_LOW_LEN				GENMASK(31, 24)				 // SCL Low Length in Fast Mode
#define	I2C_TIMCFG_SCL_LOW_LEN_SHIFT		24

/* Error Interrupt Request Source Mask Register */
#define	I2C_ERRIRQSM						MMIO32(I2C_BASE + 0x60)
#define	I2C_ERRIRQSM_RXF_UFL				BIT(0)						 // RX FIFO Underflow
#define	I2C_ERRIRQSM_RXF_OFL				BIT(1)						 // RX FIFO Overflow
#define	I2C_ERRIRQSM_TXF_UFL				BIT(2)						 // TX FIFO Underflow
#define	I2C_ERRIRQSM_TXF_OFL				BIT(3)						 // TX FIFO Overflow

/* Error Interrupt Request Source Status Register */
#define	I2C_ERRIRQSS						MMIO32(I2C_BASE + 0x64)
#define	I2C_ERRIRQSS_RXF_UFL				BIT(0)						 // RX FIFO Underflow
#define	I2C_ERRIRQSS_RXF_OFL				BIT(1)						 // RX FIFO Overflow
#define	I2C_ERRIRQSS_TXF_UFL				BIT(2)						 // TX FIFO Underflow
#define	I2C_ERRIRQSS_TXF_OFL				BIT(3)						 // TX FIFO Overflow

/* Error Interrupt Request Source Clear Register */
#define	I2C_ERRIRQSC						MMIO32(I2C_BASE + 0x68)
#define	I2C_ERRIRQSC_RXF_UFL				BIT(0)						 // RX FIFO Underflow
#define	I2C_ERRIRQSC_RXF_OFL				BIT(1)						 // RX FIFO Overflow
#define	I2C_ERRIRQSC_TXF_UFL				BIT(2)						 // TX FIFO Underflow
#define	I2C_ERRIRQSC_TXF_OFL				BIT(3)						 // TX FIFO Overflow

/* Protocol Interrupt Request Source Mask Register */
#define	I2C_PIRQSM							MMIO32(I2C_BASE + 0x70)
#define	I2C_PIRQSM_AM						BIT(0)						 // Address Match
#define	I2C_PIRQSM_GC						BIT(1)						 // General Call
#define	I2C_PIRQSM_MC						BIT(2)						 // Master Code
#define	I2C_PIRQSM_AL						BIT(3)						 // Arbitration Lost
#define	I2C_PIRQSM_NACK						BIT(4)						 // Not-acknowledge Received
#define	I2C_PIRQSM_TX_END					BIT(5)						 // Transmission End
#define	I2C_PIRQSM_RX						BIT(6)						 // Receive Mode

/* Protocol Interrupt Request Source Status Register */
#define	I2C_PIRQSS							MMIO32(I2C_BASE + 0x74)
#define	I2C_PIRQSS_AM						BIT(0)						 // Address Match
#define	I2C_PIRQSS_GC						BIT(1)						 // General Call
#define	I2C_PIRQSS_MC						BIT(2)						 // Master Code
#define	I2C_PIRQSS_AL						BIT(3)						 // Arbitration Lost
#define	I2C_PIRQSS_NACK						BIT(4)						 // Not-acknowledge Received
#define	I2C_PIRQSS_TX_END					BIT(5)						 // Transmission End
#define	I2C_PIRQSS_RX						BIT(6)						 // Receive Mode

/* Protocol Interrupt Request Source Clear Register */
#define	I2C_PIRQSC							MMIO32(I2C_BASE + 0x78)
#define	I2C_PIRQSC_AM						BIT(0)						 // Address Match
#define	I2C_PIRQSC_GC						BIT(1)						 // General Call
#define	I2C_PIRQSC_MC						BIT(2)						 // Master Code
#define	I2C_PIRQSC_AL						BIT(3)						 // Arbitration Lost
#define	I2C_PIRQSC_NACK						BIT(4)						 // Not-acknowledge Received
#define	I2C_PIRQSC_TX_END					BIT(5)						 // Transmission End
#define	I2C_PIRQSC_RX						BIT(6)						 // Receive Mode

/* Raw Interrupt Status Register */
#define	I2C_RIS								MMIO32(I2C_BASE + 0x80)
#define	I2C_RIS_LSREQ_INT					BIT(0)						 // Last Single Request Interrupt
#define	I2C_RIS_SREQ_INT					BIT(1)						 // Single Request Interrupt
#define	I2C_RIS_LBREQ_INT					BIT(2)						 // Last Burst Request Interrupt
#define	I2C_RIS_BREQ_INT					BIT(3)						 // Burst Request Interrupt
#define	I2C_RIS_I2C_ERR_INT					BIT(4)						 // I2C Error Interrupt
#define	I2C_RIS_I2C_P_INT					BIT(5)						 // I2C Protocol Interrupt

/* Interrupt Mask Control Register */
#define	I2C_IMSC							MMIO32(I2C_BASE + 0x84)
#define	I2C_IMSC_LSREQ_INT					BIT(0)						 // Last Single Request Interrupt
#define	I2C_IMSC_SREQ_INT					BIT(1)						 // Single Request Interrupt
#define	I2C_IMSC_LBREQ_INT					BIT(2)						 // Last Burst Request Interrupt
#define	I2C_IMSC_BREQ_INT					BIT(3)						 // Burst Request Interrupt
#define	I2C_IMSC_I2C_ERR_INT				BIT(4)						 // I2C Error Interrupt
#define	I2C_IMSC_I2C_P_INT					BIT(5)						 // I2C Protocol Interrupt

/* Masked Interrupt Status */
#define	I2C_MIS								MMIO32(I2C_BASE + 0x88)
#define	I2C_MIS_LSREQ_INT					BIT(0)						 // Last Single Request Interrupt
#define	I2C_MIS_SREQ_INT					BIT(1)						 // Single Request Interrupt
#define	I2C_MIS_LBREQ_INT					BIT(2)						 // Last Burst Request Interrupt
#define	I2C_MIS_BREQ_INT					BIT(3)						 // Burst Request Interrupt
#define	I2C_MIS_I2C_ERR_INT					BIT(4)						 // I2C Error Interrupt
#define	I2C_MIS_I2C_P_INT					BIT(5)						 // I2C Protocol Interrupt

/* Interrupt Clear Register */
#define	I2C_ICR								MMIO32(I2C_BASE + 0x8C)
#define	I2C_ICR_LSREQ_INT					BIT(0)						 // Last Single Request Interrupt
#define	I2C_ICR_SREQ_INT					BIT(1)						 // Single Request Interrupt
#define	I2C_ICR_LBREQ_INT					BIT(2)						 // Last Burst Request Interrupt
#define	I2C_ICR_BREQ_INT					BIT(3)						 // Burst Request Interrupt
#define	I2C_ICR_I2C_ERR_INT					BIT(4)						 // I2C Error Interrupt
#define	I2C_ICR_I2C_P_INT					BIT(5)						 // I2C Protocol Interrupt

/* Interrupt Set Register */
#define	I2C_ISR								MMIO32(I2C_BASE + 0x90)
#define	I2C_ISR_LSREQ_INT					BIT(0)						 // Last Single Request Interrupt
#define	I2C_ISR_SREQ_INT					BIT(1)						 // Single Request Interrupt
#define	I2C_ISR_LBREQ_INT					BIT(2)						 // Last Burst Request Interrupt
#define	I2C_ISR_BREQ_INT					BIT(3)						 // Burst Request Interrupt
#define	I2C_ISR_I2C_ERR_INT					BIT(4)						 // I2C Error Interrupt
#define	I2C_ISR_I2C_P_INT					BIT(5)						 // I2C Protocol Interrupt

/* Transmission Data Register */
#define	I2C_TXD								MMIO32(I2C_BASE + 0x8000)
#define	I2C_TXD_BYTE0						GENMASK(7, 0)
#define	I2C_TXD_BYTE0_SHIFT					0
#define	I2C_TXD_BYTE1						GENMASK(15, 8)
#define	I2C_TXD_BYTE1_SHIFT					8
#define	I2C_TXD_BYTE2						GENMASK(23, 16)
#define	I2C_TXD_BYTE2_SHIFT					16
#define	I2C_TXD_BYTE3						GENMASK(31, 24)
#define	I2C_TXD_BYTE3_SHIFT					24

/* Reception Data Register */
#define	I2C_RXD								MMIO32(I2C_BASE + 0xC000)
#define	I2C_RXD_BYTE0						GENMASK(7, 0)
#define	I2C_RXD_BYTE0_SHIFT					0
#define	I2C_RXD_BYTE1						GENMASK(15, 8)
#define	I2C_RXD_BYTE1_SHIFT					8
#define	I2C_RXD_BYTE2						GENMASK(23, 16)
#define	I2C_RXD_BYTE2_SHIFT					16
#define	I2C_RXD_BYTE3						GENMASK(31, 24)
#define	I2C_RXD_BYTE3_SHIFT					24


// MMICIF [MOD_NUM=F053, MOD_REV=00, MOD_32BIT=C0]
// Looks like "Multi Media Controller Interface" module, but not sure.
#define	MMICIF_BASE	0xF8000000
/* Clock Control Register */
#define	MMICIF_CLC	MMIO32(MMICIF_BASE + 0x00)

/* Module Identifier Register */
#define	MMICIF_ID	MMIO32(MMICIF_BASE + 0x08)


