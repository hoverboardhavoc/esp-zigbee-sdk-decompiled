/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_factory_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_factory_reset(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = zb_zcl_get_ctx();
  if (*(int *)(iVar1 + 4) != 0) {
    iVar1 = 0;
    while( true ) {
      iVar2 = zb_zcl_get_ctx();
      if ((int)(uint)**(byte **)(iVar2 + 4) <= iVar1) break;
      iVar2 = zb_zcl_get_ctx();
      if (*(int *)(*(int *)(*(int *)(iVar2 + 4) + 1) + iVar1 * 4) != 0) {
        iVar2 = zb_zcl_get_ctx();
        zcl_clusters_attr_factory_reset
                  (*(undefined4 *)(*(int *)(*(int *)(iVar2 + 4) + 1) + iVar1 * 4));
      }
      iVar1 = iVar1 + 1;
    }
  }
  zb_bdb_reset_via_local_action(0);
  zb_nvram_erase();
  DAT_000161ad = DAT_000161ad | 8;
  iVar1 = esp_restart();
  if (iVar1 == 0) {
    esp_zb_start_no_autostart();
  }
  else {
    esp_zb_start_autostart();
  }
  return;
}

