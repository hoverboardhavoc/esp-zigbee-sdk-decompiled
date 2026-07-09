/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_lru_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_lru_add(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = lru_queue_is_present();
  if (iVar2 == 0) {
    uVar1 = (undefined2)param_2;
    if ((uint)*(ushort *)(param_1 + 10) < (uint)*(ushort *)(param_1 + 8)) {
      lru_queue_insert(param_1,*(undefined2 *)
                                ((uint)*(ushort *)(param_1 + 10) * 0x12 + *(int *)(param_1 + 4) + 10
                                ),param_2);
    }
    else {
      *(undefined2 *)(*(int *)(param_1 + 4) + param_2 * 0x12 + 10) = uVar1;
      *(undefined2 *)(param_2 * 0x12 + *(int *)(param_1 + 4) + 0xc) = uVar1;
    }
    *(undefined2 *)(param_1 + 10) = uVar1;
  }
  return;
}

