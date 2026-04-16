/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_datasets_add(uint16_t key,uint8_t *value,uint16_t length)

{
  int iVar1;
  undefined2 in_register_0000202a;
  undefined4 uVar2;
  undefined2 in_register_00002032;
  char acStack_28 [4];
  char nvs_key [7];
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    acStack_28[0] = '\0';
    acStack_28[1] = '\0';
    acStack_28[2] = '\0';
    acStack_28[3] = '\0';
    nvs_key[0] = '\0';
    nvs_key[1] = '\0';
    nvs_key[2] = '\0';
    iVar1 = get_next_empty_nvs_key(s_nvs_handle,key,acStack_28,7);
    if (((iVar1 == 0) &&
        (iVar1 = nvs_set_blob(s_nvs_handle,acStack_28,value,CONCAT22(in_register_00002032,length)),
        iVar1 == 0)) && (iVar1 = nvs_commit(s_nvs_handle), iVar1 == 0)) goto _L0;
  }
  uVar2 = esp_err_to_name(iVar1);
  esp_log(0x12,"ESP-ZIGBEE","Failed to add dataset %d: %s",CONCAT22(in_register_0000202a,key),uVar2)
  ;
_L0:
  return (uint)(iVar1 != 0);
}

