/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_wd.o -> ias_wd_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ias_wd_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bStack_53;
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
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    uStack_52 = 0;
    bStack_53 = 0;
    memset(&uStack_50,0,0x18);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&bStack_53);
    uVar2 = uStack_52;
    iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_52,2,(int)&uStack_44 + 2);
    if (iVar3 == 0) {
      uStack_52 = 0xffff;
    }
    else {
      uStack_52 = uVar2 + (short)iVar3;
    }
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&uStack_40);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,(int)&uStack_40 + 1);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar5 = 0x80;
    if (uVar4 < uStack_52) goto _L0;
    uStack_44 = CONCAT31(uStack_44._1_3_,
                         (byte)((bStack_53 & 0xc) << 2) | bStack_53 >> 4 | bStack_53 << 6);
    uVar5 = zcl_packet_to_message(&uStack_50,param_1,0x80);
    if (uVar5 != 0) goto _L0;
    bStack_3c = 0xfe;
    iStack_48 = param_1;
    zcl_core_action_schedule(0x2d,&uStack_50,0);
    bVar1 = bStack_3c;
  }
  else {
    if (*(char *)(param_1 + 0x20) != '\x01') {
      uVar5 = 0x81;
      goto _L0;
    }
    uStack_52 = 0;
    bStack_53 = 0;
    uStack_50 = 0;
    uStack_4c = 0;
    iStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&bStack_53);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar5 = 0x80;
    if (uVar4 < uStack_52) goto _L0;
    uStack_44 = CONCAT31(uStack_44._1_3_,bStack_53);
    uVar5 = zcl_packet_to_message(&uStack_50,param_1,0x80);
    if (uVar5 != 0) goto _L0;
    uStack_40 = CONCAT31(uStack_40._1_3_,0xfe);
    iStack_48 = param_1;
    zcl_core_action_schedule(0x2e,&uStack_50,0);
    bVar1 = (byte)uStack_40;
  }
  uVar5 = (uint)bVar1;
  if (uVar5 == 0xfe) {
    uVar5 = 1;
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_38,param_1,uVar5);
  if (iVar3 == 0) {
    zcl_packet_send(auStack_38,0);
  }
  else {
    zcl_packet_free(auStack_38);
  }
  return iVar3;
}

