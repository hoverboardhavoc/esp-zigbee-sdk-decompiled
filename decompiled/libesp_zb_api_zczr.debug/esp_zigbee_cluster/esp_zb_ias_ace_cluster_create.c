/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_ias_ace_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_ace_cluster_create(byte *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte abStack_14 [8];
  
  abStack_14[0] = 0xff;
  uVar2 = esp_zb_zcl_attr_list_create(0x501);
  if (param_1 != (byte *)0x0) {
    abStack_14[0] = *param_1;
  }
  if (abStack_14[0] == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = calloc((uint)abStack_14[0],0xf);
    if (pvVar1 == (void *)0x0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC11,uVar3,0x10000);
      abStack_14[0] = 0;
    }
  }
  esp_zb_cluster_add_attr(uVar2,0x501,0xeffe,0x20,1,abStack_14);
  esp_zb_cluster_add_attr(uVar2,0x501,0xefff,abStack_14[0] * '\x0f',0x40,pvVar1);
  return uVar2;
}

