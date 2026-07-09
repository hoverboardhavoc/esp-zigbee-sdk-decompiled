/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> ds_zcl_scene_info_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ds_zcl_scene_info_read(short *param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    mm_free();
    param_1[4] = 0;
    param_1[5] = 0;
  }
  *param_1 = 0;
  iVar1 = ds_internal_read(0xb,param_1[1],0,param_1);
  if (iVar1 == 0) {
    iVar1 = mm_alloc(1,*param_1);
    *(int *)(param_1 + 4) = iVar1;
    if ((*param_1 == 0) || (iVar1 == 0)) {
      *(undefined1 *)(param_1 + 2) = 1;
    }
    else {
      ds_internal_read(0xb,param_1[1],iVar1,param_1);
    }
  }
  else {
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}

