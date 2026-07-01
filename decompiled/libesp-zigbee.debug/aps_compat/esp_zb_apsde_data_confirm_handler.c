/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee.debug -> aps_compat.o -> esp_zb_apsde_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_apsde_data_confirm_handler(ezb_apsde_data_confirm_t *confirm)

{
  esp_zb_apsde_data_indication_callback_t p_Var1;
  
  if (s_esp_zb_data_confirm_handler == (esp_zb_apsde_data_confirm_callback_t)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                  ,0x3b,"esp_zb_apsde_data_confirm_handler","s_esp_zb_data_confirm_handler != NULL")
    ;
  }
  else if (confirm != (ezb_apsde_data_confirm_t *)0x0) {
    (*s_esp_zb_data_confirm_handler)(eRam00000010);
    return;
  }
  p_Var1 = (esp_zb_apsde_data_indication_callback_t)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                         ,0x3c,"esp_zb_apsde_data_confirm_handler","confirm != NULL");
  if (p_Var1 == (esp_zb_apsde_data_indication_callback_t)0x0) {
    ezb_apsde_data_indication_handler_register(0);
  }
  else {
    ezb_apsde_data_indication_handler_register(esp_zb_apsde_data_indication_handler);
  }
  s_esp_zb_data_ind_handler = p_Var1;
  return;
}

