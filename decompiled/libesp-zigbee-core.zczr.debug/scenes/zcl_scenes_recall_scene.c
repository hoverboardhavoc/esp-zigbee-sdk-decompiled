/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> zcl_scenes_recall_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_recall_scene(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint unaff_s2;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x397,
                  "zcl_scenes_recall_scene","packet");
  }
  else {
    unaff_s2 = (uint)*(byte *)(param_1 + 0x15);
    iVar1 = scenes_check_group_id(param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = scene_table_find_entry(unaff_s2,param_2,param_3);
  if (iVar1 != 0) {
    if (param_4 == 0xffff) {
      param_4 = (uint)*(ushort *)(iVar1 + 6);
    }
    iVar2 = scenes_srv_get_attr_desc(unaff_s2,1);
    iVar3 = scenes_srv_get_attr_desc(unaff_s2,2);
    iVar4 = scenes_srv_get_attr_desc(unaff_s2,3);
    if (((iVar2 != 0) && (iVar3 != 0)) && (iVar4 != 0)) {
      **(undefined1 **)(iVar2 + 8) = (char)param_3;
      **(undefined2 **)(iVar3 + 8) = (short)param_2;
      **(undefined1 **)(iVar4 + 8) = 0;
      iVar1 = zcl_message_scenes_recall_scene(param_1,param_4,iVar1);
      if (iVar1 != 0) {
        return iVar1;
      }
      **(undefined1 **)(iVar4 + 8) = 1;
      return 0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x3a7,
                  "zcl_scenes_recall_scene",
                  "curr_scene_attr_desc && curr_group_attr_desc && scene_valid_attr_desc");
  }
  return 0x8b;
}

