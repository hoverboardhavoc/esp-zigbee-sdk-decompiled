/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mac_pal_deinit(void)

{
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = ezb_plat_radio_is_enabled();
  if ((iVar1 != 0) && (eVar2 = mac_pal_disable(), eVar2 != 0)) {
    __assert_func(0,0,0,0);
  }
  s_mac_pal_ctx.state = '\0';
  s_mac_pal_ctx.csma_nb = '\0';
  s_mac_pal_ctx.tx_retries = '\0';
  s_mac_pal_ctx._3_1_ = 0;
  return;
}

