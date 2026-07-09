/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> aps_compat.o -> esp_zb_apsde_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_apsde_data_confirm_handler(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (s_esp_zb_data_confirm_handler == (code *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                  ,0x3b,"esp_zb_apsde_data_confirm_handler","s_esp_zb_data_confirm_handler != NULL")
    ;
  }
  else if (param_1 != (undefined4 *)0x0) {
    local_30 = *param_1;
    uStack_2c = param_1[1];
    uStack_28 = param_1[2];
    uStack_24 = param_1[3];
    uStack_20 = param_1[4];
    uStack_1c = param_1[5];
    (*s_esp_zb_data_confirm_handler)(&local_30);
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                        ,0x3c,"esp_zb_apsde_data_confirm_handler","confirm != NULL");
  if (iVar1 == 0) {
    ezb_apsde_data_indication_handler_register(0);
  }
  else {
    ezb_apsde_data_indication_handler_register(esp_zb_apsde_data_indication_handler);
  }
  s_esp_zb_data_ind_handler = iVar1;
  return;
}

