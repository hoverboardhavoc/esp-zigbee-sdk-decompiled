/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_srv_send_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_srv_send_response(int param_1,undefined1 param_2)

{
  undefined1 auStack_11 [13];
  
  auStack_11[0] = param_2;
  if (*(char *)(param_1 + 0x1c) == '\x03') {
    auStack_11[0] = 0;
  }
  zb_zcl_send_cmd(param_1 + 0xb,2,*(undefined1 *)(param_1 + 0x16),1,*(undefined1 *)(param_1 + 0x17),
                  auStack_11,1);
  return;
}

