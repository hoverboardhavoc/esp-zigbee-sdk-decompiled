/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> carbon_dioxide_measurement_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool carbon_dioxide_measurement_cluster_srv_check_value_handler
               (uint param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 auStack_24 [3];
  
  if (3 < param_1) {
    return false;
  }
  uVar3 = *param_3;
  uVar4 = 0;
  if ((param_1 & 0xfffffffd) != 0) goto _L0;
  iVar2 = simple_measurement_srv_get_attr_desc(param_2,0x40d,1);
  if (iVar2 != 0) goto _L0;
  while( true ) {
    do {
      iVar2 = __assert_func(0,0,0,0);
_L0:
    } while (*(void **)(iVar2 + 8) == (void *)0x0);
    memcpy(auStack_24,*(void **)(iVar2 + 8),4);
    uVar4 = auStack_24[0];
_L0:
    if (1 < param_1) break;
    iVar2 = simple_measurement_srv_get_attr_desc(param_2,0x40d,2);
    if ((iVar2 != 0) && (*(void **)(iVar2 + 8) != (void *)0x0)) {
      memcpy(auStack_24,*(void **)(iVar2 + 8),4);
_L0:
      iVar2 = __lesf2(uVar4,uVar3);
      if (iVar2 < 1) {
        iVar2 = __gesf2(auStack_24[0],uVar3);
        bVar1 = iVar2 < 0;
      }
      else {
        bVar1 = true;
      }
      return bVar1;
    }
  }
  auStack_24[0] = 0x3f800000;
  goto _L0;
}

