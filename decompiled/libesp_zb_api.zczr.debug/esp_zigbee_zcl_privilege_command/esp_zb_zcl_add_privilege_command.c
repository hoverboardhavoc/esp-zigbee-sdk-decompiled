/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_privilege_command.o -> esp_zb_zcl_add_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_zcl_add_privilege_command(undefined1 param_1,undefined2 param_2,undefined2 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  piVar1 = (int *)zcl_privilege_command_list_find();
  if (*piVar1 == 0) {
    puVar3 = (undefined1 *)malloc(0xc);
    if (puVar3 == (undefined1 *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_PRIVILEGE_COMMAND",&_LC2,uVar2,
                    "ESP_ZIGBEE_ZCL_PRIVILEGE_COMMAND","esp_zb_zcl_add_privilege_command",0x6c);
      uVar2 = 0xffffffff;
    }
    else {
      *puVar3 = param_1;
      *(undefined2 *)(puVar3 + 2) = param_2;
      *(undefined2 *)(puVar3 + 4) = param_3;
      *(undefined1 **)(puVar3 + 8) = s_zcl_privilege_cluster_list;
      s_zcl_privilege_cluster_list = puVar3;
      zb_zcl_privilege_command_handler_register(zb_zcl_privilege_command_handler);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

