/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_reset_to_factory_new_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zcl_touchlink_reset_to_factory_new_req_handler(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
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
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_28 = *param_1;
    uStack_24 = param_1[1];
    _uStack_20 = CONCAT13(*(undefined1 *)((int)param_1 + 0x1f),
                          CONCAT12(*(undefined1 *)((int)param_1 + 0x1e),*(undefined2 *)(param_1 + 2)
                                  ));
    uStack_2a = 0;
    af_read_le32(&uStack_2a,&uStack_1c);
    uVar2 = zmsg_get_length(param_1[9]);
    if (uVar2 < uStack_2a) {
      uVar1 = 0x80;
    }
    else {
      uVar1 = touchlink_factory_new_req_handler(&uStack_28);
      uVar1 = zcl_status_to_err(uVar1);
    }
  }
  return uVar1;
}

