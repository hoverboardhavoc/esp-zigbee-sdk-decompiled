/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_validate_pan_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_validate_pan_id(uint param_1)

{
  int iVar1;
  ushort auStack_12 [3];
  
  iVar1 = 0;
  while (iVar1 = nwk_disc_table_next(iVar1), iVar1 != 0) {
    nwk_address_get_panid(*(undefined1 *)(iVar1 + 8),auStack_12);
    if (((auStack_12[0] == param_1) || (param_1 == 0xffff)) || (param_1 == 0)) {
      param_1 = random_noncrypto_get_u32();
      param_1 = param_1 & 0xffff;
      iVar1 = 0;
    }
  }
  return param_1;
}

