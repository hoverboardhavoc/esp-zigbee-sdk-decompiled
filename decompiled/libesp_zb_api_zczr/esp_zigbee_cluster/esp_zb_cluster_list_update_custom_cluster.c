/*
 * Last changed at upstream commit 3177f0284ed6d95b1f865fe68f364e4b3119ec73
 * https://github.com/espressif/esp-zigbee-sdk/commit/3177f0284ed6d95b1f865fe68f364e4b3119ec73
 * Upstream date: 2022-10-21 18:05:33 +0800
 * Upstream subject: examples: Add gateway uart update rcp
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_update_custom_cluster(int param_1,int param_2,byte param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ushort *__ptr;
  undefined4 local_30;
  uint uStack_28;
  
  puVar3 = (undefined4 *)malloc(0x14);
  uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 8);
  uVar4 = zcl_get_attr_lists(param_2);
  uVar2 = zcl_get_attr_count(param_2);
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  else if (uVar1 < 0xfc00) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC16,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x102;
  }
  else {
    __ptr = *(ushort **)(param_1 + 0x10);
    while (__ptr != (ushort *)0x0) {
      if (*__ptr == uVar1) {
        local_30 = CONCAT22(uVar2,uVar1);
        uStack_28 = (uint)param_3;
        *puVar3 = local_30;
        puVar3[1] = uVar4;
        puVar3[2] = uStack_28;
        *(undefined2 *)(puVar3 + 3) = 0;
        *(undefined1 *)((int)puVar3 + 0xe) = 0;
        puVar3[4] = *(undefined4 *)(__ptr + 8);
        free(__ptr);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
        return 0;
      }
      __ptr = *(ushort **)(__ptr + 8);
      if (__ptr == (ushort *)0x0) break;
      param_1 = *(int *)(param_1 + 0x10);
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER");
    uVar4 = 0x105;
  }
  return uVar4;
}

