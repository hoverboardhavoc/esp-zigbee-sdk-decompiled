/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_assign_response_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t touchlink_assign_response_id(void)

{
  uint32_t uVar1;
  int iVar2;
  
  do {
    do {
      do {
        uVar1 = random_noncrypto_get_u32();
      } while (uVar1 == 0);
      iVar2 = touchlink_transaction_get();
    } while (*(uint32_t *)(iVar2 + 4) == uVar1);
    iVar2 = touchlink_transaction_get();
  } while ((*(int *)(iVar2 + 4) + 1U == uVar1) ||
          (iVar2 = touchlink_transaction_get(), *(int *)(iVar2 + 4) - 1U == uVar1));
  return uVar1;
}

