/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_datasets_delete(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 local_40;
  char acStack_3c [8];
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 auStack_24 [24];
  
  iVar2 = s_nvs_handle;
  if (s_nvs_handle != 0) {
    if (param_2 == -1) {
      local_40 = 0;
      acStack_3c[0] = '\0';
      acStack_3c[1] = '\0';
      acStack_3c[2] = '\0';
      acStack_3c[3] = '\0';
      acStack_3c[4] = 0;
      snprintf(acStack_3c,5,"ZB%02x");
      iVar2 = nvs_entry_find_in_handle(iVar2,0x42,&local_40);
      bVar1 = false;
      while (iVar2 == 0) {
        nvs_entry_info(local_40,&uStack_34);
        iVar2 = memcmp(acStack_3c,auStack_24,4);
        if (iVar2 == 0) {
          iVar2 = nvs_erase_key(s_nvs_handle,auStack_24);
          if (iVar2 != 0) {
            bVar1 = false;
            break;
          }
          bVar1 = true;
        }
        iVar2 = nvs_entry_next(&local_40);
      }
      nvs_release_iterator(local_40);
      if (!bVar1) {
        return 5;
      }
    }
    else {
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2e = 0;
      iVar2 = get_nvs_key_by_index_constprop_0(s_nvs_handle,param_1,param_2,&uStack_34);
      if (iVar2 != 0) {
        return 5;
      }
      nvs_erase_key(s_nvs_handle,&uStack_34);
    }
    iVar2 = nvs_commit(s_nvs_handle);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 5;
}

