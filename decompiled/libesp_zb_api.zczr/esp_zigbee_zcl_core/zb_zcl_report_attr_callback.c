/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_core.o -> zb_zcl_report_attr_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_report_attr_callback
               (void *param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_40;
  undefined1 auStack_3c [9];
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  
  if (zb_core_action_cb != (code *)0x0) {
    local_40 = 0;
    memcpy(auStack_3c,param_1,9);
    uStack_33 = param_2;
    uStack_32 = param_3;
    uStack_30 = param_4;
    uStack_2e = param_5;
    uStack_2c = param_6;
    uStack_28 = esp_zb_zcl_get_attribute_size(param_6,param_7);
    uStack_26 = (undefined2)param_7;
    uStack_24 = (undefined2)((uint)param_7 >> 0x10);
    (*zb_core_action_cb)(0x2000,&local_40,zb_core_action_cb);
  }
  return;
}

