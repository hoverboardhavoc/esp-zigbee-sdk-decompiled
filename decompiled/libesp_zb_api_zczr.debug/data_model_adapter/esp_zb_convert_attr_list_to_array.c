/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> data_model_adapter.o -> esp_zb_convert_attr_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001031a) */

uint esp_zb_convert_attr_list_to_array(int param_1)

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
    esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC1,uVar4,"ESP_ZIGBEE_DM_ADAPTER");
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
      esp_log_write(3,"ESP_ZIGBEE_DM_ADAPTER",&_LC4,uVar4,"ESP_ZIGBEE_DM_ADAPTER");
    }
    else {
      esp_zb_finish_attr_lists();
      uVar2 = (local_20 & 0xffff) + 1;
      local_20 = CONCAT22(local_20._2_2_,(short)(uVar2 * 0x10000 >> 0x10));
      iVar1 = *(int *)(param_1 + 0xc);
      pvStack_1c = calloc(uVar2 & 0xffff,10);
      if (pvStack_1c == (void *)0x0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC2,uVar4,"ESP_ZIGBEE_DM_ADAPTER",
                      "esp_zb_convert_attr_list_to_array",0x70);
_L0:
        esp_zb_attr_array_cleanup(&local_20);
      }
      else {
        for (uVar2 = 0; uVar2 < (local_20 & 0xffff); uVar2 = uVar2 + 1 & 0xffff) {
          iVar3 = esp_zb_internal_zcl_attr_clone((void *)((int)pvStack_1c + uVar2 * 10),iVar1);
          if (iVar3 != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC3,uVar4,"ESP_ZIGBEE_DM_ADAPTER",
                          "esp_zb_convert_attr_list_to_array",0x73);
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

