/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_is_addr_in_realm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_fwd_is_addr_in_realm(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = nwk_get_short_address();
  if (iVar2 == param_1) {
    bVar1 = true;
  }
  else {
    iVar2 = nwk_neighbor_table_get_by_short(param_1);
    bVar1 = false;
    if (iVar2 != 0) {
      bVar1 = (*(uint *)(iVar2 + 0xc) & 0x3c0) == 0x40;
    }
  }
  return bVar1;
}

