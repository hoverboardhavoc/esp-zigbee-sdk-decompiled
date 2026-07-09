/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mempool_free_ent(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_a1;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 <= param_5) {
    iVar1 = mempool_free_idx(param_2,param_4,(int)(param_5 - param_1) / param_3 & 0xffff);
    return iVar1;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x69,
                        "mempool_free_ent","blk_base <= obj");
  iVar2 = test_and_clr_bitmap(extraout_a1,iVar1 + 2);
  if (iVar2 != 0) {
    iVar3 = group_is_empty(iVar1);
    if (iVar3 == 0) {
      aps_group_table_store_group(iVar1);
    }
    else {
      aps_group_table_remove_stored_group(iVar1);
      iVar3 = core_globals_get();
      uVar4 = *(undefined4 *)(iVar3 + 0x95c);
      iVar3 = core_globals_get();
      uVar5 = *(undefined4 *)(iVar3 + 0x960);
      iVar3 = core_globals_get();
      mempool_free_ent(uVar4,uVar5,0x22,*(undefined2 *)(iVar3 + 0x964),iVar1);
    }
  }
  return iVar2;
}

