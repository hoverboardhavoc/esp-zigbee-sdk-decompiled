/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> get_nvs_key_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

esp_err_t get_nvs_key_by_index
                    (nvs_handle_t nvs_handle,uint16_t ds_key,int index,char *nvs_key,
                    size_t nvs_key_len)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_48;
  nvs_iterator_t nvs_it;
  nvs_entry_info_t info;
  
  uStack_48 = 0;
  snprintf(nvs_key,7,"ZB%02x");
  iVar1 = nvs_entry_find_in_handle(nvs_handle,0x42,&uStack_48);
  iVar2 = 0;
  do {
    if (iVar1 != 0) {
_L0:
      nvs_release_iterator(uStack_48);
      return iVar1;
    }
    nvs_entry_info(uStack_48,&nvs_it);
    iVar1 = memcmp(nvs_key,info.namespace_name + 0xc,4);
    if (iVar1 == 0) {
      if (iVar2 == index) {
        memcpy(nvs_key,info.namespace_name + 0xc,7);
        iVar1 = 0;
        goto _L0;
      }
      iVar2 = iVar2 + 1;
    }
    iVar1 = nvs_entry_next(&uStack_48);
  } while( true );
}

