/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_cluster_list_update_cluster
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
  esp_zb_cluster_list_t *peVar1;
  undefined4 uVar2;
  esp_err_t eVar3;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  void *pvVar4;
  ushort *puVar5;
  
  if (cluster_list != (esp_zb_cluster_list_t *)0x0) {
    cluster_list = cluster_list + -1;
  }
  if (attr_list != (esp_zb_attribute_list_t *)0x0) {
    attr_list = attr_list + -3;
  }
  if (cluster_list == (esp_zb_cluster_list_t *)0x0) {
    uVar2 = 2;
  }
  else if (attr_list == (esp_zb_attribute_list_t *)0x0) {
    uVar2 = 2;
  }
  else if ((uint)*(ushort *)&attr_list->attr_list == CONCAT22(in_register_00002032,cluster_id)) {
    peVar1 = cluster_list + 1;
    pvVar4 = cluster_list[1].cluster_list;
    while (pvVar4 != (void *)0x0) {
      puVar5 = (ushort *)peVar1->cluster_list;
      if (((uint)*puVar5 == CONCAT22(in_register_00002032,cluster_id)) &&
         ((uint)(byte)puVar5[1] == CONCAT31(in_register_00002035,role_mask))) {
        *(ushort *)&attr_list->attr_list = *puVar5;
        *(undefined1 *)((int)&attr_list->attr_list + 2) =
             *(undefined1 *)((int)peVar1->cluster_list + 2);
        *(undefined2 *)&attr_list[1].attr_list = *(undefined2 *)((int)peVar1->cluster_list + 4);
        attr_list[2].attr_list = *(void **)((int)peVar1->cluster_list + 8);
        attr_list[4].attr_list = *(void **)((int)peVar1->cluster_list + 0x10);
        ezb_zcl_free_cluster_desc(peVar1->cluster_list);
        peVar1->cluster_list = attr_list;
        uVar2 = 0;
        goto _L0;
      }
      peVar1 = (esp_zb_cluster_list_t *)(puVar5 + 8);
      pvVar4 = *(void **)(puVar5 + 8);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
_L0:
  eVar3 = esp_zigbee_err_to_esp(uVar2);
  return eVar3;
}

