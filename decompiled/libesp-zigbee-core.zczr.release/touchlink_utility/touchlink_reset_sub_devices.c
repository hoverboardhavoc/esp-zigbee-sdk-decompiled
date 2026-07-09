/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_reset_sub_devices
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_reset_sub_devices(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = touchlink_transaction_get();
    if (*(byte *)(iVar2 + 8) <= uVar1) break;
    iVar2 = touchlink_transaction_get();
    iVar3 = uVar1 * 0xc0;
    uVar1 = uVar1 + 1 & 0xff;
    *(undefined1 *)(iVar2 + iVar3 + 0x34) = 0;
  }
  return;
}

