/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> ota_insert_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * ota_insert_file(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  void *pvVar4;
  
  if (param_1 == 0) {
    piVar1 = (int *)zb_buf_get_out_delayed_func(ota_insert_file);
  }
  else {
    puVar2 = (undefined1 *)zb_buf_get_tail_func(0x10);
    *puVar2 = ota_config;
    puVar2[1] = 0;
    *(undefined1 **)(puVar2 + 4) = &ota_config;
    *(undefined4 *)(puVar2 + 0xc) = DAT_00010350;
    puVar2[8] = 1;
    piVar1 = (int *)zb_zcl_ota_upgrade_insert_file(param_1);
    if (piVar1 != (int *)0x0) {
      iVar3 = zb_assert("/home/xiaqilin/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_ota.c",
                        0x82);
      piVar1 = (int *)malloc(0x10);
      pvVar4 = malloc(8);
      *piVar1 = iVar3;
      piVar1[1] = iVar3 + 4;
      *(undefined1 *)(piVar1 + 2) = 1;
      piVar1[3] = (int)pvVar4;
      return piVar1;
    }
  }
  return piVar1;
}

