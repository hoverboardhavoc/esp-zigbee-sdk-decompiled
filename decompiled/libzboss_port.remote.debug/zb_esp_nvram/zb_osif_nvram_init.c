/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_nvram.o -> zb_osif_nvram_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_osif_nvram_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  zb_partition = esp_partition_find_first(1,0x81,"zb_storage");
  if (zb_partition == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ZB_ESP_NVRAM",&_LC2,uVar4,"ZB_ESP_NVRAM");
    zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x54);
  }
  else {
    iVar1 = zb_get_nvram_page_length();
    if (iVar1 != 0) {
      zb_partition_product_config = esp_partition_find_first(1,0x81,"zb_fct");
      if (zb_partition_product_config != 0) {
        return;
      }
      goto _L0;
    }
  }
  uVar2 = esp_log_timestamp();
  uVar4 = *(undefined4 *)(zb_partition + 0x10);
  uVar3 = zb_get_nvram_page_count();
  esp_log_write(1,"ZB_ESP_NVRAM",&_LC4,uVar2,"ZB_ESP_NVRAM",uVar4,uVar3);
  zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x59);
_L0:
  uVar4 = esp_log_timestamp();
  esp_log_write(1,"ZB_ESP_NVRAM",&_LC6,uVar4,"ZB_ESP_NVRAM");
  zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x60);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

