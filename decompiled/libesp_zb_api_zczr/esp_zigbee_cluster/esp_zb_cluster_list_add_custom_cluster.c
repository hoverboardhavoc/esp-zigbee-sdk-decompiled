/*
 * Last changed at upstream commit 3177f0284ed6d95b1f865fe68f364e4b3119ec73
 * https://github.com/espressif/esp-zigbee-sdk/commit/3177f0284ed6d95b1f865fe68f364e4b3119ec73
 * Upstream date: 2022-10-21 18:05:33 +0800
 * Upstream subject: examples: Add gateway uart update rcp
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_add_custom_cluster(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_30;
  uint uStack_28;
  
  puVar5 = (undefined4 *)malloc(0x14);
  uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 8);
  if (param_1 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar6,"ESP_ZIGBEE_CLUSTER");
    uVar6 = 0x102;
  }
  else if (uVar1 < 0xfc00) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC16,uVar6,"ESP_ZIGBEE_CLUSTER");
    uVar6 = 0x102;
  }
  else {
    puVar2 = *(ushort **)(param_1 + 0x10);
    do {
      puVar3 = puVar2;
      if (puVar3 == (ushort *)0x0) break;
      if (*puVar3 == uVar1 && (byte)puVar3[4] == param_3) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC5,uVar6,"ESP_ZIGBEE_CLUSTER",uVar1);
        return 0x102;
      }
      puVar2 = *(ushort **)(puVar3 + 8);
    } while (*(ushort **)(puVar3 + 8) != (ushort *)0x0);
    uVar6 = zcl_get_attr_lists(param_2);
    uVar4 = zcl_get_attr_count(param_2);
    local_30 = CONCAT22(uVar4,uVar1);
    uStack_28 = param_3 & 0xff;
    *puVar5 = local_30;
    puVar5[1] = uVar6;
    puVar5[2] = uStack_28;
    *(undefined2 *)(puVar5 + 3) = 0;
    *(undefined1 *)((int)puVar5 + 0xe) = 0;
    puVar5[4] = 0;
    if (puVar3 == (ushort *)0x0) {
      *(undefined4 **)(param_1 + 0x10) = puVar5;
      uVar6 = 0;
    }
    else {
      *(undefined4 **)(puVar3 + 8) = puVar5;
      uVar6 = 0;
    }
  }
  return uVar6;
}

