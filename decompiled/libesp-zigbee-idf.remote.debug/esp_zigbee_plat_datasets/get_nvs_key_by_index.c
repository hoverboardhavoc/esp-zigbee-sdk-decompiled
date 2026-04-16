/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> get_nvs_key_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t get_nvs_key_by_index
                    (nvs_handle_t nvs_handle,uint16_t ds_key,int index,char *nvs_key,
                    size_t nvs_key_len)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_48 [4];
  nvs_entry_info_t info;
  nvs_iterator_t nvs_it;
  
  if (nvs_handle == 0) {
    __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
                  ,0x56,"get_nvs_key_by_index",0x10000);
    iVar2 = 0;
_L0:
    memcpy(nvs_key,info.namespace_name + 0xc,nvs_key_len);
  }
  else {
    info.type = 0;
    snprintf(nvs_key,nvs_key_len,"ZB%02x");
    iVar2 = nvs_entry_find_in_handle(nvs_handle,0x42,&info.type);
    iVar1 = 0;
    while (iVar2 == 0) {
      nvs_entry_info(info.type,auStack_48);
      iVar3 = memcmp(nvs_key,info.namespace_name + 0xc,4);
      if (iVar3 == 0) {
        if (iVar1 == index) goto _L0;
        iVar1 = iVar1 + 1;
      }
      iVar2 = nvs_entry_next(&info.type);
    }
  }
  nvs_release_iterator(info.type);
  return iVar2;
}

