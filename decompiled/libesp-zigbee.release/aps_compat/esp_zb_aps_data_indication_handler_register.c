/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> aps_compat.o -> esp_zb_aps_data_indication_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_aps_data_indication_handler_register(code *param_1)

{
  code *pcVar1;
  
  pcVar1 = param_1;
  if (param_1 != (code *)0x0) {
    pcVar1 = esp_zb_apsde_data_indication_handler;
  }
  ezb_apsde_data_indication_handler_register(pcVar1);
  s_esp_zb_data_ind_handler = param_1;
  return;
}

