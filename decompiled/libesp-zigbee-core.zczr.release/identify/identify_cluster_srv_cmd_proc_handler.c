/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int identify_cluster_srv_cmd_proc_handler(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  uint auStack_5c [3];
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar4 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar4 != 0) {
    return iVar4;
  }
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 == '\x01') {
    uVar2 = *(undefined1 *)(param_1 + 0x15);
    iVar4 = ezb_zcl_is_identifying(uVar2);
    if (iVar4 == 0) {
_L0:
      iVar4 = zmsg_get_length(uStack_24);
      uVar5 = 0;
      if (iVar4 != 0) {
        iVar4 = zcl_packet_setup_response(auStack_48,param_1,0);
        goto _L0;
      }
    }
    else {
      iVar4 = identify_srv_get_attr_desc_constprop_0(uVar2);
      if ((iVar4 == 0) || (*(undefined2 **)(iVar4 + 8) == (undefined2 *)0x0)) {
        uVar5 = 0x86;
      }
      else {
        auStack_5c[0] = CONCAT22(auStack_5c[0]._2_2_,**(undefined2 **)(iVar4 + 8));
        uVar5 = zmsg_append_bytes(uStack_24,2,auStack_5c);
        uVar5 = uVar5 & 0xff;
        if (uVar5 == 0) goto _L0;
      }
    }
  }
  else if (cVar1 == '@') {
    uStack_5e = 0;
    uStack_5d = 0;
    iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,&uStack_5e);
    if (iVar4 == 0) {
      iVar4 = 0xffff;
    }
    iVar7 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),iVar4,1,&uStack_5d);
    if (iVar7 == 0) {
      uVar6 = 0xffff;
    }
    else {
      uVar6 = iVar7 + iVar4 & 0xffff;
    }
    uVar8 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar3 = uStack_5d;
    uVar2 = uStack_5e;
    uVar5 = 0x80;
    if (uVar6 <= uVar8) {
      auStack_5c[0] = 0;
      auStack_5c[1] = 0;
      auStack_5c[2] = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      iVar4 = zcl_packet_to_message(auStack_5c,param_1,0x80);
      if (iVar4 == 0) {
        uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
        uStack_50._0_2_ = CONCAT11(uVar3,uVar2);
        auStack_5c[2] = param_1;
        zcl_core_action_schedule(0xb,auStack_5c);
        uVar5 = uStack_4c & 0xff;
        if (uVar5 != 0xfe) goto _L0;
      }
      uVar5 = 0;
    }
  }
  else if (cVar1 == '\0') {
    uVar2 = *(undefined1 *)(param_1 + 0x15);
    auStack_5c[0] = auStack_5c[0] & 0xffff0000;
    uVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,auStack_5c);
    if (uVar5 == 0) {
      uVar5 = 0xffff;
    }
    uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar6 < uVar5) {
      uVar5 = 0x80;
    }
    else {
      iVar4 = identify_srv_get_attr_desc_constprop_0(uVar2);
      iVar7 = identify_srv_get_attr_desc_part_0(uVar2);
      if (iVar7 == 0) {
        __assert_func(0,0,0);
      }
      if ((iVar4 == 0) || (*(int *)(iVar4 + 8) == 0)) {
        uVar5 = 0x86;
      }
      else {
        zcl_message_set_identify_attr_value_isra_0(uVar2,auStack_5c[0] & 0xffff);
        uVar5 = 0;
      }
    }
  }
  else {
    uVar5 = 0x81;
  }
_L0:
  iVar4 = zcl_packet_setup_default_response(auStack_48,param_1,uVar5);
_L0:
  if (iVar4 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar4;
}

