/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> check_value_simple_s16_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool check_value_simple_s16_measurement_server
               (undefined4 param_1,uint param_2,undefined4 param_3,short *param_4,short *param_5)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  
  if (3 < param_2) {
    return false;
  }
  sVar1 = *param_4;
  if (sVar1 == -0x8000) {
    bVar3 = false;
  }
  else {
    if (param_2 == 3) {
      sVar6 = param_5[2];
      sVar5 = param_5[3];
    }
    else {
      sVar6 = *param_5;
      sVar5 = param_5[1];
      if ((param_2 & 0xfffffffd) != 0) goto _L0;
      iVar4 = simple_measurement_srv_get_attr_desc(param_3,param_1,1);
      if (iVar4 != 0) goto _L0;
      do {
        do {
          iVar4 = __assert_func(0,0,0,0);
_L0:
        } while (*(short **)(iVar4 + 8) == (short *)0x0);
        sVar2 = **(short **)(iVar4 + 8);
        if (sVar2 != -0x8000) {
          sVar6 = sVar2;
        }
        if (param_2 == 2) goto _L0;
_L0:
        iVar4 = simple_measurement_srv_get_attr_desc(param_3,param_1,2);
      } while ((iVar4 == 0) || (*(short **)(iVar4 + 8) == (short *)0x0));
      sVar2 = **(short **)(iVar4 + 8);
      if (sVar2 != -0x8000) {
        sVar5 = sVar2;
      }
    }
_L0:
    bVar3 = sVar1 < sVar6 || sVar5 < sVar1;
  }
  return bVar3;
}

