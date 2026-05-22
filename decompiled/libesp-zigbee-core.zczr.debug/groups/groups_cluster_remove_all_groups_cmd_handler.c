/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_remove_all_groups_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
groups_cluster_remove_all_groups_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  undefined2 *unaff_s0;
  ezb_zcl_status_t eVar1;
  int iVar2;
  
  if ((packet != (zcl_packet_t *)0x0) && (rsp != (zcl_packet_t *)0x0)) {
    iVar2 = zcl_get_cluster_desc((packet->header).dst_ep,5,1);
    if (iVar2 != 0) {
      unaff_s0 = (undefined2 *)0x0;
      while (unaff_s0 = (undefined2 *)
                        aps_group_table_next_by_endpoint((packet->header).dst_ep,unaff_s0),
            unaff_s0 != (undefined2 *)0x0) {
_L0:
        zcl_scenes_remove_all_associated_scene((packet->header).dst_ep,*unaff_s0);
      }
    }
    aps_group_table_clear();
    if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
      eVar1 = zcl_packet_setup_default_response(rsp,packet,0);
    }
    else {
      eVar1 = 0xfe;
    }
    return eVar1;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x216,
                "groups_cluster_remove_all_groups_cmd_handler","packet && rsp");
  goto _L0;
}

