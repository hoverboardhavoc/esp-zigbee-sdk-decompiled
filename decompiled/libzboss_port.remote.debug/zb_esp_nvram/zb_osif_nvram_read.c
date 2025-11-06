/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_nvram.o -> zb_osif_nvram_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_osif_nvram_read(int param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  uVar2 = zb_get_nvram_page_length();
  param_2 = (uVar2 & -(uint)(param_1 != 0)) + param_2;
  if (*(char *)(zb_partition + 0x29) != '\0') {
    local_30 = -1;
    iStack_2c = -1;
    iStack_28 = -1;
    iStack_24 = -1;
    uVar2 = param_4;
    if (0x10 < param_4) {
      uVar2 = 0x10;
    }
    iVar1 = 3;
    do {
      iVar3 = esp_partition_read_raw(zb_partition,param_2,&local_30,uVar2 & 0xffff);
      iVar1 = iVar1 + -1;
      if (iVar3 != 0x107) break;
    } while (0 < iVar1);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log(1,"ZB_ESP_NVRAM","E (%lu) %s: NVRAM op failed (error = %d) after %d retries\n",uVar4,
              "ZB_ESP_NVRAM",iVar3,3);
      return -1;
    }
    if ((((local_30 == -1) && (iStack_2c == -1)) && (iStack_28 == -1)) && (iStack_24 == -1)) {
      memset(param_3,0xff,param_4);
      return 0;
    }
  }
  iVar1 = 3;
  do {
    iVar3 = esp_partition_read(zb_partition,param_2,param_3,param_4);
    iVar1 = iVar1 + -1;
    if (iVar3 != 0x107) break;
  } while (0 < iVar1);
  if (iVar3 != 0) {
    uVar4 = esp_log_timestamp();
    esp_log(1,"ZB_ESP_NVRAM","E (%lu) %s: NVRAM op failed (error = %d) after %d retries\n",uVar4,
            "ZB_ESP_NVRAM",iVar3,3);
    iVar3 = -1;
  }
  return iVar3;
}

