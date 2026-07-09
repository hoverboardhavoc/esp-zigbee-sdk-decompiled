/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_view_scene_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scenes_cluster_view_scene_rsp_handler(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  uint __size;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  char cStack_23;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  cStack_23 = '\0';
  uStack_44 = 0;
  uStack_40 = 0;
  local_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&cStack_23);
  af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_44 + 2);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_40);
  if (cStack_23 == '\0') {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_40 + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&local_3c);
    if (0x11 < (local_3c & 0xff)) {
      uVar1 = 0x80;
      goto _L0;
    }
    af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&local_3c + 1);
    while (auStack_22[0] < uVar2) {
      puVar3 = (undefined4 *)calloc(1,0xc);
      if (puVar3 == (undefined4 *)0x0) {
        uVar1 = 0x89;
        goto _L0;
      }
      *puVar3 = pvStack_28;
      pvStack_28 = puVar3;
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,puVar3 + 1);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)puVar3 + 6);
      __size = (uint)*(byte *)((int)puVar3 + 6);
      if (__size != 0) {
        pvVar4 = calloc(1,__size);
        puVar3[2] = pvVar4;
        if (pvVar4 == (void *)0x0) {
          uVar1 = 0x89;
          goto _L0;
        }
        af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,__size,pvVar4);
      }
    }
  }
  if (uVar2 < auStack_22[0]) {
    uVar1 = 0x80;
  }
  else {
    uVar1 = zcl_message_scenes_view_scene_resp(param_1,cStack_23,&uStack_44);
  }
_L0:
  if (pvStack_28 != (void *)0x0) {
    scene_entry_free_scene_extension_field(&uStack_44);
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

