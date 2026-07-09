/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> group_remove_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int group_remove_endpoint(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = test_and_clr_bitmap(param_2,param_1 + 2);
  if (iVar1 != 0) {
    uVar2 = bitmap_find_first_bit(param_1 + 2,0xff);
    if (uVar2 < 0xff) {
      aps_group_table_store_group(param_1);
    }
    else {
      aps_group_table_remove_stored_group(param_1);
      iVar3 = core_globals_get();
      uVar2 = *(uint *)(iVar3 + 0x95c);
      iVar3 = core_globals_get();
      uVar4 = *(undefined4 *)(iVar3 + 0x960);
      iVar3 = core_globals_get();
      if (param_1 < uVar2) {
        mempool_free_ent_part_0(*(undefined2 *)(iVar3 + 0x964));
      }
      mempool_free_idx(uVar4,(int)(param_1 - uVar2) / 0x22 & 0xffff);
    }
  }
  return iVar1;
}

