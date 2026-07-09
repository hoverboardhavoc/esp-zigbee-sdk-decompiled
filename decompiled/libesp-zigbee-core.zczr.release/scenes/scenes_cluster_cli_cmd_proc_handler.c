/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scenes_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int scenes_cluster_cli_cmd_proc_handler(uint param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  uint __nmemb;
  char cStack_77;
  ushort uStack_76;
  ushort auStack_74 [4];
  uint uStack_6c;
  char cStack_68;
  undefined2 uStack_66;
  undefined1 uStack_64;
  undefined2 uStack_62;
  void *pvStack_60;
  byte bStack_5c;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined1 auStack_54 [2];
  undefined2 uStack_52;
  undefined4 local_50;
  char cStack_4c;
  undefined1 uStack_4b;
  undefined1 auStack_4a [2];
  byte local_48 [4];
  void *pvStack_44;
  byte bStack_40;
  void *pvStack_3c;
  undefined1 auStack_38 [40];
  
  memset(auStack_38,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 4) {
    iVar3 = scenes_cluster_remove_scene_rsp_handler(param_1,auStack_38);
    goto _L0;
  }
  if (bVar1 < 5) {
    if (bVar1 == 2) {
      iVar3 = scenes_cluster_remove_scene_rsp_handler(param_1,auStack_38);
      goto _L0;
    }
    if (bVar1 != 3) {
      if (bVar1 != 0) goto _L0;
      goto _L0;
    }
    auStack_74[0] = 0;
    uStack_76 = uStack_76 & 0xff00;
    uStack_58 = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,&uStack_76);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,&uStack_58);
    uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar4 = 0x80;
    if (auStack_74[0] <= uVar7) {
      uVar4 = zcl_message_scenes_op_scene_resp(param_1,(undefined1)uStack_76,uStack_58,0);
    }
  }
  else {
    if (bVar1 == 0x40) {
_L0:
      iVar3 = scenes_cluster_remove_scene_rsp_handler(param_1,auStack_38);
      goto _L0;
    }
    if (bVar1 != 0x41) {
      if (bVar1 != 6) {
        uVar4 = 0x81;
        goto _L0;
      }
      auStack_74[0] = 0;
      memset(&uStack_58,0,0x1c);
      uVar4 = zcl_packet_to_message(&uStack_58,param_1);
      if (uVar4 == 0) {
        uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        local_50 = param_1;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,&cStack_4c);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,&uStack_4b);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,auStack_4a);
        if ((cStack_4c == '\0') && (auStack_74[0] < uVar7)) {
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,local_48);
          __nmemb = (uint)local_48[0];
          if (__nmemb != 0) {
            pvStack_44 = calloc(__nmemb,1);
            if (pvStack_44 == (void *)0x0) {
              uVar4 = 0x89;
              goto _L0;
            }
            af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_74,__nmemb,pvStack_44);
          }
        }
        if (uVar7 < auStack_74[0]) {
          uVar4 = 0x80;
        }
        else {
          bStack_40 = 0xfe;
          zcl_core_action_schedule(0x14,&uStack_58);
          if (bStack_40 != 0xfe) {
            uVar4 = (uint)bStack_40;
          }
        }
      }
_L0:
      if (pvStack_44 != (void *)0x0) {
        mm_free();
      }
      goto _L0;
    }
_L0:
    uStack_76 = 0;
    cStack_77 = '\0';
    memset(&uStack_58,0,0x20);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&cStack_77);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_56);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,auStack_54);
    if (cStack_77 == '\0') {
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_52);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&local_50);
      uVar7 = local_50 & 0xff;
      if (0x11 < uVar7) goto _L0;
      pvVar6 = (void *)((int)&local_50 + 1);
      do {
        af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,uVar7,pvVar6);
        do {
          if (uVar4 <= uStack_76) goto _L0;
          puVar5 = (undefined4 *)calloc(1,0xc);
          if (puVar5 == (undefined4 *)0x0) goto _L0;
          *puVar5 = pvStack_3c;
          pvStack_3c = puVar5;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,puVar5 + 1);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,(int)puVar5 + 6);
          uVar7 = (uint)*(byte *)((int)puVar5 + 6);
        } while (uVar7 == 0);
        pvVar6 = calloc(1,uVar7);
        puVar5[2] = pvVar6;
      } while (pvVar6 != (void *)0x0);
_L0:
      uVar4 = 0x89;
    }
    else {
_L0:
      cVar2 = cStack_77;
      if (uVar4 < uStack_76) {
_L0:
        uVar4 = 0x80;
      }
      else {
        memset(auStack_74,0,0x1c);
        uVar4 = zcl_packet_to_message(auStack_74,param_1);
        if (uVar4 == 0) {
          uStack_66 = uStack_56;
          cStack_68 = cVar2;
          uStack_64 = auStack_54[0];
          uStack_62 = uStack_52;
          pvStack_60 = pvStack_3c;
          bStack_5c = 0xfe;
          uStack_6c = param_1;
          zcl_core_action_schedule(0x13,auStack_74);
          if (bStack_5c != 0xfe) {
            uVar4 = (uint)bStack_5c;
          }
        }
      }
    }
    if (pvStack_3c != (void *)0x0) {
      scene_entry_free_scene_extension_field(&uStack_58);
    }
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_38,param_1,uVar4);
_L0:
  if (iVar3 == 0) {
    zcl_packet_send(auStack_38,0);
  }
  else {
    zcl_packet_free(auStack_38);
  }
  return iVar3;
}

