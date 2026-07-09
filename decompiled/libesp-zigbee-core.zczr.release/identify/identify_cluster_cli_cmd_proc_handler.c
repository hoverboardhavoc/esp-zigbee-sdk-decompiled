/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int identify_cluster_cli_cmd_proc_handler(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [44];
  
  memset(auStack_38,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(auStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (*(char *)(param_1 + 0x20) != '\0') {
    iVar2 = 0x81;
    goto _L0;
  }
  uStack_4e = 0;
  uVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,&uStack_4e);
  if (uVar3 == 0) {
    uVar3 = 0xffff;
  }
  uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  uVar1 = uStack_4e;
  if (uVar4 < uVar3) {
    iVar2 = 0x80;
    goto _L0;
  }
  uStack_4c = 0;
  uStack_48 = 0;
  iStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  iVar2 = zcl_packet_to_message(&uStack_4c,param_1);
  if (iVar2 == 0) {
    uStack_3c = CONCAT31(uStack_3c._1_3_,0xfe);
    uStack_40 = CONCAT22(uStack_40._2_2_,uVar1);
    iStack_44 = param_1;
    zcl_core_action_schedule(10,&uStack_4c);
    uVar3 = uStack_3c & 0xff;
    if (uVar3 == 0xfe) goto _L0;
  }
  else {
_L0:
    uVar3 = 0;
  }
  iVar2 = zcl_packet_setup_default_response(auStack_38,param_1,uVar3);
  if (iVar2 == 0) {
    zcl_packet_send(auStack_38,0);
    return 0;
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar2;
}

