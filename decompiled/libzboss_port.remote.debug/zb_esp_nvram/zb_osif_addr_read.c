/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_nvram.o -> zb_osif_addr_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_osif_addr_read(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    iVar2 = -0xb;
  }
  else if (param_2 == 0) {
    iVar2 = -0xc;
  }
  else {
    iVar1 = 3;
    do {
      iVar2 = esp_partition_read(zb_partition_product_config,param_1,param_2,param_3);
      iVar1 = iVar1 + -1;
      if (iVar2 != 0x107) break;
    } while (0 < iVar1);
    if (iVar2 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ZB_ESP_NVRAM",&_L0,uVar3,"ZB_ESP_NVRAM",iVar2,3);
      iVar2 = -1;
    }
  }
  return iVar2;
}

