/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_compat.o -> esp_zb_app_signal_handler_adapter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 esp_zb_app_signal_handler_adapter(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uStack_18;
  int iStack_14;
  
  uStack_18 = param_1;
  iVar1 = ezb_app_signal_get_type();
  iStack_14 = 0;
  if (iVar1 - 0x100U < 8) {
    pcVar2 = (char *)ezb_app_signal_get_params(param_1);
    iStack_14 = -(uint)(*pcVar2 != '\0');
  }
  esp_zb_app_signal_handler(&uStack_18);
  return s_signal_processed;
}

