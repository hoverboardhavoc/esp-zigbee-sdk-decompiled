/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_device_info_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_device_info_req_handler(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if ((iVar1 != 0) && (piVar2 = (int *)touchlink_transaction_get(), iVar1 == *piVar2)) {
      uVar3 = touchlink_send_device_info_rsp
                        (*(undefined1 *)(param_1 + 0x10),*(undefined1 *)(param_1 + 10));
      return uVar3;
    }
    uVar3 = 3;
  }
  return uVar3;
}

