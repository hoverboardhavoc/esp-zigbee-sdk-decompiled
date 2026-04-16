/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_add(uint16_t key,uint8_t *value,uint16_t length)

{
  bool bVar1;
  nvs_handle_t nVar2;
  int iVar3;
  char cVar4;
  undefined2 in_register_00002032;
  undefined4 local_60;
  nvs_iterator_t nvs_it;
  char nvs_key [7];
  nvs_entry_info_t info;
  
  nVar2 = s_nvs_handle;
  iVar3 = 0x103;
  if (s_nvs_handle != 0) {
    nvs_it = (nvs_iterator_t)0x0;
    nvs_key[0] = '\0';
    nvs_key[1] = '\0';
    nvs_key[2] = '\0';
    cVar4 = -1;
    do {
      s_unused_pos_0 = s_unused_pos_0 + '\x01';
      local_60 = 0;
      snprintf((char *)&nvs_it,7,"ZB%02x%02x");
      iVar3 = nvs_entry_find_in_handle(nVar2,0x42,&local_60);
      while (iVar3 == 0) {
        nvs_entry_info(local_60,nvs_key + 4);
        iVar3 = strncmp((char *)&nvs_it,info.namespace_name + 0xc,7);
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
      iVar3 = nvs_set_blob(s_nvs_handle,&nvs_it,value,CONCAT22(in_register_00002032,length));
      if (iVar3 == 0) {
        iVar3 = nvs_commit(s_nvs_handle);
      }
    }
  }
  return (uint)(iVar3 != 0);
}

