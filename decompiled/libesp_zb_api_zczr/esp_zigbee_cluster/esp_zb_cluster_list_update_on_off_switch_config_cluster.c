/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_on_off_switch_config_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_cluster_list_update_on_off_switch_config_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 extraout_a0;
  undefined4 *puVar2;
  short *__ptr;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 uStack_38;
  uint3 uStack_30;
  undefined1 uStack_2d;
  undefined2 uStack_2c;
  
  puVar2 = (undefined4 *)malloc(0x14);
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
  uVar3 = zcl_convert_attr_list_to_array(param_2);
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC2,uVar3,"ESP_ZIGBEE_CLUSTER");
    uVar3 = 0x102;
  }
  else if (sVar1 == 7) {
    __ptr = *(short **)(param_1 + 0x10);
    while (__ptr != (short *)0x0) {
      if (*__ptr == 7) {
        uStack_38 = CONCAT22(extraout_a0,7);
        if (param_3 == 1) {
          puVar4 = &zb_zcl_on_off_switch_config_init_server;
        }
        else if (param_3 == 2) {
          puVar4 = &zb_zcl_on_off_switch_config_init_client;
        }
        else {
          puVar4 = (undefined *)0x0;
        }
        _uStack_30 = CONCAT13((char)puVar4,(uint3)(byte)param_3);
        uStack_2c = (undefined2)((uint)puVar4 >> 8);
        *puVar2 = uStack_38;
        puVar2[1] = uVar3;
        puVar2[2] = _uStack_30;
        *(undefined2 *)(puVar2 + 3) = uStack_2c;
        *(undefined1 *)((int)puVar2 + 0xe) = 0;
        puVar2[4] = *(undefined4 *)(__ptr + 8);
        free(__ptr);
        *(undefined4 **)(param_1 + 0x10) = puVar2;
        return 0;
      }
      __ptr = *(short **)(__ptr + 8);
      if (__ptr == (short *)0x0) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CLUSTER",&_LC13,uVar3,"ESP_ZIGBEE_CLUSTER");
    uVar3 = 0x105;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC14,uVar3,"ESP_ZIGBEE_CLUSTER");
    uVar3 = 0x102;
  }
  return uVar3;
}

