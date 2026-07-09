/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_get_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_ias_ace_zone_table_get_zone(int param_1,int param_2,void *param_3)

{
  void *__src;
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 2;
  }
  else if (param_3 == (void *)0x0) {
    uVar1 = 2;
  }
  else if (param_2 == 0xff) {
    uVar1 = 2;
  }
  else {
    __src = (void *)ias_ace_zone_table_get_zone();
    if (__src == (void *)0x0) {
      uVar1 = 5;
    }
    else {
      memcpy(param_3,__src,0x1e);
      uVar1 = 0;
    }
  }
  return uVar1;
}

