/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> invalidate_row_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void invalidate_row_cb(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  
  puVar1 = &m_ping_request_table + param_1 * 0x20;
  uVar2 = get_request_duration(puVar1);
  if (*(code **)(&DAT_00011088 + param_1 * 0x20) != (code *)0x0) {
    (**(code **)(&DAT_00011088 + param_1 * 0x20))(1,uVar2,extraout_a1,puVar1);
  }
  zb_ping_release_request(puVar1);
  return;
}

