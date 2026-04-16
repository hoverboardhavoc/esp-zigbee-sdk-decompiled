/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_cluster_list_update_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_cluster_list_update_cluster
                    (esp_zb_cluster_list_t *cluster_list,esp_zb_attribute_list_t *attr_list,
                    uint16_t cluster_id,uint8_t role_mask)

{
  undefined4 uVar1;
  esp_err_t eVar2;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  void *pvVar3;
  ushort *puVar4;
  
  if (cluster_list == (esp_zb_cluster_list_t *)0x0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 2;
    if ((attr_list != (esp_zb_attribute_list_t *)0x0) &&
       ((uint)*(ushort *)&attr_list[-3].attr_list == CONCAT22(in_register_00002032,cluster_id))) {
      pvVar3 = cluster_list->cluster_list;
      while (pvVar3 != (void *)0x0) {
        puVar4 = (ushort *)cluster_list->cluster_list;
        if (((uint)*puVar4 == CONCAT22(in_register_00002032,cluster_id)) &&
           ((uint)(byte)puVar4[1] == CONCAT31(in_register_00002035,role_mask))) {
          *(uint8_t *)((int)&attr_list[-3].attr_list + 2) = role_mask;
          pvVar3 = *(void **)(puVar4 + 4);
          *(ushort *)&attr_list[-2].attr_list = puVar4[2];
          attr_list[-1].attr_list = pvVar3;
          attr_list[1].attr_list = *(void **)((int)cluster_list->cluster_list + 0x10);
          ezb_zcl_free_cluster_desc(cluster_list->cluster_list);
          cluster_list->cluster_list = attr_list + -3;
          break;
        }
        cluster_list = (esp_zb_cluster_list_t *)(puVar4 + 8);
        pvVar3 = *(void **)(puVar4 + 8);
      }
      uVar1 = 0;
    }
  }
  eVar2 = esp_zigbee_err_to_esp(uVar1);
  return eVar2;
}

