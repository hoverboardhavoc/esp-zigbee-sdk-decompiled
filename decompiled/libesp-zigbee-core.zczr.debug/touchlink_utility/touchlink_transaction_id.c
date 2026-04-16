/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_transaction_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t touchlink_transaction_id(_Bool is_new)

{
  undefined3 in_register_00002029;
  uint32_t *puVar1;
  uint32_t uVar2;
  
  if (CONCAT31(in_register_00002029,is_new) != 0) {
    puVar1 = (uint32_t *)touchlink_transaction_get();
    uVar2 = touchlink_assign_transaction_id();
    *puVar1 = uVar2;
  }
  puVar1 = (uint32_t *)touchlink_transaction_get();
  return *puVar1;
}

