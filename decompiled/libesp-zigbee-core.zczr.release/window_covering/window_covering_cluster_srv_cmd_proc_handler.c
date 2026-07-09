/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> window_covering.o -> window_covering_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int window_covering_cluster_srv_cmd_proc_handler(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [40];
  
  memset(auStack_38,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar1 = zcl_packet_init(auStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar1 != 0) {
    return iVar1;
  }
  uVar4 = (uint)*(byte *)(param_1 + 0x20);
  iVar1 = 8;
  if ((8 < uVar4) || ((0x1b7U >> (uVar4 & 0x1f) & 1) == 0)) {
    iVar1 = zcl_packet_send_default_response(param_1,0x81);
    goto _L0;
  }
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  iStack_44 = param_1;
  if (uVar4 == 5) {
    uVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,1,&uStack_40);
_L0:
    if (uVar4 == 0) {
      uVar4 = 0xffff;
    }
_L0:
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar3 = 0x80;
    if ((uVar4 <= uVar2) &&
       (((uVar3 = 0x80, (0x318U >> iVar1 & 1) == 0 ||
         (uVar3 = ezb_zcl_set_attr_value
                            (*(undefined1 *)(param_1 + 0x15),0x102,1,iVar1,0,&uStack_40,0),
         uVar3 == 0)) && (uVar3 = zcl_packet_to_message(&uStack_4c,param_1,uVar3), uVar3 == 0)))) {
      uStack_3c = CONCAT31(uStack_3c._1_3_,0xfe);
      zcl_core_action_schedule(0x1b,&uStack_4c,0);
      if ((uStack_3c & 0xff) != 0xfe) {
        uVar3 = (uint)((uStack_3c & 0xff) != 0);
      }
    }
  }
  else {
    if (5 < uVar4) {
      if (uVar4 == 7) {
        uVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,&uStack_40);
        iVar1 = 4;
      }
      else {
        if (uVar4 != 8) goto _L87;
        uVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,1,&uStack_40);
        iVar1 = 9;
      }
      goto _L0;
    }
    if (uVar4 < 3) {
      uVar4 = 0;
      iVar1 = 0;
      goto _L0;
    }
    if (uVar4 == 4) {
      uVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,&uStack_40);
      iVar1 = 3;
      goto _L0;
    }
_L87:
    uVar3 = 0x81;
  }
  iVar1 = zcl_packet_setup_default_response(auStack_38,param_1,uVar3);
_L0:
  if (iVar1 == 0) {
    zcl_packet_send(auStack_38,0);
  }
  else {
    zcl_packet_free(auStack_38);
  }
  return iVar1;
}

