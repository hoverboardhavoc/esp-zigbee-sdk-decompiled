/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_network_start_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zcl_touchlink_network_start_req_handler(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uStack_5e;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [8];
  undefined1 uStack_44;
  undefined1 auStack_43 [16];
  undefined1 uStack_33;
  undefined1 auStack_32 [2];
  undefined1 auStack_30 [2];
  undefined1 auStack_2e [2];
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [2];
  undefined1 auStack_24 [24];
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xfe;
  }
  else if (param_1[9] == 0) {
    uVar1 = 0xfe;
  }
  else {
    memset(&uStack_5c,0,0x4c);
    uStack_5c = *param_1;
    uStack_58 = param_1[1];
    uStack_54 = *(undefined2 *)(param_1 + 2);
    uStack_52 = *(undefined1 *)((int)param_1 + 0x1e);
    uStack_51 = *(undefined1 *)((int)param_1 + 0x1f);
    uStack_5e = 0;
    af_read_le32(param_1[9],&uStack_5e,auStack_50);
    af_read_bytes(param_1[9],&uStack_5e,8,auStack_4c);
    af_read_le8(param_1[9],&uStack_5e,&uStack_44);
    af_read_bytes(param_1[9],&uStack_5e,0x10,auStack_43);
    af_read_le8(param_1[9],&uStack_5e,&uStack_33);
    af_read_le16(param_1[9],&uStack_5e,auStack_32);
    af_read_le16(param_1[9],&uStack_5e,auStack_30);
    af_read_le16(param_1[9],&uStack_5e,auStack_2e);
    af_read_le16(param_1[9],&uStack_5e,auStack_2c);
    af_read_le16(param_1[9],&uStack_5e,auStack_2a);
    af_read_le16(param_1[9],&uStack_5e,auStack_28);
    af_read_le16(param_1[9],&uStack_5e,auStack_26);
    af_read_le16(param_1[9],&uStack_5e,auStack_24);
    uVar2 = zmsg_get_length(param_1[9]);
    if (uVar2 < uStack_5e) {
      uVar1 = 0x80;
    }
    else {
      uVar1 = touchlink_network_start_req_handler(&uStack_5c);
      uVar1 = zcl_status_to_err(uVar1);
    }
  }
  return uVar1;
}

