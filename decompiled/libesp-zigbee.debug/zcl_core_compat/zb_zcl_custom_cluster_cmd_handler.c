/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> zb_zcl_custom_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zb_zcl_custom_cluster_cmd_handler(undefined4 *param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined2 uStack_60;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (s_core_action == (code *)0x0) {
    uVar1 = 0x81;
  }
  else {
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    convert_to_esp_zb_zcl_cmd_info(&uStack_48,param_1);
    uStack_28 = CONCAT22(uStack_28._2_2_,param_3);
    uStack_24 = param_2;
    (*s_core_action)(0x61,&uStack_48,s_core_action);
    uVar1 = esp_err_to_zcl_status();
    if ((*(byte *)((int)param_1 + 0x1a) & 0x10) == 0) {
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_68 = *param_1;
      uStack_64 = param_1[1];
      _uStack_60 = CONCAT13(*(undefined1 *)((int)param_1 + 0x15),
                            CONCAT12(*(undefined1 *)(param_1 + 5),*(undefined2 *)(param_1 + 2)));
      _uStack_5c = CONCAT22(*(undefined2 *)(param_1 + 7),*(undefined2 *)((int)param_1 + 0x16));
      uStack_58 = (*(byte *)((int)param_1 + 0x1a) >> 3 & 1 ^ 1) << 1 |
                  *(byte *)((int)param_1 + 0x1a) >> 2 & 1 | 4;
      ezb_zcl_default_rsp_cmd_req(&uStack_68);
    }
  }
  return uVar1;
}

