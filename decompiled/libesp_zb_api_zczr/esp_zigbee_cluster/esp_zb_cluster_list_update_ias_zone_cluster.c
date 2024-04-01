/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_ias_zone_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_ias_zone_cluster(int param_1,int param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  undefined2 extraout_a0;
  int iVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  
  sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
  iVar3 = esp_zb_cluster_list_check(0x500);
  if ((iVar3 == 0) && (psVar2 = *(short **)(param_1 + 0x10), psVar2 != (short *)0x0)) {
    while (*psVar2 != sVar1) {
      psVar2 = *(short **)(psVar2 + 8);
      if (psVar2 == (short *)0x0) {
        return 0x105;
      }
      param_1 = *(int *)(param_1 + 0x10);
    }
    puVar4 = (undefined2 *)malloc(0x14);
    if (puVar4 == (undefined2 *)0x0) {
      iVar3 = 0x101;
    }
    else {
      uVar5 = zcl_convert_attr_list_to_array(param_2);
      if (param_3 == 1) {
        puVar6 = &zb_zcl_ias_zone_init_server;
      }
      else if (param_3 == 2) {
        puVar6 = &zb_zcl_ias_zone_init_client;
      }
      else {
        puVar6 = (undefined *)0x0;
      }
      *(undefined4 *)(puVar4 + 2) = uVar5;
      *(char *)(puVar4 + 4) = (char)param_3;
      *(char *)((int)puVar4 + 0xb) = (char)puVar6;
      *(char *)(puVar4 + 6) = (char)((uint)puVar6 >> 8);
      *(undefined1 *)(puVar4 + 7) = 0;
      uVar5 = *(undefined4 *)(psVar2 + 8);
      puVar4[1] = extraout_a0;
      *puVar4 = 0x500;
      *(undefined1 *)((int)puVar4 + 9) = 0;
      *(undefined1 *)(puVar4 + 5) = 0;
      *(char *)((int)puVar4 + 0xd) = (char)((uint)puVar6 >> 0x10);
      *(undefined4 *)(puVar4 + 8) = uVar5;
      *(undefined2 **)(param_1 + 0x10) = puVar4;
      zb_cluster_node_free(psVar2);
    }
  }
  return iVar3;
}

