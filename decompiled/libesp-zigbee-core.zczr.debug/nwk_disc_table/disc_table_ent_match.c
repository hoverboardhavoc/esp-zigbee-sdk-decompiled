/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_ent_match
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 disc_table_ent_match(void *param_1,uint param_2,uint param_3,void *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(byte *)((int)param_1 + 8) == param_2) {
    if ((*(uint *)((int)param_1 + 0x10) >> 0x1d & 1) == param_3) {
      iVar1 = memcmp(param_1,param_4,8);
      if (iVar1 == 0) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

