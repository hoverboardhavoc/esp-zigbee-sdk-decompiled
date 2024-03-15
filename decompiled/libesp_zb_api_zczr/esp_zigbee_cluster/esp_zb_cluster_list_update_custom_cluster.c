/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_custom_cluster(int param_1,int param_2,byte param_3)

{
  short sVar1;
  undefined2 extraout_a0;
  undefined4 *__ptr;
  int iVar2;
  short *__ptr_00;
  undefined4 uVar3;
  undefined4 uStack_38;
  uint uStack_30;
  
  __ptr = (undefined4 *)malloc(0x14);
  iVar2 = esp_zb_cluster_list_check(param_1,param_2,0x8000);
  if (iVar2 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    uVar3 = zcl_convert_attr_list_to_array(param_2);
    __ptr_00 = *(short **)(param_1 + 0x10);
    while (__ptr_00 != (short *)0x0) {
      if (*__ptr_00 == sVar1) {
        uStack_38 = CONCAT22(extraout_a0,sVar1);
        uStack_30 = (uint)param_3;
        *__ptr = uStack_38;
        __ptr[1] = uVar3;
        __ptr[2] = uStack_30;
        *(undefined2 *)(__ptr + 3) = 0;
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
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CLUSTER",&_LC13,uVar3,"ESP_ZIGBEE_CLUSTER");
    iVar2 = 0x105;
  }
  else {
    free(__ptr);
  }
  return iVar2;
}

