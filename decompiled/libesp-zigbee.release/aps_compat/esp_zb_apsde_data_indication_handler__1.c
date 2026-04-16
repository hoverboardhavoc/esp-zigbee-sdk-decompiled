/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> aps_compat.o -> esp_zb_apsde_data_indication_handler__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool esp_zb_apsde_data_indication_handler(ezb_apsde_data_ind_t *ind)

{
  esp_zb_apsde_data_indication_callback_t p_Var1;
  _Bool _Var2;
  undefined1 auStack_40 [56];
  
  p_Var1 = s_esp_zb_data_ind_handler;
  if (s_esp_zb_data_ind_handler == (esp_zb_apsde_data_indication_callback_t)0x0) {
    ind = (ezb_apsde_data_ind_t *)__assert_func(0,0,0,0);
  }
  if (ind == (ezb_apsde_data_ind_t *)0x0) {
    esp_zb_apsde_data_indication_handler((ezb_apsde_data_ind_t *)0x0);
  }
  memcpy(auStack_40,ind,0x24);
  _Var2 = (*p_Var1)(eRam00000010);
  return _Var2;
}

