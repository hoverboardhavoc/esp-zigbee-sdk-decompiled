/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_nvram_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_osif_nvram_read(int param_1,int param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  
  uVar1 = zb_get_nvram_page_length();
  param_2 = (uVar1 & -(uint)(param_1 != 0)) + param_2;
  if (*(char *)(zb_partition + 0x29) == '\0') {
_L0:
    iVar4 = 3;
    do {
      iVar2 = esp_partition_read(zb_partition,param_2,param_3,param_4);
      if (iVar2 != 0x107) {
        if (iVar2 == 0) {
          return 0;
        }
        break;
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    memcpy(&local_40,&_LC9,0x10);
    uVar1 = param_4;
    if (0x10 < param_4) {
      uVar1 = 0x10;
    }
    iVar4 = 3;
    do {
      iVar2 = esp_partition_read_raw(zb_partition,param_2,&local_40,uVar1 & 0xffff);
      if (iVar2 != 0x107) {
        if (iVar2 == 0) {
          if (((local_40 & uStack_38) == 0xffffffff) && ((uStack_34 & uStack_3c) == 0xffffffff)) {
            memset(param_3,0xff,param_4);
            return 0;
          }
          goto _L0;
        }
        break;
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  uVar3 = esp_log_timestamp();
  esp_log(1,0x10000,"E (%lu) %s: NVRAM op failed (error = %d) after %d retries\n",uVar3,0x10000,
          iVar2,3);
  return 0xffffffff;
}

