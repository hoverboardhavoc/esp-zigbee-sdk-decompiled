/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> data_model_adapter.o -> esp_zb_convert_cluster_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_convert_cluster_list_to_array(int param_1)

{
  uint __nmemb;
  undefined2 extraout_a0;
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  void *__src;
  uint uVar4;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  
  uStack_30 = 0;
  pvStack_2c = (void *)0x0;
  if (param_1 == 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_L0,uVar1,"ESP_ZIGBEE_DM_ADAPTER",
                  "esp_zb_convert_cluster_list_to_array",0x9b);
    uStack_28 = uStack_30;
  }
  else {
    __nmemb = 0;
    __src = *(void **)(param_1 + 0x10);
    for (pvVar2 = __src; pvVar2 != (void *)0x0; pvVar2 = *(void **)((int)pvVar2 + 0x10)) {
      if (*(char *)((int)pvVar2 + 8) == '\x01') {
        uStack_30._0_3_ = CONCAT12(uStack_30._2_1_ + '\x01',(undefined2)uStack_30);
      }
      else {
        uStack_30 = CONCAT13(uStack_30._3_1_ + '\x01',(undefined3)uStack_30);
      }
      for (iVar3 = *(int *)((int)pvVar2 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        if ((*(byte *)(iVar3 + 3) & 4) != 0) {
          uStack_30._0_2_ = CONCAT11((char)((uint)uStack_30 >> 8) + '\x01',(char)uStack_30);
        }
      }
      uStack_30 = CONCAT31(uStack_30._1_3_,(char)uStack_30 + '\x01');
      __nmemb = __nmemb + 1 & 0xff;
    }
    if (__nmemb == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_DM_ADAPTER",&_LC8,uVar1,"ESP_ZIGBEE_DM_ADAPTER");
    }
    else {
      pvStack_2c = calloc(__nmemb,0xf);
      if (pvStack_2c == (void *)0x0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC6,uVar1,"ESP_ZIGBEE_DM_ADAPTER",
                      "esp_zb_convert_cluster_list_to_array",0xad);
_L0:
        esp_zb_cluster_array_cleanup(&uStack_30);
      }
      else {
        for (uVar4 = 0; uVar4 < __nmemb; uVar4 = uVar4 + 1 & 0xff) {
          pvVar2 = (void *)((int)pvStack_2c + uVar4 * 0xf);
          memcpy(pvVar2,__src,0xf);
          uVar1 = esp_zb_convert_attr_list_to_array(*(undefined4 *)((int)pvVar2 + 4));
          *(char *)((int)pvVar2 + 4) = (char)uVar1;
          *(char *)((int)pvVar2 + 5) = (char)((uint)uVar1 >> 8);
          *(char *)((int)pvVar2 + 6) = (char)((uint)uVar1 >> 0x10);
          *(char *)((int)pvVar2 + 7) = (char)((uint)uVar1 >> 0x18);
          *(char *)((int)pvVar2 + 2) = (char)extraout_a0;
          *(char *)((int)pvVar2 + 3) = (char)((ushort)extraout_a0 >> 8);
          if (pvStack_2c == (void *)0x0) {
            uVar1 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC7,uVar1,"ESP_ZIGBEE_DM_ADAPTER",
                          "esp_zb_convert_cluster_list_to_array",0xb4);
            goto _L0;
          }
          __src = *(void **)((int)__src + 0x10);
        }
      }
    }
    uStack_28 = uStack_30;
  }
  return uStack_28;
}

