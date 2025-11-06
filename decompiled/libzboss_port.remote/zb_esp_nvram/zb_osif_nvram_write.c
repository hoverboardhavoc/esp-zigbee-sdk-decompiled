/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_nvram_write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_osif_nvram_write(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = zb_get_nvram_page_length();
  iVar1 = 3;
  do {
    iVar3 = esp_partition_write(zb_partition,(-(uint)(param_1 != 0) & uVar2) + param_2,param_3,
                                param_4);
    if (iVar3 != 0x107) {
      if (iVar3 == 0) {
        return 0;
      }
      break;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  uVar4 = esp_log_timestamp();
  esp_log(1,0x10000,"E (%lu) %s: NVRAM op failed (error = %d) after %d retries\n",uVar4,0x10000,
          iVar3,3);
  return 0xffffffff;
}

