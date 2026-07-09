/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_lru_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_lru_remove(int param_1,uint param_2)

{
  if (*(ushort *)(param_1 + 10) == param_2) {
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_2 * 0x12 + *(int *)(param_1 + 4) + 0xc);
  }
  lru_queue_remove(param_1,param_2);
  if (*(ushort *)(param_1 + 10) == param_2) {
    *(undefined2 *)(param_1 + 10) = 0xffff;
  }
  return;
}

