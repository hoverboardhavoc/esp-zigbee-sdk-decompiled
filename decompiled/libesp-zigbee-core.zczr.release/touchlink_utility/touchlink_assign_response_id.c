/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_assign_response_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_assign_response_id(void)

{
  int iVar1;
  int iVar2;
  
  do {
    do {
      do {
        iVar1 = random_noncrypto_get_u32();
      } while (iVar1 == 0);
      iVar2 = touchlink_transaction_get();
    } while (*(int *)(iVar2 + 4) == iVar1);
    iVar2 = touchlink_transaction_get();
  } while ((*(int *)(iVar2 + 4) + 1 == iVar1) ||
          (iVar2 = touchlink_transaction_get(), *(int *)(iVar2 + 4) + -1 == iVar1));
  return iVar1;
}

