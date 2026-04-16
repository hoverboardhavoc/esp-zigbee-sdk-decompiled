/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_nlme_ed_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nwk_scan_result */
/* WARNING: Unknown calling convention */

void nwk_nlme_ed_scan_callback(ed_scan_result_t *scan_result,void *user_ctx)

{
  int iVar1;
  int iVar2;
  uint8_t uStack_14;
  uint8_t uStack_13;
  int8_t iStack_12;
  nwk_ed_scan_result_t nwk_scan_result;
  
  iVar1 = core_globals_get();
  if (*(code **)(iVar1 + 0xad0) != (code *)0x0) {
    if (scan_result == (ed_scan_result_t *)0x0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xac0) = 0;
      (**(code **)(iVar1 + 0xad0))(0,user_ctx,*(code **)(iVar1 + 0xad0));
    }
    else {
      uStack_14 = scan_result->channel_page;
      uStack_13 = scan_result->channel_number;
      iStack_12 = scan_result->max_rssi;
      (**(code **)(iVar1 + 0xad0))(&uStack_14,user_ctx);
    }
  }
  return;
}

