/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file NVIC_interface.h
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_



#define		GRP_16_SUB_0		((uint32)0x5FA00300)
#define		GRP_8_SUB_2			((uint32)0x5FA00400)
#define		GRP_4_SUB_4			((uint32)0x5FA00500)
#define		GRP_2_SUB_8			((uint32)0x5FA00600)
#define		GRP_0_SUB_16		((uint32)0x5FA00700)

void NVIC_voidInit(void);
void NVIC_voidPerInterruptEnable(uint8 PerId);
void NVIC_voidPerInterruptDisable(uint8 PerId);
void NVIC_voidSetPindingFlag(uint8 PerId);
void NVIC_voidClearPindingFlag(uint8 PerId);
uint8 NVIC_u8GetActiveFlag(uint8 PerId);
void NVIC_voidSetPriority(uint8 PerID,uint8 PriorityNum);
void NVIC_voidSetCallBackFunc(void (*Copy_pvFunc)(void));

#endif /* NVIC_INTERFACE_H_ */
