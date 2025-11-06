/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
    uVar3 = esp_log_timestamp();
    esp_log(1,"ZB_ESP_NVRAM","E (%lu) %s: Failed to find zb_storage partition\n",uVar3,
            "ZB_ESP_NVRAM");
    zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x54);
_L0:
    uVar3 = esp_log_timestamp();
    uVar4 = *(undefined4 *)(zb_partition + 0x10);
    uVar2 = zb_get_nvram_page_count();
    esp_log(1,"ZB_ESP_NVRAM",
            "E (%lu) %s: Allocated zb_storage partition (0x%lx) cannot be divided into %d 16-byte aligned pages\n"
            ,uVar3,"ZB_ESP_NVRAM",uVar4,uVar2);
    zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x59);
  }
  else {
    iVar1 = zb_get_nvram_page_length();
    if (iVar1 == 0) goto _L0;
    zb_partition_product_config = esp_partition_find_first(1,0x81,"zb_fct");
    if (zb_partition_product_config != 0) {
      if (*(char *)(zb_partition_product_config + 0x29) == '\0') {
        return;
      }
      goto _L0;
    }
  }
  uVar3 = esp_log_timestamp();
  esp_log(1,"ZB_ESP_NVRAM","E (%lu) %s: Failed to find zb_fct partition\n",uVar3,"ZB_ESP_NVRAM");
  zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x60);
_L0:
  uVar3 = esp_log_timestamp();
  esp_log(1,"ZB_ESP_NVRAM","E (%lu) %s: Encrypted zb_fct partition is not supported\n",uVar3,
          "ZB_ESP_NVRAM");
  zb_assert("/builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_nvram.c",0x66);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

