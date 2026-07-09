/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_address_conflict_resolve
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_conflict_resolve(int param_1)

{
  int iVar1;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    iVar1 = nwk_get_short_address();
    if (iVar1 == param_1) {
      iVar1 = nwk_is_device_zc();
      if (iVar1 == 0) {
        nwk_assign_shortaddr();
        nwk_change_network_address();
      }
    }
    else {
      nwk_change_child_address(param_1);
    }
  }
  return;
}

