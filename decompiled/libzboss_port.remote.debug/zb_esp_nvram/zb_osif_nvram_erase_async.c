/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_nvram.o -> zb_osif_nvram_erase_async
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_osif_nvram_erase_async(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = zb_get_nvram_page_length();
  iVar1 = 3;
  do {
    iVar3 = esp_partition_erase_range(zb_partition,iVar2 * (uint)(param_1 != 0),iVar2);
    iVar1 = iVar1 + -1;
    if (iVar3 != 0x107) break;
  } while (0 < iVar1);
  if (iVar3 == 0) {
    zb_osif_flash_erase_finished(param_1);
    uVar4 = 0;
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ZB_ESP_NVRAM",&_L0,uVar4,"ZB_ESP_NVRAM",iVar3,3);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

