/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_timer_handler(char *param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  byte bVar7;
  
  if (param_1 != (char *)0x0) goto _L98;
  do {
    param_1 = (char *)__assert_func(0,0,0,0);
_L98:
    iVar3 = on_off_srv_get_attr_desc(*param_1,0);
    iVar4 = on_off_srv_get_attr_desc(*param_1,0x4001);
    iVar5 = on_off_srv_get_attr_desc(*param_1,0x4002);
  } while (iVar3 == 0);
  if ((iVar4 != 0) && (iVar5 != 0)) {
    sVar6 = **(short **)(iVar5 + 8);
    sVar2 = **(short **)(iVar4 + 8);
    if (**(byte **)(iVar3 + 8) == 0) {
      bVar7 = 0;
      if (sVar6 != 0) {
        sVar6 = sVar6 + -1;
      }
    }
    else if (sVar2 == 0) {
      bVar7 = 0;
    }
    else {
      sVar2 = sVar2 + -1;
      bVar7 = **(byte **)(iVar3 + 8) & -(sVar2 != 0);
    }
    on_off_process_transition(*param_1,0x42,bVar7,sVar2,sVar6);
    if (bVar7 != 0) {
      sVar6 = sVar2;
    }
    if (sVar6 != 0) {
      cVar1 = *param_1;
      iVar3 = on_off_srv_get_attr_desc_part_0();
      if ((iVar3 != 0) && (**(char **)(iVar3 + 8) == cVar1)) {
        milli_timer_start(*(char **)(iVar3 + 8) + 4,100);
        return;
      }
      return;
    }
  }
  return;
}

