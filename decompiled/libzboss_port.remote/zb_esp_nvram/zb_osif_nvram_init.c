/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_nvram_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_osif_nvram_init(void)

{
  undefined4 uVar1;
  int iVar2;
  
  zb_partition = esp_partition_find_first(1,0x81,"zb_storage");
  if (zb_partition != 0) goto _L0;
  uVar1 = esp_log_timestamp();
  esp_log(1,0x10000,"E (%lu) %s: Failed to find zb_storage partition\n",uVar1,0x10000);
  uVar1 = 0x54;
  while( true ) {
    while( true ) {
      while( true ) {
        zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",uVar1);
_L0:
        iVar2 = zb_get_nvram_page_length();
        if (iVar2 != 0) break;
        uVar1 = esp_log_timestamp();
        esp_log(1,0x10000,
                "E (%lu) %s: Allocated zb_storage partition (0x%lx) cannot be divided into %d 16-byte aligned pages\n"
                ,uVar1,0x10000,*(undefined4 *)(zb_partition + 0x10),2);
        uVar1 = 0x59;
      }
      zb_partition_product_config = esp_partition_find_first(1,0x81,"zb_fct");
      if (zb_partition_product_config != 0) break;
      uVar1 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Failed to find zb_fct partition\n",uVar1,0x10000);
      uVar1 = 0x60;
    }
    if (*(char *)(zb_partition_product_config + 0x29) == '\0') break;
    uVar1 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Encrypted zb_fct partition is not supported\n",uVar1,0x10000);
    uVar1 = 0x66;
  }
  return;
}

