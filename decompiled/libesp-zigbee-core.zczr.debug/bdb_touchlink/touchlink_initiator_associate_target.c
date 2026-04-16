/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_initiator_associate_target
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

bdb_comm_status_t touchlink_initiator_associate_target(void)

{
  bdb_comm_status_t bVar1;
  int iVar2;
  
  iVar2 = aps_secur_is_centralized();
  if (iVar2 == 0) {
    iVar2 = touchlink_initiator_start_association();
    if (iVar2 == 0) {
      return '\x01';
    }
  }
  else {
    iVar2 = 6;
  }
  if (iVar2 == 3) {
    bVar1 = '\x02';
  }
  else {
    bVar1 = '\t';
  }
  return bVar1;
}

