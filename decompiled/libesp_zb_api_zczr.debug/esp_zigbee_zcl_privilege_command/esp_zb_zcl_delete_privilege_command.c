/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_privilege_command.o -> esp_zb_zcl_delete_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_delete_privilege_command(void)

{
  undefined4 *puVar1;
  void *__ptr;
  
  if (s_zcl_privilege_cluster_list == 0) {
    return 0;
  }
  puVar1 = (undefined4 *)zcl_privilege_command_list_find();
  __ptr = (void *)*puVar1;
  if (__ptr != (void *)0x0) {
    *puVar1 = *(undefined4 *)((int)__ptr + 8);
    free(__ptr);
  }
  if (s_zcl_privilege_cluster_list == 0) {
    zb_zcl_privilege_command_handler_clear();
  }
  return 1;
}

