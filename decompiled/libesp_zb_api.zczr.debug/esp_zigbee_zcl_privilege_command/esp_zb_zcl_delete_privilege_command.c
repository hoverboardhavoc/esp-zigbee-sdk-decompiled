/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_privilege_command.o -> esp_zb_zcl_delete_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_delete_privilege_command(void)

{
  undefined4 *puVar1;
  void *__ptr;
  undefined4 uVar2;
  
  if (s_zcl_privilege_cluster_list == 0) {
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)zcl_privilege_command_list_find();
    __ptr = (void *)*puVar1;
    if (__ptr != (void *)0x0) {
      *puVar1 = *(undefined4 *)((int)__ptr + 8);
      free(__ptr);
    }
    if (s_zcl_privilege_cluster_list == 0) {
      zb_zcl_privilege_command_handler_clear();
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

