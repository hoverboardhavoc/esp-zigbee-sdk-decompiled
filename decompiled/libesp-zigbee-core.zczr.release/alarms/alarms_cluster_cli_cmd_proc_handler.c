/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarms_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int alarms_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uStack_64;
  ushort uStack_52;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  byte bStack_3c;
  undefined1 auStack_38 [44];
  
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
  if (*(char *)(param_1 + 0x20) == '\0') {
    uStack_50 = 0;
    uStack_4c = 0;
    iStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_52 = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&uStack_44);
    uVar2 = (uint)uStack_52;
    iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar2,2,(int)&uStack_44 + 2);
    if (iVar3 == 0) {
      uVar2 = 0xffff;
    }
    else {
      uVar2 = uVar2 + iVar3 & 0xffff;
    }
    uStack_52 = (ushort)uVar2;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uStack_64 = 0x80;
    if ((uVar4 < uVar2) ||
       (uStack_64 = zcl_packet_to_message(&uStack_50,param_1,0x80), uStack_64 != 0)) goto _L0;
    uStack_40 = CONCAT31(uStack_40._1_3_,0xfe);
    iStack_48 = param_1;
    zcl_core_action_schedule(0x34,&uStack_50,0);
    bVar1 = (byte)uStack_40;
  }
  else {
    uStack_64 = 0x81;
    if (*(char *)(param_1 + 0x20) != '\x01') goto _L0;
    memset(&uStack_50,0,0x18);
    uStack_52 = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&uStack_44);
    if ((uStack_44 & 0xff) == 0) {
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,(int)&uStack_44 + 1);
      uVar2 = (uint)uStack_52;
      iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar2,2,(int)&uStack_44 + 2);
      if (iVar3 == 0) {
        uVar2 = 0xffff;
      }
      else {
        uVar2 = uVar2 + iVar3 & 0xffff;
      }
      iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar2,4,&uStack_40);
      if (iVar3 == 0) {
        uStack_52 = 0xffff;
      }
      else {
        uStack_52 = (short)uVar2 + (short)iVar3;
      }
    }
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uStack_64 = 0x80;
    if ((uVar2 < uStack_52) ||
       (uStack_64 = zcl_packet_to_message(&uStack_50,param_1,0x80), uStack_64 != 0)) goto _L0;
    bStack_3c = 0xfe;
    iStack_48 = param_1;
    zcl_core_action_schedule(0x35,&uStack_50,0);
    bVar1 = bStack_3c;
  }
  if (bVar1 != 0xfe) {
    uStack_64 = (uint)bVar1;
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_38,param_1,uStack_64);
  if (iVar3 == 0) {
    zcl_packet_send(auStack_38,0);
  }
  else {
    zcl_packet_free(auStack_38);
  }
  return iVar3;
}

