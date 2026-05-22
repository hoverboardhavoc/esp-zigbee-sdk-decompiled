/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                  ,0x34,"esp_zb_apsde_data_indication_handler",0x10000);
  }
  else if (ind != (ezb_apsde_data_ind_t *)0x0) {
    _Var1 = (*s_esp_zb_data_ind_handler)(eRam00000010);
    return _Var1;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                ,0x35,"esp_zb_apsde_data_indication_handler","ind != NULL");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

