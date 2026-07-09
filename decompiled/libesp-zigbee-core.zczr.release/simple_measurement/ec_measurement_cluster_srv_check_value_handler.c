/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> ec_measurement_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ec_measurement_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  
  if (3 < param_1) {
    return false;
  }
  uVar1 = *param_3;
  if (uVar1 == 0xffff) {
    bVar3 = false;
  }
  else {
    if (param_1 == 3) {
      uVar6 = 0;
      uVar5 = 100;
    }
    else {
      uVar6 = 0;
      if ((param_1 & 0xfffffffd) != 0) goto _L0;
      iVar4 = simple_measurement_srv_get_attr_desc(param_2,0x40a,1);
      if (iVar4 != 0) goto _L0;
      do {
        do {
          iVar4 = __assert_func(0,0,0,0);
_L0:
        } while (*(ushort **)(iVar4 + 8) == (ushort *)0x0);
        uVar5 = **(ushort **)(iVar4 + 8);
        if (uVar5 != 0xffff) {
          uVar6 = uVar5;
        }
        uVar5 = 0xfffe;
        if (param_1 == 2) goto _L0;
_L0:
        iVar4 = simple_measurement_srv_get_attr_desc(param_2,0x40a,2);
      } while ((iVar4 == 0) || (*(ushort **)(iVar4 + 8) == (ushort *)0x0));
      uVar2 = **(ushort **)(iVar4 + 8);
      uVar5 = 0xfffe;
      if (uVar2 != 0xffff) {
        uVar5 = uVar2;
      }
    }
_L0:
    bVar3 = uVar1 < uVar6 || uVar5 < uVar1;
  }
  return bVar3;
}

