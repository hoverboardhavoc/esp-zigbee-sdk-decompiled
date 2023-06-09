/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_pressure_meas_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_pressure_meas_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  short *__ptr_00;
  undefined4 local_30;
  uint3 uStack_28;
  undefined1 uStack_25;
  undefined2 uStack_24;
  
  __ptr = (undefined4 *)malloc(0x14);
  iVar3 = esp_zb_cluster_list_check(param_1,param_2,0x403);
  if (iVar3 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    uVar4 = zcl_get_attr_lists(param_2);
    uVar2 = zcl_get_attr_count(param_2);
    __ptr_00 = *(short **)(param_1 + 0x10);
    while (__ptr_00 != (short *)0x0) {
      if (*__ptr_00 == sVar1) {
        local_30 = CONCAT22(uVar2,0x403);
        if (param_3 == 1) {
          puVar5 = &zb_zcl_pressure_measurement_init_server;
        }
        else if (param_3 == 2) {
          puVar5 = &zb_zcl_pressure_measurement_init_client;
        }
        else {
          puVar5 = (undefined *)0x0;
        }
        _uStack_28 = CONCAT13((char)puVar5,(uint3)(byte)param_3);
        uStack_24 = (undefined2)((uint)puVar5 >> 8);
        *__ptr = local_30;
        __ptr[1] = uVar4;
        __ptr[2] = _uStack_28;
        *(undefined2 *)(__ptr + 3) = uStack_24;
        *(undefined1 *)((int)__ptr + 0xe) = 0;
        __ptr[4] = *(undefined4 *)(__ptr_00 + 8);
        free(__ptr_00);
        *(undefined4 **)(param_1 + 0x10) = __ptr;
        return 0;
      }
      __ptr_00 = *(short **)(__ptr_00 + 8);
      if (__ptr_00 == (short *)0x0) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CLUSTER",&_LC11,uVar4,"ESP_ZIGBEE_CLUSTER");
    iVar3 = 0x105;
  }
  else {
    free(__ptr);
  }
  return iVar3;
}

