/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_get_scene_membership_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scenes_cluster_get_scene_membership_req_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  ushort uStack_36;
  ushort uStack_34;
  ushort auStack_32 [7];
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  auStack_32[0] = 0;
  uStack_34 = 0;
  af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_32,&uStack_34);
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 < auStack_32[0]) {
    cVar6 = '\0';
    iVar5 = 0x80;
  }
  else {
    pbVar4 = (byte *)scene_table_get(uVar1);
    if (pbVar4 == (byte *)0x0) {
      cVar6 = '\0';
      iVar5 = 0x8b;
    }
    else {
      cVar6 = *pbVar4 - **(char **)(pbVar4 + 4);
      iVar5 = scenes_check_group_id(uStack_34);
      if (iVar5 == 0) {
        uStack_36._0_1_ = 0;
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
        uStack_36 = CONCAT11(uStack_36._1_1_,cVar6);
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
        uStack_36 = uStack_34;
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_36);
        uStack_36 = uStack_36 & 0xff00;
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
        if (**(char **)(pbVar4 + 4) != '\0') {
          uVar3 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
          uStack_36 = uStack_36 & 0xff00;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
          cVar7 = '\0';
          for (uVar2 = 0; uVar2 < *pbVar4; uVar2 = uVar2 + 1 & 0xff) {
            if (*(ushort *)(pbVar4 + uVar2 * 0x20 + 10) == uStack_34) {
              uStack_36 = CONCAT11(uStack_36._1_1_,pbVar4[uVar2 * 0x20 + 0xc]);
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
              cVar7 = cVar7 + '\x01';
            }
          }
          uStack_36 = CONCAT11(uStack_36._1_1_,cVar7);
          zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),uVar3,1,&uStack_36);
        }
      }
    }
  }
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    if (iVar5 != 0) {
      uStack_36._0_1_ = (char)iVar5;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
      uStack_36 = CONCAT11(uStack_36._1_1_,cVar6);
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
      uStack_36 = uStack_34;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_36);
    }
    uVar3 = zcl_packet_setup_response(param_2,param_1,6);
  }
  else {
    uVar3 = 0xfe;
  }
  return uVar3;
}

