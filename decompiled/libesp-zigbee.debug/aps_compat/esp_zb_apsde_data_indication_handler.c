/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> aps_compat.o -> esp_zb_apsde_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

_Bool esp_zb_apsde_data_indication_handler(ezb_apsde_data_ind_t *ind)

{
  _Bool _Var1;
  
  if (s_esp_zb_data_ind_handler == (esp_zb_apsde_data_indication_callback_t)0x0) {
    __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c",0x34,
                  "esp_zb_apsde_data_indication_handler",0x10000);
  }
  else if (ind != (ezb_apsde_data_ind_t *)0x0) {
    _Var1 = (*s_esp_zb_data_ind_handler)(eRam00000010);
    return _Var1;
  }
  __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c",0x35,
                "esp_zb_apsde_data_indication_handler","ind != NULL");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

