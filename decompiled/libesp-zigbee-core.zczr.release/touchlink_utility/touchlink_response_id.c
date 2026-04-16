/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_response_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t touchlink_response_id(_Bool is_new)

{
  undefined3 in_register_00002029;
  int iVar1;
  uint32_t uVar2;
  
  if (CONCAT31(in_register_00002029,is_new) != 0) {
    iVar1 = touchlink_transaction_get();
    uVar2 = touchlink_assign_response_id();
    *(uint32_t *)(iVar1 + 4) = uVar2;
  }
  iVar1 = touchlink_transaction_get();
  return *(uint32_t *)(iVar1 + 4);
}

