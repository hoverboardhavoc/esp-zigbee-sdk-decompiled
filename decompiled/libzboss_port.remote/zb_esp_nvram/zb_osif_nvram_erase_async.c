/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_nvram_erase_async
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_osif_nvram_erase_async(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = zb_get_nvram_page_length();
  uVar4 = uVar1;
  if (param_1 == 0) {
    uVar4 = 0;
  }
  iVar3 = 3;
  do {
    iVar2 = esp_partition_erase_range(zb_partition,uVar4,uVar1);
    if (iVar2 != 0x107) {
      if (iVar2 == 0) {
        zb_nvram_erase_finished(param_1);
        return 0;
      }
      break;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar4 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC1,uVar4,0x10000,iVar2,3);
  return 0xffffffff;
}

