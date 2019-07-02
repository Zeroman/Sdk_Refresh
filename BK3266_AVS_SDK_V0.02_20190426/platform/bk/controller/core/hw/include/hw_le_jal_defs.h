#ifndef _PARTHUS_HW_LE_JAL_DEFS_
#define _PARTHUS_HW_LE_JAL_DEFS_

/******************************************************************************
 * MODULE:          hw_le_jal_defs.h
 * PROJECT:         BlueStream
 * MAINTAINER:      Gary Fleming
 * CREATION NAME:   24 July, 2011
 *
 * LICENSE:
 *     This source code is copyright (c) 2000-2004 Ceva Inc.
 *     All rights reserved.
 *
 * SOURCE CONTROL: $Id: hw_le_jal_defs.h
 *
 * COMMENTS:
 *
 *     There will be the requirement to present two definitions based on
 *     the register/memory addressing approach adopted.
 *     Currently a 32 bit approach is adopted. The associated HW module
 *     is generic of the approach, but will depend on correct constants.
 *
 * REVISION HISTORY:
 ******************************************************************************/

/*
 * the error directive had a hash include in it -- some customer
 * complain at this !!
 */

/****************************************************************
*
*  Define the addresses and bit positions for the Transmit Control
*  Registers. The Addresss assume a 32 bit address space.
*  The 16 bit address bus mappings are taken care of by the macros in
*  the HW_lbl.h.
*
*****************************x***********************************/
#include "sys_features.h"

#if (PRH_BS_CFG_SYS_LE_DUAL_MODE == 1)

#if defined(TEAKLITE4) && !defined(TEAKLITE4_IO_BB_PORT)
#include <limits.h> // CHAR_BIT - Defines the number of bits in a byte - typically 8, but can be 16 (DSPs).
#define ADDR_DIV	2 //(CHAR_BIT/8)
#else
#define ADDR_DIV	1
#endif

// Dual Mode
#ifndef JAL_LE_BASE_ADDR
#define JAL_LE_BASE_ADDR (JAL_BASE_ADDR + 0x4000/ADDR_DIV) //0x00F7A000
#endif

#ifndef JAL_LE_BASE_ADDR
#error Must include "sys_config.h" for BASE_ADDR of Jalapeno/Habanero
#endif



#define JAL_LE_MODE_ADDR         (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_MODE_MASK          0x00000001
#define JAL_LE_MODE_SHFT          0

#define JAL_LE_ADDR_TYPE_ADDR    (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_ADDR_TYPE_MASK     0x00000002
#define JAL_LE_ADDR_TYPE_SHFT     1

#define JAL_LE_MASTER_MODE_ADDR   (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_MASTER_MODE_MASK    0x00000004
#define JAL_LE_MASTER_MODE_SHFT    2

#define JAL_LE_ADV_STATE_ADDR    (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_ADV_STATE_MASK     0x00000008
#define JAL_LE_ADV_STATE_SHFT     3


#define JAL_LE_TX_ENABLE_ADDR     (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_ENABLE_MASK      0x00000010
#define JAL_LE_TX_ENABLE_SHFT      4

#define JAL_LE_AES_MODE_ADDR       (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_MODE_MASK        0x00000060
#define JAL_LE_AES_MODE_SHFT        5

#define JAL_LE_AES_ENABLE_ADDR      (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_ENABLE_MASK       0x00000080
#define JAL_LE_AES_ENABLE_SHFT       7

#define JAL_LE_AES_START_ADDR      (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_START_MASK       0x40000000
#define JAL_LE_AES_START_SHFT       30

#define JAL_LE_AES_DATA_READY_ADDR      (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_DATA_READY_MASK       0x80000000
#define JAL_LE_AES_DATA_READY_SHFT       31

#define JAL_LE_TIFS_DEFAULT_ADDR  (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_DEFAULT_MASK  0x00000100
#define JAL_LE_TIFS_DEFAULT_SHFT  8

#define JAL_LE_TIFS_ABORT_ADDR   (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_ABORT_MASK    0x00000200
#define JAL_LE_TIFS_ABORT_SHFT    9

#define JAL_LE_TIFS_DELAY_ADDR   (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_DELAY_MASK    0x0000FC00
#define JAL_LE_TIFS_DELAY_SHFT    10

#define JAL_LE_WHITENING_INIT_ADDR (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_WHITENING_INIT_MASK 0x003F0000
#define JAL_LE_WHITENING_INIT_SHFT 16

#define JAL_LE_WHITENING_ENABLE_ADDR (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_WHITENING_ENABLE_MASK 0x00400000
#define JAL_LE_WHITENING_ENABLE_SHFT 22

#define JAL_LE_TEST_CRC_ADDR (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TEST_CRC_MASK 0x00800000
#define JAL_LE_TEST_CRC_SHFT 23

#define JAL_LE_DELAY_SEARCH_WIN_ADDR (0x0000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_DELAY_SEARCH_WIN_MASK 0x3F000000
#define JAL_LE_DELAY_SEARCH_WIN_SHFT 24

#define JAL_LE_PD_ADDR       (0x00000004/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RD_ADDR        (0x0000000C/ADDR_DIV + JAL_LE_BASE_ADDR)

#define JAL_LE_ACC_ADDR_ADDR    (0x00000014/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_ACC_ADDR_MASK      0xFFFFFFFF
#define JAL_LE_ACC_ADDR_SHFT      0

#define JAL_LE_PREAMBLE_ADDR     (0x00000018/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_PREAMBLE_MASK      0x000000FF
#define JAL_LE_PREAMBLE_SHFT      0

#define JAL_LE_CRC_ERR_ADDR            (0x00000018/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_CRC_ERR_MASK             0x00000100
#define JAL_LE_CRC_ERR_SHFT               8


#define JAL_LE_CRC_INIT_ADDR   (0x0000001C/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_CRC_INIT_MASK      0x00FFFFFF
#define JAL_LE_CRC_INIT_SHFT      0

// Encryption REGISTERS

// AES Key is 16 Bytes Long.
#define JAL_LE_AES_KEY_ADDR             (0x00000020/ADDR_DIV + JAL_LE_BASE_ADDR)
// AES IV is 8 Bytes Long
#define JAL_LE_AES_IV_ADDR                (0x00000030/ADDR_DIV + JAL_LE_BASE_ADDR)
// AES Pkt Counter is 5 Bytes Long

#define JAL_LE_AES_PKTCNT1_B0_ADDR      (0x00000038/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B0_MASK       0x000000FF
#define JAL_LE_AES_PKTCNT1_B0_SHFT       0

#define JAL_LE_AES_PKTCNT1_B1_ADDR      (0x00000038/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B1_MASK       0x0000FF00
#define JAL_LE_AES_PKTCNT1_B1_SHFT       8

#define JAL_LE_AES_PKTCNT1_B2_ADDR      (0x00000038/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B2_MASK       0x00FF0000
#define JAL_LE_AES_PKTCNT1_B2_SHFT       16

#define JAL_LE_AES_PKTCNT1_B3_ADDR      (0x00000038/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B3_MASK       0xFF000000
#define JAL_LE_AES_PKTCNT1_B3_SHFT       24

#define JAL_LE_AES_PKTCNT1_B4_ADDR      (0x0000003C/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B4_MASK       0x000000FF
#define JAL_LE_AES_PKTCNT1_B4_SHFT       0


//#define JAL_LE_AES_PKT_COUNTER1_ADDR       (0x00000038 + JAL_LE_BASE_ADDR)
//#define JAL_LE_AES_PKT_COUNTER1_MASK       0xFFFFFFFF
//#define JAL_LE_AES_PKT_COUNTER1_SHFT       0

//#define JAL_LE_AES_PKT_COUNTER2_ADDR       (0x0000003C + JAL_LE_BASE_ADDR)
//#define JAL_LE_AES_PKT_COUNTER2_MASK       0x000000FF
//#define JAL_LE_AES_PKT_COUNTER2_SHFT       0

#define JAL_LE_AES_PKT_LENGTH_ADDR        (0x0000003C/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKT_LENGTH_MASK        0x00001F00
#define JAL_LE_AES_PKT_LENGTH_SHFT        8

#define JAL_LE_AES_PKT_LLID_ADDR       (0x0000003C/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKT_LLID_MASK        0x00006000
#define JAL_LE_AES_PKT_LLID_SHFT        13

// Test Mode Header Registers - the test mode registers are overwritten on the advertising channel header registers.
#define JAL_LE_TX_TEST_PDU_TYPE_ADDR   (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_TYPE_MASK    0x0000000F
#define JAL_LE_TX_TEST_PDU_TYPE_SHFT    0

#define JAL_LE_TX_TEST_PDU_RFU1_ADDR (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_RFU1_MASK 0x000000F0
#define JAL_LE_TX_TEST_PDU_RFU1_SHFT 4

#define JAL_LE_TX_TEST_PDU_LEN_ADDR (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_LEN_MASK  0x00003F00
#define JAL_LE_TX_TEST_PDU_LEN_SHFT  8

#define JAL_LE_TX_TEST_PDU_RFU2_ADDR  (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_RFU2_MASK   0x0000C000
#define JAL_LE_TX_TEST_PDU_RFU2_SHFT   14



// Transmitter Header Registers

#define JAL_LE_TX_PDU_TYPE_ADDR          (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_PDU_TYPE_MASK      0x0000000F
#define JAL_LE_TX_PDU_TYPE_SHFT      0

#define JAL_LE_TX_RFU1_ADV_ADDR        (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_RFU1_ADV_MASK       0x00000030
#define JAL_LE_TX_RFU1_ADV_SHFT       4


#define JAL_LE_TX_TX_ADD_ADDR       (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TX_ADD_MASK        0x00000040
#define JAL_LE_TX_TX_ADD_SHFT        6

#define JAL_LE_TX_RX_ADD_ADDR       (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_RX_ADD_MASK        0x00000080
#define JAL_LE_TX_RX_ADD_SHFT        7


#define JAL_LE_TX_LENGTH_ADV_ADDR  (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_LENGTH_ADV_MASK   0x00003F00
#define JAL_LE_TX_LENGTH_ADV_SHFT   8

#define JAL_LE_TX_RFU2_ADV_ADDR           (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_RFU2_ADV_MASK       0x0000C000
#define JAL_LE_TX_RFU2_ADV_SHFT       14

#define JAL_LE_TX_ADV_HEADER_ADDR  (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_ADV_HEADER_MASK   0x0000FFFF
#define JAL_LE_TX_ADV_HEADER_SHFT   0

#define JAL_LE_TX_BUFF_WIN_SIZE_ADDR   ((HWle_get_tx_acl_buf_addr() + 16/ADDR_DIV))
#define JAL_LE_TX_BUFF_WIN_SIZE_MASK   0xFF000000
#define JAL_LE_TX_BUFF_WIN_SIZE_SHFT   24

#define JAL_LE_TX_BUFF_WIN_OFFSET_ADDR   ((HWle_get_tx_acl_buf_addr()+ 20/ADDR_DIV))
#define JAL_LE_TX_BUFF_WIN_OFFSET_MASK   0x0000FFFF
#define JAL_LE_TX_BUFF_WIN_OFFSET_SHFT   0

#define JAL_LE_TX_BUF_ADDR1_ADDR ((HWle_get_tx_acl_buf_addr() + 4/ADDR_DIV))
#define JAL_LE_TX_BUF_ADDR1_MASK 0xFFFF0000
#define JAL_LE_TX_BUF_ADDR1_SHFT 16

#define JAL_LE_TX_BUF_ADDR2_ADDR (HWle_get_tx_acl_buf_addr() + 8/ADDR_DIV)
#define JAL_LE_TX_BUF_ADDR2_MASK 0xFFFFFFFF
#define JAL_LE_TX_BUF_ADDR2_SHFT 0


#define JAL_LE_TX_DATA_HEADER_ADDR  (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_DATA_HEADER_MASK  0xFFFF0000
#define JAL_LE_TX_DATA_HEADER_SHFT  16

#define JAL_LE_TX_LLID_ADDR  (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_LLID_MASK   0x00030000
#define JAL_LE_TX_LLID_SHFT   16

#define JAL_LE_TX_NESN_ADDR  (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_NESN_MASK   0x00040000
#define JAL_LE_TX_NESN_SHFT   18

#define JAL_LE_TX_SN_ADDR    (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_SN_MASK     0x00080000
#define JAL_LE_TX_SN_SHFT     19

#define JAL_LE_TX_MD_ADDR    (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_MD_MASK     0x00100000
#define JAL_LE_TX_MD_SHFT     20

#define JAL_LE_TX_LENGTH_DATA_ADDR (0x00000040/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_LENGTH_DATA_MASK  0x1F000000
#define JAL_LE_TX_LENGTH_DATA_SHFT  24


#define JAL_LE_RX_HEADER_ADDR            (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_HEADER_MASK             0x0000FFFF
#define JAL_LE_RX_HEADER_SHFT             0

#define JAL_LE_RX_PDU_TYPE_ADDR          (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_PDU_TYPE_MASK           0x0000000F
#define JAL_LE_RX_PDU_TYPE_SHFT           0

#define JAL_LE_RX_RFU1_ADV_ADDR        (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RFU1_ADV_MASK       0x00000030
#define JAL_LE_RX_RFU1_ADV_SHFT       4

#define JAL_LE_RX_TX_ADD_ADDR       (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_TX_ADD_MASK        0x00000040
#define JAL_LE_RX_TX_ADD_SHFT        6

#define JAL_LE_RX_RX_ADD_ADDR       (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RX_ADD_MASK        0x00000080
#define JAL_LE_RX_RX_ADD_SHFT        7

#define JAL_LE_RX_LENGTH_ADV_ADDR  (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_LENGTH_ADV_MASK   0x00003F00
#define JAL_LE_RX_LENGTH_ADV_SHFT   8

#define JAL_LE_RX_RFU2_ADV_ADDR           (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RFU2_ADV_MASK       0x0000C000
#define JAL_LE_RX_RFU2_ADV_SHFT       14


#define JAL_LE_RX_LLID_ADDR  (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_LLID_MASK   0x00000003
#define JAL_LE_RX_LLID_SHFT   0

#define JAL_LE_RX_NESN_ADDR  (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_NESN_MASK   0x0000004
#define JAL_LE_RX_NESN_SHFT   2

#define JAL_LE_RX_SN_ADDR    (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_SN_MASK     0x00000008
#define JAL_LE_RX_SN_SHFT     3

#define JAL_LE_RX_MD_ADDR    (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MD_MASK     0x00000010
#define JAL_LE_RX_MD_SHFT     4

#define JAL_LE_RX_RFU_DATA_LO_ADDR (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RFU_DATA_LO_MASK  0x000000E0
#define JAL_LE_RX_RFU_DATA_LO_SHFT  5

#define JAL_LE_RX_LENGTH_DATA_ADDR (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_LENGTH_DATA_MASK  0x00001F00
#define JAL_LE_RX_LENGTH_DATA_SHFT  8

#define JAL_LE_RX_RFU_DATA_HI_ADDR (0x00000044/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RFU_DATA_HI_MASK  0x0000E000
#define JAL_LE_RX_RFU_DATA_HI_SHFT  13


#if 0 //(PRH_SYS_CFG_HARDWARE_ADDRESS_FILTERING_SUPPORTED == 0)
// The REGISTERS for HARDWARE ADDRESS filtering should allways be in place
// even if disabled in the build.. I always want to access the registers to
// HWle_set_rx_filters_active(0) to turn off the HW.

#define JAL_LE_AES_MIC_ADDR  (0x00000050/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_MIC_MASK  0xFFFFFFFF
#define JAL_LE_AES_MIC_SHFT  0

#define JAL_LE_AES_RX_MIC_STATUS_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_RX_MIC_STATUS_MASK  0x00000001
#define JAL_LE_AES_RX_MIC_STATUS_SHFT  0

#define JAL_LE_AES_ACTIVE_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_ACTIVE_MASK  0x00000002
#define JAL_LE_AES_ACTIVE_SHFT  1

#define JAL_LE_AES_FINISHED_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_FINISHED_MASK  0x00000004
#define JAL_LE_AES_FINISHED_SHFT  2

#define JAL_LE_SPI_LE_ONLY_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_SPI_LE_ONLY_MASK   0x00000001
#define JAL_LE_SPI_LE_ONLY_SHFT   0

#define JAL_LE_AUXLE1_TIMER_ADDR   (0x00000060/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AUXLE1_TIMER_MASK    0x00003FFF
#define JAL_LE_AUXLE1_TIMER_SHFT    0

#define JAL_LE_AUXLE2_TIMER_ADDR   (0x00000064/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AUXLE2_TIMER_MASK    0x00003FFF
#define JAL_LE_AUXLE2_TIMER_SHFT    0

#define JAL_LE_RX_MIC_ADDR         (0x00000070/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MIC_MASK          0xFFFFFFFF
#define JAL_LE_RX_MIC_SHFT          0

#define JAL_LE_TX_MIC_ADDR         (0x00000074/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_MIC_MASK          0xFFFFFFFF
#define JAL_LE_TX_MIC_SHFT          0

#define JAL_LE_RX_MIC_STATUS_ADDR  (0x00000078/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MIC_STATUS_MASK   0x00000001
#define JAL_LE_RX_MIC_STATUS_SHFT   0

#else

#define JAL_LE_FILTER_ADDR         (0x00000060/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_IMMEDIATE_ADDR      (0x00000090/ADDR_DIV + JAL_LE_BASE_ADDR)      
#define JAL_LE_TARGET_ADDR         (0x00000098/ADDR_DIV + JAL_LE_BASE_ADDR)   

#define JAL_LE_RX_CONTROL_REG      (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)

#define JAL_LE_IMMEDIATE_FILTER_TX_ADDR_TYPE_ADDR (0x00000094/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_IMMEDIATE_FILTER_TX_ADDR_TYPE_MASK 0x40000000
#define JAL_LE_IMMEDIATE_FILTER_TX_ADDR_TYPE_SHFT 22

#define JAL_LE_TARGET_ADDRESS_RX_ADDR_TYPE_ADDR ((0x00000098 + 4)/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TARGET_ADDRESS_RX_ADDR_TYPE_MASK 0x40000000
#define JAL_LE_TARGET_ADDRESS_RX_ADDR_TYPE_SHFT 22

#define JAL_LE_AES_RX_MIC_STATUS_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_RX_MIC_STATUS_MASK  0x00000001
#define JAL_LE_AES_RX_MIC_STATUS_SHFT  0

#define JAL_LE_AES_ACTIVE_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_ACTIVE_MASK  0x00000002
#define JAL_LE_AES_ACTIVE_SHFT  1

#define JAL_LE_AES_FINISHED_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_FINISHED_MASK  0x00000004
#define JAL_LE_AES_FINISHED_SHFT  2

#define JAL_LE_TIFS_ABORTED_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_ABORTED_MASK  0x00000040
#define JAL_LE_TIFS_ABORTED_SHFT  6

#define JAL_LE_CRC_ERROR_SHADOW_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_CRC_ERROR_SHADOW_MASK  0x00000080
#define JAL_LE_CRC_ERROR_SHADOW_SHFT  7

#define JAL_LE_RX_FILTERED_ENUM_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_FILTERED_ENUM_MASK  0x00000700
#define JAL_LE_RX_FILTERED_ENUM_SHFT  8

#define JAL_LE_TARGET_ADDRESS_MATCH_ADDR  (0x00000054/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TARGET_ADDRESS_MATCH_MASK  0x00000800
#define JAL_LE_TARGET_ADDRESS_MATCH_SHFT  11

#define JAL_LE_TARGET_LAST_RXED_ADDR  (0x0000009C/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TARGET_LAST_RXED_MASK  0x02000000
#define JAL_LE_TARGET_LAST_RXED_SHFT  25

#define JAL_LE_RX_CONTROL_BYTE2_ADDR (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_CONTROL_BYTE2_MASK  0x0000FF00
#define JAL_LE_RX_CONTROL_BYTE2_SHFT  8


// New Advanced LE Rx Control Register
// Note :- Some elements are just shadows of bits held in other address

#define JAL_LE_SPI_LE_ONLY_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_SPI_LE_ONLY_MASK   0x00000001
#define JAL_LE_SPI_LE_ONLY_SHFT   0

#define JAL_LE_MASTER_MODE_SHADOW_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_MASTER_MODE_SHADOW_MASK  0x00000004
#define JAL_LE_MASTER_MODE_SHADOW_SHFT  2

#define JAL_LE_ADV_STATE_SHADOW_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_ADV_STATE_SHADOW_MASK  0x00000008
#define JAL_LE_ADV_STATE_SHADOW_SHFT  3

#define JAL_LE_TX_EN_SHADOW_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_EN_SHADOW_MASK  0x00000010
#define JAL_LE_TX_EN_SHADOW_SHFT  4

#define JAL_LE_RX_MODE_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MODE_MASK  0x000000E0
#define JAL_LE_RX_MODE_SHFT  5

#define JAL_LE_T_IFS_DEFAULT_SHADOW_ADDR (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_T_IFS_DEFAULT_SHADOW_MASK  0x00000100
#define JAL_LE_T_IFS_DEFAULT_SHADOW_SHFT  8

#define JAL_LE_T_IFS_ABORT_SHADOW_ADDR (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_T_IFS_ABORT_SHADOW_MASK  0x00000200
#define JAL_LE_T_IFS_ABORT_SHADOW_SHFT  9

#define JAL_LE_END_CONNECT_ADDR (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_END_CONNECT_MASK  0x00000400
#define JAL_LE_END_CONNECT_SHFT  10

#define JAL_LE_ADDRESS_FILTERING_ON_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_ADDRESS_FILTERING_ON_MASK  0x00002000
#define JAL_LE_ADDRESS_FILTERING_ON_SHFT  13

#define JAL_LE_FILTER_CONNECT_REQ_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_FILTER_CONNECT_REQ_MASK  0x00004000
#define JAL_LE_FILTER_CONNECT_REQ_SHFT  14

#define JAL_LE_FILTER_SCAN_REQ_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_FILTER_SCAN_REQ_MASK  0x00008000
#define JAL_LE_FILTER_SCAN_REQ_SHFT  15

#define JAL_LE_FILTER_CONTROL_SHADOW_ADDR  (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_FILTER_CONTROL_SHADOW_MASK  0x007F0000
#define JAL_LE_FILTER_CONTROL_SHADOW_SHFT  16

#define JAL_LE_IMMEDIATE_FILTER_SHADOW_ADDR   (0x00000058/ADDR_DIV + JAL_LE_BASE_ADDR)
#define JAL_LE_IMMEDIATE_FILTER_SHADOW_MASK   0x00800000
#define JAL_LE_IMMEDIATE_FILTER_SHADOW_SHFT   22

#endif

//#define JAL_LE_TX_ACL_BASE_ADDR              (0x00000200 + JAL_LE_BASE_ADDR)
//#define JAL_LE_RX_ACL_BASE_ADDR              (0x00000400 + JAL_LE_BASE_ADDR)

#define JAL_LE_AES_BUFFER_ADDR               (0x00000200/ADDR_DIV + JAL_LE_BASE_ADDR)

#define JAL_LE_ACL_BUF_LEN  168
#define JAL_LE_AES_BUF_LEN  0x20


#else // Single Mode

// Single Mode
#define JAL_LE_BASE_ADDR 0x00F7A000

#ifndef JAL_LE_BASE_ADDR
#error Must include "sys_config.h" for BASE_ADDR of Jalapeno/Habanero
#endif
//
#define JAL_LE_MODE_ADDR         (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_MODE_MASK          0x00000001
#define JAL_LE_MODE_SHFT          0

#define JAL_LE_ADDR_TYPE_ADDR    (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_ADDR_TYPE_MASK     0x00000002
#define JAL_LE_ADDR_TYPE_SHFT     1

#define JAL_LE_MASTER_MODE_ADDR   (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_MASTER_MODE_MASK    0x00000004
#define JAL_LE_MASTER_MODE_SHFT    2

#define JAL_LE_ADV_STATE_ADDR    (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_ADV_STATE_MASK     0x00000008
#define JAL_LE_ADV_STATE_SHFT     3

#define JAL_LE_TX_ENABLE_ADDR     (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_ENABLE_MASK      0x00000010
#define JAL_LE_TX_ENABLE_SHFT      4

#define JAL_LE_AES_MODE_ADDR       (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_MODE_MASK        0x00000060
#define JAL_LE_AES_MODE_SHFT        5

#define JAL_LE_AES_ENABLE_ADDR      (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_ENABLE_MASK       0x00000080
#define JAL_LE_AES_ENABLE_SHFT       7


#define JAL_LE_TIFS_DEFAULT_ADDR  (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_DEFAULT_MASK  0x00000100
#define JAL_LE_TIFS_DEFAULT_SHFT  8

#define JAL_LE_TIFS_ABORT_ADDR   (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_ABORT_MASK    0x00000200
#define JAL_LE_TIFS_ABORT_SHFT    9

#define JAL_LE_TIFS_DELAY_ADDR   (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TIFS_DELAY_MASK    0x0000FC00
#define JAL_LE_TIFS_DELAY_SHFT    10

#define JAL_LE_WHITENING_INIT_ADDR (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_WHITENING_INIT_MASK 0x003F0000
#define JAL_LE_WHITENING_INIT_SHFT 16

#define JAL_LE_WHITENING_ENABLE_ADDR (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_WHITENING_ENABLE_MASK 0x00400000
#define JAL_LE_WHITENING_ENABLE_SHFT 22

#define JAL_LE_TEST_CRC_ADDR (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_TEST_CRC_MASK 0x00800000
#define JAL_LE_TEST_CRC_SHFT 23

#define JAL_LE_DELAY_SEARCH_WIN_ADDR (0x0000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_DELAY_SEARCH_WIN_MASK 0x3F000000
#define JAL_LE_DELAY_SEARCH_WIN_SHFT 24

#define JAL_LE_AES_START_ADDR      (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_START_MASK       0x40000000
#define JAL_LE_AES_START_SHFT       30

#define JAL_LE_AES_DATA_READY_ADDR      (0x00000000 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_DATA_READY_MASK       0x80000000
#define JAL_LE_AES_DATA_READY_SHFT       31

#define JAL_LE_PD_ADDR       (0x00000004 + JAL_LE_BASE_ADDR)
#define JAL_LE_RD_ADDR        (0x0000000C + JAL_LE_BASE_ADDR)

#define JAL_LE_ACC_ADDR_ADDR    (0x00000014 + JAL_LE_BASE_ADDR)
#define JAL_LE_ACC_ADDR_MASK      0xFFFFFFFF
#define JAL_LE_ACC_ADDR_SHFT      0

#define JAL_LE_PREAMBLE_ADDR     (0x00000018 + JAL_LE_BASE_ADDR)
#define JAL_LE_PREAMBLE_MASK      0x000000FF
#define JAL_LE_PREAMBLE_SHFT      0

#define JAL_LE_CRC_ERR_ADDR            (0x00000018 + JAL_LE_BASE_ADDR)
#define JAL_LE_CRC_ERR_MASK             0x00000100
#define JAL_LE_CRC_ERR_SHFT               8


#define JAL_LE_CRC_INIT_ADDR   (0x0000001C + JAL_LE_BASE_ADDR)
#define JAL_LE_CRC_INIT_MASK      0x00FFFFFF
#define JAL_LE_CRC_INIT_SHFT      0

// Encryption REGISTERS

// AES Key is 16 Bytes Long.
#define JAL_LE_AES_KEY_ADDR             (0x00000020 + JAL_LE_BASE_ADDR)
// AES IV is 8 Bytes Long
#define JAL_LE_AES_IV_ADDR                (0x00000030 + JAL_LE_BASE_ADDR)
// AES Pkt Counter is 5 Bytes Long

#define JAL_LE_AES_PKTCNT1_B0_ADDR      (0x00000038 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B0_MASK       0x000000FF
#define JAL_LE_AES_PKTCNT1_B0_SHFT       0

#define JAL_LE_AES_PKTCNT1_B1_ADDR      (0x00000038 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B1_MASK       0x0000FF00
#define JAL_LE_AES_PKTCNT1_B1_SHFT       8

#define JAL_LE_AES_PKTCNT1_B2_ADDR      (0x00000038 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B2_MASK       0x00FF0000
#define JAL_LE_AES_PKTCNT1_B2_SHFT       16

#define JAL_LE_AES_PKTCNT1_B3_ADDR      (0x00000038 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B3_MASK       0xFF000000
#define JAL_LE_AES_PKTCNT1_B3_SHFT       24

#define JAL_LE_AES_PKTCNT1_B4_ADDR      (0x0000003C + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKTCNT1_B4_MASK       0x000000FF
#define JAL_LE_AES_PKTCNT1_B4_SHFT       0


//#define JAL_LE_AES_PKT_COUNTER1_ADDR       (0x00000038 + JAL_LE_BASE_ADDR)
//#define JAL_LE_AES_PKT_COUNTER1_MASK       0xFFFFFFFF
//#define JAL_LE_AES_PKT_COUNTER1_SHFT       0

//#define JAL_LE_AES_PKT_COUNTER2_ADDR       (0x0000003C + JAL_LE_BASE_ADDR)
//#define JAL_LE_AES_PKT_COUNTER2_MASK       0x000000FF
//#define JAL_LE_AES_PKT_COUNTER2_SHFT       0

#define JAL_LE_AES_PKT_LENGTH_ADDR        (0x0000003C + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKT_LENGTH_MASK        0x00001F00
#define JAL_LE_AES_PKT_LENGTH_SHFT        8

#define JAL_LE_AES_PKT_LLID_ADDR       (0x0000003C + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_PKT_LLID_MASK        0x00006000
#define JAL_LE_AES_PKT_LLID_SHFT        13

// Transmitter Header Registers

#define JAL_LE_TX_PDU_TYPE_ADDR          (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_PDU_TYPE_MASK      0x0000000F
#define JAL_LE_TX_PDU_TYPE_SHFT      0

#define JAL_LE_TX_RFU1_ADV_ADDR        (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_RFU1_ADV_MASK       0x00000030
#define JAL_LE_TX_RFU1_ADV_SHFT       4


#define JAL_LE_TX_TX_ADD_ADDR       (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TX_ADD_MASK        0x00000040
#define JAL_LE_TX_TX_ADD_SHFT        6

#define JAL_LE_TX_ADV_HEADER_ADDR  (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_ADV_HEADER_MASK   0x0000FFFF
#define JAL_LE_TX_ADV_HEADER_SHFT   0

#define JAL_LE_TX_BUFF_WIN_SIZE_ADDR   ((HWle_get_tx_acl_buf_addr() + 16))
#define JAL_LE_TX_BUFF_WIN_SIZE_MASK   0xFF000000
#define JAL_LE_TX_BUFF_WIN_SIZE_SHFT   24

#define JAL_LE_TX_BUFF_WIN_OFFSET_ADDR   ((HWle_get_tx_acl_buf_addr()+ 20))
#define JAL_LE_TX_BUFF_WIN_OFFSET_MASK   0xFFFF0000
#define JAL_LE_TX_BUFF_WIN_OFFSET_SHFT   16

#define JAL_LE_TX_BUF_ADDR1_ADDR ((HWle_get_tx_acl_buf_addr() + 4))
#define JAL_LE_TX_BUF_ADDR1_MASK 0xFFFF0000
#define JAL_LE_TX_BUF_ADDR1_SHFT 16

#define JAL_LE_TX_BUF_ADDR2_ADDR (HWle_get_tx_acl_buf_addr() + 8)
#define JAL_LE_TX_BUF_ADDR2_MASK 0xFFFFFFFF
#define JAL_LE_TX_BUF_ADDR2_SHFT 0

#define JAL_LE_TX_DATA_HEADER_ADDR  (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_DATA_HEADER_MASK  0xFFFF0000
#define JAL_LE_TX_DATA_HEADER_SHFT  16

#define JAL_LE_TX_RX_ADD_ADDR       (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_RX_ADD_MASK        0x00000080
#define JAL_LE_TX_RX_ADD_SHFT        7


#define JAL_LE_TX_LENGTH_ADV_ADDR  (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_LENGTH_ADV_MASK   0x00003F00
#define JAL_LE_TX_LENGTH_ADV_SHFT   8

#define JAL_LE_TX_RFU2_ADV_ADDR           (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_RFU2_ADV_MASK       0x0000C000
#define JAL_LE_TX_RFU2_ADV_SHFT       14

#define JAL_LE_TX_LLID_ADDR  (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_LLID_MASK   0x00030000
#define JAL_LE_TX_LLID_SHFT   16

#define JAL_LE_TX_NESN_ADDR  (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_NESN_MASK   0x00040000
#define JAL_LE_TX_NESN_SHFT   18

#define JAL_LE_TX_SN_ADDR    (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_SN_MASK     0x00080000
#define JAL_LE_TX_SN_SHFT     19

#define JAL_LE_TX_MD_ADDR    (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_MD_MASK     0x00100000
#define JAL_LE_TX_MD_SHFT     20

#define JAL_LE_TX_LENGTH_DATA_ADDR (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_LENGTH_DATA_MASK  0x1F000000
#define JAL_LE_TX_LENGTH_DATA_SHFT  24


#define JAL_LE_RX_HEADER_ADDR            (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_HEADER_MASK             0x0000FFFF
#define JAL_LE_RX_HEADER_SHFT             0

#define JAL_LE_RX_PDU_TYPE_ADDR          (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_PDU_TYPE_MASK           0x0000000F
#define JAL_LE_RX_PDU_TYPE_SHFT           0

#define JAL_LE_RX_RFU1_ADV_ADDR        (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RFU1_ADV_MASK       0x00000030
#define JAL_LE_RX_RFU1_ADV_SHFT       4

#define JAL_LE_RX_TX_ADD_ADDR       (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_TX_ADD_MASK        0x00000040
#define JAL_LE_RX_TX_ADD_SHFT        6

#define JAL_LE_RX_RX_ADD_ADDR       (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RX_ADD_MASK        0x00000080
#define JAL_LE_RX_RX_ADD_SHFT        7

#define JAL_LE_RX_LENGTH_ADV_ADDR  (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_LENGTH_ADV_MASK   0x00003F00
#define JAL_LE_RX_LENGTH_ADV_SHFT   8

#define JAL_LE_RX_RFU2_ADV_ADDR           (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_RFU2_ADV_MASK       0x0000C000
#define JAL_LE_RX_RFU2_ADV_SHFT       14


#define JAL_LE_RX_LLID_ADDR  (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_LLID_MASK   0x00000003
#define JAL_LE_RX_LLID_SHFT   0

#define JAL_LE_RX_NESN_ADDR  (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_NESN_MASK   0x0000004
#define JAL_LE_RX_NESN_SHFT   2

#define JAL_LE_RX_SN_ADDR    (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_SN_MASK     0x00000008
#define JAL_LE_RX_SN_SHFT     3

#define JAL_LE_RX_MD_ADDR    (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MD_MASK     0x00000010
#define JAL_LE_RX_MD_SHFT     4

#define JAL_LE_RX_LENGTH_DATA_ADDR (0x00000044 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_LENGTH_DATA_MASK  0x00001F00
#define JAL_LE_RX_LENGTH_DATA_SHFT  8


#define JAL_LE_AUXLE1_TIMER_ADDR   (0x00000048 + JAL_LE_BASE_ADDR)
#define JAL_LE_AUXLE1_TIMER_MASK    0x00003FFF
#define JAL_LE_AUXLE1_TIMER_SHFT    0

#define JAL_LE_AUXLE2_TIMER_ADDR   (0x0000004C + JAL_LE_BASE_ADDR)
#define JAL_LE_AUXLE2_TIMER_MASK    0x00003FFF
#define JAL_LE_AUXLE2_TIMER_SHFT    0

#define JAL_LE_AES_MIC_ADDR  (0x00000050 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_MIC_MASK  0xFFFFFFFF
#define JAL_LE_AES_MIC_SHFT  0

#define JAL_LE_AES_RX_MIC_STATUS_ADDR  (0x00000054 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_RX_MIC_STATUS_MASK  0x00000001
#define JAL_LE_AES_RX_MIC_STATUS_SHFT  0

#define JAL_LE_AES_ACTIVE_ADDR  (0x00000054 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_ACTIVE_MASK  0x00000002
#define JAL_LE_AES_ACTIVE_SHFT  1

#define JAL_LE_AES_FINISHED_ADDR  (0x00000054 + JAL_LE_BASE_ADDR)
#define JAL_LE_AES_FINISHED_MASK  0x00000004
#define JAL_LE_AES_FINISHED_SHFT  2

#define JAL_LE_SPI_LE_ONLY_ADDR  (0x00000058 + JAL_LE_BASE_ADDR)
#define JAL_LE_SPI_LE_ONLY_MASK   0x00000001
#define JAL_LE_SPI_LE_ONLY_SHFT   0


#define JAL_LE_RX_MIC_ADDR         (0x00000050 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MIC_MASK          0xFFFFFFFF
#define JAL_LE_RX_MIC_SHFT          0

#define JAL_LE_TX_MIC_ADDR         (0x00000050 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_MIC_MASK          0xFFFFFFFF
#define JAL_LE_TX_MIC_SHFT          0

#define JAL_LE_RX_MIC_STATUS_ADDR  (0x00000054 + JAL_LE_BASE_ADDR)
#define JAL_LE_RX_MIC_STATUS_MASK   0x00000001
#define JAL_LE_RX_MIC_STATUS_SHFT   0

#define JAL_LE_AES_BUFFER_ADDR               (0x00000060 + JAL_LE_BASE_ADDR)

#define JAL_LE_ACL_BUF_LEN  0x27
#define JAL_LE_AES_BUF_LEN  0x27


// Test Mode Header Registers - the test mode registers are overwritten on the advertising channel header registers.
#define JAL_LE_TX_TEST_PDU_TYPE_ADDR   (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_TYPE_MASK    0x0000000F
#define JAL_LE_TX_TEST_PDU_TYPE_SHFT    0

#define JAL_LE_TX_TEST_PDU_RFU1_ADDR (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_RFU1_MASK 0x000000F0
#define JAL_LE_TX_TEST_PDU_RFU1_SHFT 4

#define JAL_LE_TX_TEST_PDU_LEN_ADDR (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_LEN_MASK  0x00003F00
#define JAL_LE_TX_TEST_PDU_LEN_SHFT  8

#define JAL_LE_TX_TEST_PDU_RFU2_ADDR  (0x00000040 + JAL_LE_BASE_ADDR)
#define JAL_LE_TX_TEST_PDU_RFU2_MASK   0x0000C000
#define JAL_LE_TX_TEST_PDU_RFU2_SHFT   14


#endif
#endif
