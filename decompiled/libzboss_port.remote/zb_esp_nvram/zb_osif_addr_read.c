/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_addr_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_osif_addr_read(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    return 0xfffffff5;
  }
  if (param_2 == 0) {
    return 0xfffffff4;
  }
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
  esp_log(1,0x10000,"E (%lu) %s: NVRAM op failed (error = %d) after %d retries\n",uVar3,0x10000,
          iVar2,3);
  return 0xffffffff;
}

