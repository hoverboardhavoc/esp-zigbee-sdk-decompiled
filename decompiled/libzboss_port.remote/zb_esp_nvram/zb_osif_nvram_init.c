/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
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
  esp_log_write(1,0x10000,&_LC3,uVar1,0x10000);
  uVar1 = 0x54;
  while( true ) {
    while( true ) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",uVar1);
_L0:
      iVar2 = zb_get_nvram_page_length();
      if (iVar2 != 0) break;
      uVar1 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC5,uVar1,0x10000,*(undefined4 *)(zb_partition + 0x10),2);
      uVar1 = 0x59;
    }
    zb_partition_product_config = esp_partition_find_first(1,0x81,"zb_fct");
    if (zb_partition_product_config != 0) break;
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC7,uVar1,0x10000);
    uVar1 = 0x60;
  }
  return;
}

