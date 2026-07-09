/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_scan_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zcl_touchlink_scan_rsp_handler(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xfe;
  }
  else if (param_1[9] == 0) {
    uVar1 = 0xfe;
  }
  else {
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_4c = *param_1;
    uStack_48 = param_1[1];
    _uStack_44 = CONCAT13(*(undefined1 *)((int)param_1 + 0x1f),
                          CONCAT12(*(undefined1 *)((int)param_1 + 0x1e),*(undefined2 *)(param_1 + 2)
                                  ));
    uStack_4e = 0;
    af_read_le32(param_1[9],&uStack_4e,&uStack_40);
    af_read_le8(param_1[9],&uStack_4e,&uStack_34);
    af_read_le8(param_1[9],&uStack_4e,&uStack_38);
    af_read_le8(param_1[9],&uStack_4e,(int)&uStack_38 + 1);
    af_read_le16(param_1[9],&uStack_4e,(int)&uStack_38 + 2);
    af_read_le32(param_1[9],&uStack_4e,&uStack_3c);
    af_read_bytes(param_1[9],&uStack_4e,8,(int)&uStack_34 + 1);
    af_read_le8(param_1[9],&uStack_4e,(int)&uStack_2c + 1);
    af_read_le8(param_1[9],&uStack_4e,(int)&uStack_2c + 2);
    af_read_le16(param_1[9],&uStack_4e,&uStack_28);
    af_read_le16(param_1[9],&uStack_4e,(int)&uStack_28 + 2);
    af_read_le8(param_1[9],&uStack_4e,&uStack_24);
    af_read_le8(param_1[9],&uStack_4e,(int)&uStack_24 + 1);
    if ((uStack_24 & 0xff) == 1) {
      af_read_le8(param_1[9],&uStack_4e,(int)&uStack_24 + 2);
      af_read_le16(param_1[9],&uStack_4e,&uStack_20);
      af_read_le16(param_1[9],&uStack_4e,(int)&uStack_20 + 2);
      af_read_le8(param_1[9],&uStack_4e,&uStack_1c);
      af_read_le8(param_1[9],&uStack_4e,(int)&uStack_1c + 1);
    }
    uVar2 = zmsg_get_length(param_1[9]);
    if (uVar2 < uStack_4e) {
      uVar1 = 0x80;
    }
    else {
      uVar1 = touchlink_scan_rsp_handler(&uStack_4c);
      uVar1 = zcl_status_to_err(uVar1);
    }
  }
  return uVar1;
}

