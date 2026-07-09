/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_delete(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = check_table_ref(param_2,*param_1,*(undefined2 *)(param_1 + 2));
  if (iVar1 != 0) {
    iVar1 = param_1[1] + param_2 * 0x12;
    if (*(char *)(iVar1 + 0x10) == '\0') {
      test_and_clr_bitmap(param_2,*param_1);
      addr_table_lru_remove(param_1,param_2);
      memset((void *)(param_1[1] + param_2 * 0x12),0,0x12);
    }
    else {
      *(byte *)(iVar1 + 0x11) = *(byte *)(iVar1 + 0x11) | 8;
    }
  }
  return;
}

