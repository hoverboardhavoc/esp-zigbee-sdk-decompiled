/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_addr_read.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_osif_addr_read_part_0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = 3;
  do {
    iVar2 = esp_partition_read(zb_partition_product_config,param_1,param_2,param_3);
    if (iVar2 != 0x107) {
      if (iVar2 == 0) {
        return 0;
      }
      break;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  uVar3 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC1,uVar3,0x10000,iVar2,3);
  return 0xffffffff;
}

