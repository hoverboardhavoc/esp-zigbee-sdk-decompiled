/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> get_nvs_key_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int get_nvs_key_by_index(int param_1,int param_2,char *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [20];
  undefined4 auStack_24 [3];
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
                  ,0x56,"get_nvs_key_by_index",0x10000);
    iVar2 = 0;
_L0:
    memcpy(param_3,auStack_38,param_4);
  }
  else {
    auStack_24[0] = 0;
    snprintf(param_3,param_4,"ZB%02x");
    iVar2 = nvs_entry_find_in_handle(param_1,0x42,auStack_24);
    iVar1 = 0;
    while (iVar2 == 0) {
      nvs_entry_info(auStack_24[0],auStack_48);
      iVar3 = memcmp(param_3,auStack_38,4);
      if (iVar3 == 0) {
        if (iVar1 == param_2) goto _L0;
        iVar1 = iVar1 + 1;
      }
      iVar2 = nvs_entry_next(auStack_24);
    }
  }
  nvs_release_iterator(auStack_24[0]);
  return iVar2;
}

