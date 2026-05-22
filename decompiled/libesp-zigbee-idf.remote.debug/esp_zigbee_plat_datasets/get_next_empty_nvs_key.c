/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> get_next_empty_nvs_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: info */
/* WARNING: Unknown calling convention */

esp_err_t get_next_empty_nvs_key
                    (nvs_handle_t nvs_handle,uint16_t ds_key,char *nvs_key,size_t nvs_key_len)

{
  bool bVar1;
  int unaff_s0;
  int iVar2;
  char unaff_s2;
  undefined4 uStack_48;
  nvs_iterator_t nvs_it;
  nvs_entry_info_t info;
  
  if (nvs_handle == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_datasets.c"
                  ,0x32,"get_next_empty_nvs_key",0x10000);
    goto _L0;
  }
  unaff_s2 = '\0';
  unaff_s0 = 0x105;
_L0:
  if (unaff_s2 == -1) {
    return unaff_s0;
  }
  uStack_48 = 0;
  get_next_empty_nvs_key::s_unused_pos = get_next_empty_nvs_key::s_unused_pos + '\x01';
  snprintf(nvs_key,nvs_key_len,"ZB%02x%02x");
  unaff_s0 = nvs_entry_find_in_handle(nvs_handle,0x42,&uStack_48);
  while (unaff_s0 == 0) {
    nvs_entry_info(uStack_48,&nvs_it);
    iVar2 = strncmp(nvs_key,info.namespace_name + 0xc,7);
    if (iVar2 == 0) goto _L0;
    unaff_s0 = nvs_entry_next(&uStack_48);
  }
  bVar1 = false;
  goto _L0;
_L0:
  bVar1 = true;
_L0:
  nvs_release_iterator(uStack_48);
  if (!bVar1) {
    return 0;
  }
  unaff_s2 = unaff_s2 + '\x01';
  goto _L0;
}

