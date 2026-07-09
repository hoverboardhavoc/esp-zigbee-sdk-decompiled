/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_disc_table_get_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_disc_table_get_entry(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = touchlink_transaction_get();
  iVar1 = 0;
  if (*(byte *)(iVar2 + 8) < 8) {
    iVar1 = touchlink_transaction_get();
    iVar2 = touchlink_transaction_get();
    iVar1 = iVar1 + (uint)*(byte *)(iVar2 + 8) * 0xc0 + 0xc;
    iVar2 = touchlink_transaction_get();
    *(char *)(iVar2 + 8) = *(char *)(iVar2 + 8) + '\x01';
  }
  return iVar1;
}

