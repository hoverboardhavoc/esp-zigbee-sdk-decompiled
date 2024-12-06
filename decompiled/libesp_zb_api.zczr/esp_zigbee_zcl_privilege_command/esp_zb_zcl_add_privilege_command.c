/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_privilege_command.o -> esp_zb_zcl_add_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_zcl_add_privilege_command(undefined1 param_1,undefined2 param_2,undefined2 param_3)

{
  int *piVar1;
  undefined1 *puVar2;
  
  piVar1 = (int *)zcl_privilege_command_list_find();
  if (*piVar1 == 0) {
    puVar2 = (undefined1 *)malloc(0xc);
    if (puVar2 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    *puVar2 = param_1;
    *(undefined2 *)(puVar2 + 2) = param_2;
    *(undefined2 *)(puVar2 + 4) = param_3;
    *(undefined1 **)(puVar2 + 8) = s_zcl_privilege_cluster_list;
    s_zcl_privilege_cluster_list = puVar2;
    zb_zcl_privilege_command_handler_register(zb_zcl_privilege_command_handler);
  }
  return 0;
}

