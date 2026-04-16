/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_delete(uint16_t key,int index)

{
  bool bVar1;
  nvs_handle_t nVar2;
  int iVar3;
  esp_err_t eVar4;
  size_t in_a4;
  undefined4 local_40;
  nvs_iterator_t nvs_it;
  char nvs_key [5];
  nvs_entry_info_t info;
  
  nVar2 = s_nvs_handle;
  if (s_nvs_handle != 0) {
    if (index == -1) {
      local_40 = 0;
      nvs_it = (nvs_iterator_t)0x0;
      nvs_key[0] = '\0';
      snprintf((char *)&nvs_it,5,"ZB%02x",key & 0xff);
      iVar3 = nvs_entry_find_in_handle(nVar2,0x42,&local_40);
      bVar1 = false;
      while (iVar3 == 0) {
        nvs_entry_info(local_40,nvs_key + 4);
        iVar3 = memcmp(&nvs_it,info.namespace_name + 0xc,4);
        if (iVar3 == 0) {
          iVar3 = nvs_erase_key(s_nvs_handle,info.namespace_name + 0xc);
          if (iVar3 != 0) {
            bVar1 = false;
            break;
          }
          bVar1 = true;
        }
        iVar3 = nvs_entry_next(&local_40);
      }
      nvs_release_iterator(local_40);
      if (!bVar1) {
        return 5;
      }
    }
    else {
      stack0xffffffcc = 0;
      info.namespace_name[0] = '\0';
      info.namespace_name[1] = '\0';
      info.namespace_name[2] = '\0';
      eVar4 = get_nvs_key_by_index(s_nvs_handle,key,index,nvs_key + 4,in_a4);
      if (eVar4 != 0) {
        return 5;
      }
      nvs_erase_key(s_nvs_handle,nvs_key + 4);
    }
    iVar3 = nvs_commit(s_nvs_handle);
    if (iVar3 == 0) {
      return 0;
    }
  }
  return 5;
}

