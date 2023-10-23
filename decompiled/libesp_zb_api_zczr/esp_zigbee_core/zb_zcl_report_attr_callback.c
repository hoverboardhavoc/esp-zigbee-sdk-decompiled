/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_report_attr_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_report_attr_callback
               (undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  
  if (zb_core_action_cb != (code *)0x0) {
    local_30 = 0;
    uStack_2c = *param_1;
    uStack_2b = param_1[1];
    uStack_2a = param_1[2];
    uStack_29 = param_1[3];
    uStack_28 = param_1[4];
    uStack_27 = param_1[5];
    uStack_26 = param_1[6];
    uStack_25 = param_1[7];
    uStack_24 = param_1[8];
    uStack_23 = param_2;
    uStack_22 = param_3;
    uStack_20 = param_4;
    uStack_1e = param_5;
    uStack_1c = param_6;
    uStack_18 = zb_zcl_get_attribute_size(param_7);
    uStack_17 = (undefined1)param_7;
    uStack_16 = (undefined1)((uint)param_7 >> 8);
    uStack_15 = (undefined1)((uint)param_7 >> 0x10);
    uStack_14 = (undefined1)((uint)param_7 >> 0x18);
    (*zb_core_action_cb)(0x2000,&local_30,zb_core_action_cb);
  }
  return;
}

