/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> pressure_measurement_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool pressure_measurement_cluster_srv_check_value_handler
               (uint param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  
  if (3 < param_1) {
    return false;
  }
  sVar1 = *param_3;
  if (sVar1 == -0x8000) {
    bVar3 = false;
  }
  else {
    if (param_1 == 3) {
      sVar6 = 0;
      sVar5 = 0x800;
    }
    else {
      sVar6 = -0x7fff;
      sVar5 = 0x7fff;
      if ((param_1 & 0xfffffffd) != 0) goto _L0;
      iVar4 = simple_measurement_srv_get_attr_desc(param_2,0x403,1);
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
        if (param_1 == 2) goto _L0;
_L0:
        iVar4 = simple_measurement_srv_get_attr_desc(param_2,0x403,2);
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

