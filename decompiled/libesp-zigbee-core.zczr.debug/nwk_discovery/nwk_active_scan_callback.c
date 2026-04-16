/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_active_scan_callback(active_scan_result_t *scan_result,void *user_ctx)

{
  int iVar1;
  
  if (scan_result == (active_scan_result_t *)0x0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac0) = 0;
    nwk_network_discovery_confirm(0);
  }
  else {
    nwk_handle_active_scan_result(scan_result,user_ctx);
  }
  return;
}

