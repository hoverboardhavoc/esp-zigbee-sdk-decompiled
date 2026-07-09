/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_device_info_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_device_info_req_handler(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 local_30 [2];
  undefined1 auStack_2e [8];
  undefined1 uStack_26;
  undefined4 uStack_24;
  undefined1 uStack_20;
  byte bStack_1f;
  byte bStack_1e;
  int iStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if ((iVar3 == 0) || (piVar5 = (int *)touchlink_transaction_get(), iVar3 != *piVar5)) {
    return 3;
  }
  bVar1 = *(byte *)(param_1 + 0x10);
  uVar4 = (uint)bVar1;
  uVar2 = *(undefined1 *)(param_1 + 10);
  memset(local_30,0,0x20);
  uStack_24 = touchlink_transaction_id(0);
  uVar6 = touchlink_n_sub_device_size();
  uStack_20 = (undefined1)uVar6;
  bStack_1f = bVar1;
  if (uVar4 < uVar6) {
    iStack_1c = mm_alloc(uVar6 - uVar4 & 0xff,0x12);
    uVar7 = 1;
    if (iStack_1c == 0) goto _L0;
  }
  else {
    iStack_1c = 0;
  }
  while (iVar3 = touchlink_get_sub_device_info(uVar4,iStack_1c + (uint)bStack_1e * 0x12), iVar3 == 0
        ) {
    uVar4 = uVar4 + 1 & 0xff;
    bStack_1e = bStack_1e + 1;
  }
  pcStack_18 = touchlink_device_info_rsp_confirm;
  local_30[0] = 3;
  uStack_14 = 0;
  iVar3 = touchlink_transaction_get();
  memcpy(auStack_2e,(void *)(iVar3 + 8),8);
  uStack_26 = uVar2;
  uVar7 = zcl_touchlink_device_info_rsp(local_30);
_L0:
  if (iStack_1c != 0) {
    mm_free();
  }
  return uVar7;
}

