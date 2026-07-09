/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_active_scan_callback(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac0) = 0;
    nwk_network_discovery_confirm(0);
  }
  else {
    nwk_handle_active_scan_result();
  }
  return;
}

