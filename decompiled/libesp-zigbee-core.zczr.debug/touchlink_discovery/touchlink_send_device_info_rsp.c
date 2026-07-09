/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_send_device_info_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_send_device_info_rsp(uint param_1,undefined1 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  iStack_1c = 0;
  pcStack_18 = (code *)0x0;
  uStack_14 = 0;
  uStack_24 = touchlink_transaction_id(0);
  uVar2 = touchlink_n_sub_device_size();
  uStack_20._0_2_ = CONCAT11((char)param_1,(char)uVar2);
  if (param_1 < uVar2) {
    uVar2 = uVar2 - param_1 & 0xff;
    if (uVar2 == 0) {
      iStack_1c = 0;
    }
    else {
      iStack_1c = mm_alloc(uVar2,0x12);
    }
  }
  else {
    uVar2 = 0;
    iStack_1c = 0;
  }
  if ((iStack_1c == 0) && (uVar2 != 0)) {
    uVar1 = 1;
  }
  else {
    while (iVar3 = touchlink_get_sub_device_info
                             (param_1,iStack_1c + (uStack_20 >> 0x10 & 0xff) * 0x12), iVar3 == 0) {
      param_1 = param_1 + 1 & 0xff;
      cVar4 = uStack_20._2_1_ + '\x01';
      uStack_20._0_3_ = CONCAT12(cVar4,(undefined2)uStack_20);
    }
    pcStack_18 = touchlink_device_info_rsp_confirm;
    uStack_14 = 0;
    local_30 = CONCAT31(local_30._1_3_,3);
    iVar3 = touchlink_transaction_get();
    uStack_2c = *(undefined4 *)(iVar3 + 10);
    local_30 = CONCAT22(*(undefined2 *)(iVar3 + 8),(undefined2)local_30);
    uStack_28._0_3_ = CONCAT12(param_2,*(undefined2 *)(iVar3 + 0xe));
    uVar1 = zcl_touchlink_device_info_rsp(&local_30);
  }
  if (iStack_1c != 0) {
    mm_free();
  }
  return uVar1;
}

