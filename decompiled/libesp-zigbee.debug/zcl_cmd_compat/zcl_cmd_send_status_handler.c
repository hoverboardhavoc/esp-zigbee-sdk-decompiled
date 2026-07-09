/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zcl_cmd_send_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cmd_send_status_handler(byte *param_1)

{
  uint local_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (s_cmd_send_status_cb != (code *)0x0) {
    uStack_24 = (uint)*param_1;
    uStack_20 = (uint)CONCAT12(param_1[0xc],CONCAT11(param_1[0xd],param_1[1]));
    convert_ezb_address_to_esp_zb_zcl_addr(&uStack_1c,param_1 + 2);
    local_50 = uStack_24;
    uStack_4c = uStack_20;
    uStack_48 = uStack_1c;
    uStack_44 = uStack_18;
    uStack_40 = uStack_14;
    (*s_cmd_send_status_cb)(&local_50,s_cmd_send_status_cb);
  }
  return;
}

