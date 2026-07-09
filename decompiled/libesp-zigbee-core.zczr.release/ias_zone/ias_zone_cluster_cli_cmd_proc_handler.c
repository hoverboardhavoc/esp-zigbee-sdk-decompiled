/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ias_zone_cluster_cli_cmd_proc_handler(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uStack_52;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  byte bStack_3c;
  undefined1 auStack_38 [40];
  
  memset(auStack_38,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar1 = zcl_packet_init(auStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    uStack_52 = 0;
    memset(&uStack_50,0,0x18);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&uStack_44);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,(int)&uStack_44 + 2);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,(int)&uStack_44 + 3);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&uStack_40);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar3 = 0x80;
    if ((uStack_52 <= uVar2) && (uVar3 = zcl_packet_to_message(&uStack_50,param_1,0x80), uVar3 == 0)
       ) {
      bStack_3c = 0xfe;
      iStack_48 = param_1;
      zcl_core_action_schedule(0x33,&uStack_50,0);
      uVar3 = (uint)bStack_3c;
      if (uVar3 == 0xfe) {
_L0:
        uVar3 = 1;
      }
    }
  }
  else if (*(char *)(param_1 + 0x20) == '\x01') {
    uStack_52 = 0;
    uStack_50 = 0;
    uStack_4c = 0;
    iStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,&uStack_44);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_52,(int)&uStack_44 + 2);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar3 = 0x80;
    if ((uStack_52 <= uVar2) && (uVar3 = zcl_packet_to_message(&uStack_50,param_1,0x80), uVar3 == 0)
       ) {
      uStack_40 = CONCAT31(uStack_40._1_3_,0xfe);
      iStack_48 = param_1;
      zcl_core_action_schedule(0x31,&uStack_50,0);
      uVar3 = uStack_40 & 0xff;
      if (uVar3 == 0xfe) goto _L0;
      if (uVar3 == 0) goto _L0;
    }
  }
  else {
    uVar3 = 0x81;
  }
  iVar1 = zcl_packet_setup_default_response(auStack_38,param_1,uVar3);
  if (iVar1 != 0) {
    zcl_packet_free(auStack_38);
    return iVar1;
  }
_L0:
  zcl_packet_send(auStack_38,0);
  return 0;
}

