#ifndef  __MOTROL_H
#define  __MOTROL_H
#include "stm32f10x.h"


void Motrol_ImpactArena(void);
void Prevent_DropArena(void);

void Motrol_Advance100(void);
void Motrol_Advance200(void);
void Motrol_Advance300(void);
void Motrol_Advance400(void);
void Motrol_Advance500(void);
void Motrol_Advance600(void);
void Motrol_Advance700(void);
void Motrol_Advance800(void);

void Motrol_Retreat200(void);
void Motrol_Retreat400(void);
void Motrol_Retreat500(void);
void Motrol_Retreat600(void);
void Motrol_Retreat700(void);
void Motrol_Retreat800(void);

void Motrol_TurnRight(void);
void Motrol_TurnLeft(void);

void Motrol_TurnRight45_Angle(void);
void Motrol_TurnRight90_Angle(void);
void Motrol_TurnRight180_Angle(void);

void Motrol_TurnLeft45_Angle(void);
void Motrol_TurnLeft90_Angle(void);
void Motrol_TurnLeft180_Angle(void);

void Motrol_Stop(void);



#endif