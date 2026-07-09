/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> erase_all_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int erase_all_key(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [20];
  char acStack_1c [8];
  undefined4 auStack_14 [2];
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
                  ,0x74,"erase_all_key",0x10000);
    iVar2 = 0;
_L0:
    bVar1 = false;
  }
  else {
    auStack_14[0] = 0;
    acStack_1c[0] = '\0';
    acStack_1c[1] = '\0';
    acStack_1c[2] = '\0';
    acStack_1c[3] = '\0';
    acStack_1c[4] = 0;
    snprintf(acStack_1c,5,"ZB%02x");
    iVar2 = nvs_entry_find_in_handle(param_1,0x42,auStack_14);
    bVar1 = false;
    while (iVar2 == 0) {
      nvs_entry_info(auStack_14[0],auStack_40);
      iVar2 = memcmp(acStack_1c,auStack_30,4);
      if (iVar2 == 0) {
        iVar2 = nvs_erase_key(s_nvs_handle,auStack_30);
        if (iVar2 != 0) goto _L0;
        bVar1 = true;
      }
      iVar2 = nvs_entry_next(auStack_14);
    }
  }
  nvs_release_iterator(auStack_14[0]);
  if (bVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

