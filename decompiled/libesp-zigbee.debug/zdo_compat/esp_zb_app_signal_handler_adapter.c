/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_compat.o -> esp_zb_app_signal_handler_adapter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 esp_zb_app_signal_handler_adapter(undefined4 param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_18 = param_1;
  iVar1 = ezb_app_signal_get_type();
  if (iVar1 - 0x100U < 8) {
    pbVar2 = (byte *)ezb_app_signal_get_params(param_1);
    uStack_14 = (uint)*pbVar2;
    if (uStack_14 != 0) {
      uStack_14 = 0xffffffff;
    }
  }
  else {
    uStack_14 = 0;
  }
  esp_zb_app_signal_handler(&uStack_18);
  return s_signal_processed;
}

