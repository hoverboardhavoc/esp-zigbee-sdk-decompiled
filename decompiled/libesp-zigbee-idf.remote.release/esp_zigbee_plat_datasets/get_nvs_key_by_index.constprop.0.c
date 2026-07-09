/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> get_nvs_key_by_index.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int get_nvs_key_by_index_constprop_0(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_48;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [32];
  
  uStack_48 = 0;
  snprintf(param_3,7,"ZB%02x");
  iVar1 = nvs_entry_find_in_handle(param_1,0x42,&uStack_48);
  iVar2 = 0;
  do {
    if (iVar1 != 0) {
_L0:
      nvs_release_iterator(uStack_48);
      return iVar1;
    }
    nvs_entry_info(uStack_48,auStack_44);
    iVar1 = memcmp(param_3,auStack_34,4);
    if (iVar1 == 0) {
      if (iVar2 == param_2) {
        memcpy(param_3,auStack_34,7);
        iVar1 = 0;
        goto _L0;
      }
      iVar2 = iVar2 + 1;
    }
    iVar1 = nvs_entry_next(&uStack_48);
  } while( true );
}

