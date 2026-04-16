/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_get(uint16_t key,int index,uint8_t *value,uint16_t *length)

{
  int iVar1;
  undefined2 in_register_0000202a;
  undefined4 uVar2;
  uint uStack_2c;
  size_t tmp_len;
  char nvs_key [7];
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    tmp_len = 0;
    nvs_key[0] = '\0';
    nvs_key[1] = '\0';
    nvs_key[2] = '\0';
    iVar1 = get_nvs_key_by_index(s_nvs_handle,key,index,(char *)&tmp_len,7);
    if (iVar1 == 0) {
      if (length == (uint16_t *)0x0) {
        uStack_2c = 0;
      }
      else {
        uStack_2c = (uint)*length;
      }
      iVar1 = nvs_get_blob(s_nvs_handle,&tmp_len,value,&uStack_2c);
      if (iVar1 == 0) {
        if (length == (uint16_t *)0x0) {
          return 0;
        }
        *length = (uint16_t)uStack_2c;
        return 0;
      }
    }
  }
  if (iVar1 == 0x1102) {
    iVar1 = 5;
  }
  else {
    uVar2 = esp_err_to_name(iVar1);
    esp_log(0x12,"ESP-ZIGBEE","Failed to get dataset %d.%d: %s",CONCAT22(in_register_0000202a,key),
            index,uVar2);
    if (iVar1 != 0) {
      iVar1 = 5;
    }
  }
  return iVar1;
}

