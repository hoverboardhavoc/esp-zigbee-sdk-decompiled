/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> lru_queue_is_present
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lru_queue_is_present(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + param_2 * 0x12;
  if (*(short *)(iVar1 + 10) == -1) {
    return 0;
  }
  if (*(short *)(iVar1 + 0xc) != -1) {
    return 1;
  }
  return 0;
}

