/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
              ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
               ,0x92,"ezb_plat_datasets_init",
               "nvs_open_from_partition(DS_PART_NAME, DS_NAMESPACE, NVS_READWRITE, &s_nvs_handle)");
    if (s_nvs_handle != 0) {
      nvs_close();
      s_nvs_handle = 0;
    }
    return;
  }
  return;
}

