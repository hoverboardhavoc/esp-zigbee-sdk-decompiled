/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_nvram.o -> zb_osif_nvram_write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_osif_nvram_write(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = zb_get_nvram_page_length();
  iVar1 = 3;
  do {
    iVar3 = esp_partition_write(zb_partition,iVar2 * (uint)(param_1 != 0) + param_2,param_3,param_4)
    ;
    iVar1 = iVar1 + -1;
    if (iVar3 != 0x107) break;
  } while (0 < iVar1);
  if (iVar3 != 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ZB_ESP_NVRAM",&_L0,uVar4,"ZB_ESP_NVRAM",iVar3,3);
    iVar3 = -1;
  }
  return iVar3;
}

