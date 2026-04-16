/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> erase_all_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t erase_all_key(nvs_handle_t nvs_handle,uint16_t ds_key)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_40 [4];
  nvs_entry_info_t info;
  char nvs_key [5];
  nvs_iterator_t nvs_it;
  
  if (nvs_handle == 0) {
    __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
                  ,0x74,"erase_all_key",0x10000);
    iVar2 = 0;
_L0:
    bVar1 = false;
  }
  else {
    stack0xffffffec = 0;
    info.type = 0;
    nvs_key[0] = '\0';
    snprintf((char *)&info.type,5,"ZB%02x");
    iVar2 = nvs_entry_find_in_handle(nvs_handle,0x42,nvs_key + 4);
    bVar1 = false;
    while (iVar2 == 0) {
      nvs_entry_info(stack0xffffffec,auStack_40);
      iVar2 = memcmp(&info.type,info.namespace_name + 0xc,4);
      if (iVar2 == 0) {
        iVar2 = nvs_erase_key(s_nvs_handle,info.namespace_name + 0xc);
        if (iVar2 != 0) goto _L0;
        bVar1 = true;
      }
      iVar2 = nvs_entry_next(nvs_key + 4);
    }
  }
  nvs_release_iterator(stack0xffffffec);
  if (bVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

