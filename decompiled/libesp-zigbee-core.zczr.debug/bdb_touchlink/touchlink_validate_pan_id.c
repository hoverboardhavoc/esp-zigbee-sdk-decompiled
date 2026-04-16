/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_validate_pan_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_panid_t touchlink_validate_pan_id(ezb_panid_t pan_id)

{
  int iVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  ushort auStack_12 [2];
  ezb_panid_t parent_pan_id;
  
  uVar2 = CONCAT22(in_register_0000202a,pan_id);
  iVar1 = 0;
  while (iVar1 = nwk_disc_table_next(iVar1), iVar1 != 0) {
    nwk_address_get_panid(*(undefined1 *)(iVar1 + 8),auStack_12);
    if (((auStack_12[0] == uVar2) || (uVar2 == 0xffff)) || (uVar2 == 0)) {
      uVar2 = random_noncrypto_get_u32();
      uVar2 = uVar2 & 0xffff;
      iVar1 = 0;
    }
  }
  return (ezb_panid_t)uVar2;
}

