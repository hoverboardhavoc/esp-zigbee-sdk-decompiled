/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_off_with_effect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_cluster_off_with_effect_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint unaff_s3;
  uint unaff_s4;
  ushort uStack_24;
  undefined1 local_22;
  undefined1 auStack_21 [9];
  
  auStack_21[0] = 0;
  local_22 = 0;
  uStack_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x18e,
                  "on_off_cluster_off_with_effect_cmd_handler","packet && rsp");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x192,
                  "on_off_cluster_off_with_effect_cmd_handler","ep_desc");
  }
  else {
    unaff_s3 = (uint)*(byte *)(param_1 + 0x15);
    unaff_s4 = (uint)*(byte *)(param_1 + 0x20);
    iVar1 = af_get_ep_desc(unaff_s3);
    if (iVar1 == 0) goto _L0;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_24,auStack_21);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_24,&local_22);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar2 < uStack_24) {
      iVar1 = 0x80;
      goto _L0;
    }
  }
  iVar1 = on_off_srv_get_attr_desc(unaff_s3,0x4000);
  if ((iVar1 != 0) && (**(char **)(iVar1 + 8) != '\0')) {
    zcl_message_scenes_store_scene(unaff_s3,0,0);
    **(undefined1 **)(iVar1 + 8) = 0;
  }
  iVar1 = zcl_message_on_off_with_off_effect(param_1,auStack_21[0],local_22);
  if (iVar1 == 0) {
    on_off_process_transition(*(undefined1 *)(param_1 + 0x15),unaff_s4,0,0,0);
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar1);
  return;
}

