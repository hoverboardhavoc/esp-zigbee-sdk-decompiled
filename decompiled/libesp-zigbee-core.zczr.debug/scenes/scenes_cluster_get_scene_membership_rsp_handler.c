/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_get_scene_membership_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scenes_cluster_get_scene_membership_rsp_handler(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint __nmemb;
  undefined4 local_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  void *pvStack_2c;
  uint uStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  local_40 = 0;
  uStack_3c = 0;
  iStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  pvStack_2c = (void *)0x0;
  uStack_28 = 0;
  uVar1 = zcl_packet_to_message(&local_40,param_1);
  if (uVar1 == 0) {
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    iStack_38 = param_1;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 1);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 2);
    if (((char)uStack_34 == '\0') && (auStack_22[0] < uVar2)) {
      af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
      __nmemb = uStack_30 & 0xff;
      if (__nmemb != 0) {
        pvStack_2c = calloc(__nmemb,1);
        if (pvStack_2c == (void *)0x0) {
          uVar1 = 0x89;
          goto _L0;
        }
        af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,__nmemb,pvStack_2c);
      }
    }
    if (uVar2 < auStack_22[0]) {
      uVar1 = 0x80;
    }
    else {
      uStack_28 = CONCAT31(uStack_28._1_3_,0xfe);
      zcl_core_action_schedule(0x14,&local_40);
      if ((uStack_28 & 0xff) != 0xfe) {
        uVar1 = uStack_28 & 0xff;
      }
    }
  }
_L0:
  if (pvStack_2c != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

