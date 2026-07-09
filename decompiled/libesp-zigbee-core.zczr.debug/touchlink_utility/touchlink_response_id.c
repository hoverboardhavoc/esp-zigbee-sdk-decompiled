/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_response_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_response_id(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    iVar1 = touchlink_transaction_get();
    uVar2 = touchlink_assign_response_id();
    *(undefined4 *)(iVar1 + 4) = uVar2;
  }
  iVar1 = touchlink_transaction_get();
  return *(undefined4 *)(iVar1 + 4);
}

