/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_network_join_router_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zcl_touchlink_network_join_router_req_handler(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uStack_56;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [8];
  undefined1 uStack_3c;
  undefined1 auStack_3b [16];
  undefined1 uStack_2b;
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [2];
  undefined1 auStack_24 [2];
  undefined1 auStack_22 [2];
  undefined1 auStack_20 [2];
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [2];
  undefined1 auStack_1a [14];
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xfe;
  }
  else if (param_1[9] == 0) {
    uVar1 = 0xfe;
  }
  else {
    memset(&uStack_54,0,0x44);
    uStack_54 = *param_1;
    uStack_50 = param_1[1];
    uStack_4c = *(undefined2 *)(param_1 + 2);
    uStack_4a = *(undefined1 *)((int)param_1 + 0x1e);
    uStack_49 = *(undefined1 *)((int)param_1 + 0x1f);
    uStack_56 = 0;
    af_read_le32(param_1[9],&uStack_56,auStack_48);
    af_read_bytes(param_1[9],&uStack_56,8,auStack_44);
    af_read_le8(param_1[9],&uStack_56,&uStack_3c);
    af_read_bytes(param_1[9],&uStack_56,0x10,auStack_3b);
    af_read_le8(param_1[9],&uStack_56,&uStack_2b);
    af_read_le8(param_1[9],&uStack_56,auStack_2a);
    af_read_le16(param_1[9],&uStack_56,auStack_28);
    af_read_le16(param_1[9],&uStack_56,auStack_26);
    af_read_le16(param_1[9],&uStack_56,auStack_24);
    af_read_le16(param_1[9],&uStack_56,auStack_22);
    af_read_le16(param_1[9],&uStack_56,auStack_20);
    af_read_le16(param_1[9],&uStack_56,auStack_1e);
    af_read_le16(param_1[9],&uStack_56,auStack_1c);
    af_read_le16(param_1[9],&uStack_56,auStack_1a);
    uVar2 = zmsg_get_length(param_1[9]);
    if (uVar2 < uStack_56) {
      uVar1 = 0x80;
    }
    else {
      uVar1 = touchlink_join_router_req_handler(&uStack_54);
      uVar1 = zcl_status_to_err(uVar1);
    }
  }
  return uVar1;
}

