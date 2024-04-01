/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_endpoint.o -> zcl_convert_cluster_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000103be) */

undefined4 zcl_convert_cluster_list_to_array(int param_1)

{
  uint __nmemb;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  
  local_20 = 0;
  pvStack_1c = (void *)0x0;
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC1,uVar2,"ESP_ZIGBEE_ENDPOINT",
                  "zcl_convert_cluster_list_to_array",0x80);
    uStack_18 = local_20;
  }
  else {
    __nmemb = 0;
    iVar3 = param_1;
    while (iVar3 = *(int *)(iVar3 + 0x10), iVar3 != 0) {
      if (*(char *)(iVar3 + 8) == '\x01') {
        local_20._0_3_ = CONCAT12(local_20._2_1_ + '\x01',(undefined2)local_20);
      }
      else {
        local_20 = CONCAT13(local_20._3_1_ + '\x01',(undefined3)local_20);
      }
      for (uVar4 = 0; uVar4 < *(ushort *)(iVar3 + 2); uVar4 = uVar4 + 1 & 0xffff) {
        if ((*(byte *)(uVar4 * 10 + *(int *)(iVar3 + 4) + 3) & 4) != 0) {
          local_20._0_2_ = CONCAT11(local_20._1_1_ + '\x01',(char)local_20);
        }
      }
      local_20 = CONCAT31(local_20._1_3_,(char)local_20 + '\x01');
      __nmemb = __nmemb + 1 & 0xff;
    }
    if (__nmemb == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_ENDPOINT",&_LC4,uVar2,"ESP_ZIGBEE_ENDPOINT");
    }
    else {
      iVar3 = *(int *)(param_1 + 0x10);
      pvStack_1c = calloc(__nmemb,0xf);
      if (pvStack_1c == (void *)0x0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC2,uVar2,"ESP_ZIGBEE_ENDPOINT",
                      "zcl_convert_cluster_list_to_array",0x94);
_L0:
        zb_zcl_cluster_array_cleanup(&local_20);
        local_20 = 0;
      }
      else {
        for (uVar4 = 0; uVar4 < __nmemb; uVar4 = uVar4 + 1 & 0xff) {
          iVar1 = esp_zb_internal_zcl_clone_cluster((void *)((int)pvStack_1c + uVar4 * 0xf),iVar3);
          if (iVar1 != 0) {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC3,uVar2,"ESP_ZIGBEE_ENDPOINT",
                          "zcl_convert_cluster_list_to_array",0x97);
            goto _L0;
          }
          iVar3 = *(int *)(iVar3 + 0x10);
        }
      }
    }
    uStack_18 = local_20;
  }
  return uStack_18;
}

