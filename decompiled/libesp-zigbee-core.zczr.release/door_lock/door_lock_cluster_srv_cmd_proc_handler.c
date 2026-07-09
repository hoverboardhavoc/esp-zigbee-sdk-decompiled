/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> door_lock_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int door_lock_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  byte abStack_5c [3];
  undefined1 uStack_59;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [32];
  char cStack_28;
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  abStack_5c[0] = 0;
  if (param_1 == 0) {
    return 1;
  }
  bVar1 = *(byte *)(param_1 + 0x1a) >> 3;
  bVar6 = (bool)(bVar1 & 1);
  if ((bVar1 & 1) != 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = ezb_zcl_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x101,1,0x34,0);
  if (iVar2 == 0) {
_L0:
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
    if ((**(char **)(iVar2 + 8) != '\0') && (iVar5 = 2, **(char **)(iVar2 + 8) != '\x01')) {
      __assert_func(0,0,0,0);
      goto _L0;
    }
  }
  iVar2 = zcl_packet_get_security(param_1);
  if (iVar2 < iVar5) {
    return 0xfe;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    uStack_58 = 0;
    uStack_54 = 0;
    iStack_50 = 0;
    uStack_4c = 0;
    uVar3 = zcl_packet_to_message(&uStack_58,param_1);
    if (uVar3 == 0) {
      uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
      iStack_50 = param_1;
      zcl_core_action_schedule(0x17,&uStack_58);
      uStack_59 = (char)uStack_4c != '\0';
      uVar3 = zmsg_append_bytes(uStack_24,1,&uStack_59);
      uVar3 = uVar3 & 0xff;
      uVar4 = 0;
      if (uVar3 == 0) {
_L70:
        uVar3 = zcl_packet_setup_response(auStack_48,param_1,uVar4);
        if (uVar3 == 0) goto _L0;
      }
    }
  }
  else if (*(char *)(param_1 + 0x20) == '\x01') {
    uStack_58 = 0;
    uStack_54 = 0;
    iStack_50 = 0;
    uStack_4c = 0;
    uVar3 = zcl_packet_to_message(&uStack_58,param_1);
    if (uVar3 == 0) {
      uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
      iStack_50 = param_1;
      zcl_core_action_schedule(0x18,&uStack_58);
      uStack_59 = (char)uStack_4c != '\0';
      uVar3 = zmsg_append_bytes(uStack_24,1,&uStack_59);
      uVar3 = uVar3 & 0xff;
      if (uVar3 == 0) {
        uVar4 = 1;
        goto _L70;
      }
    }
  }
  else {
    uVar3 = 0x81;
  }
  iVar2 = zcl_packet_setup_default_response(auStack_48,param_1,uVar3);
  if (iVar2 != 0) {
    zcl_packet_free(auStack_48);
    return iVar2;
  }
_L0:
  if (cStack_28 != '\v') {
    iVar2 = zcl_packet_get_security(param_1);
    bVar6 = iVar2 == 2;
  }
  abStack_5c[0] = abStack_5c[0] & 0xfe | bVar6;
  zcl_packet_send_with_ext(auStack_48,0,abStack_5c);
  return 0;
}

