/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nvs_key */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_get(uint16_t key,int index,uint8_t *value,uint16_t *length)

{
  esp_err_t eVar1;
  int iVar2;
  size_t in_a4;
  uint uStack_1c;
  size_t tmp_len;
  char nvs_key [7];
  
  if (s_nvs_handle != 0) {
    tmp_len = 0;
    nvs_key[0] = '\0';
    nvs_key[1] = '\0';
    nvs_key[2] = '\0';
    eVar1 = get_nvs_key_by_index(s_nvs_handle,key,index,(char *)&tmp_len,in_a4);
    if (eVar1 == 0) {
      uStack_1c = 0;
      if (length != (uint16_t *)0x0) {
        uStack_1c = (uint)*length;
      }
      iVar2 = nvs_get_blob(s_nvs_handle,&tmp_len,value,&uStack_1c);
      if (iVar2 == 0) {
        if (length == (uint16_t *)0x0) {
          return 0;
        }
        *length = (uint16_t)uStack_1c;
        return 0;
      }
    }
  }
  return 5;
}

