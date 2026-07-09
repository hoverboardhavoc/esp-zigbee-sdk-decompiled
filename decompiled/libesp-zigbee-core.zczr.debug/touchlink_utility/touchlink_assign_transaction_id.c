/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_assign_transaction_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_assign_transaction_id(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  do {
    if (iVar1 != 0) {
      piVar2 = (int *)touchlink_transaction_get();
      if ((*piVar2 + 1 != iVar1) &&
         (piVar2 = (int *)touchlink_transaction_get(), *piVar2 + -1 != iVar1)) {
        return iVar1;
      }
    }
    iVar1 = random_noncrypto_get_u32();
  } while( true );
}

