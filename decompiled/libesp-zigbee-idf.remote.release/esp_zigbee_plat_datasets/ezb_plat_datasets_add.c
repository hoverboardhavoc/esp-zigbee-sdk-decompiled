/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ezb_plat_datasets_add(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 local_60;
  char acStack_5c [8];
  undefined1 auStack_54 [16];
  char acStack_44 [28];
  
  iVar2 = s_nvs_handle;
  iVar3 = 0x103;
  if (s_nvs_handle != 0) {
    acStack_5c[0] = '\0';
    acStack_5c[1] = '\0';
    acStack_5c[2] = '\0';
    acStack_5c[3] = '\0';
    acStack_5c[4] = '\0';
    acStack_5c[5] = '\0';
    acStack_5c[6] = 0;
    cVar4 = -1;
    do {
      s_unused_pos_0 = s_unused_pos_0 + '\x01';
      local_60 = 0;
      snprintf(acStack_5c,7,"ZB%02x%02x");
      iVar3 = nvs_entry_find_in_handle(iVar2,0x42,&local_60);
      while (iVar3 == 0) {
        nvs_entry_info(local_60,auStack_54);
        iVar3 = strncmp(acStack_5c,acStack_44,7);
        if (iVar3 == 0) {
          bVar1 = true;
          iVar3 = 0;
          goto _L0;
        }
        iVar3 = nvs_entry_next(&local_60);
      }
      bVar1 = false;
_L0:
      nvs_release_iterator(local_60);
      if (!bVar1) goto _L0;
      cVar4 = cVar4 + -1;
    } while (cVar4 != '\0');
    if (iVar3 == 0) {
_L0:
      iVar3 = nvs_set_blob(s_nvs_handle,acStack_5c,param_1,param_2);
      if (iVar3 == 0) {
        iVar3 = nvs_commit(s_nvs_handle);
      }
    }
  }
  return iVar3 != 0;
}

