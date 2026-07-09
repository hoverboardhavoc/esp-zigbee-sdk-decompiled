/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_device_information_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zcl_touchlink_device_information_rsp_handler(undefined4 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  ushort uStack_42;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0xfe;
  }
  else if (param_1[9] == 0) {
    uVar2 = 0xfe;
  }
  else {
    uStack_34 = 0;
    uStack_30 = 0;
    pvStack_2c = (void *)0x0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_40 = *param_1;
    uStack_3c = param_1[1];
    _uStack_38 = CONCAT13(*(undefined1 *)((int)param_1 + 0x1f),
                          CONCAT12(*(undefined1 *)((int)param_1 + 0x1e),*(undefined2 *)(param_1 + 2)
                                  ));
    uStack_42 = 0;
    af_read_le32(&uStack_42,&uStack_34);
    af_read_le8(param_1[9],&uStack_42,(int)&uStack_30 + 1);
    af_read_le8(param_1[9],&uStack_42,&uStack_30);
    af_read_le8(param_1[9],&uStack_42,(int)&uStack_30 + 2);
    uVar3 = zmsg_get_length(param_1[9]);
    if (uVar3 < uStack_42) {
      uVar2 = 0x80;
    }
    else {
      uVar3 = uStack_30 >> 0x10 & 0xff;
      if (uVar3 != 0) {
        pvStack_2c = calloc(uVar3,0x12);
        for (uVar3 = 0; uVar3 < (uStack_30 >> 0x10 & 0xff); uVar3 = uVar3 + 1 & 0xff) {
          iVar1 = uVar3 * 0x12;
          af_read_bytes(param_1[9],&uStack_42,8,(void *)((int)pvStack_2c + iVar1));
          af_read_le8(param_1[9],&uStack_42,(int)pvStack_2c + iVar1 + 8);
          af_read_le16(param_1[9],&uStack_42,(int)pvStack_2c + iVar1 + 10);
          af_read_le16(param_1[9],&uStack_42,(int)pvStack_2c + iVar1 + 0xc);
          af_read_le8(param_1[9],&uStack_42,(int)pvStack_2c + iVar1 + 0xe);
          af_read_le8(param_1[9],&uStack_42,(int)pvStack_2c + iVar1 + 0xf);
          af_read_le8(param_1[9],&uStack_42,(int)pvStack_2c + iVar1 + 0x10);
        }
      }
      uVar2 = touchlink_device_info_rsp_handler(&uStack_40);
      uVar2 = zcl_status_to_err(uVar2);
    }
  }
  if (pvStack_2c != (void *)0x0) {
    mm_free();
  }
  return uVar2;
}

