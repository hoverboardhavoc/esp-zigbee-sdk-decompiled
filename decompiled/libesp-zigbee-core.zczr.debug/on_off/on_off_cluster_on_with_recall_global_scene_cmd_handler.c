/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_on_with_recall_global_scene_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_cluster_on_with_recall_global_scene_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  uint unaff_s4;
  uint unaff_s5;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1ba,
                  "on_off_cluster_on_with_recall_global_scene_cmd_handler","packet && rsp");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1be,
                  "on_off_cluster_on_with_recall_global_scene_cmd_handler","ep_desc");
  }
  else {
    unaff_s3 = (uint)*(byte *)(param_1 + 0x15);
    unaff_s5 = (uint)*(byte *)(param_1 + 0x20);
    iVar1 = af_get_ep_desc(unaff_s3);
    if (iVar1 == 0) goto _L0;
    unaff_s2 = on_off_srv_get_attr_desc(unaff_s3,0x4000);
    if (unaff_s2 == 0) {
      unaff_s4 = 0x86;
      goto _L0;
    }
    if (*(byte **)(unaff_s2 + 8) == (byte *)0x0) {
      unaff_s4 = 0x86;
      goto _L0;
    }
    unaff_s4 = (uint)**(byte **)(unaff_s2 + 8);
    if (unaff_s4 != 0) {
      unaff_s4 = 0xfe;
      goto _L0;
    }
  }
  zcl_scenes_recall_scene(param_1,0,0,0);
  **(undefined1 **)(unaff_s2 + 8) = 1;
  on_off_process_transition(unaff_s3,unaff_s5,0,0);
_L0:
  zcl_packet_setup_default_response(param_2,param_1,unaff_s4);
  return;
}

