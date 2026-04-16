/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> aps_compat.o -> esp_zb_apsde_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_apsde_data_confirm_handler(ezb_apsde_data_confirm_t *confirm)

{
  esp_zb_apsde_data_confirm_callback_t p_Var1;
  undefined1 auStack_30 [40];
  
  p_Var1 = s_esp_zb_data_confirm_handler;
  if (s_esp_zb_data_confirm_handler == (esp_zb_apsde_data_confirm_callback_t)0x0) {
    confirm = (ezb_apsde_data_confirm_t *)__assert_func(0,0,0,0);
  }
  if (confirm == (ezb_apsde_data_confirm_t *)0x0) {
    esp_zb_apsde_data_indication_handler((ezb_apsde_data_ind_t *)0x0);
  }
  memcpy(auStack_30,confirm,0x18);
  (*p_Var1)(eRam00000010);
  return;
}

