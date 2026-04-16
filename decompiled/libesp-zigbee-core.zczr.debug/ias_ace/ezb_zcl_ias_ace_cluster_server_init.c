/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_ias_ace_cluster_server_init(uint8_t ep_id)

{
  ezb_err_t eVar1;
  int iVar2;
  ias_ace_zone_table_t *zone_table;
  ezb_zcl_ias_ace_zone_table_ent_t *peVar3;
  uint8_t *__src;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x10501;
  template.cluster_id = 0;
  template.cluster_role = '\0';
  template._3_1_ = 0;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = ias_ace_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = ias_ace_cluster_srv_cmd_proc_handler;
  eVar1 = zone_table_init(ep_id);
  if (eVar1 == 0) {
    zone_table_restore(ep_id);
    iVar2 = zcl_cluster_template_add(&uStack_24);
    if (iVar2 == 0) {
      return;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x374,
                  "ezb_zcl_ias_ace_cluster_server_init","zone_table_init(ep_id) == 0");
  }
  zone_table = (ias_ace_zone_table_t *)
               __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x376,
                             "ezb_zcl_ias_ace_cluster_server_init",
                             "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  if ((((zone_table != (ias_ace_zone_table_t *)0x0) && (__src != (uint8_t *)0x0)) &&
      (*__src != 0xff)) && (*(short *)(__src + 2) != -1)) {
    if (((*(int *)(__src + 4) != 0 || *(int *)(__src + 8) != 0) &&
        ((*(int *)(__src + 4) != -1 || (*(int *)(__src + 8) != -1)))) &&
       (peVar3 = ias_ace_zone_table_get_zone(zone_table,*__src),
       peVar3 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0)) {
      for (iVar2 = 0; iVar2 < (int)(uint)zone_table->table_size; iVar2 = iVar2 + 1) {
        peVar3 = zone_table->zone_entries + iVar2;
        if (peVar3->zone_type == 0xffff) {
          memcpy(peVar3,__src,0x1e);
          zone_table_store_zone(zone_table->ep_id,peVar3);
          return;
        }
      }
    }
  }
  return;
}

