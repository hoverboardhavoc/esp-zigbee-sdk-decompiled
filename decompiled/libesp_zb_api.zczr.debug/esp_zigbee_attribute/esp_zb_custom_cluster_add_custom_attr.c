/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_custom_cluster_add_custom_attr
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = esp_log_timestamp(param_5);
    esp_log_write(1,0x10000,&_LC12,uVar1,0x10000,"esp_zb_custom_cluster_add_custom_attr",0xbcf);
    uVar1 = 0x102;
  }
  else {
    uVar1 = esp_zb_internal_cluster_add_attr
                      (*(undefined2 *)(*(int *)(param_1 + 0xc) + 10),param_2,param_3,param_4,0xffff)
    ;
  }
  return uVar1;
}

