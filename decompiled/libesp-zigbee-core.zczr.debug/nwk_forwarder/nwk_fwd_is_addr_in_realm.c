/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_is_addr_in_realm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_fwd_is_addr_in_realm(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = nwk_get_short_address();
  if (iVar1 == param_1) {
    uVar2 = 1;
  }
  else {
    iVar1 = nwk_neighbor_table_get_by_short(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if ((*(uint *)(iVar1 + 0xc) & 0x3c0) == 0x40) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

