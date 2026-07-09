/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int on_off_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 uVar9;
  bool bVar10;
  uint uVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  undefined1 uStack_61;
  undefined1 uStack_60;
  byte bStack_5f;
  ushort uStack_5e;
  uint auStack_5c [3];
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [48];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar5 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar5 != 0) {
    return iVar5;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  uVar4 = 0;
  if (bVar1 == 0x40) {
    uVar9 = *(undefined1 *)(param_1 + 0x15);
    uStack_61 = 0;
    uStack_60 = 0;
    iVar5 = af_get_ep_desc(uVar9);
    if (iVar5 == 0) goto _L133;
    iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,1,&uStack_61);
    if (iVar5 == 0) {
      iVar5 = 0xffff;
    }
    iVar6 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),iVar5,1,&uStack_60);
    if (iVar6 == 0) {
      uVar14 = 0xffff;
    }
    else {
      uVar14 = iVar6 + iVar5 & 0xffff;
    }
    uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar11 = 0x80;
    if (uVar14 <= uVar7) {
      iVar5 = on_off_srv_get_attr_desc(uVar9,0x4000,0x80);
      if ((iVar5 != 0) && (**(char **)(iVar5 + 8) != '\0')) {
        zcl_message_scenes_store_scene(uVar9,0,0);
        **(undefined1 **)(iVar5 + 8) = 0;
      }
      uVar9 = uStack_60;
      uVar4 = uStack_61;
      auStack_5c[0] = 0;
      auStack_5c[1] = 0;
      auStack_5c[2] = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uVar11 = zcl_packet_to_message(auStack_5c,param_1);
      if (uVar11 == 0) {
        uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
        uStack_50._0_2_ = CONCAT11(uVar9,uVar4);
        auStack_5c[2] = param_1;
        zcl_core_action_schedule(0xd,auStack_5c,0);
        uVar11 = uStack_4c & 0xff;
        if ((uVar11 == 0xfe) || (uVar11 == 0)) {
          bVar10 = false;
          uVar9 = 0x40;
          goto _L0;
        }
      }
    }
    goto _L0;
  }
  if (bVar1 < 0x41) {
    if (bVar1 == 1) {
      uVar9 = 1;
      bVar10 = true;
_L0:
      uVar4 = *(undefined1 *)(param_1 + 0x15);
    }
    else {
      if (bVar1 != 2) {
        if (bVar1 != 0) goto _L0;
        bVar10 = false;
        uVar9 = 0;
        goto _L0;
      }
      uVar4 = *(undefined1 *)(param_1 + 0x15);
      iVar5 = on_off_srv_get_attr_desc(uVar4,0);
      if (iVar5 == 0) goto _L133;
_L0:
      bVar10 = **(char **)(iVar5 + 8) == '\0';
      uVar9 = bVar10;
    }
    on_off_process_transition(uVar4,uVar9,bVar10,0,0);
    uVar11 = 0;
_L0:
    iVar5 = zcl_packet_setup_default_response(auStack_48,param_1,uVar11);
  }
  else {
    if (bVar1 == 0x41) {
      uVar9 = *(undefined1 *)(param_1 + 0x15);
      iVar5 = af_get_ep_desc(uVar9);
      if (iVar5 == 0) goto _L133;
      iVar5 = on_off_srv_get_attr_desc(uVar9,0x4000);
      uVar11 = 0x86;
      if ((iVar5 != 0) && (*(char **)(iVar5 + 8) != (char *)0x0)) {
        if (**(char **)(iVar5 + 8) == '\0') {
          zcl_scenes_recall_scene(param_1,0,0,0);
          **(undefined1 **)(iVar5 + 8) = 1;
          on_off_process_transition(uVar9,0x41,0,0);
          uVar11 = 0;
        }
        else {
          uVar11 = 0xfe;
        }
      }
      goto _L0;
    }
    if (bVar1 != 0x42) {
_L0:
      uVar11 = 0x81;
      goto _L0;
    }
    uVar9 = *(undefined1 *)(param_1 + 0x15);
    bStack_5f = 0;
    uStack_5e = 0;
    auStack_5c[0] = auStack_5c[0] & 0xffff0000;
    iVar5 = af_get_ep_desc(uVar9);
    if (iVar5 == 0) {
_L133:
      iVar5 = __assert_func(0,0,0,0);
      goto _L0;
    }
    iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,1,&bStack_5f);
    if (iVar5 == 0) {
      iVar5 = 0xffff;
    }
    iVar6 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),iVar5,2,&uStack_5e);
    if (iVar6 == 0) {
      uVar14 = 0xffff;
    }
    else {
      uVar14 = iVar5 + iVar6 & 0xffff;
    }
    iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar14,2,auStack_5c);
    if (iVar5 == 0) {
      uVar14 = 0xffff;
    }
    else {
      uVar14 = uVar14 + iVar5 & 0xffff;
    }
    uVar11 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar11 < uVar14) {
      iVar5 = 0x80;
      goto _L0;
    }
    iVar5 = on_off_srv_get_attr_desc(uVar9,0);
    iVar6 = on_off_srv_get_attr_desc(uVar9,0x4001);
    iVar8 = on_off_srv_get_attr_desc(uVar9,0x4002);
    if (iVar5 == 0) goto _L133;
    if ((iVar6 == 0) || (iVar8 == 0)) {
      uVar11 = 0x8c;
      goto _L0;
    }
    cVar2 = '\0';
    if (*(char **)(iVar5 + 8) != (char *)0x0) {
      cVar2 = **(char **)(iVar5 + 8);
    }
    uVar13 = 0;
    if (*(ushort **)(iVar6 + 8) != (ushort *)0x0) {
      uVar13 = **(ushort **)(iVar6 + 8);
    }
    uVar14 = 0;
    if (*(ushort **)(iVar8 + 8) != (ushort *)0x0) {
      uVar14 = (uint)**(ushort **)(iVar8 + 8);
    }
    if ((bStack_5f & 1) == 0) {
      if ((uVar14 == 0) || (cVar2 != '\0')) goto _L0;
      uVar11 = auStack_5c[0] & 0xffff;
      if (uVar14 < (auStack_5c[0] & 0xffff)) {
        uVar11 = uVar14;
      }
      uVar12 = 0;
      uVar3 = 0;
    }
    else {
      if (cVar2 == '\0') {
        iVar5 = 0xfe;
        goto _L0;
      }
_L0:
      uVar12 = uStack_5e;
      if (uStack_5e < uVar13) {
        uVar12 = uVar13;
      }
      uVar11 = auStack_5c[0] & 0xffff;
      uVar3 = 1;
    }
    on_off_process_transition(uVar9,0x42,uVar3,uVar12,uVar11);
    iVar5 = zcl_packet_setup_default_response(auStack_48,param_1,0);
    if ((uStack_5e != 0xffff) && ((auStack_5c[0] & 0xffff) != 0xffff)) {
      on_off_timer_start_constprop_0(uVar9);
    }
  }
  if (iVar5 == 0) {
    zcl_packet_send(auStack_48,0);
    return 0;
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar5;
}

