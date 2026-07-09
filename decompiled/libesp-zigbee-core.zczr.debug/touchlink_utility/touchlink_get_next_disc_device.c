/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_next_disc_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_get_next_disc_device(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 == 0) && (iVar2 = touchlink_transaction_get(), *(char *)(iVar2 + 8) != '\0')) {
    iVar2 = touchlink_transaction_get();
    return iVar2 + 0xc;
  }
  uVar1 = 0;
  while( true ) {
    iVar2 = touchlink_transaction_get();
    if (*(byte *)(iVar2 + 8) <= uVar1) {
      return 0;
    }
    iVar2 = touchlink_transaction_get();
    if (uVar1 * 0xc0 + iVar2 + 0xc == param_1) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = touchlink_transaction_get();
  if (uVar1 + 1 == (uint)*(byte *)(iVar2 + 8)) {
    return 0;
  }
  iVar2 = touchlink_transaction_get();
  return iVar2 + (uVar1 + 1) * 0xc0 + 0xc;
}

