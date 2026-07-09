/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> do_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void do_lock_ref(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = check_table_ref(param_2,*param_1,*(undefined2 *)(param_1 + 2));
  if (iVar1 != 0) {
    iVar1 = param_1[1] + param_2 * 0x12;
    uVar2 = (uint)*(byte *)(iVar1 + 0x10);
    if (uVar2 == 0xff) {
      __assert_func(0,0,0,0);
    }
    if (uVar2 == 0) {
      addr_table_lru_remove(param_1,param_2);
    }
    *(char *)(iVar1 + 0x10) = *(char *)(iVar1 + 0x10) + '\x01';
  }
  return;
}

