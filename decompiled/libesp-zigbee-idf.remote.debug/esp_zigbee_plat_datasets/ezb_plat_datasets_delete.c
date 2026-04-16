/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nvs_key */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_delete(uint16_t key,int index)

{
  undefined2 in_register_0000202a;
  int iVar1;
  undefined4 uVar2;
  char acStack_18 [4];
  char nvs_key [7];
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    if (index == -1) {
      iVar1 = erase_all_key(s_nvs_handle,key);
      if (iVar1 != 0) goto _L0;
    }
    else {
      acStack_18[0] = '\0';
      acStack_18[1] = '\0';
      acStack_18[2] = '\0';
      acStack_18[3] = '\0';
      nvs_key[0] = '\0';
      nvs_key[1] = '\0';
      nvs_key[2] = '\0';
      iVar1 = get_nvs_key_by_index(s_nvs_handle,key,index,acStack_18,7);
      if (iVar1 != 0) goto _L0;
      nvs_erase_key(s_nvs_handle,acStack_18);
    }
    iVar1 = nvs_commit(s_nvs_handle);
    if (iVar1 == 0) {
      return 0;
    }
  }
_L0:
  if (iVar1 == 0x1102) {
    iVar1 = 5;
  }
  else {
    uVar2 = esp_err_to_name(iVar1);
    esp_log(0x12,"ESP-ZIGBEE","Failed to delete dataset %d.%d: %s",
            CONCAT22(in_register_0000202a,key),index,uVar2);
    if (iVar1 != 0) {
      iVar1 = 5;
    }
  }
  return iVar1;
}

