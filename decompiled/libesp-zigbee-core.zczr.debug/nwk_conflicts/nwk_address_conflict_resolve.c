/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_address_conflict_resolve
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_conflict_resolve(ezb_shortaddr_t offending_addr)

{
  ezb_shortaddr_t new_addr;
  undefined2 in_register_0000202a;
  int iVar1;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    iVar1 = nwk_get_short_address();
    if (iVar1 == CONCAT22(in_register_0000202a,offending_addr)) {
      iVar1 = nwk_is_device_zc();
      if (iVar1 == 0) {
        new_addr = nwk_assign_shortaddr();
        nwk_change_network_address(new_addr);
      }
    }
    else {
      nwk_change_child_address(offending_addr);
    }
  }
  return;
}

