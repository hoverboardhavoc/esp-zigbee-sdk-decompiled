/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_remove_all_groups_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 groups_cluster_remove_all_groups_cmd_handler(int param_1,int param_2)

{
  undefined2 *unaff_s0;
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = zcl_get_cluster_desc(*(undefined1 *)(param_1 + 0x15),5,1);
    if (iVar1 != 0) {
      unaff_s0 = (undefined2 *)0x0;
      while (unaff_s0 = (undefined2 *)
                        aps_group_table_next_by_endpoint(*(undefined1 *)(param_1 + 0x15),unaff_s0),
            unaff_s0 != (undefined2 *)0x0) {
_L0:
        zcl_scenes_remove_all_associated_scene(*(undefined1 *)(param_1 + 0x15),*unaff_s0);
      }
    }
    aps_group_table_clear();
    if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
      uVar2 = zcl_packet_setup_default_response(param_2,param_1,0);
    }
    else {
      uVar2 = 0xfe;
    }
    return uVar2;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x216,
                "groups_cluster_remove_all_groups_cmd_handler","packet && rsp");
  goto _L0;
}

