/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nvs_key */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_set(uint16_t key,uint8_t *value,uint16_t length)

{
  int iVar1;
  undefined2 in_register_00002032;
  char acStack_18 [4];
  char nvs_key [7];
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    acStack_18[0] = '\0';
    acStack_18[1] = '\0';
    acStack_18[2] = '\0';
    acStack_18[3] = '\0';
    nvs_key[0] = '\0';
    nvs_key[1] = '\0';
    nvs_key[2] = '\0';
    snprintf(acStack_18,7,"ZB%02x%02x");
    iVar1 = nvs_set_blob(s_nvs_handle,acStack_18,value,CONCAT22(in_register_00002032,length));
    if (iVar1 == 0) {
      iVar1 = nvs_commit(s_nvs_handle);
    }
  }
  return (uint)(iVar1 != 0);
}

