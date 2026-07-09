/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_initiator_associate_target
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_initiator_associate_target(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = aps_secur_is_centralized();
  if (iVar1 == 0) {
    iVar1 = touchlink_initiator_start_association();
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    iVar1 = 6;
  }
  if (iVar1 == 3) {
    uVar2 = 2;
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}

