/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> zcl_convert_attr_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001064c) */

uint zcl_convert_attr_list_to_array(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_20;
  void *pvStack_1c;
  uint uStack_18;
  
  local_20 = local_20 & 0xffff0000;
  pvStack_1c = (void *)0x0;
  iVar1 = param_1;
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uStack_18 = local_20;
  }
  else {
    while( true ) {
      if (*(int *)(iVar1 + 0xc) == 0) break;
      local_20 = CONCAT22(local_20._2_2_,(short)local_20 + 1);
      iVar1 = *(int *)(iVar1 + 0xc);
    }
    if ((local_20 & 0xffff) == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CLUSTER",&_LC11,uVar4,"ESP_ZIGBEE_CLUSTER");
    }
    else {
      zcl_finish_attr_lists();
      uVar2 = (local_20 & 0xffff) + 1;
      local_20 = CONCAT22(local_20._2_2_,(short)(uVar2 * 0x10000 >> 0x10));
      iVar1 = *(int *)(param_1 + 0xc);
      pvStack_1c = calloc(uVar2 & 0xffff,10);
      if (pvStack_1c == (void *)0x0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC9,uVar4,"ESP_ZIGBEE_CLUSTER",
                      "zcl_convert_attr_list_to_array",0xb4);
_L0:
        zb_zcl_attr_array_cleanup(&local_20);
        local_20 = 0;
      }
      else {
        for (uVar2 = 0; uVar2 < (local_20 & 0xffff); uVar2 = uVar2 + 1 & 0xffff) {
          iVar3 = esp_zb_internal_zcl_clone_attribute((void *)((int)pvStack_1c + uVar2 * 10),iVar1);
          if (iVar3 != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC10,uVar4,"ESP_ZIGBEE_CLUSTER",
                          "zcl_convert_attr_list_to_array",0xb7);
            goto _L0;
          }
          iVar1 = *(int *)(iVar1 + 0xc);
        }
      }
    }
    uStack_18 = local_20;
  }
  return uStack_18;
}

