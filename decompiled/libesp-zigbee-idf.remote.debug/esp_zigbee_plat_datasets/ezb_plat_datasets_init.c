/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ezb_plat_datasets_init(void)

{
  int iVar1;
  
  if ((s_nvs_handle == 0) &&
     (iVar1 = nvs_open_from_partition(s_storage_name,"zigbee",1,&s_nvs_handle), iVar1 != 0)) {
    _esp_error_check_failed
              ("/build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c",
               0x92,"ezb_plat_datasets_init",
               "nvs_open_from_partition(DS_PART_NAME, DS_NAMESPACE, NVS_READWRITE, &s_nvs_handle)");
    if (s_nvs_handle != 0) {
      nvs_close();
      s_nvs_handle = 0;
    }
    return;
  }
  return;
}

