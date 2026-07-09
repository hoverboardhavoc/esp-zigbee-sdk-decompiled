/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_add_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scenes_cluster_add_scene_req_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  uint unaff_s0;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  uint __size;
  uint unaff_s4;
  undefined1 uVar7;
  int unaff_s6;
  ushort uStack_38;
  undefined1 local_35;
  ushort uStack_34;
  ushort auStack_32 [7];
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  auStack_32[0] = 0;
  uStack_34 = 0;
  local_35 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x278,
                  "scenes_cluster_add_scene_req_handler","packet && rsp");
_L0:
    uVar7 = (undefined1)unaff_s6;
    iVar6 = scene_table_find_entry(uVar1,unaff_s0,local_35);
    if (iVar6 == 0) {
      iVar6 = scene_table_get_unused_entry(uVar1);
    }
    else {
      scene_entry_free_scene_extension_field();
    }
    if (iVar6 == 0) {
      unaff_s6 = 0x89;
    }
    else {
      *(ushort *)(iVar6 + 2) = uStack_34;
      *(undefined1 *)(iVar6 + 4) = local_35;
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_32,iVar6 + 6);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_32,iVar6 + 8);
      if (*(byte *)(iVar6 + 8) < 0x11) {
        af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_32,iVar6 + 9);
        iVar3 = scene_name_is_supported(uVar1);
        if (iVar3 == 0) {
          *(undefined1 *)(iVar6 + 8) = 0;
        }
        while (auStack_32[0] < unaff_s4) {
          puVar4 = (undefined4 *)calloc(1,0xc);
          if (puVar4 == (undefined4 *)0x0) {
            unaff_s6 = 0x89;
            goto _L0;
          }
          *puVar4 = *(undefined4 *)(iVar6 + 0x1c);
          *(undefined4 **)(iVar6 + 0x1c) = puVar4;
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_32,puVar4 + 1);
          af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_32,(int)puVar4 + 6);
          __size = (uint)*(byte *)((int)puVar4 + 6);
          if (__size != 0) {
            pvVar5 = calloc(1,__size);
            puVar4[2] = pvVar5;
            if (pvVar5 == (void *)0x0) {
              unaff_s6 = 0x89;
              goto _L0;
            }
            af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_32,__size,pvVar5);
          }
        }
        if (unaff_s4 < auStack_32[0]) {
          unaff_s6 = 0x80;
        }
        else {
          iVar3 = scene_table_add_entry(uVar1,iVar6,1);
          if (iVar3 != 0) goto _L0;
          unaff_s6 = 1;
        }
      }
      else {
        unaff_s6 = 0x80;
      }
    }
  }
  else {
    unaff_s4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_32,&uStack_34);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_32,&local_35);
    unaff_s0 = (uint)uStack_34;
    unaff_s6 = scenes_check_group_id(unaff_s0);
    if (unaff_s6 == 0) goto _L0;
    iVar6 = 0;
  }
_L0:
  uVar7 = (undefined1)unaff_s6;
  scene_entry_set_unused(iVar6);
_L0:
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    uStack_38 = CONCAT11(uStack_38._1_1_,uVar7);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
    uStack_38 = uStack_34;
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
    uStack_38 = CONCAT11(uStack_38._1_1_,local_35);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
    uVar2 = zcl_packet_setup_response(param_2,param_1,0);
  }
  else {
    uVar2 = 0xfe;
  }
  return uVar2;
}

