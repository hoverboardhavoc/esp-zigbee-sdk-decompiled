/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee.release -> aps_compat.o -> esp_zb_apsde_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

_Bool esp_zb_apsde_data_indication_handler(ezb_apsde_data_ind_t *ind)

{
  esp_zb_apsde_data_indication_callback_t p_Var1;
  _Bool _Var2;
  void *__src;
  undefined1 auStack_50 [56];
  
  __src = (void *)__assert_func(0,0,0,0);
  p_Var1 = s_esp_zb_data_ind_handler;
  if (s_esp_zb_data_ind_handler == (esp_zb_apsde_data_indication_callback_t)0x0) {
    __src = (void *)__assert_func(0,0,0,0);
  }
  if (__src == (void *)0x0) {
    esp_zb_apsde_data_indication_handler((ezb_apsde_data_ind_t *)0x0);
  }
  memcpy(auStack_50,__src,0x28);
  _Var2 = (*p_Var1)(eRam00000010);
  return _Var2;
}

