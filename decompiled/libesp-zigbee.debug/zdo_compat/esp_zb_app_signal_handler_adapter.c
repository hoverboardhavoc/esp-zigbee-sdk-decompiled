/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_compat.o -> esp_zb_app_signal_handler_adapter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool esp_zb_app_signal_handler_adapter(ezb_app_signal_t *signal_src)

{
  int iVar1;
  byte *pbVar2;
  undefined1 auStack_18 [4];
  esp_zb_app_signal_t signal_dst;
  
  auStack_18 = (undefined1  [4])signal_src;
  iVar1 = ezb_app_signal_get_type();
  if (iVar1 - 0x100U < 8) {
    pbVar2 = (byte *)ezb_app_signal_get_params(signal_src);
    signal_dst.p_app_signal = (uint32_t *)(uint)*pbVar2;
    if (signal_dst.p_app_signal != (uint32_t *)0x0) {
      signal_dst.p_app_signal = (uint32_t *)0xffffffff;
    }
  }
  else {
    signal_dst.p_app_signal = (uint32_t *)0x0;
  }
  esp_zb_app_signal_handler((esp_zb_app_signal_t *)auStack_18);
  return s_signal_processed;
}

