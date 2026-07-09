/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_initiator_process_discovery_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_initiator_process_discovery_done(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  int iVar9;
  char *pcVar10;
  undefined1 *puVar11;
  void *__src;
  
  iVar9 = touchlink_commissioning_get();
  if (*(char *)(iVar9 + 1) == '\x01') {
    if (param_1 != 0) {
      touchlink_commissioning_task_result(1);
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0x11b,"touchlink_initiator_process_discovery_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_INITIATOR");
  }
  pcVar10 = (char *)touchlink_commissioning_get();
  if (*pcVar10 == '\x03') {
    iVar9 = touchlink_transaction_get();
    *(undefined1 *)(iVar9 + 0x60c) = 5;
    iVar9 = touchlink_transaction_get();
    *(undefined1 *)(iVar9 + 0x610) = 0;
    iVar9 = touchlink_transaction_get();
    uVar7 = touchlink_get_logical_channel();
    *(undefined1 *)(iVar9 + 0x61c) = uVar7;
    iVar9 = touchlink_transaction_get();
    uVar8 = touchlink_assign_pan_id();
    *(undefined2 *)(iVar9 + 0x61a) = uVar8;
    iVar9 = touchlink_transaction_get();
    uVar8 = touchlink_assign_short_addr();
    *(undefined2 *)(iVar9 + 0x61e) = uVar8;
    iVar9 = touchlink_transaction_get();
    puVar11 = (undefined1 *)touchlink_extended_address();
    uVar7 = puVar11[1];
    uVar1 = puVar11[2];
    uVar2 = puVar11[3];
    uVar3 = puVar11[4];
    uVar4 = puVar11[5];
    uVar5 = puVar11[6];
    uVar6 = puVar11[7];
    *(undefined1 *)(iVar9 + 0x611) = *puVar11;
    *(undefined1 *)(iVar9 + 0x612) = uVar7;
    *(undefined1 *)(iVar9 + 0x613) = uVar1;
    *(undefined1 *)(iVar9 + 0x614) = uVar2;
    *(undefined1 *)(iVar9 + 0x615) = uVar3;
    *(undefined1 *)(iVar9 + 0x616) = uVar4;
    *(undefined1 *)(iVar9 + 0x617) = uVar5;
    *(undefined1 *)(iVar9 + 0x618) = uVar6;
    iVar9 = touchlink_transaction_get();
    __src = (void *)touchlink_nwk_key();
    memcpy((void *)(iVar9 + 0x620),__src,0x10);
  }
  iVar9 = touchlink_transaction_get();
  touchlink_zdo_start_router(iVar9 + 0x610);
  return;
}

