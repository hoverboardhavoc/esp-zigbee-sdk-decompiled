/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_find_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_zb_zcl_find_reporting_info(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           ezb_zcl_reporting_info_find
                     (*param_1,*(undefined2 *)(param_1 + 2),param_1[4],*(undefined2 *)(param_1 + 8),
                      *(undefined2 *)(param_1 + 6));
  if (puVar1 != (undefined1 *)0x0) {
    convert_to_esp_zb_zcl_reporting_info(s_esp_zb_find_reporting_info_out_4,puVar1);
    puVar1 = s_esp_zb_find_reporting_info_out_4;
  }
  return puVar1;
}

