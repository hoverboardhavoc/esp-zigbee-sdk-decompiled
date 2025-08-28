/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_alarms_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

undefined4 esp_zb_alarms_cluster_create(short *param_1)

{
  undefined4 uVar1;
  short asStack_14 [4];
  
  asStack_14[0] = 0xf;
  uVar1 = esp_zb_zcl_attr_list_create(9);
  if (param_1 != (short *)0x0) {
    asStack_14[0] = *param_1;
  }
  if (asStack_14[0] != 0) {
    asStack_14[1] = 0;
    esp_zb_alarms_cluster_add_attr(uVar1,0,asStack_14 + 1);
  }
  esp_zb_cluster_add_manufacturer_attr(uVar1,9,0xeffe,0xffff,2,0x40,asStack_14);
  esp_zb_cluster_add_manufacturer_attr(uVar1,9,0xefff,0xffff,0,0x40,0);
  return uVar1;
}

